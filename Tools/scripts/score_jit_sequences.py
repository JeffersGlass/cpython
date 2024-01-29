import argparse
import csv
import pathlib
import re
import typing

TOOLS_SCRIPTS = pathlib.Path(__file__).resolve()
TOOLS = TOOLS_SCRIPTS.parent
CPYTHON = TOOLS.parent
JIT_STENCILS = CPYTHON / "jit_stencils.h"

supernode_pattern = re.compile(r"static const unsigned char (?P<fullname>([A-Z_]+)(plus([A-Z_]+))+)_code_body\[(?P<length>\d+)\] = {")
op_pattern = re.compile(r"static const unsigned char (?P<fullname>[A-Z_]+)_code_body\[(?P<length>\d+)\] = {")

def output_scores(sequences: typing.Iterable[typing.Iterable[str]]) -> None:
    for s in sequences:
        opscores = [score_instruction(op) for op in opscores]
        sequence_score = score_sequence(s)
        print(f"UOps {", ".join(s)}\n\tSum of Parts: {sum(opscores):> 3}\n\t    Together: {sequence_score}")


def score_sequence(uops: typing.Iterable[str]) -> int:
    ...

def get_scores_from_stencils_h() -> dict[str, int] | None:
    scores = {}
    if JIT_STENCILS.exists():
        with open(JIT_STENCILS, "r") as f:
            for line in f.readlines():
                if m:= re.match(op_pattern, line):
                    scores[m.group("fullname")] = int(m.group("length"))

    return scores

def score_instruction(uop: str) -> int:
    if stencil_scores := get_scores_from_stencils_h():
        return stencil_scores[uop]
    else:
        raise NotImplementedError("Have not yet implemented scoring individual uops by hand")


def get_sequences_from_files(inputs: typing.Iterable[pathlib.Path | str]):
    sequences = []
    for inp in inputs:
        file = pathlib.Path(inp).resolve()
        if not file.exists(): raise ValueError(f"Input '{inp}' does not match any known file")
        
        match file.suffix.lower():
            case 'csv':
                sequences.extend(get_sequences_from_csv(file))
            case '.h':
                sequences.extend(get_sequences_from_stencil_file(file))
            case _:
                raise ValueError(f"Input '{inp} must have file extension .csv or .h'")           

    return sequences


def get_sequences_from_csv(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    path = pathlib.Path(path)
    with open(path, "r") as f:
        return [line for line in csv.reader(f)]
        

def get_sequences_from_stencil_file(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    path = pathlib.Path(path)
    sequences = []
    supernode_pattern = re.compile(r"static const unsigned char (?P<fullname>([A-Z_]+)(plus([A-Z_]+))+)_code_body\[(\d+)\] = {")
    with open(path, "r") as f:
        for line in f.readlines():
            if m:= re.match(supernode_pattern, line):
                sequences.append(m.group("fullname").split("plus"))

def get_sequences_from_string(s: str) -> typing.List[typing.List[str]]:
    return [op.strip() for op in s.split(",")]

def main():
    parser = argparse.ArgumentParser(description="Score JIT sequences for condensability.")

    parser.add_argument(
        "inputs",
        nargs="*",
        type=str,
        help="""
        Input files(s).
        Each file may be: 
            - A .csv file containing lists of UOps
            - A .h file that 'looks like' jit_stencils.h - all multi-uop pairs
                will be scored
        """,
    )

    parser.add_argument(
        "-s",
        "--string",
        type=str,
        help=f"""
        A comma-separated list of UOp names
        """,
        required=False
    )

    args = parser.parse_args()
    if args.string and args.inputs:
        raise ValueError("Cannot provide both a -s string and file inputs")
    
    if args.inputs:
        output_scores(get_sequences_from_files(args.inputs))
    if args.string:
        output_scores(get_sequences_from_string(args.string))
    
    raise ValueError("Must provide at least one file input or -s string")

if __name__ == "__main__":
    main()
