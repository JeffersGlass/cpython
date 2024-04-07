
#include "Python.h"

#include "pycore_backoff.h"
#include "pycore_call.h"
#include "pycore_ceval.h"
#include "pycore_cell.h"
#include "pycore_dict.h"
#include "pycore_emscripten_signal.h"
#include "pycore_intrinsics.h"
#include "pycore_jit.h"
#include "pycore_long.h"
#include "pycore_opcode_metadata.h"
#include "pycore_opcode_utils.h"
#include "pycore_optimizer.h"
#include "pycore_range.h"
#include "pycore_setobject.h"
#include "pycore_sliceobject.h"
#include "pycore_descrobject.h"

#include "ceval_macros.h"

#undef CURRENT_OPARG
#define CURRENT_OPARG() (_oparg)

#undef CURRENT_OPERAND
#define CURRENT_OPERAND() (_operand)

#undef DEOPT_IF
#define DEOPT_IF(COND, INSTNAME)     do {                                 if ((COND)) {                        goto deoptimize;             }                            } while (0)

#undef ENABLE_SPECIALIZATION
#define ENABLE_SPECIALIZATION (0)

#undef GOTO_ERROR
#define GOTO_ERROR(LABEL)            do {                                 goto LABEL ## _tier_two;     } while (0)

#undef GOTO_TIER_TWO
#define GOTO_TIER_TWO(EXECUTOR) do {      OPT_STAT_INC(traces_executed);                    __attribute__((musttail))                         return ((jit_func)((EXECUTOR)->jit_code))(frame, stack_pointer, tstate); } while (0)

#undef GOTO_TIER_ONE
#define GOTO_TIER_ONE(TARGET) do {      _PyFrame_SetStackPointer(frame, stack_pointer);     return TARGET; } while (0)

#undef LOAD_IP
#define LOAD_IP(UNUSED)     do {                    } while (0)

#define PATCH_VALUE(TYPE, NAME, ALIAS)      PyAPI_DATA(void) ALIAS;                 TYPE NAME = (TYPE)(uint64_t)&ALIAS;

#define PATCH_JUMP(ALIAS)                                    do {                                                             PyAPI_DATA(void) ALIAS;                                      __attribute__((musttail))                                    return ((jit_func)&ALIAS)(frame, stack_pointer, tstate); } while (0)

#undef JUMP_TO_JUMP_TARGET
#define JUMP_TO_JUMP_TARGET() PATCH_JUMP(_JIT_JUMP_TARGET)

#undef JUMP_TO_ERROR
#define JUMP_TO_ERROR() PATCH_JUMP(_JIT_ERROR_TARGET)

_Py_CODEUNIT *
_JIT_ENTRY(_PyInterpreterFrame *frame, PyObject **stack_pointer, PyThreadState *tstate)
{
    // Locals that the instruction implementations expect to exist:
    PATCH_VALUE(_PyExecutorObject *, current_executor, _JIT_EXECUTOR)
    int oparg;
    _PyUOpInstruction *next_uop;
    PATCH_VALUE(uint32_t, _target, _JIT_TARGET0)
    PATCH_VALUE(uint16_t, _exit_index, _JIT_EXIT_INDEX)
    int opcode;

    #undef CURRENT_OPARG
    #define CURRENT_OPARG() (_oparg0)
    #undef CURRENT_OPERAND
    #define CURRENT_OPERAND() (_operand0)
    
    int opcode0 = _JIT_OPCODE0;
    int uopcode = opcode0;
    PATCH_VALUE(uint16_t, _oparg0, _JIT_OPARG0)
    #if SIZEOF_VOID_P == 8
        PATCH_VALUE(uint64_t, _operand0, _JIT_OPERAND0)
    #else
        assert(SIZEOF_VOID_P == 4);
        PATCH_VALUE(uint32_t, _operand_hi0, _JIT_OPERAND_HI0)
        PATCH_VALUE(uint32_t, _operand_lo0, _JIT_OPERAND_LO0)
        uint64_t _operand0 = ((uint64_t)_operand_hi0 << 32) | _operand_lo0;
    #endif
    
    

    OPT_STAT_INC(uops_executed);
    UOP_STAT_INC(uopcode, execution_count);

    if (uopcode == _JUMP_TO_TOP) {
        CHECK_EVAL_BREAKER();
        PATCH_JUMP(_JIT_TOP);
    }    
    switch (uopcode) {
#include "executor_cases.c.h"
        default:
            Py_UNREACHABLE();
    }

    #undef CURRENT_OPARG
    #define CURRENT_OPARG() (_oparg1)
    #undef CURRENT_OPERAND
    #define CURRENT_OPERAND() (_operand1)
    
    int opcode1 = _JIT_OPCODE1;
    int uopcode = opcode1;
    PATCH_VALUE(uint16_t, _oparg1, _JIT_OPARG1)
    #if SIZEOF_VOID_P == 8
        PATCH_VALUE(uint64_t, _operand1, _JIT_OPERAND1)
    #else
        assert(SIZEOF_VOID_P == 4);
        PATCH_VALUE(uint32_t, _operand_hi1, _JIT_OPERAND_HI1)
        PATCH_VALUE(uint32_t, _operand_lo1, _JIT_OPERAND_LO1)
        uint64_t _operand1 = ((uint64_t)_operand_hi1 << 32) | _operand_lo1;
    #endif
    REASSIGN_VALUE(uint32_t, _target, _JIT_TARGET1);
    REASSIGN_VALUE(uint16_t, _exit_index, _JIT_EXIT_INDEX1);

    OPT_STAT_INC(uops_executed);
    UOP_STAT_INC(uopcode, execution_count);

    if (uopcode == _JUMP_TO_TOP) {
        CHECK_EVAL_BREAKER();
        PATCH_JUMP(_JIT_TOP);
    }    
    switch (uopcode) {
#include "executor_cases.c.h"
        default:
            Py_UNREACHABLE();
    }

    PATCH_JUMP(_JIT_CONTINUE);
    // Labels that the instruction implementations expect to exist:

error_tier_two:
    tstate->previous_executor = (PyObject *)current_executor;
    GOTO_TIER_ONE(NULL);
exit_to_tier1:
    tstate->previous_executor = (PyObject *)current_executor;
    GOTO_TIER_ONE(_PyCode_CODE(_PyFrame_GetCode(frame)) + _target);
exit_to_trace:
    {
        _PyExitData *exit = &current_executor->exits[_exit_index];
        Py_INCREF(exit->executor);
        tstate->previous_executor = (PyObject *)current_executor;
        GOTO_TIER_TWO(exit->executor);
    }
}