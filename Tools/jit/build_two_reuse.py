import argparse
import asyncio
import dataclasses
import datetime
import enum
import hashlib
import itertools
import json
import os
import pathlib
import re
import shlex
import subprocess
import sys
import tempfile
import time
import typing

import llvm
import schema

from build import get_target, StencilGroup, run, format_addend, HoleValue
from build import INCLUDE, INCLUDE_INTERNAL, INCLUDE_INTERNAL_MIMALLOC, PYTHON, CPYTHON, PYTHON_EXECUTOR_CASES_C_H, TOOLS_JIT
TOOLS_JIT_TEMPLATE_C2 = TOOLS_JIT / "template2.c"

async def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("target", help="a PEP 11 target triple to compile for")
    #parser.add_argument("--all_targets", action="store_true", help="Compile for all PEP 11 triples for Tier 1 CPython Platforms")
    parser.add_argument("first_opcode", nargs="?", help="A valid opcode name to generate opcode pairs for")
    parser.add_argument("-a", "--all_ops", action="store_true", help="Build all opcodes")
    parser.add_argument(
        "-d", "--debug", action="store_true", help="compile for a debug build of Python"
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="echo commands as they are run"
    )
    
    args = parser.parse_args()

    if not args.first_opcode and not args.all_ops:
        raise ValueError("Must specify one of first_opcode (by position) or --all_ops")
    #if not args.target and not args.all_targets:
    #    raise ValueError("Must specify one of target (by position) or --all_targets")

    target = get_target(args.target, debug=args.debug, verbose=args.verbose)
    

    if not args.all_ops:
        target.build = build_singles_plus_selected.__get__(target, target.__class__)
        await target.build(pathlib.Path.cwd(), [
            ('_GUARD_BOTH_INT', '_BINARY_OP_ADD_INT')
            ,])
    else: # --all
        generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
        opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
        for first in opnames:
            target.build = build_2.__get__(target, target.__class__)
            await target.build(pathlib.Path.cwd())
       

async def build_2(self, out: pathlib.Path) -> None:
    jit_stencils = out / "jit_stencils.h"
    generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
    opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
    num_ops = len(opnames)

    """ #header
    with open(jit_stencils, "w") as file:
        for line in dump_header():
            file.write(f"{line}\n")

    single_stencil_groups = await self.build_stencils() 

    with open(jit_stencils, "a") as file:
        for line in dump(single_stencil_groups):
            file.write(f"{line}\n") """

    # Patch build(), build_stencils(), and _compile() to take an initial opcode argument
    self.build_stencils_2 = build_dual_stencils.__get__(self, self.__class__)
    self._compile = _compile2.__get__(self, self.__class__)

    compiliation_start = time.time()

    for index, first_opcode in enumerate(opnames[opnames.index("_BUILD_MAP")+1:]):
        print(f"Building  ({first_opcode}, *) pairs...", end = " ", flush=True)
        start = time.time()
        stencil_groups = await self.build_stencils_2(first_opcode, opnames[opnames.index("_WITH_EXCEPT_START")+1:])
        with open(jit_stencils, "a") as file:    
            for line in dump(stencil_groups):
                file.write(f"{line}\n")
        
        print(f"DONE in {round(time.time() - start, 2)} seconds. Total time {round(time.time() - main_start, 2)}.", end = " ")
        if index < num_ops - 1: print(f"Projected remaining: {str(datetime.timedelta(seconds=((time.time() - compiliation_start) / (index+1)) * (num_ops-index-1)))}")
        else: print("DONE")

    with open (jit_stencils, "a") as file:
        file.write("\n// Injected opcode constants\n")
        max_id = int(max_uop_id())
        op_values = get_op_values()
        for first in opnames:
            for second in opnames:
                file.write(f"#define {first}plus{second} {max_id * op_values[first] + op_values[second] + max_id + 1 + 1}\n")
            print(f"Wrote all constants for ({first}, ) pairs")

    #footer
    with open(jit_stencils, "a") as file:
        for line in dump_footer(itertools.chain(opnames, (op1 + "plus" + op2 for op1 in opnames for op2 in opnames))):
            file.write(f"{line}\n")

async def build_singles_plus_selected(self, out: pathlib.Path, selected: typing.Iterable[tuple[str, str]]):
    selected = list(selected)
    jit_stencils = out / "jit_stencils.h"
    generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
    opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
    num_ops = len(opnames)

    #header
    with open(jit_stencils, "w") as file:
        for line in dump_header():
            file.write(f"{line}\n")

    single_stencil_groups = await self.build_stencils() 

    with open(jit_stencils, "a") as file:
        for line in dump(single_stencil_groups):
            file.write(f"{line}\n")

    # Patch build(), build_stencils(), and _compile() to take an initial opcode argument
    self.build_single_dual_stencil = build_single_dual_stencil.__get__(self, self.__class__)
    self._compile = _compile2.__get__(self, self.__class__)

    compiliation_start = time.time()

    for first_opcode, second_opcode in selected:
        stencil_groups = await self.build_single_dual_stencil(first_opcode, second_opcode)
        with open(jit_stencils, "a") as file:    
            for line in dump(stencil_groups):
                file.write(f"{line}\n")
    with open (jit_stencils, "a") as file:
        file.write("\n// Injected opcode constants\n")
        max_id = int(max_uop_id())
        op_values = get_op_values()
        for first, second in selected:
            file.write(f"# define {first}plus{second} {max_id * op_values[first] + op_values[second] + max_id + 1 + 1}\n")

    #footer
    with open(jit_stencils, "a") as file:
        for line in dump_footer(itertools.chain(opnames, (op1 + "plus" + op2 for (op1, op2) in selected))):
            file.write(f"{line}\n")

async def build_dual_stencils(self, first_opcode, opnames) -> dict[str, StencilGroup]:
    tasks = []
    with tempfile.TemporaryDirectory() as tempdir:
        async with asyncio.TaskGroup() as group:
            for second in opnames:
                work = pathlib.Path(tempdir).resolve()
                coro = self._compile(first_opcode, second, TOOLS_JIT_TEMPLATE_C2, work)
                tasks.append(group.create_task(coro, name=f"{first_opcode}plus{second}"))

    return {task.get_name(): task.result() for task in tasks}

async def build_single_dual_stencil(self, first_opcode, second_opcode) -> dict[str, StencilGroup]:
    with tempfile.TemporaryDirectory() as tempdir:
        work = pathlib.Path(tempdir).resolve()
        result = await self._compile(first_opcode, second_opcode, TOOLS_JIT_TEMPLATE_C2, work)
        
    return {f"{first_opcode}plus{second_opcode}": result}

def dump_header() -> typing.Iterator[str]:
    yield f"// $ {shlex.join([sys.executable, *sys.argv])}"
    yield ""
    yield "typedef enum {"
    for kind in sorted(typing.get_args(schema.HoleKind)):
        yield f"    HoleKind_{kind},"
    yield "} HoleKind;"
    yield ""
    yield "typedef enum {"
    for value in sorted(HoleValue, key=lambda value: value.name):
        yield f"    HoleValue_{value.name},"
    yield "} HoleValue;"
    yield ""
    yield "typedef struct {"
    yield "    const uint64_t offset;"
    yield "    const HoleKind kind;"
    yield "    const HoleValue value;"
    yield "    const void *symbol;"
    yield "    const uint64_t addend;"
    yield "} Hole;"
    yield ""
    yield "typedef struct {"
    yield "    const size_t body_size;"
    yield "    const unsigned char * const body;"
    yield "    const size_t holes_size;"
    yield "    const Hole * const holes;"
    yield "} Stencil;"
    yield ""
    yield "typedef struct {"
    yield "    const Stencil code;"
    yield "    const Stencil data;"
    yield "} StencilGroup;"
    yield ""


def dump_footer(opnames: list[str]) -> typing.Iterator[str]:
    max_id = int(max_uop_id())
    yield "\n#define INIT_STENCIL(STENCIL) {                         \\"
    yield "    .body_size = Py_ARRAY_LENGTH(STENCIL##_body) - 1,   \\"
    yield "    .body = STENCIL##_body,                             \\"
    yield "    .holes_size = Py_ARRAY_LENGTH(STENCIL##_holes) - 1, \\"
    yield "    .holes = STENCIL##_holes,                           \\"
    yield "}"
    yield ""
    yield "#define INIT_STENCIL_GROUP(OP) {     \\"
    yield "    .code = INIT_STENCIL(OP##_code), \\"
    yield "    .data = INIT_STENCIL(OP##_data), \\"
    yield "}"
    yield ""
    array_size = max_id ** 2 + 2*max_id + 1 + 1 + 1
    print(f"{array_size=}")
    yield f"static const StencilGroup stencil_groups[{array_size}] = {{"
    for opname in opnames:
        yield f"    [{opname}] = INIT_STENCIL_GROUP({opname}),"
    yield "};"
    yield ""
    yield "#define GET_PATCHES() { \\"
    for value in sorted(HoleValue, key=lambda value: value.name):
        yield f"    [HoleValue_{value.name}] = (uint64_t)0xBADBADBADBADBADB, \\"
    yield "}"


def dump(stencil_groups: dict[str, StencilGroup]) -> typing.Iterator[str]:
    #yield from dump_header()
    opnames = []
    for opname, stencil in sorted(stencil_groups.items()):
        opnames.append(opname)
        yield f"// {opname}"
        assert stencil.code
        for line in stencil.code.disassembly:
            yield f"// {line}"
        body = ", ".join(f"0x{byte:02x}" for byte in stencil.code.body)
        size = len(stencil.code.body) + 1
        yield f"static const unsigned char {opname}_code_body[{size}] = {{{body}}};"
        if stencil.code.holes:
            size = len(stencil.code.holes) + 1
            yield f"static const Hole {opname}_code_holes[{size}] = {{"
            for hole in sorted(stencil.code.holes, key=lambda hole: hole.offset):
                parts = [
                    hex(hole.offset),
                    f"HoleKind_{hole.kind}",
                    f"HoleValue_{hole.value.name}",
                    f"&{hole.symbol}" if hole.symbol else "NULL",
                    format_addend(hole.addend),
                ]
                yield f"    {{{', '.join(parts)}}},"
            yield "};"
        else:
            yield f"static const Hole {opname}_code_holes[1];"
        for line in stencil.data.disassembly:
            yield f"// {line}"
        body = ", ".join(f"0x{byte:02x}" for byte in stencil.data.body)
        if stencil.data.body:
            size = len(stencil.data.body) + 1
            yield f"static const unsigned char {opname}_data_body[{size}] = {{{body}}};"
        else:
            yield f"static const unsigned char {opname}_data_body[1];"
        if stencil.data.holes:
            size = len(stencil.data.holes) + 1
            yield f"static const Hole {opname}_data_holes[{size}] = {{"
            for hole in sorted(stencil.data.holes, key=lambda hole: hole.offset):
                parts = [
                    hex(hole.offset),
                    f"HoleKind_{hole.kind}",
                    f"HoleValue_{hole.value.name}",
                    f"&{hole.symbol}" if hole.symbol else "NULL",
                    format_addend(hole.addend),
                ]
                yield f"    {{{', '.join(parts)}}},"
            yield "};"
        else:
            yield f"static const Hole {opname}_data_holes[1];"
        yield ""
    #yield from dump_footer(opnames)

async def _compile2(
        self, first: str, second: str, c: pathlib.Path, tempdir: pathlib.Path
    ) -> StencilGroup:
        o = tempdir / f"{first}plus{second}.o"
        flags = [
            f"--target={self.triple}",
            "-DPy_BUILD_CORE",
            "-D_DEBUG" if self.debug else "-DNDEBUG",
            f"-D_JIT_OPCODE={first}",
            f"-D_JIT_OPCODE_2={second}",
            "-D_PyJIT_ACTIVE",
            "-D_Py_JIT",
            "-I.",
            "-Wdeprecated-pragma",
            f"-I{INCLUDE}",
            f"-I{INCLUDE_INTERNAL}",
            f"-I{INCLUDE_INTERNAL_MIMALLOC}",
            f"-I{PYTHON}",
            "-O3",
            "-c",
            "-fno-asynchronous-unwind-tables",
            # SET_FUNCTION_ATTRIBUTE on 32-bit Windows debug builds:
            "-fno-jump-tables",
            # Position-independent code adds indirection to every load and jump:
            "-fno-pic",
            # Don't make calls to weird stack-smashing canaries:
            "-fno-stack-protector",
            # We have three options for code model:
            # - "small": the default, assumes that code and data reside in the lowest
            #   2GB of memory (128MB on aarch64)
            # - "medium": assumes that code resides in the lowest 2GB of memory, and
            #   makes no assumptions about data (not available on aarch64)
            # - "large": makes no assumptions about either code or data
            "-mcmodel=large",
        ]
        clang = llvm.require_tool("clang", echo=self.verbose)
        await run(clang, *flags, "-o", o, c, echo=self.verbose)
        return await self.parse(o)

def max_uop_id():
    with open(CPYTHON / "Include" / "internal" / "pycore_uop_ids.h") as file:
        for line in file.readlines():
            if m:= re.match(r"#define MAX_UOP_ID (?P<id>\d+)", line):
                return m.group("id")
            
def get_op_values() -> dict[str, int]:
    values = {}
    with open(CPYTHON / "Include" / "opcode_ids.h") as f:
        for line in f.readlines():
            if m:= re.match(r"#define (?P<opname>[A-Z0-9_]+)\s+(?P<index>\d+)", line):
                values["_" + m.group('opname')] = int(m.group('index'))

    with open(CPYTHON / "Include" / "internal" / "pycore_uop_ids.h") as f:
        for line in f.readlines():
            if m:= re.match(r"#define (?P<opname>[A-Z0-9_]+)\s+(?P<index>\d+)", line):
                values[m.group('opname')] = int(m.group('index'))

    return values



if __name__ == "__main__":
    main_start = time.time()
    asyncio.run(main())
