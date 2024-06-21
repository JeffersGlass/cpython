import argparse
from pathlib import Path
from typing import TextIO

from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()

THRESHHOLD_ADD = .01
THRESHHOLD_DROP = .001

def output_pair_stats(inputs: list[Path]):
    match len(inputs):
        case 1:
            data = load_raw_data(Path(inputs[0]))
            stats = Stats(data)
            calculate_supernodes(stats)

def calculate_supernodes(stats: Stats):
    pair_counts = get_pairs(stats)
    #current_supernodes_seen = set(name for name in stats.get_opcode_stats("uops").get_execution_counts().keys() if "_PLUS_" in name)
    total = sum(value for value in pair_counts.values())
    to_add = {k: v for k,v  in pair_counts.items() if (v / total) > THRESHHOLD_ADD}
    update_supernodes_c(to_add)

    #print(stats.get_opcode_stats("uops").get_execution_counts())
    #print(current_supernodes_seen)
    #print(to_add)

def update_supernodes_c(supernodes: list[tuple[str]]) -> None:
    new_supers = (f"super() = ({" + ".join(uop for uop in node)});" for node in supernodes)
    with open(DEFAULT_SUPERNODES_INPUT, "r") as f:
        data = f.readlines()

    start_bytecodes = data.index(next(line for line in data if line.strip() == "// BEGIN BYTECODES //"))+1
    end_bytecodes = data.index(next(line for line in data if line.strip() == "// END BYTECODES //"))

    with open(DEFAULT_SUPERNODES_INPUT, "w") as f:
        f.writelines(data[:start_bytecodes])
        f.writelines("\t" + line + "\n" for line in new_supers)
        f.writelines(data[end_bytecodes])

def get_pairs(
    base_stats: Stats,
) -> dict[tuple[str, str], int]:
    opcode_stats = base_stats.get_opcode_stats("uops")
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
