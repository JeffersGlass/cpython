import argparse
import asyncio
import dataclasses
import enum
import hashlib
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

from build import get_target, dump, StencilGroup, run
from build import INCLUDE, INCLUDE_INTERNAL, INCLUDE_INTERNAL_MIMALLOC, PYTHON, PYTHON_EXECUTOR_CASES_C_H, TOOLS_JIT
TOOLS_JIT_TEMPLATE_C = TOOLS_JIT / "template2.c"

def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("target", help="a PEP 11 target triple to compile for")
    parser.add_argument("first_opcode", nargs="?", help="A valid opcode name to generate opcode pairs for")
    parser.add_argument("-a", "--all", action="store_true", help="Build all opcodes")
    parser.add_argument(
        "-d", "--debug", action="store_true", help="compile for a debug build of Python"
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="echo commands as they are run"
    )
    
    args = parser.parse_args()
    if not args.first_opcode and not args.all:
        raise ValueError("Must specific one of first_opcode (by position) or --all")

    target = get_target(args.target, debug=args.debug, verbose=args.verbose)

    # Patch build(), build_stencils(), and _compile() to take an initial opcode argument
    target.build = build_2.__get__(target, target.__class__)
    target.build_stencils = build_dual_stencils.__get__(target, target.__class__)
    target._compile = _compile2.__get__(target, target.__class__)

    if args.first_opcode:
        target.build(pathlib.Path.cwd(), args.first_opcode)
    else: # --all
        generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
        opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
        for first in opnames:
            target.build(pathlib.Path.cwd(), first)


def build_2(self, out: pathlib.Path, first_opcode) -> None:
    print(f"Building stencils for all pairs of opcodes with {first_opcode} as the first opcode", end = " ")
    start = time.time()
    os.makedirs( out / "stencils" / self.triple , exist_ok=True)
    stencil_groups = asyncio.run(self.build_stencils(first_opcode))
    with (out / "stencils" / self.triple / f"{first_opcode}.h").open("w") as file:
        for line in dump(stencil_groups):
            file.write(f"{line}\n")
    print(f"DONE in {time.time() - start} seconds")

async def build_dual_stencils(self, first_opcode) -> dict[str, StencilGroup]:
    generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
    opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
    tasks = []
    with tempfile.TemporaryDirectory() as tempdir:
        async with asyncio.TaskGroup() as group:
            for second in opnames:
                work = pathlib.Path(tempdir).resolve()
                coro = self._compile(first_opcode, second, TOOLS_JIT_TEMPLATE_C, work)
                tasks.append(group.create_task(coro, name=f"{first_opcode}plus{second}"))

    return{task.get_name(): task.result() for task in tasks}

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

if __name__ == "__main__":
    main()
