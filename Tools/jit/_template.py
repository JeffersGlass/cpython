# Generate template_x.c files for any number of opcodes
# Based on 'template.c' by B. Bucher

import argparse
from pathlib import Path
import tempfile
from typing import Generator


def create_template_file(num_opcodes, path: Path | str):
    with open(path, "w") as f:
        for val in gen_template_text(num_opcodes):
            f.write(val)

    return path

def gen_template_text(num_opcodes: int) -> Generator[str, None, None]:
    if num_opcodes < 1:
        raise ValueError("num_opcodes must be 1 or greater")
    
    yield """
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
#define DEOPT_IF(COND, INSTNAME) \
    do {                         \
        if ((COND)) {            \
            goto deoptimize;     \
        }                        \
    } while (0)

#undef ENABLE_SPECIALIZATION
#define ENABLE_SPECIALIZATION (0)

#undef GOTO_ERROR
#define GOTO_ERROR(LABEL)        \
    do {                         \
        goto LABEL ## _tier_two; \
    } while (0)

#undef GOTO_TIER_TWO
#define GOTO_TIER_TWO(EXECUTOR) \
do {  \
    OPT_STAT_INC(traces_executed);                \
    __attribute__((musttail))                     \
    return ((jit_func)((EXECUTOR)->jit_code))(frame, stack_pointer, tstate); \
} while (0)

#undef GOTO_TIER_ONE
#define GOTO_TIER_ONE(TARGET) \
do {  \
    _PyFrame_SetStackPointer(frame, stack_pointer); \
    return TARGET; \
} while (0)

#undef LOAD_IP
#define LOAD_IP(UNUSED) \
    do {                \
    } while (0)

#define PATCH_VALUE(TYPE, NAME, ALIAS)  \
    PyAPI_DATA(void) ALIAS;             \
    TYPE NAME = (TYPE)(uint64_t)&ALIAS;

#define REASSIGN_VALUE(TYPE, NAME, ALIAS)  \
    extern void ALIAS;                    \
    NAME = (TYPE)(uint64_t)&ALIAS;

#define PATCH_JUMP(ALIAS)                                    \
do {                                                         \
    PyAPI_DATA(void) ALIAS;                                  \
    __attribute__((musttail))                                \
    return ((jit_func)&ALIAS)(frame, stack_pointer, tstate); \
} while (0)

_Py_CODEUNIT *
_JIT_ENTRY(_PyInterpreterFrame *frame, PyObject **stack_pointer, PyThreadState *tstate)
{
    // Locals that the instruction implementations expect to exist:
    PATCH_VALUE(_PyExecutorObject *, current_executor, _JIT_EXECUTOR)
    int oparg;
    _PyUOpInstruction *next_uop;
    PATCH_VALUE(uint32_t, _target, _JIT_TARGET0)
    PATCH_VALUE(uint16_t, _exit_index, _JIT_EXIT_INDEX0)
    int opcode;
    int uopcode;
"""
    for index in range(num_opcodes):
        yield f"""
    #undef CURRENT_OPARG
    #define CURRENT_OPARG() (_oparg{index})
    #undef CURRENT_OPERAND
    #define CURRENT_OPERAND() (_operand{index})

    #undef JUMP_TO_JUMP_TARGET
    #define JUMP_TO_JUMP_TARGET() PATCH_JUMP(_JIT_JUMP_TARGET{index})

    #undef JUMP_TO_ERROR
    #define JUMP_TO_ERROR() PATCH_JUMP(_JIT_ERROR_TARGET{index})
    
    int opcode{index} = _JIT_OPCODE{index};
    uopcode = opcode{index};
    PATCH_VALUE(uint16_t, _oparg{index}, _JIT_OPARG{index})
    #if SIZEOF_VOID_P == 8
        PATCH_VALUE(uint64_t, _operand{index}, _JIT_OPERAND{index})
    #else
        assert(SIZEOF_VOID_P == 4);
        PATCH_VALUE(uint32_t, _operand_hi{index}, _JIT_OPERAND_HI{index})
        PATCH_VALUE(uint32_t, _operand_lo{index}, _JIT_OPERAND_LO{index})
        uint64_t _operand{index} = ((uint64_t)_operand_hi{index} << 32) | _operand_lo{index};
    #endif
    {f'REASSIGN_VALUE(uint32_t, _target, _JIT_TARGET{index});' if index > 0 else ''}
    {f'REASSIGN_VALUE(uint16_t, _exit_index, _JIT_EXIT_INDEX{index});' if index > 0 else ''}

    OPT_STAT_INC(uops_executed);
    UOP_STAT_INC(uopcode, execution_count);

    if (uopcode == _JUMP_TO_TOP) {{
        CHECK_EVAL_BREAKER();
        PATCH_JUMP(_JIT_TOP);
    }}    
    switch (uopcode) {{
#include "executor_cases.c.h"
        default:
            Py_UNREACHABLE();
    }}
""" # End itereting over each opcode

    yield """
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
}"""

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("num_opcodes", type=int, help="How many opcodes will this template accomodate?")
    parser.add_argument("-p", "--path", default=None, required=False, help="The file to place this template into")

    args = parser.parse_args()

    path = args.path or Path(Path.cwd()) / f"template_{args.num_opcodes}.c"

    create_template_file(args.num_opcodes, path)
    