import argparse
import functools
import os
from pathlib import Path
import re
import shutil
import subprocess
import textwrap


from summarize_stats import Stats, DEFAULT_DIR, load_raw_data

ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()
SUPERNODE_CASES = (ROOT / "Python" / "supernodes_cases.c.h").absolute().as_posix()

PRE = """// This file contains instruction definitions.
// It is read by generators stored in Tools/cases_generator/
// to generate Python/generated_cases.c.h and others.
// Note that there is some dummy C code at the top and bottom of the file
// to fool text editors like VS Code into believing this is valid C code.
// The actual instruction definitions start at // BEGIN BYTECODES //.
// See Tools/cases_generator/README.md for more information.

#include "Python.h"
#include "pycore_abstract.h"      // _PyIndex_Check()
#include "pycore_backoff.h"
#include "pycore_cell.h"          // PyCell_GetRef()
#include "pycore_code.h"
#include "pycore_emscripten_signal.h"  // _Py_CHECK_EMSCRIPTEN_SIGNALS
#include "pycore_function.h"
#include "pycore_instruments.h"
#include "pycore_intrinsics.h"
#include "pycore_long.h"          // _PyLong_GetZero()
#include "pycore_moduleobject.h"  // PyModuleObject
#include "pycore_object.h"        // _PyObject_GC_TRACK()
#include "pycore_opcode_metadata.h"  // uop names
#include "pycore_opcode_utils.h"  // MAKE_FUNCTION_*
#include "pycore_pyatomic_ft_wrappers.h" // FT_ATOMIC_*
#include "pycore_pyerrors.h"      // _PyErr_GetRaisedException()
#include "pycore_pystate.h"       // _PyInterpreterState_GET()
#include "pycore_range.h"         // _PyRangeIterObject
#include "pycore_setobject.h"     // _PySet_NextEntry()
#include "pycore_sliceobject.h"   // _PyBuildSlice_ConsumeRefs
#include "pycore_sysmodule.h"     // _PySys_Audit()
#include "pycore_tuple.h"         // _PyTuple_ITEMS()
#include "pycore_typeobject.h"    // _PySuper_Lookup()

#include "pycore_dict.h"
#include "dictobject.h"
#include "pycore_frame.h"
#include "opcode.h"
#include "optimizer.h"
#include "pydtrace.h"
#include "setobject.h"


#define USE_COMPUTED_GOTOS 0
#include "ceval_macros.h"

/* Flow control macros */
#define GO_TO_INSTRUCTION(instname) ((void)0)

#define inst(name, ...) case name:
#define op(name, ...) /* NAME is ignored */
#define macro(name) static int MACRO_##name
#define super(name) static int SUPER_##name
#define family(name, ...) static int family_##name
#define pseudo(name) static int pseudo_##name
#define macro(name) static int SUPER_##name

/* Annotations */
#define guard
#define override
#define specializing
#define split
#define replicate(TIMES)

// Dummy variables for stack effects.
static PyObject *value, *value1, *value2, *left, *right, *res, *sum, *prod, *sub;
static PyObject *container, *start, *stop, *v, *lhs, *rhs, *res2;
static PyObject *list, *tuple, *dict, *owner, *set, *str, *tup, *map, *keys;
static PyObject *exit_func, *lasti, *val, *retval, *obj, *iter, *exhausted;
static PyObject *aiter, *awaitable, *iterable, *w, *exc_value, *bc, *locals;
static PyObject *orig, *excs, *update, *b, *fromlist, *level, *from;
static PyObject **pieces, **values;
static size_t jump;
// Dummy variables for cache effects
static uint16_t invert, counter, index, hint;
#define unused 0  // Used in a macro def, can't be static
static uint32_t type_version;
static _PyExecutorObject *current_executor;

static PyObject *
dummy_func(
    PyThreadState *tstate,
    _PyInterpreterFrame *frame,
    unsigned char opcode,
    unsigned int oparg,
    _Py_CODEUNIT *next_instr,
    PyObject **stack_pointer,
    int throwflag,
    PyObject *args[]
)
{
    // Dummy labels.
    pop_1_error:
    // Dummy locals.
    PyObject *dummy;
    _Py_CODEUNIT *this_instr;
    PyObject *attr;
    PyObject *attrs;
    PyObject *bottom;
    PyObject *callable;
    PyObject *callargs;
    PyObject *codeobj;
    PyObject *cond;
    PyObject *descr;
    _PyInterpreterFrame  entry_frame;
    PyObject *exc;
    PyObject *exit;
    PyObject *fget;
    PyObject *fmt_spec;
    PyObject *func;
    uint32_t func_version;
    PyObject *getattribute;
    PyObject *kwargs;
    PyObject *kwdefaults;
    PyObject *len_o;
    PyObject *match;
    PyObject *match_type;
    PyObject *method;
    PyObject *mgr;
    Py_ssize_t min_args;
    PyObject *names;
    PyObject *new_exc;
    PyObject *next;
    PyObject *none;
    PyObject *null;
    PyObject *prev_exc;
    PyObject *receiver;
    PyObject *rest;
    int result;
    PyObject *self;
    PyObject *seq;
    PyObject *slice;
    PyObject *step;
    PyObject *subject;
    PyObject *top;
    PyObject *type;
    PyObject *typevars;
    PyObject *val0;
    PyObject *val1;
    int values_or_none;

    switch (opcode) {

// BEGIN BYTECODES //
"""

POST = """
// END BYTECODES //

    }
 dispatch_opcode:
 error:
 exception_unwind:
 exit_unwind:
 handle_eval_breaker:
 resume_frame:
 resume_with_error:
 start_frame:
 unbound_local_error:
    ;
}

// Future families go below this point //"""

THRESHHOLD_ADD_NEW = 0.01
THRESHHOLD_RETAIN = 0.005

type PairCount = dict[tuple[str, str], int]

class DPrintMixin:
    verbose = 0

    def dprint(self, level: int, *args, wrap=True, **kwargs):
        if level <= self.verbose:
            if wrap:
                print(textwrap.fill(''.join(str(a) for a in args), initial_indent= "  " * level, subsequent_indent= ("  " * level + "↳")))
            else:
                print("  " * level, *args, **kwargs)



class SuperNodeAnalysis(DPrintMixin):
    def __init__(self, /, dry_run=False, verbose=0):
        self.dry_run = dry_run
        self.verbose = verbose

    def output_pair_stats(self, inputs: list[Path]):
        match len(inputs):
            case 1:
                stats = self.get_stats(inputs)
                new_supers = self.calculate_supernodes(stats)
                if not self.dry_run:
                    self.update_supernodes_c(new_supers)

    def get_stats(self, inputs: list[Path]) -> Stats:
        data = load_raw_data(Path(inputs[0]))
        return Stats(data)

    def calculate_supernodes(self, stats: Stats) -> PairCount:
        opcode_stats = stats.get_opcode_stats("uops")

        raw_pairs =  opcode_stats.get_pair_counts()
        exec_counts = opcode_stats.get_execution_counts()
        pair_counts = self.filter_unusable_ops(raw_pairs)

        # TODO filter by conflicting oparg/operand/target here

        max_pair_str_length = max(len(str(uop)) for uop in pair_counts.keys())

        # current_supernodes_seen = set(name for name in stats.get_opcode_stats("uops").get_execution_counts().keys() if "_PLUS_" in name)
        total_pair_count = sum(value for value in pair_counts.values())

        to_add = {}
        messages: list[tuple[str, int]] = []

        # Add/Decline newly identified pairs
        for k, v in pair_counts.items():
            if (percent := (v / total_pair_count)) > THRESHHOLD_ADD_NEW:
                messages.append(
                    (
                        "ADDED Pair {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 2)
                        ),
                        percent,
                    )
                )
                to_add[k] = v
            else:
                messages.append(
                    (
                        "  DECLINED Pair {0:<{1}}    {2}%".format(
                            str(k), max_pair_str_length, round(percent * 100, 2)
                        ),
                        percent,
                    )
                )

        #Retain/Remove previous supernodes:
        exec_counts = opcode_stats.get_execution_counts()
        super_exec_counts = {s: v for s, v in exec_counts.items() if "_PLUS_" in s}
        total_exec_count = sum(value[0] for value in exec_counts.values())
        max_super_str_length = max(len(str(uop)) for uop in exec_counts.keys())

        for k, v in super_exec_counts.items():
            count = v[0]
            if (percent := (count / total_exec_count)) > THRESHHOLD_RETAIN:
                messages.append(("  RETAINED old op {0:<{1}}    {2}%".format(
                    str(k), max_super_str_length, round(percent * 100, 2)
                ), percent))
                k0, k1 = k.split("_PLUS_", 1)
                to_add[(k0, k1)] = v[0]
            else:
                messages.append(("  REMOVED old op  {0:<{1}}    {2}%".format(
                    str(k), max_super_str_length, round(percent * 100, 2)), percent
                ))

        for m in sorted(messages, key=lambda m: m[1], reverse=True):
            self.dprint(2, m[0], wrap=False)

        self.dprint(
            1,
            f"Added {len(to_add)} of {len(raw_pairs)} possible supernodes that make up more than {100*THRESHHOLD_ADD_NEW}% of nodes and are viable",
        )
        return to_add

    def update_supernodes_c(self, supernodes: list[tuple[str]]) -> None:
        new_supers = (
            f"super() = {" + ".join(uop for uop in node)};" for node in supernodes
        )

        with open(DEFAULT_SUPERNODES_INPUT, "w") as f:
            f.writelines(PRE)
            f.writelines("\t" + line + "\n" for line in new_supers)
            f.writelines(POST)

    def get_pairs(
        self, base_stats: Stats, verbose: bool = False
    ) -> dict[tuple[str, str], int]:
        opcode_stats = base_stats.get_opcode_stats("uops")
        return opcode_stats.get_pair_counts()

    def filter_unusable_ops(self, pairs: PairCount, verbose=False) -> PairCount:
        forbidden = ("_EXIT_TRACE",)
        if not verbose:
            return {
                k: v
                for k, v in pairs.items()
                if k[0] not in forbidden and k[1] not in forbidden
            }
        else:
            result = {}
            for k, v in pairs.items():
                if (fail := k[0]) in forbidden or (fail := k[1]) in forbidden:
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

class SuperNodeIterator(DPrintMixin):

    default_kwargs = {
        "cwd": ROOT,
        "shell": True,
        "stdout": subprocess.PIPE,
        "stderr": subprocess.STDOUT,
    }

    def __init__(
        self,
        /,
        verbose=False,
        threads=2,
        pyperf_command=None,
        iterations=5,
        benchmarks=None,
    ):
        self.verbose = verbose
        if self.verbose >= 2:
            # Send build output to the terminal
            del self.default_kwargs["stdout"]
            del self.default_kwargs["stderr"]
        self.threads = threads
        self.pyperf_command = pyperf_command
        self.iterations = iterations
        self.benchmarks = benchmarks

    def iterate_supernodes(self):
        print(
            f"Beginning supernode generation process for {self.iterations} iterations max"
        )
        for gen in range(self.iterations):
            self.dprint(0, f"Starting supernode generation {gen+1} of {self.iterations}")
            # Build Python with current nodes/supernodes
            starting_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()

            self.build_python()

            # Generate Stats
            self.generate_stats()
            # Generate new set of supernodes

            self.generate_supernodes_from_stats()

            ending_supernodes = SuperNodeAnalysis.get_supernode_executor_cases()
            added = ending_supernodes - starting_supernodes
            removed = starting_supernodes - ending_supernodes
            retained = starting_supernodes & ending_supernodes

            if added:
                self.dprint(2, f"Added {len(added)} supernodes")
                self.dprint(3, added)

            if removed:
                self.dprint(2, f"Removed {len(removed)} supernodes")
                self.dprint(3, removed)

            if retained:
                self.dprint(2, f"Retained {len(retained)} supernodes")
                self.dprint(3, retained)

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
            ]
        , stdout=subprocess.DEVNULL)

        # self.run_command_list([["make", "regen-uop-ids"] "regen-uop-metadata", "regen-exeuctor-cases", "regen-jit"]])
        # self.call_command_list([["./configure","--enable-experimental-jit","--enable-pystats",],])
        self.dprint(2, f"Running `make -j{self.threads}")
        subprocess.run(["make", f"-j{self.threads}"], stdout=subprocess.DEVNULL)
        #self.run_command_list([["make", f"-j{self.threads}"]])

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

        # self.run_command_list(commands)

    def generate_stats(self) -> None:
        self.dprint(1, "Generating statistics")
        if (venv := Path("./venv")).exists() and venv.is_dir():
            self.dprint(2, "Deleting old venv")
            shutil.rmtree(venv)

        if self.pyperf_command == None:
            self.pyperf_command = [
                "./venv/bin/python",
                "-m",
                "pyperformance",
                "run",
                "--python",
                str(ROOT / "python"),
            ]
            #if self.verbose:
            #    self.pyperf_command.append(f"-{'v'*self.verbose}")
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
            self.dprint(1, f"Could not remove all of /tmp/py_stats. Failed with error: {e}")

        self.call_command_list(
            [
                ["python", "-m", "venv", "venv"],
                ["./venv/bin/python", "-m", "pip", "install", "pyperformance"],
                self.pyperf_command,
            ],
            kwargs={
                "cwd": ROOT,
            },
        )

    def generate_supernodes_from_stats(self):
        self.dprint(1, "Generating supernodes from stats")
        analysis = SuperNodeAnalysis(verbose=self.verbose)

        self.dprint(2, "Collating statistics")
        stats = analysis.get_stats([DEFAULT_DIR])
        self.dprint(2, "Calculating supernodes from stats")
        new_supers = analysis.calculate_supernodes(stats)
        self.dprint(2, f"Updating supernodes.c with {len(new_supers)} potential supernodes")
        analysis.update_supernodes_c(new_supers)

        self.dprint(2, "Running command `make regen-uop-ids`")
        subprocess.check_call(["make", "regen-uop-ids"], stdout=subprocess.DEVNULL)
        self.dprint(2, "Running command `make regen-uop-metadata`")
        subprocess.check_call(["make", "regen-uop-metadata"], stdout=subprocess.DEVNULL)
        self.dprint(2, "Running command `make regen-executor-cases`")
        subprocess.check_call(["make", "regen-executor-cases"], stdout=subprocess.DEVNULL)
        self.dprint(2, "Running command `make regen-jit`")
        subprocess.check_call(["make", "regen-jit"], stdout=subprocess.DEVNULL)

    def do_command_func(self, command_list: list[str], func, kwargs=None, ignore_errors = False):
        for command in command_list:
            self.dprint(2, f"Running {command=} with function {func.__name__}")
            if kwargs == None:
                kwargs = self.default_kwargs
            result: subprocess.CompletedProcess = func(command, {"stdout": subprocess.DEVNULL}.update(kwargs))
            if not ignore_errors and result.returncode: raise RuntimeError(f"Command {command} exiting with error code {result.returncode}")

    run_command_list = functools.partialmethod(do_command_func, func=subprocess.run)
    call_command_list = functools.partialmethod(do_command_func, func=subprocess.call, ignore_errors=True)


def _update(args: argparse.Namespace) -> None:
    analysis = SuperNodeAnalysis(dry_run=args.dry_run, verbose=args.verbose)
    analysis.output_pair_stats(args.inputs)


def _iterate(args: argparse.Namespace) -> None:
    manager = SuperNodeIterator(
        pyperf_command=args.perf_command,
        threads=args.jobs,
        verbose=args.verbose,
        iterations=args.iterations,
        benchmarks=args.benchmarks,
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

    subparsers = parser.add_subparsers(help="Sub-command help")

    update_parser = subparsers.add_parser(
        "update", help="Update superinstructions based on pystats", parents=[parser]
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

    update_parser.add_argument(
        "--dry-run", action="store_true", help="Do not update supernodes.c"
    )

    update_parser.set_defaults(func=_update)

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
    #I = SuperNodeIterator(verbose=True, threads=8)
    #I.generate_supernodes_from_stats()
    main()
    # I.iterate_supernodes()
    # subprocess.call(["./configure","--enable-experimental-jit","--enable-pystats",])

    # subprocess.call(["./venv/bin/python", "-m", "pyperformance", "run", "--python", "/home/jglass/Documents/cpython/python","-b", "spectral_norm"])
