import argparse
import os
from pathlib import Path
import re
import shutil
import subprocess
import textwrap
import typing


from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
from _bytecode_file_parts import PRE, POST

ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()
SUPERNODE_CASES = (ROOT / "Python" / "supernodes_cases.c.h").absolute().as_posix()

THRESHHOLD_ADD_NEW = 0.001
THRESHHOLD_RETAIN = THRESHHOLD_ADD_NEW * 0.02

FORBIDDEN = ("_EXIT_TRACE",)

type PairCount = dict[tuple[str, str], int]


class DPrintMixin:
    verbose = 0
    dump = False

    def __init__(self, dump=False, verbose=0):
        """A mixin class for doing debug printing, based on a per-instance "verbose" level

        Optionally dump all output to this class to file (currently hardcoded as './out.txt')

        Args:
            dump (bool, optional): Whether to dump all printed output to file. Defaults to False.
            verbose (int, optional): The verbosity level of output. Defaults to 0.
        """
        self.verbose = verbose
        self.dump = dump

    def clear_dump_output(self):
        if self.dump:
            with open("./out.txt", "w+") as f:
                f.write("")

    def dprint(self, level: int, *args, wrap=True, **kwargs):
        if level <= self.verbose:
            if wrap:
                text = [
                    textwrap.fill(
                        "".join(str(a) for a in args),
                        initial_indent="  " * level,
                        subsequent_indent=("  " * level + "↳"),
                    )
                ]
            else:
                text = ["  " * level, *args]
            print(*text, **kwargs)
            if self.dump:
                with open("./out.txt", "a+") as f:
                    f.write("".join(text) + "\n")


class SuperNodeAnalysis(DPrintMixin):
    def __init__(self, /, **kwargs):
        super().__init__(**kwargs)

    def calculate_new_supernodes(self, inputs: list[Path]) -> PairCount:
        """Grab the stats from a (collection of) Pystats runs, calcalate the resulting next set of supernodes,
        and (optionally) update `supernodes.c` whhere they are stored.

        Args:
            inputs (list[Path]): The list of files/paths to analyze for pystats

        Returns:
            PairCount (dict[tuple[str, str], int]): A mapping of pairs of uops/superops to the count of
            their occurance in the stats.
        """

        stats = self.get_stats(inputs)
        return self.calculate_supernodes(stats)

    def get_stats(self, inputs: list[Path]) -> Stats:
        data = load_raw_data(Path(inputs[0]))
        return Stats(data)

    def calculate_supernodes(self, stats: Stats) -> PairCount:
        """Give a set of statistics from previous pystats runs, use a series of metrics to determine
        which supernodes to add, keep, and remove from the set to improve performance

        Args:
            stats (Stats): An amalgamation of

        Returns:
            PairCount (dict[tuple[str, str], int]): A mapping of pairs of uops/superops to the count of
            their occurance in the stats.
        """
        opcode_stats = stats.get_opcode_stats("uops")

        raw_pairs = opcode_stats.get_pair_counts()
        exec_counts = opcode_stats.get_execution_counts()
        pair_counts = self.filter_unusable_ops(raw_pairs)
        total_pair_count = sum(value for value in pair_counts.values())
        max_pair_str_length = (
            max(len(str(uop)) for uop in pair_counts.keys()) if pair_counts else 40
        )

        # Retain/Remove previous supernodes:
        super_exec_counts = {s: v for s, v in exec_counts.items() if "_PLUS_" in s}
        max_super_str_length = (
            max(len(str(uop)) for uop in super_exec_counts.keys())
            if super_exec_counts
            else 40
        )
        total_exec_count = sum(value[0] for value in exec_counts.values())

        big_total = total_exec_count + total_pair_count
        # TODO filter by conflicting oparg/operand/target here
        next_nodes = {}
        messages: list[tuple[str, int]] = []

        # Add/Decline newly identified pairs
        for k, v in pair_counts.items():

            if (percent := (v / big_total)) > THRESHHOLD_ADD_NEW:
                messages.append(
                    (
                        "ADDED Pair {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 4)
                        ),
                        percent,
                    )
                )
                next_nodes[k] = v
            else:
                messages.append(
                    (
                        "  DECLINED Pair {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 4)
                        ),
                        percent,
                    )
                )

        for k, v in super_exec_counts.items():
            count = v[0]
            if (percent := (count / big_total)) > THRESHHOLD_RETAIN:
                messages.append(
                    (
                        "  RETAINED old op {0:<{1}}    {2}%".format(
                            str(k), max_super_str_length, round(percent * 100, 2)
                        ),
                        percent,
                    )
                )
                k0, k1 = k.split("_PLUS_", 1)
                next_nodes[(k0, k1)] = v[0]
            else:
                messages.append(
                    (
                        "  REMOVED old op  {0:<{1}}    {2}%".format(
                            str(k), max_super_str_length, round(percent * 100, 2)
                        ),
                        percent,
                    )
                )

        for m in sorted(messages, key=lambda m: m[1], reverse=True):
            self.dprint(2, m[0], wrap=False)

        self.dprint(
            1,
            f"Added {len(next_nodes)} of {len(raw_pairs)} possible supernodes that make up more than {100*THRESHHOLD_ADD_NEW}% of nodes and are viable",
        )
        return next_nodes

    def update_supernodes_c(self, supernodes: list[tuple[str, ...]]) -> None:
        """Given a list of supernodes, update `supernode.c` with properly formatted supernodes

        Args:
            supernodes (list[tuple[str, ...]]): The list of supernodes to add; each element of the inner tuple is
            either a uop or another supernode
        """
        new_supers = (
            f"super() = {" + ".join(uop for uop in node)};" for node in supernodes
        )

        with open(DEFAULT_SUPERNODES_INPUT, "w") as f:
            f.writelines(PRE)
            f.writelines("\t" + line + "\n" for line in new_supers)
            f.writelines(POST)

    def get_pairs(self, base_stats: Stats) -> dict[tuple[str, str], int]:
        opcode_stats = base_stats.get_opcode_stats("uops")
        return opcode_stats.get_pair_counts()

    def filter_unusable_ops(self, pairs: PairCount) -> PairCount:
        """Some uops/superops seem to crash the interpreter/JIT whenver they are included. Currently,
        these are hardcoded into the FORBIDDEN list. This would be a good thing to continue invesitgated

        Args:
            pairs (PairCount): _description_

        Returns:
            PairCount: _description_
        """

        result = {}
        for k, v in pairs.items():
            if (fail := k[0]) in FORBIDDEN or (fail := k[1]) in FORBIDDEN:
                self.dprint(
                    1, f"Rejecting pair {k} because {fail} is forbidden in superops"
                )
            else:
                result[k] = v

        return result

    @classmethod
    def get_supernode_executor_cases(cls) -> set[str]:
        with open(SUPERNODE_CASES, "r") as f:
            return set(m for m in re.findall(r"case (?P<name>[_A-Z0-9]+):", f.read()))


class SuperNodeEvolver(DPrintMixin):
    default_kwargs = {
        "cwd": ROOT,
        "stdout": subprocess.PIPE,
        "stderr": subprocess.STDOUT,
    }

    def __init__(
        self, /, threads=2, pyperf_command=None, iterations=5, benchmarks=None, **kwargs
    ):
        """Manages the iterative process of taking a set of supernodes; running some benchmarking with pystats on,
        analyzing the results, generating a new set of supernodes, and repeating.

        Args:
            threads (int, optional): The number of threads to use for build and test tasks. Defaults to 2.
            pyperf_command (_type_, optional): _description_. Defaults to ./venv/bin/python -m pyperformance run --python ./python
            iterations (int, optional): The maximum number of times to iteratively generate new supernodes. Defaults to 5. Node geneation will halt if no supernodes change after a given iteration.
            benchmarks (_type_, optional): The set of pyperformance benchmarks to rum. Defaults to running all benchmarks.
        """
        super().__init__(**kwargs)
        if self.verbose >= 2:
            # Send build output to the terminal
            del self.default_kwargs["stdout"]
            del self.default_kwargs["stderr"]
        self.threads = threads
        self.pyperf_command = pyperf_command
        self.iterations = iterations
        self.benchmarks = benchmarks

    def iterate_supernodes(self):
        """The primary iteration method for generating new supernodes."""
        self.clear_dump_output()
        self.dprint(0, "Dumping output to ./out.txt")
        self.dprint(
            0,
            f"Beginning supernode generation process for {self.iterations} iterations max",
        )

        for gen in range(self.iterations):
            self.dprint(
                0, f"Starting supernode generation {gen+1} of {self.iterations}"
            )
            starting_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()

            self.build_python()
            self.generate_stats()
            self.generate_supernodes_from_stats()

            ending_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()
            self.print_supernode_changes(starting_supernodes, ending_supernodes)
            if starting_supernodes == ending_supernodes:
                self.dprint(0, "No supernodes were changed during this run, ending run")
                break

                # TODO Run tests and gather failure types
                # TODO Bail on specific failure types specified by args

    def build_python(self) -> None:
        self.dprint(1, "Building python")
        if self.verbose >= 3:
            nodes = SuperNodeAnalysis.get_supernode_executor_cases()
            self.dprint(3, f"Supernodes: {nodes}")
        self.dprint(2, "Running `make clean`")
        subprocess.call(["make", "clean"], stdout=subprocess.DEVNULL)
        self.dprint(2, "Running `configure --enable-experimental-jit --enable-pystats`")
        subprocess.call(
            [
                "./configure",
                "--enable-experimental-jit",
                "--enable-pystats",
            ],
            stdout=subprocess.DEVNULL,
        )

        self.dprint(2, f"Running `make -j{self.threads}`")
        subprocess.run(["make", f"-j{self.threads}"], stdout=subprocess.DEVNULL)

        """         commands = [
            ["make", "distclean"],
            [
                "./configure",
                "--enable-experimental-jit",
                "--enable-pystats",
            ],
            [
                "make",
                f"-j{self.threads}",
            ],
        ] """

    def generate_stats(self) -> None:
        """Run a command (defaults to pyperformance with all benchmarks) and generate pystats
        There could be other ways of generating stats in the future.
        """
        self.dprint(1, "Generating statistics")
        if (venv := Path("./venv")).exists() and venv.is_dir():
            self.dprint(2, "Deleting old venv")
            shutil.rmtree(venv)

        # Set pyperformance command
        if self.pyperf_command == None:
            self.pyperf_command = [
                "./venv/bin/python",
                "-m",
                "pyperformance",
                "run",
                "--python",
                str(ROOT / "python"),
            ]
            if self.benchmarks:
                self.dprint(2, f"Adding benchmarks to command: {self.benchmarks}")
                self.pyperf_command.extend(["-b", self.benchmarks])
        else:
            if type(self.pyperf_command) == str:
                self.pyperf_command = self.pyperf_command.split(" ")

        # delete old pystats
        try:
            directory = "/tmp/py_stats"
            stats_files = os.listdir(directory)
            for file in stats_files:
                os.remove(os.path.join(directory, file))
        except FileNotFoundError as e:
            self.dprint(
                1, f"Could not remove all of /tmp/py_stats. Failed with error: {e}"
            )

        # run pyperformance
        self.run_command(["python", "-m", "venv", "venv"])
        self.run_command(["./venv/bin/python", "-m", "pip", "install", "pyperformance"])
        self.run_command(self.pyperf_command)

    def generate_supernodes_from_stats(self):
        """Once stats have been generated, calculate new supernodes, then regenerate
        relevant metadata
        """
        self.dprint(1, "Generating supernodes from stats")
        analysis = SuperNodeAnalysis(verbose=self.verbose, dump=self.dump)

        self.dprint(2, "Collating statistics")
        stats = analysis.get_stats([DEFAULT_DIR])
        self.dprint(2, "Calculating supernodes from stats")
        new_supers = analysis.calculate_supernodes(stats)
        self.dprint(
            2, f"Updating supernodes.c with {len(new_supers)} potential supernodes"
        )
        analysis.update_supernodes_c(new_supers)

        for command in [
            ("make", "regen-uop-ids"),
            ("make", "regen-uop-metadata"),
            ("make", "regen-executor-cases"),
            ("make", "regen-jit"),
        ]:
            self.dprint(2, f"Running command `{command}`")
            subprocess.check_call(command, stdout=subprocess.DEVNULL)

    def print_supernode_changes(self, start, end):
        """Print a summary of of changes between a starting set of nodes and an ending set

        Args:
            start (_type_): _description_
            end (_type_): _description_

        Returns:
            bool: _description_
        """
        added = end - start
        removed = start - end
        retained = start & end

        if added:
            self.dprint(2, f"Added {len(added)} supernodes")
            self.dprint(3, added)

        if removed:
            self.dprint(2, f"Removed {len(removed)} supernodes")
            self.dprint(3, removed)

        if retained:
            self.dprint(2, f"Retained {len(retained)} supernodes")
            self.dprint(3, retained)

    def run_command(
        self, command: list[str], kwargs=None, raise_errors=False
    ) -> subprocess.CompletedProcess:
        self.dprint(2, f"Running {command=}")
        if kwargs == None:
            kwargs = self.default_kwargs
        result: subprocess.CompletedProcess = subprocess.run(command, **kwargs)
        if raise_errors and result.returncode:
            raise RuntimeError(
                f"Command {command} exited with error code {result.returncode}"
            )
        return result


### argparse functions:


def _calculate_new(args: argparse.Namespace) -> None:
    analysis = SuperNodeAnalysis(verbose=args.verbose)
    print(analysis.calculate_new_supernodes(args.inputs))


def _iterate(args: argparse.Namespace) -> None:
    manager = SuperNodeEvolver(
        pyperf_command=args.perf_command,
        threads=args.jobs,
        verbose=args.verbose,
        iterations=args.iterations,
        benchmarks=args.benchmarks,
        dump=args.dump_output,
    )
    manager.iterate_supernodes()


def main():
    parser = argparse.ArgumentParser(
        prog="Tools for examining and updating supernodes", add_help=False
    )

    parser.add_argument(
        "-v",
        "--verbose",
        action="count",
        default=0,
        help="show additional debug information",
    )

    parser.add_argument(
        "--dump-output", action="store_true", help="Dump stdout output to ./out.txt"
    )

    subparsers = parser.add_subparsers(help="Sub-command help")

    update_parser = subparsers.add_parser(
        "calculate", help="Calculate new superinstructions based on pystats", parents=[parser]
    )

    update_parser.add_argument(
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

    update_parser.set_defaults(func=_calculate_new)

    # -- Iterate --

    iterate_parser = subparsers.add_parser(
        "iterate",
        help="Rebuild and re-stat python builds to identify supernodes",
        parents=[parser],
    )

    iterate_parser.add_argument(
        "-i",
        "--iterations",
        type=int,
        default=5,
        help="Maximum number of generations to iterate",
    )

    iterate_parser.add_argument(
        "--perf-command", type=str, help="Pyperf command to run to generate stats"
    )

    iterate_parser.add_argument(
        "-j",
        "--jobs",
        type=int,
        default=2,
        help="Number of threads to run builds and tests with",
    )

    iterate_parser.add_argument(
        "--bisect-sefaults",
        action="store_true",
        help="Identify segfaulting supernodes by bisecting and attempt to continue running.",
    )

    iterate_parser.add_argument(
        "--bisect-failures",
        action="store_true",
        help="Identify supernodes that fail tests by bisecting and attempt to continue running. Implies -B",
    )

    iterate_parser.add_argument(
        "-b",
        "--benchmarks",
        type=str,
        help="Which benchmarks to run",
    )

    iterate_parser.set_defaults(func=_iterate)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
