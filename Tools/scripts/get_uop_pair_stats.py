import argparse
from pathlib import Path
from typing import TypeAlias

from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()

THRESHHOLD_ADD = .01
THRESHHOLD_DROP = .001

type PairCount = dict[tuple[str, str], int]

def output_pair_stats(inputs: list[Path], verbose: bool = False):
    match len(inputs):
        case 1:
            data = load_raw_data(Path(inputs[0]))
            stats = Stats(data)
            calculate_supernodes(stats, verbose)

def calculate_supernodes(stats: Stats, verbose: bool = False):
    raw_pair_counts = get_pairs(stats, verbose)
    pair_counts = filter_unusable_ops(raw_pair_counts)
    #current_supernodes_seen = set(name for name in stats.get_opcode_stats("uops").get_execution_counts().keys() if "_PLUS_" in name)
    total = sum(value for value in pair_counts.values())
    if not verbose:
        to_add = {k: v for k,v  in pair_counts.items() if (v / total) > THRESHHOLD_ADD}
    else:
        to_add = {}
        for k, v in pair_counts.items():
            if (percent := (v / total)) > THRESHHOLD_ADD:
                print(f"ADDED Pair {k} ({percent*100:.2}% of supernodes)")
                to_add[k] = v
            else:
                print(f"DECLINED Pair {k} (makes up {percent*100:.2}% of supernodes)")
        print(f"Added {len(to_add)} of {len(raw_pair_counts)} possible supernodes that make up more than {100*THRESHHOLD_ADD}% of nodes and are viable")

    update_supernodes_c(to_add, verbose)

    #print(stats.get_opcode_stats("uops").get_execution_counts())
    #print(current_supernodes_seen)
    #print(to_add)

def update_supernodes_c(supernodes: list[tuple[str]], verbose: bool = False) -> None:
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
    verbose: bool = False
) -> dict[tuple[str, str], int]:
    opcode_stats = base_stats.get_opcode_stats("uops")
    return opcode_stats.get_pair_counts()

def filter_unusable_ops(pairs: PairCount, verbose = False) -> PairCount:
    forbidden = ("_EXIT_TRACE",
                 )
    if not verbose:
        return {k: v for k, v in pairs.items() if k[0] not in forbidden and k[1] not in forbidden}
    else:
        result = {}
        for k, v in pairs.items():
            if (fail:= k[0]) in forbidden or (fail:= k[1]) in forbidden:
                print(f"Rejecting pair {k} because {fail} is forbidden in superops")
            else:
                result[k] = v

        return result


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

    parser.add_argument(
        "-v", "--verbose", action="store_true", help="show information on superinstructions being added"
    )

    args = parser.parse_args()

    output_pair_stats(args.inputs, verbose = args.verbose)


if __name__ == "__main__":
    main()
