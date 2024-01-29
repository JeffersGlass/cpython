import argparse
import pathlib
import typing

TOOLS_SCRIPTS = pathlib.Path(__file__).resolve()
TOOLS = TOOLS_SCRIPTS.parent
CPYTHON = TOOLS.parent
JIT_STENCISL = CPYTHON / "jit_stencils.h"

def output_scores(sequences: typing.Iterable[typing.Iterable[str]]) -> None:
    for s in sequences:
        opscores = [score_instruction(op) for op in opscores]
        sequence_score = score_sequence(s)
        print(f"UOps {", ".join(s)}\n\tSum of Parts: {sum(opscores):> 3}\n\t    Together: {sequence_score}")


def score_sequence(uops: typing.Iterable[str]) -> int:
    ...

def score_instruction(uop: str) -> int:
    ...

def get_sequences_from_files(inputs: typing.Iterable[pathlib.Path | str]):
    sequences = []
    for inp in inputs:
        file = pathlib.Path(inp).resolve()
        if not file.exists(): raise ValueError(f"Input '{inp}' does not match any known file")
        
        if file.suffix.lower() == '.csv':
            sequences.extend(get_sequences_from_csv(file))
        elif file.suffix.lower() == '.h':
            sequences.extend(get_sequences_from_stencil_file(file))
        else:
            raise ValueError(f"Input '{inp} must have file extension .csv or .h'")

    return sequences


def get_sequences_from_csv(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    ...

def get_sequences_from_stencil_file(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    ...

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
