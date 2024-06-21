import argparse
from pathlib import Path
from typing import TextIO

from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()

THRESHHOLD_ADD = 1
THRESHHOLD_DROP = .1

def output_pair_stats(inputs: list[Path]):
    match len(inputs):
        case 1:
            data = load_raw_data(Path(inputs[0]))
            stats = Stats(data)
            update_supernodes(stats)

def update_supernodes(stats: Stats):
    current_supernodes = set(name for name in stats.get_opcode_stats("uops").get_execution_counts().keys() if "_PLUS" in name)
    pair_counts = get_pairs(stats)
    total = sum(value for value in pair_counts.values())
    to_add = {k: v for k,v  in pair_counts.items() if (v / total) > THRESHHOLD_ADD}

    print(stats.get_opcode_stats("uops").get_execution_counts())
    print(current_supernodes)
    print(to_add)

def get_pairs(
    base_stats: Stats,
) -> dict[tuple[str, str], int]:
    opcode_stats = base_stats.get_opcode_stats("uop")
    return opcode_stats.get_pair_counts()


def main():
    parser = argparse.ArgumentParser(description="Summarize pystats results")

    parser.add_argument(
        "inputs",
        nargs="*",
        type=str,
        default=[DEFAULT_DIR],
        help=f"""
        Input source(s).
        For each entry, if a .json file, the output provided by --json-output from a previous run;
        if a directory, a directory containing raw pystats .txt files.
        If one source is provided, its stats are printed.
        Default is {DEFAULT_DIR}.
        """,
    )

    args = parser.parse_args()

    output_pair_stats(args.inputs)


if __name__ == "__main__":
    main()
