import argparse
from pathlib import Path
from typing import TypeAlias

from summarize_stats import Stats, DEFAULT_DIR, load_raw_data
ROOT = Path(__file__).parent.parent.parent
DEFAULT_SUPERNODES_INPUT = (ROOT / "Python/supernodes.c").absolute().as_posix()

PRE = """
// This file contains instruction definitions.
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

THRESHHOLD_ADD = .01
THRESHHOLD_DROP = .001

type PairCount = dict[tuple[str, str], int]

def output_pair_stats(inputs: list[Path], verbose: bool = False):
    match len(inputs):
        case 1:
            data = load_raw_data(Path(inputs[0]))
            stats = Stats(data)
            new_supers = calculate_supernodes(stats, verbose)
            update_supernodes_c(new_supers, verbose)

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
    return to_add



    #print(stats.get_opcode_stats("uops").get_execution_counts())
    #print(current_supernodes_seen)
    #print(to_add)

def update_supernodes_c(supernodes: list[tuple[str]], verbose: bool = False) -> None:
    new_supers = (f"super() = {" + ".join(uop for uop in node)};" for node in supernodes)

    with open(DEFAULT_SUPERNODES_INPUT, "w") as f:
        f.writelines(PRE)
        f.writelines("\t" + line + "\n" for line in new_supers)
        f.writelines(POST)

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
