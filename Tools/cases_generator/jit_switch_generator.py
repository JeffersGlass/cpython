"""Generate a switch statement to select superinstructions
Reads the instruction definitions from superinstructions.c
Writes the switch statement to jit_switch.c by default.
"""

import argparse
import itertools
import textwrap
import string

from analyzer import Analysis, analyze_files, SuperNode
from generators_common import (
    DEFAULT_INPUT,
    DEFAULT_SUPERNODES_INPUT,
    ROOT,
    write_header,
)
from typing import TextIO, Generator


DEFAULT_OUTPUT = ROOT / "Python/jit_switch.c"
INDENT_UNIT = "    "

PREAMBLE = """
#include "Python.h"
#include "pycore_uop_ids.h"
#include "opcode_ids.h"
#include "jit_switch.h"
"""

POST = """"""


def generate_jit_switch_file(
    filenames: list[str],
    analysis: Analysis,
    outfile: TextIO,
) -> None:
    """Generate a switch statement to select appropriate SuperInstructions,
    based on the superinstructions present in the input files. The final result
    (minus preable) looks like:

    SuperNode
    _JIT_INDEX(uint16_t a, uint16_t b) {
        switch (a) {
            case _LOAD_FAST_0:
                switch (b) {
                    case _GUARD_TYPE_VERSION:
                        return (SuperNode) {.index = _LOAD_FAST_0_PLUS__GUARD_TYPE_VERSION, .length = 2};
                        break;
                    ...
    """
    write_header(__file__, filenames, outfile)
    outfile.write(PREAMBLE)
    outfile.write("\n\n")

    result = _generate_jit_switch_function(analysis.supernodes)
    outfile.writelines(line + "\n" for line in result)

    outfile.write(POST)


def _generate_jit_switch_function(
    supernodes: dict[str, SuperNode]
) -> Generator[str, None, None]:

    depth = max(len(node.uops) for node in supernodes.values())
    yield f"// This function always needs to be fed {depth} uops"
    yield "SuperNode"
    yield "_JIT_INDEX(const _PyUOpInstruction *uops, uint16_t start_index) {"
    yield from _recurse_jit(supernodes.values(), level=0, indent_level=1)
    yield "}"  # _JIT_INDEX


def _recurse_jit(
    nodes: list[SuperNode], level: int, indent_level: int
):
    """Recursively generate lower levels of the switch statement"""

    initial_opcodes = []
    for node in nodes:
        if node.uops[0].name not in initial_opcodes:
            initial_opcodes.append(node.uops[0].name)

    yield f"{INDENT_UNIT * indent_level}switch (uops[start_index + {level}]) {{"

    for initial_op in initial_opcodes:
        yield f"{INDENT_UNIT * (indent_level + 1)}case {initial_op}:"
        next_nodes = [
            node.pop_front()
            for node in nodes
            if len(node.uops) > 1 and node.uops[0].name == initial_op
        ]
        if next_nodes:
            yield from _recurse_jit(next_nodes, level + 1, indent_level + 2)
        else:
            first_nodes = [node for node in nodes if node.uops[0].name == initial_op]
            if len(first_nodes) != 1:
                raise ValueError(f"Wrong number of first_nodes")
            only_node = first_nodes[0]
            yield f"{INDENT_UNIT * (indent_level + 2)}return (SuperNode) {{.index = {only_node.top_parent().name}, .length = {only_node.top_parent().length}}};"
        yield f"{INDENT_UNIT * (indent_level + 2)}break;"

    yield f"{INDENT_UNIT * (indent_level + 1)}default:"
    yield f"{INDENT_UNIT * (indent_level + 2)}return (SuperNode) {{.index = uops[0], .length = 1}};"
    yield f"{INDENT_UNIT * indent_level}}}"  # end of switch


def _parameter_names(num):
    """Generate single-letter arg names, following by two-letter arg names if
    necessary. (a, b, c, ..., z, aa, ab, ...)

    Args:
        num (_type_): How many argument names to create

    Yields:
        Generator[str]: The returned argument names
    """
    for i in range(min(num, 26)):
        yield string.ascii_lowercase[i]
    if num <= 26:
        return

    for i in range(num**2):
        yield from itertools.combinations_with_replacement(string.ascii_lowercase)

def generate_jit_header_file(
    filenames: list[str],
    analysis: Analysis,
    outfile: TextIO,
) -> Generator[str, None, None]:

    write_header(__file__, filenames, outfile)
    outfile.write(textwrap.dedent("""
        #include "Python.h"
        #include "cpython/optimizer.h"

        typedef struct {
            const uint64_t index;
            const uint16_t length;
        } SuperNode;\n
        """
        ))

    depth = _supernode_max_depth(analysis.supernodes)
    outfile.writelines([f"#define SUPERNODE_MAX_DEPTH {depth}\n\n",
                        f"//This function must always be fed {depth} uops\n"
                        "SuperNode\n",
                        "_JIT_INDEX(const _PyUOpInstruction *uops, uint16_t start_index);\n"])

def _supernode_max_depth(supernodes: dict[str: SuperNode]):
    return max(len(node.uops) for node in supernodes.values())

arg_parser = argparse.ArgumentParser(
    description="Generate the switch statement to select superinstructions at runtime",
    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
)

arg_parser.add_argument(
    "-o", "--output", type=str, help="Generated code", default=DEFAULT_OUTPUT
)

arg_parser.add_argument(
    "--header", type=str, help="Generated header file", default=DEFAULT_OUTPUT.with_suffix(".h")
)

arg_parser.add_argument(
    "input", nargs=argparse.REMAINDER, help="Instruction definition file(s)"
)

if __name__ == "__main__":
    args = arg_parser.parse_args()
    if len(args.input) == 0:
        args.input.append(DEFAULT_INPUT)
        args.input.append(DEFAULT_SUPERNODES_INPUT)
    data = analyze_files(args.input)

    with open(args.output, "w") as outfile:
        generate_jit_switch_file(args.input, data, outfile)


    with open(args.header, "w") as outfile:
        generate_jit_header_file(args.input, data, outfile)
