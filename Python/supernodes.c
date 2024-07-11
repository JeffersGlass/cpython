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
	super() = _TO_BOOL_NONE + _POP_TOP;
	super() = _DYNAMIC_EXIT + _START_EXECUTOR;
	super() = _FOR_ITER_GEN_FRAME + _PUSH_FRAME;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST;
	super() = _GUARD_NOT_EXHAUSTED_TUPLE + _ITER_NEXT_TUPLE;
	super() = _JUMP_TO_TOP + _TIER2_RESUME_CHECK;
	super() = _LOAD_FAST_2 + _SET_IP;
	super() = _LOAD_FAST_2 + _LOAD_FAST_1 + _SET_IP;
	super() = _PUSH_FRAME + _DYNAMIC_EXIT;
	super() = _SAVE_RETURN_OFFSET + _PUSH_FRAME;
	super() = _TIER2_RESUME_CHECK + _POP_TOP;
	super() = _CHECK_VALIDITY_AND_SET_IP + _LOAD_ATTR + _CHECK_VALIDITY_AND_SET_IP + _BINARY_OP + _CHECK_VALIDITY_AND_SET_IP + _CHECK_FUNCTION_VERSION;
	super() = _BINARY_OP + _CHECK_VALIDITY_AND_SET_IP;
	super() = _BUILD_LIST + _LOAD_FAST_0 + _GUARD_TYPE_VERSION;
	super() = _CALL_BUILTIN_FAST + _CHECK_PERIODIC;
	super() = _CALL_BUILTIN_O + _CHECK_PERIODIC;
	super() = _CALL_METHOD_DESCRIPTOR_O + _CHECK_PERIODIC;
	super() = _CALL_NON_PY_GENERAL + _CHECK_PERIODIC;
	super() = _CHECK_FUNCTION_EXACT_ARGS + _INIT_CALL_PY_EXACT_ARGS_1;
	super() = _CHECK_PERIODIC + _CHECK_VALIDITY;
	super() = _CHECK_PERIODIC + _CHECK_VALIDITY_AND_SET_IP;
	super() = _CHECK_STACK_SPACE_OPERAND + _INIT_CALL_PY_EXACT_ARGS_0 + _SAVE_RETURN_OFFSET + _PUSH_FRAME;
	super() = _CHECK_STACK_SPACE_OPERAND + _INIT_CALL_PY_EXACT_ARGS_1 + _SAVE_RETURN_OFFSET + _PUSH_FRAME;
	super() = _CHECK_STACK_SPACE + _INIT_CALL_PY_EXACT_ARGS_1;
	super() = _CHECK_VALIDITY_AND_SET_IP + _GET_ITER;
	super() = _CHECK_VALIDITY_AND_SET_IP + _LOAD_ATTR + _CHECK_VALIDITY_AND_SET_IP + _BINARY_OP + _CHECK_VALIDITY_AND_SET_IP;
	super() = _CHECK_VALIDITY + _LIST_APPEND + _JUMP_TO_TOP;
	super() = _CHECK_VALIDITY + _LOAD_CONST_INLINE_BORROW;
	super() = _CHECK_VALIDITY + _LOAD_FAST_0;
	super() = _CHECK_VALIDITY + _LOAD_FAST_1 + _SET_IP;
	super() = _CHECK_VALIDITY + _LOAD_FAST_2 + _SET_IP;
	super() = _CHECK_VALIDITY + _LOAD_FAST_4;
	super() = _CHECK_VALIDITY + _LOAD_FAST_5 + _SET_IP;
	super() = _CHECK_VALIDITY + _POP_TOP;
	super() = _CHECK_VALIDITY + _STORE_FAST;
	super() = _CHECK_VALIDITY + _STORE_FAST_1;
	super() = _CHECK_VALIDITY + _STORE_FAST_2;
	super() = _CHECK_VALIDITY + _STORE_FAST_3;
	super() = _CHECK_VALIDITY + _STORE_FAST_4 + _LOAD_FAST_3 + _LOAD_FAST_4 + _LOAD_FAST_2 + _BUILD_TUPLE;
	super() = _CHECK_VALIDITY + _STORE_FAST_5 + _LOAD_FAST_5;
	super() = _CONTAINS_OP + _CHECK_VALIDITY;
	super() = _GET_ITER + _CHECK_VALIDITY;
	super() = _GUARD_BOTH_INT + _BINARY_OP_ADD_INT;
	super() = _GUARD_BOTH_UNICODE + _COMPARE_OP_STR;
	super() = _GUARD_DORV_NO_DICT + _STORE_ATTR_INSTANCE_VALUE;
	super() = _GUARD_IS_FALSE_POP + _JUMP_TO_TOP;
	super() = _GUARD_IS_FALSE_POP + _LOAD_FAST_0;
	super() = _GUARD_IS_FALSE_POP + _LOAD_FAST_3 + _LOAD_FAST_2 + _SET_IP;
	super() = _GUARD_IS_NONE_POP + _LOAD_FAST_0;
	super() = _GUARD_IS_NOT_NONE_POP + _LOAD_FAST_3;
	super() = _GUARD_IS_TRUE_POP + _LOAD_CONST_INLINE_WITH_NULL + _LOAD_FAST_0 + _LOAD_FAST_1;
	super() = _GUARD_IS_TRUE_POP + _LOAD_FAST_0;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _STORE_FAST_2;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _STORE_FAST_3 + _LOAD_FAST_3 + _LOAD_FAST_0;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _STORE_FAST_4;
	super() = _GUARD_NOT_EXHAUSTED_LIST + _ITER_NEXT_LIST + _STORE_FAST_5;
	super() = _GUARD_NOT_EXHAUSTED_TUPLE + _ITER_NEXT_TUPLE + _STORE_FAST_4;
	super() = _GUARD_NOT_EXHAUSTED_TUPLE + _ITER_NEXT_TUPLE + _STORE_FAST_5;
	super() = _INIT_CALL_PY_EXACT_ARGS_0 + _SAVE_RETURN_OFFSET + _PUSH_FRAME + _RESUME_CHECK;
	super() = _INIT_CALL_PY_EXACT_ARGS_2 + _SAVE_RETURN_OFFSET + _PUSH_FRAME;
	super() = _ITER_NEXT_LIST + _STORE_FAST_3 + _LOAD_FAST_3 + _GUARD_IS_NOT_NONE_POP + _LOAD_FAST_3 + _LIST_APPEND + _JUMP_TO_TOP;
	super() = _LIST_APPEND + _JUMP_TO_TOP;
	super() = _LOAD_ATTR_INSTANCE_VALUE_0 + _LOAD_FAST_0;
	super() = _LOAD_ATTR_INSTANCE_VALUE_0 + _LOAD_FAST_1;
	super() = _LOAD_ATTR_INSTANCE_VALUE_0 + _LOAD_FAST_5;
	super() = _LOAD_ATTR_METHOD_NO_DICT + _LOAD_FAST_0;
	super() = _LOAD_ATTR_METHOD_NO_DICT + _LOAD_FAST_1;
	super() = _LOAD_ATTR_METHOD_NO_DICT + _LOAD_FAST_2;
	super() = _LOAD_ATTR_METHOD_WITH_VALUES + _LOAD_FAST_0 + _CHECK_MANAGED_OBJECT_HAS_VALUES;
	super() = _LOAD_ATTR_METHOD_WITH_VALUES + _LOAD_FAST_1;
	super() = _LOAD_ATTR + _CHECK_VALIDITY + _STORE_FAST_2;
	super() = _LOAD_CONST_INLINE_BORROW + _STORE_FAST_2;
	super() = _LOAD_CONST_INLINE + _LOAD_FAST_0;
	super() = _LOAD_CONST_INLINE + _PUSH_NULL;
	super() = _LOAD_CONST_INLINE_WITH_NULL + _LOAD_FAST_0 + _CHECK_MANAGED_OBJECT_HAS_VALUES;
	super() = _LOAD_CONST_INLINE_WITH_NULL + _LOAD_FAST_3;
	super() = _LOAD_CONST_INLINE_WITH_NULL + _LOAD_FAST_5 + _LOAD_FAST_2;
	super() = _LOAD_FAST_0 + _CHECK_MANAGED_OBJECT_HAS_VALUES;
	super() = _LOAD_FAST_0 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST_0 + _LOAD_FAST_1;
	super() = _LOAD_FAST_0 + _SET_IP;
	super() = _LOAD_FAST_1 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST_1 + _SET_IP;
	super() = _LOAD_FAST_2 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST_2 + _LOAD_CONST_INLINE_BORROW;
	super() = _LOAD_FAST_2 + _SET_IP + _CALL_BUILTIN_O + _CHECK_PERIODIC;
	super() = _LOAD_FAST_2 + _SET_IP + _CALL_METHOD_DESCRIPTOR_FAST + _CHECK_PERIODIC;
	super() = _LOAD_FAST_3 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST_3 + _LOAD_CONST_INLINE_BORROW;
	super() = _LOAD_FAST_3 + _LOAD_FAST_2;
	super() = _LOAD_FAST_3 + _LOAD_FAST_4;
	super() = _LOAD_FAST_4 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST_4 + _SET_IP;
	super() = _LOAD_FAST_5 + _SET_IP;
	super() = _LOAD_FAST_6 + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST + _GUARD_TYPE_VERSION;
	super() = _LOAD_FAST + _SET_IP;
	super() = _LOAD_FAST + _TO_BOOL_NONE + _POP_TOP;
	super() = _POP_TOP + _LOAD_FAST_1;
	super() = _PUSH_FRAME + _RESUME_CHECK;
	super() = _PUSH_NULL + _LOAD_FAST_2;
	super() = _RESUME_CHECK + _LOAD_FAST_0;
	super() = _RESUME_CHECK + _LOAD_FAST_1;
	super() = _RESUME_CHECK + _LOAD_FAST_2;
	super() = _SAVE_RETURN_OFFSET + _PUSH_FRAME + _CHECK_VALIDITY;
	super() = _SAVE_RETURN_OFFSET + _PUSH_FRAME + _RESUME_CHECK + _LOAD_FAST_0;
	super() = _SAVE_RETURN_OFFSET + _PUSH_FRAME + _RESUME_CHECK + _LOAD_FAST_1;
	super() = _SET_IP + _BINARY_SLICE;
	super() = _SET_IP + _BINARY_SUBSCR_DICT;
	super() = _SET_IP + _CALL_BUILTIN_FAST + _CHECK_PERIODIC;
	super() = _SET_IP + _CALL_METHOD_DESCRIPTOR_FAST + _CHECK_PERIODIC;
	super() = _SET_IP + _CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS;
	super() = _SET_IP + _CHECK_IS_NOT_PY_CALLABLE;
	super() = _SET_IP + _CONTAINS_OP_DICT;
	super() = _SET_IP + _LOAD_ATTR;
	super() = _SET_IP + _STORE_SUBSCR_DICT;
	super() = _SET_IP + _TO_BOOL + _CHECK_VALIDITY;
	super() = _STORE_FAST_1 + _STORE_FAST_2;
	super() = _STORE_FAST_2 + _CHECK_FUNCTION;
	super() = _STORE_FAST_2 + _LOAD_FAST_0;
	super() = _STORE_FAST_2 + _LOAD_FAST_1;
	super() = _STORE_FAST_2 + _LOAD_FAST_2;
	super() = _STORE_FAST_3 + _CHECK_FUNCTION;
	super() = _STORE_FAST_3 + _LOAD_FAST_3;
	super() = _STORE_FAST_4 + _LOAD_FAST_3;
	super() = _STORE_FAST_5 + _CHECK_FUNCTION;
	super() = _STORE_FAST_7 + _STORE_FAST + _LOAD_FAST_6 + _GUARD_TYPE_VERSION;
	super() = _STORE_FAST + _LOAD_FAST_6;
	super() = _TIER2_RESUME_CHECK + _LOAD_CONST_INLINE_BORROW;
	super() = _TIER2_RESUME_CHECK + _LOAD_FAST_0;
	super() = _TIER2_RESUME_CHECK + _SET_IP;
	super() = _UNPACK_SEQUENCE_TUPLE + _STORE_FAST_6;
	super() = _UNPACK_SEQUENCE_TWO_TUPLE + _STORE_FAST_1;

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