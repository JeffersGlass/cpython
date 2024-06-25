
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
    super() = _RETURN_VALUE + _LOAD_FAST_5;
	super() = _RESUME_CHECK + _LOAD_CONST_INLINE;
	//super() = _UNPACK_SEQUENCE_TWO_TUPLE + _STORE_FAST_4; // Causes test failure?
	super() = _SET_IP + _BINARY_OP;
	super() = _SET_IP + _CHECK_FUNCTION_VERSION;
	super() = _SET_IP + _FOR_ITER_TIER_TWO;
	super() = _BINARY_OP + _CHECK_VALIDITY;
	super() = _BINARY_OP_ADD_FLOAT + _STORE_FAST_3;
	super() = _BINARY_OP_ADD_INT + _SET_IP;
    super() = _BINARY_OP_ADD_INT + _BINARY_OP_MULTIPLY_INT;
	super() = _BINARY_OP_ADD_INT + _LOAD_CONST_INLINE_BORROW;
	super() = _BINARY_OP_ADD_INT + _LOAD_FAST_0;
	super() = _BINARY_OP_MULTIPLY_INT + _LOAD_CONST_INLINE_BORROW;
	super() = _CHECK_FUNCTION + _LOAD_CONST_INLINE_WITH_NULL;
	super() = _CHECK_FUNCTION_EXACT_ARGS + _CHECK_STACK_SPACE_OPERAND;
    super() = _CHECK_FUNCTION_VERSION + _CHECK_FUNCTION_EXACT_ARGS;
	super() = _CHECK_STACK_SPACE_OPERAND + _INIT_CALL_PY_EXACT_ARGS_2;
	super() = _CHECK_VALIDITY + _RETURN_VALUE;
	super() = _CHECK_VALIDITY + _UNPACK_SEQUENCE_TWO_TUPLE;
	super() = _CHECK_VALIDITY + _LOAD_FAST_0;
    super() = _FOR_ITER_TIER_TWO + _CHECK_VALIDITY;
	//super() = _GUARD_BOTH_INT + _BINARY_OP_ADD_INT; // Segfaults?
    super() = _GUARD_NOS_INT + _LOAD_CONST_INLINE_BORROW;
    super() = _INIT_CALL_PY_EXACT_ARGS_2 + _SAVE_RETURN_OFFSET;
	super() = _JUMP_TO_TOP + _TIER2_RESUME_CHECK;
	super() = _LOAD_CONST_INLINE + _LOAD_FAST_0;
	super() = _LOAD_CONST_INLINE_BORROW + _SET_IP;
	super() = _LOAD_CONST_INLINE_BORROW + _BINARY_OP_ADD_INT;
	super() = _LOAD_FAST_0 + _GUARD_NOS_INT;
	super() = _LOAD_FAST_0 + _LOAD_FAST_1;
	super() = _LOAD_FAST_1 + _BINARY_OP_ADD_INT;
	super() = _LOAD_FAST_1 + _GUARD_BOTH_INT;
	super() = _LOAD_FAST_3 + _CHECK_FUNCTION;
	super() = _PUSH_FRAME + _RESUME_CHECK;
	super() = _SAVE_RETURN_OFFSET + _PUSH_FRAME;
	super() = _STORE_FAST_3 + _JUMP_TO_TOP;
	super() = _STORE_FAST_4 + _STORE_FAST_5;
	super() = _STORE_FAST_5 + _LOAD_FAST_3;
	super() = _TIER2_RESUME_CHECK + _SET_IP;

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