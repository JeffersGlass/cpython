#ifndef Py_INTERNAL_JIT_H
#define Py_INTERNAL_JIT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_BUILD_CORE
#  error "this header requires Py_BUILD_CORE define"
#endif

#ifdef _Py_JIT

typedef _Py_CODEUNIT *(*jit_func)(_PyInterpreterFrame *frame, PyObject **stack_pointer, PyThreadState *tstate);

int _PyJIT_Compile(_PyExecutorObject *executor, const _PyUOpInstruction *trace, size_t length);
void _PyJIT_Free(_PyExecutorObject *executor);
_PyUOpInstruction _PyJIT_Combine(const _PyUOpInstruction *uops, uint16_t start_index, uint16_t count, uint16_t supernode_index);
_PyUOpInstruction _PyJIT_Format_Inst(uint16_t opcode, uint16_t format, uint32_t temp_target, uint16_t oparg, uint64_t operand);

#endif  // _Py_JIT

#ifdef __cplusplus
}
#endif

#endif // !Py_INTERNAL_JIT_H
