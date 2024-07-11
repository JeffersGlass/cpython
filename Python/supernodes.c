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
	super() = _COPY + _COPY;
	super() = _COPY + _BINARY_SUBSCR_LIST_INT + _LOAD_FAST;
	super() = _COPY + _COPY + _BINARY_SUBSCR_LIST_INT + _LOAD_FAST_0;
	super() = _SWAP + _SWAP;
	super() = _SWAP + _STORE_SUBSCR_LIST_INT;
	super() = _SWAP + _STORE_SUBSCR_LIST_INT + _LOAD_FAST + _LOAD_CONST_INLINE_BORROW;
	super() = _SWAP + _SWAP + _STORE_SUBSCR_LIST_INT + _JUMP_TO_TOP;
	super() = _UNPACK_SEQUENCE_LIST + _STORE_FAST;
	super() = _UNPACK_SEQUENCE_TUPLE + _UNPACK_SEQUENCE_LIST;
	super() = _UNPACK_SEQUENCE_TUPLE + _STORE_FAST;
	super() = _UNPACK_SEQUENCE_TUPLE + _UNPACK_SEQUENCE_LIST + _STORE_FAST_5 + _STORE_FAST_6 + _STORE_FAST_7;
	super() = _UNPACK_SEQUENCE_TWO_TUPLE + _UNPACK_SEQUENCE_TUPLE;
	super() = _COLD_EXIT + _COLD_EXIT;
	super() = _GUARD_BOTH_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP;
	super() = _ITER_CHECK_LIST + _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST;
	super() = _ITER_CHECK_RANGE + _GUARD_NOT_EXHAUSTED_RANGE;
	super() = _LOAD_FAST + _GUARD_BOTH_FLOAT;
	super() = _LOAD_FAST + _LOAD_FAST;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_FAST;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _LOAD_FAST;
	super() = _LOAD_FAST + _LOAD_FAST + _GUARD_NOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT;
	super() = _START_EXECUTOR + _TIER2_RESUME_CHECK;
	super() = _STORE_FAST + _UNPACK_SEQUENCE_LIST;
	super() = _STORE_FAST + _UNPACK_SEQUENCE_TUPLE;
	super() = _STORE_FAST + _LOAD_FAST;
	super() = _STORE_FAST + _STORE_FAST;
	super() = _STORE_FAST + _LOAD_FAST + _LOAD_CONST_INLINE_BORROW;
	super() = _STORE_FAST + _STORE_FAST + _LOAD_FAST_5;
	super() = _TIER2_RESUME_CHECK + _ITER_CHECK_LIST;
	super() = _TIER2_RESUME_CHECK + _ITER_CHECK_RANGE;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_FAST + _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_CONST_INLINE;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP + _SWAP;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _LOAD_FAST + _LOAD_FAST;
	super() = _BINARY_SUBSCR_LIST_INT + _LOAD_FAST + _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT;
	super() = _BINARY_SUBSCR_LIST_INT + _LOAD_FAST + _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _COPY + _BINARY_SUBSCR_LIST_INT + _LOAD_FAST_0 + _LOAD_FAST;
	super() = _COPY + _BINARY_SUBSCR_LIST_INT + _LOAD_FAST_0 + _LOAD_FAST + _GUARD_TOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT;
	super() = _GUARD_BOTH_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _STORE_FAST + _LOAD_FAST;
	super() = _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP + _SWAP;
	super() = _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP + _SWAP + _STORE_SUBSCR_LIST_INT + _JUMP_TO_TOP;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _UNPACK_SEQUENCE_TUPLE;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _UNPACK_SEQUENCE_TWO_TUPLE;
	super() = _ITER_NEXT_RANGE + _STORE_FAST_4 + _LOAD_FAST_3 + _SET_IP + _GET_ITER + _CHECK_VALIDITY;
	super() = _LOAD_FAST_3 + _SET_IP + _GET_ITER + _CHECK_VALIDITY + _ITER_CHECK_LIST;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_CONST_INLINE + _SET_IP + _BINARY_OP + _CHECK_VALIDITY;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_SUBTRACT_FLOAT + _SWAP;
	super() = _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT + _STORE_FAST + _LOAD_FAST_0;
	super() = _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT + _STORE_FAST + _LOAD_FAST_6;
	super() = _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT + _STORE_FAST + _LOAD_FAST_7;
	super() = _LOAD_FAST + _GUARD_NOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _STORE_FAST;
	super() = _LOAD_FAST + _GUARD_TOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP;
	super() = _LOAD_FAST + _LOAD_CONST_INLINE_BORROW + _COPY;
	super() = _POP_TOP + _LOAD_FAST_2 + _SET_IP + _GET_ITER + _CHECK_VALIDITY + _ITER_CHECK_LIST;
	super() = _SET_IP + _BINARY_OP + _CHECK_VALIDITY + _GUARD_BOTH_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _STORE_FAST;
	super() = _STORE_FAST + _LOAD_FAST_0 + _LOAD_FAST;
	super() = _STORE_FAST + _LOAD_FAST_5 + _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _STORE_FAST + _LOAD_FAST_6 + _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _STORE_FAST + _LOAD_FAST_7 + _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _STORE_SUBSCR_LIST_INT + _LOAD_FAST + _LOAD_CONST_INLINE_BORROW + _COPY;
	super() = _SWAP + _STORE_SUBSCR_LIST_INT + _JUMP_TO_TOP + _TIER2_RESUME_CHECK;
	super() = _UNPACK_SEQUENCE_LIST + _STORE_FAST_5 + _STORE_FAST_6 + _STORE_FAST_7 + _STORE_FAST;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_FAST;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP;
	super() = _BINARY_OP_MULTIPLY_FLOAT + _LOAD_FAST;
	super() = _BINARY_SUBSCR_LIST_INT + _LOAD_FAST;
	super() = _COPY + _BINARY_SUBSCR_LIST_INT + _LOAD_FAST_0;
	super() = _GUARD_BOTH_FLOAT + _BINARY_OP_MULTIPLY_FLOAT + _STORE_FAST;
	super() = _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT + _SWAP;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST;
	super() = _ITER_NEXT_RANGE + _STORE_FAST_4;
	super() = _LOAD_FAST_3 + _SET_IP + _GET_ITER + _CHECK_VALIDITY;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _BINARY_OP_ADD_FLOAT + _LOAD_CONST_INLINE;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_ADD_FLOAT;
	super() = _LOAD_FAST + _BINARY_OP_MULTIPLY_FLOAT + _GUARD_NOS_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _LOAD_FAST + _GUARD_BOTH_FLOAT + _BINARY_OP_SUBTRACT_FLOAT;
	super() = _LOAD_FAST + _GUARD_NOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT;
	super() = _LOAD_FAST + _GUARD_TOS_FLOAT + _BINARY_OP_MULTIPLY_FLOAT;
	super() = _LOAD_FAST + _LOAD_CONST_INLINE_BORROW;
	super() = _POP_TOP + _LOAD_FAST_2 + _SET_IP + _GET_ITER + _CHECK_VALIDITY;
	super() = _SET_IP + _BINARY_OP + _CHECK_VALIDITY;
	super() = _STORE_FAST + _LOAD_FAST_0;
	super() = _STORE_FAST + _LOAD_FAST_5;
	super() = _STORE_FAST + _LOAD_FAST_6;
	super() = _STORE_FAST + _LOAD_FAST_7;
	super() = _STORE_SUBSCR_LIST_INT + _LOAD_FAST + _LOAD_CONST_INLINE_BORROW;
	super() = _SWAP + _STORE_SUBSCR_LIST_INT + _JUMP_TO_TOP;
	super() = _UNPACK_SEQUENCE_LIST + _STORE_FAST_5 + _STORE_FAST_6 + _STORE_FAST_7;

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

// Future families go below this point //