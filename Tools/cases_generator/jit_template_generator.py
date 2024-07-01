import argparse
from pathlib import Path

from analyzer import Analysis
from generators_common import write_header
from jit_switch_generator import (
    ROOT,
    DEFAULT_INPUT,
    DEFAULT_SUPERNODES_INPUT,
    analyze_files,
    _supernode_max_depth,
)

DEFAULT_TEMPLATE_OUTPUT = ROOT / "Tools" / "jit" / "template.c"
STARTER = "// START SUPEROP HANDLERS //"
ENDER = "// END SUPEROP HANDLERS //"

template_section = """
    if (_JIT_LENGTH > {num}){{
        int uopcode = uopcode_array[{num}];
        UOP_STAT_INC(uopcode, execution_count);
        if (uopcode == _JUMP_TO_TOP) {{
            PATCH_JUMP(_JIT_TOP);
        }}
        switch (uopcode_array[{num}]) {{
#include "executor_cases.c.h"
            default:
                Py_UNREACHABLE();
        }}
    }}
    """


def update_jit_template(
    filenames: list[str],
    analysis: Analysis,
    template_file: str | Path,
) -> None:
    """Given an Analysis of the Bytecode DSL, re-generate `template.c` to accomodate
    the number of supernodes present

    Args:
        analysis (Analysis): An Analysis of the bytecodes specified in the DSL
        template_file (str | Path): The template file to update (`template.c`)
    """
    with open(template_file, "r") as f:
        lines = f.readlines()

    start_marker = lines.index(next(line for line in lines if STARTER in line))
    header = lines[: start_marker + 1]
    end_marker = lines.index(next(line for line in lines if ENDER in line))
    footer = lines[end_marker:]

    depth = _supernode_max_depth(analysis.supernodes)

    if depth > 1:
        templates = [template_section.format(num=i) for i in range(1, depth)]
    else:
        templates = []

    with open(template_file, "w") as f:
        f.writelines(header)
        for t in templates:
            f.writelines(t)
        f.write("\n\n")
        f.writelines(footer)


arg_parser = argparse.ArgumentParser(
    description="Generate the switch statement to select superinstructions at runtime",
    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
)

arg_parser.add_argument(
    "-t",
    "--template_file",
    type=str,
    help="Jit template file",
    default=DEFAULT_TEMPLATE_OUTPUT,
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

    update_jit_template(args.input, data, args.template_file)
