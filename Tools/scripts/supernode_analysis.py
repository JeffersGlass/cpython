import argparse
import contextlib
import dataclasses
import os
from pathlib import Path
import re
import shutil
import subprocess
import textwrap
import typing
import warnings


from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
from _bytecode_file_parts import PRE, POST
from score_jit import configure_parser, get_sequences_from_files, get_sequences_from_string, output_scores

ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()
SUPERNODE_CASES = (ROOT / "Python" / "supernodes_cases.c.h").absolute().as_posix()

THRESHHOLD_ADD_NEW = 0.0001
THRESHHOLD_RETAIN = THRESHHOLD_ADD_NEW * 0.0

FORBIDDEN = (
    ("_EXIT_TRACE",),
    ("_START_EXECUTOR", "_POP_TOP"),
    ('_GUARD_NOT_EXHAUSTED_TUPLE', '_ITER_NEXT_TUPLE', '_STORE_FAST_4', '_BUILD_LIST'), #failed during docutils stat
    ('_SET_IP', '_LOAD_ATTR', '_CHECK_VALIDITY'),                                       #failed during docutils stat
    ('_SET_IP', '_LOAD_ATTR', '_CHECK_VALIDITY_AND_SET_IP', '_LOAD_ATTR'),              #failed during docutils stat
    ('_GUARD_NOT_EXHAUSTED_RANGE', '_ITER_NEXT_RANGE')                                  #failed during nbody stat
)

type PairCount = dict[tuple[str, str], int]


@dataclasses.dataclass(eq=True)
class SuperNode:
    SEP = "_PLUS_"
    uops: list[str]

    @property
    def name(self):
        return self.SEP.join(self.uops)

    @property
    def depth(self):
        return len(self.uops)

    def sum_form(self):
        return " + ".join(self.uops)

    def __hash__(self):
        return hash(self.name)

    def __eq__(self, other):
        return self.name == other.name

    def is_subop_of(self, other: typing.Self):
        for index, _ in enumerate(other.uops):
            if all(self.uops[i] == other.uops[index+i] for i in range(len(self.depth))): return True
        return False


    @classmethod
    def from_supernode_names(cls, *args: str):
        uops: list[str] = []
        for arg in args:
            uops.extend(arg.split(cls.SEP))
        return SuperNode(uops)


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
            text = [*args]
            with open("./out.txt", "a+") as f:
                f.write("".join(str(a) for a in text) + "\n")

    def clear_dump_output(self):
        if self.dump:
            with open("./out.txt", "w+") as f:
                f.write("")


class SuperNodeAnalysis(DPrintMixin):
    def __init__(self, /, **kwargs):
        super().__init__(**kwargs)

    def calculate_new_supernodes(self, inputs: list[Path]) -> list[SuperNode]:
        """Grab the stats from a (collection of) Pystats runs, calculate the resulting next set of supernodes,
        and (optionally) update `supernodes.c` whhere they are stored.

        Args:
            inputs (list[Path]): The list of files/paths to analyze for pystats

        Returns:
            PairCount (dict[tuple[str, str], int]): A mapping of pairs of uops/superops to the count of
            their occurrence in the stats.
        """

        stats = self._get_stats(inputs)
        return self._calculate_supernodes(stats)

    def _get_stats(self, inputs: list[Path]) -> Stats:
        self.dprint(2, "Collating statistics")
        data = load_raw_data(Path(inputs[0]))
        return Stats(data)

    def _calculate_supernodes(self, stats: Stats) -> list[SuperNode]:
        """Give a set of statistics from previous pystats runs, use a series of metrics to determine
        which supernodes to add, keep, and remove from the set to improve performance

        Args:
            stats (Stats): An amalgamation of

        Returns:
            PairCount (dict[tuple[str, str], int]): A mapping of pairs of uops/superops to the count of
            their occurrence in the stats.
        """
        self.dprint(2, "Calculating supernodes from stats")
        opcode_stats = stats.get_opcode_stats("uops")

        raw_pairs = opcode_stats.get_pair_counts()
        exec_counts = opcode_stats.get_execution_counts()
        pair_counts = self.filter_tenable_pairs(raw_pairs)
        total_pair_count = sum(value for value in pair_counts.values())
        max_pair_str_length = (
            max(len(str(uop)) for uop in pair_counts.keys()) if pair_counts else 40
        )

        # Retain/Remove previous supernodes:
        super_exec_counts: dict[SuperNode, tuple[int, int]] = {
            SuperNode.from_supernode_names(s): v
            for s, v in exec_counts.items()
            if SuperNode.SEP in s
        }
        total_exec_count = sum(value[0] for value in exec_counts.values())

        big_total = total_exec_count + total_pair_count
        # TODO filter by conflicting oparg/operand/target here
        next_nodes: list[SuperNode] = []
        messages: list[tuple[str, float]] = []

        # Add/Decline newly identified pairs
        for k, v in pair_counts.items():

            if (percent := (v / total_pair_count)) > THRESHHOLD_ADD_NEW:
                messages.append(
                    (
                        "ADDED {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 4)
                        ),
                        percent,
                    )
                )
                next_nodes.append(SuperNode.from_supernode_names(k[0], k[1]))
            else:
                messages.append(
                    (
                        "DECLINED {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 4)
                        ),
                        percent,
                    )
                )

        for supernode, (count, _) in super_exec_counts.items():
            if (percent := (count / big_total)) > THRESHHOLD_RETAIN:
                messages.append(
                    (
                        "RETAINED {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 2)
                        ),
                        percent,
                    )
                )
                next_nodes.append(supernode)
            else:
                messages.append(
                    (
                        "REMOVED {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 2)
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

    def filter_tenable_pairs(
        self, pairs: PairCount, known_bad_sequences=None
    ) -> PairCount:
        """Some uops/superops seem to crash the interpreter/JIT whenever they are included. Currently,
        these are hardcoded into the FORBIDDEN list. This would be a good thing to continue investigated

        Args:
            pairs (PairCount): _description_

        Returns:
            PairCount: _description_
        """

        def is_subseq(x: typing.Iterable, y: typing.Iterable) -> bool:
            if len(x) == 0 or len(y) == 0: return False
            xlist, ylist = list(x), list(y)
            for ystart in range(len(ylist)):
                if all(((ystart + i) < len(ylist) and xlist[i] == ylist[ystart+i]) for i in range(len(xlist))): return True
            return False



        result = {}
        for k, v in pairs.items():
            good = True
            uop_sequence = k[0].split(SuperNode.SEP) + k[1].split(SuperNode.SEP)

            if known_bad_sequences is not None:
                for bad in known_bad_sequences:
                    if is_subseq(bad, uop_sequence):
                        self.dprint(
                            2,
                            f"Rejecting pair {k} because {bad} is a known failing sequence",
                        )
                        good = False
                        break

            for forbidden in FORBIDDEN:
                if is_subseq(forbidden, uop_sequence):
                    self.dprint(
                        2,
                        f"Rejecting pair {k} because {forbidden} is forbidden in superops",
                    )
                    good = False
                    break

            if good:
                result[k] = v

        return result

    @classmethod
    def get_supernode_executor_cases(cls) -> list[SuperNode]:
        with open(SUPERNODE_CASES, "r") as f:
            raw_cases = re.findall(r"case (?P<name>[_A-Z0-9]+):", f.read())
            return list(SuperNode.from_supernode_names(m) for m in raw_cases)


class SuperNodeEvolver(DPrintMixin):
    default_kwargs = {
        "cwd": ROOT,
        "stdout": subprocess.PIPE,
        "stderr": subprocess.STDOUT,
        "text": True
    }

    def __init__(
        self,
        /,
        threads=2,
        pyperf_command=None,
        iterations=5,
        benchmarks=None,
        fail_segfaults=False,
        fail_stats=False,
        **kwargs,
    ):
        """Manages the iterative process of taking a set of supernodes; running some benchmarking with pystats on,
        analyzing the results, generating a new set of supernodes, and repeating.

        Args:
            threads (int, optional): The number of threads to use for build and test tasks. Defaults to 2.
            pyperf_command (str, optional): _description_. Defaults to ./venv/bin/python -m pyperformance run --python ./python
            iterations (int, optional): The maximum number of times to iteratively generate new supernodes. Defaults to 5. Node generation will halt if no supernodes change after a given iteration.
            benchmarks (str, optional): The set of pyperformance benchmarks to rum. Defaults to running all benchmarks.
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
        self.fail_segfaults = fail_segfaults
        self.fail_stats = fail_stats

        self.known_bad_supernodes = set()

    def iterate_supernodes(self):
        """The primary iteration method for generating new supernodes."""
        self.clear_dump_output()
        self.dprint(
            0,
            f"Beginning supernode generation process for {self.iterations} iterations max",
        )

        # Deep clean and reconfigure before starting
        self.run_command(["make", "distclean"], raise_errors=False)
        self.run_command(
            [
                "./configure",
                "--enable-experimental-jit",
                "--enable-pystats",
            ],
        )

        # Make sure metadata is up to date with supernodes.c
        self.update_supernode_metadata()

        # Iterative generation
        for gen in range(self.iterations):
            self.dprint(
                0, f"Starting supernode generation {gen+1} of {self.iterations}"
            )
            starting_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()
            self.dprint(
                2,
                f"Starting supernodes: {','.join(str(node) for node in starting_supernodes)}",
            )

            self.build_and_generate_stats(starting_supernodes)
            self.generate_supernodes_from_stats()
            ending_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()

            self.print_supernode_changes(starting_supernodes, ending_supernodes)
            if starting_supernodes == ending_supernodes:
                self.dprint(0, "No supernodes were changed during this run, ending run")
                break

                # TODO Run tests and gather failure types
                # TODO Bail on specific failure types specified by args
        self.dprint(
            0,
            f"Ending supernodes: {','.join(str(node) for node in ending_supernodes)}",
        )
        self.dprint(
            0,
            f"Known bad supernodes: {','.join(str(node) for node in self.known_bad_supernodes)}",
        )

    def _build_and_bisect(
        self,
        nodes: list[SuperNode],
        command: list[str] | None,
        verb: str = "Action",
        total_nodes="???",
    ) -> tuple[list[SuperNode], list[SuperNode]]:
        """Build Python and (optionally) run a shell command. If either the build or the command fails,
        bisect the list of supernodes that were used and try again, until all nodes have been
        identified as successful or failing.

        Args:
            nodes (list[SuperNode]): The SuperNodes to build with
            command (list[str]): A single shell command (as a list of strings) to optionally run after building
            verb (str): The thing currently being done, for logging purposes
            total_nodes (str, optional): The total number of nodes the run started with, for logging purposes. Defaults to "???".
            build (bool): Whether to build during this run. Defaults to True.

        Raises:
            RuntimeError: Throws an error if the build fails and self.fail_segfaults is true, or if the command fails and fail_stats is true

        Returns:
            tuple[list[SuperNode], list[SuperNode]]: Returns a tuple (good, bad) of supernodes which successfully built and tested, and those which caused the build or command to fail.
        """
        self.dprint(
            1,
            f"{verb.capitalize()}-ing python with {len(nodes)} of {total_nodes} nodes",
        )
        self.dprint(2, f"{[node.name for node in nodes]}")
        self.run_command(["make", "clean"])
        # TODO: These modifications should be made in temporary files, not in the main files,
        # so we don't lose data if the process is killed during bisection
        self.update_supernodes_c(nodes)
        self.update_supernode_metadata()

        self.dprint(1, f"Running make -j{self.threads}")
        current_verb = "build"
        result: subprocess.CompletedProcess[str] = self.run_command(
            ["make", f"-j{self.threads}"]
        )
        if command and not result.returncode:  # only run command if build succeeded
            self.dprint(1, f"Running {command}")
            current_verb = verb
            result = self.run_command(command)
        if result.returncode:
            if self.fail_segfaults:
                raise RuntimeError(f"{current_verb} failed with error {result}")
            half_point = len(nodes) // 2
            self.dprint(1, f"{current_verb.capitalize()} FAILED, bisecting")
            self.dprint(
                2,
                f"Failed with {len(nodes)} nodes: {','.join(node.name for node in nodes)}",
            )
            if len(nodes) == 1:
                self.dprint(1, f"Identified bad node during {current_verb}: {nodes[0]}")
                self.dprint(2, f"When running with command {command}")
                return ([], nodes)

            first_good, first_bad = self._build_and_bisect(
                nodes[:half_point], command=command, verb=verb, total_nodes=total_nodes
            )
            second_good, second_bad = self._build_and_bisect(
                nodes[half_point:], command=command, verb=verb, total_nodes=total_nodes
            )
            return (first_good + second_good, first_bad + second_bad)
        else:
            self.dprint(1, f"{verb.capitalize()} SUCCEEDED")
            return (list(nodes), [])

    def _build_python_with_nodes(
        self, nodes: list[SuperNode]
    ) -> tuple[list[SuperNode], list[SuperNode]]:
        return self._build_and_bisect(
            nodes, command=None, verb="build", total_nodes=len(nodes)
        )

    def _run_pyperformance_with_nodes(
        self, nodes: list[SuperNode]
    ) -> tuple[list[SuperNode], list[SuperNode]]:
        return self._build_and_bisect(
            nodes, command=self.pyperf_command, verb="stat", total_nodes=len(nodes)
        )

    def build_and_generate_stats(self, nodes: list[SuperNode]) -> list[SuperNode]:
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

        directory = "/tmp/py_stats"
        if not Path(directory).exists():
            os.mkdir(directory)
        # delete old pystats
        try:
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

        good, bad = self._run_pyperformance_with_nodes(nodes)
        self.known_bad_supernodes.update(bad)
        return good

    def generate_supernodes_from_stats(self):
        """Once stats have been generated, calculate new supernodes, then regenerate
        relevant metadata
        """
        self.dprint(1, "Generating supernodes from stats")
        analysis = SuperNodeAnalysis(verbose=self.verbose, dump=self.dump)

        new_supers = analysis.calculate_new_supernodes([DEFAULT_DIR])

        self.dprint(
            2, f"Updating supernodes.c with {len(new_supers)} potential supernodes"
        )
        self.update_supernodes_c(new_supers)
        self.update_supernode_metadata()

    def update_supernode_metadata(self):

        self.dprint(1, "Updating supernode metadata and building JIT")
        for command in [
            ("make", "regen-uop-ids"),
            ("make", "regen-uop-metadata"),
            ("make", "regen-executor-cases"),
            ("make", "regen-jit"),
        ]:
            #with warnings.catch_warnings(record=True) as caught_warnings:
            #warnings.simplefilter("always")
            self.run_command(command, print_warnings=True)
            #for warning in caught_warnings:
            #    self.dprint(1, f"Warning from `{' '.join(command)}` :", warning)

    def update_supernodes_c(self, supernodes: typing.Iterable[SuperNode]) -> None:
        """Given a list of supernodes, update `supernode.c` with properly formatted supernodes

        Args:
            supernodes (list[tuple[str, ...]]): The list of supernodes to add; each element of the inner tuple is
            either a uop or another supernode
        """
        self.dprint(1, "Updating supernodes.c")
        self.dprint(2, f"Updating supernodes.c with {len(supernodes)} nodes {supernodes}")
        update_supernodes_c(supernodes)

    def print_supernode_changes(
        self, start: typing.Iterable[str], end: typing.Iterable[str]
    ):
        """Print a summary of of changes between a starting set of nodes and an ending set

        Args:
            start (typing.Iterable[str]): The set of supernodes at the start of the comparison
            end (typing.Iterable[str]): The set of supernodesa at the end of the comparison
        """
        start = set(start)
        end = set(end)
        added = end - start
        removed = start - end
        retained = start & end

        if added:
            self.dprint(1, f"Added {len(added)} supernodes")
            self.dprint(2, added)

        if removed:
            self.dprint(1, f"Removed {len(removed)} supernodes")
            self.dprint(2, removed)

        if retained:
            self.dprint(1, f"Retained {len(retained)} supernodes")
            self.dprint(2, retained)

    def run_command(
        self,
        command: list[str],
        raise_errors=False,
        print_warnings=False,
        kwargs=None,
    ) -> subprocess.CompletedProcess[str]:
        self.dprint(2, f"Running {command=}")
        if kwargs == None:
            kwargs = self.default_kwargs

        if print_warnings:
            kwargs |= {"capture_output": True}

        result: subprocess.CompletedProcess[str] = subprocess.run(command, **kwargs)

        if print_warnings:
            for line in result.stderr.split("\n"):
                if line.strip():
                    self.dprint(1, f"Warning from `{' '.join(command)}` :", line)
        if raise_errors and result.returncode:
            raise RuntimeError(
                f"Command {command} exited with error code {result.returncode}"
            )
        return result


### Module-level functions:

def update_supernodes_c(supernodes: typing.Iterable[SuperNode]) -> None:
    """Given a list of supernodes, update `supernode.c` with properly formatted supernodes

    Args:
        supernodes (list[tuple[str, ...]]): The list of supernodes to add; each element of the inner tuple is
        either a uop or another supernode
    """
    supernodes = list(supernodes)
    new_supers = [f"super() = {node.sum_form()};" for node in supernodes]

    with open(DEFAULT_SUPERNODES_INPUT, "w") as f:
        f.writelines(PRE)
        f.writelines("\t" + line + "\n" for line in new_supers)
        f.writelines(POST)


### argparse functions:


def _calculate_new(args: argparse.Namespace) -> None:
    analysis = SuperNodeAnalysis(verbose=args.verbose)
    print(analysis.calculate_new_supernodes(args.inputs))


def _iterate(args: argparse.Namespace) -> None:
    manager = SuperNodeEvolver(
        pyperf_command=args.perf_command,
        threads=args.jobs,
        verbose=args.verbose,
        fail_segfaults=args.fail_segfaults,
        fail_stats=args.fail_stats,
        iterations=args.iterations,
        benchmarks=args.benchmarks,
        dump=args.dump_output,
    )
    manager.iterate_supernodes()

def _prune(args: argparse.Namespace) -> None:
    nodes = SuperNodeAnalysis.get_supernode_executor_cases()
    print(f"Found {len(nodes)} cases in supernode_cases.h")

    if args.bisect_with:
        e = SuperNodeEvolver(verbose = args.verbose, threads=args.jobs)
        command = args.bisect_with
        if type(command) == str:
            command = command.split(" ")
        good, bad = e._build_and_bisect(nodes, command, verb="prune-bisect", total_nodes=len(nodes))
        print(f"Updating supernodes.c with {len(good)} good nodes and omitting {len(bad)} bad nodes")
        print(f"Bad nodes: {','.join(bad)}")
        nodes = good

    update_supernodes_c(nodes)

def _score(args):
    if args.string and args.inputs:
        raise ValueError("Cannot provide both a -s string and file inputs")

    if args.input:
        input_func = get_sequences_from_files
    elif args.string:\
        input_func = get_sequences_from_string
    else:
        raise ValueError("Must provide at least one file input or -s string")

    if args.output_mode and args.output_mode != "table" and args.table:
        ValueError(f"Cannot provide --output_mode={args.output_mode}")
    if not args.output_mode:
        output_mode = "table" if args.table else "text"

    output_scores(input_func(args.input), args.significance_factor, output_mode=args.output_mode or output_mode)

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


    parser.add_argument(
        "-j",
        "--jobs",
        type=int,
        default=2,
        help="Number of threads to run builds and tests with",
    )

    subparsers = parser.add_subparsers(help="Sub-command help")

    update_parser = subparsers.add_parser(
        "calculate",
        help="Calculate new superinstructions based on pystats",
        parents=[parser],
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

    # -- Prune --

    prune_parser = subparsers.add_parser(
        "prune",
        help="Validate the current selection of sueprnodes in supernode_cases.h by bisecting, then update supernodes.c",
        parents=[parser],
    )

    prune_parser.add_argument(
        "--bisect-with",
        type=str,
        help="The command to run to bisect the results, if any"
    )

    prune_parser.set_defaults(func=_prune)

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
        "--fail-segfaults",
        action="store_true",
        help="Don't bisect and attempt to continue running when segfaulting on build",
    )

    iterate_parser.add_argument(
        "--fail-stats",
        action="store_true",
        help="Don't bisect and attempt to continue running when erroring on performance runs",
    )

    iterate_parser.add_argument(
        "-b",
        "--benchmarks",
        type=str,
        help="Which benchmarks to run",
    )

    iterate_parser.set_defaults(func=_iterate)

    score_parser = subparsers.add_parser(
        "score",
        help="Generate scores for superinstructions",
        parents=[parser],
    )

    configure_parser(score_parser)

    score_parser.set_defaults(func=_score)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
