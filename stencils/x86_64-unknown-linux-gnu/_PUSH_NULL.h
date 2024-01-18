// $ /home/jglass/.pyenv/versions/3.12.1/bin/python Tools/jit/build_two_reuse.py x86_64-unknown-linux-gnu --all_ops

typedef enum {
    HoleKind_ARM64_RELOC_GOT_LOAD_PAGE21,
    HoleKind_ARM64_RELOC_GOT_LOAD_PAGEOFF12,
    HoleKind_ARM64_RELOC_UNSIGNED,
    HoleKind_IMAGE_REL_AMD64_ADDR64,
    HoleKind_IMAGE_REL_I386_DIR32,
    HoleKind_R_AARCH64_ABS64,
    HoleKind_R_AARCH64_CALL26,
    HoleKind_R_AARCH64_JUMP26,
    HoleKind_R_AARCH64_MOVW_UABS_G0_NC,
    HoleKind_R_AARCH64_MOVW_UABS_G1_NC,
    HoleKind_R_AARCH64_MOVW_UABS_G2_NC,
    HoleKind_R_AARCH64_MOVW_UABS_G3,
    HoleKind_R_X86_64_64,
    HoleKind_X86_64_RELOC_UNSIGNED,
} HoleKind;

typedef enum {
    HoleValue_CODE,
    HoleValue_CONTINUE,
    HoleValue_DATA,
    HoleValue_EXECUTOR,
    HoleValue_GOT,
    HoleValue_OPARG,
    HoleValue_OPERAND,
    HoleValue_TARGET,
    HoleValue_TOP,
    HoleValue_ZERO,
} HoleValue;

typedef struct {
    const uint64_t offset;
    const HoleKind kind;
    const HoleValue value;
    const void *symbol;
    const uint64_t addend;
} Hole;

typedef struct {
    const size_t body_size;
    const unsigned char * const body;
    const size_t holes_size;
    const Hole * const holes;
} Stencil;

typedef struct {
    const Stencil code;
    const Stencil data;
} StencilGroup;

// _PUSH_NULLplus_BEFORE_ASYNC_WITH
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BEFORE_ASYNC_WITH.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 d4                      movq    %rdx, %r12
// e: 48 89 f3                      movq    %rsi, %rbx
// 11: 49 89 fe                      movq    %rdi, %r14
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 000000000000001d:  R_X86_64_64  _PyObject_LookupSpecial
// 25: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000027:  R_X86_64_64  _PyRuntime
// 2f: 49 8d b5 68 a6 00 00          leaq    0xa668(%r13), %rsi
// 36: 31 ff                         xorl    %edi, %edi
// 38: ff d5                         callq   *%rbp
// 3a: 48 85 c0                      testq   %rax, %rax
// 3d: 0f 84 b7 00 00 00             je      0xfa <_JIT_ENTRY+0xfa>
// 43: 49 89 c7                      movq    %rax, %r15
// 46: 49 81 c5 a0 a6 00 00          addq    $0xa6a0, %r13           # imm = 0xA6A0
// 4d: 31 ff                         xorl    %edi, %edi
// 4f: 4c 89 ee                      movq    %r13, %rsi
// 52: ff d5                         callq   *%rbp
// 54: 49 8b 44 24 68                movq    0x68(%r12), %rax
// 59: 48 85 c0                      testq   %rax, %rax
// 5c: 74 18                         je      0x76 <_JIT_ENTRY+0x76>
// 5e: 48 83 78 08 00                cmpq    $0x0, 0x8(%rax)
// 63: 74 11                         je      0x76 <_JIT_ENTRY+0x76>
// 65: 49 8b 07                      movq    (%r15), %rax
// 68: 48 85 c0                      testq   %rax, %rax
// 6b: 7e 46                         jle     0xb3 <_JIT_ENTRY+0xb3>
// 6d: 85 c0                         testl   %eax, %eax
// 6f: 79 67                         jns     0xd8 <_JIT_ENTRY+0xd8>
// 71: e9 ca 00 00 00                jmp     0x140 <_JIT_ENTRY+0x140>
// 76: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000078:  R_X86_64_64  PyExc_TypeError
// 80: 48 8b 30                      movq    (%rax), %rsi
// 83: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 8b: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 8f: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000091:  R_X86_64_64  .rodata.str1.1+0x84
// 99: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 000000000000009b:  R_X86_64_64  _PyErr_Format
// a3: 4c 89 e7                      movq    %r12, %rdi
// a6: 31 c0                         xorl    %eax, %eax
// a8: 41 ff d0                      callq   *%r8
// ab: 49 8b 07                      movq    (%r15), %rax
// ae: 48 85 c0                      testq   %rax, %rax
// b1: 7f ba                         jg      0x6d <_JIT_ENTRY+0x6d>
// b3: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000b5:  R_X86_64_64  .rodata.str1.1
// bd: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000bf:  R_X86_64_64  _Py_NegativeRefcount
// c7: be 11 09 00 00                movl    $0x911, %esi            # imm = 0x911
// cc: 4c 89 fa                      movq    %r15, %rdx
// cf: ff d0                         callq   *%rax
// d1: 49 8b 07                      movq    (%r15), %rax
// d4: 85 c0                         testl   %eax, %eax
// d6: 78 68                         js      0x140 <_JIT_ENTRY+0x140>
// d8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000da:  R_X86_64_64  _Py_DECREF_DecRefTotal
// e2: ff d0                         callq   *%rax
// e4: 49 ff 0f                      decq    (%r15)
// e7: 75 57                         jne     0x140 <_JIT_ENTRY+0x140>
// e9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000eb:  R_X86_64_64  _Py_Dealloc
// f3: 4c 89 ff                      movq    %r15, %rdi
// f6: ff d0                         callq   *%rax
// f8: eb 46                         jmp     0x140 <_JIT_ENTRY+0x140>
// fa: 49 8b 44 24 68                movq    0x68(%r12), %rax
// ff: 48 85 c0                      testq   %rax, %rax
// 102: 74 07                         je      0x10b <_JIT_ENTRY+0x10b>
// 104: 48 83 78 08 00                cmpq    $0x0, 0x8(%rax)
// 109: 75 35                         jne     0x140 <_JIT_ENTRY+0x140>
// 10b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010d:  R_X86_64_64  PyExc_TypeError
// 115: 48 8b 30                      movq    (%rax), %rsi
// 118: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 120: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 124: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000126:  R_X86_64_64  .rodata.str1.1+0x39
// 12e: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000130:  R_X86_64_64  _PyErr_Format
// 138: 4c 89 e7                      movq    %r12, %rdi
// 13b: 31 c0                         xorl    %eax, %eax
// 13d: 41 ff d0                      callq   *%r8
// 140: 4c 29 f3                      subq    %r14, %rbx
// 143: 48 83 c3 c0                   addq    $-0x40, %rbx
// 147: 48 c1 eb 03                   shrq    $0x3, %rbx
// 14b: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 14f: 31 c0                         xorl    %eax, %eax
// 151: 48 83 c4 08                   addq    $0x8, %rsp
// 155: 5b                            popq    %rbx
// 156: 41 5c                         popq    %r12
// 158: 41 5d                         popq    %r13
// 15a: 41 5e                         popq    %r14
// 15c: 41 5f                         popq    %r15
// 15e: 5d                            popq    %rbp
// 15f: c3                            retq
// 160: 
static const unsigned char _PUSH_NULLplus_BEFORE_ASYNC_WITH_code_body[353] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd4, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8d, 0xb5, 0x68, 0xa6, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd5, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0xb7, 0x00, 0x00, 0x00, 0x49, 0x89, 0xc7, 0x49, 0x81, 0xc5, 0xa0, 0xa6, 0x00, 0x00, 0x31, 0xff, 0x4c, 0x89, 0xee, 0xff, 0xd5, 0x49, 0x8b, 0x44, 0x24, 0x68, 0x48, 0x85, 0xc0, 0x74, 0x18, 0x48, 0x83, 0x78, 0x08, 0x00, 0x74, 0x11, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7e, 0x46, 0x85, 0xc0, 0x79, 0x67, 0xe9, 0xca, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7f, 0xba, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x11, 0x09, 0x00, 0x00, 0x4c, 0x89, 0xfa, 0xff, 0xd0, 0x49, 0x8b, 0x07, 0x85, 0xc0, 0x78, 0x68, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0f, 0x75, 0x57, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0xeb, 0x46, 0x49, 0x8b, 0x44, 0x24, 0x68, 0x48, 0x85, 0xc0, 0x74, 0x07, 0x48, 0x83, 0x78, 0x08, 0x00, 0x75, 0x35, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BEFORE_ASYNC_WITH_code_holes[13] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyObject_LookupSpecial, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyRuntime, 0x0},
    {0x78, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x91, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x84},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0xb5, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xbf, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xda, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xeb, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x10d, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x126, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x130, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
};
// 0: "/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'%.200s' object does not support the asynchronous context manager protocol\x00'%.200s' object does not support the asynchronous context manager protocol (missed __aexit__ method)\x00"
// e9: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BEFORE_ASYNC_WITH_data_body[241] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x64, 0x6f, 0x65, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x73, 0x75, 0x70, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x61, 0x73, 0x79, 0x6e, 0x63, 0x68, 0x72, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x20, 0x6d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, 0x20, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x00, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x64, 0x6f, 0x65, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x73, 0x75, 0x70, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x61, 0x73, 0x79, 0x6e, 0x63, 0x68, 0x72, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x20, 0x6d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, 0x20, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x20, 0x28, 0x6d, 0x69, 0x73, 0x73, 0x65, 0x64, 0x20, 0x5f, 0x5f, 0x61, 0x65, 0x78, 0x69, 0x74, 0x5f, 0x5f, 0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BEFORE_ASYNC_WITH_data_holes[1];

// _PUSH_NULLplus_BEFORE_WITH
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BEFORE_WITH.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 d4                      movq    %rdx, %r12
// e: 48 89 f3                      movq    %rsi, %rbx
// 11: 49 89 fe                      movq    %rdi, %r14
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 000000000000001d:  R_X86_64_64  _PyObject_LookupSpecial
// 25: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000027:  R_X86_64_64  _PyRuntime
// 2f: 49 8d b5 50 ae 00 00          leaq    0xae50(%r13), %rsi
// 36: 31 ff                         xorl    %edi, %edi
// 38: ff d5                         callq   *%rbp
// 3a: 48 85 c0                      testq   %rax, %rax
// 3d: 0f 84 b7 00 00 00             je      0xfa <_JIT_ENTRY+0xfa>
// 43: 49 89 c7                      movq    %rax, %r15
// 46: 49 81 c5 b8 ae 00 00          addq    $0xaeb8, %r13           # imm = 0xAEB8
// 4d: 31 ff                         xorl    %edi, %edi
// 4f: 4c 89 ee                      movq    %r13, %rsi
// 52: ff d5                         callq   *%rbp
// 54: 49 8b 44 24 68                movq    0x68(%r12), %rax
// 59: 48 85 c0                      testq   %rax, %rax
// 5c: 74 18                         je      0x76 <_JIT_ENTRY+0x76>
// 5e: 48 83 78 08 00                cmpq    $0x0, 0x8(%rax)
// 63: 74 11                         je      0x76 <_JIT_ENTRY+0x76>
// 65: 49 8b 07                      movq    (%r15), %rax
// 68: 48 85 c0                      testq   %rax, %rax
// 6b: 7e 46                         jle     0xb3 <_JIT_ENTRY+0xb3>
// 6d: 85 c0                         testl   %eax, %eax
// 6f: 79 67                         jns     0xd8 <_JIT_ENTRY+0xd8>
// 71: e9 ca 00 00 00                jmp     0x140 <_JIT_ENTRY+0x140>
// 76: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000078:  R_X86_64_64  PyExc_TypeError
// 80: 48 8b 30                      movq    (%rax), %rsi
// 83: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 8b: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 8f: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000091:  R_X86_64_64  .rodata.str1.1+0x77
// 99: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 000000000000009b:  R_X86_64_64  _PyErr_Format
// a3: 4c 89 e7                      movq    %r12, %rdi
// a6: 31 c0                         xorl    %eax, %eax
// a8: 41 ff d0                      callq   *%r8
// ab: 49 8b 07                      movq    (%r15), %rax
// ae: 48 85 c0                      testq   %rax, %rax
// b1: 7f ba                         jg      0x6d <_JIT_ENTRY+0x6d>
// b3: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000b5:  R_X86_64_64  .rodata.str1.1
// bd: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000bf:  R_X86_64_64  _Py_NegativeRefcount
// c7: be 3c 09 00 00                movl    $0x93c, %esi            # imm = 0x93C
// cc: 4c 89 fa                      movq    %r15, %rdx
// cf: ff d0                         callq   *%rax
// d1: 49 8b 07                      movq    (%r15), %rax
// d4: 85 c0                         testl   %eax, %eax
// d6: 78 68                         js      0x140 <_JIT_ENTRY+0x140>
// d8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000da:  R_X86_64_64  _Py_DECREF_DecRefTotal
// e2: ff d0                         callq   *%rax
// e4: 49 ff 0f                      decq    (%r15)
// e7: 75 57                         jne     0x140 <_JIT_ENTRY+0x140>
// e9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000eb:  R_X86_64_64  _Py_Dealloc
// f3: 4c 89 ff                      movq    %r15, %rdi
// f6: ff d0                         callq   *%rax
// f8: eb 46                         jmp     0x140 <_JIT_ENTRY+0x140>
// fa: 49 8b 44 24 68                movq    0x68(%r12), %rax
// ff: 48 85 c0                      testq   %rax, %rax
// 102: 74 07                         je      0x10b <_JIT_ENTRY+0x10b>
// 104: 48 83 78 08 00                cmpq    $0x0, 0x8(%rax)
// 109: 75 35                         jne     0x140 <_JIT_ENTRY+0x140>
// 10b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010d:  R_X86_64_64  PyExc_TypeError
// 115: 48 8b 30                      movq    (%rax), %rsi
// 118: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 120: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 124: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000126:  R_X86_64_64  .rodata.str1.1+0x39
// 12e: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000130:  R_X86_64_64  _PyErr_Format
// 138: 4c 89 e7                      movq    %r12, %rdi
// 13b: 31 c0                         xorl    %eax, %eax
// 13d: 41 ff d0                      callq   *%r8
// 140: 4c 29 f3                      subq    %r14, %rbx
// 143: 48 83 c3 c0                   addq    $-0x40, %rbx
// 147: 48 c1 eb 03                   shrq    $0x3, %rbx
// 14b: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 14f: 31 c0                         xorl    %eax, %eax
// 151: 48 83 c4 08                   addq    $0x8, %rsp
// 155: 5b                            popq    %rbx
// 156: 41 5c                         popq    %r12
// 158: 41 5d                         popq    %r13
// 15a: 41 5e                         popq    %r14
// 15c: 41 5f                         popq    %r15
// 15e: 5d                            popq    %rbp
// 15f: c3                            retq
// 160: 
static const unsigned char _PUSH_NULLplus_BEFORE_WITH_code_body[353] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd4, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8d, 0xb5, 0x50, 0xae, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd5, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0xb7, 0x00, 0x00, 0x00, 0x49, 0x89, 0xc7, 0x49, 0x81, 0xc5, 0xb8, 0xae, 0x00, 0x00, 0x31, 0xff, 0x4c, 0x89, 0xee, 0xff, 0xd5, 0x49, 0x8b, 0x44, 0x24, 0x68, 0x48, 0x85, 0xc0, 0x74, 0x18, 0x48, 0x83, 0x78, 0x08, 0x00, 0x74, 0x11, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7e, 0x46, 0x85, 0xc0, 0x79, 0x67, 0xe9, 0xca, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7f, 0xba, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x3c, 0x09, 0x00, 0x00, 0x4c, 0x89, 0xfa, 0xff, 0xd0, 0x49, 0x8b, 0x07, 0x85, 0xc0, 0x78, 0x68, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0f, 0x75, 0x57, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0xeb, 0x46, 0x49, 0x8b, 0x44, 0x24, 0x68, 0x48, 0x85, 0xc0, 0x74, 0x07, 0x48, 0x83, 0x78, 0x08, 0x00, 0x75, 0x35, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BEFORE_WITH_code_holes[13] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyObject_LookupSpecial, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyRuntime, 0x0},
    {0x78, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x91, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x77},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0xb5, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xbf, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xda, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xeb, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x10d, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x126, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x130, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
};
// 0: "/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'%.200s' object does not support the context manager protocol\x00'%.200s' object does not support the context manager protocol (missed __exit__ method)\x00"
// ce: 00 00
static const unsigned char _PUSH_NULLplus_BEFORE_WITH_data_body[209] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x64, 0x6f, 0x65, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x73, 0x75, 0x70, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x20, 0x6d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, 0x20, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x00, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x64, 0x6f, 0x65, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x73, 0x75, 0x70, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x20, 0x6d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, 0x20, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x20, 0x28, 0x6d, 0x69, 0x73, 0x73, 0x65, 0x64, 0x20, 0x5f, 0x5f, 0x65, 0x78, 0x69, 0x74, 0x5f, 0x5f, 0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x29, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BEFORE_WITH_data_holes[1];

// _PUSH_NULLplus_BINARY_OP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  _JIT_OPARG
// 16: 0f b7 c0                      movzwl  %ax, %eax
// 19: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001b:  R_X86_64_64  _PyEval_BinaryOps
// 23: 48 89 df                      movq    %rbx, %rdi
// 26: 31 f6                         xorl    %esi, %esi
// 28: ff 14 c1                      callq   *(%rcx,%rax,8)
// 2b: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 2f: 7f 1e                         jg      0x4f <_JIT_ENTRY+0x4f>
// 31: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000033:  R_X86_64_64  .rodata.str1.1
// 3b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003d:  R_X86_64_64  _Py_NegativeRefcount
// 45: be d4 0c 00 00                movl    $0xcd4, %esi            # imm = 0xCD4
// 4a: 48 89 da                      movq    %rbx, %rdx
// 4d: ff d0                         callq   *%rax
// 4f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000051:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 59: ff d0                         callq   *%rax
// 5b: 48 ff 0b                      decq    (%rbx)
// 5e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000060:  R_X86_64_64  _Py_Dealloc
// 68: 48 89 df                      movq    %rbx, %rdi
// 6b: ff d0                         callq   *%rax
// 6d: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_code_body[110] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0x14, 0xc1, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xd4, 0x0c, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_OP_code_holes[7] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_BinaryOps, 0x0},
    {0x33, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x3d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BINARY_OP_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BINARY_OP_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_ADD_FLOAT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_ADD_FLOAT.o:  file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_FLOAT_code_body[1] = {};
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_FLOAT_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_FLOAT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_FLOAT_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_ADD_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_ADD_INT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 7e f8                   movq    -0x8(%rsi), %rdi
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  _PyLong_Add
// 16: 31 f6                         xorl    %esi, %esi
// 18: ff d0                         callq   *%rax
// 1a: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_INT_code_body[27] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_INT_code_holes[2] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyLong_Add, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_INT_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_ADD_UNICODE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_ADD_UNICODE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyUnicode_Concat
// 16: 48 89 df                      movq    %rbx, %rdi
// 19: 31 f6                         xorl    %esi, %esi
// 1b: ff d0                         callq   *%rax
// 1d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001f:  R_X86_64_64  PyInterpreterState_Get
// 27: ff d0                         callq   *%rax
// 29: 48 ff 88 c8 15 04 00          decq    0x415c8(%rax)
// 30: 48 ff 0b                      decq    (%rbx)
// 33: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000035:  R_X86_64_64  _PyUnicode_ExactDealloc
// 3d: 48 89 df                      movq    %rbx, %rdi
// 40: ff d0                         callq   *%rax
// 42: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_UNICODE_code_body[67] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x88, 0xc8, 0x15, 0x04, 0x00, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_UNICODE_code_holes[4] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Concat, 0x0},
    {0x1f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyInterpreterState_Get, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyUnicode_ExactDealloc, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_ADD_UNICODE_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_ADD_UNICODE_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT.o:     file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT_code_body[1] = {};
static const Hole _PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_MULTIPLY_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_MULTIPLY_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 7e f8                   movq    -0x8(%rsi), %rdi
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  _PyLong_Multiply
// 16: 31 f6                         xorl    %esi, %esi
// 18: ff d0                         callq   *%rax
// 1a: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_MULTIPLY_INT_code_body[27] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_OP_MULTIPLY_INT_code_holes[2] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyLong_Multiply, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_MULTIPLY_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_MULTIPLY_INT_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT.o:     file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT_code_body[1] = {};
static const Hole _PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT_data_holes[1];

// _PUSH_NULLplus_BINARY_OP_SUBTRACT_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_OP_SUBTRACT_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 7e f8                   movq    -0x8(%rsi), %rdi
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  _PyLong_Subtract
// 16: 31 f6                         xorl    %esi, %esi
// 18: ff d0                         callq   *%rax
// 1a: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_SUBTRACT_INT_code_body[27] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_OP_SUBTRACT_INT_code_holes[2] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyLong_Subtract, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_OP_SUBTRACT_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_OP_SUBTRACT_INT_data_holes[1];

// _PUSH_NULLplus_BINARY_SLICE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SLICE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 d6                      movq    %rdx, %r14
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 4c 8b 66 f0                   movq    -0x10(%rsi), %r12
// 1f: 48 8b 7e f8                   movq    -0x8(%rsi), %rdi
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  _PyBuildSlice_ConsumeRefs
// 2d: 45 31 ed                      xorl    %r13d, %r13d
// 30: 31 f6                         xorl    %esi, %esi
// 32: ff d0                         callq   *%rax
// 34: 48 85 c0                      testq   %rax, %rax
// 37: 74 5f                         je      0x98 <_JIT_ENTRY+0x98>
// 39: 48 89 c5                      movq    %rax, %rbp
// 3c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003e:  R_X86_64_64  PyObject_GetItem
// 46: 4c 89 e7                      movq    %r12, %rdi
// 49: 48 89 ee                      movq    %rbp, %rsi
// 4c: ff d0                         callq   *%rax
// 4e: 49 89 c5                      movq    %rax, %r13
// 51: 48 8b 45 00                   movq    (%rbp), %rax
// 55: 48 85 c0                      testq   %rax, %rax
// 58: 7e 06                         jle     0x60 <_JIT_ENTRY+0x60>
// 5a: 85 c0                         testl   %eax, %eax
// 5c: 79 28                         jns     0x86 <_JIT_ENTRY+0x86>
// 5e: eb 38                         jmp     0x98 <_JIT_ENTRY+0x98>
// 60: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000062:  R_X86_64_64  .rodata.str1.1
// 6a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006c:  R_X86_64_64  _Py_NegativeRefcount
// 74: be 99 01 00 00                movl    $0x199, %esi            # imm = 0x199
// 79: 48 89 ea                      movq    %rbp, %rdx
// 7c: ff d0                         callq   *%rax
// 7e: 48 8b 45 00                   movq    (%rbp), %rax
// 82: 85 c0                         testl   %eax, %eax
// 84: 78 12                         js      0x98 <_JIT_ENTRY+0x98>
// 86: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000088:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 90: ff d0                         callq   *%rax
// 92: 48 ff 4d 00                   decq    (%rbp)
// 96: 74 0f                         je      0xa7 <_JIT_ENTRY+0xa7>
// 98: 49 8b 04 24                   movq    (%r12), %rax
// 9c: 48 85 c0                      testq   %rax, %rax
// 9f: 7e 1e                         jle     0xbf <_JIT_ENTRY+0xbf>
// a1: 85 c0                         testl   %eax, %eax
// a3: 79 40                         jns     0xe5 <_JIT_ENTRY+0xe5>
// a5: eb 50                         jmp     0xf7 <_JIT_ENTRY+0xf7>
// a7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a9:  R_X86_64_64  _Py_Dealloc
// b1: 48 89 ef                      movq    %rbp, %rdi
// b4: ff d0                         callq   *%rax
// b6: 49 8b 04 24                   movq    (%r12), %rax
// ba: 48 85 c0                      testq   %rax, %rax
// bd: 7f e2                         jg      0xa1 <_JIT_ENTRY+0xa1>
// bf: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000c1:  R_X86_64_64  .rodata.str1.1
// c9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000cb:  R_X86_64_64  _Py_NegativeRefcount
// d3: be 9b 01 00 00                movl    $0x19b, %esi            # imm = 0x19B
// d8: 4c 89 e2                      movq    %r12, %rdx
// db: ff d0                         callq   *%rax
// dd: 49 8b 04 24                   movq    (%r12), %rax
// e1: 85 c0                         testl   %eax, %eax
// e3: 78 12                         js      0xf7 <_JIT_ENTRY+0xf7>
// e5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e7:  R_X86_64_64  _Py_DECREF_DecRefTotal
// ef: ff d0                         callq   *%rax
// f1: 49 ff 0c 24                   decq    (%r12)
// f5: 74 33                         je      0x12a <_JIT_ENTRY+0x12a>
// f7: 49 8d 47 f0                   leaq    -0x10(%r15), %rax
// fb: 4d 85 ed                      testq   %r13, %r13
// fe: 74 42                         je      0x142 <_JIT_ENTRY+0x142>
// 100: 49 83 c7 f8                   addq    $-0x8, %r15
// 104: 4c 89 28                      movq    %r13, (%rax)
// 107: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000109:  R_X86_64_64  _JIT_CONTINUE
// 111: 48 89 df                      movq    %rbx, %rdi
// 114: 4c 89 fe                      movq    %r15, %rsi
// 117: 4c 89 f2                      movq    %r14, %rdx
// 11a: 48 83 c4 08                   addq    $0x8, %rsp
// 11e: 5b                            popq    %rbx
// 11f: 41 5c                         popq    %r12
// 121: 41 5d                         popq    %r13
// 123: 41 5e                         popq    %r14
// 125: 41 5f                         popq    %r15
// 127: 5d                            popq    %rbp
// 128: ff e0                         jmpq    *%rax
// 12a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000012c:  R_X86_64_64  _Py_Dealloc
// 134: 4c 89 e7                      movq    %r12, %rdi
// 137: ff d0                         callq   *%rax
// 139: 49 8d 47 f0                   leaq    -0x10(%r15), %rax
// 13d: 4d 85 ed                      testq   %r13, %r13
// 140: 75 be                         jne     0x100 <_JIT_ENTRY+0x100>
// 142: 48 29 d8                      subq    %rbx, %rax
// 145: 48 83 c0 b8                   addq    $-0x48, %rax
// 149: 48 c1 e8 03                   shrq    $0x3, %rax
// 14d: 89 43 40                      movl    %eax, 0x40(%rbx)
// 150: 31 c0                         xorl    %eax, %eax
// 152: 48 83 c4 08                   addq    $0x8, %rsp
// 156: 5b                            popq    %rbx
// 157: 41 5c                         popq    %r12
// 159: 41 5d                         popq    %r13
// 15b: 41 5e                         popq    %r14
// 15d: 41 5f                         popq    %r15
// 15f: 5d                            popq    %rbp
// 160: c3                            retq
// 161: 
static const unsigned char _PUSH_NULLplus_BINARY_SLICE_code_body[354] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd6, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x66, 0xf0, 0x48, 0x8b, 0x7e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x31, 0xed, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x5f, 0x48, 0x89, 0xc5, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x48, 0x89, 0xee, 0xff, 0xd0, 0x49, 0x89, 0xc5, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x38, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x99, 0x01, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x74, 0x0f, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x1e, 0x85, 0xc0, 0x79, 0x40, 0xeb, 0x50, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0xe2, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x9b, 0x01, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x74, 0x33, 0x49, 0x8d, 0x47, 0xf0, 0x4d, 0x85, 0xed, 0x74, 0x42, 0x49, 0x83, 0xc7, 0xf8, 0x4c, 0x89, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfe, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0x8d, 0x47, 0xf0, 0x4d, 0x85, 0xed, 0x75, 0xbe, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BINARY_SLICE_code_holes[12] = {
    {0x25, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyBuildSlice_ConsumeRefs, 0x0},
    {0x3e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GetItem, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x6c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x88, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xa9, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xc1, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xcb, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xe7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x109, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x12c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BINARY_SLICE_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BINARY_SLICE_data_holes[1];

// _PUSH_NULLplus_BINARY_SUBSCR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SUBSCR.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyObject_GetItem
// 16: 48 89 df                      movq    %rbx, %rdi
// 19: 31 f6                         xorl    %esi, %esi
// 1b: ff d0                         callq   *%rax
// 1d: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 21: 7f 1e                         jg      0x41 <_JIT_ENTRY+0x41>
// 23: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000025:  R_X86_64_64  .rodata.str1.1
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  _Py_NegativeRefcount
// 37: be 81 01 00 00                movl    $0x181, %esi            # imm = 0x181
// 3c: 48 89 da                      movq    %rbx, %rdx
// 3f: ff d0                         callq   *%rax
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4b: ff d0                         callq   *%rax
// 4d: 48 ff 0b                      decq    (%rbx)
// 50: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000052:  R_X86_64_64  _Py_Dealloc
// 5a: 48 89 df                      movq    %rbx, %rdi
// 5d: ff d0                         callq   *%rax
// 5f: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_code_body[96] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x81, 0x01, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GetItem, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x52, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_data_holes[1];

// _PUSH_NULLplus_BINARY_SUBSCR_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SUBSCR_DICT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 83 ec 10                   subq    $0x10, %rsp
// 5: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// c: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// 10: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000012:  R_X86_64_64  PyDict_Type
// 1a: 48 39 43 08                   cmpq    %rax, 0x8(%rbx)
// 1e: 74 2d                         je      0x4d <_JIT_ENTRY+0x4d>
// 20: 48 29 fe                      subq    %rdi, %rsi
// 23: 48 83 c6 c0                   addq    $-0x40, %rsi
// 27: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2b: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2e: 48 8b 07                      movq    (%rdi), %rax
// 31: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000033:  R_X86_64_64  _JIT_TARGET
// 3b: 89 c9                         movl    %ecx, %ecx
// 3d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 41: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 47: 48 83 c4 10                   addq    $0x10, %rsp
// 4b: 5b                            popq    %rbx
// 4c: c3                            retq
// 4d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004f:  R_X86_64_64  PyDict_GetItemRef
// 57: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 5c: 48 89 df                      movq    %rbx, %rdi
// 5f: 31 f6                         xorl    %esi, %esi
// 61: ff d0                         callq   *%rax
// 63: 85 c0                         testl   %eax, %eax
// 65: 75 0e                         jne     0x75 <_JIT_ENTRY+0x75>
// 67: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000069:  R_X86_64_64  _PyErr_SetKeyError
// 71: 31 ff                         xorl    %edi, %edi
// 73: ff d0                         callq   *%rax
// 75: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 79: 7f 1e                         jg      0x99 <_JIT_ENTRY+0x99>
// 7b: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000007d:  R_X86_64_64  .rodata.str1.1
// 85: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000087:  R_X86_64_64  _Py_NegativeRefcount
// 8f: be 0c 02 00 00                movl    $0x20c, %esi            # imm = 0x20C
// 94: 48 89 da                      movq    %rbx, %rdx
// 97: ff d0                         callq   *%rax
// 99: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000009b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// a3: ff d0                         callq   *%rax
// a5: 48 ff 0b                      decq    (%rbx)
// a8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000aa:  R_X86_64_64  _Py_Dealloc
// b2: 48 89 df                      movq    %rbx, %rdi
// b5: ff d0                         callq   *%rax
// b7: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_DICT_code_body[184] = {0x53, 0x48, 0x83, 0xec, 0x10, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x43, 0x08, 0x74, 0x2d, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x85, 0xc0, 0x75, 0x0e, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x0c, 0x02, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_DICT_code_holes[9] = {
    {0x12, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x33, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x4f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_GetItemRef, 0x0},
    {0x69, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetKeyError, 0x0},
    {0x7d, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x87, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xaa, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_DICT_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_DICT_data_holes[1];

// _PUSH_NULLplus_BINARY_SUBSCR_LIST_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SUBSCR_LIST_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyLong_Type
// 12: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1a: 75 2c                         jne     0x48 <_JIT_ENTRY+0x48>
// 1c: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  PyList_Type
// 2a: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 2e: 75 18                         jne     0x48 <_JIT_ENTRY+0x48>
// 30: 48 83 3c 25 10 00 00 00 08    cmpq    $0x8, 0x10
// 39: 77 0d                         ja      0x48 <_JIT_ENTRY+0x48>
// 3b: 8b 0c 25 18 00 00 00          movl    0x18, %ecx
// 42: 48 39 48 10                   cmpq    %rcx, 0x10(%rax)
// 46: 7f 29                         jg      0x71 <_JIT_ENTRY+0x71>
// 48: 48 29 fe                      subq    %rdi, %rsi
// 4b: 48 83 c6 c0                   addq    $-0x40, %rsi
// 4f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 53: 89 77 40                      movl    %esi, 0x40(%rdi)
// 56: 48 8b 07                      movq    (%rdi), %rax
// 59: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000005b:  R_X86_64_64  _JIT_TARGET
// 63: 89 c9                         movl    %ecx, %ecx
// 65: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 69: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 6f: 59                            popq    %rcx
// 70: c3                            retq
// 71: 48 8b 40 18                   movq    0x18(%rax), %rax
// 75: 48 8b 04 c8                   movq    (%rax,%rcx,8), %rax
// 79: ff 00                         incl    (%rax)
// 7b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 85: ff d0                         callq   *%rax
// 87: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_LIST_INT_code_body[136] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x2c, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x18, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x08, 0x77, 0x0d, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x10, 0x7f, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0x48, 0x8b, 0x40, 0x18, 0x48, 0x8b, 0x04, 0xc8, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_LIST_INT_code_holes[5] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyList_Type, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x7d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_LIST_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_LIST_INT_data_holes[1];

// _PUSH_NULLplus_BINARY_SUBSCR_STR_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SUBSCR_STR_INT.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  PyLong_Type
// 11: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 19: 75 3d                         jne     0x58 <_JIT_ENTRY+0x58>
// 1b: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// 1f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000021:  R_X86_64_64  PyUnicode_Type
// 29: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 2d: 75 29                         jne     0x58 <_JIT_ENTRY+0x58>
// 2f: 48 83 3c 25 10 00 00 00 08    cmpq    $0x8, 0x10
// 38: 77 1e                         ja      0x58 <_JIT_ENTRY+0x58>
// 3a: 8b 0c 25 18 00 00 00          movl    0x18, %ecx
// 41: 48 39 48 10                   cmpq    %rcx, 0x10(%rax)
// 45: 7e 11                         jle     0x58 <_JIT_ENTRY+0x58>
// 47: 8b 40 20                      movl    0x20(%rax), %eax
// 4a: c1 e8 02                      shrl    $0x2, %eax
// 4d: 83 e0 07                      andl    $0x7, %eax
// 50: 83 f8 02                      cmpl    $0x2, %eax
// 53: 74 03                         je      0x58 <_JIT_ENTRY+0x58>
// 55: 83 f8 01                      cmpl    $0x1, %eax
// 58: 48 29 fe                      subq    %rdi, %rsi
// 5b: 48 83 c6 c0                   addq    $-0x40, %rsi
// 5f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 63: 89 77 40                      movl    %esi, 0x40(%rdi)
// 66: 48 8b 07                      movq    (%rdi), %rax
// 69: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006b:  R_X86_64_64  _JIT_TARGET
// 73: 89 c9                         movl    %ecx, %ecx
// 75: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 79: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 7f: c3                            retq
// 80: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_STR_INT_code_body[129] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x3d, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x29, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x08, 0x77, 0x1e, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x10, 0x7e, 0x11, 0x8b, 0x40, 0x20, 0xc1, 0xe8, 0x02, 0x83, 0xe0, 0x07, 0x83, 0xf8, 0x02, 0x74, 0x03, 0x83, 0xf8, 0x01, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_STR_INT_code_holes[4] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x21, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x6b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_STR_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_STR_INT_data_holes[1];

// _PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyLong_Type
// 12: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1a: 75 2c                         jne     0x48 <_JIT_ENTRY+0x48>
// 1c: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  PyTuple_Type
// 2a: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 2e: 75 18                         jne     0x48 <_JIT_ENTRY+0x48>
// 30: 48 83 3c 25 10 00 00 00 08    cmpq    $0x8, 0x10
// 39: 77 0d                         ja      0x48 <_JIT_ENTRY+0x48>
// 3b: 8b 0c 25 18 00 00 00          movl    0x18, %ecx
// 42: 48 39 48 10                   cmpq    %rcx, 0x10(%rax)
// 46: 7f 29                         jg      0x71 <_JIT_ENTRY+0x71>
// 48: 48 29 fe                      subq    %rdi, %rsi
// 4b: 48 83 c6 c0                   addq    $-0x40, %rsi
// 4f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 53: 89 77 40                      movl    %esi, 0x40(%rdi)
// 56: 48 8b 07                      movq    (%rdi), %rax
// 59: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000005b:  R_X86_64_64  _JIT_TARGET
// 63: 89 c9                         movl    %ecx, %ecx
// 65: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 69: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 6f: 59                            popq    %rcx
// 70: c3                            retq
// 71: 48 8b 44 c8 18                movq    0x18(%rax,%rcx,8), %rax
// 76: ff 00                         incl    (%rax)
// 78: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007a:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 82: ff d0                         callq   *%rax
// 84: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT_code_body[133] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x2c, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x18, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x08, 0x77, 0x0d, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x10, 0x7f, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0x48, 0x8b, 0x44, 0xc8, 0x18, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT_code_holes[5] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x7a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT_data_body[1];
static const Hole _PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT_data_holes[1];

// _PUSH_NULLplus_BUILD_CONST_KEY_MAP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_CONST_KEY_MAP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  PyTuple_Type
// 22: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 2a: 0f 85 dd 00 00 00             jne     0x10d <_JIT_ENTRY+0x10d>
// 30: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000032:  R_X86_64_64  _JIT_OPARG
// 3a: 0f b7 c0                      movzwl  %ax, %eax
// 3d: 48 39 04 25 10 00 00 00       cmpq    %rax, 0x10
// 45: 0f 85 c2 00 00 00             jne     0x10d <_JIT_ENTRY+0x10d>
// 4b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004d:  R_X86_64_64  _JIT_OPARG
// 55: f7 d0                         notl    %eax
// 57: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 5c: 48 98                         cltq
// 5e: 48 8d 1c c3                   leaq    (%rbx,%rax,8), %rbx
// 62: 48 83 c3 08                   addq    $0x8, %rbx
// 66: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 0000000000000068:  R_X86_64_64  _JIT_OPARG
// 70: 45 0f b7 c6                   movzwl  %r14w, %r8d
// 74: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000076:  R_X86_64_64  _PyDict_FromItems
// 7e: bf 18 00 00 00                movl    $0x18, %edi
// 83: be 01 00 00 00                movl    $0x1, %esi
// 88: b9 01 00 00 00                movl    $0x1, %ecx
// 8d: 48 89 da                      movq    %rbx, %rdx
// 90: ff d0                         callq   *%rax
// 92: 45 0f b7 e6                   movzwl  %r14w, %r12d
// 96: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 0000000000000098:  R_X86_64_64  .rodata.str1.1
// a0: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 00000000000000a2:  R_X86_64_64  _Py_NegativeRefcount
// aa: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 00000000000000ac:  R_X86_64_64  _Py_DECREF_DecRefTotal
// b4: 66 66 66 2e 0f 1f 84 00 00 00 00 00   nopw    %cs:(%rax,%rax)
// c0: 41 ff cc                      decl    %r12d
// c3: 4e 8b 3c e3                   movq    (%rbx,%r12,8), %r15
// c7: 49 8b 07                      movq    (%r15), %rax
// ca: 48 85 c0                      testq   %rax, %rax
// cd: 7e 11                         jle     0xe0 <_JIT_ENTRY+0xe0>
// cf: 85 c0                         testl   %eax, %eax
// d1: 78 ed                         js      0xc0 <_JIT_ENTRY+0xc0>
// d3: eb 20                         jmp     0xf5 <_JIT_ENTRY+0xf5>
// d5: 66 66 2e 0f 1f 84 00 00 00 00 00      nopw    %cs:(%rax,%rax)
// e0: 4c 89 f7                      movq    %r14, %rdi
// e3: be ac 05 00 00                movl    $0x5ac, %esi            # imm = 0x5AC
// e8: 4c 89 fa                      movq    %r15, %rdx
// eb: 41 ff d5                      callq   *%r13
// ee: 49 8b 07                      movq    (%r15), %rax
// f1: 85 c0                         testl   %eax, %eax
// f3: 78 cb                         js      0xc0 <_JIT_ENTRY+0xc0>
// f5: ff d5                         callq   *%rbp
// f7: 49 ff 0f                      decq    (%r15)
// fa: 75 c4                         jne     0xc0 <_JIT_ENTRY+0xc0>
// fc: 4c 89 ff                      movq    %r15, %rdi
// ff: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000101:  R_X86_64_64  _Py_Dealloc
// 109: ff d0                         callq   *%rax
// 10b: eb b3                         jmp     0xc0 <_JIT_ENTRY+0xc0>
// 10d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010f:  R_X86_64_64  PyExc_SystemError
// 117: 48 8b 30                      movq    (%rax), %rsi
// 11a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011c:  R_X86_64_64  .rodata.str1.1+0x39
// 124: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000126:  R_X86_64_64  _PyErr_SetString
// 12e: 48 89 d7                      movq    %rdx, %rdi
// 131: 48 89 c2                      movq    %rax, %rdx
// 134: ff d1                         callq   *%rcx
// 136: 4c 29 f3                      subq    %r14, %rbx
// 139: 48 83 c3 c0                   addq    $-0x40, %rbx
// 13d: 48 c1 eb 03                   shrq    $0x3, %rbx
// 141: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 145: 31 c0                         xorl    %eax, %eax
// 147: 48 83 c4 08                   addq    $0x8, %rsp
// 14b: 5b                            popq    %rbx
// 14c: 41 5c                         popq    %r12
// 14e: 41 5d                         popq    %r13
// 150: 41 5e                         popq    %r14
// 152: 41 5f                         popq    %r15
// 154: 5d                            popq    %rbp
// 155: c3                            retq
// 156: 
static const unsigned char _PUSH_NULLplus_BUILD_CONST_KEY_MAP_code_body[343] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x85, 0xdd, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x39, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x0f, 0x85, 0xc2, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8d, 0x1c, 0xc3, 0x48, 0x83, 0xc3, 0x08, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x0f, 0xb7, 0xc6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x18, 0x00, 0x00, 0x00, 0xbe, 0x01, 0x00, 0x00, 0x00, 0xb9, 0x01, 0x00, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x45, 0x0f, 0xb7, 0xe6, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xff, 0xcc, 0x4e, 0x8b, 0x3c, 0xe3, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7e, 0x11, 0x85, 0xc0, 0x78, 0xed, 0xeb, 0x20, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xbe, 0xac, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xfa, 0x41, 0xff, 0xd5, 0x49, 0x8b, 0x07, 0x85, 0xc0, 0x78, 0xcb, 0xff, 0xd5, 0x49, 0xff, 0x0f, 0x75, 0xc4, 0x4c, 0x89, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0xb3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0xc2, 0xff, 0xd1, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_CONST_KEY_MAP_code_holes[13] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x68, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x76, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_FromItems, 0x0},
    {0x98, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xa2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xac, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x101, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x10f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0x11c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x126, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetString, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00bad BUILD_CONST_KEY_MAP keys argument\x00'
// 5f: 00
static const unsigned char _PUSH_NULLplus_BUILD_CONST_KEY_MAP_data_body[97] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x62, 0x61, 0x64, 0x20, 0x42, 0x55, 0x49, 0x4c, 0x44, 0x5f, 0x43, 0x4f, 0x4e, 0x53, 0x54, 0x5f, 0x4b, 0x45, 0x59, 0x5f, 0x4d, 0x41, 0x50, 0x20, 0x6b, 0x65, 0x79, 0x73, 0x20, 0x61, 0x72, 0x67, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BUILD_CONST_KEY_MAP_data_holes[1];

// _PUSH_NULLplus_BUILD_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_LIST.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d6                      movq    %rdx, %r14
// b: 49 89 f7                      movq    %rsi, %r15
// e: 48 89 fb                      movq    %rdi, %rbx
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 f0                      movzwl  %ax, %esi
// 25: 48 8d 04 f5 00 00 00 00       leaq    (,%rsi,8), %rax
// 2d: 48 f7 d8                      negq    %rax
// 30: 4d 8d 24 07                   leaq    (%r15,%rax), %r12
// 34: 49 83 c4 08                   addq    $0x8, %r12
// 38: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003a:  R_X86_64_64  _PyList_FromArraySteal
// 42: 4c 89 e7                      movq    %r12, %rdi
// 45: ff d0                         callq   *%rax
// 47: 48 85 c0                      testq   %rax, %rax
// 4a: 74 4a                         je      0x96 <_JIT_ENTRY+0x96>
// 4c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004e:  R_X86_64_64  _JIT_OPARG
// 56: 0f b7 d1                      movzwl  %cx, %edx
// 59: 0f b7 c9                      movzwl  %cx, %ecx
// 5c: 48 c1 e1 03                   shlq    $0x3, %rcx
// 60: 48 f7 d9                      negq    %rcx
// 63: 49 89 44 0f 08                movq    %rax, 0x8(%r15,%rcx)
// 68: b8 01 00 00 00                movl    $0x1, %eax
// 6d: 29 d0                         subl    %edx, %eax
// 6f: 48 98                         cltq
// 71: 49 8d 34 c7                   leaq    (%r15,%rax,8), %rsi
// 75: 48 83 c6 08                   addq    $0x8, %rsi
// 79: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007b:  R_X86_64_64  _JIT_CONTINUE
// 83: 48 89 df                      movq    %rbx, %rdi
// 86: 4c 89 f2                      movq    %r14, %rdx
// 89: 48 83 c4 08                   addq    $0x8, %rsp
// 8d: 5b                            popq    %rbx
// 8e: 41 5c                         popq    %r12
// 90: 41 5e                         popq    %r14
// 92: 41 5f                         popq    %r15
// 94: ff e0                         jmpq    *%rax
// 96: 49 29 dc                      subq    %rbx, %r12
// 99: 49 83 c4 b8                   addq    $-0x48, %r12
// 9d: 49 c1 ec 03                   shrq    $0x3, %r12
// a1: 44 89 63 40                   movl    %r12d, 0x40(%rbx)
// a5: 31 c0                         xorl    %eax, %eax
// a7: 48 83 c4 08                   addq    $0x8, %rsp
// ab: 5b                            popq    %rbx
// ac: 41 5c                         popq    %r12
// ae: 41 5e                         popq    %r14
// b0: 41 5f                         popq    %r15
// b2: c3                            retq
// b3: 
static const unsigned char _PUSH_NULLplus_BUILD_LIST_code_body[180] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd6, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf0, 0x48, 0x8d, 0x04, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xd8, 0x4d, 0x8d, 0x24, 0x07, 0x49, 0x83, 0xc4, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x4a, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd1, 0x0f, 0xb7, 0xc9, 0x48, 0xc1, 0xe1, 0x03, 0x48, 0xf7, 0xd9, 0x49, 0x89, 0x44, 0x0f, 0x08, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x29, 0xd0, 0x48, 0x98, 0x49, 0x8d, 0x34, 0xc7, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x49, 0x29, 0xdc, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x63, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_LIST_code_holes[5] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyList_FromArraySteal, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x7b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BUILD_LIST_data_body[1];
static const Hole _PUSH_NULLplus_BUILD_LIST_data_holes[1];

// _PUSH_NULLplus_BUILD_MAP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_MAP.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// 13: 48 89 7c 24 08                movq    %rdi, 0x8(%rsp)
// 18: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000021:  R_X86_64_64  _JIT_OPARG
// 29: 0f b7 d8                      movzwl  %ax, %ebx
// 2c: 89 d9                         movl    %ebx, %ecx
// 2e: f7 d9                         negl    %ecx
// 30: 01 c9                         addl    %ecx, %ecx
// 32: 48 63 c9                      movslq  %ecx, %rcx
// 35: 4c 8d 24 ce                   leaq    (%rsi,%rcx,8), %r12
// 39: 49 83 c4 08                   addq    $0x8, %r12
// 3d: 48 89 74 24 10                movq    %rsi, 0x10(%rsp)
// 42: 48 8d 54 ce 10                leaq    0x10(%rsi,%rcx,8), %rdx
// 47: 44 0f b7 c0                   movzwl  %ax, %r8d
// 4b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004d:  R_X86_64_64  _PyDict_FromItems
// 55: be 02 00 00 00                movl    $0x2, %esi
// 5a: b9 02 00 00 00                movl    $0x2, %ecx
// 5f: 4c 89 e7                      movq    %r12, %rdi
// 62: ff d0                         callq   *%rax
// 64: 48 89 44 24 20                movq    %rax, 0x20(%rsp)
// 69: 01 db                         addl    %ebx, %ebx
// 6b: 85 db                         testl   %ebx, %ebx
// 6d: 0f 8e 8b 00 00 00             jle     0xfe <_JIT_ENTRY+0xfe>
// 73: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000075:  R_X86_64_64  _JIT_OPARG
// 7d: 0f b7 c0                      movzwl  %ax, %eax
// 80: 48 8d 1c 00                   leaq    (%rax,%rax), %rbx
// 84: 48 ff c3                      incq    %rbx
// 87: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 0000000000000089:  R_X86_64_64  .rodata.str1.1
// 91: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000093:  R_X86_64_64  _Py_NegativeRefcount
// 9b: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000009d:  R_X86_64_64  _Py_DECREF_DecRefTotal
// a5: eb 12                         jmp     0xb9 <_JIT_ENTRY+0xb9>
// a7: 66 0f 1f 84 00 00 00 00 00    nopw    (%rax,%rax)
// b0: 48 ff cb                      decq    %rbx
// b3: 48 83 fb 01                   cmpq    $0x1, %rbx
// b7: 7e 45                         jle     0xfe <_JIT_ENTRY+0xfe>
// b9: 8d 43 fe                      leal    -0x2(%rbx), %eax
// bc: 4d 8b 34 c4                   movq    (%r12,%rax,8), %r14
// c0: 49 8b 06                      movq    (%r14), %rax
// c3: 48 85 c0                      testq   %rax, %rax
// c6: 7e 08                         jle     0xd0 <_JIT_ENTRY+0xd0>
// c8: 85 c0                         testl   %eax, %eax
// ca: 78 e4                         js      0xb0 <_JIT_ENTRY+0xb0>
// cc: eb 17                         jmp     0xe5 <_JIT_ENTRY+0xe5>
// ce: 66 90                         nop
// d0: 48 89 ef                      movq    %rbp, %rdi
// d3: be 7b 05 00 00                movl    $0x57b, %esi            # imm = 0x57B
// d8: 4c 89 f2                      movq    %r14, %rdx
// db: 41 ff d5                      callq   *%r13
// de: 49 8b 06                      movq    (%r14), %rax
// e1: 85 c0                         testl   %eax, %eax
// e3: 78 cb                         js      0xb0 <_JIT_ENTRY+0xb0>
// e5: 41 ff d7                      callq   *%r15
// e8: 49 ff 0e                      decq    (%r14)
// eb: 75 c3                         jne     0xb0 <_JIT_ENTRY+0xb0>
// ed: 4c 89 f7                      movq    %r14, %rdi
// f0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f2:  R_X86_64_64  _Py_Dealloc
// fa: ff d0                         callq   *%rax
// fc: eb b2                         jmp     0xb0 <_JIT_ENTRY+0xb0>
// fe: 48 8b 74 24 20                movq    0x20(%rsp), %rsi
// 103: 48 85 f6                      testq   %rsi, %rsi
// 106: 74 58                         je      0x160 <_JIT_ENTRY+0x160>
// 108: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010a:  R_X86_64_64  _JIT_OPARG
// 112: 0f b7 c0                      movzwl  %ax, %eax
// 115: 89 c1                         movl    %eax, %ecx
// 117: f7 d9                         negl    %ecx
// 119: 01 c9                         addl    %ecx, %ecx
// 11b: 48 63 c9                      movslq  %ecx, %rcx
// 11e: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// 123: 48 89 74 ca 08                movq    %rsi, 0x8(%rdx,%rcx,8)
// 128: 01 c0                         addl    %eax, %eax
// 12a: b9 01 00 00 00                movl    $0x1, %ecx
// 12f: 29 c1                         subl    %eax, %ecx
// 131: 48 63 c1                      movslq  %ecx, %rax
// 134: 48 8d 34 c2                   leaq    (%rdx,%rax,8), %rsi
// 138: 48 83 c6 08                   addq    $0x8, %rsi
// 13c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013e:  R_X86_64_64  _JIT_CONTINUE
// 146: 48 8b 7c 24 08                movq    0x8(%rsp), %rdi
// 14b: 48 8b 54 24 18                movq    0x18(%rsp), %rdx
// 150: 48 83 c4 28                   addq    $0x28, %rsp
// 154: 5b                            popq    %rbx
// 155: 41 5c                         popq    %r12
// 157: 41 5d                         popq    %r13
// 159: 41 5e                         popq    %r14
// 15b: 41 5f                         popq    %r15
// 15d: 5d                            popq    %rbp
// 15e: ff e0                         jmpq    *%rax
// 160: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 165: 49 29 c4                      subq    %rax, %r12
// 168: 49 83 c4 b8                   addq    $-0x48, %r12
// 16c: 49 c1 ec 03                   shrq    $0x3, %r12
// 170: 44 89 60 40                   movl    %r12d, 0x40(%rax)
// 174: 31 c0                         xorl    %eax, %eax
// 176: 48 83 c4 28                   addq    $0x28, %rsp
// 17a: 5b                            popq    %rbx
// 17b: 41 5c                         popq    %r12
// 17d: 41 5d                         popq    %r13
// 17f: 41 5e                         popq    %r14
// 181: 41 5f                         popq    %r15
// 183: 5d                            popq    %rbp
// 184: c3                            retq
// 185: 
static const unsigned char _PUSH_NULLplus_BUILD_MAP_code_body[390] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x08, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd8, 0x89, 0xd9, 0xf7, 0xd9, 0x01, 0xc9, 0x48, 0x63, 0xc9, 0x4c, 0x8d, 0x24, 0xce, 0x49, 0x83, 0xc4, 0x08, 0x48, 0x89, 0x74, 0x24, 0x10, 0x48, 0x8d, 0x54, 0xce, 0x10, 0x44, 0x0f, 0xb7, 0xc0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x02, 0x00, 0x00, 0x00, 0xb9, 0x02, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x89, 0x44, 0x24, 0x20, 0x01, 0xdb, 0x85, 0xdb, 0x0f, 0x8e, 0x8b, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8d, 0x1c, 0x00, 0x48, 0xff, 0xc3, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x12, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xcb, 0x48, 0x83, 0xfb, 0x01, 0x7e, 0x45, 0x8d, 0x43, 0xfe, 0x4d, 0x8b, 0x34, 0xc4, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x08, 0x85, 0xc0, 0x78, 0xe4, 0xeb, 0x17, 0x66, 0x90, 0x48, 0x89, 0xef, 0xbe, 0x7b, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x41, 0xff, 0xd5, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0xcb, 0x41, 0xff, 0xd7, 0x49, 0xff, 0x0e, 0x75, 0xc3, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0xb2, 0x48, 0x8b, 0x74, 0x24, 0x20, 0x48, 0x85, 0xf6, 0x74, 0x58, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x89, 0xc1, 0xf7, 0xd9, 0x01, 0xc9, 0x48, 0x63, 0xc9, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x89, 0x74, 0xca, 0x08, 0x01, 0xc0, 0xb9, 0x01, 0x00, 0x00, 0x00, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x48, 0x8d, 0x34, 0xc2, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7c, 0x24, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x18, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x49, 0x29, 0xc4, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x60, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_MAP_code_holes[10] = {
    {0x21, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_FromItems, 0x0},
    {0x75, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x93, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x9d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xf2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x10a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x13e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BUILD_MAP_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BUILD_MAP_data_holes[1];

// _PUSH_NULLplus_BUILD_SET
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_SET.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 49 89 d7                      movq    %rdx, %r15
// 11: 48 89 f5                      movq    %rsi, %rbp
// 14: 48 89 fb                      movq    %rdi, %rbx
// 17: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000020:  R_X86_64_64  PySet_New
// 28: 31 ff                         xorl    %edi, %edi
// 2a: ff d0                         callq   *%rax
// 2c: 48 85 c0                      testq   %rax, %rax
// 2f: 0f 84 f5 00 00 00             je      0x12a <_JIT_ENTRY+0x12a>
// 35: 49 89 c6                      movq    %rax, %r14
// 38: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003a:  R_X86_64_64  _JIT_OPARG
// 42: 66 85 c0                      testw   %ax, %ax
// 45: 0f 84 67 01 00 00             je      0x1b2 <_JIT_ENTRY+0x1b2>
// 4b: 4c 89 7c 24 08                movq    %r15, 0x8(%rsp)
// 50: 48 89 5c 24 10                movq    %rbx, 0x10(%rsp)
// 55: 0f b7 c0                      movzwl  %ax, %eax
// 58: 48 c1 e0 03                   shlq    $0x3, %rax
// 5c: 48 f7 d8                      negq    %rax
// 5f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000061:  R_X86_64_64  _JIT_OPARG
// 69: 0f b7 c9                      movzwl  %cx, %ecx
// 6c: 83 f9 02                      cmpl    $0x2, %ecx
// 6f: 41 bd 01 00 00 00             movl    $0x1, %r13d
// 75: 44 0f 43 e9                   cmovael %ecx, %r13d
// 79: 48 89 2c 24                   movq    %rbp, (%rsp)
// 7d: 4c 8d 24 28                   leaq    (%rax,%rbp), %r12
// 81: 49 83 c4 08                   addq    $0x8, %r12
// 85: 31 db                         xorl    %ebx, %ebx
// 87: 31 ed                         xorl    %ebp, %ebp
// 89: eb 11                         jmp     0x9c <_JIT_ENTRY+0x9c>
// 8b: 0f 1f 44 00 00                nopl    (%rax,%rax)
// 90: 48 ff c3                      incq    %rbx
// 93: 49 39 dd                      cmpq    %rbx, %r13
// 96: 0f 84 97 00 00 00             je      0x133 <_JIT_ENTRY+0x133>
// 9c: 4d 8b 3c dc                   movq    (%r12,%rbx,8), %r15
// a0: 85 ed                         testl   %ebp, %ebp
// a2: 74 1c                         je      0xc0 <_JIT_ENTRY+0xc0>
// a4: 49 8b 07                      movq    (%r15), %rax
// a7: 48 85 c0                      testq   %rax, %rax
// aa: 7e 30                         jle     0xdc <_JIT_ENTRY+0xdc>
// ac: 85 c0                         testl   %eax, %eax
// ae: 78 e0                         js      0x90 <_JIT_ENTRY+0x90>
// b0: eb 4f                         jmp     0x101 <_JIT_ENTRY+0x101>
// b2: 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00     nopw    %cs:(%rax,%rax)
// c0: 4c 89 f7                      movq    %r14, %rdi
// c3: 4c 89 fe                      movq    %r15, %rsi
// c6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c8:  R_X86_64_64  PySet_Add
// d0: ff d0                         callq   *%rax
// d2: 89 c5                         movl    %eax, %ebp
// d4: 49 8b 07                      movq    (%r15), %rax
// d7: 48 85 c0                      testq   %rax, %rax
// da: 7f d0                         jg      0xac <_JIT_ENTRY+0xac>
// dc: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000de:  R_X86_64_64  .rodata.str1.1
// e6: be 66 05 00 00                movl    $0x566, %esi            # imm = 0x566
// eb: 4c 89 fa                      movq    %r15, %rdx
// ee: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f0:  R_X86_64_64  _Py_NegativeRefcount
// f8: ff d0                         callq   *%rax
// fa: 49 8b 07                      movq    (%r15), %rax
// fd: 85 c0                         testl   %eax, %eax
// ff: 78 8f                         js      0x90 <_JIT_ENTRY+0x90>
// 101: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000103:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 10b: ff d0                         callq   *%rax
// 10d: 49 ff 0f                      decq    (%r15)
// 110: 0f 85 7a ff ff ff             jne     0x90 <_JIT_ENTRY+0x90>
// 116: 4c 89 ff                      movq    %r15, %rdi
// 119: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011b:  R_X86_64_64  _Py_Dealloc
// 123: ff d0                         callq   *%rax
// 125: e9 66 ff ff ff                jmp     0x90 <_JIT_ENTRY+0x90>
// 12a: 48 83 c5 08                   addq    $0x8, %rbp
// 12e: 49 89 ec                      movq    %rbp, %r12
// 131: eb 5f                         jmp     0x192 <_JIT_ENTRY+0x192>
// 133: 85 ed                         testl   %ebp, %ebp
// 135: 48 8b 5c 24 10                movq    0x10(%rsp), %rbx
// 13a: 4c 8b 7c 24 08                movq    0x8(%rsp), %r15
// 13f: 48 8b 2c 24                   movq    (%rsp), %rbp
// 143: 74 6d                         je      0x1b2 <_JIT_ENTRY+0x1b2>
// 145: 49 8b 06                      movq    (%r14), %rax
// 148: 48 85 c0                      testq   %rax, %rax
// 14b: 7f 21                         jg      0x16e <_JIT_ENTRY+0x16e>
// 14d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000014f:  R_X86_64_64  .rodata.str1.1
// 157: be 69 05 00 00                movl    $0x569, %esi            # imm = 0x569
// 15c: 4c 89 f2                      movq    %r14, %rdx
// 15f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000161:  R_X86_64_64  _Py_NegativeRefcount
// 169: ff d0                         callq   *%rax
// 16b: 49 8b 06                      movq    (%r14), %rax
// 16e: 85 c0                         testl   %eax, %eax
// 170: 78 20                         js      0x192 <_JIT_ENTRY+0x192>
// 172: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000174:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 17c: ff d0                         callq   *%rax
// 17e: 49 ff 0e                      decq    (%r14)
// 181: 75 0f                         jne     0x192 <_JIT_ENTRY+0x192>
// 183: 4c 89 f7                      movq    %r14, %rdi
// 186: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000188:  R_X86_64_64  _Py_Dealloc
// 190: ff d0                         callq   *%rax
// 192: 49 29 dc                      subq    %rbx, %r12
// 195: 49 83 c4 b8                   addq    $-0x48, %r12
// 199: 49 c1 ec 03                   shrq    $0x3, %r12
// 19d: 44 89 63 40                   movl    %r12d, 0x40(%rbx)
// 1a1: 31 c0                         xorl    %eax, %eax
// 1a3: 48 83 c4 18                   addq    $0x18, %rsp
// 1a7: 5b                            popq    %rbx
// 1a8: 41 5c                         popq    %r12
// 1aa: 41 5d                         popq    %r13
// 1ac: 41 5e                         popq    %r14
// 1ae: 41 5f                         popq    %r15
// 1b0: 5d                            popq    %rbp
// 1b1: c3                            retq
// 1b2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001b4:  R_X86_64_64  _JIT_OPARG
// 1bc: 0f b7 c8                      movzwl  %ax, %ecx
// 1bf: 0f b7 c0                      movzwl  %ax, %eax
// 1c2: 48 c1 e0 03                   shlq    $0x3, %rax
// 1c6: 48 f7 d8                      negq    %rax
// 1c9: 4c 89 74 05 08                movq    %r14, 0x8(%rbp,%rax)
// 1ce: b8 01 00 00 00                movl    $0x1, %eax
// 1d3: 29 c8                         subl    %ecx, %eax
// 1d5: 48 98                         cltq
// 1d7: 48 8d 34 c5 08 00 00 00       leaq    0x8(,%rax,8), %rsi
// 1df: 48 01 ee                      addq    %rbp, %rsi
// 1e2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001e4:  R_X86_64_64  _JIT_CONTINUE
// 1ec: 48 89 df                      movq    %rbx, %rdi
// 1ef: 4c 89 fa                      movq    %r15, %rdx
// 1f2: 48 83 c4 18                   addq    $0x18, %rsp
// 1f6: 5b                            popq    %rbx
// 1f7: 41 5c                         popq    %r12
// 1f9: 41 5d                         popq    %r13
// 1fb: 41 5e                         popq    %r14
// 1fd: 41 5f                         popq    %r15
// 1ff: 5d                            popq    %rbp
// 200: ff e0                         jmpq    *%rax
// 202: 
static const unsigned char _PUSH_NULLplus_BUILD_SET_code_body[515] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf5, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0xf5, 0x00, 0x00, 0x00, 0x49, 0x89, 0xc6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x84, 0x67, 0x01, 0x00, 0x00, 0x4c, 0x89, 0x7c, 0x24, 0x08, 0x48, 0x89, 0x5c, 0x24, 0x10, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x48, 0xf7, 0xd8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x83, 0xf9, 0x02, 0x41, 0xbd, 0x01, 0x00, 0x00, 0x00, 0x44, 0x0f, 0x43, 0xe9, 0x48, 0x89, 0x2c, 0x24, 0x4c, 0x8d, 0x24, 0x28, 0x49, 0x83, 0xc4, 0x08, 0x31, 0xdb, 0x31, 0xed, 0xeb, 0x11, 0x0f, 0x1f, 0x44, 0x00, 0x00, 0x48, 0xff, 0xc3, 0x49, 0x39, 0xdd, 0x0f, 0x84, 0x97, 0x00, 0x00, 0x00, 0x4d, 0x8b, 0x3c, 0xdc, 0x85, 0xed, 0x74, 0x1c, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7e, 0x30, 0x85, 0xc0, 0x78, 0xe0, 0xeb, 0x4f, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x4c, 0x89, 0xfe, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x89, 0xc5, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7f, 0xd0, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x66, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xfa, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x07, 0x85, 0xc0, 0x78, 0x8f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0f, 0x0f, 0x85, 0x7a, 0xff, 0xff, 0xff, 0x4c, 0x89, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xe9, 0x66, 0xff, 0xff, 0xff, 0x48, 0x83, 0xc5, 0x08, 0x49, 0x89, 0xec, 0xeb, 0x5f, 0x85, 0xed, 0x48, 0x8b, 0x5c, 0x24, 0x10, 0x4c, 0x8b, 0x7c, 0x24, 0x08, 0x48, 0x8b, 0x2c, 0x24, 0x74, 0x6d, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7f, 0x21, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x69, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0x20, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x75, 0x0f, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x29, 0xdc, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x63, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x48, 0xf7, 0xd8, 0x4c, 0x89, 0x74, 0x05, 0x08, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x29, 0xc8, 0x48, 0x98, 0x48, 0x8d, 0x34, 0xc5, 0x08, 0x00, 0x00, 0x00, 0x48, 0x01, 0xee, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_BUILD_SET_code_holes[15] = {
    {0x20, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySet_New, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x61, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xc8, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySet_Add, 0x0},
    {0xde, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xf0, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x103, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x11b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x14f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x161, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x174, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x188, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1b4, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1e4, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BUILD_SET_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BUILD_SET_data_holes[1];

// _PUSH_NULLplus_BUILD_SLICE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_SLICE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 48 89 54 24 10                movq    %rdx, 0x10(%rsp)
// 13: 49 89 f7                      movq    %rsi, %r15
// 16: 48 89 3c 24                   movq    %rdi, (%rsp)
// 1a: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 21: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000023:  R_X86_64_64  _JIT_OPARG
// 2b: 66 83 f8 03                   cmpw    $0x3, %ax
// 2f: 75 0f                         jne     0x40 <_JIT_ENTRY+0x40>
// 31: 31 c9                         xorl    %ecx, %ecx
// 33: 66 83 f8 03                   cmpw    $0x3, %ax
// 37: 0f 95 c1                      setne   %cl
// 3a: 4d 8b 24 cf                   movq    (%r15,%rcx,8), %r12
// 3e: eb 03                         jmp     0x43 <_JIT_ENTRY+0x43>
// 40: 45 31 e4                      xorl    %r12d, %r12d
// 43: 31 c9                         xorl    %ecx, %ecx
// 45: 66 83 f8 03                   cmpw    $0x3, %ax
// 49: 0f 94 c1                      sete    %cl
// 4c: b8 fe ff ff ff                movl    $0xfffffffe, %eax       # imm = 0xFFFFFFFE
// 51: 29 c8                         subl    %ecx, %eax
// 53: f7 d1                         notl    %ecx
// 55: 48 63 c9                      movslq  %ecx, %rcx
// 58: 48 89 4c 24 08                movq    %rcx, 0x8(%rsp)
// 5d: 49 8b 6c cf 08                movq    0x8(%r15,%rcx,8), %rbp
// 62: 48 63 d8                      movslq  %eax, %rbx
// 65: 4d 8b 74 df 08                movq    0x8(%r15,%rbx,8), %r14
// 6a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006c:  R_X86_64_64  PySlice_New
// 74: 4c 89 f7                      movq    %r14, %rdi
// 77: 48 89 ee                      movq    %rbp, %rsi
// 7a: 4c 89 e2                      movq    %r12, %rdx
// 7d: ff d0                         callq   *%rax
// 7f: 49 89 c5                      movq    %rax, %r13
// 82: 49 8b 06                      movq    (%r14), %rax
// 85: 48 85 c0                      testq   %rax, %rax
// 88: 7e 06                         jle     0x90 <_JIT_ENTRY+0x90>
// 8a: 85 c0                         testl   %eax, %eax
// 8c: 79 27                         jns     0xb5 <_JIT_ENTRY+0xb5>
// 8e: eb 36                         jmp     0xc6 <_JIT_ENTRY+0xc6>
// 90: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000092:  R_X86_64_64  .rodata.str1.1
// 9a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000009c:  R_X86_64_64  _Py_NegativeRefcount
// a4: be 86 0c 00 00                movl    $0xc86, %esi            # imm = 0xC86
// a9: 4c 89 f2                      movq    %r14, %rdx
// ac: ff d0                         callq   *%rax
// ae: 49 8b 06                      movq    (%r14), %rax
// b1: 85 c0                         testl   %eax, %eax
// b3: 78 11                         js      0xc6 <_JIT_ENTRY+0xc6>
// b5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b7:  R_X86_64_64  _Py_DECREF_DecRefTotal
// bf: ff d0                         callq   *%rax
// c1: 49 ff 0e                      decq    (%r14)
// c4: 74 0f                         je      0xd5 <_JIT_ENTRY+0xd5>
// c6: 48 8b 45 00                   movq    (%rbp), %rax
// ca: 48 85 c0                      testq   %rax, %rax
// cd: 7e 1e                         jle     0xed <_JIT_ENTRY+0xed>
// cf: 85 c0                         testl   %eax, %eax
// d1: 79 40                         jns     0x113 <_JIT_ENTRY+0x113>
// d3: eb 5f                         jmp     0x134 <_JIT_ENTRY+0x134>
// d5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d7:  R_X86_64_64  _Py_Dealloc
// df: 4c 89 f7                      movq    %r14, %rdi
// e2: ff d0                         callq   *%rax
// e4: 48 8b 45 00                   movq    (%rbp), %rax
// e8: 48 85 c0                      testq   %rax, %rax
// eb: 7f e2                         jg      0xcf <_JIT_ENTRY+0xcf>
// ed: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000ef:  R_X86_64_64  .rodata.str1.1
// f7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f9:  R_X86_64_64  _Py_NegativeRefcount
// 101: be 87 0c 00 00                movl    $0xc87, %esi            # imm = 0xC87
// 106: 48 89 ea                      movq    %rbp, %rdx
// 109: ff d0                         callq   *%rax
// 10b: 48 8b 45 00                   movq    (%rbp), %rax
// 10f: 85 c0                         testl   %eax, %eax
// 111: 78 21                         js      0x134 <_JIT_ENTRY+0x134>
// 113: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000115:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 11d: ff d0                         callq   *%rax
// 11f: 48 ff 4d 00                   decq    (%rbp)
// 123: 75 0f                         jne     0x134 <_JIT_ENTRY+0x134>
// 125: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000127:  R_X86_64_64  _Py_Dealloc
// 12f: 48 89 ef                      movq    %rbp, %rdi
// 132: ff d0                         callq   *%rax
// 134: 4d 85 e4                      testq   %r12, %r12
// 137: 74 47                         je      0x180 <_JIT_ENTRY+0x180>
// 139: 49 8b 04 24                   movq    (%r12), %rax
// 13d: 48 85 c0                      testq   %rax, %rax
// 140: 7e 06                         jle     0x148 <_JIT_ENTRY+0x148>
// 142: 85 c0                         testl   %eax, %eax
// 144: 79 28                         jns     0x16e <_JIT_ENTRY+0x16e>
// 146: eb 38                         jmp     0x180 <_JIT_ENTRY+0x180>
// 148: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000014a:  R_X86_64_64  .rodata.str1.1+0x39
// 152: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000154:  R_X86_64_64  _Py_NegativeRefcount
// 15c: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// 161: 4c 89 e2                      movq    %r12, %rdx
// 164: ff d0                         callq   *%rax
// 166: 49 8b 04 24                   movq    (%r12), %rax
// 16a: 85 c0                         testl   %eax, %eax
// 16c: 78 12                         js      0x180 <_JIT_ENTRY+0x180>
// 16e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000170:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 178: ff d0                         callq   *%rax
// 17a: 49 ff 0c 24                   decq    (%r12)
// 17e: 74 40                         je      0x1c0 <_JIT_ENTRY+0x1c0>
// 180: 49 8d 04 df                   leaq    (%r15,%rbx,8), %rax
// 184: 48 83 c0 08                   addq    $0x8, %rax
// 188: 4d 85 ed                      testq   %r13, %r13
// 18b: 74 4f                         je      0x1dc <_JIT_ENTRY+0x1dc>
// 18d: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 192: 49 8d 34 cf                   leaq    (%r15,%rcx,8), %rsi
// 196: 48 83 c6 08                   addq    $0x8, %rsi
// 19a: 4c 89 28                      movq    %r13, (%rax)
// 19d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000019f:  R_X86_64_64  _JIT_CONTINUE
// 1a7: 48 8b 3c 24                   movq    (%rsp), %rdi
// 1ab: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// 1b0: 48 83 c4 18                   addq    $0x18, %rsp
// 1b4: 5b                            popq    %rbx
// 1b5: 41 5c                         popq    %r12
// 1b7: 41 5d                         popq    %r13
// 1b9: 41 5e                         popq    %r14
// 1bb: 41 5f                         popq    %r15
// 1bd: 5d                            popq    %rbp
// 1be: ff e0                         jmpq    *%rax
// 1c0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c2:  R_X86_64_64  _Py_Dealloc
// 1ca: 4c 89 e7                      movq    %r12, %rdi
// 1cd: ff d0                         callq   *%rax
// 1cf: 49 8d 04 df                   leaq    (%r15,%rbx,8), %rax
// 1d3: 48 83 c0 08                   addq    $0x8, %rax
// 1d7: 4d 85 ed                      testq   %r13, %r13
// 1da: 75 b1                         jne     0x18d <_JIT_ENTRY+0x18d>
// 1dc: 48 8b 0c 24                   movq    (%rsp), %rcx
// 1e0: 48 29 c8                      subq    %rcx, %rax
// 1e3: 48 83 c0 b8                   addq    $-0x48, %rax
// 1e7: 48 c1 e8 03                   shrq    $0x3, %rax
// 1eb: 89 41 40                      movl    %eax, 0x40(%rcx)
// 1ee: 31 c0                         xorl    %eax, %eax
// 1f0: 48 83 c4 18                   addq    $0x18, %rsp
// 1f4: 5b                            popq    %rbx
// 1f5: 41 5c                         popq    %r12
// 1f7: 41 5d                         popq    %r13
// 1f9: 41 5e                         popq    %r14
// 1fb: 41 5f                         popq    %r15
// 1fd: 5d                            popq    %rbp
// 1fe: c3                            retq
// 1ff: 
static const unsigned char _PUSH_NULLplus_BUILD_SLICE_code_body[512] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x48, 0x89, 0x54, 0x24, 0x10, 0x49, 0x89, 0xf7, 0x48, 0x89, 0x3c, 0x24, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x83, 0xf8, 0x03, 0x75, 0x0f, 0x31, 0xc9, 0x66, 0x83, 0xf8, 0x03, 0x0f, 0x95, 0xc1, 0x4d, 0x8b, 0x24, 0xcf, 0xeb, 0x03, 0x45, 0x31, 0xe4, 0x31, 0xc9, 0x66, 0x83, 0xf8, 0x03, 0x0f, 0x94, 0xc1, 0xb8, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc8, 0xf7, 0xd1, 0x48, 0x63, 0xc9, 0x48, 0x89, 0x4c, 0x24, 0x08, 0x49, 0x8b, 0x6c, 0xcf, 0x08, 0x48, 0x63, 0xd8, 0x4d, 0x8b, 0x74, 0xdf, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xee, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x89, 0xc5, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x27, 0xeb, 0x36, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x86, 0x0c, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0x11, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x74, 0x0f, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x1e, 0x85, 0xc0, 0x79, 0x40, 0xeb, 0x5f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0xe2, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x87, 0x0c, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x4d, 0x85, 0xe4, 0x74, 0x47, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x38, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x74, 0x40, 0x49, 0x8d, 0x04, 0xdf, 0x48, 0x83, 0xc0, 0x08, 0x4d, 0x85, 0xed, 0x74, 0x4f, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x49, 0x8d, 0x34, 0xcf, 0x48, 0x83, 0xc6, 0x08, 0x4c, 0x89, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3c, 0x24, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0x8d, 0x04, 0xdf, 0x48, 0x83, 0xc0, 0x08, 0x4d, 0x85, 0xed, 0x75, 0xb1, 0x48, 0x8b, 0x0c, 0x24, 0x48, 0x29, 0xc8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x41, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_SLICE_code_holes[16] = {
    {0x23, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x6c, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySlice_New, 0x0},
    {0x92, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x9c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xb7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xd7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xef, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xf9, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x115, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x127, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x14a, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x154, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x170, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x19f, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x1c2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00/home/jglass/Documents/cpython/Include/object.h\x00'
// 69: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BUILD_SLICE_data_body[113] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BUILD_SLICE_data_holes[1];

// _PUSH_NULLplus_BUILD_STRING
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_STRING.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// 13: 48 89 7c 24 08                movq    %rdi, 0x8(%rsp)
// 18: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1f: 48 bb 00 00 00 00 00 00 00 00 movabsq $0x0, %rbx
// 0000000000000021:  R_X86_64_64  _JIT_OPARG
// 29: 0f b7 d3                      movzwl  %bx, %edx
// 2c: 48 8d 04 d5 00 00 00 00       leaq    (,%rdx,8), %rax
// 34: 48 f7 d8                      negq    %rax
// 37: 48 89 74 24 10                movq    %rsi, 0x10(%rsp)
// 3c: 4c 8d 24 06                   leaq    (%rsi,%rax), %r12
// 40: 49 83 c4 08                   addq    $0x8, %r12
// 44: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000046:  R_X86_64_64  _PyUnicode_JoinArray
// 4e: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000050:  R_X86_64_64  _PyRuntime
// 58: 48 81 c7 00 a1 00 00          addq    $0xa100, %rdi           # imm = 0xA100
// 5f: 4c 89 e6                      movq    %r12, %rsi
// 62: ff d0                         callq   *%rax
// 64: 48 89 44 24 20                movq    %rax, 0x20(%rsp)
// 69: f7 c3 ff ff 00 00             testl   $0xffff, %ebx           # imm = 0xFFFF
// 6f: 0f 8e 89 00 00 00             jle     0xfe <_JIT_ENTRY+0xfe>
// 75: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000077:  R_X86_64_64  _JIT_OPARG
// 7f: 0f b7 d8                      movzwl  %ax, %ebx
// 82: 48 ff c3                      incq    %rbx
// 85: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 0000000000000087:  R_X86_64_64  .rodata.str1.1
// 8f: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000091:  R_X86_64_64  _Py_NegativeRefcount
// 99: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000009b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// a3: eb 14                         jmp     0xb9 <_JIT_ENTRY+0xb9>
// a5: 66 66 2e 0f 1f 84 00 00 00 00 00      nopw    %cs:(%rax,%rax)
// b0: 48 ff cb                      decq    %rbx
// b3: 48 83 fb 01                   cmpq    $0x1, %rbx
// b7: 7e 45                         jle     0xfe <_JIT_ENTRY+0xfe>
// b9: 8d 43 fe                      leal    -0x2(%rbx), %eax
// bc: 4d 8b 34 c4                   movq    (%r12,%rax,8), %r14
// c0: 49 8b 06                      movq    (%r14), %rax
// c3: 48 85 c0                      testq   %rax, %rax
// c6: 7e 08                         jle     0xd0 <_JIT_ENTRY+0xd0>
// c8: 85 c0                         testl   %eax, %eax
// ca: 78 e4                         js      0xb0 <_JIT_ENTRY+0xb0>
// cc: eb 17                         jmp     0xe5 <_JIT_ENTRY+0xe5>
// ce: 66 90                         nop
// d0: 48 89 ef                      movq    %rbp, %rdi
// d3: be 13 05 00 00                movl    $0x513, %esi            # imm = 0x513
// d8: 4c 89 f2                      movq    %r14, %rdx
// db: 41 ff d5                      callq   *%r13
// de: 49 8b 06                      movq    (%r14), %rax
// e1: 85 c0                         testl   %eax, %eax
// e3: 78 cb                         js      0xb0 <_JIT_ENTRY+0xb0>
// e5: 41 ff d7                      callq   *%r15
// e8: 49 ff 0e                      decq    (%r14)
// eb: 75 c3                         jne     0xb0 <_JIT_ENTRY+0xb0>
// ed: 4c 89 f7                      movq    %r14, %rdi
// f0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f2:  R_X86_64_64  _Py_Dealloc
// fa: ff d0                         callq   *%rax
// fc: eb b2                         jmp     0xb0 <_JIT_ENTRY+0xb0>
// fe: 48 8b 74 24 20                movq    0x20(%rsp), %rsi
// 103: 48 85 f6                      testq   %rsi, %rsi
// 106: 74 56                         je      0x15e <_JIT_ENTRY+0x15e>
// 108: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010a:  R_X86_64_64  _JIT_OPARG
// 112: 0f b7 c8                      movzwl  %ax, %ecx
// 115: 0f b7 c0                      movzwl  %ax, %eax
// 118: 48 c1 e0 03                   shlq    $0x3, %rax
// 11c: 48 f7 d8                      negq    %rax
// 11f: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// 124: 48 89 74 02 08                movq    %rsi, 0x8(%rdx,%rax)
// 129: b8 01 00 00 00                movl    $0x1, %eax
// 12e: 29 c8                         subl    %ecx, %eax
// 130: 48 98                         cltq
// 132: 48 8d 34 c2                   leaq    (%rdx,%rax,8), %rsi
// 136: 48 83 c6 08                   addq    $0x8, %rsi
// 13a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013c:  R_X86_64_64  _JIT_CONTINUE
// 144: 48 8b 7c 24 08                movq    0x8(%rsp), %rdi
// 149: 48 8b 54 24 18                movq    0x18(%rsp), %rdx
// 14e: 48 83 c4 28                   addq    $0x28, %rsp
// 152: 5b                            popq    %rbx
// 153: 41 5c                         popq    %r12
// 155: 41 5d                         popq    %r13
// 157: 41 5e                         popq    %r14
// 159: 41 5f                         popq    %r15
// 15b: 5d                            popq    %rbp
// 15c: ff e0                         jmpq    *%rax
// 15e: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 163: 49 29 c4                      subq    %rax, %r12
// 166: 49 83 c4 b8                   addq    $-0x48, %r12
// 16a: 49 c1 ec 03                   shrq    $0x3, %r12
// 16e: 44 89 60 40                   movl    %r12d, 0x40(%rax)
// 172: 31 c0                         xorl    %eax, %eax
// 174: 48 83 c4 28                   addq    $0x28, %rsp
// 178: 5b                            popq    %rbx
// 179: 41 5c                         popq    %r12
// 17b: 41 5d                         popq    %r13
// 17d: 41 5e                         popq    %r14
// 17f: 41 5f                         popq    %r15
// 181: 5d                            popq    %rbp
// 182: c3                            retq
// 183: 
static const unsigned char _PUSH_NULLplus_BUILD_STRING_code_body[388] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x08, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd3, 0x48, 0x8d, 0x04, 0xd5, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xd8, 0x48, 0x89, 0x74, 0x24, 0x10, 0x4c, 0x8d, 0x24, 0x06, 0x49, 0x83, 0xc4, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x81, 0xc7, 0x00, 0xa1, 0x00, 0x00, 0x4c, 0x89, 0xe6, 0xff, 0xd0, 0x48, 0x89, 0x44, 0x24, 0x20, 0xf7, 0xc3, 0xff, 0xff, 0x00, 0x00, 0x0f, 0x8e, 0x89, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd8, 0x48, 0xff, 0xc3, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x14, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xcb, 0x48, 0x83, 0xfb, 0x01, 0x7e, 0x45, 0x8d, 0x43, 0xfe, 0x4d, 0x8b, 0x34, 0xc4, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x08, 0x85, 0xc0, 0x78, 0xe4, 0xeb, 0x17, 0x66, 0x90, 0x48, 0x89, 0xef, 0xbe, 0x13, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x41, 0xff, 0xd5, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0xcb, 0x41, 0xff, 0xd7, 0x49, 0xff, 0x0e, 0x75, 0xc3, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0xb2, 0x48, 0x8b, 0x74, 0x24, 0x20, 0x48, 0x85, 0xf6, 0x74, 0x56, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x48, 0xf7, 0xd8, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x89, 0x74, 0x02, 0x08, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x29, 0xc8, 0x48, 0x98, 0x48, 0x8d, 0x34, 0xc2, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7c, 0x24, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x18, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x49, 0x29, 0xc4, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x60, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_STRING_code_holes[11] = {
    {0x21, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x46, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyUnicode_JoinArray, 0x0},
    {0x50, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyRuntime, 0x0},
    {0x77, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x87, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x91, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xf2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x10a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x13c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_BUILD_STRING_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_BUILD_STRING_data_holes[1];

// _PUSH_NULLplus_BUILD_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_BUILD_TUPLE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d6                      movq    %rdx, %r14
// b: 49 89 f7                      movq    %rsi, %r15
// e: 48 89 fb                      movq    %rdi, %rbx
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 f0                      movzwl  %ax, %esi
// 25: 48 8d 04 f5 00 00 00 00       leaq    (,%rsi,8), %rax
// 2d: 48 f7 d8                      negq    %rax
// 30: 4d 8d 24 07                   leaq    (%r15,%rax), %r12
// 34: 49 83 c4 08                   addq    $0x8, %r12
// 38: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003a:  R_X86_64_64  _PyTuple_FromArraySteal
// 42: 4c 89 e7                      movq    %r12, %rdi
// 45: ff d0                         callq   *%rax
// 47: 48 85 c0                      testq   %rax, %rax
// 4a: 74 4a                         je      0x96 <_JIT_ENTRY+0x96>
// 4c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004e:  R_X86_64_64  _JIT_OPARG
// 56: 0f b7 d1                      movzwl  %cx, %edx
// 59: 0f b7 c9                      movzwl  %cx, %ecx
// 5c: 48 c1 e1 03                   shlq    $0x3, %rcx
// 60: 48 f7 d9                      negq    %rcx
// 63: 49 89 44 0f 08                movq    %rax, 0x8(%r15,%rcx)
// 68: b8 01 00 00 00                movl    $0x1, %eax
// 6d: 29 d0                         subl    %edx, %eax
// 6f: 48 98                         cltq
// 71: 49 8d 34 c7                   leaq    (%r15,%rax,8), %rsi
// 75: 48 83 c6 08                   addq    $0x8, %rsi
// 79: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007b:  R_X86_64_64  _JIT_CONTINUE
// 83: 48 89 df                      movq    %rbx, %rdi
// 86: 4c 89 f2                      movq    %r14, %rdx
// 89: 48 83 c4 08                   addq    $0x8, %rsp
// 8d: 5b                            popq    %rbx
// 8e: 41 5c                         popq    %r12
// 90: 41 5e                         popq    %r14
// 92: 41 5f                         popq    %r15
// 94: ff e0                         jmpq    *%rax
// 96: 49 29 dc                      subq    %rbx, %r12
// 99: 49 83 c4 b8                   addq    $-0x48, %r12
// 9d: 49 c1 ec 03                   shrq    $0x3, %r12
// a1: 44 89 63 40                   movl    %r12d, 0x40(%rbx)
// a5: 31 c0                         xorl    %eax, %eax
// a7: 48 83 c4 08                   addq    $0x8, %rsp
// ab: 5b                            popq    %rbx
// ac: 41 5c                         popq    %r12
// ae: 41 5e                         popq    %r14
// b0: 41 5f                         popq    %r15
// b2: c3                            retq
// b3: 
static const unsigned char _PUSH_NULLplus_BUILD_TUPLE_code_body[180] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd6, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf0, 0x48, 0x8d, 0x04, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xd8, 0x4d, 0x8d, 0x24, 0x07, 0x49, 0x83, 0xc4, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x4a, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd1, 0x0f, 0xb7, 0xc9, 0x48, 0xc1, 0xe1, 0x03, 0x48, 0xf7, 0xd9, 0x49, 0x89, 0x44, 0x0f, 0x08, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x29, 0xd0, 0x48, 0x98, 0x49, 0x8d, 0x34, 0xc7, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x49, 0x29, 0xdc, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x63, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_BUILD_TUPLE_code_holes[5] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyTuple_FromArraySteal, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x7b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_BUILD_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_BUILD_TUPLE_data_holes[1];

// _PUSH_NULLplus_CALL_BUILTIN_CLASS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_BUILTIN_CLASS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 44 0f b7 c1                   movzwl  %cx, %r8d
// 26: 44 89 c0                      movl    %r8d, %eax
// 29: f7 d0                         notl    %eax
// 2b: 4c 63 c8                      movslq  %eax, %r9
// 2e: 4a 8b 44 ce 08                movq    0x8(%rsi,%r9,8), %rax
// 33: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 38: 44 29 c6                      subl    %r8d, %esi
// 3b: 4c 63 d6                      movslq  %esi, %r10
// 3e: 0f b7 c9                      movzwl  %cx, %ecx
// 41: be 01 00 00 00                movl    $0x1, %esi
// 46: 48 29 ce                      subq    %rcx, %rsi
// 49: 48 f7 d9                      negq    %rcx
// 4c: 41 8d 58 01                   leal    0x1(%r8), %ebx
// 50: 48 85 c0                      testq   %rax, %rax
// 53: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 57: 41 0f 44 d8                   cmovel  %r8d, %ebx
// 5b: 4f 8b 64 d7 08                movq    0x8(%r15,%r10,8), %r12
// 60: 49 8b 74 24 08                movq    0x8(%r12), %rsi
// 65: f6 86 ab 00 00 00 80          testb   $-0x80, 0xab(%rsi)
// 6c: 74 76                         je      0xe4 <_JIT_ENTRY+0xe4>
// 6e: 4d 8b 84 24 90 01 00 00       movq    0x190(%r12), %r8
// 76: 4d 85 c0                      testq   %r8, %r8
// 79: 74 69                         je      0xe4 <_JIT_ENTRY+0xe4>
// 7b: 4c 89 54 24 10                movq    %r10, 0x10(%rsp)
// 80: 4c 89 0c 24                   movq    %r9, (%rsp)
// 84: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// 89: 48 89 7c 24 20                movq    %rdi, 0x20(%rsp)
// 8e: 49 8d 2c cf                   leaq    (%r15,%rcx,8), %rbp
// 92: 48 85 c0                      testq   %rax, %rax
// 95: 41 0f 94 c6                   sete    %r14b
// 99: 89 da                         movl    %ebx, %edx
// 9b: 4c 89 e7                      movq    %r12, %rdi
// 9e: 48 89 ee                      movq    %rbp, %rsi
// a1: 31 c9                         xorl    %ecx, %ecx
// a3: 41 ff d0                      callq   *%r8
// a6: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// ab: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ad:  R_X86_64_64  _JIT_OPARG
// b5: 66 85 c0                      testw   %ax, %ax
// b8: 0f 94 c0                      sete    %al
// bb: 41 84 c6                      testb   %al, %r14b
// be: 74 55                         je      0x115 <_JIT_ENTRY+0x115>
// c0: 49 8b 04 24                   movq    (%r12), %rax
// c4: 48 85 c0                      testq   %rax, %rax
// c7: 0f 8e ca 00 00 00             jle     0x197 <_JIT_ENTRY+0x197>
// cd: 85 c0                         testl   %eax, %eax
// cf: 4c 8b 6c 24 18                movq    0x18(%rsp), %r13
// d4: 48 8b 5c 24 10                movq    0x10(%rsp), %rbx
// d9: 0f 89 e8 00 00 00             jns     0x1c7 <_JIT_ENTRY+0x1c7>
// df: e9 04 01 00 00                jmp     0x1e8 <_JIT_ENTRY+0x1e8>
// e4: 49 83 c7 08                   addq    $0x8, %r15
// e8: 49 29 ff                      subq    %rdi, %r15
// eb: 49 83 c7 b8                   addq    $-0x48, %r15
// ef: 49 c1 ef 03                   shrq    $0x3, %r15
// f3: 44 89 7f 40                   movl    %r15d, 0x40(%rdi)
// f7: 48 8b 07                      movq    (%rdi), %rax
// fa: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000fc:  R_X86_64_64  _JIT_TARGET
// 104: 89 c9                         movl    %ecx, %ecx
// 106: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 10a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 110: e9 2a 01 00 00                jmp     0x23f <_JIT_ENTRY+0x23f>
// 115: 83 fb 02                      cmpl    $0x2, %ebx
// 118: 41 bd 01 00 00 00             movl    $0x1, %r13d
// 11e: 44 0f 43 eb                   cmovael %ebx, %r13d
// 122: 31 db                         xorl    %ebx, %ebx
// 124: eb 12                         jmp     0x138 <_JIT_ENTRY+0x138>
// 126: 66 2e 0f 1f 84 00 00 00 00 00 nopw    %cs:(%rax,%rax)
// 130: 48 ff c3                      incq    %rbx
// 133: 49 39 dd                      cmpq    %rbx, %r13
// 136: 74 88                         je      0xc0 <_JIT_ENTRY+0xc0>
// 138: 4c 8b 74 dd 00                movq    (%rbp,%rbx,8), %r14
// 13d: 49 8b 06                      movq    (%r14), %rax
// 140: 48 85 c0                      testq   %rax, %rax
// 143: 7e 0b                         jle     0x150 <_JIT_ENTRY+0x150>
// 145: 85 c0                         testl   %eax, %eax
// 147: 78 e7                         js      0x130 <_JIT_ENTRY+0x130>
// 149: eb 2a                         jmp     0x175 <_JIT_ENTRY+0x175>
// 14b: 0f 1f 44 00 00                nopl    (%rax,%rax)
// 150: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000152:  R_X86_64_64  .rodata.str1.1
// 15a: be db 0a 00 00                movl    $0xadb, %esi            # imm = 0xADB
// 15f: 4c 89 f2                      movq    %r14, %rdx
// 162: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000164:  R_X86_64_64  _Py_NegativeRefcount
// 16c: ff d0                         callq   *%rax
// 16e: 49 8b 06                      movq    (%r14), %rax
// 171: 85 c0                         testl   %eax, %eax
// 173: 78 bb                         js      0x130 <_JIT_ENTRY+0x130>
// 175: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000177:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 17f: ff d0                         callq   *%rax
// 181: 49 ff 0e                      decq    (%r14)
// 184: 75 aa                         jne     0x130 <_JIT_ENTRY+0x130>
// 186: 4c 89 f7                      movq    %r14, %rdi
// 189: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000018b:  R_X86_64_64  _Py_Dealloc
// 193: ff d0                         callq   *%rax
// 195: eb 99                         jmp     0x130 <_JIT_ENTRY+0x130>
// 197: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000199:  R_X86_64_64  .rodata.str1.1
// 1a1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001a3:  R_X86_64_64  _Py_NegativeRefcount
// 1ab: be dd 0a 00 00                movl    $0xadd, %esi            # imm = 0xADD
// 1b0: 4c 89 e2                      movq    %r12, %rdx
// 1b3: ff d0                         callq   *%rax
// 1b5: 49 8b 04 24                   movq    (%r12), %rax
// 1b9: 85 c0                         testl   %eax, %eax
// 1bb: 4c 8b 6c 24 18                movq    0x18(%rsp), %r13
// 1c0: 48 8b 5c 24 10                movq    0x10(%rsp), %rbx
// 1c5: 78 21                         js      0x1e8 <_JIT_ENTRY+0x1e8>
// 1c7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c9:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 1d1: ff d0                         callq   *%rax
// 1d3: 49 ff 0c 24                   decq    (%r12)
// 1d7: 75 0f                         jne     0x1e8 <_JIT_ENTRY+0x1e8>
// 1d9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001db:  R_X86_64_64  _Py_Dealloc
// 1e3: 4c 89 e7                      movq    %r12, %rdi
// 1e6: ff d0                         callq   *%rax
// 1e8: 49 8d 04 df                   leaq    (%r15,%rbx,8), %rax
// 1ec: 48 83 c0 08                   addq    $0x8, %rax
// 1f0: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 1f5: 48 85 d2                      testq   %rdx, %rdx
// 1f8: 48 8b 5c 24 20                movq    0x20(%rsp), %rbx
// 1fd: 74 30                         je      0x22f <_JIT_ENTRY+0x22f>
// 1ff: 48 8b 0c 24                   movq    (%rsp), %rcx
// 203: 4d 8d 34 cf                   leaq    (%r15,%rcx,8), %r14
// 207: 49 83 c6 08                   addq    $0x8, %r14
// 20b: 48 89 10                      movq    %rdx, (%rax)
// 20e: 49 8b 45 10                   movq    0x10(%r13), %rax
// 212: 48 8b 00                      movq    (%rax), %rax
// 215: 84 c0                         testb   %al, %al
// 217: 74 35                         je      0x24e <_JIT_ENTRY+0x24e>
// 219: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000021b:  R_X86_64_64  _Py_HandlePending
// 223: 4c 89 ef                      movq    %r13, %rdi
// 226: ff d0                         callq   *%rax
// 228: 85 c0                         testl   %eax, %eax
// 22a: 74 22                         je      0x24e <_JIT_ENTRY+0x24e>
// 22c: 4c 89 f0                      movq    %r14, %rax
// 22f: 48 29 d8                      subq    %rbx, %rax
// 232: 48 83 c0 b8                   addq    $-0x48, %rax
// 236: 48 c1 e8 03                   shrq    $0x3, %rax
// 23a: 89 43 40                      movl    %eax, 0x40(%rbx)
// 23d: 31 c0                         xorl    %eax, %eax
// 23f: 48 83 c4 28                   addq    $0x28, %rsp
// 243: 5b                            popq    %rbx
// 244: 41 5c                         popq    %r12
// 246: 41 5d                         popq    %r13
// 248: 41 5e                         popq    %r14
// 24a: 41 5f                         popq    %r15
// 24c: 5d                            popq    %rbp
// 24d: c3                            retq
// 24e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000250:  R_X86_64_64  _JIT_CONTINUE
// 258: 48 89 df                      movq    %rbx, %rdi
// 25b: 4c 89 f6                      movq    %r14, %rsi
// 25e: 4c 89 ea                      movq    %r13, %rdx
// 261: 48 83 c4 28                   addq    $0x28, %rsp
// 265: 5b                            popq    %rbx
// 266: 41 5c                         popq    %r12
// 268: 41 5d                         popq    %r13
// 26a: 41 5e                         popq    %r14
// 26c: 41 5f                         popq    %r15
// 26e: 5d                            popq    %rbp
// 26f: ff e0                         jmpq    *%rax
// 271: 
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_CLASS_code_body[626] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xc1, 0x44, 0x89, 0xc0, 0xf7, 0xd0, 0x4c, 0x63, 0xc8, 0x4a, 0x8b, 0x44, 0xce, 0x08, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x44, 0x29, 0xc6, 0x4c, 0x63, 0xd6, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xce, 0x48, 0xf7, 0xd9, 0x41, 0x8d, 0x58, 0x01, 0x48, 0x85, 0xc0, 0x48, 0x0f, 0x44, 0xce, 0x41, 0x0f, 0x44, 0xd8, 0x4f, 0x8b, 0x64, 0xd7, 0x08, 0x49, 0x8b, 0x74, 0x24, 0x08, 0xf6, 0x86, 0xab, 0x00, 0x00, 0x00, 0x80, 0x74, 0x76, 0x4d, 0x8b, 0x84, 0x24, 0x90, 0x01, 0x00, 0x00, 0x4d, 0x85, 0xc0, 0x74, 0x69, 0x4c, 0x89, 0x54, 0x24, 0x10, 0x4c, 0x89, 0x0c, 0x24, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x20, 0x49, 0x8d, 0x2c, 0xcf, 0x48, 0x85, 0xc0, 0x41, 0x0f, 0x94, 0xc6, 0x89, 0xda, 0x4c, 0x89, 0xe7, 0x48, 0x89, 0xee, 0x31, 0xc9, 0x41, 0xff, 0xd0, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x94, 0xc0, 0x41, 0x84, 0xc6, 0x74, 0x55, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x0f, 0x8e, 0xca, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x4c, 0x8b, 0x6c, 0x24, 0x18, 0x48, 0x8b, 0x5c, 0x24, 0x10, 0x0f, 0x89, 0xe8, 0x00, 0x00, 0x00, 0xe9, 0x04, 0x01, 0x00, 0x00, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xff, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xe9, 0x2a, 0x01, 0x00, 0x00, 0x83, 0xfb, 0x02, 0x41, 0xbd, 0x01, 0x00, 0x00, 0x00, 0x44, 0x0f, 0x43, 0xeb, 0x31, 0xdb, 0xeb, 0x12, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xc3, 0x49, 0x39, 0xdd, 0x74, 0x88, 0x4c, 0x8b, 0x74, 0xdd, 0x00, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x0b, 0x85, 0xc0, 0x78, 0xe7, 0xeb, 0x2a, 0x0f, 0x1f, 0x44, 0x00, 0x00, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xdb, 0x0a, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0xbb, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x75, 0xaa, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0x99, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xdd, 0x0a, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x4c, 0x8b, 0x6c, 0x24, 0x18, 0x48, 0x8b, 0x5c, 0x24, 0x10, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0x8d, 0x04, 0xdf, 0x48, 0x83, 0xc0, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x85, 0xd2, 0x48, 0x8b, 0x5c, 0x24, 0x20, 0x74, 0x30, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x34, 0xcf, 0x49, 0x83, 0xc6, 0x08, 0x48, 0x89, 0x10, 0x49, 0x8b, 0x45, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x35, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x22, 0x4c, 0x89, 0xf0, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x4c, 0x89, 0xea, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_CLASS_code_holes[14] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xad, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xfc, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x152, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x164, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x177, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x18b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x199, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x1a3, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x1c9, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x1db, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x21b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x250, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_CLASS_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_CLASS_data_holes[1];

// _PUSH_NULLplus_CALL_BUILTIN_FAST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_BUILTIN_FAST.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 44 0f b7 c1                   movzwl  %cx, %r8d
// 26: 44 89 c0                      movl    %r8d, %eax
// 29: f7 d0                         notl    %eax
// 2b: 4c 63 c8                      movslq  %eax, %r9
// 2e: 4a 8b 44 ce 08                movq    0x8(%rsi,%r9,8), %rax
// 33: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 38: 44 29 c6                      subl    %r8d, %esi
// 3b: 4c 63 d6                      movslq  %esi, %r10
// 3e: 0f b7 c9                      movzwl  %cx, %ecx
// 41: be 01 00 00 00                movl    $0x1, %esi
// 46: 48 29 ce                      subq    %rcx, %rsi
// 49: 48 f7 d9                      negq    %rcx
// 4c: 41 8d 58 01                   leal    0x1(%r8), %ebx
// 50: 48 85 c0                      testq   %rax, %rax
// 53: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 57: 41 0f 44 d8                   cmovel  %r8d, %ebx
// 5b: 4f 8b 64 d7 08                movq    0x8(%r15,%r10,8), %r12
// 60: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000062:  R_X86_64_64  PyCFunction_Type
// 6a: 49 39 74 24 08                cmpq    %rsi, 0x8(%r12)
// 6f: 0f 85 18 01 00 00             jne     0x18d <_JIT_ENTRY+0x18d>
// 75: 4d 8b 44 24 10                movq    0x10(%r12), %r8
// 7a: 41 81 78 10 80 00 00 00       cmpl    $0x80, 0x10(%r8)
// 82: 0f 85 05 01 00 00             jne     0x18d <_JIT_ENTRY+0x18d>
// 88: 4c 89 54 24 10                movq    %r10, 0x10(%rsp)
// 8d: 4c 89 0c 24                   movq    %r9, (%rsp)
// 91: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// 96: 48 89 7c 24 20                movq    %rdi, 0x20(%rsp)
// 9b: 49 8d 2c cf                   leaq    (%r15,%rcx,8), %rbp
// 9f: 48 85 c0                      testq   %rax, %rax
// a2: 41 0f 94 c6                   sete    %r14b
// a6: 49 8b 7c 24 18                movq    0x18(%r12), %rdi
// ab: 89 da                         movl    %ebx, %edx
// ad: 48 89 ee                      movq    %rbp, %rsi
// b0: 41 ff 50 08                   callq   *0x8(%r8)
// b4: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// b9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000bb:  R_X86_64_64  _JIT_OPARG
// c3: 66 85 c0                      testw   %ax, %ax
// c6: 0f 94 c0                      sete    %al
// c9: 41 84 c6                      testb   %al, %r14b
// cc: 0f 84 f6 00 00 00             je      0x1c8 <_JIT_ENTRY+0x1c8>
// d2: 49 8b 04 24                   movq    (%r12), %rax
// d6: 48 85 c0                      testq   %rax, %rax
// d9: 7f 22                         jg      0xfd <_JIT_ENTRY+0xfd>
// db: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000dd:  R_X86_64_64  .rodata.str1.1
// e5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e7:  R_X86_64_64  _Py_NegativeRefcount
// ef: be 28 0b 00 00                movl    $0xb28, %esi            # imm = 0xB28
// f4: 4c 89 e2                      movq    %r12, %rdx
// f7: ff d0                         callq   *%rax
// f9: 49 8b 04 24                   movq    (%r12), %rax
// fd: 85 c0                         testl   %eax, %eax
// ff: 4c 8b 6c 24 18                movq    0x18(%rsp), %r13
// 104: 48 8b 5c 24 10                movq    0x10(%rsp), %rbx
// 109: 78 21                         js      0x12c <_JIT_ENTRY+0x12c>
// 10b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010d:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 115: ff d0                         callq   *%rax
// 117: 49 ff 0c 24                   decq    (%r12)
// 11b: 75 0f                         jne     0x12c <_JIT_ENTRY+0x12c>
// 11d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011f:  R_X86_64_64  _Py_Dealloc
// 127: 4c 89 e7                      movq    %r12, %rdi
// 12a: ff d0                         callq   *%rax
// 12c: 49 8d 04 df                   leaq    (%r15,%rbx,8), %rax
// 130: 48 83 c0 08                   addq    $0x8, %rax
// 134: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 139: 48 85 d2                      testq   %rdx, %rdx
// 13c: 48 8b 5c 24 20                movq    0x20(%rsp), %rbx
// 141: 74 38                         je      0x17b <_JIT_ENTRY+0x17b>
// 143: 48 8b 0c 24                   movq    (%rsp), %rcx
// 147: 4d 8d 34 cf                   leaq    (%r15,%rcx,8), %r14
// 14b: 49 83 c6 08                   addq    $0x8, %r14
// 14f: 48 89 10                      movq    %rdx, (%rax)
// 152: 49 8b 45 10                   movq    0x10(%r13), %rax
// 156: 48 8b 00                      movq    (%rax), %rax
// 159: 84 c0                         testb   %al, %al
// 15b: 0f 84 e6 00 00 00             je      0x247 <_JIT_ENTRY+0x247>
// 161: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000163:  R_X86_64_64  _Py_HandlePending
// 16b: 4c 89 ef                      movq    %r13, %rdi
// 16e: ff d0                         callq   *%rax
// 170: 85 c0                         testl   %eax, %eax
// 172: 0f 84 cf 00 00 00             je      0x247 <_JIT_ENTRY+0x247>
// 178: 4c 89 f0                      movq    %r14, %rax
// 17b: 48 29 d8                      subq    %rbx, %rax
// 17e: 48 83 c0 b8                   addq    $-0x48, %rax
// 182: 48 c1 e8 03                   shrq    $0x3, %rax
// 186: 89 43 40                      movl    %eax, 0x40(%rbx)
// 189: 31 c0                         xorl    %eax, %eax
// 18b: eb 2c                         jmp     0x1b9 <_JIT_ENTRY+0x1b9>
// 18d: 49 83 c7 08                   addq    $0x8, %r15
// 191: 49 29 ff                      subq    %rdi, %r15
// 194: 49 83 c7 b8                   addq    $-0x48, %r15
// 198: 49 c1 ef 03                   shrq    $0x3, %r15
// 19c: 44 89 7f 40                   movl    %r15d, 0x40(%rdi)
// 1a0: 48 8b 07                      movq    (%rdi), %rax
// 1a3: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000001a5:  R_X86_64_64  _JIT_TARGET
// 1ad: 89 c9                         movl    %ecx, %ecx
// 1af: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 1b3: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 1b9: 48 83 c4 28                   addq    $0x28, %rsp
// 1bd: 5b                            popq    %rbx
// 1be: 41 5c                         popq    %r12
// 1c0: 41 5d                         popq    %r13
// 1c2: 41 5e                         popq    %r14
// 1c4: 41 5f                         popq    %r15
// 1c6: 5d                            popq    %rbp
// 1c7: c3                            retq
// 1c8: 83 fb 02                      cmpl    $0x2, %ebx
// 1cb: 41 bd 01 00 00 00             movl    $0x1, %r13d
// 1d1: 44 0f 43 eb                   cmovael %ebx, %r13d
// 1d5: 31 db                         xorl    %ebx, %ebx
// 1d7: eb 13                         jmp     0x1ec <_JIT_ENTRY+0x1ec>
// 1d9: 0f 1f 80 00 00 00 00          nopl    (%rax)
// 1e0: 48 ff c3                      incq    %rbx
// 1e3: 49 39 dd                      cmpq    %rbx, %r13
// 1e6: 0f 84 e6 fe ff ff             je      0xd2 <_JIT_ENTRY+0xd2>
// 1ec: 4c 8b 74 dd 00                movq    (%rbp,%rbx,8), %r14
// 1f1: 49 8b 06                      movq    (%r14), %rax
// 1f4: 48 85 c0                      testq   %rax, %rax
// 1f7: 7e 07                         jle     0x200 <_JIT_ENTRY+0x200>
// 1f9: 85 c0                         testl   %eax, %eax
// 1fb: 78 e3                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 1fd: eb 26                         jmp     0x225 <_JIT_ENTRY+0x225>
// 1ff: 90                            nop
// 200: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000202:  R_X86_64_64  .rodata.str1.1
// 20a: be 26 0b 00 00                movl    $0xb26, %esi            # imm = 0xB26
// 20f: 4c 89 f2                      movq    %r14, %rdx
// 212: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000214:  R_X86_64_64  _Py_NegativeRefcount
// 21c: ff d0                         callq   *%rax
// 21e: 49 8b 06                      movq    (%r14), %rax
// 221: 85 c0                         testl   %eax, %eax
// 223: 78 bb                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 225: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000227:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 22f: ff d0                         callq   *%rax
// 231: 49 ff 0e                      decq    (%r14)
// 234: 75 aa                         jne     0x1e0 <_JIT_ENTRY+0x1e0>
// 236: 4c 89 f7                      movq    %r14, %rdi
// 239: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000023b:  R_X86_64_64  _Py_Dealloc
// 243: ff d0                         callq   *%rax
// 245: eb 99                         jmp     0x1e0 <_JIT_ENTRY+0x1e0>
// 247: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000249:  R_X86_64_64  _JIT_CONTINUE
// 251: 48 89 df                      movq    %rbx, %rdi
// 254: 4c 89 f6                      movq    %r14, %rsi
// 257: 4c 89 ea                      movq    %r13, %rdx
// 25a: 48 83 c4 28                   addq    $0x28, %rsp
// 25e: 5b                            popq    %rbx
// 25f: 41 5c                         popq    %r12
// 261: 41 5d                         popq    %r13
// 263: 41 5e                         popq    %r14
// 265: 41 5f                         popq    %r15
// 267: 5d                            popq    %rbp
// 268: ff e0                         jmpq    *%rax
// 26a: 
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_FAST_code_body[619] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xc1, 0x44, 0x89, 0xc0, 0xf7, 0xd0, 0x4c, 0x63, 0xc8, 0x4a, 0x8b, 0x44, 0xce, 0x08, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x44, 0x29, 0xc6, 0x4c, 0x63, 0xd6, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xce, 0x48, 0xf7, 0xd9, 0x41, 0x8d, 0x58, 0x01, 0x48, 0x85, 0xc0, 0x48, 0x0f, 0x44, 0xce, 0x41, 0x0f, 0x44, 0xd8, 0x4f, 0x8b, 0x64, 0xd7, 0x08, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x74, 0x24, 0x08, 0x0f, 0x85, 0x18, 0x01, 0x00, 0x00, 0x4d, 0x8b, 0x44, 0x24, 0x10, 0x41, 0x81, 0x78, 0x10, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x85, 0x05, 0x01, 0x00, 0x00, 0x4c, 0x89, 0x54, 0x24, 0x10, 0x4c, 0x89, 0x0c, 0x24, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x20, 0x49, 0x8d, 0x2c, 0xcf, 0x48, 0x85, 0xc0, 0x41, 0x0f, 0x94, 0xc6, 0x49, 0x8b, 0x7c, 0x24, 0x18, 0x89, 0xda, 0x48, 0x89, 0xee, 0x41, 0xff, 0x50, 0x08, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x94, 0xc0, 0x41, 0x84, 0xc6, 0x0f, 0x84, 0xf6, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x28, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x4c, 0x8b, 0x6c, 0x24, 0x18, 0x48, 0x8b, 0x5c, 0x24, 0x10, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0x8d, 0x04, 0xdf, 0x48, 0x83, 0xc0, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x85, 0xd2, 0x48, 0x8b, 0x5c, 0x24, 0x20, 0x74, 0x38, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x34, 0xcf, 0x49, 0x83, 0xc6, 0x08, 0x48, 0x89, 0x10, 0x49, 0x8b, 0x45, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x0f, 0x84, 0xe6, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x84, 0xcf, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf0, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0xeb, 0x2c, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xff, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x83, 0xfb, 0x02, 0x41, 0xbd, 0x01, 0x00, 0x00, 0x00, 0x44, 0x0f, 0x43, 0xeb, 0x31, 0xdb, 0xeb, 0x13, 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xc3, 0x49, 0x39, 0xdd, 0x0f, 0x84, 0xe6, 0xfe, 0xff, 0xff, 0x4c, 0x8b, 0x74, 0xdd, 0x00, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x07, 0x85, 0xc0, 0x78, 0xe3, 0xeb, 0x26, 0x90, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x26, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0xbb, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x75, 0xaa, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0x99, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x4c, 0x89, 0xea, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_FAST_code_holes[15] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyCFunction_Type, 0x0},
    {0xbb, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xdd, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xe7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x10d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x11f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x163, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x1a5, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x202, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x214, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x227, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x23b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x249, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_FAST_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_FAST_data_holes[1];

// _PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 44 0f b7 c1                   movzwl  %cx, %r8d
// 26: 44 89 c0                      movl    %r8d, %eax
// 29: f7 d0                         notl    %eax
// 2b: 4c 63 c8                      movslq  %eax, %r9
// 2e: 4a 8b 44 ce 08                movq    0x8(%rsi,%r9,8), %rax
// 33: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 38: 44 29 c6                      subl    %r8d, %esi
// 3b: 4c 63 d6                      movslq  %esi, %r10
// 3e: 0f b7 c9                      movzwl  %cx, %ecx
// 41: be 01 00 00 00                movl    $0x1, %esi
// 46: 48 29 ce                      subq    %rcx, %rsi
// 49: 48 f7 d9                      negq    %rcx
// 4c: 41 8d 58 01                   leal    0x1(%r8), %ebx
// 50: 48 85 c0                      testq   %rax, %rax
// 53: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 57: 41 0f 44 d8                   cmovel  %r8d, %ebx
// 5b: 4f 8b 64 d7 08                movq    0x8(%r15,%r10,8), %r12
// 60: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000062:  R_X86_64_64  PyCFunction_Type
// 6a: 49 39 74 24 08                cmpq    %rsi, 0x8(%r12)
// 6f: 0f 85 1a 01 00 00             jne     0x18f <_JIT_ENTRY+0x18f>
// 75: 4d 8b 44 24 10                movq    0x10(%r12), %r8
// 7a: 41 81 78 10 82 00 00 00       cmpl    $0x82, 0x10(%r8)
// 82: 0f 85 07 01 00 00             jne     0x18f <_JIT_ENTRY+0x18f>
// 88: 4c 89 54 24 10                movq    %r10, 0x10(%rsp)
// 8d: 4c 89 0c 24                   movq    %r9, (%rsp)
// 91: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// 96: 48 89 7c 24 20                movq    %rdi, 0x20(%rsp)
// 9b: 49 8d 2c cf                   leaq    (%r15,%rcx,8), %rbp
// 9f: 48 85 c0                      testq   %rax, %rax
// a2: 41 0f 94 c6                   sete    %r14b
// a6: 49 8b 7c 24 18                movq    0x18(%r12), %rdi
// ab: 89 da                         movl    %ebx, %edx
// ad: 48 89 ee                      movq    %rbp, %rsi
// b0: 31 c9                         xorl    %ecx, %ecx
// b2: 41 ff 50 08                   callq   *0x8(%r8)
// b6: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// bb: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000bd:  R_X86_64_64  _JIT_OPARG
// c5: 66 85 c0                      testw   %ax, %ax
// c8: 0f 94 c0                      sete    %al
// cb: 41 84 c6                      testb   %al, %r14b
// ce: 0f 84 f6 00 00 00             je      0x1ca <_JIT_ENTRY+0x1ca>
// d4: 49 8b 04 24                   movq    (%r12), %rax
// d8: 48 85 c0                      testq   %rax, %rax
// db: 7f 22                         jg      0xff <_JIT_ENTRY+0xff>
// dd: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000df:  R_X86_64_64  .rodata.str1.1
// e7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e9:  R_X86_64_64  _Py_NegativeRefcount
// f1: be 51 0b 00 00                movl    $0xb51, %esi            # imm = 0xB51
// f6: 4c 89 e2                      movq    %r12, %rdx
// f9: ff d0                         callq   *%rax
// fb: 49 8b 04 24                   movq    (%r12), %rax
// ff: 85 c0                         testl   %eax, %eax
// 101: 4c 8b 6c 24 18                movq    0x18(%rsp), %r13
// 106: 48 8b 5c 24 10                movq    0x10(%rsp), %rbx
// 10b: 78 21                         js      0x12e <_JIT_ENTRY+0x12e>
// 10d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010f:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 117: ff d0                         callq   *%rax
// 119: 49 ff 0c 24                   decq    (%r12)
// 11d: 75 0f                         jne     0x12e <_JIT_ENTRY+0x12e>
// 11f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000121:  R_X86_64_64  _Py_Dealloc
// 129: 4c 89 e7                      movq    %r12, %rdi
// 12c: ff d0                         callq   *%rax
// 12e: 49 8d 04 df                   leaq    (%r15,%rbx,8), %rax
// 132: 48 83 c0 08                   addq    $0x8, %rax
// 136: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 13b: 48 85 d2                      testq   %rdx, %rdx
// 13e: 48 8b 5c 24 20                movq    0x20(%rsp), %rbx
// 143: 74 38                         je      0x17d <_JIT_ENTRY+0x17d>
// 145: 48 8b 0c 24                   movq    (%rsp), %rcx
// 149: 4d 8d 34 cf                   leaq    (%r15,%rcx,8), %r14
// 14d: 49 83 c6 08                   addq    $0x8, %r14
// 151: 48 89 10                      movq    %rdx, (%rax)
// 154: 49 8b 45 10                   movq    0x10(%r13), %rax
// 158: 48 8b 00                      movq    (%rax), %rax
// 15b: 84 c0                         testb   %al, %al
// 15d: 0f 84 e4 00 00 00             je      0x247 <_JIT_ENTRY+0x247>
// 163: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000165:  R_X86_64_64  _Py_HandlePending
// 16d: 4c 89 ef                      movq    %r13, %rdi
// 170: ff d0                         callq   *%rax
// 172: 85 c0                         testl   %eax, %eax
// 174: 0f 84 cd 00 00 00             je      0x247 <_JIT_ENTRY+0x247>
// 17a: 4c 89 f0                      movq    %r14, %rax
// 17d: 48 29 d8                      subq    %rbx, %rax
// 180: 48 83 c0 b8                   addq    $-0x48, %rax
// 184: 48 c1 e8 03                   shrq    $0x3, %rax
// 188: 89 43 40                      movl    %eax, 0x40(%rbx)
// 18b: 31 c0                         xorl    %eax, %eax
// 18d: eb 2c                         jmp     0x1bb <_JIT_ENTRY+0x1bb>
// 18f: 49 83 c7 08                   addq    $0x8, %r15
// 193: 49 29 ff                      subq    %rdi, %r15
// 196: 49 83 c7 b8                   addq    $-0x48, %r15
// 19a: 49 c1 ef 03                   shrq    $0x3, %r15
// 19e: 44 89 7f 40                   movl    %r15d, 0x40(%rdi)
// 1a2: 48 8b 07                      movq    (%rdi), %rax
// 1a5: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000001a7:  R_X86_64_64  _JIT_TARGET
// 1af: 89 c9                         movl    %ecx, %ecx
// 1b1: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 1b5: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 1bb: 48 83 c4 28                   addq    $0x28, %rsp
// 1bf: 5b                            popq    %rbx
// 1c0: 41 5c                         popq    %r12
// 1c2: 41 5d                         popq    %r13
// 1c4: 41 5e                         popq    %r14
// 1c6: 41 5f                         popq    %r15
// 1c8: 5d                            popq    %rbp
// 1c9: c3                            retq
// 1ca: 83 fb 02                      cmpl    $0x2, %ebx
// 1cd: 41 bd 01 00 00 00             movl    $0x1, %r13d
// 1d3: 44 0f 43 eb                   cmovael %ebx, %r13d
// 1d7: 31 db                         xorl    %ebx, %ebx
// 1d9: eb 11                         jmp     0x1ec <_JIT_ENTRY+0x1ec>
// 1db: 0f 1f 44 00 00                nopl    (%rax,%rax)
// 1e0: 48 ff c3                      incq    %rbx
// 1e3: 49 39 dd                      cmpq    %rbx, %r13
// 1e6: 0f 84 e8 fe ff ff             je      0xd4 <_JIT_ENTRY+0xd4>
// 1ec: 4c 8b 74 dd 00                movq    (%rbp,%rbx,8), %r14
// 1f1: 49 8b 06                      movq    (%r14), %rax
// 1f4: 48 85 c0                      testq   %rax, %rax
// 1f7: 7e 07                         jle     0x200 <_JIT_ENTRY+0x200>
// 1f9: 85 c0                         testl   %eax, %eax
// 1fb: 78 e3                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 1fd: eb 26                         jmp     0x225 <_JIT_ENTRY+0x225>
// 1ff: 90                            nop
// 200: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000202:  R_X86_64_64  .rodata.str1.1
// 20a: be 4f 0b 00 00                movl    $0xb4f, %esi            # imm = 0xB4F
// 20f: 4c 89 f2                      movq    %r14, %rdx
// 212: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000214:  R_X86_64_64  _Py_NegativeRefcount
// 21c: ff d0                         callq   *%rax
// 21e: 49 8b 06                      movq    (%r14), %rax
// 221: 85 c0                         testl   %eax, %eax
// 223: 78 bb                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 225: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000227:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 22f: ff d0                         callq   *%rax
// 231: 49 ff 0e                      decq    (%r14)
// 234: 75 aa                         jne     0x1e0 <_JIT_ENTRY+0x1e0>
// 236: 4c 89 f7                      movq    %r14, %rdi
// 239: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000023b:  R_X86_64_64  _Py_Dealloc
// 243: ff d0                         callq   *%rax
// 245: eb 99                         jmp     0x1e0 <_JIT_ENTRY+0x1e0>
// 247: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000249:  R_X86_64_64  _JIT_CONTINUE
// 251: 48 89 df                      movq    %rbx, %rdi
// 254: 4c 89 f6                      movq    %r14, %rsi
// 257: 4c 89 ea                      movq    %r13, %rdx
// 25a: 48 83 c4 28                   addq    $0x28, %rsp
// 25e: 5b                            popq    %rbx
// 25f: 41 5c                         popq    %r12
// 261: 41 5d                         popq    %r13
// 263: 41 5e                         popq    %r14
// 265: 41 5f                         popq    %r15
// 267: 5d                            popq    %rbp
// 268: ff e0                         jmpq    *%rax
// 26a: 
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_code_body[619] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xc1, 0x44, 0x89, 0xc0, 0xf7, 0xd0, 0x4c, 0x63, 0xc8, 0x4a, 0x8b, 0x44, 0xce, 0x08, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x44, 0x29, 0xc6, 0x4c, 0x63, 0xd6, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xce, 0x48, 0xf7, 0xd9, 0x41, 0x8d, 0x58, 0x01, 0x48, 0x85, 0xc0, 0x48, 0x0f, 0x44, 0xce, 0x41, 0x0f, 0x44, 0xd8, 0x4f, 0x8b, 0x64, 0xd7, 0x08, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x74, 0x24, 0x08, 0x0f, 0x85, 0x1a, 0x01, 0x00, 0x00, 0x4d, 0x8b, 0x44, 0x24, 0x10, 0x41, 0x81, 0x78, 0x10, 0x82, 0x00, 0x00, 0x00, 0x0f, 0x85, 0x07, 0x01, 0x00, 0x00, 0x4c, 0x89, 0x54, 0x24, 0x10, 0x4c, 0x89, 0x0c, 0x24, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x20, 0x49, 0x8d, 0x2c, 0xcf, 0x48, 0x85, 0xc0, 0x41, 0x0f, 0x94, 0xc6, 0x49, 0x8b, 0x7c, 0x24, 0x18, 0x89, 0xda, 0x48, 0x89, 0xee, 0x31, 0xc9, 0x41, 0xff, 0x50, 0x08, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x94, 0xc0, 0x41, 0x84, 0xc6, 0x0f, 0x84, 0xf6, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x51, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x4c, 0x8b, 0x6c, 0x24, 0x18, 0x48, 0x8b, 0x5c, 0x24, 0x10, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0x8d, 0x04, 0xdf, 0x48, 0x83, 0xc0, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x85, 0xd2, 0x48, 0x8b, 0x5c, 0x24, 0x20, 0x74, 0x38, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x34, 0xcf, 0x49, 0x83, 0xc6, 0x08, 0x48, 0x89, 0x10, 0x49, 0x8b, 0x45, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x0f, 0x84, 0xe4, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x84, 0xcd, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf0, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0xeb, 0x2c, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xff, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x83, 0xfb, 0x02, 0x41, 0xbd, 0x01, 0x00, 0x00, 0x00, 0x44, 0x0f, 0x43, 0xeb, 0x31, 0xdb, 0xeb, 0x11, 0x0f, 0x1f, 0x44, 0x00, 0x00, 0x48, 0xff, 0xc3, 0x49, 0x39, 0xdd, 0x0f, 0x84, 0xe8, 0xfe, 0xff, 0xff, 0x4c, 0x8b, 0x74, 0xdd, 0x00, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x07, 0x85, 0xc0, 0x78, 0xe3, 0xeb, 0x26, 0x90, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x4f, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0xbb, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x75, 0xaa, 0x4c, 0x89, 0xf7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0x99, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x4c, 0x89, 0xea, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_code_holes[15] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyCFunction_Type, 0x0},
    {0xbd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xdf, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xe9, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x10f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x121, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x165, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x1a7, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x202, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x214, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x227, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x23b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x249, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_data_holes[1];

// _PUSH_NULLplus_CALL_BUILTIN_O
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_BUILTIN_O.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 49 89 f6                      movq    %rsi, %r14
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 c1                      movzwl  %cx, %eax
// 28: 89 c6                         movl    %eax, %esi
// 2a: f7 d6                         notl    %esi
// 2c: 4c 63 ee                      movslq  %esi, %r13
// 2f: 0f b7 c9                      movzwl  %cx, %ecx
// 32: 41 b8 01 00 00 00             movl    $0x1, %r8d
// 38: 49 29 c8                      subq    %rcx, %r8
// 3b: 48 89 cd                      movq    %rcx, %rbp
// 3e: 48 f7 dd                      negq    %rbp
// 41: 31 f6                         xorl    %esi, %esi
// 43: 66 85 c9                      testw   %cx, %cx
// 46: 40 0f 94 c6                   sete    %sil
// 4a: 31 ff                         xorl    %edi, %edi
// 4c: 66 83 f9 01                   cmpw    $0x1, %cx
// 50: 40 0f 94 c7                   sete    %dil
// 54: 4b 83 7c ee 08 00             cmpq    $0x0, 0x8(%r14,%r13,8)
// 5a: 49 0f 44 e8                   cmoveq  %r8, %rbp
// 5e: 4d 8d 7e 08                   leaq    0x8(%r14), %r15
// 62: 0f 44 f7                      cmovel  %edi, %esi
// 65: 40 80 fe 01                   cmpb    $0x1, %sil
// 69: 75 5c                         jne     0xc7 <_JIT_ENTRY+0xc7>
// 6b: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 70: 29 c1                         subl    %eax, %ecx
// 72: 48 63 c9                      movslq  %ecx, %rcx
// 75: 4d 8b 64 ce 08                movq    0x8(%r14,%rcx,8), %r12
// 7a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007c:  R_X86_64_64  PyCFunction_Type
// 84: 49 39 44 24 08                cmpq    %rax, 0x8(%r12)
// 89: 75 3c                         jne     0xc7 <_JIT_ENTRY+0xc7>
// 8b: 49 8b 44 24 10                movq    0x10(%r12), %rax
// 90: 83 78 10 08                   cmpl    $0x8, 0x10(%rax)
// 94: 75 31                         jne     0xc7 <_JIT_ENTRY+0xc7>
// 96: 48 89 4c 24 10                movq    %rcx, 0x10(%rsp)
// 9b: 4c 8b 40 08                   movq    0x8(%rax), %r8
// 9f: 8b 4a 2c                      movl    0x2c(%rdx), %ecx
// a2: 8d 71 ff                      leal    -0x1(%rcx), %esi
// a5: 89 72 2c                      movl    %esi, 0x2c(%rdx)
// a8: 85 c9                         testl   %ecx, %ecx
// aa: 7e 52                         jle     0xfe <_JIT_ENTRY+0xfe>
// ac: 4d 8b 3c ee                   movq    (%r14,%rbp,8), %r15
// b0: f6 40 10 20                   testb   $0x20, 0x10(%rax)
// b4: 48 89 d5                      movq    %rdx, %rbp
// b7: 0f 85 8a 00 00 00             jne     0x147 <_JIT_ENTRY+0x147>
// bd: 49 8b 7c 24 18                movq    0x18(%r12), %rdi
// c2: e9 82 00 00 00                jmp     0x149 <_JIT_ENTRY+0x149>
// c7: 49 29 df                      subq    %rbx, %r15
// ca: 49 83 c7 b8                   addq    $-0x48, %r15
// ce: 49 c1 ef 03                   shrq    $0x3, %r15
// d2: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// d6: 48 8b 03                      movq    (%rbx), %rax
// d9: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000db:  R_X86_64_64  _JIT_TARGET
// e3: 89 c9                         movl    %ecx, %ecx
// e5: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// e9: 48 05 c8 00 00 00             addq    $0xc8, %rax
// ef: 48 83 c4 18                   addq    $0x18, %rsp
// f3: 5b                            popq    %rbx
// f4: 41 5c                         popq    %r12
// f6: 41 5d                         popq    %r13
// f8: 41 5e                         popq    %r14
// fa: 41 5f                         popq    %r15
// fc: 5d                            popq    %rbp
// fd: c3                            retq
// fe: 4c 89 04 24                   movq    %r8, (%rsp)
// 102: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000104:  R_X86_64_64  .rodata.str1.1+0x39
// 10c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010e:  R_X86_64_64  _Py_CheckRecursiveCall
// 116: 48 89 d7                      movq    %rdx, %rdi
// 119: 48 89 54 24 08                movq    %rdx, 0x8(%rsp)
// 11e: ff d0                         callq   *%rax
// 120: 85 c0                         testl   %eax, %eax
// 122: 0f 85 25 01 00 00             jne     0x24d <_JIT_ENTRY+0x24d>
// 128: 49 8b 44 24 10                movq    0x10(%r12), %rax
// 12d: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 132: 4c 8b 04 24                   movq    (%rsp), %r8
// 136: 4d 8b 3c ee                   movq    (%r14,%rbp,8), %r15
// 13a: f6 40 10 20                   testb   $0x20, 0x10(%rax)
// 13e: 48 89 d5                      movq    %rdx, %rbp
// 141: 0f 84 76 ff ff ff             je      0xbd <_JIT_ENTRY+0xbd>
// 147: 31 ff                         xorl    %edi, %edi
// 149: 4c 89 fe                      movq    %r15, %rsi
// 14c: 41 ff d0                      callq   *%r8
// 14f: 48 89 ea                      movq    %rbp, %rdx
// 152: ff 45 2c                      incl    0x2c(%rbp)
// 155: 48 89 04 24                   movq    %rax, (%rsp)
// 159: 49 8b 07                      movq    (%r15), %rax
// 15c: 48 85 c0                      testq   %rax, %rax
// 15f: 7f 24                         jg      0x185 <_JIT_ENTRY+0x185>
// 161: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000163:  R_X86_64_64  .rodata.str1.1
// 16b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000016d:  R_X86_64_64  _Py_NegativeRefcount
// 175: be 02 0b 00 00                movl    $0xb02, %esi            # imm = 0xB02
// 17a: 4c 89 fa                      movq    %r15, %rdx
// 17d: ff d0                         callq   *%rax
// 17f: 48 89 ea                      movq    %rbp, %rdx
// 182: 49 8b 07                      movq    (%r15), %rax
// 185: 85 c0                         testl   %eax, %eax
// 187: 78 26                         js      0x1af <_JIT_ENTRY+0x1af>
// 189: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000018b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 193: ff d0                         callq   *%rax
// 195: 48 89 ea                      movq    %rbp, %rdx
// 198: 49 ff 0f                      decq    (%r15)
// 19b: 75 12                         jne     0x1af <_JIT_ENTRY+0x1af>
// 19d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000019f:  R_X86_64_64  _Py_Dealloc
// 1a7: 4c 89 ff                      movq    %r15, %rdi
// 1aa: ff d0                         callq   *%rax
// 1ac: 48 89 ea                      movq    %rbp, %rdx
// 1af: 49 8b 04 24                   movq    (%r12), %rax
// 1b3: 48 85 c0                      testq   %rax, %rax
// 1b6: 7f 25                         jg      0x1dd <_JIT_ENTRY+0x1dd>
// 1b8: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000001ba:  R_X86_64_64  .rodata.str1.1
// 1c2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c4:  R_X86_64_64  _Py_NegativeRefcount
// 1cc: be 03 0b 00 00                movl    $0xb03, %esi            # imm = 0xB03
// 1d1: 4c 89 e2                      movq    %r12, %rdx
// 1d4: ff d0                         callq   *%rax
// 1d6: 48 89 ea                      movq    %rbp, %rdx
// 1d9: 49 8b 04 24                   movq    (%r12), %rax
// 1dd: 85 c0                         testl   %eax, %eax
// 1df: 78 27                         js      0x208 <_JIT_ENTRY+0x208>
// 1e1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001e3:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 1eb: ff d0                         callq   *%rax
// 1ed: 48 89 ea                      movq    %rbp, %rdx
// 1f0: 49 ff 0c 24                   decq    (%r12)
// 1f4: 75 12                         jne     0x208 <_JIT_ENTRY+0x208>
// 1f6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001f8:  R_X86_64_64  _Py_Dealloc
// 200: 4c 89 e7                      movq    %r12, %rdi
// 203: ff d0                         callq   *%rax
// 205: 48 89 ea                      movq    %rbp, %rdx
// 208: 48 8b 44 24 10                movq    0x10(%rsp), %rax
// 20d: 4d 8d 3c c6                   leaq    (%r14,%rax,8), %r15
// 211: 49 83 c7 08                   addq    $0x8, %r15
// 215: 48 8b 04 24                   movq    (%rsp), %rax
// 219: 48 85 c0                      testq   %rax, %rax
// 21c: 74 2f                         je      0x24d <_JIT_ENTRY+0x24d>
// 21e: 4f 8d 34 ee                   leaq    (%r14,%r13,8), %r14
// 222: 49 83 c6 08                   addq    $0x8, %r14
// 226: 49 89 07                      movq    %rax, (%r15)
// 229: 48 8b 42 10                   movq    0x10(%rdx), %rax
// 22d: 48 8b 00                      movq    (%rax), %rax
// 230: 84 c0                         testb   %al, %al
// 232: 74 2f                         je      0x263 <_JIT_ENTRY+0x263>
// 234: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000236:  R_X86_64_64  _Py_HandlePending
// 23e: 48 89 d7                      movq    %rdx, %rdi
// 241: ff d0                         callq   *%rax
// 243: 48 89 ea                      movq    %rbp, %rdx
// 246: 85 c0                         testl   %eax, %eax
// 248: 74 19                         je      0x263 <_JIT_ENTRY+0x263>
// 24a: 4d 89 f7                      movq    %r14, %r15
// 24d: 49 29 df                      subq    %rbx, %r15
// 250: 49 83 c7 b8                   addq    $-0x48, %r15
// 254: 49 c1 ef 03                   shrq    $0x3, %r15
// 258: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 25c: 31 c0                         xorl    %eax, %eax
// 25e: e9 8c fe ff ff                jmp     0xef <_JIT_ENTRY+0xef>
// 263: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000265:  R_X86_64_64  _JIT_CONTINUE
// 26d: 48 89 df                      movq    %rbx, %rdi
// 270: 4c 89 f6                      movq    %r14, %rsi
// 273: 48 83 c4 18                   addq    $0x18, %rsp
// 277: 5b                            popq    %rbx
// 278: 41 5c                         popq    %r12
// 27a: 41 5d                         popq    %r13
// 27c: 41 5e                         popq    %r14
// 27e: 41 5f                         popq    %r15
// 280: 5d                            popq    %rbp
// 281: ff e0                         jmpq    *%rax
// 283: 
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_O_code_body[644] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc1, 0x89, 0xc6, 0xf7, 0xd6, 0x4c, 0x63, 0xee, 0x0f, 0xb7, 0xc9, 0x41, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x49, 0x29, 0xc8, 0x48, 0x89, 0xcd, 0x48, 0xf7, 0xdd, 0x31, 0xf6, 0x66, 0x85, 0xc9, 0x40, 0x0f, 0x94, 0xc6, 0x31, 0xff, 0x66, 0x83, 0xf9, 0x01, 0x40, 0x0f, 0x94, 0xc7, 0x4b, 0x83, 0x7c, 0xee, 0x08, 0x00, 0x49, 0x0f, 0x44, 0xe8, 0x4d, 0x8d, 0x7e, 0x08, 0x0f, 0x44, 0xf7, 0x40, 0x80, 0xfe, 0x01, 0x75, 0x5c, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc9, 0x4d, 0x8b, 0x64, 0xce, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x44, 0x24, 0x08, 0x75, 0x3c, 0x49, 0x8b, 0x44, 0x24, 0x10, 0x83, 0x78, 0x10, 0x08, 0x75, 0x31, 0x48, 0x89, 0x4c, 0x24, 0x10, 0x4c, 0x8b, 0x40, 0x08, 0x8b, 0x4a, 0x2c, 0x8d, 0x71, 0xff, 0x89, 0x72, 0x2c, 0x85, 0xc9, 0x7e, 0x52, 0x4d, 0x8b, 0x3c, 0xee, 0xf6, 0x40, 0x10, 0x20, 0x48, 0x89, 0xd5, 0x0f, 0x85, 0x8a, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x7c, 0x24, 0x18, 0xe9, 0x82, 0x00, 0x00, 0x00, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x4c, 0x89, 0x04, 0x24, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0x54, 0x24, 0x08, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x85, 0x25, 0x01, 0x00, 0x00, 0x49, 0x8b, 0x44, 0x24, 0x10, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x4c, 0x8b, 0x04, 0x24, 0x4d, 0x8b, 0x3c, 0xee, 0xf6, 0x40, 0x10, 0x20, 0x48, 0x89, 0xd5, 0x0f, 0x84, 0x76, 0xff, 0xff, 0xff, 0x31, 0xff, 0x4c, 0x89, 0xfe, 0x41, 0xff, 0xd0, 0x48, 0x89, 0xea, 0xff, 0x45, 0x2c, 0x48, 0x89, 0x04, 0x24, 0x49, 0x8b, 0x07, 0x48, 0x85, 0xc0, 0x7f, 0x24, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x02, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xfa, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x49, 0x8b, 0x07, 0x85, 0xc0, 0x78, 0x26, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x49, 0xff, 0x0f, 0x75, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x25, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x03, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x27, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x48, 0x8b, 0x44, 0x24, 0x10, 0x4d, 0x8d, 0x3c, 0xc6, 0x49, 0x83, 0xc7, 0x08, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x2f, 0x4f, 0x8d, 0x34, 0xee, 0x49, 0x83, 0xc6, 0x08, 0x49, 0x89, 0x07, 0x48, 0x8b, 0x42, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x2f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0xff, 0xd0, 0x48, 0x89, 0xea, 0x85, 0xc0, 0x74, 0x19, 0x4d, 0x89, 0xf7, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x31, 0xc0, 0xe9, 0x8c, 0xfe, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_O_code_holes[16] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x7c, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyCFunction_Type, 0x0},
    {0xdb, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x104, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x10e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_CheckRecursiveCall, 0x0},
    {0x163, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x16d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x18b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x19f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1ba, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x1c4, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x1e3, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x1f8, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x236, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x265, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00 while calling a Python object\x00'
// 58: 
static const unsigned char _PUSH_NULLplus_CALL_BUILTIN_O_data_body[89] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x20, 0x77, 0x68, 0x69, 0x6c, 0x65, 0x20, 0x63, 0x61, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x20, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00};
static const Hole _PUSH_NULLplus_CALL_BUILTIN_O_data_holes[1];

// _PUSH_NULLplus_CALL_INTRINSIC_1
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_INTRINSIC_1.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 89 d7                      movq    %rdx, %rdi
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_OPARG
// 15: 0f b7 c0                      movzwl  %ax, %eax
// 18: 48 c1 e0 04                   shlq    $0x4, %rax
// 1c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001e:  R_X86_64_64  _PyIntrinsics_UnaryFunctions
// 26: 31 f6                         xorl    %esi, %esi
// 28: ff 14 08                      callq   *(%rax,%rcx)
// 2b: 
static const unsigned char _PUSH_NULLplus_CALL_INTRINSIC_1_code_body[44] = {0x50, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x04, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0x14, 0x08};
static const Hole _PUSH_NULLplus_CALL_INTRINSIC_1_code_holes[3] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyIntrinsics_UnaryFunctions, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CALL_INTRINSIC_1_data_body[1];
static const Hole _PUSH_NULLplus_CALL_INTRINSIC_1_data_holes[1];

// _PUSH_NULLplus_CALL_INTRINSIC_2
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_INTRINSIC_2.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 89 d7                      movq    %rdx, %rdi
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  _JIT_OPARG
// 19: 0f b7 c0                      movzwl  %ax, %eax
// 1c: 48 c1 e0 04                   shlq    $0x4, %rax
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  _PyIntrinsics_BinaryFunctions
// 2a: 48 89 de                      movq    %rbx, %rsi
// 2d: 31 d2                         xorl    %edx, %edx
// 2f: ff 14 08                      callq   *(%rax,%rcx)
// 32: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 36: 7f 1e                         jg      0x56 <_JIT_ENTRY+0x56>
// 38: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000003a:  R_X86_64_64  .rodata.str1.1
// 42: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000044:  R_X86_64_64  _Py_NegativeRefcount
// 4c: be 8d 02 00 00                movl    $0x28d, %esi            # imm = 0x28D
// 51: 48 89 da                      movq    %rbx, %rdx
// 54: ff d0                         callq   *%rax
// 56: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000058:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 60: ff d0                         callq   *%rax
// 62: 48 ff 0b                      decq    (%rbx)
// 65: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000067:  R_X86_64_64  _Py_Dealloc
// 6f: 48 89 df                      movq    %rbx, %rdi
// 72: ff d0                         callq   *%rax
// 74: 
static const unsigned char _PUSH_NULLplus_CALL_INTRINSIC_2_code_body[117] = {0x53, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x04, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xde, 0x31, 0xd2, 0xff, 0x14, 0x08, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x8d, 0x02, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_CALL_INTRINSIC_2_code_holes[7] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyIntrinsics_BinaryFunctions, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x44, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x58, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x67, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_INTRINSIC_2_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_INTRINSIC_2_data_holes[1];

// _PUSH_NULLplus_CALL_ISINSTANCE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_ISINSTANCE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 c1                      movzwl  %cx, %eax
// 28: 89 c6                         movl    %eax, %esi
// 2a: f7 d6                         notl    %esi
// 2c: 48 63 ee                      movslq  %esi, %rbp
// 2f: 44 0f b7 c9                   movzwl  %cx, %r9d
// 33: be 01 00 00 00                movl    $0x1, %esi
// 38: 4c 29 ce                      subq    %r9, %rsi
// 3b: 4c 89 c9                      movq    %r9, %rcx
// 3e: 48 f7 d9                      negq    %rcx
// 41: 31 ff                         xorl    %edi, %edi
// 43: 66 41 83 f9 01                cmpw    $0x1, %r9w
// 48: 40 0f 94 c7                   sete    %dil
// 4c: 45 31 c0                      xorl    %r8d, %r8d
// 4f: 66 41 83 f9 02                cmpw    $0x2, %r9w
// 54: 41 0f 94 c0                   sete    %r8b
// 58: 49 83 7c ef 08 00             cmpq    $0x0, 0x8(%r15,%rbp,8)
// 5e: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 62: 4d 8d 77 08                   leaq    0x8(%r15), %r14
// 66: 41 0f 44 f8                   cmovel  %r8d, %edi
// 6a: 40 80 ff 01                   cmpb    $0x1, %dil
// 6e: 75 1c                         jne     0x8c <_JIT_ENTRY+0x8c>
// 70: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 75: 29 c6                         subl    %eax, %esi
// 77: 48 63 f6                      movslq  %esi, %rsi
// 7a: 4d 8b 64 f7 08                movq    0x8(%r15,%rsi,8), %r12
// 7f: 48 8b 42 10                   movq    0x10(%rdx), %rax
// 83: 4c 3b a0 b8 54 06 00          cmpq    0x654b8(%rax), %r12
// 8a: 74 37                         je      0xc3 <_JIT_ENTRY+0xc3>
// 8c: 49 29 de                      subq    %rbx, %r14
// 8f: 49 83 c6 b8                   addq    $-0x48, %r14
// 93: 49 c1 ee 03                   shrq    $0x3, %r14
// 97: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 9b: 48 8b 03                      movq    (%rbx), %rax
// 9e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000a0:  R_X86_64_64  _JIT_TARGET
// a8: 89 c9                         movl    %ecx, %ecx
// aa: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// ae: 48 05 c8 00 00 00             addq    $0xc8, %rax
// b4: 48 83 c4 28                   addq    $0x28, %rsp
// b8: 5b                            popq    %rbx
// b9: 41 5c                         popq    %r12
// bb: 41 5d                         popq    %r13
// bd: 41 5e                         popq    %r14
// bf: 41 5f                         popq    %r15
// c1: 5d                            popq    %rbp
// c2: c3                            retq
// c3: 48 89 74 24 20                movq    %rsi, 0x20(%rsp)
// c8: 48 89 54 24 10                movq    %rdx, 0x10(%rsp)
// cd: 4d 8b 2c cf                   movq    (%r15,%rcx,8), %r13
// d1: 49 8b 74 cf 08                movq    0x8(%r15,%rcx,8), %rsi
// d6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d8:  R_X86_64_64  PyObject_IsInstance
// e0: 4c 89 ef                      movq    %r13, %rdi
// e3: 48 89 74 24 18                movq    %rsi, 0x18(%rsp)
// e8: ff d0                         callq   *%rax
// ea: 85 c0                         testl   %eax, %eax
// ec: 0f 88 49 01 00 00             js      0x23b <_JIT_ENTRY+0x23b>
// f2: 89 c7                         movl    %eax, %edi
// f4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f6:  R_X86_64_64  PyBool_FromLong
// fe: ff d0                         callq   *%rax
// 100: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// 105: 49 8b 45 00                   movq    (%r13), %rax
// 109: 48 85 c0                      testq   %rax, %rax
// 10c: 7f 22                         jg      0x130 <_JIT_ENTRY+0x130>
// 10e: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000110:  R_X86_64_64  .rodata.str1.1
// 118: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011a:  R_X86_64_64  _Py_NegativeRefcount
// 122: be 96 0b 00 00                movl    $0xb96, %esi            # imm = 0xB96
// 127: 4c 89 ea                      movq    %r13, %rdx
// 12a: ff d0                         callq   *%rax
// 12c: 49 8b 45 00                   movq    (%r13), %rax
// 130: 85 c0                         testl   %eax, %eax
// 132: 4c 8b 74 24 18                movq    0x18(%rsp), %r14
// 137: 78 21                         js      0x15a <_JIT_ENTRY+0x15a>
// 139: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 143: ff d0                         callq   *%rax
// 145: 49 ff 4d 00                   decq    (%r13)
// 149: 75 0f                         jne     0x15a <_JIT_ENTRY+0x15a>
// 14b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014d:  R_X86_64_64  _Py_Dealloc
// 155: 4c 89 ef                      movq    %r13, %rdi
// 158: ff d0                         callq   *%rax
// 15a: 49 8b 06                      movq    (%r14), %rax
// 15d: 48 85 c0                      testq   %rax, %rax
// 160: 7f 21                         jg      0x183 <_JIT_ENTRY+0x183>
// 162: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000164:  R_X86_64_64  .rodata.str1.1
// 16c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000016e:  R_X86_64_64  _Py_NegativeRefcount
// 176: be 97 0b 00 00                movl    $0xb97, %esi            # imm = 0xB97
// 17b: 4c 89 f2                      movq    %r14, %rdx
// 17e: ff d0                         callq   *%rax
// 180: 49 8b 06                      movq    (%r14), %rax
// 183: 85 c0                         testl   %eax, %eax
// 185: 78 20                         js      0x1a7 <_JIT_ENTRY+0x1a7>
// 187: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000189:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 191: ff d0                         callq   *%rax
// 193: 49 ff 0e                      decq    (%r14)
// 196: 75 0f                         jne     0x1a7 <_JIT_ENTRY+0x1a7>
// 198: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000019a:  R_X86_64_64  _Py_Dealloc
// 1a2: 4c 89 f7                      movq    %r14, %rdi
// 1a5: ff d0                         callq   *%rax
// 1a7: 49 8b 04 24                   movq    (%r12), %rax
// 1ab: 48 85 c0                      testq   %rax, %rax
// 1ae: 7f 22                         jg      0x1d2 <_JIT_ENTRY+0x1d2>
// 1b0: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000001b2:  R_X86_64_64  .rodata.str1.1
// 1ba: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001bc:  R_X86_64_64  _Py_NegativeRefcount
// 1c4: be 98 0b 00 00                movl    $0xb98, %esi            # imm = 0xB98
// 1c9: 4c 89 e2                      movq    %r12, %rdx
// 1cc: ff d0                         callq   *%rax
// 1ce: 49 8b 04 24                   movq    (%r12), %rax
// 1d2: 85 c0                         testl   %eax, %eax
// 1d4: 78 21                         js      0x1f7 <_JIT_ENTRY+0x1f7>
// 1d6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001d8:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 1e0: ff d0                         callq   *%rax
// 1e2: 49 ff 0c 24                   decq    (%r12)
// 1e6: 75 0f                         jne     0x1f7 <_JIT_ENTRY+0x1f7>
// 1e8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001ea:  R_X86_64_64  _Py_Dealloc
// 1f2: 4c 89 e7                      movq    %r12, %rdi
// 1f5: ff d0                         callq   *%rax
// 1f7: 48 8b 44 24 20                movq    0x20(%rsp), %rax
// 1fc: 4d 8d 34 c7                   leaq    (%r15,%rax,8), %r14
// 200: 49 83 c6 08                   addq    $0x8, %r14
// 204: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 209: 48 85 c0                      testq   %rax, %rax
// 20c: 74 2d                         je      0x23b <_JIT_ENTRY+0x23b>
// 20e: 49 8d 34 ef                   leaq    (%r15,%rbp,8), %rsi
// 212: 48 83 c6 08                   addq    $0x8, %rsi
// 216: 49 89 06                      movq    %rax, (%r14)
// 219: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000021b:  R_X86_64_64  _JIT_CONTINUE
// 223: 48 89 df                      movq    %rbx, %rdi
// 226: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// 22b: 48 83 c4 28                   addq    $0x28, %rsp
// 22f: 5b                            popq    %rbx
// 230: 41 5c                         popq    %r12
// 232: 41 5d                         popq    %r13
// 234: 41 5e                         popq    %r14
// 236: 41 5f                         popq    %r15
// 238: 5d                            popq    %rbp
// 239: ff e0                         jmpq    *%rax
// 23b: 49 29 de                      subq    %rbx, %r14
// 23e: 49 83 c6 b8                   addq    $-0x48, %r14
// 242: 49 c1 ee 03                   shrq    $0x3, %r14
// 246: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 24a: 31 c0                         xorl    %eax, %eax
// 24c: e9 63 fe ff ff                jmp     0xb4 <_JIT_ENTRY+0xb4>
// 251: 
static const unsigned char _PUSH_NULLplus_CALL_ISINSTANCE_code_body[594] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc1, 0x89, 0xc6, 0xf7, 0xd6, 0x48, 0x63, 0xee, 0x44, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x4c, 0x29, 0xce, 0x4c, 0x89, 0xc9, 0x48, 0xf7, 0xd9, 0x31, 0xff, 0x66, 0x41, 0x83, 0xf9, 0x01, 0x40, 0x0f, 0x94, 0xc7, 0x45, 0x31, 0xc0, 0x66, 0x41, 0x83, 0xf9, 0x02, 0x41, 0x0f, 0x94, 0xc0, 0x49, 0x83, 0x7c, 0xef, 0x08, 0x00, 0x48, 0x0f, 0x44, 0xce, 0x4d, 0x8d, 0x77, 0x08, 0x41, 0x0f, 0x44, 0xf8, 0x40, 0x80, 0xff, 0x01, 0x75, 0x1c, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc6, 0x48, 0x63, 0xf6, 0x4d, 0x8b, 0x64, 0xf7, 0x08, 0x48, 0x8b, 0x42, 0x10, 0x4c, 0x3b, 0xa0, 0xb8, 0x54, 0x06, 0x00, 0x74, 0x37, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xb8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0x89, 0x74, 0x24, 0x20, 0x48, 0x89, 0x54, 0x24, 0x10, 0x4d, 0x8b, 0x2c, 0xcf, 0x49, 0x8b, 0x74, 0xcf, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0x48, 0x89, 0x74, 0x24, 0x18, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x88, 0x49, 0x01, 0x00, 0x00, 0x89, 0xc7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x89, 0x44, 0x24, 0x08, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x96, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x4c, 0x8b, 0x74, 0x24, 0x18, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7f, 0x21, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x97, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x85, 0xc0, 0x78, 0x20, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0e, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x98, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x4d, 0x8d, 0x34, 0xc7, 0x49, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x74, 0x2d, 0x49, 0x8d, 0x34, 0xef, 0x48, 0x83, 0xc6, 0x08, 0x49, 0x89, 0x06, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xb8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x31, 0xc0, 0xe9, 0x63, 0xfe, 0xff, 0xff};
static const Hole _PUSH_NULLplus_CALL_ISINSTANCE_code_holes[18] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xa0, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0xd8, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_IsInstance, 0x0},
    {0xf6, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyBool_FromLong, 0x0},
    {0x110, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x11a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x13b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x14d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x164, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x16e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x189, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x19a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1b2, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x1bc, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x1d8, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x1ea, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x21b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_ISINSTANCE_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_ISINSTANCE_data_holes[1];

// _PUSH_NULLplus_CALL_LEN
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_LEN.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 c1                      movzwl  %cx, %eax
// 28: 89 c6                         movl    %eax, %esi
// 2a: f7 d6                         notl    %esi
// 2c: 4c 63 ee                      movslq  %esi, %r13
// 2f: 44 0f b7 c9                   movzwl  %cx, %r9d
// 33: be 01 00 00 00                movl    $0x1, %esi
// 38: 4c 29 ce                      subq    %r9, %rsi
// 3b: 4c 89 c9                      movq    %r9, %rcx
// 3e: 48 f7 d9                      negq    %rcx
// 41: 31 ff                         xorl    %edi, %edi
// 43: 66 45 85 c9                   testw   %r9w, %r9w
// 47: 40 0f 94 c7                   sete    %dil
// 4b: 45 31 c0                      xorl    %r8d, %r8d
// 4e: 66 41 83 f9 01                cmpw    $0x1, %r9w
// 53: 41 0f 94 c0                   sete    %r8b
// 57: 4b 83 7c ef 08 00             cmpq    $0x0, 0x8(%r15,%r13,8)
// 5d: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 61: 4d 8d 77 08                   leaq    0x8(%r15), %r14
// 65: 41 0f 44 f8                   cmovel  %r8d, %edi
// 69: 40 80 ff 01                   cmpb    $0x1, %dil
// 6d: 75 1c                         jne     0x8b <_JIT_ENTRY+0x8b>
// 6f: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 74: 29 c6                         subl    %eax, %esi
// 76: 4c 63 e6                      movslq  %esi, %r12
// 79: 4b 8b 6c e7 08                movq    0x8(%r15,%r12,8), %rbp
// 7e: 48 8b 42 10                   movq    0x10(%rdx), %rax
// 82: 48 3b a8 c0 54 06 00          cmpq    0x654c0(%rax), %rbp
// 89: 74 37                         je      0xc2 <_JIT_ENTRY+0xc2>
// 8b: 49 29 de                      subq    %rbx, %r14
// 8e: 49 83 c6 b8                   addq    $-0x48, %r14
// 92: 49 c1 ee 03                   shrq    $0x3, %r14
// 96: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 9a: 48 8b 03                      movq    (%rbx), %rax
// 9d: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000009f:  R_X86_64_64  _JIT_TARGET
// a7: 89 c9                         movl    %ecx, %ecx
// a9: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// ad: 48 05 c8 00 00 00             addq    $0xc8, %rax
// b3: 48 83 c4 18                   addq    $0x18, %rsp
// b7: 5b                            popq    %rbx
// b8: 41 5c                         popq    %r12
// ba: 41 5d                         popq    %r13
// bc: 41 5e                         popq    %r14
// be: 41 5f                         popq    %r15
// c0: 5d                            popq    %rbp
// c1: c3                            retq
// c2: 48 89 54 24 08                movq    %rdx, 0x8(%rsp)
// c7: 49 8b 3c cf                   movq    (%r15,%rcx,8), %rdi
// cb: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000cd:  R_X86_64_64  PyObject_Size
// d5: 48 89 7c 24 10                movq    %rdi, 0x10(%rsp)
// da: ff d0                         callq   *%rax
// dc: 48 85 c0                      testq   %rax, %rax
// df: 0f 88 ee 00 00 00             js      0x1d3 <_JIT_ENTRY+0x1d3>
// e5: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000e7:  R_X86_64_64  PyLong_FromSsize_t
// ef: 48 89 c7                      movq    %rax, %rdi
// f2: ff d1                         callq   *%rcx
// f4: 48 89 04 24                   movq    %rax, (%rsp)
// f8: 48 8b 45 00                   movq    (%rbp), %rax
// fc: 48 85 c0                      testq   %rax, %rax
// ff: 7f 22                         jg      0x123 <_JIT_ENTRY+0x123>
// 101: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000103:  R_X86_64_64  .rodata.str1.1
// 10b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010d:  R_X86_64_64  _Py_NegativeRefcount
// 115: be 73 0b 00 00                movl    $0xb73, %esi            # imm = 0xB73
// 11a: 48 89 ea                      movq    %rbp, %rdx
// 11d: ff d0                         callq   *%rax
// 11f: 48 8b 45 00                   movq    (%rbp), %rax
// 123: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 0000000000000125:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 12d: 85 c0                         testl   %eax, %eax
// 12f: 78 18                         js      0x149 <_JIT_ENTRY+0x149>
// 131: 41 ff d6                      callq   *%r14
// 134: 48 ff 4d 00                   decq    (%rbp)
// 138: 75 0f                         jne     0x149 <_JIT_ENTRY+0x149>
// 13a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013c:  R_X86_64_64  _Py_Dealloc
// 144: 48 89 ef                      movq    %rbp, %rdi
// 147: ff d0                         callq   *%rax
// 149: 48 8b 6c 24 10                movq    0x10(%rsp), %rbp
// 14e: 48 8b 45 00                   movq    (%rbp), %rax
// 152: 48 85 c0                      testq   %rax, %rax
// 155: 7f 22                         jg      0x179 <_JIT_ENTRY+0x179>
// 157: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000159:  R_X86_64_64  .rodata.str1.1
// 161: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000163:  R_X86_64_64  _Py_NegativeRefcount
// 16b: be 74 0b 00 00                movl    $0xb74, %esi            # imm = 0xB74
// 170: 48 89 ea                      movq    %rbp, %rdx
// 173: ff d0                         callq   *%rax
// 175: 48 8b 45 00                   movq    (%rbp), %rax
// 179: 85 c0                         testl   %eax, %eax
// 17b: 78 18                         js      0x195 <_JIT_ENTRY+0x195>
// 17d: 41 ff d6                      callq   *%r14
// 180: 48 ff 4d 00                   decq    (%rbp)
// 184: 75 0f                         jne     0x195 <_JIT_ENTRY+0x195>
// 186: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000188:  R_X86_64_64  _Py_Dealloc
// 190: 48 89 ef                      movq    %rbp, %rdi
// 193: ff d0                         callq   *%rax
// 195: 4f 8d 34 e7                   leaq    (%r15,%r12,8), %r14
// 199: 49 83 c6 08                   addq    $0x8, %r14
// 19d: 48 8b 04 24                   movq    (%rsp), %rax
// 1a1: 48 85 c0                      testq   %rax, %rax
// 1a4: 74 2d                         je      0x1d3 <_JIT_ENTRY+0x1d3>
// 1a6: 4b 8d 34 ef                   leaq    (%r15,%r13,8), %rsi
// 1aa: 48 83 c6 08                   addq    $0x8, %rsi
// 1ae: 49 89 06                      movq    %rax, (%r14)
// 1b1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001b3:  R_X86_64_64  _JIT_CONTINUE
// 1bb: 48 89 df                      movq    %rbx, %rdi
// 1be: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 1c3: 48 83 c4 18                   addq    $0x18, %rsp
// 1c7: 5b                            popq    %rbx
// 1c8: 41 5c                         popq    %r12
// 1ca: 41 5d                         popq    %r13
// 1cc: 41 5e                         popq    %r14
// 1ce: 41 5f                         popq    %r15
// 1d0: 5d                            popq    %rbp
// 1d1: ff e0                         jmpq    *%rax
// 1d3: 49 29 de                      subq    %rbx, %r14
// 1d6: 49 83 c6 b8                   addq    $-0x48, %r14
// 1da: 49 c1 ee 03                   shrq    $0x3, %r14
// 1de: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 1e2: 31 c0                         xorl    %eax, %eax
// 1e4: e9 ca fe ff ff                jmp     0xb3 <_JIT_ENTRY+0xb3>
// 1e9: 
static const unsigned char _PUSH_NULLplus_CALL_LEN_code_body[490] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc1, 0x89, 0xc6, 0xf7, 0xd6, 0x4c, 0x63, 0xee, 0x44, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x4c, 0x29, 0xce, 0x4c, 0x89, 0xc9, 0x48, 0xf7, 0xd9, 0x31, 0xff, 0x66, 0x45, 0x85, 0xc9, 0x40, 0x0f, 0x94, 0xc7, 0x45, 0x31, 0xc0, 0x66, 0x41, 0x83, 0xf9, 0x01, 0x41, 0x0f, 0x94, 0xc0, 0x4b, 0x83, 0x7c, 0xef, 0x08, 0x00, 0x48, 0x0f, 0x44, 0xce, 0x4d, 0x8d, 0x77, 0x08, 0x41, 0x0f, 0x44, 0xf8, 0x40, 0x80, 0xff, 0x01, 0x75, 0x1c, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc6, 0x4c, 0x63, 0xe6, 0x4b, 0x8b, 0x6c, 0xe7, 0x08, 0x48, 0x8b, 0x42, 0x10, 0x48, 0x3b, 0xa8, 0xc0, 0x54, 0x06, 0x00, 0x74, 0x37, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xb8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0x89, 0x54, 0x24, 0x08, 0x49, 0x8b, 0x3c, 0xcf, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x7c, 0x24, 0x10, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x0f, 0x88, 0xee, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xc7, 0xff, 0xd1, 0x48, 0x89, 0x04, 0x24, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x73, 0x0b, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x18, 0x41, 0xff, 0xd6, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x48, 0x8b, 0x6c, 0x24, 0x10, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x74, 0x0b, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x18, 0x41, 0xff, 0xd6, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x4f, 0x8d, 0x34, 0xe7, 0x49, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x2d, 0x4b, 0x8d, 0x34, 0xef, 0x48, 0x83, 0xc6, 0x08, 0x49, 0x89, 0x06, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xb8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x31, 0xc0, 0xe9, 0xca, 0xfe, 0xff, 0xff};
static const Hole _PUSH_NULLplus_CALL_LEN_code_holes[13] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x9f, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0xcd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Size, 0x0},
    {0xe7, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_FromSsize_t, 0x0},
    {0x103, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x10d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x125, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x13c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x159, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x163, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x188, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1b3, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_LEN_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_LEN_data_holes[1];

// _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 f9                      movzwl  %cx, %edi
// 28: 89 f8                         movl    %edi, %eax
// 2a: f7 d0                         notl    %eax
// 2c: 4c 63 c8                      movslq  %eax, %r9
// 2f: 4a 8b 44 ce 08                movq    0x8(%rsi,%r9,8), %rax
// 34: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 39: 29 fe                         subl    %edi, %esi
// 3b: 4c 63 d6                      movslq  %esi, %r10
// 3e: 0f b7 c9                      movzwl  %cx, %ecx
// 41: be 01 00 00 00                movl    $0x1, %esi
// 46: 48 29 ce                      subq    %rcx, %rsi
// 49: 48 f7 d9                      negq    %rcx
// 4c: 44 8d 6f 01                   leal    0x1(%rdi), %r13d
// 50: 48 85 c0                      testq   %rax, %rax
// 53: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 57: 44 0f 44 ef                   cmovel  %edi, %r13d
// 5b: 4f 8b 64 d7 08                movq    0x8(%r15,%r10,8), %r12
// 60: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000062:  R_X86_64_64  PyMethodDescr_Type
// 6a: 49 39 74 24 08                cmpq    %rsi, 0x8(%r12)
// 6f: 75 21                         jne     0x92 <_JIT_ENTRY+0x92>
// 71: 4d 8b 44 24 28                movq    0x28(%r12), %r8
// 76: 41 81 78 10 80 00 00 00       cmpl    $0x80, 0x10(%r8)
// 7e: 75 12                         jne     0x92 <_JIT_ENTRY+0x92>
// 80: 49 8d 34 cf                   leaq    (%r15,%rcx,8), %rsi
// 84: 48 8b 3e                      movq    (%rsi), %rdi
// 87: 48 8b 4f 08                   movq    0x8(%rdi), %rcx
// 8b: 49 3b 4c 24 10                cmpq    0x10(%r12), %rcx
// 90: 74 3b                         je      0xcd <_JIT_ENTRY+0xcd>
// 92: 49 83 c7 08                   addq    $0x8, %r15
// 96: 49 29 df                      subq    %rbx, %r15
// 99: 49 83 c7 b8                   addq    $-0x48, %r15
// 9d: 49 c1 ef 03                   shrq    $0x3, %r15
// a1: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// a5: 48 8b 03                      movq    (%rbx), %rax
// a8: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000aa:  R_X86_64_64  _JIT_TARGET
// b2: 89 c9                         movl    %ecx, %ecx
// b4: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// b8: 48 05 c8 00 00 00             addq    $0xc8, %rax
// be: 48 83 c4 28                   addq    $0x28, %rsp
// c2: 5b                            popq    %rbx
// c3: 41 5c                         popq    %r12
// c5: 41 5d                         popq    %r13
// c7: 41 5e                         popq    %r14
// c9: 41 5f                         popq    %r15
// cb: 5d                            popq    %rbp
// cc: c3                            retq
// cd: 4c 89 54 24 10                movq    %r10, 0x10(%rsp)
// d2: 4c 89 0c 24                   movq    %r9, (%rsp)
// d6: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// db: 48 85 c0                      testq   %rax, %rax
// de: 40 0f 94 c5                   sete    %bpl
// e2: 41 8d 45 ff                   leal    -0x1(%r13), %eax
// e6: 48 89 74 24 20                movq    %rsi, 0x20(%rsp)
// eb: 48 83 c6 08                   addq    $0x8, %rsi
// ef: 48 63 d0                      movslq  %eax, %rdx
// f2: 41 ff 50 08                   callq   *0x8(%r8)
// f6: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// fb: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000fd:  R_X86_64_64  _JIT_OPARG
// 105: 66 85 c0                      testw   %ax, %ax
// 108: 0f 94 c0                      sete    %al
// 10b: 40 84 c5                      testb   %al, %bpl
// 10e: 0f 84 b9 00 00 00             je      0x1cd <_JIT_ENTRY+0x1cd>
// 114: 49 8b 04 24                   movq    (%r12), %rax
// 118: 48 85 c0                      testq   %rax, %rax
// 11b: 7f 22                         jg      0x13f <_JIT_ENTRY+0x13f>
// 11d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000011f:  R_X86_64_64  .rodata.str1.1
// 127: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000129:  R_X86_64_64  _Py_NegativeRefcount
// 131: be 38 0c 00 00                movl    $0xc38, %esi            # imm = 0xC38
// 136: 4c 89 e2                      movq    %r12, %rdx
// 139: ff d0                         callq   *%rax
// 13b: 49 8b 04 24                   movq    (%r12), %rax
// 13f: 85 c0                         testl   %eax, %eax
// 141: 4c 8b 74 24 18                movq    0x18(%rsp), %r14
// 146: 78 21                         js      0x169 <_JIT_ENTRY+0x169>
// 148: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014a:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 152: ff d0                         callq   *%rax
// 154: 49 ff 0c 24                   decq    (%r12)
// 158: 75 0f                         jne     0x169 <_JIT_ENTRY+0x169>
// 15a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000015c:  R_X86_64_64  _Py_Dealloc
// 164: 4c 89 e7                      movq    %r12, %rdi
// 167: ff d0                         callq   *%rax
// 169: 48 8b 44 24 10                movq    0x10(%rsp), %rax
// 16e: 49 8d 04 c7                   leaq    (%r15,%rax,8), %rax
// 172: 48 83 c0 08                   addq    $0x8, %rax
// 176: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 17b: 48 85 d2                      testq   %rdx, %rdx
// 17e: 74 38                         je      0x1b8 <_JIT_ENTRY+0x1b8>
// 180: 48 8b 0c 24                   movq    (%rsp), %rcx
// 184: 4d 8d 3c cf                   leaq    (%r15,%rcx,8), %r15
// 188: 49 83 c7 08                   addq    $0x8, %r15
// 18c: 48 89 10                      movq    %rdx, (%rax)
// 18f: 49 8b 46 10                   movq    0x10(%r14), %rax
// 193: 48 8b 00                      movq    (%rax), %rax
// 196: 84 c0                         testb   %al, %al
// 198: 0f 84 bb 00 00 00             je      0x259 <_JIT_ENTRY+0x259>
// 19e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001a0:  R_X86_64_64  _Py_HandlePending
// 1a8: 4c 89 f7                      movq    %r14, %rdi
// 1ab: ff d0                         callq   *%rax
// 1ad: 85 c0                         testl   %eax, %eax
// 1af: 0f 84 a4 00 00 00             je      0x259 <_JIT_ENTRY+0x259>
// 1b5: 4c 89 f8                      movq    %r15, %rax
// 1b8: 48 29 d8                      subq    %rbx, %rax
// 1bb: 48 83 c0 b8                   addq    $-0x48, %rax
// 1bf: 48 c1 e8 03                   shrq    $0x3, %rax
// 1c3: 89 43 40                      movl    %eax, 0x40(%rbx)
// 1c6: 31 c0                         xorl    %eax, %eax
// 1c8: e9 f1 fe ff ff                jmp     0xbe <_JIT_ENTRY+0xbe>
// 1cd: 41 83 fd 02                   cmpl    $0x2, %r13d
// 1d1: 41 be 01 00 00 00             movl    $0x1, %r14d
// 1d7: 45 0f 43 f5                   cmovael %r13d, %r14d
// 1db: 31 ed                         xorl    %ebp, %ebp
// 1dd: eb 0d                         jmp     0x1ec <_JIT_ENTRY+0x1ec>
// 1df: 90                            nop
// 1e0: 48 ff c5                      incq    %rbp
// 1e3: 49 39 ee                      cmpq    %rbp, %r14
// 1e6: 0f 84 28 ff ff ff             je      0x114 <_JIT_ENTRY+0x114>
// 1ec: 48 8b 44 24 20                movq    0x20(%rsp), %rax
// 1f1: 4c 8b 2c e8                   movq    (%rax,%rbp,8), %r13
// 1f5: 49 8b 45 00                   movq    (%r13), %rax
// 1f9: 48 85 c0                      testq   %rax, %rax
// 1fc: 7e 12                         jle     0x210 <_JIT_ENTRY+0x210>
// 1fe: 85 c0                         testl   %eax, %eax
// 200: 78 de                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 202: eb 32                         jmp     0x236 <_JIT_ENTRY+0x236>
// 204: 66 66 66 2e 0f 1f 84 00 00 00 00 00   nopw    %cs:(%rax,%rax)
// 210: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000212:  R_X86_64_64  .rodata.str1.1
// 21a: be 36 0c 00 00                movl    $0xc36, %esi            # imm = 0xC36
// 21f: 4c 89 ea                      movq    %r13, %rdx
// 222: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000224:  R_X86_64_64  _Py_NegativeRefcount
// 22c: ff d0                         callq   *%rax
// 22e: 49 8b 45 00                   movq    (%r13), %rax
// 232: 85 c0                         testl   %eax, %eax
// 234: 78 aa                         js      0x1e0 <_JIT_ENTRY+0x1e0>
// 236: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000238:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 240: ff d0                         callq   *%rax
// 242: 49 ff 4d 00                   decq    (%r13)
// 246: 75 98                         jne     0x1e0 <_JIT_ENTRY+0x1e0>
// 248: 4c 89 ef                      movq    %r13, %rdi
// 24b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000024d:  R_X86_64_64  _Py_Dealloc
// 255: ff d0                         callq   *%rax
// 257: eb 87                         jmp     0x1e0 <_JIT_ENTRY+0x1e0>
// 259: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000025b:  R_X86_64_64  _JIT_CONTINUE
// 263: 48 89 df                      movq    %rbx, %rdi
// 266: 4c 89 fe                      movq    %r15, %rsi
// 269: 4c 89 f2                      movq    %r14, %rdx
// 26c: 48 83 c4 28                   addq    $0x28, %rsp
// 270: 5b                            popq    %rbx
// 271: 41 5c                         popq    %r12
// 273: 41 5d                         popq    %r13
// 275: 41 5e                         popq    %r14
// 277: 41 5f                         popq    %r15
// 279: 5d                            popq    %rbp
// 27a: ff e0                         jmpq    *%rax
// 27c: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_code_body[637] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf9, 0x89, 0xf8, 0xf7, 0xd0, 0x4c, 0x63, 0xc8, 0x4a, 0x8b, 0x44, 0xce, 0x08, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xfe, 0x4c, 0x63, 0xd6, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xce, 0x48, 0xf7, 0xd9, 0x44, 0x8d, 0x6f, 0x01, 0x48, 0x85, 0xc0, 0x48, 0x0f, 0x44, 0xce, 0x44, 0x0f, 0x44, 0xef, 0x4f, 0x8b, 0x64, 0xd7, 0x08, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x74, 0x24, 0x08, 0x75, 0x21, 0x4d, 0x8b, 0x44, 0x24, 0x28, 0x41, 0x81, 0x78, 0x10, 0x80, 0x00, 0x00, 0x00, 0x75, 0x12, 0x49, 0x8d, 0x34, 0xcf, 0x48, 0x8b, 0x3e, 0x48, 0x8b, 0x4f, 0x08, 0x49, 0x3b, 0x4c, 0x24, 0x10, 0x74, 0x3b, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x4c, 0x89, 0x54, 0x24, 0x10, 0x4c, 0x89, 0x0c, 0x24, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x85, 0xc0, 0x40, 0x0f, 0x94, 0xc5, 0x41, 0x8d, 0x45, 0xff, 0x48, 0x89, 0x74, 0x24, 0x20, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x63, 0xd0, 0x41, 0xff, 0x50, 0x08, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x94, 0xc0, 0x40, 0x84, 0xc5, 0x0f, 0x84, 0xb9, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x38, 0x0c, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x4c, 0x8b, 0x74, 0x24, 0x18, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x8b, 0x44, 0x24, 0x10, 0x49, 0x8d, 0x04, 0xc7, 0x48, 0x83, 0xc0, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x85, 0xd2, 0x74, 0x38, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x3c, 0xcf, 0x49, 0x83, 0xc7, 0x08, 0x48, 0x89, 0x10, 0x49, 0x8b, 0x46, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x0f, 0x84, 0xbb, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x84, 0xa4, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf8, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0xe9, 0xf1, 0xfe, 0xff, 0xff, 0x41, 0x83, 0xfd, 0x02, 0x41, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x45, 0x0f, 0x43, 0xf5, 0x31, 0xed, 0xeb, 0x0d, 0x90, 0x48, 0xff, 0xc5, 0x49, 0x39, 0xee, 0x0f, 0x84, 0x28, 0xff, 0xff, 0xff, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x4c, 0x8b, 0x2c, 0xe8, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x12, 0x85, 0xc0, 0x78, 0xde, 0xeb, 0x32, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x36, 0x0c, 0x00, 0x00, 0x4c, 0x89, 0xea, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0xaa, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x75, 0x98, 0x4c, 0x89, 0xef, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0x87, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfe, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_code_holes[15] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMethodDescr_Type, 0x0},
    {0xaa, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0xfd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x11f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x129, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x14a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x15c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1a0, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x212, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x224, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x238, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x24d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x25b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_data_holes[1];

// _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 f9                      movzwl  %cx, %edi
// 28: 89 f8                         movl    %edi, %eax
// 2a: f7 d0                         notl    %eax
// 2c: 4c 63 c8                      movslq  %eax, %r9
// 2f: 4a 8b 44 ce 08                movq    0x8(%rsi,%r9,8), %rax
// 34: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 39: 29 fe                         subl    %edi, %esi
// 3b: 4c 63 d6                      movslq  %esi, %r10
// 3e: 0f b7 c9                      movzwl  %cx, %ecx
// 41: be 01 00 00 00                movl    $0x1, %esi
// 46: 48 29 ce                      subq    %rcx, %rsi
// 49: 48 f7 d9                      negq    %rcx
// 4c: 44 8d 6f 01                   leal    0x1(%rdi), %r13d
// 50: 48 85 c0                      testq   %rax, %rax
// 53: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 57: 44 0f 44 ef                   cmovel  %edi, %r13d
// 5b: 4f 8b 64 d7 08                movq    0x8(%r15,%r10,8), %r12
// 60: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000062:  R_X86_64_64  PyMethodDescr_Type
// 6a: 49 39 74 24 08                cmpq    %rsi, 0x8(%r12)
// 6f: 75 21                         jne     0x92 <_JIT_ENTRY+0x92>
// 71: 4d 8b 44 24 28                movq    0x28(%r12), %r8
// 76: 41 81 78 10 82 00 00 00       cmpl    $0x82, 0x10(%r8)
// 7e: 75 12                         jne     0x92 <_JIT_ENTRY+0x92>
// 80: 49 8d 34 cf                   leaq    (%r15,%rcx,8), %rsi
// 84: 48 8b 3e                      movq    (%rsi), %rdi
// 87: 48 8b 4f 08                   movq    0x8(%rdi), %rcx
// 8b: 49 3b 4c 24 10                cmpq    0x10(%r12), %rcx
// 90: 74 3b                         je      0xcd <_JIT_ENTRY+0xcd>
// 92: 49 83 c7 08                   addq    $0x8, %r15
// 96: 49 29 df                      subq    %rbx, %r15
// 99: 49 83 c7 b8                   addq    $-0x48, %r15
// 9d: 49 c1 ef 03                   shrq    $0x3, %r15
// a1: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// a5: 48 8b 03                      movq    (%rbx), %rax
// a8: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000aa:  R_X86_64_64  _JIT_TARGET
// b2: 89 c9                         movl    %ecx, %ecx
// b4: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// b8: 48 05 c8 00 00 00             addq    $0xc8, %rax
// be: 48 83 c4 28                   addq    $0x28, %rsp
// c2: 5b                            popq    %rbx
// c3: 41 5c                         popq    %r12
// c5: 41 5d                         popq    %r13
// c7: 41 5e                         popq    %r14
// c9: 41 5f                         popq    %r15
// cb: 5d                            popq    %rbp
// cc: c3                            retq
// cd: 4c 89 54 24 10                movq    %r10, 0x10(%rsp)
// d2: 4c 89 0c 24                   movq    %r9, (%rsp)
// d6: 48 89 54 24 18                movq    %rdx, 0x18(%rsp)
// db: 48 85 c0                      testq   %rax, %rax
// de: 40 0f 94 c5                   sete    %bpl
// e2: 41 8d 45 ff                   leal    -0x1(%r13), %eax
// e6: 48 89 74 24 20                movq    %rsi, 0x20(%rsp)
// eb: 48 83 c6 08                   addq    $0x8, %rsi
// ef: 48 63 d0                      movslq  %eax, %rdx
// f2: 31 c9                         xorl    %ecx, %ecx
// f4: 41 ff 50 08                   callq   *0x8(%r8)
// f8: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// fd: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ff:  R_X86_64_64  _JIT_OPARG
// 107: 66 85 c0                      testw   %ax, %ax
// 10a: 0f 94 c0                      sete    %al
// 10d: 40 84 c5                      testb   %al, %bpl
// 110: 0f 84 b9 00 00 00             je      0x1cf <_JIT_ENTRY+0x1cf>
// 116: 49 8b 04 24                   movq    (%r12), %rax
// 11a: 48 85 c0                      testq   %rax, %rax
// 11d: 7f 22                         jg      0x141 <_JIT_ENTRY+0x141>
// 11f: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000121:  R_X86_64_64  .rodata.str1.1
// 129: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000012b:  R_X86_64_64  _Py_NegativeRefcount
// 133: be e8 0b 00 00                movl    $0xbe8, %esi            # imm = 0xBE8
// 138: 4c 89 e2                      movq    %r12, %rdx
// 13b: ff d0                         callq   *%rax
// 13d: 49 8b 04 24                   movq    (%r12), %rax
// 141: 85 c0                         testl   %eax, %eax
// 143: 4c 8b 74 24 18                movq    0x18(%rsp), %r14
// 148: 78 21                         js      0x16b <_JIT_ENTRY+0x16b>
// 14a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014c:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 154: ff d0                         callq   *%rax
// 156: 49 ff 0c 24                   decq    (%r12)
// 15a: 75 0f                         jne     0x16b <_JIT_ENTRY+0x16b>
// 15c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000015e:  R_X86_64_64  _Py_Dealloc
// 166: 4c 89 e7                      movq    %r12, %rdi
// 169: ff d0                         callq   *%rax
// 16b: 48 8b 44 24 10                movq    0x10(%rsp), %rax
// 170: 49 8d 04 c7                   leaq    (%r15,%rax,8), %rax
// 174: 48 83 c0 08                   addq    $0x8, %rax
// 178: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// 17d: 48 85 d2                      testq   %rdx, %rdx
// 180: 74 38                         je      0x1ba <_JIT_ENTRY+0x1ba>
// 182: 48 8b 0c 24                   movq    (%rsp), %rcx
// 186: 4d 8d 3c cf                   leaq    (%r15,%rcx,8), %r15
// 18a: 49 83 c7 08                   addq    $0x8, %r15
// 18e: 48 89 10                      movq    %rdx, (%rax)
// 191: 49 8b 46 10                   movq    0x10(%r14), %rax
// 195: 48 8b 00                      movq    (%rax), %rax
// 198: 84 c0                         testb   %al, %al
// 19a: 0f 84 c9 00 00 00             je      0x269 <_JIT_ENTRY+0x269>
// 1a0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001a2:  R_X86_64_64  _Py_HandlePending
// 1aa: 4c 89 f7                      movq    %r14, %rdi
// 1ad: ff d0                         callq   *%rax
// 1af: 85 c0                         testl   %eax, %eax
// 1b1: 0f 84 b2 00 00 00             je      0x269 <_JIT_ENTRY+0x269>
// 1b7: 4c 89 f8                      movq    %r15, %rax
// 1ba: 48 29 d8                      subq    %rbx, %rax
// 1bd: 48 83 c0 b8                   addq    $-0x48, %rax
// 1c1: 48 c1 e8 03                   shrq    $0x3, %rax
// 1c5: 89 43 40                      movl    %eax, 0x40(%rbx)
// 1c8: 31 c0                         xorl    %eax, %eax
// 1ca: e9 ef fe ff ff                jmp     0xbe <_JIT_ENTRY+0xbe>
// 1cf: 41 83 fd 02                   cmpl    $0x2, %r13d
// 1d3: 41 be 01 00 00 00             movl    $0x1, %r14d
// 1d9: 45 0f 43 f5                   cmovael %r13d, %r14d
// 1dd: 31 ed                         xorl    %ebp, %ebp
// 1df: eb 1b                         jmp     0x1fc <_JIT_ENTRY+0x1fc>
// 1e1: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nopw    %cs:(%rax,%rax)
// 1f0: 48 ff c5                      incq    %rbp
// 1f3: 49 39 ee                      cmpq    %rbp, %r14
// 1f6: 0f 84 1a ff ff ff             je      0x116 <_JIT_ENTRY+0x116>
// 1fc: 48 8b 44 24 20                movq    0x20(%rsp), %rax
// 201: 4c 8b 2c e8                   movq    (%rax,%rbp,8), %r13
// 205: 49 8b 45 00                   movq    (%r13), %rax
// 209: 48 85 c0                      testq   %rax, %rax
// 20c: 7e 12                         jle     0x220 <_JIT_ENTRY+0x220>
// 20e: 85 c0                         testl   %eax, %eax
// 210: 78 de                         js      0x1f0 <_JIT_ENTRY+0x1f0>
// 212: eb 32                         jmp     0x246 <_JIT_ENTRY+0x246>
// 214: 66 66 66 2e 0f 1f 84 00 00 00 00 00   nopw    %cs:(%rax,%rax)
// 220: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000222:  R_X86_64_64  .rodata.str1.1
// 22a: be e6 0b 00 00                movl    $0xbe6, %esi            # imm = 0xBE6
// 22f: 4c 89 ea                      movq    %r13, %rdx
// 232: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000234:  R_X86_64_64  _Py_NegativeRefcount
// 23c: ff d0                         callq   *%rax
// 23e: 49 8b 45 00                   movq    (%r13), %rax
// 242: 85 c0                         testl   %eax, %eax
// 244: 78 aa                         js      0x1f0 <_JIT_ENTRY+0x1f0>
// 246: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000248:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 250: ff d0                         callq   *%rax
// 252: 49 ff 4d 00                   decq    (%r13)
// 256: 75 98                         jne     0x1f0 <_JIT_ENTRY+0x1f0>
// 258: 4c 89 ef                      movq    %r13, %rdi
// 25b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000025d:  R_X86_64_64  _Py_Dealloc
// 265: ff d0                         callq   *%rax
// 267: eb 87                         jmp     0x1f0 <_JIT_ENTRY+0x1f0>
// 269: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000026b:  R_X86_64_64  _JIT_CONTINUE
// 273: 48 89 df                      movq    %rbx, %rdi
// 276: 4c 89 fe                      movq    %r15, %rsi
// 279: 4c 89 f2                      movq    %r14, %rdx
// 27c: 48 83 c4 28                   addq    $0x28, %rsp
// 280: 5b                            popq    %rbx
// 281: 41 5c                         popq    %r12
// 283: 41 5d                         popq    %r13
// 285: 41 5e                         popq    %r14
// 287: 41 5f                         popq    %r15
// 289: 5d                            popq    %rbp
// 28a: ff e0                         jmpq    *%rax
// 28c: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_code_body[653] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf9, 0x89, 0xf8, 0xf7, 0xd0, 0x4c, 0x63, 0xc8, 0x4a, 0x8b, 0x44, 0xce, 0x08, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xfe, 0x4c, 0x63, 0xd6, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xce, 0x48, 0xf7, 0xd9, 0x44, 0x8d, 0x6f, 0x01, 0x48, 0x85, 0xc0, 0x48, 0x0f, 0x44, 0xce, 0x44, 0x0f, 0x44, 0xef, 0x4f, 0x8b, 0x64, 0xd7, 0x08, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x74, 0x24, 0x08, 0x75, 0x21, 0x4d, 0x8b, 0x44, 0x24, 0x28, 0x41, 0x81, 0x78, 0x10, 0x82, 0x00, 0x00, 0x00, 0x75, 0x12, 0x49, 0x8d, 0x34, 0xcf, 0x48, 0x8b, 0x3e, 0x48, 0x8b, 0x4f, 0x08, 0x49, 0x3b, 0x4c, 0x24, 0x10, 0x74, 0x3b, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x4c, 0x89, 0x54, 0x24, 0x10, 0x4c, 0x89, 0x0c, 0x24, 0x48, 0x89, 0x54, 0x24, 0x18, 0x48, 0x85, 0xc0, 0x40, 0x0f, 0x94, 0xc5, 0x41, 0x8d, 0x45, 0xff, 0x48, 0x89, 0x74, 0x24, 0x20, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x63, 0xd0, 0x31, 0xc9, 0x41, 0xff, 0x50, 0x08, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x0f, 0x94, 0xc0, 0x40, 0x84, 0xc5, 0x0f, 0x84, 0xb9, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xe8, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x4c, 0x8b, 0x74, 0x24, 0x18, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x8b, 0x44, 0x24, 0x10, 0x49, 0x8d, 0x04, 0xc7, 0x48, 0x83, 0xc0, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x85, 0xd2, 0x74, 0x38, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x3c, 0xcf, 0x49, 0x83, 0xc7, 0x08, 0x48, 0x89, 0x10, 0x49, 0x8b, 0x46, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x0f, 0x84, 0xc9, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x84, 0xb2, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf8, 0x48, 0x29, 0xd8, 0x48, 0x83, 0xc0, 0xb8, 0x48, 0xc1, 0xe8, 0x03, 0x89, 0x43, 0x40, 0x31, 0xc0, 0xe9, 0xef, 0xfe, 0xff, 0xff, 0x41, 0x83, 0xfd, 0x02, 0x41, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x45, 0x0f, 0x43, 0xf5, 0x31, 0xed, 0xeb, 0x1b, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xc5, 0x49, 0x39, 0xee, 0x0f, 0x84, 0x1a, 0xff, 0xff, 0xff, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x4c, 0x8b, 0x2c, 0xe8, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x12, 0x85, 0xc0, 0x78, 0xde, 0xeb, 0x32, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xe6, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xea, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0xaa, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x75, 0x98, 0x4c, 0x89, 0xef, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0xeb, 0x87, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfe, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_code_holes[15] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMethodDescr_Type, 0x0},
    {0xaa, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0xff, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x121, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x12b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x14c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x15e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1a2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x222, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x234, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x248, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x25d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x26b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_data_holes[1];

// _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 49 89 f6                      movq    %rsi, %r14
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 c1                      movzwl  %cx, %eax
// 28: 89 c6                         movl    %eax, %esi
// 2a: f7 d6                         notl    %esi
// 2c: 4c 63 ee                      movslq  %esi, %r13
// 2f: 44 0f b7 c9                   movzwl  %cx, %r9d
// 33: be 01 00 00 00                movl    $0x1, %esi
// 38: 4c 29 ce                      subq    %r9, %rsi
// 3b: 4c 89 c9                      movq    %r9, %rcx
// 3e: 48 f7 d9                      negq    %rcx
// 41: 31 ff                         xorl    %edi, %edi
// 43: 66 45 85 c9                   testw   %r9w, %r9w
// 47: 40 0f 94 c7                   sete    %dil
// 4b: 45 31 c0                      xorl    %r8d, %r8d
// 4e: 66 41 83 f9 01                cmpw    $0x1, %r9w
// 53: 41 0f 94 c0                   sete    %r8b
// 57: 4b 83 7c ee 08 00             cmpq    $0x0, 0x8(%r14,%r13,8)
// 5d: 48 0f 44 ce                   cmoveq  %rsi, %rcx
// 61: 4d 8d 7e 08                   leaq    0x8(%r14), %r15
// 65: 41 0f 44 f8                   cmovel  %r8d, %edi
// 69: 40 80 ff 01                   cmpb    $0x1, %dil
// 6d: 0f 85 77 01 00 00             jne     0x1ea <_JIT_ENTRY+0x1ea>
// 73: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 78: 29 c6                         subl    %eax, %esi
// 7a: 48 63 ee                      movslq  %esi, %rbp
// 7d: 4d 8b 64 ee 08                movq    0x8(%r14,%rbp,8), %r12
// 82: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000084:  R_X86_64_64  PyMethodDescr_Type
// 8c: 49 39 44 24 08                cmpq    %rax, 0x8(%r12)
// 91: 0f 85 53 01 00 00             jne     0x1ea <_JIT_ENTRY+0x1ea>
// 97: 49 8b 3c ce                   movq    (%r14,%rcx,8), %rdi
// 9b: 48 8b 47 08                   movq    0x8(%rdi), %rax
// 9f: 49 3b 44 24 10                cmpq    0x10(%r12), %rax
// a4: 0f 85 40 01 00 00             jne     0x1ea <_JIT_ENTRY+0x1ea>
// aa: 49 8b 44 24 28                movq    0x28(%r12), %rax
// af: 83 78 10 04                   cmpl    $0x4, 0x10(%rax)
// b3: 0f 85 31 01 00 00             jne     0x1ea <_JIT_ENTRY+0x1ea>
// b9: 4c 8b 40 08                   movq    0x8(%rax), %r8
// bd: 8b 42 2c                      movl    0x2c(%rdx), %eax
// c0: 8d 48 ff                      leal    -0x1(%rax), %ecx
// c3: 89 4a 2c                      movl    %ecx, 0x2c(%rdx)
// c6: 85 c0                         testl   %eax, %eax
// c8: 48 89 14 24                   movq    %rdx, (%rsp)
// cc: 48 89 7c 24 08                movq    %rdi, 0x8(%rsp)
// d1: 0f 8e 4a 01 00 00             jle     0x221 <_JIT_ENTRY+0x221>
// d7: 31 f6                         xorl    %esi, %esi
// d9: 41 ff d0                      callq   *%r8
// dc: 48 8b 54 24 08                movq    0x8(%rsp), %rdx
// e1: 48 8b 0c 24                   movq    (%rsp), %rcx
// e5: ff 41 2c                      incl    0x2c(%rcx)
// e8: 48 89 44 24 10                movq    %rax, 0x10(%rsp)
// ed: 48 8b 02                      movq    (%rdx), %rax
// f0: 48 85 c0                      testq   %rax, %rax
// f3: 7f 27                         jg      0x11c <_JIT_ENTRY+0x11c>
// f5: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000f7:  R_X86_64_64  .rodata.str1.1
// ff: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000101:  R_X86_64_64  _Py_NegativeRefcount
// 109: be 10 0c 00 00                movl    $0xc10, %esi            # imm = 0xC10
// 10e: ff d0                         callq   *%rax
// 110: 48 8b 0c 24                   movq    (%rsp), %rcx
// 114: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 119: 48 8b 00                      movq    (%rax), %rax
// 11c: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000011e:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 126: 85 c0                         testl   %eax, %eax
// 128: 78 21                         js      0x14b <_JIT_ENTRY+0x14b>
// 12a: 41 ff d7                      callq   *%r15
// 12d: 48 8b 7c 24 08                movq    0x8(%rsp), %rdi
// 132: 48 8b 0c 24                   movq    (%rsp), %rcx
// 136: 48 ff 0f                      decq    (%rdi)
// 139: 75 10                         jne     0x14b <_JIT_ENTRY+0x14b>
// 13b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013d:  R_X86_64_64  _Py_Dealloc
// 145: ff d0                         callq   *%rax
// 147: 48 8b 0c 24                   movq    (%rsp), %rcx
// 14b: 49 8b 04 24                   movq    (%r12), %rax
// 14f: 48 85 c0                      testq   %rax, %rax
// 152: 7f 26                         jg      0x17a <_JIT_ENTRY+0x17a>
// 154: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000156:  R_X86_64_64  .rodata.str1.1
// 15e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000160:  R_X86_64_64  _Py_NegativeRefcount
// 168: be 11 0c 00 00                movl    $0xc11, %esi            # imm = 0xC11
// 16d: 4c 89 e2                      movq    %r12, %rdx
// 170: ff d0                         callq   *%rax
// 172: 48 8b 0c 24                   movq    (%rsp), %rcx
// 176: 49 8b 04 24                   movq    (%r12), %rax
// 17a: 85 c0                         testl   %eax, %eax
// 17c: 78 20                         js      0x19e <_JIT_ENTRY+0x19e>
// 17e: 41 ff d7                      callq   *%r15
// 181: 48 8b 0c 24                   movq    (%rsp), %rcx
// 185: 49 ff 0c 24                   decq    (%r12)
// 189: 75 13                         jne     0x19e <_JIT_ENTRY+0x19e>
// 18b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000018d:  R_X86_64_64  _Py_Dealloc
// 195: 4c 89 e7                      movq    %r12, %rdi
// 198: ff d0                         callq   *%rax
// 19a: 48 8b 0c 24                   movq    (%rsp), %rcx
// 19e: 4d 8d 3c ee                   leaq    (%r14,%rbp,8), %r15
// 1a2: 49 83 c7 08                   addq    $0x8, %r15
// 1a6: 48 8b 44 24 10                movq    0x10(%rsp), %rax
// 1ab: 48 85 c0                      testq   %rax, %rax
// 1ae: 0f 84 9d 00 00 00             je      0x251 <_JIT_ENTRY+0x251>
// 1b4: 4f 8d 34 ee                   leaq    (%r14,%r13,8), %r14
// 1b8: 49 83 c6 08                   addq    $0x8, %r14
// 1bc: 49 89 07                      movq    %rax, (%r15)
// 1bf: 48 8b 41 10                   movq    0x10(%rcx), %rax
// 1c3: 48 8b 00                      movq    (%rax), %rax
// 1c6: 84 c0                         testb   %al, %al
// 1c8: 0f 84 96 00 00 00             je      0x264 <_JIT_ENTRY+0x264>
// 1ce: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001d0:  R_X86_64_64  _Py_HandlePending
// 1d8: 48 89 cf                      movq    %rcx, %rdi
// 1db: ff d0                         callq   *%rax
// 1dd: 48 8b 0c 24                   movq    (%rsp), %rcx
// 1e1: 85 c0                         testl   %eax, %eax
// 1e3: 74 7f                         je      0x264 <_JIT_ENTRY+0x264>
// 1e5: 4d 89 f7                      movq    %r14, %r15
// 1e8: eb 67                         jmp     0x251 <_JIT_ENTRY+0x251>
// 1ea: 49 29 df                      subq    %rbx, %r15
// 1ed: 49 83 c7 b8                   addq    $-0x48, %r15
// 1f1: 49 c1 ef 03                   shrq    $0x3, %r15
// 1f5: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 1f9: 48 8b 03                      movq    (%rbx), %rax
// 1fc: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000001fe:  R_X86_64_64  _JIT_TARGET
// 206: 89 c9                         movl    %ecx, %ecx
// 208: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 20c: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 212: 48 83 c4 18                   addq    $0x18, %rsp
// 216: 5b                            popq    %rbx
// 217: 41 5c                         popq    %r12
// 219: 41 5d                         popq    %r13
// 21b: 41 5e                         popq    %r14
// 21d: 41 5f                         popq    %r15
// 21f: 5d                            popq    %rbp
// 220: c3                            retq
// 221: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000223:  R_X86_64_64  .rodata.str1.1+0x39
// 22b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000022d:  R_X86_64_64  _Py_CheckRecursiveCall
// 235: 48 89 d7                      movq    %rdx, %rdi
// 238: 4c 89 44 24 10                movq    %r8, 0x10(%rsp)
// 23d: ff d0                         callq   *%rax
// 23f: 4c 8b 44 24 10                movq    0x10(%rsp), %r8
// 244: 48 8b 7c 24 08                movq    0x8(%rsp), %rdi
// 249: 85 c0                         testl   %eax, %eax
// 24b: 0f 84 86 fe ff ff             je      0xd7 <_JIT_ENTRY+0xd7>
// 251: 49 29 df                      subq    %rbx, %r15
// 254: 49 83 c7 b8                   addq    $-0x48, %r15
// 258: 49 c1 ef 03                   shrq    $0x3, %r15
// 25c: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 260: 31 c0                         xorl    %eax, %eax
// 262: eb ae                         jmp     0x212 <_JIT_ENTRY+0x212>
// 264: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000266:  R_X86_64_64  _JIT_CONTINUE
// 26e: 48 89 df                      movq    %rbx, %rdi
// 271: 4c 89 f6                      movq    %r14, %rsi
// 274: 48 89 ca                      movq    %rcx, %rdx
// 277: 48 83 c4 18                   addq    $0x18, %rsp
// 27b: 5b                            popq    %rbx
// 27c: 41 5c                         popq    %r12
// 27e: 41 5d                         popq    %r13
// 280: 41 5e                         popq    %r14
// 282: 41 5f                         popq    %r15
// 284: 5d                            popq    %rbp
// 285: ff e0                         jmpq    *%rax
// 287: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS_code_body[648] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc1, 0x89, 0xc6, 0xf7, 0xd6, 0x4c, 0x63, 0xee, 0x44, 0x0f, 0xb7, 0xc9, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x4c, 0x29, 0xce, 0x4c, 0x89, 0xc9, 0x48, 0xf7, 0xd9, 0x31, 0xff, 0x66, 0x45, 0x85, 0xc9, 0x40, 0x0f, 0x94, 0xc7, 0x45, 0x31, 0xc0, 0x66, 0x41, 0x83, 0xf9, 0x01, 0x41, 0x0f, 0x94, 0xc0, 0x4b, 0x83, 0x7c, 0xee, 0x08, 0x00, 0x48, 0x0f, 0x44, 0xce, 0x4d, 0x8d, 0x7e, 0x08, 0x41, 0x0f, 0x44, 0xf8, 0x40, 0x80, 0xff, 0x01, 0x0f, 0x85, 0x77, 0x01, 0x00, 0x00, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc6, 0x48, 0x63, 0xee, 0x4d, 0x8b, 0x64, 0xee, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x44, 0x24, 0x08, 0x0f, 0x85, 0x53, 0x01, 0x00, 0x00, 0x49, 0x8b, 0x3c, 0xce, 0x48, 0x8b, 0x47, 0x08, 0x49, 0x3b, 0x44, 0x24, 0x10, 0x0f, 0x85, 0x40, 0x01, 0x00, 0x00, 0x49, 0x8b, 0x44, 0x24, 0x28, 0x83, 0x78, 0x10, 0x04, 0x0f, 0x85, 0x31, 0x01, 0x00, 0x00, 0x4c, 0x8b, 0x40, 0x08, 0x8b, 0x42, 0x2c, 0x8d, 0x48, 0xff, 0x89, 0x4a, 0x2c, 0x85, 0xc0, 0x48, 0x89, 0x14, 0x24, 0x48, 0x89, 0x7c, 0x24, 0x08, 0x0f, 0x8e, 0x4a, 0x01, 0x00, 0x00, 0x31, 0xf6, 0x41, 0xff, 0xd0, 0x48, 0x8b, 0x54, 0x24, 0x08, 0x48, 0x8b, 0x0c, 0x24, 0xff, 0x41, 0x2c, 0x48, 0x89, 0x44, 0x24, 0x10, 0x48, 0x8b, 0x02, 0x48, 0x85, 0xc0, 0x7f, 0x27, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x10, 0x0c, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x0c, 0x24, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x8b, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x41, 0xff, 0xd7, 0x48, 0x8b, 0x7c, 0x24, 0x08, 0x48, 0x8b, 0x0c, 0x24, 0x48, 0xff, 0x0f, 0x75, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x0c, 0x24, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x26, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x11, 0x0c, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x48, 0x8b, 0x0c, 0x24, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x20, 0x41, 0xff, 0xd7, 0x48, 0x8b, 0x0c, 0x24, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x13, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x8b, 0x0c, 0x24, 0x4d, 0x8d, 0x3c, 0xee, 0x49, 0x83, 0xc7, 0x08, 0x48, 0x8b, 0x44, 0x24, 0x10, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0x9d, 0x00, 0x00, 0x00, 0x4f, 0x8d, 0x34, 0xee, 0x49, 0x83, 0xc6, 0x08, 0x49, 0x89, 0x07, 0x48, 0x8b, 0x41, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x0f, 0x84, 0x96, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xcf, 0xff, 0xd0, 0x48, 0x8b, 0x0c, 0x24, 0x85, 0xc0, 0x74, 0x7f, 0x4d, 0x89, 0xf7, 0xeb, 0x67, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x4c, 0x89, 0x44, 0x24, 0x10, 0xff, 0xd0, 0x4c, 0x8b, 0x44, 0x24, 0x10, 0x48, 0x8b, 0x7c, 0x24, 0x08, 0x85, 0xc0, 0x0f, 0x84, 0x86, 0xfe, 0xff, 0xff, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x31, 0xc0, 0xeb, 0xae, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xca, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS_code_holes[15] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x84, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMethodDescr_Type, 0x0},
    {0xf7, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x101, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x11e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x13d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x156, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x160, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x18d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1d0, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x1fe, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x223, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x22d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_CheckRecursiveCall, 0x0},
    {0x266, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00 while calling a Python object\x00'
// 58: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS_data_body[89] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x20, 0x77, 0x68, 0x69, 0x6c, 0x65, 0x20, 0x63, 0x61, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x20, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS_data_holes[1];

// _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 f6                      movq    %rsi, %r14
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001d:  R_X86_64_64  _JIT_OPARG
// 25: 0f b7 c8                      movzwl  %ax, %ecx
// 28: 89 ce                         movl    %ecx, %esi
// 2a: f7 d6                         notl    %esi
// 2c: 48 63 ee                      movslq  %esi, %rbp
// 2f: 44 0f b7 c8                   movzwl  %ax, %r9d
// 33: be 01 00 00 00                movl    $0x1, %esi
// 38: 4c 29 ce                      subq    %r9, %rsi
// 3b: 4c 89 c8                      movq    %r9, %rax
// 3e: 48 f7 d8                      negq    %rax
// 41: 31 ff                         xorl    %edi, %edi
// 43: 66 41 83 f9 01                cmpw    $0x1, %r9w
// 48: 40 0f 94 c7                   sete    %dil
// 4c: 45 31 c0                      xorl    %r8d, %r8d
// 4f: 66 41 83 f9 02                cmpw    $0x2, %r9w
// 54: 41 0f 94 c0                   sete    %r8b
// 58: 49 83 7c ee 08 00             cmpq    $0x0, 0x8(%r14,%rbp,8)
// 5e: 48 0f 44 c6                   cmoveq  %rsi, %rax
// 62: 4d 8d 7e 08                   leaq    0x8(%r14), %r15
// 66: 41 0f 44 f8                   cmovel  %r8d, %edi
// 6a: 40 80 ff 01                   cmpb    $0x1, %dil
// 6e: 75 3a                         jne     0xaa <_JIT_ENTRY+0xaa>
// 70: be fe ff ff ff                movl    $0xfffffffe, %esi       # imm = 0xFFFFFFFE
// 75: 29 ce                         subl    %ecx, %esi
// 77: 4c 63 ee                      movslq  %esi, %r13
// 7a: 4f 8b 64 ee 08                movq    0x8(%r14,%r13,8), %r12
// 7f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000081:  R_X86_64_64  PyMethodDescr_Type
// 89: 49 39 4c 24 08                cmpq    %rcx, 0x8(%r12)
// 8e: 75 1a                         jne     0xaa <_JIT_ENTRY+0xaa>
// 90: 49 8b 4c 24 28                movq    0x28(%r12), %rcx
// 95: 83 79 10 08                   cmpl    $0x8, 0x10(%rcx)
// 99: 75 0f                         jne     0xaa <_JIT_ENTRY+0xaa>
// 9b: 49 8b 3c c6                   movq    (%r14,%rax,8), %rdi
// 9f: 48 8b 77 08                   movq    0x8(%rdi), %rsi
// a3: 49 3b 74 24 10                cmpq    0x10(%r12), %rsi
// a8: 74 37                         je      0xe1 <_JIT_ENTRY+0xe1>
// aa: 49 29 df                      subq    %rbx, %r15
// ad: 49 83 c7 b8                   addq    $-0x48, %r15
// b1: 49 c1 ef 03                   shrq    $0x3, %r15
// b5: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// b9: 48 8b 03                      movq    (%rbx), %rax
// bc: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000be:  R_X86_64_64  _JIT_TARGET
// c6: 89 c9                         movl    %ecx, %ecx
// c8: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// cc: 48 05 c8 00 00 00             addq    $0xc8, %rax
// d2: 48 83 c4 28                   addq    $0x28, %rsp
// d6: 5b                            popq    %rbx
// d7: 41 5c                         popq    %r12
// d9: 41 5d                         popq    %r13
// db: 41 5e                         popq    %r14
// dd: 41 5f                         popq    %r15
// df: 5d                            popq    %rbp
// e0: c3                            retq
// e1: 49 8b 74 c6 08                movq    0x8(%r14,%rax,8), %rsi
// e6: 4c 8b 41 08                   movq    0x8(%rcx), %r8
// ea: 8b 42 2c                      movl    0x2c(%rdx), %eax
// ed: 8d 48 ff                      leal    -0x1(%rax), %ecx
// f0: 89 4a 2c                      movl    %ecx, 0x2c(%rdx)
// f3: 85 c0                         testl   %eax, %eax
// f5: 48 89 54 24 08                movq    %rdx, 0x8(%rsp)
// fa: 48 89 74 24 18                movq    %rsi, 0x18(%rsp)
// ff: 48 89 7c 24 10                movq    %rdi, 0x10(%rsp)
// 104: 0f 8e 6d 01 00 00             jle     0x277 <_JIT_ENTRY+0x277>
// 10a: 41 ff d0                      callq   *%r8
// 10d: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// 112: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 117: ff 41 2c                      incl    0x2c(%rcx)
// 11a: 48 89 44 24 20                movq    %rax, 0x20(%rsp)
// 11f: 48 8b 02                      movq    (%rdx), %rax
// 122: 48 85 c0                      testq   %rax, %rax
// 125: 7f 28                         jg      0x14f <_JIT_ENTRY+0x14f>
// 127: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000129:  R_X86_64_64  .rodata.str1.1
// 131: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000133:  R_X86_64_64  _Py_NegativeRefcount
// 13b: be bf 0b 00 00                movl    $0xbbf, %esi            # imm = 0xBBF
// 140: ff d0                         callq   *%rax
// 142: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 147: 48 8b 44 24 10                movq    0x10(%rsp), %rax
// 14c: 48 8b 00                      movq    (%rax), %rax
// 14f: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 0000000000000151:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 159: 85 c0                         testl   %eax, %eax
// 15b: 78 23                         js      0x180 <_JIT_ENTRY+0x180>
// 15d: 41 ff d7                      callq   *%r15
// 160: 48 8b 7c 24 10                movq    0x10(%rsp), %rdi
// 165: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 16a: 48 ff 0f                      decq    (%rdi)
// 16d: 75 11                         jne     0x180 <_JIT_ENTRY+0x180>
// 16f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000171:  R_X86_64_64  _Py_Dealloc
// 179: ff d0                         callq   *%rax
// 17b: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 180: 48 8b 54 24 18                movq    0x18(%rsp), %rdx
// 185: 48 8b 02                      movq    (%rdx), %rax
// 188: 48 85 c0                      testq   %rax, %rax
// 18b: 7f 28                         jg      0x1b5 <_JIT_ENTRY+0x1b5>
// 18d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000018f:  R_X86_64_64  .rodata.str1.1
// 197: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000199:  R_X86_64_64  _Py_NegativeRefcount
// 1a1: be c0 0b 00 00                movl    $0xbc0, %esi            # imm = 0xBC0
// 1a6: ff d0                         callq   *%rax
// 1a8: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 1ad: 48 8b 44 24 18                movq    0x18(%rsp), %rax
// 1b2: 48 8b 00                      movq    (%rax), %rax
// 1b5: 85 c0                         testl   %eax, %eax
// 1b7: 78 23                         js      0x1dc <_JIT_ENTRY+0x1dc>
// 1b9: 41 ff d7                      callq   *%r15
// 1bc: 48 8b 7c 24 18                movq    0x18(%rsp), %rdi
// 1c1: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 1c6: 48 ff 0f                      decq    (%rdi)
// 1c9: 75 11                         jne     0x1dc <_JIT_ENTRY+0x1dc>
// 1cb: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001cd:  R_X86_64_64  _Py_Dealloc
// 1d5: ff d0                         callq   *%rax
// 1d7: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 1dc: 49 8b 04 24                   movq    (%r12), %rax
// 1e0: 48 85 c0                      testq   %rax, %rax
// 1e3: 7f 27                         jg      0x20c <_JIT_ENTRY+0x20c>
// 1e5: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000001e7:  R_X86_64_64  .rodata.str1.1
// 1ef: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001f1:  R_X86_64_64  _Py_NegativeRefcount
// 1f9: be c1 0b 00 00                movl    $0xbc1, %esi            # imm = 0xBC1
// 1fe: 4c 89 e2                      movq    %r12, %rdx
// 201: ff d0                         callq   *%rax
// 203: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 208: 49 8b 04 24                   movq    (%r12), %rax
// 20c: 85 c0                         testl   %eax, %eax
// 20e: 78 22                         js      0x232 <_JIT_ENTRY+0x232>
// 210: 41 ff d7                      callq   *%r15
// 213: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 218: 49 ff 0c 24                   decq    (%r12)
// 21c: 75 14                         jne     0x232 <_JIT_ENTRY+0x232>
// 21e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000220:  R_X86_64_64  _Py_Dealloc
// 228: 4c 89 e7                      movq    %r12, %rdi
// 22b: ff d0                         callq   *%rax
// 22d: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 232: 4f 8d 3c ee                   leaq    (%r14,%r13,8), %r15
// 236: 49 83 c7 08                   addq    $0x8, %r15
// 23a: 48 8b 44 24 20                movq    0x20(%rsp), %rax
// 23f: 48 85 c0                      testq   %rax, %rax
// 242: 74 68                         je      0x2ac <_JIT_ENTRY+0x2ac>
// 244: 4d 8d 34 ee                   leaq    (%r14,%rbp,8), %r14
// 248: 49 83 c6 08                   addq    $0x8, %r14
// 24c: 49 89 07                      movq    %rax, (%r15)
// 24f: 48 8b 41 10                   movq    0x10(%rcx), %rax
// 253: 48 8b 00                      movq    (%rax), %rax
// 256: 84 c0                         testb   %al, %al
// 258: 74 68                         je      0x2c2 <_JIT_ENTRY+0x2c2>
// 25a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000025c:  R_X86_64_64  _Py_HandlePending
// 264: 48 89 cf                      movq    %rcx, %rdi
// 267: ff d0                         callq   *%rax
// 269: 48 8b 4c 24 08                movq    0x8(%rsp), %rcx
// 26e: 85 c0                         testl   %eax, %eax
// 270: 74 50                         je      0x2c2 <_JIT_ENTRY+0x2c2>
// 272: 4d 89 f7                      movq    %r14, %r15
// 275: eb 35                         jmp     0x2ac <_JIT_ENTRY+0x2ac>
// 277: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000279:  R_X86_64_64  .rodata.str1.1+0x39
// 281: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000283:  R_X86_64_64  _Py_CheckRecursiveCall
// 28b: 48 89 d7                      movq    %rdx, %rdi
// 28e: 4c 89 44 24 20                movq    %r8, 0x20(%rsp)
// 293: ff d0                         callq   *%rax
// 295: 4c 8b 44 24 20                movq    0x20(%rsp), %r8
// 29a: 48 8b 7c 24 10                movq    0x10(%rsp), %rdi
// 29f: 48 8b 74 24 18                movq    0x18(%rsp), %rsi
// 2a4: 85 c0                         testl   %eax, %eax
// 2a6: 0f 84 5e fe ff ff             je      0x10a <_JIT_ENTRY+0x10a>
// 2ac: 49 29 df                      subq    %rbx, %r15
// 2af: 49 83 c7 b8                   addq    $-0x48, %r15
// 2b3: 49 c1 ef 03                   shrq    $0x3, %r15
// 2b7: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 2bb: 31 c0                         xorl    %eax, %eax
// 2bd: e9 10 fe ff ff                jmp     0xd2 <_JIT_ENTRY+0xd2>
// 2c2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000002c4:  R_X86_64_64  _JIT_CONTINUE
// 2cc: 48 89 df                      movq    %rbx, %rdi
// 2cf: 4c 89 f6                      movq    %r14, %rsi
// 2d2: 48 89 ca                      movq    %rcx, %rdx
// 2d5: 48 83 c4 28                   addq    $0x28, %rsp
// 2d9: 5b                            popq    %rbx
// 2da: 41 5c                         popq    %r12
// 2dc: 41 5d                         popq    %r13
// 2de: 41 5e                         popq    %r14
// 2e0: 41 5f                         popq    %r15
// 2e2: 5d                            popq    %rbp
// 2e3: ff e0                         jmpq    *%rax
// 2e5: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O_code_body[742] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x89, 0xce, 0xf7, 0xd6, 0x48, 0x63, 0xee, 0x44, 0x0f, 0xb7, 0xc8, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x4c, 0x29, 0xce, 0x4c, 0x89, 0xc8, 0x48, 0xf7, 0xd8, 0x31, 0xff, 0x66, 0x41, 0x83, 0xf9, 0x01, 0x40, 0x0f, 0x94, 0xc7, 0x45, 0x31, 0xc0, 0x66, 0x41, 0x83, 0xf9, 0x02, 0x41, 0x0f, 0x94, 0xc0, 0x49, 0x83, 0x7c, 0xee, 0x08, 0x00, 0x48, 0x0f, 0x44, 0xc6, 0x4d, 0x8d, 0x7e, 0x08, 0x41, 0x0f, 0x44, 0xf8, 0x40, 0x80, 0xff, 0x01, 0x75, 0x3a, 0xbe, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xce, 0x4c, 0x63, 0xee, 0x4f, 0x8b, 0x64, 0xee, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x4c, 0x24, 0x08, 0x75, 0x1a, 0x49, 0x8b, 0x4c, 0x24, 0x28, 0x83, 0x79, 0x10, 0x08, 0x75, 0x0f, 0x49, 0x8b, 0x3c, 0xc6, 0x48, 0x8b, 0x77, 0x08, 0x49, 0x3b, 0x74, 0x24, 0x10, 0x74, 0x37, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x49, 0x8b, 0x74, 0xc6, 0x08, 0x4c, 0x8b, 0x41, 0x08, 0x8b, 0x42, 0x2c, 0x8d, 0x48, 0xff, 0x89, 0x4a, 0x2c, 0x85, 0xc0, 0x48, 0x89, 0x54, 0x24, 0x08, 0x48, 0x89, 0x74, 0x24, 0x18, 0x48, 0x89, 0x7c, 0x24, 0x10, 0x0f, 0x8e, 0x6d, 0x01, 0x00, 0x00, 0x41, 0xff, 0xd0, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0xff, 0x41, 0x2c, 0x48, 0x89, 0x44, 0x24, 0x20, 0x48, 0x8b, 0x02, 0x48, 0x85, 0xc0, 0x7f, 0x28, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xbf, 0x0b, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x48, 0x8b, 0x44, 0x24, 0x10, 0x48, 0x8b, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x23, 0x41, 0xff, 0xd7, 0x48, 0x8b, 0x7c, 0x24, 0x10, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x48, 0xff, 0x0f, 0x75, 0x11, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x48, 0x8b, 0x54, 0x24, 0x18, 0x48, 0x8b, 0x02, 0x48, 0x85, 0xc0, 0x7f, 0x28, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xc0, 0x0b, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x48, 0x8b, 0x44, 0x24, 0x18, 0x48, 0x8b, 0x00, 0x85, 0xc0, 0x78, 0x23, 0x41, 0xff, 0xd7, 0x48, 0x8b, 0x7c, 0x24, 0x18, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x48, 0xff, 0x0f, 0x75, 0x11, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x27, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xc1, 0x0b, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x22, 0x41, 0xff, 0xd7, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x14, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x4f, 0x8d, 0x3c, 0xee, 0x49, 0x83, 0xc7, 0x08, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x48, 0x85, 0xc0, 0x74, 0x68, 0x4d, 0x8d, 0x34, 0xee, 0x49, 0x83, 0xc6, 0x08, 0x49, 0x89, 0x07, 0x48, 0x8b, 0x41, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x68, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xcf, 0xff, 0xd0, 0x48, 0x8b, 0x4c, 0x24, 0x08, 0x85, 0xc0, 0x74, 0x50, 0x4d, 0x89, 0xf7, 0xeb, 0x35, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x4c, 0x89, 0x44, 0x24, 0x20, 0xff, 0xd0, 0x4c, 0x8b, 0x44, 0x24, 0x20, 0x48, 0x8b, 0x7c, 0x24, 0x10, 0x48, 0x8b, 0x74, 0x24, 0x18, 0x85, 0xc0, 0x0f, 0x84, 0x5e, 0xfe, 0xff, 0xff, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x31, 0xc0, 0xe9, 0x10, 0xfe, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xca, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O_code_holes[18] = {
    {0x1d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x81, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMethodDescr_Type, 0x0},
    {0xbe, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x129, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x133, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x151, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x171, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x18f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x199, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x1cd, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x1e7, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x1f1, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x220, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x25c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x279, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0x283, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_CheckRecursiveCall, 0x0},
    {0x2c4, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00 while calling a Python object\x00'
// 58: 
static const unsigned char _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O_data_body[89] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x20, 0x77, 0x68, 0x69, 0x6c, 0x65, 0x20, 0x63, 0x61, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x20, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00};
static const Hole _PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O_data_holes[1];

// _PUSH_NULLplus_CALL_STR_1
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_STR_1.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 f7                      movq    %rsi, %r15
// e: 48 89 fb                      movq    %rdi, %rbx
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 89 c1                         movl    %eax, %ecx
// 27: f7 d1                         notl    %ecx
// 29: 4c 63 e1                      movslq  %ecx, %r12
// 2c: 4a 83 7c e6 08 00             cmpq    $0x0, 0x8(%rsi,%r12,8)
// 32: 75 22                         jne     0x56 <_JIT_ENTRY+0x56>
// 34: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 39: 29 c1                         subl    %eax, %ecx
// 3b: 48 63 c1                      movslq  %ecx, %rax
// 3e: 4d 8d 2c c7                   leaq    (%r15,%rax,8), %r13
// 42: 49 83 c5 08                   addq    $0x8, %r13
// 46: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000048:  R_X86_64_64  PyUnicode_Type
// 50: 49 39 45 00                   cmpq    %rax, (%r13)
// 54: 74 3b                         je      0x91 <_JIT_ENTRY+0x91>
// 56: 49 83 c7 08                   addq    $0x8, %r15
// 5a: 49 29 df                      subq    %rbx, %r15
// 5d: 49 83 c7 b8                   addq    $-0x48, %r15
// 61: 49 c1 ef 03                   shrq    $0x3, %r15
// 65: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 69: 48 8b 03                      movq    (%rbx), %rax
// 6c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006e:  R_X86_64_64  _JIT_TARGET
// 76: 89 c9                         movl    %ecx, %ecx
// 78: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 7c: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 82: 48 83 c4 08                   addq    $0x8, %rsp
// 86: 5b                            popq    %rbx
// 87: 41 5c                         popq    %r12
// 89: 41 5d                         popq    %r13
// 8b: 41 5e                         popq    %r14
// 8d: 41 5f                         popq    %r15
// 8f: 5d                            popq    %rbp
// 90: c3                            retq
// 91: 49 89 d6                      movq    %rdx, %r14
// 94: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000096:  R_X86_64_64  _JIT_OPARG
// 9e: 0f b7 c0                      movzwl  %ax, %eax
// a1: 48 c1 e0 03                   shlq    $0x3, %rax
// a5: 4c 89 f9                      movq    %r15, %rcx
// a8: 48 29 c1                      subq    %rax, %rcx
// ab: 48 8b 69 08                   movq    0x8(%rcx), %rbp
// af: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b1:  R_X86_64_64  PyObject_Str
// b9: 48 89 ef                      movq    %rbp, %rdi
// bc: ff d0                         callq   *%rax
// be: 48 89 04 24                   movq    %rax, (%rsp)
// c2: 48 8b 45 00                   movq    (%rbp), %rax
// c6: 48 85 c0                      testq   %rax, %rax
// c9: 7f 22                         jg      0xed <_JIT_ENTRY+0xed>
// cb: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000cd:  R_X86_64_64  .rodata.str1.1
// d5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d7:  R_X86_64_64  _Py_NegativeRefcount
// df: be 95 0a 00 00                movl    $0xa95, %esi            # imm = 0xA95
// e4: 48 89 ea                      movq    %rbp, %rdx
// e7: ff d0                         callq   *%rax
// e9: 48 8b 45 00                   movq    (%rbp), %rax
// ed: 85 c0                         testl   %eax, %eax
// ef: 78 21                         js      0x112 <_JIT_ENTRY+0x112>
// f1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f3:  R_X86_64_64  _Py_DECREF_DecRefTotal
// fb: ff d0                         callq   *%rax
// fd: 48 ff 4d 00                   decq    (%rbp)
// 101: 75 0f                         jne     0x112 <_JIT_ENTRY+0x112>
// 103: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000105:  R_X86_64_64  _Py_Dealloc
// 10d: 48 89 ef                      movq    %rbp, %rdi
// 110: ff d0                         callq   *%rax
// 112: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 0000000000000114:  R_X86_64_64  PyUnicode_Type
// 11c: 48 8b 45 00                   movq    (%rbp), %rax
// 120: 48 85 c0                      testq   %rax, %rax
// 123: 7f 22                         jg      0x147 <_JIT_ENTRY+0x147>
// 125: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000127:  R_X86_64_64  .rodata.str1.1
// 12f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000131:  R_X86_64_64  _Py_NegativeRefcount
// 139: be 96 0a 00 00                movl    $0xa96, %esi            # imm = 0xA96
// 13e: 48 89 ea                      movq    %rbp, %rdx
// 141: ff d0                         callq   *%rax
// 143: 48 8b 45 00                   movq    (%rbp), %rax
// 147: 85 c0                         testl   %eax, %eax
// 149: 78 28                         js      0x173 <_JIT_ENTRY+0x173>
// 14b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014d:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 155: ff d0                         callq   *%rax
// 157: 48 ff 4d 00                   decq    (%rbp)
// 15b: 75 16                         jne     0x173 <_JIT_ENTRY+0x173>
// 15d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000015f:  R_X86_64_64  PyUnicode_Type
// 167: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000169:  R_X86_64_64  _Py_Dealloc
// 171: ff d0                         callq   *%rax
// 173: 48 8b 04 24                   movq    (%rsp), %rax
// 177: 48 85 c0                      testq   %rax, %rax
// 17a: 74 2d                         je      0x1a9 <_JIT_ENTRY+0x1a9>
// 17c: 4f 8d 3c e7                   leaq    (%r15,%r12,8), %r15
// 180: 49 83 c7 08                   addq    $0x8, %r15
// 184: 49 89 45 00                   movq    %rax, (%r13)
// 188: 49 8b 46 10                   movq    0x10(%r14), %rax
// 18c: 48 8b 00                      movq    (%rax), %rax
// 18f: 84 c0                         testb   %al, %al
// 191: 74 2c                         je      0x1bf <_JIT_ENTRY+0x1bf>
// 193: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000195:  R_X86_64_64  _Py_HandlePending
// 19d: 4c 89 f7                      movq    %r14, %rdi
// 1a0: ff d0                         callq   *%rax
// 1a2: 85 c0                         testl   %eax, %eax
// 1a4: 74 19                         je      0x1bf <_JIT_ENTRY+0x1bf>
// 1a6: 4d 89 fd                      movq    %r15, %r13
// 1a9: 49 29 dd                      subq    %rbx, %r13
// 1ac: 49 83 c5 b8                   addq    $-0x48, %r13
// 1b0: 49 c1 ed 03                   shrq    $0x3, %r13
// 1b4: 44 89 6b 40                   movl    %r13d, 0x40(%rbx)
// 1b8: 31 c0                         xorl    %eax, %eax
// 1ba: e9 c3 fe ff ff                jmp     0x82 <_JIT_ENTRY+0x82>
// 1bf: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c1:  R_X86_64_64  _JIT_CONTINUE
// 1c9: 48 89 df                      movq    %rbx, %rdi
// 1cc: 4c 89 fe                      movq    %r15, %rsi
// 1cf: 4c 89 f2                      movq    %r14, %rdx
// 1d2: 48 83 c4 08                   addq    $0x8, %rsp
// 1d6: 5b                            popq    %rbx
// 1d7: 41 5c                         popq    %r12
// 1d9: 41 5d                         popq    %r13
// 1db: 41 5e                         popq    %r14
// 1dd: 41 5f                         popq    %r15
// 1df: 5d                            popq    %rbp
// 1e0: ff e0                         jmpq    *%rax
// 1e2: 
static const unsigned char _PUSH_NULLplus_CALL_STR_1_code_body[483] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x89, 0xc1, 0xf7, 0xd1, 0x4c, 0x63, 0xe1, 0x4a, 0x83, 0x7c, 0xe6, 0x08, 0x00, 0x75, 0x22, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x4d, 0x8d, 0x2c, 0xc7, 0x49, 0x83, 0xc5, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x45, 0x00, 0x74, 0x3b, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x49, 0x89, 0xd6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x4c, 0x89, 0xf9, 0x48, 0x29, 0xc1, 0x48, 0x8b, 0x69, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x48, 0x89, 0x04, 0x24, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x95, 0x0a, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x96, 0x0a, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x16, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x2d, 0x4f, 0x8d, 0x3c, 0xe7, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x89, 0x45, 0x00, 0x49, 0x8b, 0x46, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x2c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x19, 0x4d, 0x89, 0xfd, 0x49, 0x29, 0xdd, 0x49, 0x83, 0xc5, 0xb8, 0x49, 0xc1, 0xed, 0x03, 0x44, 0x89, 0x6b, 0x40, 0x31, 0xc0, 0xe9, 0xc3, 0xfe, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfe, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_STR_1_code_holes[18] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x6e, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xb1, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Str, 0x0},
    {0xcd, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xd7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xf3, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x105, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x114, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x127, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x131, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x14d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x15f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x169, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x195, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x1c1, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_STR_1_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_STR_1_data_holes[1];

// _PUSH_NULLplus_CALL_TUPLE_1
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_TUPLE_1.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 f7                      movq    %rsi, %r15
// e: 48 89 fb                      movq    %rdi, %rbx
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 89 c1                         movl    %eax, %ecx
// 27: f7 d1                         notl    %ecx
// 29: 4c 63 e1                      movslq  %ecx, %r12
// 2c: 4a 83 7c e6 08 00             cmpq    $0x0, 0x8(%rsi,%r12,8)
// 32: 75 22                         jne     0x56 <_JIT_ENTRY+0x56>
// 34: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 39: 29 c1                         subl    %eax, %ecx
// 3b: 48 63 c1                      movslq  %ecx, %rax
// 3e: 4d 8d 2c c7                   leaq    (%r15,%rax,8), %r13
// 42: 49 83 c5 08                   addq    $0x8, %r13
// 46: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000048:  R_X86_64_64  PyTuple_Type
// 50: 49 39 45 00                   cmpq    %rax, (%r13)
// 54: 74 3b                         je      0x91 <_JIT_ENTRY+0x91>
// 56: 49 83 c7 08                   addq    $0x8, %r15
// 5a: 49 29 df                      subq    %rbx, %r15
// 5d: 49 83 c7 b8                   addq    $-0x48, %r15
// 61: 49 c1 ef 03                   shrq    $0x3, %r15
// 65: 44 89 7b 40                   movl    %r15d, 0x40(%rbx)
// 69: 48 8b 03                      movq    (%rbx), %rax
// 6c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006e:  R_X86_64_64  _JIT_TARGET
// 76: 89 c9                         movl    %ecx, %ecx
// 78: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 7c: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 82: 48 83 c4 08                   addq    $0x8, %rsp
// 86: 5b                            popq    %rbx
// 87: 41 5c                         popq    %r12
// 89: 41 5d                         popq    %r13
// 8b: 41 5e                         popq    %r14
// 8d: 41 5f                         popq    %r15
// 8f: 5d                            popq    %rbp
// 90: c3                            retq
// 91: 49 89 d6                      movq    %rdx, %r14
// 94: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000096:  R_X86_64_64  _JIT_OPARG
// 9e: 0f b7 c0                      movzwl  %ax, %eax
// a1: 48 c1 e0 03                   shlq    $0x3, %rax
// a5: 4c 89 f9                      movq    %r15, %rcx
// a8: 48 29 c1                      subq    %rax, %rcx
// ab: 48 8b 69 08                   movq    0x8(%rcx), %rbp
// af: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b1:  R_X86_64_64  PySequence_Tuple
// b9: 48 89 ef                      movq    %rbp, %rdi
// bc: ff d0                         callq   *%rax
// be: 48 89 04 24                   movq    %rax, (%rsp)
// c2: 48 8b 45 00                   movq    (%rbp), %rax
// c6: 48 85 c0                      testq   %rax, %rax
// c9: 7f 22                         jg      0xed <_JIT_ENTRY+0xed>
// cb: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000cd:  R_X86_64_64  .rodata.str1.1
// d5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d7:  R_X86_64_64  _Py_NegativeRefcount
// df: be ad 0a 00 00                movl    $0xaad, %esi            # imm = 0xAAD
// e4: 48 89 ea                      movq    %rbp, %rdx
// e7: ff d0                         callq   *%rax
// e9: 48 8b 45 00                   movq    (%rbp), %rax
// ed: 85 c0                         testl   %eax, %eax
// ef: 78 21                         js      0x112 <_JIT_ENTRY+0x112>
// f1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f3:  R_X86_64_64  _Py_DECREF_DecRefTotal
// fb: ff d0                         callq   *%rax
// fd: 48 ff 4d 00                   decq    (%rbp)
// 101: 75 0f                         jne     0x112 <_JIT_ENTRY+0x112>
// 103: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000105:  R_X86_64_64  _Py_Dealloc
// 10d: 48 89 ef                      movq    %rbp, %rdi
// 110: ff d0                         callq   *%rax
// 112: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 0000000000000114:  R_X86_64_64  PyTuple_Type
// 11c: 48 8b 45 00                   movq    (%rbp), %rax
// 120: 48 85 c0                      testq   %rax, %rax
// 123: 7f 22                         jg      0x147 <_JIT_ENTRY+0x147>
// 125: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000127:  R_X86_64_64  .rodata.str1.1
// 12f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000131:  R_X86_64_64  _Py_NegativeRefcount
// 139: be ae 0a 00 00                movl    $0xaae, %esi            # imm = 0xAAE
// 13e: 48 89 ea                      movq    %rbp, %rdx
// 141: ff d0                         callq   *%rax
// 143: 48 8b 45 00                   movq    (%rbp), %rax
// 147: 85 c0                         testl   %eax, %eax
// 149: 78 28                         js      0x173 <_JIT_ENTRY+0x173>
// 14b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014d:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 155: ff d0                         callq   *%rax
// 157: 48 ff 4d 00                   decq    (%rbp)
// 15b: 75 16                         jne     0x173 <_JIT_ENTRY+0x173>
// 15d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000015f:  R_X86_64_64  PyTuple_Type
// 167: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000169:  R_X86_64_64  _Py_Dealloc
// 171: ff d0                         callq   *%rax
// 173: 48 8b 04 24                   movq    (%rsp), %rax
// 177: 48 85 c0                      testq   %rax, %rax
// 17a: 74 2d                         je      0x1a9 <_JIT_ENTRY+0x1a9>
// 17c: 4f 8d 3c e7                   leaq    (%r15,%r12,8), %r15
// 180: 49 83 c7 08                   addq    $0x8, %r15
// 184: 49 89 45 00                   movq    %rax, (%r13)
// 188: 49 8b 46 10                   movq    0x10(%r14), %rax
// 18c: 48 8b 00                      movq    (%rax), %rax
// 18f: 84 c0                         testb   %al, %al
// 191: 74 2c                         je      0x1bf <_JIT_ENTRY+0x1bf>
// 193: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000195:  R_X86_64_64  _Py_HandlePending
// 19d: 4c 89 f7                      movq    %r14, %rdi
// 1a0: ff d0                         callq   *%rax
// 1a2: 85 c0                         testl   %eax, %eax
// 1a4: 74 19                         je      0x1bf <_JIT_ENTRY+0x1bf>
// 1a6: 4d 89 fd                      movq    %r15, %r13
// 1a9: 49 29 dd                      subq    %rbx, %r13
// 1ac: 49 83 c5 b8                   addq    $-0x48, %r13
// 1b0: 49 c1 ed 03                   shrq    $0x3, %r13
// 1b4: 44 89 6b 40                   movl    %r13d, 0x40(%rbx)
// 1b8: 31 c0                         xorl    %eax, %eax
// 1ba: e9 c3 fe ff ff                jmp     0x82 <_JIT_ENTRY+0x82>
// 1bf: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c1:  R_X86_64_64  _JIT_CONTINUE
// 1c9: 48 89 df                      movq    %rbx, %rdi
// 1cc: 4c 89 fe                      movq    %r15, %rsi
// 1cf: 4c 89 f2                      movq    %r14, %rdx
// 1d2: 48 83 c4 08                   addq    $0x8, %rsp
// 1d6: 5b                            popq    %rbx
// 1d7: 41 5c                         popq    %r12
// 1d9: 41 5d                         popq    %r13
// 1db: 41 5e                         popq    %r14
// 1dd: 41 5f                         popq    %r15
// 1df: 5d                            popq    %rbp
// 1e0: ff e0                         jmpq    *%rax
// 1e2: 
static const unsigned char _PUSH_NULLplus_CALL_TUPLE_1_code_body[483] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x89, 0xc1, 0xf7, 0xd1, 0x4c, 0x63, 0xe1, 0x4a, 0x83, 0x7c, 0xe6, 0x08, 0x00, 0x75, 0x22, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x4d, 0x8d, 0x2c, 0xc7, 0x49, 0x83, 0xc5, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x45, 0x00, 0x74, 0x3b, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x29, 0xdf, 0x49, 0x83, 0xc7, 0xb8, 0x49, 0xc1, 0xef, 0x03, 0x44, 0x89, 0x7b, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x49, 0x89, 0xd6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x4c, 0x89, 0xf9, 0x48, 0x29, 0xc1, 0x48, 0x8b, 0x69, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x48, 0x89, 0x04, 0x24, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xad, 0x0a, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xae, 0x0a, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x16, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x2d, 0x4f, 0x8d, 0x3c, 0xe7, 0x49, 0x83, 0xc7, 0x08, 0x49, 0x89, 0x45, 0x00, 0x49, 0x8b, 0x46, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x2c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x19, 0x4d, 0x89, 0xfd, 0x49, 0x29, 0xdd, 0x49, 0x83, 0xc5, 0xb8, 0x49, 0xc1, 0xed, 0x03, 0x44, 0x89, 0x6b, 0x40, 0x31, 0xc0, 0xe9, 0xc3, 0xfe, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfe, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_TUPLE_1_code_holes[18] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x6e, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xb1, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySequence_Tuple, 0x0},
    {0xcd, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xd7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xf3, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x105, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x114, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x127, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x131, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x14d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x15f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x169, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x195, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x1c1, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_TUPLE_1_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_TUPLE_1_data_holes[1];

// _PUSH_NULLplus_CALL_TYPE_1
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CALL_TYPE_1.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 f6                      movq    %rsi, %r14
// e: 48 89 fb                      movq    %rdi, %rbx
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: f7 d0                         notl    %eax
// 24: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 29: 48 63 e8                      movslq  %eax, %rbp
// 2c: 48 83 7c ee 08 00             cmpq    $0x0, 0x8(%rsi,%rbp,8)
// 32: 75 28                         jne     0x5c <_JIT_ENTRY+0x5c>
// 34: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000036:  R_X86_64_64  _JIT_OPARG
// 3e: 0f b7 c0                      movzwl  %ax, %eax
// 41: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 46: 29 c1                         subl    %eax, %ecx
// 48: 48 63 c1                      movslq  %ecx, %rax
// 4b: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 000000000000004d:  R_X86_64_64  PyType_Type
// 55: 4d 39 64 c6 08                cmpq    %r12, 0x8(%r14,%rax,8)
// 5a: 74 37                         je      0x93 <_JIT_ENTRY+0x93>
// 5c: 49 29 de                      subq    %rbx, %r14
// 5f: 49 83 c6 c0                   addq    $-0x40, %r14
// 63: 49 c1 ee 03                   shrq    $0x3, %r14
// 67: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 6b: 48 8b 03                      movq    (%rbx), %rax
// 6e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000070:  R_X86_64_64  _JIT_TARGET
// 78: 89 c9                         movl    %ecx, %ecx
// 7a: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 7e: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 84: 48 83 c4 08                   addq    $0x8, %rsp
// 88: 5b                            popq    %rbx
// 89: 41 5c                         popq    %r12
// 8b: 41 5d                         popq    %r13
// 8d: 41 5e                         popq    %r14
// 8f: 41 5f                         popq    %r15
// 91: 5d                            popq    %rbp
// 92: c3                            retq
// 93: 49 89 d7                      movq    %rdx, %r15
// 96: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000098:  R_X86_64_64  _JIT_OPARG
// a0: 0f b7 c0                      movzwl  %ax, %eax
// a3: 48 c1 e0 03                   shlq    $0x3, %rax
// a7: 4c 89 f1                      movq    %r14, %rcx
// aa: 48 29 c1                      subq    %rax, %rcx
// ad: 4c 8b 69 08                   movq    0x8(%rcx), %r13
// b1: 49 8b 45 08                   movq    0x8(%r13), %rax
// b5: 48 89 04 24                   movq    %rax, (%rsp)
// b9: 8b 00                         movl    (%rax), %eax
// bb: ff c0                         incl    %eax
// bd: 75 0f                         jne     0xce <_JIT_ENTRY+0xce>
// bf: 49 8b 45 00                   movq    (%r13), %rax
// c3: 48 85 c0                      testq   %rax, %rax
// c6: 7e 21                         jle     0xe9 <_JIT_ENTRY+0xe9>
// c8: 85 c0                         testl   %eax, %eax
// ca: 79 43                         jns     0x10f <_JIT_ENTRY+0x10f>
// cc: eb 62                         jmp     0x130 <_JIT_ENTRY+0x130>
// ce: 48 8b 0c 24                   movq    (%rsp), %rcx
// d2: 89 01                         movl    %eax, (%rcx)
// d4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d6:  R_X86_64_64  _Py_INCREF_IncRefTotal
// de: ff d0                         callq   *%rax
// e0: 49 8b 45 00                   movq    (%r13), %rax
// e4: 48 85 c0                      testq   %rax, %rax
// e7: 7f df                         jg      0xc8 <_JIT_ENTRY+0xc8>
// e9: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000eb:  R_X86_64_64  .rodata.str1.1
// f3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f5:  R_X86_64_64  _Py_NegativeRefcount
// fd: be 7f 0a 00 00                movl    $0xa7f, %esi            # imm = 0xA7F
// 102: 4c 89 ea                      movq    %r13, %rdx
// 105: ff d0                         callq   *%rax
// 107: 49 8b 45 00                   movq    (%r13), %rax
// 10b: 85 c0                         testl   %eax, %eax
// 10d: 78 21                         js      0x130 <_JIT_ENTRY+0x130>
// 10f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000111:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 119: ff d0                         callq   *%rax
// 11b: 49 ff 4d 00                   decq    (%r13)
// 11f: 75 0f                         jne     0x130 <_JIT_ENTRY+0x130>
// 121: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000123:  R_X86_64_64  _Py_Dealloc
// 12b: 4c 89 ef                      movq    %r13, %rdi
// 12e: ff d0                         callq   *%rax
// 130: 49 8b 04 24                   movq    (%r12), %rax
// 134: 48 85 c0                      testq   %rax, %rax
// 137: 7f 22                         jg      0x15b <_JIT_ENTRY+0x15b>
// 139: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000013b:  R_X86_64_64  .rodata.str1.1
// 143: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000145:  R_X86_64_64  _Py_NegativeRefcount
// 14d: be 80 0a 00 00                movl    $0xa80, %esi            # imm = 0xA80
// 152: 4c 89 e2                      movq    %r12, %rdx
// 155: ff d0                         callq   *%rax
// 157: 49 8b 04 24                   movq    (%r12), %rax
// 15b: 4d 8d 2c ee                   leaq    (%r14,%rbp,8), %r13
// 15f: 49 83 c5 08                   addq    $0x8, %r13
// 163: 85 c0                         testl   %eax, %eax
// 165: 78 28                         js      0x18f <_JIT_ENTRY+0x18f>
// 167: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000169:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 171: ff d0                         callq   *%rax
// 173: 49 ff 0c 24                   decq    (%r12)
// 177: 75 16                         jne     0x18f <_JIT_ENTRY+0x18f>
// 179: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000017b:  R_X86_64_64  PyType_Type
// 183: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000185:  R_X86_64_64  _Py_Dealloc
// 18d: ff d0                         callq   *%rax
// 18f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000191:  R_X86_64_64  _JIT_OPARG
// 199: 0f b7 c0                      movzwl  %ax, %eax
// 19c: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 1a1: 29 c1                         subl    %eax, %ecx
// 1a3: 48 63 c1                      movslq  %ecx, %rax
// 1a6: 48 8b 0c 24                   movq    (%rsp), %rcx
// 1aa: 49 89 4c c6 08                movq    %rcx, 0x8(%r14,%rax,8)
// 1af: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001b1:  R_X86_64_64  _JIT_CONTINUE
// 1b9: 48 89 df                      movq    %rbx, %rdi
// 1bc: 4c 89 ee                      movq    %r13, %rsi
// 1bf: 4c 89 fa                      movq    %r15, %rdx
// 1c2: 48 83 c4 08                   addq    $0x8, %rsp
// 1c6: 5b                            popq    %rbx
// 1c7: 41 5c                         popq    %r12
// 1c9: 41 5d                         popq    %r13
// 1cb: 41 5e                         popq    %r14
// 1cd: 41 5f                         popq    %r15
// 1cf: 5d                            popq    %rbp
// 1d0: ff e0                         jmpq    *%rax
// 1d2: 
static const unsigned char _PUSH_NULLplus_CALL_TYPE_1_code_body[467] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x63, 0xe8, 0x48, 0x83, 0x7c, 0xee, 0x08, 0x00, 0x75, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x39, 0x64, 0xc6, 0x08, 0x74, 0x37, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xc0, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x49, 0x89, 0xd7, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x4c, 0x89, 0xf1, 0x48, 0x29, 0xc1, 0x4c, 0x8b, 0x69, 0x08, 0x49, 0x8b, 0x45, 0x08, 0x48, 0x89, 0x04, 0x24, 0x8b, 0x00, 0xff, 0xc0, 0x75, 0x0f, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x21, 0x85, 0xc0, 0x79, 0x43, 0xeb, 0x62, 0x48, 0x8b, 0x0c, 0x24, 0x89, 0x01, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0xdf, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x7f, 0x0a, 0x00, 0x00, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x80, 0x0a, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x4d, 0x8d, 0x2c, 0xee, 0x49, 0x83, 0xc5, 0x08, 0x85, 0xc0, 0x78, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x16, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x48, 0x8b, 0x0c, 0x24, 0x49, 0x89, 0x4c, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xee, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CALL_TYPE_1_code_holes[18] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x36, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4d, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyType_Type, 0x0},
    {0x70, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x98, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xd6, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0xeb, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xf5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x111, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x123, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x13b, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x145, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x169, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x17b, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyType_Type, 0x0},
    {0x185, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x191, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1b1, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CALL_TYPE_1_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CALL_TYPE_1_data_holes[1];

// _PUSH_NULLplus_CHECK_ATTR_CLASS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_ATTR_CLASS.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 13: f6 80 ab 00 00 00 80          testb   $-0x80, 0xab(%rax)
// 1a: 74 1f                         je      0x3b <_JIT_ENTRY+0x3b>
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPERAND
// 26: 39 04 25 80 01 00 00          cmpl    %eax, 0x180
// 2d: 75 0c                         jne     0x3b <_JIT_ENTRY+0x3b>
// 2f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000031:  R_X86_64_64  _JIT_CONTINUE
// 39: ff e0                         jmpq    *%rax
// 3b: 48 29 fe                      subq    %rdi, %rsi
// 3e: 48 83 c6 b8                   addq    $-0x48, %rsi
// 42: 48 c1 ee 03                   shrq    $0x3, %rsi
// 46: 89 77 40                      movl    %esi, 0x40(%rdi)
// 49: 48 8b 07                      movq    (%rdi), %rax
// 4c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004e:  R_X86_64_64  _JIT_TARGET
// 56: 89 c9                         movl    %ecx, %ecx
// 58: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 5c: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 62: c3                            retq
// 63: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_CLASS_code_body[100] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0xf6, 0x80, 0xab, 0x00, 0x00, 0x00, 0x80, 0x74, 0x1f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x04, 0x25, 0x80, 0x01, 0x00, 0x00, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_ATTR_CLASS_code_holes[4] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x31, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_CLASS_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_ATTR_CLASS_data_holes[1];

// _PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT.o:  file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT_code_body[1] = {};
static const Hole _PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT_data_holes[1];

// _PUSH_NULLplus_CHECK_ATTR_MODULE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_ATTR_MODULE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  PyModule_Type
// 15: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1d: 75 27                         jne     0x46 <_JIT_ENTRY+0x46>
// 1f: 48 8b 04 25 10 00 00 00       movq    0x10, %rax
// 27: 48 8b 40 20                   movq    0x20(%rax), %rax
// 2b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002d:  R_X86_64_64  _JIT_OPERAND
// 35: 39 48 0c                      cmpl    %ecx, 0xc(%rax)
// 38: 75 0c                         jne     0x46 <_JIT_ENTRY+0x46>
// 3a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003c:  R_X86_64_64  _JIT_CONTINUE
// 44: ff e0                         jmpq    *%rax
// 46: 48 29 fe                      subq    %rdi, %rsi
// 49: 48 83 c6 b8                   addq    $-0x48, %rsi
// 4d: 48 c1 ee 03                   shrq    $0x3, %rsi
// 51: 89 77 40                      movl    %esi, 0x40(%rdi)
// 54: 48 8b 07                      movq    (%rdi), %rax
// 57: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000059:  R_X86_64_64  _JIT_TARGET
// 61: 89 c9                         movl    %ecx, %ecx
// 63: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 67: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 6d: c3                            retq
// 6e: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_MODULE_code_body[111] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x27, 0x48, 0x8b, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x48, 0x0c, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_ATTR_MODULE_code_holes[5] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyModule_Type, 0x0},
    {0x2d, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x3c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x59, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_MODULE_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_ATTR_MODULE_data_holes[1];

// _PUSH_NULLplus_CHECK_ATTR_WITH_HINT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_ATTR_WITH_HINT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 e8 ff ff ff       movq    -0x18, %rax
// 13: a8 01                         testb   $0x1, %al
// 15: 75 11                         jne     0x28 <_JIT_ENTRY+0x28>
// 17: 48 85 c0                      testq   %rax, %rax
// 1a: 74 0c                         je      0x28 <_JIT_ENTRY+0x28>
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_CONTINUE
// 26: ff e0                         jmpq    *%rax
// 28: 48 29 fe                      subq    %rdi, %rsi
// 2b: 48 83 c6 b8                   addq    $-0x48, %rsi
// 2f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 33: 89 77 40                      movl    %esi, 0x40(%rdi)
// 36: 48 8b 07                      movq    (%rdi), %rax
// 39: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003b:  R_X86_64_64  _JIT_TARGET
// 43: 89 c9                         movl    %ecx, %ecx
// 45: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 49: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4f: c3                            retq
// 50: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_WITH_HINT_code_body[81] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0xa8, 0x01, 0x75, 0x11, 0x48, 0x85, 0xc0, 0x74, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_ATTR_WITH_HINT_code_holes[3] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x3b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_ATTR_WITH_HINT_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_ATTR_WITH_HINT_data_holes[1];

// _PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 89 f0                      movq    %rsi, %rax
// 3: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// a: 48 83 c6 08                   addq    $0x8, %rsi
// e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000010:  R_X86_64_64  _JIT_OPARG
// 18: f7 d1                         notl    %ecx
// 1a: 81 c9 00 00 ff ff             orl     $0xffff0000, %ecx       # imm = 0xFFFF0000
// 20: 48 63 c9                      movslq  %ecx, %rcx
// 23: 48 83 7c c8 08 00             cmpq    $0x0, 0x8(%rax,%rcx,8)
// 29: 75 2e                         jne     0x59 <_JIT_ENTRY+0x59>
// 2b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002d:  R_X86_64_64  _JIT_OPARG
// 35: 0f b7 c9                      movzwl  %cx, %ecx
// 38: 41 b8 fe ff ff ff             movl    $0xfffffffe, %r8d       # imm = 0xFFFFFFFE
// 3e: 41 29 c8                      subl    %ecx, %r8d
// 41: 49 63 c8                      movslq  %r8d, %rcx
// 44: 48 8b 44 c8 08                movq    0x8(%rax,%rcx,8), %rax
// 49: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004b:  R_X86_64_64  PyMethod_Type
// 53: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 57: 74 28                         je      0x81 <_JIT_ENTRY+0x81>
// 59: 48 29 fe                      subq    %rdi, %rsi
// 5c: 48 83 c6 b8                   addq    $-0x48, %rsi
// 60: 48 c1 ee 03                   shrq    $0x3, %rsi
// 64: 89 77 40                      movl    %esi, 0x40(%rdi)
// 67: 48 8b 07                      movq    (%rdi), %rax
// 6a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006c:  R_X86_64_64  _JIT_TARGET
// 74: 89 c9                         movl    %ecx, %ecx
// 76: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 7a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 80: c3                            retq
// 81: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000083:  R_X86_64_64  _JIT_CONTINUE
// 8b: ff e0                         jmpq    *%rax
// 8d: 
static const unsigned char _PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_code_body[142] = {0x48, 0x89, 0xf0, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd1, 0x81, 0xc9, 0x00, 0x00, 0xff, 0xff, 0x48, 0x63, 0xc9, 0x48, 0x83, 0x7c, 0xc8, 0x08, 0x00, 0x75, 0x2e, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x41, 0xb8, 0xfe, 0xff, 0xff, 0xff, 0x41, 0x29, 0xc8, 0x49, 0x63, 0xc8, 0x48, 0x8b, 0x44, 0xc8, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_code_holes[6] = {
    {0x10, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMethod_Type, 0x0},
    {0x6c, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x83, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_data_holes[1];

// _PUSH_NULLplus_CHECK_EG_MATCH
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_EG_MATCH.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 83 ec 10                   subq    $0x10, %rsp
// 5: 48 89 d7                      movq    %rdx, %rdi
// 8: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// f: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// 13: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000015:  R_X86_64_64  _PyEval_CheckExceptStarTypeValid
// 1d: 31 f6                         xorl    %esi, %esi
// 1f: ff d0                         callq   *%rax
// 21: 85 c0                         testl   %eax, %eax
// 23: 78 4b                         js      0x70 <_JIT_ENTRY+0x70>
// 25: 48 c7 04 24 00 00 00 00       movq    $0x0, (%rsp)
// 2d: 48 c7 44 24 08 00 00 00 00    movq    $0x0, 0x8(%rsp)
// 36: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000038:  R_X86_64_64  _PyEval_ExceptionGroupMatch
// 40: 48 89 e2                      movq    %rsp, %rdx
// 43: 48 8d 4c 24 08                leaq    0x8(%rsp), %rcx
// 48: 48 89 df                      movq    %rbx, %rdi
// 4b: 31 f6                         xorl    %esi, %esi
// 4d: ff d0                         callq   *%rax
// 4f: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 53: 7f 3f                         jg      0x94 <_JIT_ENTRY+0x94>
// 55: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000057:  R_X86_64_64  .rodata.str1.1
// 5f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000061:  R_X86_64_64  _Py_NegativeRefcount
// 69: be c1 07 00 00                movl    $0x7c1, %esi            # imm = 0x7C1
// 6e: eb 1f                         jmp     0x8f <_JIT_ENTRY+0x8f>
// 70: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 74: 7f 1e                         jg      0x94 <_JIT_ENTRY+0x94>
// 76: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000078:  R_X86_64_64  .rodata.str1.1
// 80: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000082:  R_X86_64_64  _Py_NegativeRefcount
// 8a: be b9 07 00 00                movl    $0x7b9, %esi            # imm = 0x7B9
// 8f: 48 89 da                      movq    %rbx, %rdx
// 92: ff d0                         callq   *%rax
// 94: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000096:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 9e: ff d0                         callq   *%rax
// a0: 48 ff 0b                      decq    (%rbx)
// a3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a5:  R_X86_64_64  _Py_Dealloc
// ad: 48 89 df                      movq    %rbx, %rdi
// b0: ff d0                         callq   *%rax
// b2: 
static const unsigned char _PUSH_NULLplus_CHECK_EG_MATCH_code_body[179] = {0x53, 0x48, 0x83, 0xec, 0x10, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0x4b, 0x48, 0xc7, 0x04, 0x24, 0x00, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x44, 0x24, 0x08, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe2, 0x48, 0x8d, 0x4c, 0x24, 0x08, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x3f, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xc1, 0x07, 0x00, 0x00, 0xeb, 0x1f, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xb9, 0x07, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_CHECK_EG_MATCH_code_holes[9] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_CheckExceptStarTypeValid, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_ExceptionGroupMatch, 0x0},
    {0x57, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x61, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x78, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x82, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xa5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CHECK_EG_MATCH_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CHECK_EG_MATCH_data_holes[1];

// _PUSH_NULLplus_CHECK_EXC_MATCH
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_EXC_MATCH.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 89 d7                      movq    %rdx, %rdi
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  _PyEval_CheckExceptTypeValid
// 19: 31 f6                         xorl    %esi, %esi
// 1b: ff d0                         callq   *%rax
// 1d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001f:  R_X86_64_64  PyErr_GivenExceptionMatches
// 27: 48 89 df                      movq    %rbx, %rdi
// 2a: 31 f6                         xorl    %esi, %esi
// 2c: ff d0                         callq   *%rax
// 2e: 
static const unsigned char _PUSH_NULLplus_CHECK_EXC_MATCH_code_body[47] = {0x53, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_CHECK_EXC_MATCH_code_holes[3] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_CheckExceptTypeValid, 0x0},
    {0x1f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyErr_GivenExceptionMatches, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_EXC_MATCH_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_EXC_MATCH_data_holes[1];

// _PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 89 f0                      movq    %rsi, %rax
// 3: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// a: 48 83 c6 08                   addq    $0x8, %rsi
// e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000010:  R_X86_64_64  _JIT_OPARG
// 18: 0f b7 c9                      movzwl  %cx, %ecx
// 1b: 41 b8 fe ff ff ff             movl    $0xfffffffe, %r8d       # imm = 0xFFFFFFFE
// 21: 41 29 c8                      subl    %ecx, %r8d
// 24: 4d 63 c0                      movslq  %r8d, %r8
// 27: 4e 8b 44 c0 08                movq    0x8(%rax,%r8,8), %r8
// 2c: 49 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %r9
// 000000000000002e:  R_X86_64_64  PyFunction_Type
// 36: 4d 39 48 08                   cmpq    %r9, 0x8(%r8)
// 3a: 75 46                         jne     0x82 <_JIT_ENTRY+0x82>
// 3c: 49 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %r9
// 000000000000003e:  R_X86_64_64  _JIT_OPERAND
// 46: 45 39 88 88 00 00 00          cmpl    %r9d, 0x88(%r8)
// 4d: 75 33                         jne     0x82 <_JIT_ENTRY+0x82>
// 4f: f7 d1                         notl    %ecx
// 51: 48 63 c9                      movslq  %ecx, %rcx
// 54: 4d 8b 40 30                   movq    0x30(%r8), %r8
// 58: 49 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %r9
// 000000000000005a:  R_X86_64_64  _JIT_OPARG
// 62: 45 0f b7 c9                   movzwl  %r9w, %r9d
// 66: 48 83 7c c8 08 01             cmpq    $0x1, 0x8(%rax,%rcx,8)
// 6c: 41 83 d9 ff                   sbbl    $-0x1, %r9d
// 70: 45 39 48 34                   cmpl    %r9d, 0x34(%r8)
// 74: 75 0c                         jne     0x82 <_JIT_ENTRY+0x82>
// 76: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000078:  R_X86_64_64  _JIT_CONTINUE
// 80: ff e0                         jmpq    *%rax
// 82: 48 29 fe                      subq    %rdi, %rsi
// 85: 48 83 c6 b8                   addq    $-0x48, %rsi
// 89: 48 c1 ee 03                   shrq    $0x3, %rsi
// 8d: 89 77 40                      movl    %esi, 0x40(%rdi)
// 90: 48 8b 07                      movq    (%rdi), %rax
// 93: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000095:  R_X86_64_64  _JIT_TARGET
// 9d: 89 c9                         movl    %ecx, %ecx
// 9f: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// a3: 48 05 c8 00 00 00             addq    $0xc8, %rax
// a9: c3                            retq
// aa: 
static const unsigned char _PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS_code_body[171] = {0x48, 0x89, 0xf0, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x41, 0xb8, 0xfe, 0xff, 0xff, 0xff, 0x41, 0x29, 0xc8, 0x4d, 0x63, 0xc0, 0x4e, 0x8b, 0x44, 0xc0, 0x08, 0x49, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x39, 0x48, 0x08, 0x75, 0x46, 0x49, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x39, 0x88, 0x88, 0x00, 0x00, 0x00, 0x75, 0x33, 0xf7, 0xd1, 0x48, 0x63, 0xc9, 0x4d, 0x8b, 0x40, 0x30, 0x49, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x0f, 0xb7, 0xc9, 0x48, 0x83, 0x7c, 0xc8, 0x08, 0x01, 0x41, 0x83, 0xd9, 0xff, 0x45, 0x39, 0x48, 0x34, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS_code_holes[7] = {
    {0x10, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyFunction_Type, 0x0},
    {0x3e, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x5a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x78, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x95, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS_data_holes[1];

// _PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 83 c3 08                   addq    $0x8, %rbx
// 19: f6 04 25 e8 ff ff ff 01       testb   $0x1, -0x18
// 21: 75 19                         jne     0x3c <_JIT_ENTRY+0x3c>
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  _PyObject_MakeInstanceAttributesFromDict
// 2d: 31 ff                         xorl    %edi, %edi
// 2f: 48 c7 c6 e8 ff ff ff          movq    $-0x18, %rsi
// 36: ff d0                         callq   *%rax
// 38: 84 c0                         testb   %al, %al
// 3a: 74 1a                         je      0x56 <_JIT_ENTRY+0x56>
// 3c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003e:  R_X86_64_64  _JIT_CONTINUE
// 46: 4c 89 f7                      movq    %r14, %rdi
// 49: 48 89 de                      movq    %rbx, %rsi
// 4c: 4c 89 fa                      movq    %r15, %rdx
// 4f: 5b                            popq    %rbx
// 50: 41 5e                         popq    %r14
// 52: 41 5f                         popq    %r15
// 54: ff e0                         jmpq    *%rax
// 56: 4c 29 f3                      subq    %r14, %rbx
// 59: 48 83 c3 b8                   addq    $-0x48, %rbx
// 5d: 48 c1 eb 03                   shrq    $0x3, %rbx
// 61: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 65: 49 8b 06                      movq    (%r14), %rax
// 68: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006a:  R_X86_64_64  _JIT_TARGET
// 72: 89 c9                         movl    %ecx, %ecx
// 74: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// 7c: 5b                            popq    %rbx
// 7d: 41 5e                         popq    %r14
// 7f: 41 5f                         popq    %r15
// 81: c3                            retq
// 82: 
static const unsigned char _PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES_code_body[131] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0xf6, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x01, 0x75, 0x19, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0x48, 0xc7, 0xc6, 0xe8, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x84, 0xc0, 0x74, 0x1a, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x49, 0x8b, 0x06, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES_code_holes[4] = {
    {0x25, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyObject_MakeInstanceAttributesFromDict, 0x0},
    {0x3e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES_data_holes[1];

// _PUSH_NULLplus_CHECK_PEP_523
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_PEP_523.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 42 10                   movq    0x10(%rdx), %rax
// f: 48 83 b8 20 08 00 00 00       cmpq    $0x0, 0x820(%rax)
// 17: 74 28                         je      0x41 <_JIT_ENTRY+0x41>
// 19: 48 29 fe                      subq    %rdi, %rsi
// 1c: 48 83 c6 b8                   addq    $-0x48, %rsi
// 20: 48 c1 ee 03                   shrq    $0x3, %rsi
// 24: 89 77 40                      movl    %esi, 0x40(%rdi)
// 27: 48 8b 07                      movq    (%rdi), %rax
// 2a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002c:  R_X86_64_64  _JIT_TARGET
// 34: 89 c9                         movl    %ecx, %ecx
// 36: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 3a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 40: c3                            retq
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _JIT_CONTINUE
// 4b: ff e0                         jmpq    *%rax
// 4d: 
static const unsigned char _PUSH_NULLplus_CHECK_PEP_523_code_body[78] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x42, 0x10, 0x48, 0x83, 0xb8, 0x20, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CHECK_PEP_523_code_holes[3] = {
    {0x2c, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_PEP_523_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_PEP_523_data_holes[1];

// _PUSH_NULLplus_CHECK_STACK_SPACE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_STACK_SPACE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 89 f0                      movq    %rsi, %rax
// 3: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// a: 48 83 c6 08                   addq    $0x8, %rsi
// e: 48 8b 8a 00 01 00 00          movq    0x100(%rdx), %rcx
// 15: 48 85 c9                      testq   %rcx, %rcx
// 18: 74 40                         je      0x5a <_JIT_ENTRY+0x5a>
// 1a: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 000000000000001c:  R_X86_64_64  _JIT_OPARG
// 24: 45 0f b7 c0                   movzwl  %r8w, %r8d
// 28: 41 b9 fe ff ff ff             movl    $0xfffffffe, %r9d       # imm = 0xFFFFFFFE
// 2e: 45 29 c1                      subl    %r8d, %r9d
// 31: 4d 63 c1                      movslq  %r9d, %r8
// 34: 4a 8b 44 c0 08                movq    0x8(%rax,%r8,8), %rax
// 39: 48 8b 40 30                   movq    0x30(%rax), %rax
// 3d: 48 63 40 4c                   movslq  0x4c(%rax), %rax
// 41: 4c 8b 82 08 01 00 00          movq    0x108(%rdx), %r8
// 48: 49 29 c8                      subq    %rcx, %r8
// 4b: 49 c1 f8 03                   sarq    $0x3, %r8
// 4f: 49 39 c0                      cmpq    %rax, %r8
// 52: 7e 06                         jle     0x5a <_JIT_ENTRY+0x5a>
// 54: 83 7a 24 02                   cmpl    $0x2, 0x24(%rdx)
// 58: 7d 28                         jge     0x82 <_JIT_ENTRY+0x82>
// 5a: 48 29 fe                      subq    %rdi, %rsi
// 5d: 48 83 c6 b8                   addq    $-0x48, %rsi
// 61: 48 c1 ee 03                   shrq    $0x3, %rsi
// 65: 89 77 40                      movl    %esi, 0x40(%rdi)
// 68: 48 8b 07                      movq    (%rdi), %rax
// 6b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006d:  R_X86_64_64  _JIT_TARGET
// 75: 89 c9                         movl    %ecx, %ecx
// 77: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 7b: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 81: c3                            retq
// 82: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000084:  R_X86_64_64  _JIT_CONTINUE
// 8c: ff e0                         jmpq    *%rax
// 8e: 
static const unsigned char _PUSH_NULLplus_CHECK_STACK_SPACE_code_body[143] = {0x48, 0x89, 0xf0, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x8a, 0x00, 0x01, 0x00, 0x00, 0x48, 0x85, 0xc9, 0x74, 0x40, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x0f, 0xb7, 0xc0, 0x41, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x45, 0x29, 0xc1, 0x4d, 0x63, 0xc1, 0x4a, 0x8b, 0x44, 0xc0, 0x08, 0x48, 0x8b, 0x40, 0x30, 0x48, 0x63, 0x40, 0x4c, 0x4c, 0x8b, 0x82, 0x08, 0x01, 0x00, 0x00, 0x49, 0x29, 0xc8, 0x49, 0xc1, 0xf8, 0x03, 0x49, 0x39, 0xc0, 0x7e, 0x06, 0x83, 0x7a, 0x24, 0x02, 0x7d, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_CHECK_STACK_SPACE_code_holes[4] = {
    {0x1c, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x6d, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x84, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_STACK_SPACE_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_STACK_SPACE_data_holes[1];

// _PUSH_NULLplus_CHECK_VALIDITY
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CHECK_VALIDITY.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_EXECUTOR
// 15: 80 78 22 00                   cmpb    $0x0, 0x22(%rax)
// 19: 74 0c                         je      0x27 <_JIT_ENTRY+0x27>
// 1b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001d:  R_X86_64_64  _JIT_CONTINUE
// 25: ff e0                         jmpq    *%rax
// 27: 48 29 fe                      subq    %rdi, %rsi
// 2a: 48 83 c6 b8                   addq    $-0x48, %rsi
// 2e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 32: 89 77 40                      movl    %esi, 0x40(%rdi)
// 35: 48 8b 07                      movq    (%rdi), %rax
// 38: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003a:  R_X86_64_64  _JIT_TARGET
// 42: 89 c9                         movl    %ecx, %ecx
// 44: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 48: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4e: c3                            retq
// 4f: 
static const unsigned char _PUSH_NULLplus_CHECK_VALIDITY_code_body[80] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x78, 0x22, 0x00, 0x74, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_CHECK_VALIDITY_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_EXECUTOR, NULL, 0x0},
    {0x1d, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_CHECK_VALIDITY_data_body[1];
static const Hole _PUSH_NULLplus_CHECK_VALIDITY_data_holes[1];

// _PUSH_NULLplus_COMPARE_OP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COMPARE_OP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  _JIT_OPARG
// 16: 0f b7 d0                      movzwl  %ax, %edx
// 19: c1 ea 05                      shrl    $0x5, %edx
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  PyObject_RichCompare
// 26: 48 89 df                      movq    %rbx, %rdi
// 29: 31 f6                         xorl    %esi, %esi
// 2b: ff d0                         callq   *%rax
// 2d: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 31: 7f 1e                         jg      0x51 <_JIT_ENTRY+0x51>
// 33: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000035:  R_X86_64_64  .rodata.str1.1
// 3d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003f:  R_X86_64_64  _Py_NegativeRefcount
// 47: be 38 07 00 00                movl    $0x738, %esi            # imm = 0x738
// 4c: 48 89 da                      movq    %rbx, %rdx
// 4f: ff d0                         callq   *%rax
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 5b: ff d0                         callq   *%rax
// 5d: 48 ff 0b                      decq    (%rbx)
// 60: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000062:  R_X86_64_64  _Py_Dealloc
// 6a: 48 89 df                      movq    %rbx, %rdi
// 6d: ff d0                         callq   *%rax
// 6f: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_code_body[112] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0xc1, 0xea, 0x05, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x38, 0x07, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_COMPARE_OP_code_holes[7] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_RichCompare, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_COMPARE_OP_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_COMPARE_OP_data_holes[1];

// _PUSH_NULLplus_COMPARE_OP_FLOAT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COMPARE_OP_FLOAT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyFloat_Type
// 16: 48 39 43 08                   cmpq    %rax, 0x8(%rbx)
// 1a: 75 0a                         jne     0x26 <_JIT_ENTRY+0x26>
// 1c: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 24: 74 29                         je      0x4f <_JIT_ENTRY+0x4f>
// 26: 48 29 fe                      subq    %rdi, %rsi
// 29: 48 83 c6 c0                   addq    $-0x40, %rsi
// 2d: 48 c1 ee 03                   shrq    $0x3, %rsi
// 31: 89 77 40                      movl    %esi, 0x40(%rdi)
// 34: 48 8b 07                      movq    (%rdi), %rax
// 37: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000039:  R_X86_64_64  _JIT_TARGET
// 41: 89 c9                         movl    %ecx, %ecx
// 43: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 47: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4d: 5b                            popq    %rbx
// 4e: c3                            retq
// 4f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000051:  R_X86_64_64  PyInterpreterState_Get
// 59: ff d0                         callq   *%rax
// 5b: 48 ff 88 c8 15 04 00          decq    0x415c8(%rax)
// 62: 48 ff 0b                      decq    (%rbx)
// 65: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000067:  R_X86_64_64  _PyFloat_ExactDealloc
// 6f: 48 89 df                      movq    %rbx, %rdi
// 72: ff d0                         callq   *%rax
// 74: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_FLOAT_code_body[117] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x43, 0x08, 0x75, 0x0a, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x88, 0xc8, 0x15, 0x04, 0x00, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_COMPARE_OP_FLOAT_code_holes[5] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyFloat_Type, 0x0},
    {0x39, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyInterpreterState_Get, 0x0},
    {0x67, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyFloat_ExactDealloc, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_FLOAT_data_body[1];
static const Hole _PUSH_NULLplus_COMPARE_OP_FLOAT_data_holes[1];

// _PUSH_NULLplus_COMPARE_OP_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COMPARE_OP_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyLong_Type
// 16: 48 39 43 08                   cmpq    %rax, 0x8(%rbx)
// 1a: 75 1c                         jne     0x38 <_JIT_ENTRY+0x38>
// 1c: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 24: 75 12                         jne     0x38 <_JIT_ENTRY+0x38>
// 26: 48 83 7b 10 0f                cmpq    $0xf, 0x10(%rbx)
// 2b: 77 0b                         ja      0x38 <_JIT_ENTRY+0x38>
// 2d: 48 83 3c 25 10 00 00 00 0f    cmpq    $0xf, 0x10
// 36: 76 29                         jbe     0x61 <_JIT_ENTRY+0x61>
// 38: 48 29 fe                      subq    %rdi, %rsi
// 3b: 48 83 c6 c0                   addq    $-0x40, %rsi
// 3f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 43: 89 77 40                      movl    %esi, 0x40(%rdi)
// 46: 48 8b 07                      movq    (%rdi), %rax
// 49: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004b:  R_X86_64_64  _JIT_TARGET
// 53: 89 c9                         movl    %ecx, %ecx
// 55: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 59: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 5f: 5b                            popq    %rbx
// 60: c3                            retq
// 61: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000063:  R_X86_64_64  PyInterpreterState_Get
// 6b: ff d0                         callq   *%rax
// 6d: 48 ff 88 c8 15 04 00          decq    0x415c8(%rax)
// 74: 48 ff 0b                      decq    (%rbx)
// 77: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000079:  R_X86_64_64  PyObject_Free
// 81: 48 89 df                      movq    %rbx, %rdi
// 84: ff d0                         callq   *%rax
// 86: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_INT_code_body[135] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x43, 0x08, 0x75, 0x1c, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x12, 0x48, 0x83, 0x7b, 0x10, 0x0f, 0x77, 0x0b, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x0f, 0x76, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x88, 0xc8, 0x15, 0x04, 0x00, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_COMPARE_OP_INT_code_holes[5] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x63, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyInterpreterState_Get, 0x0},
    {0x79, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Free, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_INT_data_body[1];
static const Hole _PUSH_NULLplus_COMPARE_OP_INT_data_holes[1];

// _PUSH_NULLplus_COMPARE_OP_STR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COMPARE_OP_STR.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyUnicode_Type
// 16: 48 39 43 08                   cmpq    %rax, 0x8(%rbx)
// 1a: 75 0a                         jne     0x26 <_JIT_ENTRY+0x26>
// 1c: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 24: 74 29                         je      0x4f <_JIT_ENTRY+0x4f>
// 26: 48 29 fe                      subq    %rdi, %rsi
// 29: 48 83 c6 c0                   addq    $-0x40, %rsi
// 2d: 48 c1 ee 03                   shrq    $0x3, %rsi
// 31: 89 77 40                      movl    %esi, 0x40(%rdi)
// 34: 48 8b 07                      movq    (%rdi), %rax
// 37: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000039:  R_X86_64_64  _JIT_TARGET
// 41: 89 c9                         movl    %ecx, %ecx
// 43: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 47: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4d: 5b                            popq    %rbx
// 4e: c3                            retq
// 4f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000051:  R_X86_64_64  _PyUnicode_Equal
// 59: 48 89 df                      movq    %rbx, %rdi
// 5c: 31 f6                         xorl    %esi, %esi
// 5e: ff d0                         callq   *%rax
// 60: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000062:  R_X86_64_64  PyInterpreterState_Get
// 6a: ff d0                         callq   *%rax
// 6c: 48 ff 88 c8 15 04 00          decq    0x415c8(%rax)
// 73: 48 ff 0b                      decq    (%rbx)
// 76: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000078:  R_X86_64_64  _PyUnicode_ExactDealloc
// 80: 48 89 df                      movq    %rbx, %rdi
// 83: ff d0                         callq   *%rax
// 85: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_STR_code_body[134] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x43, 0x08, 0x75, 0x0a, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x88, 0xc8, 0x15, 0x04, 0x00, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_COMPARE_OP_STR_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x39, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyUnicode_Equal, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyInterpreterState_Get, 0x0},
    {0x78, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyUnicode_ExactDealloc, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_COMPARE_OP_STR_data_body[1];
static const Hole _PUSH_NULLplus_COMPARE_OP_STR_data_holes[1];

// _PUSH_NULLplus_CONTAINS_OP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CONTAINS_OP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PySequence_Contains
// 16: 31 ff                         xorl    %edi, %edi
// 18: 48 89 de                      movq    %rbx, %rsi
// 1b: ff d0                         callq   *%rax
// 1d: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 21: 7f 1e                         jg      0x41 <_JIT_ENTRY+0x41>
// 23: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000025:  R_X86_64_64  .rodata.str1.1
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  _Py_NegativeRefcount
// 37: be a8 07 00 00                movl    $0x7a8, %esi            # imm = 0x7A8
// 3c: 48 89 da                      movq    %rbx, %rdx
// 3f: ff d0                         callq   *%rax
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4b: ff d0                         callq   *%rax
// 4d: 48 ff 0b                      decq    (%rbx)
// 50: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000052:  R_X86_64_64  _Py_Dealloc
// 5a: 48 89 df                      movq    %rbx, %rdi
// 5d: ff d0                         callq   *%rax
// 5f: 
static const unsigned char _PUSH_NULLplus_CONTAINS_OP_code_body[96] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0x48, 0x89, 0xde, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xa8, 0x07, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_CONTAINS_OP_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySequence_Contains, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x52, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_CONTAINS_OP_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CONTAINS_OP_data_holes[1];

// _PUSH_NULLplus_CONVERT_VALUE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_CONVERT_VALUE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  _JIT_OPARG
// 12: 0f b7 c0                      movzwl  %ax, %eax
// 15: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000017:  R_X86_64_64  .rodata
// 1f: 31 ff                         xorl    %edi, %edi
// 21: ff 14 c1                      callq   *(%rcx,%rax,8)
// 24: 
static const unsigned char _PUSH_NULLplus_CONVERT_VALUE_code_body[37] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0x14, 0xc1};
static const Hole _PUSH_NULLplus_CONVERT_VALUE_code_holes[3] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x17, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
};
// 0: '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
// 20: 
static const unsigned char _PUSH_NULLplus_CONVERT_VALUE_data_body[33] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_CONVERT_VALUE_data_holes[4] = {
    {0x8, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Str, 0x0},
    {0x10, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Repr, 0x0},
    {0x18, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_ASCII, 0x0},
};

// _PUSH_NULLplus_COPY
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COPY.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 48 c1 e0 03                   shlq    $0x3, %rax
// 29: 48 f7 d8                      negq    %rax
// 2c: 4c 8b 64 06 08                movq    0x8(%rsi,%rax), %r12
// 31: 41 8b 04 24                   movl    (%r12), %eax
// 35: ff c0                         incl    %eax
// 37: 74 10                         je      0x49 <_JIT_ENTRY+0x49>
// 39: 41 89 04 24                   movl    %eax, (%r12)
// 3d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003f:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 47: ff d0                         callq   *%rax
// 49: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 4d: 49 83 c6 10                   addq    $0x10, %r14
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: 4c 89 ff                      movq    %r15, %rdi
// 5e: 4c 89 f6                      movq    %r14, %rsi
// 61: 48 89 da                      movq    %rbx, %rdx
// 64: 48 83 c4 08                   addq    $0x8, %rsp
// 68: 5b                            popq    %rbx
// 69: 41 5c                         popq    %r12
// 6b: 41 5e                         popq    %r14
// 6d: 41 5f                         popq    %r15
// 6f: ff e0                         jmpq    *%rax
// 71: 
static const unsigned char _PUSH_NULLplus_COPY_code_body[114] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x48, 0xf7, 0xd8, 0x4c, 0x8b, 0x64, 0x06, 0x08, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_COPY_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_COPY_data_body[1];
static const Hole _PUSH_NULLplus_COPY_data_holes[1];

// _PUSH_NULLplus_COPY_FREE_VARS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_COPY_FREE_VARS.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 18                   subq    $0x18, %rsp
// e: 48 89 54 24 10                movq    %rdx, 0x10(%rsp)
// 13: 48 89 3c 24                   movq    %rdi, (%rsp)
// 17: 48 89 74 24 08                movq    %rsi, 0x8(%rsp)
// 1c: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  _JIT_OPARG
// 2d: 66 85 c0                      testw   %ax, %ax
// 30: 74 6f                         je      0xa1 <_JIT_ENTRY+0xa1>
// 32: 48 8b 14 24                   movq    (%rsp), %rdx
// 36: 48 8b 42 10                   movq    0x10(%rdx), %rax
// 3a: 4c 8b 60 48                   movq    0x48(%rax), %r12
// 3e: 48 8b 02                      movq    (%rdx), %rax
// 41: 8b 40 48                      movl    0x48(%rax), %eax
// 44: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000046:  R_X86_64_64  _JIT_OPARG
// 4e: 0f b7 c9                      movzwl  %cx, %ecx
// 51: 29 c8                         subl    %ecx, %eax
// 53: 83 f9 02                      cmpl    $0x2, %ecx
// 56: 41 bd 01 00 00 00             movl    $0x1, %r13d
// 5c: 44 0f 43 e9                   cmovael %ecx, %r13d
// 60: 48 98                         cltq
// 62: 48 8d 2c c2                   leaq    (%rdx,%rax,8), %rbp
// 66: 48 83 c5 48                   addq    $0x48, %rbp
// 6a: 31 db                         xorl    %ebx, %ebx
// 6c: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000006e:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 76: eb 15                         jmp     0x8d <_JIT_ENTRY+0x8d>
// 78: 0f 1f 84 00 00 00 00 00       nopl    (%rax,%rax)
// 80: 4c 89 74 dd 00                movq    %r14, (%rbp,%rbx,8)
// 85: 48 ff c3                      incq    %rbx
// 88: 49 39 dd                      cmpq    %rbx, %r13
// 8b: 74 14                         je      0xa1 <_JIT_ENTRY+0xa1>
// 8d: 4d 8b 74 dc 18                movq    0x18(%r12,%rbx,8), %r14
// 92: 41 8b 06                      movl    (%r14), %eax
// 95: ff c0                         incl    %eax
// 97: 74 e7                         je      0x80 <_JIT_ENTRY+0x80>
// 99: 41 89 06                      movl    %eax, (%r14)
// 9c: 41 ff d7                      callq   *%r15
// 9f: eb df                         jmp     0x80 <_JIT_ENTRY+0x80>
// a1: 48 8b 74 24 08                movq    0x8(%rsp), %rsi
// a6: 48 83 c6 08                   addq    $0x8, %rsi
// aa: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ac:  R_X86_64_64  _JIT_CONTINUE
// b4: 48 8b 3c 24                   movq    (%rsp), %rdi
// b8: 48 8b 54 24 10                movq    0x10(%rsp), %rdx
// bd: 48 83 c4 18                   addq    $0x18, %rsp
// c1: 5b                            popq    %rbx
// c2: 41 5c                         popq    %r12
// c4: 41 5d                         popq    %r13
// c6: 41 5e                         popq    %r14
// c8: 41 5f                         popq    %r15
// ca: 5d                            popq    %rbp
// cb: ff e0                         jmpq    *%rax
// cd: 
static const unsigned char _PUSH_NULLplus_COPY_FREE_VARS_code_body[206] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x18, 0x48, 0x89, 0x54, 0x24, 0x10, 0x48, 0x89, 0x3c, 0x24, 0x48, 0x89, 0x74, 0x24, 0x08, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x85, 0xc0, 0x74, 0x6f, 0x48, 0x8b, 0x14, 0x24, 0x48, 0x8b, 0x42, 0x10, 0x4c, 0x8b, 0x60, 0x48, 0x48, 0x8b, 0x02, 0x8b, 0x40, 0x48, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x29, 0xc8, 0x83, 0xf9, 0x02, 0x41, 0xbd, 0x01, 0x00, 0x00, 0x00, 0x44, 0x0f, 0x43, 0xe9, 0x48, 0x98, 0x48, 0x8d, 0x2c, 0xc2, 0x48, 0x83, 0xc5, 0x48, 0x31, 0xdb, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x15, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0x74, 0xdd, 0x00, 0x48, 0xff, 0xc3, 0x49, 0x39, 0xdd, 0x74, 0x14, 0x4d, 0x8b, 0x74, 0xdc, 0x18, 0x41, 0x8b, 0x06, 0xff, 0xc0, 0x74, 0xe7, 0x41, 0x89, 0x06, 0x41, 0xff, 0xd7, 0xeb, 0xdf, 0x48, 0x8b, 0x74, 0x24, 0x08, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3c, 0x24, 0x48, 0x8b, 0x54, 0x24, 0x10, 0x48, 0x83, 0xc4, 0x18, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_COPY_FREE_VARS_code_holes[5] = {
    {0x25, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x46, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x6e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0xac, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_COPY_FREE_VARS_data_body[1];
static const Hole _PUSH_NULLplus_COPY_FREE_VARS_data_holes[1];

// _PUSH_NULLplus_DELETE_ATTR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_ATTR.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 07                      movq    (%rdi), %rax
// b: 48 8b 40 20                   movq    0x20(%rax), %rax
// f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000011:  R_X86_64_64  _JIT_OPARG
// 19: 0f b7 c9                      movzwl  %cx, %ecx
// 1c: 48 8b 74 c8 18                movq    0x18(%rax,%rcx,8), %rsi
// 21: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000023:  R_X86_64_64  PyObject_DelAttr
// 2b: 31 ff                         xorl    %edi, %edi
// 2d: ff d0                         callq   *%rax
// 2f: 
static const unsigned char _PUSH_NULLplus_DELETE_ATTR_code_body[48] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x74, 0xc8, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_DELETE_ATTR_code_holes[3] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x23, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_DelAttr, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_DELETE_ATTR_data_body[1];
static const Hole _PUSH_NULLplus_DELETE_ATTR_data_holes[1];

// _PUSH_NULLplus_DELETE_DEREF
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_DEREF.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 83 c3 08                   addq    $0x8, %rbx
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPARG
// 26: 0f b7 c0                      movzwl  %ax, %eax
// 29: 48 8b 44 c7 48                movq    0x48(%rdi,%rax,8), %rax
// 2e: 4c 8b 60 10                   movq    0x10(%rax), %r12
// 32: 4d 85 e4                      testq   %r12, %r12
// 35: 74 1a                         je      0x51 <_JIT_ENTRY+0x51>
// 37: 48 c7 40 10 00 00 00 00       movq    $0x0, 0x10(%rax)
// 3f: 49 8b 04 24                   movq    (%r12), %rax
// 43: 48 85 c0                      testq   %rax, %rax
// 46: 7e 45                         jle     0x8d <_JIT_ENTRY+0x8d>
// 48: 85 c0                         testl   %eax, %eax
// 4a: 79 67                         jns     0xb3 <_JIT_ENTRY+0xb3>
// 4c: e9 83 00 00 00                jmp     0xd4 <_JIT_ENTRY+0xd4>
// 51: 49 8b 36                      movq    (%r14), %rsi
// 54: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000056:  R_X86_64_64  _JIT_OPARG
// 5e: 0f b7 d0                      movzwl  %ax, %edx
// 61: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000063:  R_X86_64_64  _PyEval_FormatExcUnbound
// 6b: 4c 89 ff                      movq    %r15, %rdi
// 6e: ff d0                         callq   *%rax
// 70: 4c 29 f3                      subq    %r14, %rbx
// 73: 48 83 c3 b8                   addq    $-0x48, %rbx
// 77: 48 c1 eb 03                   shrq    $0x3, %rbx
// 7b: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 7f: 31 c0                         xorl    %eax, %eax
// 81: 48 83 c4 08                   addq    $0x8, %rsp
// 85: 5b                            popq    %rbx
// 86: 41 5c                         popq    %r12
// 88: 41 5e                         popq    %r14
// 8a: 41 5f                         popq    %r15
// 8c: c3                            retq
// 8d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000008f:  R_X86_64_64  .rodata.str1.1
// 97: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000099:  R_X86_64_64  _Py_NegativeRefcount
// a1: be c4 04 00 00                movl    $0x4c4, %esi            # imm = 0x4C4
// a6: 4c 89 e2                      movq    %r12, %rdx
// a9: ff d0                         callq   *%rax
// ab: 49 8b 04 24                   movq    (%r12), %rax
// af: 85 c0                         testl   %eax, %eax
// b1: 78 21                         js      0xd4 <_JIT_ENTRY+0xd4>
// b3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b5:  R_X86_64_64  _Py_DECREF_DecRefTotal
// bd: ff d0                         callq   *%rax
// bf: 49 ff 0c 24                   decq    (%r12)
// c3: 75 0f                         jne     0xd4 <_JIT_ENTRY+0xd4>
// c5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c7:  R_X86_64_64  _Py_Dealloc
// cf: 4c 89 e7                      movq    %r12, %rdi
// d2: ff d0                         callq   *%rax
// d4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d6:  R_X86_64_64  _JIT_CONTINUE
// de: 4c 89 f7                      movq    %r14, %rdi
// e1: 48 89 de                      movq    %rbx, %rsi
// e4: 4c 89 fa                      movq    %r15, %rdx
// e7: 48 83 c4 08                   addq    $0x8, %rsp
// eb: 5b                            popq    %rbx
// ec: 41 5c                         popq    %r12
// ee: 41 5e                         popq    %r14
// f0: 41 5f                         popq    %r15
// f2: ff e0                         jmpq    *%rax
// f4: 
static const unsigned char _PUSH_NULLplus_DELETE_DEREF_code_body[245] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x44, 0xc7, 0x48, 0x4c, 0x8b, 0x60, 0x10, 0x4d, 0x85, 0xe4, 0x74, 0x1a, 0x48, 0xc7, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x45, 0x85, 0xc0, 0x79, 0x67, 0xe9, 0x83, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x36, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xc4, 0x04, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_DELETE_DEREF_code_holes[9] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x56, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x63, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcUnbound, 0x0},
    {0x8f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x99, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xb5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xc7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xd6, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_DELETE_DEREF_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_DELETE_DEREF_data_holes[1];

// _PUSH_NULLplus_DELETE_FAST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_FAST.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 83 c3 08                   addq    $0x8, %rbx
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPARG
// 26: 0f b7 c0                      movzwl  %ax, %eax
// 29: 4c 8b 64 c7 48                movq    0x48(%rdi,%rax,8), %r12
// 2e: 4d 85 e4                      testq   %r12, %r12
// 31: 74 2c                         je      0x5f <_JIT_ENTRY+0x5f>
// 33: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000035:  R_X86_64_64  _JIT_OPARG
// 3d: 0f b7 c0                      movzwl  %ax, %eax
// 40: 49 c7 44 c6 48 00 00 00 00    movq    $0x0, 0x48(%r14,%rax,8)
// 49: 49 8b 04 24                   movq    (%r12), %rax
// 4d: 48 85 c0                      testq   %rax, %rax
// 50: 7e 77                         jle     0xc9 <_JIT_ENTRY+0xc9>
// 52: 85 c0                         testl   %eax, %eax
// 54: 0f 89 95 00 00 00             jns     0xef <_JIT_ENTRY+0xef>
// 5a: e9 b1 00 00 00                jmp     0x110 <_JIT_ENTRY+0x110>
// 5f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000061:  R_X86_64_64  PyExc_UnboundLocalError
// 69: 4c 8b 20                      movq    (%rax), %r12
// 6c: 49 8b 06                      movq    (%r14), %rax
// 6f: 48 8b 78 60                   movq    0x60(%rax), %rdi
// 73: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000075:  R_X86_64_64  _JIT_OPARG
// 7d: 0f b7 f0                      movzwl  %ax, %esi
// 80: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000082:  R_X86_64_64  PyTuple_GetItem
// 8a: ff d0                         callq   *%rax
// 8c: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000008e:  R_X86_64_64  .rodata.str1.1
// 96: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000098:  R_X86_64_64  _PyEval_FormatExcCheckArg
// a0: 4c 89 ff                      movq    %r15, %rdi
// a3: 4c 89 e6                      movq    %r12, %rsi
// a6: 48 89 c1                      movq    %rax, %rcx
// a9: 41 ff d0                      callq   *%r8
// ac: 4c 29 f3                      subq    %r14, %rbx
// af: 48 83 c3 b8                   addq    $-0x48, %rbx
// b3: 48 c1 eb 03                   shrq    $0x3, %rbx
// b7: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// bb: 31 c0                         xorl    %eax, %eax
// bd: 48 83 c4 08                   addq    $0x8, %rsp
// c1: 5b                            popq    %rbx
// c2: 41 5c                         popq    %r12
// c4: 41 5e                         popq    %r14
// c6: 41 5f                         popq    %r15
// c8: c3                            retq
// c9: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000cb:  R_X86_64_64  .rodata.str1.1+0x4a
// d3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d5:  R_X86_64_64  _Py_NegativeRefcount
// dd: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// e2: 4c 89 e2                      movq    %r12, %rdx
// e5: ff d0                         callq   *%rax
// e7: 49 8b 04 24                   movq    (%r12), %rax
// eb: 85 c0                         testl   %eax, %eax
// ed: 78 21                         js      0x110 <_JIT_ENTRY+0x110>
// ef: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f1:  R_X86_64_64  _Py_DECREF_DecRefTotal
// f9: ff d0                         callq   *%rax
// fb: 49 ff 0c 24                   decq    (%r12)
// ff: 75 0f                         jne     0x110 <_JIT_ENTRY+0x110>
// 101: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000103:  R_X86_64_64  _Py_Dealloc
// 10b: 4c 89 e7                      movq    %r12, %rdi
// 10e: ff d0                         callq   *%rax
// 110: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000112:  R_X86_64_64  _JIT_CONTINUE
// 11a: 4c 89 f7                      movq    %r14, %rdi
// 11d: 48 89 de                      movq    %rbx, %rsi
// 120: 4c 89 fa                      movq    %r15, %rdx
// 123: 48 83 c4 08                   addq    $0x8, %rsp
// 127: 5b                            popq    %rbx
// 128: 41 5c                         popq    %r12
// 12a: 41 5e                         popq    %r14
// 12c: 41 5f                         popq    %r15
// 12e: ff e0                         jmpq    *%rax
// 130: 
static const unsigned char _PUSH_NULLplus_DELETE_FAST_code_body[305] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x4c, 0x8b, 0x64, 0xc7, 0x48, 0x4d, 0x85, 0xe4, 0x74, 0x2c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x49, 0xc7, 0x44, 0xc6, 0x48, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x77, 0x85, 0xc0, 0x0f, 0x89, 0x95, 0x00, 0x00, 0x00, 0xe9, 0xb1, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x20, 0x49, 0x8b, 0x06, 0x48, 0x8b, 0x78, 0x60, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe6, 0x48, 0x89, 0xc1, 0x41, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_DELETE_FAST_code_holes[13] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x61, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_UnboundLocalError, 0x0},
    {0x75, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x82, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_GetItem, 0x0},
    {0x8e, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x98, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
    {0xcb, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x4a},
    {0xd5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xf1, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x103, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x112, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: "cannot access local variable '%s' where it is not associated with a value\x00/home/jglass/Documents/cpython/Include/object.h\x00"
// 7a: 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_DELETE_FAST_data_body[129] = {0x63, 0x61, 0x6e, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x20, 0x76, 0x61, 0x72, 0x69, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x27, 0x25, 0x73, 0x27, 0x20, 0x77, 0x68, 0x65, 0x72, 0x65, 0x20, 0x69, 0x74, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x73, 0x73, 0x6f, 0x63, 0x69, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x00, 0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_DELETE_FAST_data_holes[1];

// _PUSH_NULLplus_DELETE_GLOBAL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_GLOBAL.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 83 c3 08                   addq    $0x8, %rbx
// 1c: 48 8b 07                      movq    (%rdi), %rax
// 1f: 48 8b 7f 18                   movq    0x18(%rdi), %rdi
// 23: 48 8b 40 20                   movq    0x20(%rax), %rax
// 27: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000029:  R_X86_64_64  _JIT_OPARG
// 31: 0f b7 c9                      movzwl  %cx, %ecx
// 34: 4c 8b 64 c8 18                movq    0x18(%rax,%rcx,8), %r12
// 39: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003b:  R_X86_64_64  PyDict_DelItem
// 43: 4c 89 e6                      movq    %r12, %rsi
// 46: ff d0                         callq   *%rax
// 48: 85 c0                         testl   %eax, %eax
// 4a: 74 66                         je      0xb2 <_JIT_ENTRY+0xb2>
// 4c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004e:  R_X86_64_64  PyExc_KeyError
// 56: 48 8b 30                      movq    (%rax), %rsi
// 59: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005b:  R_X86_64_64  _PyErr_ExceptionMatches
// 63: 4c 89 ff                      movq    %r15, %rdi
// 66: ff d0                         callq   *%rax
// 68: 85 c0                         testl   %eax, %eax
// 6a: 74 29                         je      0x95 <_JIT_ENTRY+0x95>
// 6c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006e:  R_X86_64_64  PyExc_NameError
// 76: 48 8b 30                      movq    (%rax), %rsi
// 79: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000007b:  R_X86_64_64  .rodata.str1.1
// 83: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000085:  R_X86_64_64  _PyEval_FormatExcCheckArg
// 8d: 4c 89 ff                      movq    %r15, %rdi
// 90: 4c 89 e1                      movq    %r12, %rcx
// 93: ff d0                         callq   *%rax
// 95: 4c 29 f3                      subq    %r14, %rbx
// 98: 48 83 c3 b8                   addq    $-0x48, %rbx
// 9c: 48 c1 eb 03                   shrq    $0x3, %rbx
// a0: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// a4: 31 c0                         xorl    %eax, %eax
// a6: 48 83 c4 08                   addq    $0x8, %rsp
// aa: 5b                            popq    %rbx
// ab: 41 5c                         popq    %r12
// ad: 41 5e                         popq    %r14
// af: 41 5f                         popq    %r15
// b1: c3                            retq
// b2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b4:  R_X86_64_64  _JIT_CONTINUE
// bc: 4c 89 f7                      movq    %r14, %rdi
// bf: 48 89 de                      movq    %rbx, %rsi
// c2: 4c 89 fa                      movq    %r15, %rdx
// c5: 48 83 c4 08                   addq    $0x8, %rsp
// c9: 5b                            popq    %rbx
// ca: 41 5c                         popq    %r12
// cc: 41 5e                         popq    %r14
// ce: 41 5f                         popq    %r15
// d0: ff e0                         jmpq    *%rax
// d2: 
static const unsigned char _PUSH_NULLplus_DELETE_GLOBAL_code_body[211] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x7f, 0x18, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4c, 0x8b, 0x64, 0xc8, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe6, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x66, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x29, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe1, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_DELETE_GLOBAL_code_holes[9] = {
    {0x29, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3b, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_DelItem, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_KeyError, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_ExceptionMatches, 0x0},
    {0x6e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x7b, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x85, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
    {0xb4, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: "name '%.200s' is not defined\x00"
// 1d: 00 00 00
static const unsigned char _PUSH_NULLplus_DELETE_GLOBAL_data_body[33] = {0x6e, 0x61, 0x6d, 0x65, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_DELETE_GLOBAL_data_holes[1];

// _PUSH_NULLplus_DELETE_NAME
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_NAME.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 83 c3 08                   addq    $0x8, %rbx
// 1c: 48 8b 07                      movq    (%rdi), %rax
// 1f: 48 8b 7f 28                   movq    0x28(%rdi), %rdi
// 23: 48 8b 40 20                   movq    0x20(%rax), %rax
// 27: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000029:  R_X86_64_64  _JIT_OPARG
// 31: 0f b7 c9                      movzwl  %cx, %ecx
// 34: 4c 8b 64 c8 18                movq    0x18(%rax,%rcx,8), %r12
// 39: 48 85 ff                      testq   %rdi, %rdi
// 3c: 74 3e                         je      0x7c <_JIT_ENTRY+0x7c>
// 3e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000040:  R_X86_64_64  PyObject_DelItem
// 48: 4c 89 e6                      movq    %r12, %rsi
// 4b: ff d0                         callq   *%rax
// 4d: 85 c0                         testl   %eax, %eax
// 4f: 74 74                         je      0xc5 <_JIT_ENTRY+0xc5>
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  PyExc_NameError
// 5b: 48 8b 30                      movq    (%rax), %rsi
// 5e: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000060:  R_X86_64_64  .rodata.str1.1+0x1b
// 68: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006a:  R_X86_64_64  _PyEval_FormatExcCheckArg
// 72: 4c 89 ff                      movq    %r15, %rdi
// 75: 4c 89 e1                      movq    %r12, %rcx
// 78: ff d0                         callq   *%rax
// 7a: eb 2c                         jmp     0xa8 <_JIT_ENTRY+0xa8>
// 7c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007e:  R_X86_64_64  PyExc_SystemError
// 86: 48 8b 30                      movq    (%rax), %rsi
// 89: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000008b:  R_X86_64_64  .rodata.str1.1
// 93: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000095:  R_X86_64_64  _PyErr_Format
// 9d: 4c 89 ff                      movq    %r15, %rdi
// a0: 4c 89 e1                      movq    %r12, %rcx
// a3: 31 c0                         xorl    %eax, %eax
// a5: 41 ff d0                      callq   *%r8
// a8: 4c 29 f3                      subq    %r14, %rbx
// ab: 48 83 c3 b8                   addq    $-0x48, %rbx
// af: 48 c1 eb 03                   shrq    $0x3, %rbx
// b3: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// b7: 31 c0                         xorl    %eax, %eax
// b9: 48 83 c4 08                   addq    $0x8, %rsp
// bd: 5b                            popq    %rbx
// be: 41 5c                         popq    %r12
// c0: 41 5e                         popq    %r14
// c2: 41 5f                         popq    %r15
// c4: c3                            retq
// c5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c7:  R_X86_64_64  _JIT_CONTINUE
// cf: 4c 89 f7                      movq    %r14, %rdi
// d2: 48 89 de                      movq    %rbx, %rsi
// d5: 4c 89 fa                      movq    %r15, %rdx
// d8: 48 83 c4 08                   addq    $0x8, %rsp
// dc: 5b                            popq    %rbx
// dd: 41 5c                         popq    %r12
// df: 41 5e                         popq    %r14
// e1: 41 5f                         popq    %r15
// e3: ff e0                         jmpq    *%rax
// e5: 
static const unsigned char _PUSH_NULLplus_DELETE_NAME_code_body[230] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x7f, 0x28, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4c, 0x8b, 0x64, 0xc8, 0x18, 0x48, 0x85, 0xff, 0x74, 0x3e, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe6, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x74, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe1, 0xff, 0xd0, 0xeb, 0x2c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe1, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_DELETE_NAME_code_holes[10] = {
    {0x29, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x40, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_DelItem, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x1b},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
    {0x7e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0x8b, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x95, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0xc7, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: "no locals when deleting %R\x00name '%.200s' is not defined\x00"
// 38: 
static const unsigned char _PUSH_NULLplus_DELETE_NAME_data_body[57] = {0x6e, 0x6f, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x73, 0x20, 0x77, 0x68, 0x65, 0x6e, 0x20, 0x64, 0x65, 0x6c, 0x65, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x25, 0x52, 0x00, 0x6e, 0x61, 0x6d, 0x65, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x00};
static const Hole _PUSH_NULLplus_DELETE_NAME_data_holes[1];

// _PUSH_NULLplus_DELETE_SUBSCR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DELETE_SUBSCR.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyObject_DelItem
// 16: 48 89 df                      movq    %rbx, %rdi
// 19: 31 f6                         xorl    %esi, %esi
// 1b: ff d0                         callq   *%rax
// 1d: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 21: 7f 1e                         jg      0x41 <_JIT_ENTRY+0x41>
// 23: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000025:  R_X86_64_64  .rodata.str1.1
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  _Py_NegativeRefcount
// 37: be 70 02 00 00                movl    $0x270, %esi            # imm = 0x270
// 3c: 48 89 da                      movq    %rbx, %rdx
// 3f: ff d0                         callq   *%rax
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4b: ff d0                         callq   *%rax
// 4d: 48 ff 0b                      decq    (%rbx)
// 50: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000052:  R_X86_64_64  _Py_Dealloc
// 5a: 48 89 df                      movq    %rbx, %rdi
// 5d: ff d0                         callq   *%rax
// 5f: 
static const unsigned char _PUSH_NULLplus_DELETE_SUBSCR_code_body[96] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x70, 0x02, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_DELETE_SUBSCR_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_DelItem, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x52, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_DELETE_SUBSCR_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_DELETE_SUBSCR_data_holes[1];

// _PUSH_NULLplus_DICT_MERGE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DICT_MERGE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 56                         pushq   %r14
// 2: 53                            pushq   %rbx
// 3: 50                            pushq   %rax
// 4: 48 89 d3                      movq    %rdx, %rbx
// 7: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000010:  R_X86_64_64  _JIT_OPARG
// 18: 0f b7 c0                      movzwl  %ax, %eax
// 1b: b9 fc ff ff ff                movl    $0xfffffffc, %ecx       # imm = 0xFFFFFFFC
// 20: 29 c1                         subl    %eax, %ecx
// 22: f7 d0                         notl    %eax
// 24: 48 98                         cltq
// 26: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 2b: 48 63 c1                      movslq  %ecx, %rax
// 2e: 4c 8b 74 c6 08                movq    0x8(%rsi,%rax,8), %r14
// 33: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000035:  R_X86_64_64  _PyDict_MergeEx
// 3d: 31 f6                         xorl    %esi, %esi
// 3f: ba 02 00 00 00                movl    $0x2, %edx
// 44: ff d0                         callq   *%rax
// 46: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000048:  R_X86_64_64  _PyEval_FormatKwargsError
// 50: 48 89 df                      movq    %rbx, %rdi
// 53: 4c 89 f6                      movq    %r14, %rsi
// 56: 31 d2                         xorl    %edx, %edx
// 58: ff d0                         callq   *%rax
// 5a: 
static const unsigned char _PUSH_NULLplus_DICT_MERGE_code_body[91] = {0x41, 0x56, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfc, 0xff, 0xff, 0xff, 0x29, 0xc1, 0xf7, 0xd0, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0x63, 0xc1, 0x4c, 0x8b, 0x74, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xba, 0x02, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x31, 0xd2, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_DICT_MERGE_code_holes[4] = {
    {0x10, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_MergeEx, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatKwargsError, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_DICT_MERGE_data_body[1];
static const Hole _PUSH_NULLplus_DICT_MERGE_data_holes[1];

// _PUSH_NULLplus_DICT_UPDATE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_DICT_UPDATE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 89 d3                      movq    %rdx, %rbx
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_OPARG
// 15: f7 d0                         notl    %eax
// 17: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 1c: 48 98                         cltq
// 1e: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  PyDict_Update
// 2d: 31 f6                         xorl    %esi, %esi
// 2f: ff d0                         callq   *%rax
// 31: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000033:  R_X86_64_64  PyExc_AttributeError
// 3b: 48 8b 30                      movq    (%rax), %rsi
// 3e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000040:  R_X86_64_64  _PyErr_ExceptionMatches
// 48: 48 89 df                      movq    %rbx, %rdi
// 4b: ff d0                         callq   *%rax
// 4d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004f:  R_X86_64_64  PyExc_TypeError
// 57: 48 8b 30                      movq    (%rax), %rsi
// 5a: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 62: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 66: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000068:  R_X86_64_64  .rodata.str1.1
// 70: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000072:  R_X86_64_64  _PyErr_Format
// 7a: 48 89 df                      movq    %rbx, %rdi
// 7d: 31 c0                         xorl    %eax, %eax
// 7f: 41 ff d0                      callq   *%r8
// 82: 
static const unsigned char _PUSH_NULLplus_DICT_UPDATE_code_body[131] = {0x53, 0x48, 0x89, 0xd3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xc0, 0x41, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_DICT_UPDATE_code_holes[8] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Update, 0x0},
    {0x33, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_AttributeError, 0x0},
    {0x40, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_ExceptionMatches, 0x0},
    {0x4f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x68, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x72, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
};
// 0: "'%.200s' object is not a mapping\x00"
// 21: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_DICT_UPDATE_data_body[41] = {0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x20, 0x6d, 0x61, 0x70, 0x70, 0x69, 0x6e, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_DICT_UPDATE_data_holes[1];

// _PUSH_NULLplus_END_SEND
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_END_SEND.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 4c 8b 66 f8                   movq    -0x8(%rsi), %r12
// 1c: 49 8b 04 24                   movq    (%r12), %rax
// 20: 48 85 c0                      testq   %rax, %rax
// 23: 7e 06                         jle     0x2b <_JIT_ENTRY+0x2b>
// 25: 85 c0                         testl   %eax, %eax
// 27: 79 28                         jns     0x51 <_JIT_ENTRY+0x51>
// 29: eb 47                         jmp     0x72 <_JIT_ENTRY+0x72>
// 2b: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000002d:  R_X86_64_64  .rodata.str1.1
// 35: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000037:  R_X86_64_64  _Py_NegativeRefcount
// 3f: be 66 00 00 00                movl    $0x66, %esi
// 44: 4c 89 e2                      movq    %r12, %rdx
// 47: ff d0                         callq   *%rax
// 49: 49 8b 04 24                   movq    (%r12), %rax
// 4d: 85 c0                         testl   %eax, %eax
// 4f: 78 21                         js      0x72 <_JIT_ENTRY+0x72>
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 5b: ff d0                         callq   *%rax
// 5d: 49 ff 0c 24                   decq    (%r12)
// 61: 75 0f                         jne     0x72 <_JIT_ENTRY+0x72>
// 63: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000065:  R_X86_64_64  _Py_Dealloc
// 6d: 4c 89 e7                      movq    %r12, %rdi
// 70: ff d0                         callq   *%rax
// 72: 49 c7 46 f8 00 00 00 00       movq    $0x0, -0x8(%r14)
// 7a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007c:  R_X86_64_64  _JIT_CONTINUE
// 84: 4c 89 ff                      movq    %r15, %rdi
// 87: 4c 89 f6                      movq    %r14, %rsi
// 8a: 48 89 da                      movq    %rbx, %rdx
// 8d: 48 83 c4 08                   addq    $0x8, %rsp
// 91: 5b                            popq    %rbx
// 92: 41 5c                         popq    %r12
// 94: 41 5e                         popq    %r14
// 96: 41 5f                         popq    %r15
// 98: ff e0                         jmpq    *%rax
// 9a: 
static const unsigned char _PUSH_NULLplus_END_SEND_code_body[155] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x66, 0xf8, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x66, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x49, 0xc7, 0x46, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_END_SEND_code_holes[6] = {
    {0x2d, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x37, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x65, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x7c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_END_SEND_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_END_SEND_data_holes[1];

// _PUSH_NULLplus_EXIT_INIT_CHECK
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_EXIT_INIT_CHECK.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 56                         pushq   %r14
// 2: 53                            pushq   %rbx
// 3: 50                            pushq   %rax
// 4: 48 89 f3                      movq    %rsi, %rbx
// 7: 49 89 fe                      movq    %rdi, %r14
// a: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 11: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000013:  R_X86_64_64  PyExc_TypeError
// 1b: 48 8b 38                      movq    (%rax), %rdi
// 1e: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 26: 48 8b 50 18                   movq    0x18(%rax), %rdx
// 2a: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 000000000000002c:  R_X86_64_64  .rodata.str1.1
// 34: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000036:  R_X86_64_64  PyErr_Format
// 3e: 31 c0                         xorl    %eax, %eax
// 40: ff d1                         callq   *%rcx
// 42: 4c 29 f3                      subq    %r14, %rbx
// 45: 48 83 c3 c0                   addq    $-0x40, %rbx
// 49: 48 c1 eb 03                   shrq    $0x3, %rbx
// 4d: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 51: 31 c0                         xorl    %eax, %eax
// 53: 48 83 c4 08                   addq    $0x8, %rsp
// 57: 5b                            popq    %rbx
// 58: 41 5e                         popq    %r14
// 5a: c3                            retq
// 5b: 
static const unsigned char _PUSH_NULLplus_EXIT_INIT_CHECK_code_body[92] = {0x41, 0x56, 0x53, 0x50, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x38, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x50, 0x18, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xff, 0xd1, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5e, 0xc3};
static const Hole _PUSH_NULLplus_EXIT_INIT_CHECK_code_holes[4] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x2c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x36, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyErr_Format, 0x0},
};
// 0: "__init__() should return None, not '%.200s'\x00"
// 2c: 00 00 00 00
static const unsigned char _PUSH_NULLplus_EXIT_INIT_CHECK_data_body[49] = {0x5f, 0x5f, 0x69, 0x6e, 0x69, 0x74, 0x5f, 0x5f, 0x28, 0x29, 0x20, 0x73, 0x68, 0x6f, 0x75, 0x6c, 0x64, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x4e, 0x6f, 0x6e, 0x65, 0x2c, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_EXIT_INIT_CHECK_data_holes[1];

// _PUSH_NULLplus_EXIT_TRACE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_EXIT_TRACE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_EXIT_TRACE_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_EXIT_TRACE_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_EXIT_TRACE_data_body[1];
static const Hole _PUSH_NULLplus_EXIT_TRACE_data_holes[1];

// _PUSH_NULLplus_FORMAT_SIMPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_FORMAT_SIMPLE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyUnicode_Type
// 12: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1a: 75 11                         jne     0x2d <_JIT_ENTRY+0x2d>
// 1c: 48 83 c6 08                   addq    $0x8, %rsi
// 20: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000022:  R_X86_64_64  _JIT_CONTINUE
// 2a: 59                            popq    %rcx
// 2b: ff e0                         jmpq    *%rax
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  PyObject_Format
// 37: 31 ff                         xorl    %edi, %edi
// 39: 31 f6                         xorl    %esi, %esi
// 3b: ff d0                         callq   *%rax
// 3d: 
static const unsigned char _PUSH_NULLplus_FORMAT_SIMPLE_code_body[62] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x11, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_FORMAT_SIMPLE_code_holes[4] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Format, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_FORMAT_SIMPLE_data_body[1];
static const Hole _PUSH_NULLplus_FORMAT_SIMPLE_data_holes[1];

// _PUSH_NULLplus_FORMAT_WITH_SPEC
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_FORMAT_WITH_SPEC.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyObject_Format
// 16: 48 89 df                      movq    %rbx, %rdi
// 19: 31 f6                         xorl    %esi, %esi
// 1b: ff d0                         callq   *%rax
// 1d: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 21: 7f 1e                         jg      0x41 <_JIT_ENTRY+0x41>
// 23: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000025:  R_X86_64_64  .rodata.str1.1
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  _Py_NegativeRefcount
// 37: be b7 0c 00 00                movl    $0xcb7, %esi            # imm = 0xCB7
// 3c: 48 89 da                      movq    %rbx, %rdx
// 3f: ff d0                         callq   *%rax
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4b: ff d0                         callq   *%rax
// 4d: 48 ff 0b                      decq    (%rbx)
// 50: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000052:  R_X86_64_64  _Py_Dealloc
// 5a: 48 89 df                      movq    %rbx, %rdi
// 5d: ff d0                         callq   *%rax
// 5f: 
static const unsigned char _PUSH_NULLplus_FORMAT_WITH_SPEC_code_body[96] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xb7, 0x0c, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_FORMAT_WITH_SPEC_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Format, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x52, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_FORMAT_WITH_SPEC_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_FORMAT_WITH_SPEC_data_holes[1];

// _PUSH_NULLplus_FOR_ITER_TIER_TWO
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_FOR_ITER_TIER_TWO.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 1d: 31 ff                         xorl    %edi, %edi
// 1f: ff 90 e0 00 00 00             callq   *0xe0(%rax)
// 25: 48 85 c0                      testq   %rax, %rax
// 28: 74 22                         je      0x4c <_JIT_ENTRY+0x4c>
// 2a: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 2e: 48 83 c3 10                   addq    $0x10, %rbx
// 32: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000034:  R_X86_64_64  _JIT_CONTINUE
// 3c: 4c 89 f7                      movq    %r14, %rdi
// 3f: 48 89 de                      movq    %rbx, %rsi
// 42: 4c 89 fa                      movq    %r15, %rdx
// 45: 5b                            popq    %rbx
// 46: 41 5e                         popq    %r14
// 48: 41 5f                         popq    %r15
// 4a: ff e0                         jmpq    *%rax
// 4c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004e:  R_X86_64_64  PyExc_StopIteration
// 56: 48 8b 30                      movq    (%rax), %rsi
// 59: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005b:  R_X86_64_64  _PyErr_ExceptionMatches
// 63: 4c 89 ff                      movq    %r15, %rdi
// 66: ff d0                         callq   *%rax
// 68: 85 c0                         testl   %eax, %eax
// 6a: 75 1b                         jne     0x87 <_JIT_ENTRY+0x87>
// 6c: 48 83 c3 08                   addq    $0x8, %rbx
// 70: 4c 29 f3                      subq    %r14, %rbx
// 73: 48 83 c3 b8                   addq    $-0x48, %rbx
// 77: 48 c1 eb 03                   shrq    $0x3, %rbx
// 7b: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 7f: 31 c0                         xorl    %eax, %eax
// 81: 5b                            popq    %rbx
// 82: 41 5e                         popq    %r14
// 84: 41 5f                         popq    %r15
// 86: c3                            retq
// 87: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000089:  R_X86_64_64  _PyErr_Clear
// 91: 4c 89 ff                      movq    %r15, %rdi
// 94: ff d0                         callq   *%rax
// 96: 
static const unsigned char _PUSH_NULLplus_FOR_ITER_TIER_TWO_code_body[151] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0x90, 0xe0, 0x00, 0x00, 0x00, 0x48, 0x85, 0xc0, 0x74, 0x22, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x85, 0xc0, 0x75, 0x1b, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_FOR_ITER_TIER_TWO_code_holes[5] = {
    {0x34, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_StopIteration, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_ExceptionMatches, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Clear, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_FOR_ITER_TIER_TWO_data_body[1];
static const Hole _PUSH_NULLplus_FOR_ITER_TIER_TWO_data_holes[1];

// _PUSH_NULLplus_GET_AITER
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_AITER.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 10: 48 8b 48 50                   movq    0x50(%rax), %rcx
// 14: 48 85 c9                      testq   %rcx, %rcx
// 17: 74 0d                         je      0x26 <_JIT_ENTRY+0x26>
// 19: 48 8b 49 08                   movq    0x8(%rcx), %rcx
// 1d: 48 85 c9                      testq   %rcx, %rcx
// 20: 74 04                         je      0x26 <_JIT_ENTRY+0x26>
// 22: 31 ff                         xorl    %edi, %edi
// 24: ff d1                         callq   *%rcx
// 26: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000028:  R_X86_64_64  PyExc_TypeError
// 30: 48 8b 31                      movq    (%rcx), %rsi
// 33: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 37: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000039:  R_X86_64_64  .rodata.str1.1
// 41: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000043:  R_X86_64_64  _PyErr_Format
// 4b: 48 89 d7                      movq    %rdx, %rdi
// 4e: 48 89 c2                      movq    %rax, %rdx
// 51: 31 c0                         xorl    %eax, %eax
// 53: 41 ff d0                      callq   *%r8
// 56: 
static const unsigned char _PUSH_NULLplus_GET_AITER_code_body[87] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x50, 0x48, 0x85, 0xc9, 0x74, 0x0d, 0x48, 0x8b, 0x49, 0x08, 0x48, 0x85, 0xc9, 0x74, 0x04, 0x31, 0xff, 0xff, 0xd1, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x31, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0xc2, 0x31, 0xc0, 0x41, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_GET_AITER_code_holes[4] = {
    {0x28, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x39, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
};
// 0: "'async for' requires an object with __aiter__ method, got %.100s\x00"
// 41: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_GET_AITER_data_body[73] = {0x27, 0x61, 0x73, 0x79, 0x6e, 0x63, 0x20, 0x66, 0x6f, 0x72, 0x27, 0x20, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x73, 0x20, 0x61, 0x6e, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x5f, 0x5f, 0x61, 0x69, 0x74, 0x65, 0x72, 0x5f, 0x5f, 0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x2c, 0x20, 0x67, 0x6f, 0x74, 0x20, 0x25, 0x2e, 0x31, 0x30, 0x30, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_GET_AITER_data_holes[1];

// _PUSH_NULLplus_GET_ANEXT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_ANEXT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 49 89 d7                      movq    %rdx, %r15
// c: 48 89 f3                      movq    %rsi, %rbx
// f: 49 89 fe                      movq    %rdi, %r14
// 12: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 19: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 21: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000023:  R_X86_64_64  PyAsyncGen_Type
// 2b: 48 39 c8                      cmpq    %rcx, %rax
// 2e: 0f 84 c5 00 00 00             je      0xf9 <_JIT_ENTRY+0xf9>
// 34: 48 8b 48 50                   movq    0x50(%rax), %rcx
// 38: 48 85 c9                      testq   %rcx, %rcx
// 3b: 0f 84 86 00 00 00             je      0xc7 <_JIT_ENTRY+0xc7>
// 41: 48 8b 49 10                   movq    0x10(%rcx), %rcx
// 45: 48 85 c9                      testq   %rcx, %rcx
// 48: 74 7d                         je      0xc7 <_JIT_ENTRY+0xc7>
// 4a: 31 ff                         xorl    %edi, %edi
// 4c: ff d1                         callq   *%rcx
// 4e: 48 85 c0                      testq   %rax, %rax
// 51: 0f 84 5b 01 00 00             je      0x1b2 <_JIT_ENTRY+0x1b2>
// 57: 49 89 c4                      movq    %rax, %r12
// 5a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005c:  R_X86_64_64  _PyCoro_GetAwaitableIter
// 64: 4c 89 e7                      movq    %r12, %rdi
// 67: ff d0                         callq   *%rax
// 69: 48 85 c0                      testq   %rax, %rax
// 6c: 0f 84 c2 00 00 00             je      0x134 <_JIT_ENTRY+0x134>
// 72: 49 89 c5                      movq    %rax, %r13
// 75: 49 8b 04 24                   movq    (%r12), %rax
// 79: 48 85 c0                      testq   %rax, %rax
// 7c: 7f 22                         jg      0xa0 <_JIT_ENTRY+0xa0>
// 7e: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000080:  R_X86_64_64  .rodata.str1.1
// 88: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000008a:  R_X86_64_64  _Py_NegativeRefcount
// 92: be fb 02 00 00                movl    $0x2fb, %esi            # imm = 0x2FB
// 97: 4c 89 e2                      movq    %r12, %rdx
// 9a: ff d0                         callq   *%rax
// 9c: 49 8b 04 24                   movq    (%r12), %rax
// a0: 85 c0                         testl   %eax, %eax
// a2: 78 6a                         js      0x10e <_JIT_ENTRY+0x10e>
// a4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a6:  R_X86_64_64  _Py_DECREF_DecRefTotal
// ae: ff d0                         callq   *%rax
// b0: 49 ff 0c 24                   decq    (%r12)
// b4: 75 58                         jne     0x10e <_JIT_ENTRY+0x10e>
// b6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b8:  R_X86_64_64  _Py_Dealloc
// c0: 4c 89 e7                      movq    %r12, %rdi
// c3: ff d0                         callq   *%rax
// c5: eb 47                         jmp     0x10e <_JIT_ENTRY+0x10e>
// c7: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000c9:  R_X86_64_64  PyExc_TypeError
// d1: 48 8b 31                      movq    (%rcx), %rsi
// d4: 48 8b 48 18                   movq    0x18(%rax), %rcx
// d8: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 00000000000000da:  R_X86_64_64  .rodata.str1.1+0x39
// e2: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 00000000000000e4:  R_X86_64_64  _PyErr_Format
// ec: 4c 89 ff                      movq    %r15, %rdi
// ef: 31 c0                         xorl    %eax, %eax
// f1: 41 ff d0                      callq   *%r8
// f4: e9 b9 00 00 00                jmp     0x1b2 <_JIT_ENTRY+0x1b2>
// f9: 48 8b 41 50                   movq    0x50(%rcx), %rax
// fd: 31 ff                         xorl    %edi, %edi
// ff: ff 50 10                      callq   *0x10(%rax)
// 102: 49 89 c5                      movq    %rax, %r13
// 105: 48 85 c0                      testq   %rax, %rax
// 108: 0f 84 a4 00 00 00             je      0x1b2 <_JIT_ENTRY+0x1b2>
// 10e: 4c 89 6b 08                   movq    %r13, 0x8(%rbx)
// 112: 48 83 c3 10                   addq    $0x10, %rbx
// 116: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000118:  R_X86_64_64  _JIT_CONTINUE
// 120: 4c 89 f7                      movq    %r14, %rdi
// 123: 48 89 de                      movq    %rbx, %rsi
// 126: 4c 89 fa                      movq    %r15, %rdx
// 129: 5b                            popq    %rbx
// 12a: 41 5c                         popq    %r12
// 12c: 41 5d                         popq    %r13
// 12e: 41 5e                         popq    %r14
// 130: 41 5f                         popq    %r15
// 132: ff e0                         jmpq    *%rax
// 134: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000136:  R_X86_64_64  PyExc_TypeError
// 13e: 48 8b 38                      movq    (%rax), %rdi
// 141: 49 8b 44 24 08                movq    0x8(%r12), %rax
// 146: 48 8b 50 18                   movq    0x18(%rax), %rdx
// 14a: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 000000000000014c:  R_X86_64_64  .rodata.str1.1+0x7c
// 154: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000156:  R_X86_64_64  _PyErr_FormatFromCause
// 15e: 31 c0                         xorl    %eax, %eax
// 160: ff d1                         callq   *%rcx
// 162: 49 8b 04 24                   movq    (%r12), %rax
// 166: 48 85 c0                      testq   %rax, %rax
// 169: 7f 22                         jg      0x18d <_JIT_ENTRY+0x18d>
// 16b: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000016d:  R_X86_64_64  .rodata.str1.1
// 175: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000177:  R_X86_64_64  _Py_NegativeRefcount
// 17f: be f8 02 00 00                movl    $0x2f8, %esi            # imm = 0x2F8
// 184: 4c 89 e2                      movq    %r12, %rdx
// 187: ff d0                         callq   *%rax
// 189: 49 8b 04 24                   movq    (%r12), %rax
// 18d: 85 c0                         testl   %eax, %eax
// 18f: 78 21                         js      0x1b2 <_JIT_ENTRY+0x1b2>
// 191: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000193:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 19b: ff d0                         callq   *%rax
// 19d: 49 ff 0c 24                   decq    (%r12)
// 1a1: 75 0f                         jne     0x1b2 <_JIT_ENTRY+0x1b2>
// 1a3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001a5:  R_X86_64_64  _Py_Dealloc
// 1ad: 4c 89 e7                      movq    %r12, %rdi
// 1b0: ff d0                         callq   *%rax
// 1b2: 48 83 c3 08                   addq    $0x8, %rbx
// 1b6: 4c 29 f3                      subq    %r14, %rbx
// 1b9: 48 83 c3 b8                   addq    $-0x48, %rbx
// 1bd: 48 c1 eb 03                   shrq    $0x3, %rbx
// 1c1: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 1c5: 31 c0                         xorl    %eax, %eax
// 1c7: 5b                            popq    %rbx
// 1c8: 41 5c                         popq    %r12
// 1ca: 41 5d                         popq    %r13
// 1cc: 41 5e                         popq    %r14
// 1ce: 41 5f                         popq    %r15
// 1d0: c3                            retq
// 1d1: 
static const unsigned char _PUSH_NULLplus_GET_ANEXT_code_body[466] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0xc8, 0x0f, 0x84, 0xc5, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x50, 0x48, 0x85, 0xc9, 0x0f, 0x84, 0x86, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x49, 0x10, 0x48, 0x85, 0xc9, 0x74, 0x7d, 0x31, 0xff, 0xff, 0xd1, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0x5b, 0x01, 0x00, 0x00, 0x49, 0x89, 0xc4, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0xc2, 0x00, 0x00, 0x00, 0x49, 0x89, 0xc5, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xfb, 0x02, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x6a, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x58, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0xeb, 0x47, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x31, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0xe9, 0xb9, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x41, 0x50, 0x31, 0xff, 0xff, 0x50, 0x10, 0x49, 0x89, 0xc5, 0x48, 0x85, 0xc0, 0x0f, 0x84, 0xa4, 0x00, 0x00, 0x00, 0x4c, 0x89, 0x6b, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x38, 0x49, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x8b, 0x50, 0x18, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xff, 0xd1, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xf8, 0x02, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_GET_ANEXT_code_holes[18] = {
    {0x23, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyAsyncGen_Type, 0x0},
    {0x5c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyCoro_GetAwaitableIter, 0x0},
    {0x80, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x8a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xa6, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xb8, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xc9, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0xda, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0xe4, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0x118, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x136, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x14c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x7c},
    {0x156, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_FormatFromCause, 0x0},
    {0x16d, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x177, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x193, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x1a5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: "/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'async for' requires an iterator with __anext__ method, got %.100s\x00'async for' received an invalid object from __anext__: %.100s\x00"
// ba: 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_GET_ANEXT_data_body[193] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x27, 0x61, 0x73, 0x79, 0x6e, 0x63, 0x20, 0x66, 0x6f, 0x72, 0x27, 0x20, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x73, 0x20, 0x61, 0x6e, 0x20, 0x69, 0x74, 0x65, 0x72, 0x61, 0x74, 0x6f, 0x72, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x5f, 0x5f, 0x61, 0x6e, 0x65, 0x78, 0x74, 0x5f, 0x5f, 0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x2c, 0x20, 0x67, 0x6f, 0x74, 0x20, 0x25, 0x2e, 0x31, 0x30, 0x30, 0x73, 0x00, 0x27, 0x61, 0x73, 0x79, 0x6e, 0x63, 0x20, 0x66, 0x6f, 0x72, 0x27, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x64, 0x20, 0x61, 0x6e, 0x20, 0x69, 0x6e, 0x76, 0x61, 0x6c, 0x69, 0x64, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x5f, 0x5f, 0x61, 0x6e, 0x65, 0x78, 0x74, 0x5f, 0x5f, 0x3a, 0x20, 0x25, 0x2e, 0x31, 0x30, 0x30, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_GET_ANEXT_data_holes[1];

// _PUSH_NULLplus_GET_AWAITABLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_AWAITABLE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 89 d3                      movq    %rdx, %rbx
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _PyCoro_GetAwaitableIter
// 15: 31 ff                         xorl    %edi, %edi
// 17: ff d0                         callq   *%rax
// 19: 48 8b 34 25 08 00 00 00       movq    0x8, %rsi
// 21: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000023:  R_X86_64_64  _JIT_OPARG
// 2b: 0f b7 d0                      movzwl  %ax, %edx
// 2e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000030:  R_X86_64_64  _PyEval_FormatAwaitableError
// 38: 48 89 df                      movq    %rbx, %rdi
// 3b: ff d0                         callq   *%rax
// 3d: 
static const unsigned char _PUSH_NULLplus_GET_AWAITABLE_code_body[62] = {0x53, 0x48, 0x89, 0xd3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x8b, 0x34, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_GET_AWAITABLE_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyCoro_GetAwaitableIter, 0x0},
    {0x23, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatAwaitableError, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GET_AWAITABLE_data_body[1];
static const Hole _PUSH_NULLplus_GET_AWAITABLE_data_holes[1];

// _PUSH_NULLplus_GET_ITER
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_ITER.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyObject_GetIter
// 12: 31 ff                         xorl    %edi, %edi
// 14: ff d0                         callq   *%rax
// 16: 
static const unsigned char _PUSH_NULLplus_GET_ITER_code_body[23] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_GET_ITER_code_holes[2] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GetIter, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GET_ITER_data_body[1];
static const Hole _PUSH_NULLplus_GET_ITER_data_holes[1];

// _PUSH_NULLplus_GET_LEN
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_LEN.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000017:  R_X86_64_64  PyObject_Size
// 1f: 31 ff                         xorl    %edi, %edi
// 21: ff d0                         callq   *%rax
// 23: 48 85 c0                      testq   %rax, %rax
// 26: 78 36                         js      0x5e <_JIT_ENTRY+0x5e>
// 28: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002a:  R_X86_64_64  PyLong_FromSsize_t
// 32: 48 89 c7                      movq    %rax, %rdi
// 35: ff d1                         callq   *%rcx
// 37: 48 85 c0                      testq   %rax, %rax
// 3a: 74 22                         je      0x5e <_JIT_ENTRY+0x5e>
// 3c: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 40: 48 83 c3 10                   addq    $0x10, %rbx
// 44: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000046:  R_X86_64_64  _JIT_CONTINUE
// 4e: 4c 89 f7                      movq    %r14, %rdi
// 51: 48 89 de                      movq    %rbx, %rsi
// 54: 4c 89 fa                      movq    %r15, %rdx
// 57: 5b                            popq    %rbx
// 58: 41 5e                         popq    %r14
// 5a: 41 5f                         popq    %r15
// 5c: ff e0                         jmpq    *%rax
// 5e: 48 83 c3 08                   addq    $0x8, %rbx
// 62: 4c 29 f3                      subq    %r14, %rbx
// 65: 48 83 c3 b8                   addq    $-0x48, %rbx
// 69: 48 c1 eb 03                   shrq    $0x3, %rbx
// 6d: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 71: 31 c0                         xorl    %eax, %eax
// 73: 5b                            popq    %rbx
// 74: 41 5e                         popq    %r14
// 76: 41 5f                         popq    %r15
// 78: c3                            retq
// 79: 
static const unsigned char _PUSH_NULLplus_GET_LEN_code_body[122] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x78, 0x36, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xc7, 0xff, 0xd1, 0x48, 0x85, 0xc0, 0x74, 0x22, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_GET_LEN_code_holes[4] = {
    {0x17, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Size, 0x0},
    {0x2a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_FromSsize_t, 0x0},
    {0x46, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GET_LEN_data_body[1];
static const Hole _PUSH_NULLplus_GET_LEN_data_holes[1];

// _PUSH_NULLplus_GET_YIELD_FROM_ITER
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GET_YIELD_FROM_ITER.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 56                         pushq   %r14
// 2: 53                            pushq   %rbx
// 3: 50                            pushq   %rax
// 4: 48 89 f3                      movq    %rsi, %rbx
// 7: 49 89 fe                      movq    %rdi, %r14
// a: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 11: 48 83 c3 08                   addq    $0x8, %rbx
// 15: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 1d: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001f:  R_X86_64_64  PyCoro_Type
// 27: 48 39 c8                      cmpq    %rcx, %rax
// 2a: 74 1f                         je      0x4b <_JIT_ENTRY+0x4b>
// 2c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002e:  R_X86_64_64  PyGen_Type
// 36: 48 39 c8                      cmpq    %rcx, %rax
// 39: 74 1e                         je      0x59 <_JIT_ENTRY+0x59>
// 3b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003d:  R_X86_64_64  PyObject_GetIter
// 45: 31 ff                         xorl    %edi, %edi
// 47: ff d0                         callq   *%rax
// 49: eb 50                         jmp     0x9b <_JIT_ENTRY+0x9b>
// 4b: 49 8b 06                      movq    (%r14), %rax
// 4e: 0f b7 40 30                   movzwl  0x30(%rax), %eax
// 52: a9 80 01 00 00                testl   $0x180, %eax            # imm = 0x180
// 57: 74 19                         je      0x72 <_JIT_ENTRY+0x72>
// 59: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005b:  R_X86_64_64  _JIT_CONTINUE
// 63: 4c 89 f7                      movq    %r14, %rdi
// 66: 48 89 de                      movq    %rbx, %rsi
// 69: 48 83 c4 08                   addq    $0x8, %rsp
// 6d: 5b                            popq    %rbx
// 6e: 41 5e                         popq    %r14
// 70: ff e0                         jmpq    *%rax
// 72: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000074:  R_X86_64_64  PyExc_TypeError
// 7c: 48 8b 30                      movq    (%rax), %rsi
// 7f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000081:  R_X86_64_64  .rodata.str1.1
// 89: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000008b:  R_X86_64_64  _PyErr_SetString
// 93: 48 89 d7                      movq    %rdx, %rdi
// 96: 48 89 c2                      movq    %rax, %rdx
// 99: ff d1                         callq   *%rcx
// 9b: 4c 29 f3                      subq    %r14, %rbx
// 9e: 48 83 c3 b8                   addq    $-0x48, %rbx
// a2: 48 c1 eb 03                   shrq    $0x3, %rbx
// a6: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// aa: 31 c0                         xorl    %eax, %eax
// ac: 48 83 c4 08                   addq    $0x8, %rsp
// b0: 5b                            popq    %rbx
// b1: 41 5e                         popq    %r14
// b3: c3                            retq
// b4: 
static const unsigned char _PUSH_NULLplus_GET_YIELD_FROM_ITER_code_body[181] = {0x41, 0x56, 0x53, 0x50, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0xc8, 0x74, 0x1f, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0xc8, 0x74, 0x1e, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0xeb, 0x50, 0x49, 0x8b, 0x06, 0x0f, 0xb7, 0x40, 0x30, 0xa9, 0x80, 0x01, 0x00, 0x00, 0x74, 0x19, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5e, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0xc2, 0xff, 0xd1, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5e, 0xc3};
static const Hole _PUSH_NULLplus_GET_YIELD_FROM_ITER_code_holes[8] = {
    {0x1f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyCoro_Type, 0x0},
    {0x2e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyGen_Type, 0x0},
    {0x3d, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GetIter, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x74, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x81, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x8b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetString, 0x0},
};
// 0: "cannot 'yield from' a coroutine object in a non-coroutine generator\x00"
// 44: 00 00 00 00
static const unsigned char _PUSH_NULLplus_GET_YIELD_FROM_ITER_data_body[73] = {0x63, 0x61, 0x6e, 0x6e, 0x6f, 0x74, 0x20, 0x27, 0x79, 0x69, 0x65, 0x6c, 0x64, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x27, 0x20, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x6f, 0x75, 0x74, 0x69, 0x6e, 0x65, 0x20, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x20, 0x69, 0x6e, 0x20, 0x61, 0x20, 0x6e, 0x6f, 0x6e, 0x2d, 0x63, 0x6f, 0x72, 0x6f, 0x75, 0x74, 0x69, 0x6e, 0x65, 0x20, 0x67, 0x65, 0x6e, 0x65, 0x72, 0x61, 0x74, 0x6f, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_GET_YIELD_FROM_ITER_data_holes[1];

// _PUSH_NULLplus_GUARD_BOTH_FLOAT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_BOTH_FLOAT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 4e f8                   movq    -0x8(%rsi), %rcx
// b: 48 83 c6 08                   addq    $0x8, %rsi
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  PyFloat_Type
// 19: 48 39 41 08                   cmpq    %rax, 0x8(%rcx)
// 1d: 75 0a                         jne     0x29 <_JIT_ENTRY+0x29>
// 1f: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 27: 74 28                         je      0x51 <_JIT_ENTRY+0x51>
// 29: 48 29 fe                      subq    %rdi, %rsi
// 2c: 48 83 c6 b8                   addq    $-0x48, %rsi
// 30: 48 c1 ee 03                   shrq    $0x3, %rsi
// 34: 89 77 40                      movl    %esi, 0x40(%rdi)
// 37: 48 8b 07                      movq    (%rdi), %rax
// 3a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003c:  R_X86_64_64  _JIT_TARGET
// 44: 89 c9                         movl    %ecx, %ecx
// 46: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 4a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 50: c3                            retq
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: ff e0                         jmpq    *%rax
// 5d: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_FLOAT_code_body[94] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x4e, 0xf8, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x41, 0x08, 0x75, 0x0a, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_BOTH_FLOAT_code_holes[4] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyFloat_Type, 0x0},
    {0x3c, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_FLOAT_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_BOTH_FLOAT_data_holes[1];

// _PUSH_NULLplus_GUARD_BOTH_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_BOTH_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 4e f8                   movq    -0x8(%rsi), %rcx
// b: 48 83 c6 08                   addq    $0x8, %rsi
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  PyLong_Type
// 19: 48 39 41 08                   cmpq    %rax, 0x8(%rcx)
// 1d: 75 0a                         jne     0x29 <_JIT_ENTRY+0x29>
// 1f: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 27: 74 28                         je      0x51 <_JIT_ENTRY+0x51>
// 29: 48 29 fe                      subq    %rdi, %rsi
// 2c: 48 83 c6 b8                   addq    $-0x48, %rsi
// 30: 48 c1 ee 03                   shrq    $0x3, %rsi
// 34: 89 77 40                      movl    %esi, 0x40(%rdi)
// 37: 48 8b 07                      movq    (%rdi), %rax
// 3a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003c:  R_X86_64_64  _JIT_TARGET
// 44: 89 c9                         movl    %ecx, %ecx
// 46: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 4a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 50: c3                            retq
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: ff e0                         jmpq    *%rax
// 5d: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_INT_code_body[94] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x4e, 0xf8, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x41, 0x08, 0x75, 0x0a, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_BOTH_INT_code_holes[4] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x3c, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_INT_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_BOTH_INT_data_holes[1];

// _PUSH_NULLplus_GUARD_BOTH_UNICODE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_BOTH_UNICODE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 4e f8                   movq    -0x8(%rsi), %rcx
// b: 48 83 c6 08                   addq    $0x8, %rsi
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  PyUnicode_Type
// 19: 48 39 41 08                   cmpq    %rax, 0x8(%rcx)
// 1d: 75 0a                         jne     0x29 <_JIT_ENTRY+0x29>
// 1f: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 27: 74 28                         je      0x51 <_JIT_ENTRY+0x51>
// 29: 48 29 fe                      subq    %rdi, %rsi
// 2c: 48 83 c6 b8                   addq    $-0x48, %rsi
// 30: 48 c1 ee 03                   shrq    $0x3, %rsi
// 34: 89 77 40                      movl    %esi, 0x40(%rdi)
// 37: 48 8b 07                      movq    (%rdi), %rax
// 3a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003c:  R_X86_64_64  _JIT_TARGET
// 44: 89 c9                         movl    %ecx, %ecx
// 46: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 4a: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 50: c3                            retq
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: ff e0                         jmpq    *%rax
// 5d: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_UNICODE_code_body[94] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x4e, 0xf8, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x41, 0x08, 0x75, 0x0a, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_BOTH_UNICODE_code_holes[4] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyUnicode_Type, 0x0},
    {0x3c, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_BOTH_UNICODE_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_BOTH_UNICODE_data_holes[1];

// _PUSH_NULLplus_GUARD_BUILTINS_VERSION
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_BUILTINS_VERSION.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 47 20                   movq    0x20(%rdi), %rax
// f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000011:  R_X86_64_64  PyDict_Type
// 19: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 1d: 75 22                         jne     0x41 <_JIT_ENTRY+0x41>
// 1f: 48 8b 40 20                   movq    0x20(%rax), %rax
// 23: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000025:  R_X86_64_64  _JIT_OPERAND
// 2d: 0f b7 c9                      movzwl  %cx, %ecx
// 30: 39 48 0c                      cmpl    %ecx, 0xc(%rax)
// 33: 75 0c                         jne     0x41 <_JIT_ENTRY+0x41>
// 35: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000037:  R_X86_64_64  _JIT_CONTINUE
// 3f: ff e0                         jmpq    *%rax
// 41: 48 29 fe                      subq    %rdi, %rsi
// 44: 48 83 c6 b8                   addq    $-0x48, %rsi
// 48: 48 c1 ee 03                   shrq    $0x3, %rsi
// 4c: 89 77 40                      movl    %esi, 0x40(%rdi)
// 4f: 48 8b 07                      movq    (%rdi), %rax
// 52: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000054:  R_X86_64_64  _JIT_TARGET
// 5c: 89 c9                         movl    %ecx, %ecx
// 5e: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 62: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 68: c3                            retq
// 69: 
static const unsigned char _PUSH_NULLplus_GUARD_BUILTINS_VERSION_code_body[106] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x47, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x22, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x39, 0x48, 0x0c, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_BUILTINS_VERSION_code_holes[5] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x37, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x54, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_BUILTINS_VERSION_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_BUILTINS_VERSION_data_holes[1];

// _PUSH_NULLplus_GUARD_DORV_VALUES
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_DORV_VALUES.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: f6 04 25 e8 ff ff ff 01       testb   $0x1, -0x18
// 13: 75 28                         jne     0x3d <_JIT_ENTRY+0x3d>
// 15: 48 29 fe                      subq    %rdi, %rsi
// 18: 48 83 c6 b8                   addq    $-0x48, %rsi
// 1c: 48 c1 ee 03                   shrq    $0x3, %rsi
// 20: 89 77 40                      movl    %esi, 0x40(%rdi)
// 23: 48 8b 07                      movq    (%rdi), %rax
// 26: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000028:  R_X86_64_64  _JIT_TARGET
// 30: 89 c9                         movl    %ecx, %ecx
// 32: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 36: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 3c: c3                            retq
// 3d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003f:  R_X86_64_64  _JIT_CONTINUE
// 47: ff e0                         jmpq    *%rax
// 49: 
static const unsigned char _PUSH_NULLplus_GUARD_DORV_VALUES_code_body[74] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0xf6, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x01, 0x75, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_DORV_VALUES_code_holes[3] = {
    {0x28, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_DORV_VALUES_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_DORV_VALUES_data_holes[1];

// _PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 83 c3 08                   addq    $0x8, %rbx
// 19: f6 04 25 e8 ff ff ff 01       testb   $0x1, -0x18
// 21: 75 19                         jne     0x3c <_JIT_ENTRY+0x3c>
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  _PyObject_MakeInstanceAttributesFromDict
// 2d: 31 ff                         xorl    %edi, %edi
// 2f: 48 c7 c6 e8 ff ff ff          movq    $-0x18, %rsi
// 36: ff d0                         callq   *%rax
// 38: 84 c0                         testb   %al, %al
// 3a: 74 1a                         je      0x56 <_JIT_ENTRY+0x56>
// 3c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003e:  R_X86_64_64  _JIT_CONTINUE
// 46: 4c 89 f7                      movq    %r14, %rdi
// 49: 48 89 de                      movq    %rbx, %rsi
// 4c: 4c 89 fa                      movq    %r15, %rdx
// 4f: 5b                            popq    %rbx
// 50: 41 5e                         popq    %r14
// 52: 41 5f                         popq    %r15
// 54: ff e0                         jmpq    *%rax
// 56: 4c 29 f3                      subq    %r14, %rbx
// 59: 48 83 c3 b8                   addq    $-0x48, %rbx
// 5d: 48 c1 eb 03                   shrq    $0x3, %rbx
// 61: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 65: 49 8b 06                      movq    (%r14), %rax
// 68: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006a:  R_X86_64_64  _JIT_TARGET
// 72: 89 c9                         movl    %ecx, %ecx
// 74: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// 7c: 5b                            popq    %rbx
// 7d: 41 5e                         popq    %r14
// 7f: 41 5f                         popq    %r15
// 81: c3                            retq
// 82: 
static const unsigned char _PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_code_body[131] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0xf6, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x01, 0x75, 0x19, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0x48, 0xc7, 0xc6, 0xe8, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x84, 0xc0, 0x74, 0x1a, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x49, 0x8b, 0x06, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_code_holes[4] = {
    {0x25, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyObject_MakeInstanceAttributesFromDict, 0x0},
    {0x3e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_data_holes[1];

// _PUSH_NULLplus_GUARD_GLOBALS_VERSION
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_GLOBALS_VERSION.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 47 18                   movq    0x18(%rdi), %rax
// f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000011:  R_X86_64_64  PyDict_Type
// 19: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 1d: 75 22                         jne     0x41 <_JIT_ENTRY+0x41>
// 1f: 48 8b 40 20                   movq    0x20(%rax), %rax
// 23: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000025:  R_X86_64_64  _JIT_OPERAND
// 2d: 0f b7 c9                      movzwl  %cx, %ecx
// 30: 39 48 0c                      cmpl    %ecx, 0xc(%rax)
// 33: 75 0c                         jne     0x41 <_JIT_ENTRY+0x41>
// 35: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000037:  R_X86_64_64  _JIT_CONTINUE
// 3f: ff e0                         jmpq    *%rax
// 41: 48 29 fe                      subq    %rdi, %rsi
// 44: 48 83 c6 b8                   addq    $-0x48, %rsi
// 48: 48 c1 ee 03                   shrq    $0x3, %rsi
// 4c: 89 77 40                      movl    %esi, 0x40(%rdi)
// 4f: 48 8b 07                      movq    (%rdi), %rax
// 52: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000054:  R_X86_64_64  _JIT_TARGET
// 5c: 89 c9                         movl    %ecx, %ecx
// 5e: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 62: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 68: c3                            retq
// 69: 
static const unsigned char _PUSH_NULLplus_GUARD_GLOBALS_VERSION_code_body[106] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x47, 0x18, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x22, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x39, 0x48, 0x0c, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_GLOBALS_VERSION_code_holes[5] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x25, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x37, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x54, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_GLOBALS_VERSION_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_GLOBALS_VERSION_data_holes[1];

// _PUSH_NULLplus_GUARD_IS_FALSE_POP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_IS_FALSE_POP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  _JIT_CONTINUE
// 11: ff e0                         jmpq    *%rax
// 13: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_FALSE_POP_code_body[20] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_IS_FALSE_POP_code_holes[2] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_FALSE_POP_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_IS_FALSE_POP_data_holes[1];

// _PUSH_NULLplus_GUARD_IS_NONE_POP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_IS_NONE_POP.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_NONE_POP_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_IS_NONE_POP_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_NONE_POP_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_IS_NONE_POP_data_holes[1];

// _PUSH_NULLplus_GUARD_IS_NOT_NONE_POP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_IS_NOT_NONE_POP.o:        file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_NOT_NONE_POP_code_body[1] = {};
static const Hole _PUSH_NULLplus_GUARD_IS_NOT_NONE_POP_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_NOT_NONE_POP_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_IS_NOT_NONE_POP_data_holes[1];

// _PUSH_NULLplus_GUARD_IS_TRUE_POP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_IS_TRUE_POP.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  _JIT_CONTINUE
// 11: ff e0                         jmpq    *%rax
// 13: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_TRUE_POP_code_body[20] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_GUARD_IS_TRUE_POP_code_holes[2] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_IS_TRUE_POP_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_IS_TRUE_POP_data_holes[1];

// _PUSH_NULLplus_GUARD_KEYS_VERSION
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_KEYS_VERSION.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 13: 48 8b 80 70 03 00 00          movq    0x370(%rax), %rax
// 1a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001c:  R_X86_64_64  _JIT_OPERAND
// 24: 39 48 0c                      cmpl    %ecx, 0xc(%rax)
// 27: 75 0c                         jne     0x35 <_JIT_ENTRY+0x35>
// 29: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002b:  R_X86_64_64  _JIT_CONTINUE
// 33: ff e0                         jmpq    *%rax
// 35: 48 29 fe                      subq    %rdi, %rsi
// 38: 48 83 c6 b8                   addq    $-0x48, %rsi
// 3c: 48 c1 ee 03                   shrq    $0x3, %rsi
// 40: 89 77 40                      movl    %esi, 0x40(%rdi)
// 43: 48 8b 07                      movq    (%rdi), %rax
// 46: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000048:  R_X86_64_64  _JIT_TARGET
// 50: 89 c9                         movl    %ecx, %ecx
// 52: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 56: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 5c: c3                            retq
// 5d: 
static const unsigned char _PUSH_NULLplus_GUARD_KEYS_VERSION_code_body[94] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x80, 0x70, 0x03, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x48, 0x0c, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_KEYS_VERSION_code_holes[4] = {
    {0x1c, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x2b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_KEYS_VERSION_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_KEYS_VERSION_data_holes[1];

// _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 18 00 00 00       movq    0x18, %rax
// 13: 48 85 c0                      testq   %rax, %rax
// 16: 74 1a                         je      0x32 <_JIT_ENTRY+0x32>
// 18: 48 8b 0c 25 10 00 00 00       movq    0x10, %rcx
// 20: 48 3b 48 10                   cmpq    0x10(%rax), %rcx
// 24: 7d 0c                         jge     0x32 <_JIT_ENTRY+0x32>
// 26: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000028:  R_X86_64_64  _JIT_CONTINUE
// 30: ff e0                         jmpq    *%rax
// 32: 48 29 fe                      subq    %rdi, %rsi
// 35: 48 83 c6 b8                   addq    $-0x48, %rsi
// 39: 48 c1 ee 03                   shrq    $0x3, %rsi
// 3d: 89 77 40                      movl    %esi, 0x40(%rdi)
// 40: 48 8b 07                      movq    (%rdi), %rax
// 43: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000045:  R_X86_64_64  _JIT_TARGET
// 4d: 89 c9                         movl    %ecx, %ecx
// 4f: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 53: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 59: c3                            retq
// 5a: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST_code_body[91] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x85, 0xc0, 0x74, 0x1a, 0x48, 0x8b, 0x0c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x3b, 0x48, 0x10, 0x7d, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST_code_holes[3] = {
    {0x28, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x45, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST_data_holes[1];

// _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 83 3c 25 20 00 00 00 00    cmpq    $0x0, 0x20
// 14: 7e 0c                         jle     0x22 <_JIT_ENTRY+0x22>
// 16: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000018:  R_X86_64_64  _JIT_CONTINUE
// 20: ff e0                         jmpq    *%rax
// 22: 48 29 fe                      subq    %rdi, %rsi
// 25: 48 83 c6 b8                   addq    $-0x48, %rsi
// 29: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2d: 89 77 40                      movl    %esi, 0x40(%rdi)
// 30: 48 8b 07                      movq    (%rdi), %rax
// 33: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000035:  R_X86_64_64  _JIT_TARGET
// 3d: 89 c9                         movl    %ecx, %ecx
// 3f: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 43: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 49: c3                            retq
// 4a: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE_code_body[75] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x83, 0x3c, 0x25, 0x20, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE_code_holes[3] = {
    {0x18, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE_data_holes[1];

// _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 18 00 00 00       movq    0x18, %rax
// 13: 48 85 c0                      testq   %rax, %rax
// 16: 74 1a                         je      0x32 <_JIT_ENTRY+0x32>
// 18: 48 8b 0c 25 10 00 00 00       movq    0x10, %rcx
// 20: 48 3b 48 10                   cmpq    0x10(%rax), %rcx
// 24: 7d 0c                         jge     0x32 <_JIT_ENTRY+0x32>
// 26: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000028:  R_X86_64_64  _JIT_CONTINUE
// 30: ff e0                         jmpq    *%rax
// 32: 48 29 fe                      subq    %rdi, %rsi
// 35: 48 83 c6 b8                   addq    $-0x48, %rsi
// 39: 48 c1 ee 03                   shrq    $0x3, %rsi
// 3d: 89 77 40                      movl    %esi, 0x40(%rdi)
// 40: 48 8b 07                      movq    (%rdi), %rax
// 43: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000045:  R_X86_64_64  _JIT_TARGET
// 4d: 89 c9                         movl    %ecx, %ecx
// 4f: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 53: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 59: c3                            retq
// 5a: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE_code_body[91] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x85, 0xc0, 0x74, 0x1a, 0x48, 0x8b, 0x0c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x3b, 0x48, 0x10, 0x7d, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE_code_holes[3] = {
    {0x28, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x45, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE_data_holes[1];

// _PUSH_NULLplus_GUARD_TYPE_VERSION
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_GUARD_TYPE_VERSION.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 13: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000015:  R_X86_64_64  _JIT_OPERAND
// 1d: 39 88 80 01 00 00             cmpl    %ecx, 0x180(%rax)
// 23: 75 0c                         jne     0x31 <_JIT_ENTRY+0x31>
// 25: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000027:  R_X86_64_64  _JIT_CONTINUE
// 2f: ff e0                         jmpq    *%rax
// 31: 48 29 fe                      subq    %rdi, %rsi
// 34: 48 83 c6 b8                   addq    $-0x48, %rsi
// 38: 48 c1 ee 03                   shrq    $0x3, %rsi
// 3c: 89 77 40                      movl    %esi, 0x40(%rdi)
// 3f: 48 8b 07                      movq    (%rdi), %rax
// 42: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000044:  R_X86_64_64  _JIT_TARGET
// 4c: 89 c9                         movl    %ecx, %ecx
// 4e: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 52: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 58: c3                            retq
// 59: 
static const unsigned char _PUSH_NULLplus_GUARD_TYPE_VERSION_code_body[90] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x88, 0x80, 0x01, 0x00, 0x00, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_GUARD_TYPE_VERSION_code_holes[4] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x44, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_GUARD_TYPE_VERSION_data_body[1];
static const Hole _PUSH_NULLplus_GUARD_TYPE_VERSION_data_holes[1];

// _PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 14 24                   movq    %rdx, (%rsp)
// f: 49 89 f6                      movq    %rsi, %r14
// 12: 49 89 ff                      movq    %rdi, %r15
// 15: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPARG
// 26: 0f b7 c0                      movzwl  %ax, %eax
// 29: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 2e: 29 c1                         subl    %eax, %ecx
// 30: 48 63 c1                      movslq  %ecx, %rax
// 33: 4c 8b 64 c6 08                movq    0x8(%rsi,%rax,8), %r12
// 38: 4d 8b 6c 24 18                movq    0x18(%r12), %r13
// 3d: 41 8b 45 00                   movl    (%r13), %eax
// 41: 48 bb 00 00 00 00 00 00 00 00 movabsq $0x0, %rbx
// 0000000000000043:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 4b: ff c0                         incl    %eax
// 4d: 74 06                         je      0x55 <_JIT_ENTRY+0x55>
// 4f: 41 89 45 00                   movl    %eax, (%r13)
// 53: ff d3                         callq   *%rbx
// 55: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000057:  R_X86_64_64  _JIT_OPARG
// 5f: f7 d0                         notl    %eax
// 61: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 66: 48 98                         cltq
// 68: 4d 89 6c c6 08                movq    %r13, 0x8(%r14,%rax,8)
// 6d: 49 8b 6c 24 10                movq    0x10(%r12), %rbp
// 72: 8b 45 00                      movl    (%rbp), %eax
// 75: ff c0                         incl    %eax
// 77: 74 05                         je      0x7e <_JIT_ENTRY+0x7e>
// 79: 89 45 00                      movl    %eax, (%rbp)
// 7c: ff d3                         callq   *%rbx
// 7e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000080:  R_X86_64_64  _JIT_OPARG
// 88: 0f b7 c0                      movzwl  %ax, %eax
// 8b: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 90: 29 c1                         subl    %eax, %ecx
// 92: 48 63 c1                      movslq  %ecx, %rax
// 95: 49 89 6c c6 08                movq    %rbp, 0x8(%r14,%rax,8)
// 9a: 49 8b 04 24                   movq    (%r12), %rax
// 9e: 48 85 c0                      testq   %rax, %rax
// a1: 7e 06                         jle     0xa9 <_JIT_ENTRY+0xa9>
// a3: 85 c0                         testl   %eax, %eax
// a5: 79 28                         jns     0xcf <_JIT_ENTRY+0xcf>
// a7: eb 47                         jmp     0xf0 <_JIT_ENTRY+0xf0>
// a9: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000ab:  R_X86_64_64  .rodata.str1.1
// b3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b5:  R_X86_64_64  _Py_NegativeRefcount
// bd: be 18 0a 00 00                movl    $0xa18, %esi            # imm = 0xA18
// c2: 4c 89 e2                      movq    %r12, %rdx
// c5: ff d0                         callq   *%rax
// c7: 49 8b 04 24                   movq    (%r12), %rax
// cb: 85 c0                         testl   %eax, %eax
// cd: 78 21                         js      0xf0 <_JIT_ENTRY+0xf0>
// cf: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d1:  R_X86_64_64  _Py_DECREF_DecRefTotal
// d9: ff d0                         callq   *%rax
// db: 49 ff 0c 24                   decq    (%r12)
// df: 75 0f                         jne     0xf0 <_JIT_ENTRY+0xf0>
// e1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e3:  R_X86_64_64  _Py_Dealloc
// eb: 4c 89 e7                      movq    %r12, %rdi
// ee: ff d0                         callq   *%rax
// f0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000f2:  R_X86_64_64  _JIT_OPARG
// fa: 0f b7 c0                      movzwl  %ax, %eax
// fd: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 102: 29 c1                         subl    %eax, %ecx
// 104: 48 63 c9                      movslq  %ecx, %rcx
// 107: 49 89 6c ce 08                movq    %rbp, 0x8(%r14,%rcx,8)
// 10c: f7 d0                         notl    %eax
// 10e: 48 98                         cltq
// 110: 4d 89 6c c6 08                movq    %r13, 0x8(%r14,%rax,8)
// 115: 49 83 c6 08                   addq    $0x8, %r14
// 119: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011b:  R_X86_64_64  _JIT_CONTINUE
// 123: 4c 89 ff                      movq    %r15, %rdi
// 126: 4c 89 f6                      movq    %r14, %rsi
// 129: 48 8b 14 24                   movq    (%rsp), %rdx
// 12d: 48 83 c4 08                   addq    $0x8, %rsp
// 131: 5b                            popq    %rbx
// 132: 41 5c                         popq    %r12
// 134: 41 5d                         popq    %r13
// 136: 41 5e                         popq    %r14
// 138: 41 5f                         popq    %r15
// 13a: 5d                            popq    %rbp
// 13b: ff e0                         jmpq    *%rax
// 13d: 
static const unsigned char _PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_code_body[318] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0x14, 0x24, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x4c, 0x8b, 0x64, 0xc6, 0x08, 0x4d, 0x8b, 0x6c, 0x24, 0x18, 0x41, 0x8b, 0x45, 0x00, 0x48, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x74, 0x06, 0x41, 0x89, 0x45, 0x00, 0xff, 0xd3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x4d, 0x89, 0x6c, 0xc6, 0x08, 0x49, 0x8b, 0x6c, 0x24, 0x10, 0x8b, 0x45, 0x00, 0xff, 0xc0, 0x74, 0x05, 0x89, 0x45, 0x00, 0xff, 0xd3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x49, 0x89, 0x6c, 0xc6, 0x08, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x18, 0x0a, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc9, 0x49, 0x89, 0x6c, 0xce, 0x08, 0xf7, 0xd0, 0x48, 0x98, 0x4d, 0x89, 0x6c, 0xc6, 0x08, 0x49, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x8b, 0x14, 0x24, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_code_holes[11] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x57, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x80, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xab, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xb5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xd1, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xe3, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xf2, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x11b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_data_holes[1];

// _PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 d3                      movq    %rdx, %rbx
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 3c 24                   movq    %rdi, (%rsp)
// 15: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPARG
// 26: 0f b7 c0                      movzwl  %ax, %eax
// 29: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 2e: 29 c1                         subl    %eax, %ecx
// 30: f7 d0                         notl    %eax
// 32: 48 63 d0                      movslq  %eax, %rdx
// 35: 48 63 c1                      movslq  %ecx, %rax
// 38: 4c 8b 74 c6 08                movq    0x8(%rsi,%rax,8), %r14
// 3d: 48 8b 4c d6 08                movq    0x8(%rsi,%rdx,8), %rcx
// 42: 49 8b 6e 30                   movq    0x30(%r14), %rbp
// 46: 4c 8b ab 00 01 00 00          movq    0x100(%rbx), %r13
// 4d: 48 63 45 4c                   movslq  0x4c(%rbp), %rax
// 51: 49 8d 44 c5 00                leaq    (%r13,%rax,8), %rax
// 56: 48 89 83 00 01 00 00          movq    %rax, 0x100(%rbx)
// 5d: 4d 89 75 10                   movq    %r14, 0x10(%r13)
// 61: 8b 45 00                      movl    (%rbp), %eax
// 64: ff c0                         incl    %eax
// 66: 4c 8d 24 d6                   leaq    (%rsi,%rdx,8), %r12
// 6a: 49 83 c4 08                   addq    $0x8, %r12
// 6e: 48 85 c9                      testq   %rcx, %rcx
// 71: 0f 84 bd 00 00 00             je      0x134 <_JIT_ENTRY+0x134>
// 77: 85 c0                         testl   %eax, %eax
// 79: 74 0f                         je      0x8a <_JIT_ENTRY+0x8a>
// 7b: 89 45 00                      movl    %eax, (%rbp)
// 7e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000080:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 88: ff d0                         callq   *%rax
// 8a: 49 89 6d 00                   movq    %rbp, (%r13)
// 8e: 41 0f 10 46 10                movups  0x10(%r14), %xmm0
// 93: 41 0f 11 45 18                movups  %xmm0, 0x18(%r13)
// 98: 49 c7 45 28 00 00 00 00       movq    $0x0, 0x28(%r13)
// a0: 8b 45 48                      movl    0x48(%rbp), %eax
// a3: 41 89 45 40                   movl    %eax, 0x40(%r13)
// a7: 49 c7 45 30 00 00 00 00       movq    $0x0, 0x30(%r13)
// af: 48 81 c5 c8 00 00 00          addq    $0xc8, %rbp
// b6: 49 89 6d 38                   movq    %rbp, 0x38(%r13)
// ba: 66 41 c7 45 44 00 00          movw    $0x0, 0x44(%r13)
// c1: 41 c6 45 46 00                movb    $0x0, 0x46(%r13)
// c6: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 00000000000000c8:  R_X86_64_64  _JIT_OPARG
// d0: 0f b7 ea                      movzwl  %dx, %ebp
// d3: ff c5                         incl    %ebp
// d5: 85 ed                         testl   %ebp, %ebp
// d7: 0f 9f c1                      setg    %cl
// da: 39 e8                         cmpl    %ebp, %eax
// dc: 0f 8e 07 01 00 00             jle     0x1e9 <_JIT_ENTRY+0x1e9>
// e2: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 00000000000000e4:  R_X86_64_64  _JIT_OPARG
// ec: 41 0f b7 ee                   movzwl  %r14w, %ebp
// f0: ff c5                         incl    %ebp
// f2: 48 8d 3c ed 48 00 00 00       leaq    0x48(,%rbp,8), %rdi
// fa: 4c 01 ef                      addq    %r13, %rdi
// fd: 89 e9                         movl    %ebp, %ecx
// ff: f7 d1                         notl    %ecx
// 101: 01 c8                         addl    %ecx, %eax
// 103: 48 8d 14 c5 08 00 00 00       leaq    0x8(,%rax,8), %rdx
// 10b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010d:  R_X86_64_64  memset
// 115: 31 f6                         xorl    %esi, %esi
// 117: ff d0                         callq   *%rax
// 119: 85 ed                         testl   %ebp, %ebp
// 11b: 0f 8e b6 01 00 00             jle     0x2d7 <_JIT_ENTRY+0x2d7>
// 121: 41 0f b7 ce                   movzwl  %r14w, %ecx
// 125: 48 c1 e1 03                   shlq    $0x3, %rcx
// 129: 4c 89 f8                      movq    %r15, %rax
// 12c: 48 29 c8                      subq    %rcx, %rax
// 12f: e9 dd 00 00 00                jmp     0x211 <_JIT_ENTRY+0x211>
// 134: 85 c0                         testl   %eax, %eax
// 136: 74 0f                         je      0x147 <_JIT_ENTRY+0x147>
// 138: 89 45 00                      movl    %eax, (%rbp)
// 13b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 145: ff d0                         callq   *%rax
// 147: 49 89 6d 00                   movq    %rbp, (%r13)
// 14b: 41 0f 10 46 10                movups  0x10(%r14), %xmm0
// 150: 41 0f 11 45 18                movups  %xmm0, 0x18(%r13)
// 155: 49 c7 45 28 00 00 00 00       movq    $0x0, 0x28(%r13)
// 15d: 8b 45 48                      movl    0x48(%rbp), %eax
// 160: 41 89 45 40                   movl    %eax, 0x40(%r13)
// 164: 49 c7 45 30 00 00 00 00       movq    $0x0, 0x30(%r13)
// 16c: 48 81 c5 c8 00 00 00          addq    $0xc8, %rbp
// 173: 49 89 6d 38                   movq    %rbp, 0x38(%r13)
// 177: 66 41 c7 45 44 00 00          movw    $0x0, 0x44(%r13)
// 17e: 41 c6 45 46 00                movb    $0x0, 0x46(%r13)
// 183: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000185:  R_X86_64_64  _JIT_OPARG
// 18d: 0f b7 ea                      movzwl  %dx, %ebp
// 190: 85 ed                         testl   %ebp, %ebp
// 192: 0f 9f c1                      setg    %cl
// 195: 39 e8                         cmpl    %ebp, %eax
// 197: 7e 60                         jle     0x1f9 <_JIT_ENTRY+0x1f9>
// 199: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000019b:  R_X86_64_64  _JIT_OPARG
// 1a3: 44 0f b7 f1                   movzwl  %cx, %r14d
// 1a7: 4a 8d 3c f5 48 00 00 00       leaq    0x48(,%r14,8), %rdi
// 1af: 4c 01 ef                      addq    %r13, %rdi
// 1b2: 0f b7 e9                      movzwl  %cx, %ebp
// 1b5: 89 e9                         movl    %ebp, %ecx
// 1b7: f7 d1                         notl    %ecx
// 1b9: 01 c8                         addl    %ecx, %eax
// 1bb: 48 8d 14 c5 08 00 00 00       leaq    0x8(,%rax,8), %rdx
// 1c3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000001c5:  R_X86_64_64  memset
// 1cd: 31 f6                         xorl    %esi, %esi
// 1cf: ff d0                         callq   *%rax
// 1d1: 85 ed                         testl   %ebp, %ebp
// 1d3: 0f 8e fe 00 00 00             jle     0x2d7 <_JIT_ENTRY+0x2d7>
// 1d9: 49 c1 e6 03                   shlq    $0x3, %r14
// 1dd: 4c 89 f8                      movq    %r15, %rax
// 1e0: 4c 29 f0                      subq    %r14, %rax
// 1e3: 48 83 c0 08                   addq    $0x8, %rax
// 1e7: eb 28                         jmp     0x211 <_JIT_ENTRY+0x211>
// 1e9: 0f b7 c2                      movzwl  %dx, %eax
// 1ec: 48 f7 d8                      negq    %rax
// 1ef: f6 c1 01                      testb   $0x1, %cl
// 1f2: 75 19                         jne     0x20d <_JIT_ENTRY+0x20d>
// 1f4: e9 de 00 00 00                jmp     0x2d7 <_JIT_ENTRY+0x2d7>
// 1f9: 0f b7 d2                      movzwl  %dx, %edx
// 1fc: b8 01 00 00 00                movl    $0x1, %eax
// 201: 48 29 d0                      subq    %rdx, %rax
// 204: f6 c1 01                      testb   $0x1, %cl
// 207: 0f 84 ca 00 00 00             je      0x2d7 <_JIT_ENTRY+0x2d7>
// 20d: 49 8d 04 c7                   leaq    (%r15,%rax,8), %rax
// 211: 83 fd 02                      cmpl    $0x2, %ebp
// 214: b9 01 00 00 00                movl    $0x1, %ecx
// 219: 0f 4d cd                      cmovgel %ebp, %ecx
// 21c: 83 f9 08                      cmpl    $0x8, %ecx
// 21f: 72 10                         jb      0x231 <_JIT_ENTRY+0x231>
// 221: 4c 89 ea                      movq    %r13, %rdx
// 224: 48 29 c2                      subq    %rax, %rdx
// 227: 48 83 c2 48                   addq    $0x48, %rdx
// 22b: 48 83 fa 20                   cmpq    $0x20, %rdx
// 22f: 73 71                         jae     0x2a2 <_JIT_ENTRY+0x2a2>
// 231: 31 d2                         xorl    %edx, %edx
// 233: 48 89 d6                      movq    %rdx, %rsi
// 236: 48 f7 d6                      notq    %rsi
// 239: 48 01 ce                      addq    %rcx, %rsi
// 23c: 48 89 cf                      movq    %rcx, %rdi
// 23f: 48 83 e7 03                   andq    $0x3, %rdi
// 243: 74 1c                         je      0x261 <_JIT_ENTRY+0x261>
// 245: 66 66 2e 0f 1f 84 00 00 00 00 00      nopw    %cs:(%rax,%rax)
// 250: 4c 8b 04 d0                   movq    (%rax,%rdx,8), %r8
// 254: 4d 89 44 d5 48                movq    %r8, 0x48(%r13,%rdx,8)
// 259: 48 ff c2                      incq    %rdx
// 25c: 48 ff cf                      decq    %rdi
// 25f: 75 ef                         jne     0x250 <_JIT_ENTRY+0x250>
// 261: 48 83 fe 03                   cmpq    $0x3, %rsi
// 265: 72 70                         jb      0x2d7 <_JIT_ENTRY+0x2d7>
// 267: 66 0f 1f 84 00 00 00 00 00    nopw    (%rax,%rax)
// 270: 48 8b 34 d0                   movq    (%rax,%rdx,8), %rsi
// 274: 49 89 74 d5 48                movq    %rsi, 0x48(%r13,%rdx,8)
// 279: 48 8b 74 d0 08                movq    0x8(%rax,%rdx,8), %rsi
// 27e: 49 89 74 d5 50                movq    %rsi, 0x50(%r13,%rdx,8)
// 283: 48 8b 74 d0 10                movq    0x10(%rax,%rdx,8), %rsi
// 288: 49 89 74 d5 58                movq    %rsi, 0x58(%r13,%rdx,8)
// 28d: 48 8b 74 d0 18                movq    0x18(%rax,%rdx,8), %rsi
// 292: 49 89 74 d5 60                movq    %rsi, 0x60(%r13,%rdx,8)
// 297: 48 83 c2 04                   addq    $0x4, %rdx
// 29b: 48 39 d1                      cmpq    %rdx, %rcx
// 29e: 75 d0                         jne     0x270 <_JIT_ENTRY+0x270>
// 2a0: eb 35                         jmp     0x2d7 <_JIT_ENTRY+0x2d7>
// 2a2: 89 ca                         movl    %ecx, %edx
// 2a4: 81 e2 fc ff ff 7f             andl    $0x7ffffffc, %edx       # imm = 0x7FFFFFFC
// 2aa: 31 f6                         xorl    %esi, %esi
// 2ac: 0f 1f 40 00                   nopl    (%rax)
// 2b0: 0f 10 04 f0                   movups  (%rax,%rsi,8), %xmm0
// 2b4: 0f 10 4c f0 10                movups  0x10(%rax,%rsi,8), %xmm1
// 2b9: 41 0f 11 44 f5 48             movups  %xmm0, 0x48(%r13,%rsi,8)
// 2bf: 41 0f 11 4c f5 58             movups  %xmm1, 0x58(%r13,%rsi,8)
// 2c5: 48 83 c6 04                   addq    $0x4, %rsi
// 2c9: 48 39 f2                      cmpq    %rsi, %rdx
// 2cc: 75 e2                         jne     0x2b0 <_JIT_ENTRY+0x2b0>
// 2ce: 48 39 ca                      cmpq    %rcx, %rdx
// 2d1: 0f 85 5c ff ff ff             jne     0x233 <_JIT_ENTRY+0x233>
// 2d7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000002d9:  R_X86_64_64  _JIT_OPARG
// 2e1: 0f b7 c0                      movzwl  %ax, %eax
// 2e4: b9 fe ff ff ff                movl    $0xfffffffe, %ecx       # imm = 0xFFFFFFFE
// 2e9: 29 c1                         subl    %eax, %ecx
// 2eb: 48 63 c1                      movslq  %ecx, %rax
// 2ee: 4d 89 6c c7 08                movq    %r13, 0x8(%r15,%rax,8)
// 2f3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000002f5:  R_X86_64_64  _JIT_CONTINUE
// 2fd: 48 8b 3c 24                   movq    (%rsp), %rdi
// 301: 4c 89 e6                      movq    %r12, %rsi
// 304: 48 89 da                      movq    %rbx, %rdx
// 307: 48 83 c4 08                   addq    $0x8, %rsp
// 30b: 5b                            popq    %rbx
// 30c: 41 5c                         popq    %r12
// 30e: 41 5d                         popq    %r13
// 310: 41 5e                         popq    %r14
// 312: 41 5f                         popq    %r15
// 314: 5d                            popq    %rbp
// 315: ff e0                         jmpq    *%rax
// 317: 
static const unsigned char _PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS_code_body[792] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf7, 0x48, 0x89, 0x3c, 0x24, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0xf7, 0xd0, 0x48, 0x63, 0xd0, 0x48, 0x63, 0xc1, 0x4c, 0x8b, 0x74, 0xc6, 0x08, 0x48, 0x8b, 0x4c, 0xd6, 0x08, 0x49, 0x8b, 0x6e, 0x30, 0x4c, 0x8b, 0xab, 0x00, 0x01, 0x00, 0x00, 0x48, 0x63, 0x45, 0x4c, 0x49, 0x8d, 0x44, 0xc5, 0x00, 0x48, 0x89, 0x83, 0x00, 0x01, 0x00, 0x00, 0x4d, 0x89, 0x75, 0x10, 0x8b, 0x45, 0x00, 0xff, 0xc0, 0x4c, 0x8d, 0x24, 0xd6, 0x49, 0x83, 0xc4, 0x08, 0x48, 0x85, 0xc9, 0x0f, 0x84, 0xbd, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x74, 0x0f, 0x89, 0x45, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x89, 0x6d, 0x00, 0x41, 0x0f, 0x10, 0x46, 0x10, 0x41, 0x0f, 0x11, 0x45, 0x18, 0x49, 0xc7, 0x45, 0x28, 0x00, 0x00, 0x00, 0x00, 0x8b, 0x45, 0x48, 0x41, 0x89, 0x45, 0x40, 0x49, 0xc7, 0x45, 0x30, 0x00, 0x00, 0x00, 0x00, 0x48, 0x81, 0xc5, 0xc8, 0x00, 0x00, 0x00, 0x49, 0x89, 0x6d, 0x38, 0x66, 0x41, 0xc7, 0x45, 0x44, 0x00, 0x00, 0x41, 0xc6, 0x45, 0x46, 0x00, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xea, 0xff, 0xc5, 0x85, 0xed, 0x0f, 0x9f, 0xc1, 0x39, 0xe8, 0x0f, 0x8e, 0x07, 0x01, 0x00, 0x00, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x0f, 0xb7, 0xee, 0xff, 0xc5, 0x48, 0x8d, 0x3c, 0xed, 0x48, 0x00, 0x00, 0x00, 0x4c, 0x01, 0xef, 0x89, 0xe9, 0xf7, 0xd1, 0x01, 0xc8, 0x48, 0x8d, 0x14, 0xc5, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x85, 0xed, 0x0f, 0x8e, 0xb6, 0x01, 0x00, 0x00, 0x41, 0x0f, 0xb7, 0xce, 0x48, 0xc1, 0xe1, 0x03, 0x4c, 0x89, 0xf8, 0x48, 0x29, 0xc8, 0xe9, 0xdd, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x74, 0x0f, 0x89, 0x45, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x89, 0x6d, 0x00, 0x41, 0x0f, 0x10, 0x46, 0x10, 0x41, 0x0f, 0x11, 0x45, 0x18, 0x49, 0xc7, 0x45, 0x28, 0x00, 0x00, 0x00, 0x00, 0x8b, 0x45, 0x48, 0x41, 0x89, 0x45, 0x40, 0x49, 0xc7, 0x45, 0x30, 0x00, 0x00, 0x00, 0x00, 0x48, 0x81, 0xc5, 0xc8, 0x00, 0x00, 0x00, 0x49, 0x89, 0x6d, 0x38, 0x66, 0x41, 0xc7, 0x45, 0x44, 0x00, 0x00, 0x41, 0xc6, 0x45, 0x46, 0x00, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xea, 0x85, 0xed, 0x0f, 0x9f, 0xc1, 0x39, 0xe8, 0x7e, 0x60, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xf1, 0x4a, 0x8d, 0x3c, 0xf5, 0x48, 0x00, 0x00, 0x00, 0x4c, 0x01, 0xef, 0x0f, 0xb7, 0xe9, 0x89, 0xe9, 0xf7, 0xd1, 0x01, 0xc8, 0x48, 0x8d, 0x14, 0xc5, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x85, 0xed, 0x0f, 0x8e, 0xfe, 0x00, 0x00, 0x00, 0x49, 0xc1, 0xe6, 0x03, 0x4c, 0x89, 0xf8, 0x4c, 0x29, 0xf0, 0x48, 0x83, 0xc0, 0x08, 0xeb, 0x28, 0x0f, 0xb7, 0xc2, 0x48, 0xf7, 0xd8, 0xf6, 0xc1, 0x01, 0x75, 0x19, 0xe9, 0xde, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd2, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x48, 0x29, 0xd0, 0xf6, 0xc1, 0x01, 0x0f, 0x84, 0xca, 0x00, 0x00, 0x00, 0x49, 0x8d, 0x04, 0xc7, 0x83, 0xfd, 0x02, 0xb9, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x4d, 0xcd, 0x83, 0xf9, 0x08, 0x72, 0x10, 0x4c, 0x89, 0xea, 0x48, 0x29, 0xc2, 0x48, 0x83, 0xc2, 0x48, 0x48, 0x83, 0xfa, 0x20, 0x73, 0x71, 0x31, 0xd2, 0x48, 0x89, 0xd6, 0x48, 0xf7, 0xd6, 0x48, 0x01, 0xce, 0x48, 0x89, 0xcf, 0x48, 0x83, 0xe7, 0x03, 0x74, 0x1c, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x04, 0xd0, 0x4d, 0x89, 0x44, 0xd5, 0x48, 0x48, 0xff, 0xc2, 0x48, 0xff, 0xcf, 0x75, 0xef, 0x48, 0x83, 0xfe, 0x03, 0x72, 0x70, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x34, 0xd0, 0x49, 0x89, 0x74, 0xd5, 0x48, 0x48, 0x8b, 0x74, 0xd0, 0x08, 0x49, 0x89, 0x74, 0xd5, 0x50, 0x48, 0x8b, 0x74, 0xd0, 0x10, 0x49, 0x89, 0x74, 0xd5, 0x58, 0x48, 0x8b, 0x74, 0xd0, 0x18, 0x49, 0x89, 0x74, 0xd5, 0x60, 0x48, 0x83, 0xc2, 0x04, 0x48, 0x39, 0xd1, 0x75, 0xd0, 0xeb, 0x35, 0x89, 0xca, 0x81, 0xe2, 0xfc, 0xff, 0xff, 0x7f, 0x31, 0xf6, 0x0f, 0x1f, 0x40, 0x00, 0x0f, 0x10, 0x04, 0xf0, 0x0f, 0x10, 0x4c, 0xf0, 0x10, 0x41, 0x0f, 0x11, 0x44, 0xf5, 0x48, 0x41, 0x0f, 0x11, 0x4c, 0xf5, 0x58, 0x48, 0x83, 0xc6, 0x04, 0x48, 0x39, 0xf2, 0x75, 0xe2, 0x48, 0x39, 0xca, 0x0f, 0x85, 0x5c, 0xff, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0xb9, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xc1, 0x48, 0x63, 0xc1, 0x4d, 0x89, 0x6c, 0xc7, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3c, 0x24, 0x4c, 0x89, 0xe6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS_code_holes[12] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x80, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0xc8, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xe4, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x10d, HoleKind_R_X86_64_64, HoleValue_ZERO, &memset, 0x0},
    {0x13d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x185, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x19b, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1c5, HoleKind_R_X86_64_64, HoleValue_ZERO, &memset, 0x0},
    {0x2d9, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2f5, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS_data_body[1];
static const Hole _PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS_data_holes[1];

// _PUSH_NULLplus_INSERT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_INSERT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 48 89 d3                      movq    %rdx, %rbx
// c: 49 89 f6                      movq    %rsi, %r14
// f: 49 89 ff                      movq    %rdi, %r15
// 12: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 19: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001b:  R_X86_64_64  _JIT_OPARG
// 23: 0f b7 d0                      movzwl  %ax, %edx
// 26: f7 d0                         notl    %eax
// 28: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 2d: 4c 63 e8                      movslq  %eax, %r13
// 30: 4a 8d 3c ee                   leaq    (%rsi,%r13,8), %rdi
// 34: 48 83 c7 08                   addq    $0x8, %rdi
// 38: 48 c1 e2 03                   shlq    $0x3, %rdx
// 3c: 4c 8d 66 08                   leaq    0x8(%rsi), %r12
// 40: 4c 89 e6                      movq    %r12, %rsi
// 43: 48 29 d6                      subq    %rdx, %rsi
// 46: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000048:  R_X86_64_64  memmove
// 50: ff d0                         callq   *%rax
// 52: 4b c7 44 ee 08 00 00 00 00    movq    $0x0, 0x8(%r14,%r13,8)
// 5b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005d:  R_X86_64_64  _JIT_CONTINUE
// 65: 4c 89 ff                      movq    %r15, %rdi
// 68: 4c 89 e6                      movq    %r12, %rsi
// 6b: 48 89 da                      movq    %rbx, %rdx
// 6e: 5b                            popq    %rbx
// 6f: 41 5c                         popq    %r12
// 71: 41 5d                         popq    %r13
// 73: 41 5e                         popq    %r14
// 75: 41 5f                         popq    %r15
// 77: ff e0                         jmpq    *%rax
// 79: 
static const unsigned char _PUSH_NULLplus_INSERT_code_body[122] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x4c, 0x63, 0xe8, 0x4a, 0x8d, 0x3c, 0xee, 0x48, 0x83, 0xc7, 0x08, 0x48, 0xc1, 0xe2, 0x03, 0x4c, 0x8d, 0x66, 0x08, 0x4c, 0x89, 0xe6, 0x48, 0x29, 0xd6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4b, 0xc7, 0x44, 0xee, 0x08, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe6, 0x48, 0x89, 0xda, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_INSERT_code_holes[4] = {
    {0x1b, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_ZERO, &memmove, 0x0},
    {0x5d, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_INSERT_data_body[1];
static const Hole _PUSH_NULLplus_INSERT_data_holes[1];

// _PUSH_NULLplus_IS_NONE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_IS_NONE.o:      file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_IS_NONE_code_body[1] = {};
static const Hole _PUSH_NULLplus_IS_NONE_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_IS_NONE_data_body[1];
static const Hole _PUSH_NULLplus_IS_NONE_data_holes[1];

// _PUSH_NULLplus_IS_OP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_IS_OP.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 10: 7f 1e                         jg      0x30 <_JIT_ENTRY+0x30>
// 12: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000014:  R_X86_64_64  .rodata.str1.1
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _Py_NegativeRefcount
// 26: be 98 07 00 00                movl    $0x798, %esi            # imm = 0x798
// 2b: 48 89 da                      movq    %rbx, %rdx
// 2e: ff d0                         callq   *%rax
// 30: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000032:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 3a: ff d0                         callq   *%rax
// 3c: 48 ff 0b                      decq    (%rbx)
// 3f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000041:  R_X86_64_64  _Py_Dealloc
// 49: 48 89 df                      movq    %rbx, %rdi
// 4c: ff d0                         callq   *%rax
// 4e: 
static const unsigned char _PUSH_NULLplus_IS_OP_code_body[79] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x98, 0x07, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_IS_OP_code_holes[5] = {
    {0x14, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x1e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_IS_OP_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_IS_OP_data_holes[1];

// _PUSH_NULLplus_ITER_CHECK_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_CHECK_LIST.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  PyListIter_Type
// 15: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1d: 74 28                         je      0x47 <_JIT_ENTRY+0x47>
// 1f: 48 29 fe                      subq    %rdi, %rsi
// 22: 48 83 c6 b8                   addq    $-0x48, %rsi
// 26: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2a: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2d: 48 8b 07                      movq    (%rdi), %rax
// 30: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000032:  R_X86_64_64  _JIT_TARGET
// 3a: 89 c9                         movl    %ecx, %ecx
// 3c: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 40: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 46: c3                            retq
// 47: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000049:  R_X86_64_64  _JIT_CONTINUE
// 51: ff e0                         jmpq    *%rax
// 53: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_LIST_code_body[84] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_ITER_CHECK_LIST_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyListIter_Type, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x49, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_LIST_data_body[1];
static const Hole _PUSH_NULLplus_ITER_CHECK_LIST_data_holes[1];

// _PUSH_NULLplus_ITER_CHECK_RANGE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_CHECK_RANGE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  PyRangeIter_Type
// 15: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1d: 74 28                         je      0x47 <_JIT_ENTRY+0x47>
// 1f: 48 29 fe                      subq    %rdi, %rsi
// 22: 48 83 c6 b8                   addq    $-0x48, %rsi
// 26: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2a: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2d: 48 8b 07                      movq    (%rdi), %rax
// 30: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000032:  R_X86_64_64  _JIT_TARGET
// 3a: 89 c9                         movl    %ecx, %ecx
// 3c: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 40: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 46: c3                            retq
// 47: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000049:  R_X86_64_64  _JIT_CONTINUE
// 51: ff e0                         jmpq    *%rax
// 53: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_RANGE_code_body[84] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_ITER_CHECK_RANGE_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyRangeIter_Type, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x49, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_RANGE_data_body[1];
static const Hole _PUSH_NULLplus_ITER_CHECK_RANGE_data_holes[1];

// _PUSH_NULLplus_ITER_CHECK_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_CHECK_TUPLE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  PyTupleIter_Type
// 15: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1d: 74 28                         je      0x47 <_JIT_ENTRY+0x47>
// 1f: 48 29 fe                      subq    %rdi, %rsi
// 22: 48 83 c6 b8                   addq    $-0x48, %rsi
// 26: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2a: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2d: 48 8b 07                      movq    (%rdi), %rax
// 30: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000032:  R_X86_64_64  _JIT_TARGET
// 3a: 89 c9                         movl    %ecx, %ecx
// 3c: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 40: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 46: c3                            retq
// 47: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000049:  R_X86_64_64  _JIT_CONTINUE
// 51: ff e0                         jmpq    *%rax
// 53: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_TUPLE_code_body[84] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_ITER_CHECK_TUPLE_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTupleIter_Type, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x49, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_CHECK_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_ITER_CHECK_TUPLE_data_holes[1];

// _PUSH_NULLplus_ITER_NEXT_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_NEXT_LIST.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 8b 04 25 10 00 00 00       movq    0x10, %rax
// 20: 48 8b 0c 25 18 00 00 00       movq    0x18, %rcx
// 28: 48 8b 49 18                   movq    0x18(%rcx), %rcx
// 2c: 48 8d 50 01                   leaq    0x1(%rax), %rdx
// 30: 48 89 14 25 10 00 00 00       movq    %rdx, 0x10
// 38: 4c 8b 24 c1                   movq    (%rcx,%rax,8), %r12
// 3c: 41 8b 04 24                   movl    (%r12), %eax
// 40: ff c0                         incl    %eax
// 42: 74 10                         je      0x54 <_JIT_ENTRY+0x54>
// 44: 41 89 04 24                   movl    %eax, (%r12)
// 48: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004a:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 52: ff d0                         callq   *%rax
// 54: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 58: 49 83 c6 10                   addq    $0x10, %r14
// 5c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005e:  R_X86_64_64  _JIT_CONTINUE
// 66: 4c 89 ff                      movq    %r15, %rdi
// 69: 4c 89 f6                      movq    %r14, %rsi
// 6c: 48 89 da                      movq    %rbx, %rdx
// 6f: 48 83 c4 08                   addq    $0x8, %rsp
// 73: 5b                            popq    %rbx
// 74: 41 5c                         popq    %r12
// 76: 41 5e                         popq    %r14
// 78: 41 5f                         popq    %r15
// 7a: ff e0                         jmpq    *%rax
// 7c: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_LIST_code_body[125] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x49, 0x18, 0x48, 0x8d, 0x50, 0x01, 0x48, 0x89, 0x14, 0x25, 0x10, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x24, 0xc1, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_ITER_NEXT_LIST_code_holes[3] = {
    {0x4a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x5e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_LIST_data_body[1];
static const Hole _PUSH_NULLplus_ITER_NEXT_LIST_data_holes[1];

// _PUSH_NULLplus_ITER_NEXT_RANGE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_NEXT_RANGE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 8b 3c 25 10 00 00 00       movq    0x10, %rdi
// 1d: 48 8b 04 25 18 00 00 00       movq    0x18, %rax
// 25: 48 01 f8                      addq    %rdi, %rax
// 28: 48 89 04 25 10 00 00 00       movq    %rax, 0x10
// 30: 48 ff 0c 25 20 00 00 00       decq    0x20
// 38: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003a:  R_X86_64_64  PyLong_FromLong
// 42: ff d0                         callq   *%rax
// 44: 48 85 c0                      testq   %rax, %rax
// 47: 74 22                         je      0x6b <_JIT_ENTRY+0x6b>
// 49: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 4d: 48 83 c3 10                   addq    $0x10, %rbx
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: 4c 89 f7                      movq    %r14, %rdi
// 5e: 48 89 de                      movq    %rbx, %rsi
// 61: 4c 89 fa                      movq    %r15, %rdx
// 64: 5b                            popq    %rbx
// 65: 41 5e                         popq    %r14
// 67: 41 5f                         popq    %r15
// 69: ff e0                         jmpq    *%rax
// 6b: 48 83 c3 08                   addq    $0x8, %rbx
// 6f: 4c 29 f3                      subq    %r14, %rbx
// 72: 48 83 c3 b8                   addq    $-0x48, %rbx
// 76: 48 c1 eb 03                   shrq    $0x3, %rbx
// 7a: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 7e: 31 c0                         xorl    %eax, %eax
// 80: 5b                            popq    %rbx
// 81: 41 5e                         popq    %r14
// 83: 41 5f                         popq    %r15
// 85: c3                            retq
// 86: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_RANGE_code_body[135] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x01, 0xf8, 0x48, 0x89, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0xff, 0x0c, 0x25, 0x20, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x22, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_ITER_NEXT_RANGE_code_holes[3] = {
    {0x3a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_FromLong, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_RANGE_data_body[1];
static const Hole _PUSH_NULLplus_ITER_NEXT_RANGE_data_holes[1];

// _PUSH_NULLplus_ITER_NEXT_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_ITER_NEXT_TUPLE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 8b 04 25 10 00 00 00       movq    0x10, %rax
// 20: 48 8b 0c 25 18 00 00 00       movq    0x18, %rcx
// 28: 48 8d 50 01                   leaq    0x1(%rax), %rdx
// 2c: 48 89 14 25 10 00 00 00       movq    %rdx, 0x10
// 34: 4c 8b 64 c1 18                movq    0x18(%rcx,%rax,8), %r12
// 39: 41 8b 04 24                   movl    (%r12), %eax
// 3d: ff c0                         incl    %eax
// 3f: 74 10                         je      0x51 <_JIT_ENTRY+0x51>
// 41: 41 89 04 24                   movl    %eax, (%r12)
// 45: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000047:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 4f: ff d0                         callq   *%rax
// 51: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 55: 49 83 c6 10                   addq    $0x10, %r14
// 59: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005b:  R_X86_64_64  _JIT_CONTINUE
// 63: 4c 89 ff                      movq    %r15, %rdi
// 66: 4c 89 f6                      movq    %r14, %rsi
// 69: 48 89 da                      movq    %rbx, %rdx
// 6c: 48 83 c4 08                   addq    $0x8, %rsp
// 70: 5b                            popq    %rbx
// 71: 41 5c                         popq    %r12
// 73: 41 5e                         popq    %r14
// 75: 41 5f                         popq    %r15
// 77: ff e0                         jmpq    *%rax
// 79: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_TUPLE_code_body[122] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x50, 0x01, 0x48, 0x89, 0x14, 0x25, 0x10, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x64, 0xc1, 0x18, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_ITER_NEXT_TUPLE_code_holes[3] = {
    {0x47, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_ITER_NEXT_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_ITER_NEXT_TUPLE_data_holes[1];

// _PUSH_NULLplus_JUMP_TO_TOP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_JUMP_TO_TOP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 83 c3 08                   addq    $0x8, %rbx
// 19: 48 8b 42 10                   movq    0x10(%rdx), %rax
// 1d: 48 8b 00                      movq    (%rax), %rax
// 20: 84 c0                         testb   %al, %al
// 22: 74 2a                         je      0x4e <_JIT_ENTRY+0x4e>
// 24: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000026:  R_X86_64_64  _Py_HandlePending
// 2e: 4c 89 ff                      movq    %r15, %rdi
// 31: ff d0                         callq   *%rax
// 33: 85 c0                         testl   %eax, %eax
// 35: 74 17                         je      0x4e <_JIT_ENTRY+0x4e>
// 37: 4c 29 f3                      subq    %r14, %rbx
// 3a: 48 83 c3 b8                   addq    $-0x48, %rbx
// 3e: 48 c1 eb 03                   shrq    $0x3, %rbx
// 42: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 46: 31 c0                         xorl    %eax, %eax
// 48: 5b                            popq    %rbx
// 49: 41 5e                         popq    %r14
// 4b: 41 5f                         popq    %r15
// 4d: c3                            retq
// 4e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000050:  R_X86_64_64  _JIT_CONTINUE
// 58: 4c 89 f7                      movq    %r14, %rdi
// 5b: 48 89 de                      movq    %rbx, %rsi
// 5e: 4c 89 fa                      movq    %r15, %rdx
// 61: 5b                            popq    %rbx
// 62: 41 5e                         popq    %r14
// 64: 41 5f                         popq    %r15
// 66: ff e0                         jmpq    *%rax
// 68: 
static const unsigned char _PUSH_NULLplus_JUMP_TO_TOP_code_body[105] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0x8b, 0x42, 0x10, 0x48, 0x8b, 0x00, 0x84, 0xc0, 0x74, 0x2a, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x85, 0xc0, 0x74, 0x17, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_JUMP_TO_TOP_code_holes[3] = {
    {0x26, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_HandlePending, 0x0},
    {0x50, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_JUMP_TO_TOP_data_body[1];
static const Hole _PUSH_NULLplus_JUMP_TO_TOP_data_holes[1];

// _PUSH_NULLplus_LIST_APPEND
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LIST_APPEND.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000017:  R_X86_64_64  _JIT_OPARG
// 1f: f7 d0                         notl    %eax
// 21: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 26: 48 98                         cltq
// 28: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 2d: 48 8b 47 10                   movq    0x10(%rdi), %rax
// 31: 48 39 47 20                   cmpq    %rax, 0x20(%rdi)
// 35: 7e 15                         jle     0x4c <_JIT_ENTRY+0x4c>
// 37: 48 8b 4f 18                   movq    0x18(%rdi), %rcx
// 3b: 48 c7 04 c1 00 00 00 00       movq    $0x0, (%rcx,%rax,8)
// 43: 48 ff c0                      incq    %rax
// 46: 48 89 47 10                   movq    %rax, 0x10(%rdi)
// 4a: eb 12                         jmp     0x5e <_JIT_ENTRY+0x5e>
// 4c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004e:  R_X86_64_64  _PyList_AppendTakeRefListResize
// 56: 31 f6                         xorl    %esi, %esi
// 58: ff d0                         callq   *%rax
// 5a: 85 c0                         testl   %eax, %eax
// 5c: 78 1a                         js      0x78 <_JIT_ENTRY+0x78>
// 5e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000060:  R_X86_64_64  _JIT_CONTINUE
// 68: 4c 89 f7                      movq    %r14, %rdi
// 6b: 48 89 de                      movq    %rbx, %rsi
// 6e: 4c 89 fa                      movq    %r15, %rdx
// 71: 5b                            popq    %rbx
// 72: 41 5e                         popq    %r14
// 74: 41 5f                         popq    %r15
// 76: ff e0                         jmpq    *%rax
// 78: 4c 29 f3                      subq    %r14, %rbx
// 7b: 48 83 c3 b8                   addq    $-0x48, %rbx
// 7f: 48 c1 eb 03                   shrq    $0x3, %rbx
// 83: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 87: 31 c0                         xorl    %eax, %eax
// 89: 5b                            popq    %rbx
// 8a: 41 5e                         popq    %r14
// 8c: 41 5f                         popq    %r15
// 8e: c3                            retq
// 8f: 
static const unsigned char _PUSH_NULLplus_LIST_APPEND_code_body[144] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0x8b, 0x47, 0x10, 0x48, 0x39, 0x47, 0x20, 0x7e, 0x15, 0x48, 0x8b, 0x4f, 0x18, 0x48, 0xc7, 0x04, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x47, 0x10, 0xeb, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0x1a, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LIST_APPEND_code_holes[4] = {
    {0x17, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyList_AppendTakeRefListResize, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LIST_APPEND_data_body[1];
static const Hole _PUSH_NULLplus_LIST_APPEND_data_holes[1];

// _PUSH_NULLplus_LIST_EXTEND
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LIST_EXTEND.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 56                         pushq   %r14
// 2: 53                            pushq   %rbx
// 3: 50                            pushq   %rax
// 4: 48 89 d3                      movq    %rdx, %rbx
// 7: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000010:  R_X86_64_64  _JIT_OPARG
// 18: f7 d0                         notl    %eax
// 1a: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 1f: 48 98                         cltq
// 21: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 26: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000028:  R_X86_64_64  _PyList_Extend
// 30: 31 f6                         xorl    %esi, %esi
// 32: ff d0                         callq   *%rax
// 34: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 0000000000000036:  R_X86_64_64  PyExc_TypeError
// 3e: 49 8b 36                      movq    (%r14), %rsi
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _PyErr_ExceptionMatches
// 4b: 48 89 df                      movq    %rbx, %rdi
// 4e: ff d0                         callq   *%rax
// 50: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000052:  R_X86_64_64  PySequence_Check
// 5a: 31 ff                         xorl    %edi, %edi
// 5c: ff d0                         callq   *%rax
// 5e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000060:  R_X86_64_64  _PyErr_Clear
// 68: 48 89 df                      movq    %rbx, %rdi
// 6b: ff d0                         callq   *%rax
// 6d: 49 8b 36                      movq    (%r14), %rsi
// 70: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// 78: 48 8b 48 18                   movq    0x18(%rax), %rcx
// 7c: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000007e:  R_X86_64_64  .rodata.str1.1
// 86: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000088:  R_X86_64_64  _PyErr_Format
// 90: 48 89 df                      movq    %rbx, %rdi
// 93: 31 c0                         xorl    %eax, %eax
// 95: 41 ff d0                      callq   *%r8
// 98: 
static const unsigned char _PUSH_NULLplus_LIST_EXTEND_code_body[153] = {0x41, 0x56, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x36, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0, 0x49, 0x8b, 0x36, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x48, 0x18, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xc0, 0x41, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LIST_EXTEND_code_holes[9] = {
    {0x10, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x28, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyList_Extend, 0x0},
    {0x36, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_TypeError, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_ExceptionMatches, 0x0},
    {0x52, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySequence_Check, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Clear, 0x0},
    {0x7e, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x88, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
};
// 0: 'Value after * must be an iterable, not %.200s\x00'
// 2e: 00 00
static const unsigned char _PUSH_NULLplus_LIST_EXTEND_data_body[49] = {0x56, 0x61, 0x6c, 0x75, 0x65, 0x20, 0x61, 0x66, 0x74, 0x65, 0x72, 0x20, 0x2a, 0x20, 0x6d, 0x75, 0x73, 0x74, 0x20, 0x62, 0x65, 0x20, 0x61, 0x6e, 0x20, 0x69, 0x74, 0x65, 0x72, 0x61, 0x62, 0x6c, 0x65, 0x2c, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LIST_EXTEND_data_holes[1];

// _PUSH_NULLplus_LOAD_ASSERTION_ERROR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ASSERTION_ERROR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  PyExc_AssertionError
// 22: 4c 8b 20                      movq    (%rax), %r12
// 25: 41 8b 04 24                   movl    (%r12), %eax
// 29: ff c0                         incl    %eax
// 2b: 74 10                         je      0x3d <_JIT_ENTRY+0x3d>
// 2d: 41 89 04 24                   movl    %eax, (%r12)
// 31: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000033:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 3b: ff d0                         callq   *%rax
// 3d: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 41: 49 83 c6 10                   addq    $0x10, %r14
// 45: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000047:  R_X86_64_64  _JIT_CONTINUE
// 4f: 4c 89 ff                      movq    %r15, %rdi
// 52: 4c 89 f6                      movq    %r14, %rsi
// 55: 48 89 da                      movq    %rbx, %rdx
// 58: 48 83 c4 08                   addq    $0x8, %rsp
// 5c: 5b                            popq    %rbx
// 5d: 41 5c                         popq    %r12
// 5f: 41 5e                         popq    %r14
// 61: 41 5f                         popq    %r15
// 63: ff e0                         jmpq    *%rax
// 65: 
static const unsigned char _PUSH_NULLplus_LOAD_ASSERTION_ERROR_code_body[102] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x20, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_ASSERTION_ERROR_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_AssertionError, 0x0},
    {0x33, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x47, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ASSERTION_ERROR_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ASSERTION_ERROR_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 48 83 ec 10                   subq    $0x10, %rsp
// 9: 48 89 d3                      movq    %rdx, %rbx
// c: 49 89 f7                      movq    %rsi, %r15
// f: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 16: 48 8b 07                      movq    (%rdi), %rax
// 19: 48 8b 40 20                   movq    0x20(%rax), %rax
// 1d: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001f:  R_X86_64_64  _JIT_OPARG
// 27: 89 ca                         movl    %ecx, %edx
// 29: 81 e2 fe ff 00 00             andl    $0xfffe, %edx           # imm = 0xFFFE
// 2f: 48 8b 74 90 18                movq    0x18(%rax,%rdx,4), %rsi
// 34: f6 c1 01                      testb   $0x1, %cl
// 37: 74 5f                         je      0x98 <_JIT_ENTRY+0x98>
// 39: 49 89 fe                      movq    %rdi, %r14
// 3c: 48 c7 44 24 08 00 00 00 00    movq    $0x0, 0x8(%rsp)
// 45: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000047:  R_X86_64_64  _PyObject_GetMethod
// 4f: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 54: 31 ff                         xorl    %edi, %edi
// 56: ff d0                         callq   *%rax
// 58: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 5d: 49 89 07                      movq    %rax, (%r15)
// 60: 49 c7 47 08 00 00 00 00       movq    $0x0, 0x8(%r15)
// 68: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006a:  R_X86_64_64  _JIT_OPARG
// 72: 83 e0 01                      andl    $0x1, %eax
// 75: 49 8d 34 c7                   leaq    (%r15,%rax,8), %rsi
// 79: 48 83 c6 08                   addq    $0x8, %rsi
// 7d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007f:  R_X86_64_64  _JIT_CONTINUE
// 87: 4c 89 f7                      movq    %r14, %rdi
// 8a: 48 89 da                      movq    %rbx, %rdx
// 8d: 48 83 c4 10                   addq    $0x10, %rsp
// 91: 5b                            popq    %rbx
// 92: 41 5e                         popq    %r14
// 94: 41 5f                         popq    %r15
// 96: ff e0                         jmpq    *%rax
// 98: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000009a:  R_X86_64_64  PyObject_GetAttr
// a2: 31 ff                         xorl    %edi, %edi
// a4: ff d0                         callq   *%rax
// a6: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_code_body[167] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x48, 0x83, 0xec, 0x10, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xca, 0x81, 0xe2, 0xfe, 0xff, 0x00, 0x00, 0x48, 0x8b, 0x74, 0x90, 0x18, 0xf6, 0xc1, 0x01, 0x74, 0x5f, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x44, 0x24, 0x08, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x49, 0x89, 0x07, 0x49, 0xc7, 0x47, 0x08, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xe0, 0x01, 0x49, 0x8d, 0x34, 0xc7, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_code_holes[6] = {
    {0x1f, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x47, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyObject_GetMethod, 0x0},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x7f, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x9a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GetAttr, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_CLASS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_CLASS.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  _JIT_OPERAND
// 12: ff 00                         incl    (%rax)
// 14: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000016:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 1e: ff d0                         callq   *%rax
// 20: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_CLASS_code_body[33] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_CLASS_code_holes[3] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x16, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_CLASS_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_CLASS_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 04 25 e8 ff ff ff       movq    -0x18, %rax
// 10: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000012:  R_X86_64_64  _JIT_OPERAND
// 1a: 0f b7 c9                      movzwl  %cx, %ecx
// 1d: 48 8b 44 c8 01                movq    0x1(%rax,%rcx,8), %rax
// 22: 48 85 c0                      testq   %rax, %rax
// 25: 75 29                         jne     0x50 <_JIT_ENTRY+0x50>
// 27: 48 29 fe                      subq    %rdi, %rsi
// 2a: 48 83 c6 c0                   addq    $-0x40, %rsi
// 2e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 32: 89 77 40                      movl    %esi, 0x40(%rdi)
// 35: 48 8b 07                      movq    (%rdi), %rax
// 38: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003a:  R_X86_64_64  _JIT_TARGET
// 42: 89 c9                         movl    %ecx, %ecx
// 44: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 48: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4e: 59                            popq    %rcx
// 4f: c3                            retq
// 50: ff 00                         incl    (%rax)
// 52: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000054:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 5c: ff d0                         callq   *%rax
// 5e: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE_code_body[95] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x44, 0xc8, 0x01, 0x48, 0x85, 0xc0, 0x75, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE_code_holes[4] = {
    {0x12, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x54, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 000000000000001a:  R_X86_64_64  _JIT_OPERAND
// 22: 41 8b 04 24                   movl    (%r12), %eax
// 26: ff c0                         incl    %eax
// 28: 74 10                         je      0x3a <_JIT_ENTRY+0x3a>
// 2a: 41 89 04 24                   movl    %eax, (%r12)
// 2e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000030:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 38: ff d0                         callq   *%rax
// 3a: 4d 89 26                      movq    %r12, (%r14)
// 3d: 49 c7 46 08 00 00 00 00       movq    $0x0, 0x8(%r14)
// 45: 49 83 c6 10                   addq    $0x10, %r14
// 49: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004b:  R_X86_64_64  _JIT_CONTINUE
// 53: 4c 89 ff                      movq    %r15, %rdi
// 56: 4c 89 f6                      movq    %r14, %rsi
// 59: 48 89 da                      movq    %rbx, %rdx
// 5c: 48 83 c4 08                   addq    $0x8, %rsp
// 60: 5b                            popq    %rbx
// 61: 41 5c                         popq    %r12
// 63: 41 5e                         popq    %r14
// 65: 41 5f                         popq    %r15
// 67: ff e0                         jmpq    *%rax
// 69: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT_code_body[106] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x26, 0x49, 0xc7, 0x46, 0x08, 0x00, 0x00, 0x00, 0x00, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 000000000000001a:  R_X86_64_64  _JIT_OPERAND
// 22: 41 8b 04 24                   movl    (%r12), %eax
// 26: ff c0                         incl    %eax
// 28: 74 10                         je      0x3a <_JIT_ENTRY+0x3a>
// 2a: 41 89 04 24                   movl    %eax, (%r12)
// 2e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000030:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 38: ff d0                         callq   *%rax
// 3a: 4d 89 26                      movq    %r12, (%r14)
// 3d: 49 c7 46 08 00 00 00 00       movq    $0x0, 0x8(%r14)
// 45: 49 83 c6 10                   addq    $0x10, %r14
// 49: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004b:  R_X86_64_64  _JIT_CONTINUE
// 53: 4c 89 ff                      movq    %r15, %rdi
// 56: 4c 89 f6                      movq    %r14, %rsi
// 59: 48 89 da                      movq    %rbx, %rdx
// 5c: 48 83 c4 08                   addq    $0x8, %rsp
// 60: 5b                            popq    %rbx
// 61: 41 5c                         popq    %r12
// 63: 41 5e                         popq    %r14
// 65: 41 5f                         popq    %r15
// 67: ff e0                         jmpq    *%rax
// 69: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT_code_body[106] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x26, 0x49, 0xc7, 0x46, 0x08, 0x00, 0x00, 0x00, 0x00, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 000000000000001a:  R_X86_64_64  _JIT_OPERAND
// 22: 41 8b 04 24                   movl    (%r12), %eax
// 26: ff c0                         incl    %eax
// 28: 74 10                         je      0x3a <_JIT_ENTRY+0x3a>
// 2a: 41 89 04 24                   movl    %eax, (%r12)
// 2e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000030:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 38: ff d0                         callq   *%rax
// 3a: 4d 89 26                      movq    %r12, (%r14)
// 3d: 49 c7 46 08 00 00 00 00       movq    $0x0, 0x8(%r14)
// 45: 49 83 c6 10                   addq    $0x10, %r14
// 49: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004b:  R_X86_64_64  _JIT_CONTINUE
// 53: 4c 89 ff                      movq    %r15, %rdi
// 56: 4c 89 f6                      movq    %r14, %rsi
// 59: 48 89 da                      movq    %rbx, %rdx
// 5c: 48 83 c4 08                   addq    $0x8, %rsp
// 60: 5b                            popq    %rbx
// 61: 41 5c                         popq    %r12
// 63: 41 5e                         popq    %r14
// 65: 41 5f                         popq    %r15
// 67: ff e0                         jmpq    *%rax
// 69: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES_code_body[106] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x26, 0x49, 0xc7, 0x46, 0x08, 0x00, 0x00, 0x00, 0x00, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_MODULE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_MODULE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 04 25 10 00 00 00       movq    0x10, %rax
// 10: 48 8b 40 20                   movq    0x20(%rax), %rax
// 14: 0f b6 48 09                   movzbl  0x9(%rax), %ecx
// 18: ba 01 00 00 00                movl    $0x1, %edx
// 1d: 48 d3 e2                      shlq    %cl, %rdx
// 20: 48 01 c2                      addq    %rax, %rdx
// 23: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000025:  R_X86_64_64  _JIT_OPERAND
// 2d: 0f b7 c0                      movzwl  %ax, %eax
// 30: 48 c1 e0 04                   shlq    $0x4, %rax
// 34: 48 8b 44 10 28                movq    0x28(%rax,%rdx), %rax
// 39: 48 85 c0                      testq   %rax, %rax
// 3c: 75 29                         jne     0x67 <_JIT_ENTRY+0x67>
// 3e: 48 29 fe                      subq    %rdi, %rsi
// 41: 48 83 c6 c0                   addq    $-0x40, %rsi
// 45: 48 c1 ee 03                   shrq    $0x3, %rsi
// 49: 89 77 40                      movl    %esi, 0x40(%rdi)
// 4c: 48 8b 07                      movq    (%rdi), %rax
// 4f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000051:  R_X86_64_64  _JIT_TARGET
// 59: 89 c9                         movl    %ecx, %ecx
// 5b: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 5f: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 65: 59                            popq    %rcx
// 66: c3                            retq
// 67: ff 00                         incl    (%rax)
// 69: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006b:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 73: ff d0                         callq   *%rax
// 75: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_MODULE_code_body[118] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x40, 0x20, 0x0f, 0xb6, 0x48, 0x09, 0xba, 0x01, 0x00, 0x00, 0x00, 0x48, 0xd3, 0xe2, 0x48, 0x01, 0xc2, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x04, 0x48, 0x8b, 0x44, 0x10, 0x28, 0x48, 0x85, 0xc0, 0x75, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_MODULE_code_holes[4] = {
    {0x25, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x6b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_MODULE_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_MODULE_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT.o:      file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_code_body[1] = {};
static const Hole _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES.o:  file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_code_body[1] = {};
static const Hole _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_SLOT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_SLOT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  _JIT_OPERAND
// 12: 0f b7 c0                      movzwl  %ax, %eax
// 15: 48 8b 00                      movq    (%rax), %rax
// 18: 48 85 c0                      testq   %rax, %rax
// 1b: 75 29                         jne     0x46 <_JIT_ENTRY+0x46>
// 1d: 48 29 fe                      subq    %rdi, %rsi
// 20: 48 83 c6 c0                   addq    $-0x40, %rsi
// 24: 48 c1 ee 03                   shrq    $0x3, %rsi
// 28: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2b: 48 8b 07                      movq    (%rdi), %rax
// 2e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000030:  R_X86_64_64  _JIT_TARGET
// 38: 89 c9                         movl    %ecx, %ecx
// 3a: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 3e: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 44: 59                            popq    %rcx
// 45: c3                            retq
// 46: ff 00                         incl    (%rax)
// 48: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004a:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 52: ff d0                         callq   *%rax
// 54: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_SLOT_code_body[85] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x00, 0x48, 0x85, 0xc0, 0x75, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_SLOT_code_holes[4] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x4a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_SLOT_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_SLOT_data_holes[1];

// _PUSH_NULLplus_LOAD_ATTR_WITH_HINT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_ATTR_WITH_HINT.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 04 25 e8 ff ff ff       movq    -0x18, %rax
// 10: 48 8b 50 20                   movq    0x20(%rax), %rdx
// 14: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000016:  R_X86_64_64  _JIT_OPERAND
// 1e: 0f b7 c8                      movzwl  %ax, %ecx
// 21: 48 8b 07                      movq    (%rdi), %rax
// 24: 48 39 4a 18                   cmpq    %rcx, 0x18(%rdx)
// 28: 0f 86 97 00 00 00             jbe     0xc5 <_JIT_ENTRY+0xc5>
// 2e: 4c 8b 40 20                   movq    0x20(%rax), %r8
// 32: 49 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %r9
// 0000000000000034:  R_X86_64_64  _JIT_OPARG
// 3c: 41 81 e1 fe ff 00 00          andl    $0xfffe, %r9d           # imm = 0xFFFE
// 43: 0f b6 4a 09                   movzbl  0x9(%rdx), %ecx
// 47: 41 ba 01 00 00 00             movl    $0x1, %r10d
// 4d: 49 d3 e2                      shlq    %cl, %r10
// 50: 4f 8b 44 88 18                movq    0x18(%r8,%r9,4), %r8
// 55: 80 7a 0a 00                   cmpb    $0x0, 0xa(%rdx)
// 59: 4a 8d 4c 12 20                leaq    0x20(%rdx,%r10), %rcx
// 5e: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000060:  R_X86_64_64  _JIT_OPERAND
// 68: 0f b7 d2                      movzwl  %dx, %edx
// 6b: 74 2c                         je      0x99 <_JIT_ENTRY+0x99>
// 6d: 48 c1 e2 04                   shlq    $0x4, %rdx
// 71: 4c 39 04 11                   cmpq    %r8, (%rcx,%rdx)
// 75: 75 4e                         jne     0xc5 <_JIT_ENTRY+0xc5>
// 77: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000079:  R_X86_64_64  _JIT_OPERAND
// 81: 0f b7 d2                      movzwl  %dx, %edx
// 84: 48 c1 e2 04                   shlq    $0x4, %rdx
// 88: 48 01 d1                      addq    %rdx, %rcx
// 8b: 48 83 c1 08                   addq    $0x8, %rcx
// 8f: 48 8b 09                      movq    (%rcx), %rcx
// 92: 48 85 c9                      testq   %rcx, %rcx
// 95: 74 2e                         je      0xc5 <_JIT_ENTRY+0xc5>
// 97: eb 52                         jmp     0xeb <_JIT_ENTRY+0xeb>
// 99: 48 8d 14 52                   leaq    (%rdx,%rdx,2), %rdx
// 9d: 4c 39 44 d1 08                cmpq    %r8, 0x8(%rcx,%rdx,8)
// a2: 75 21                         jne     0xc5 <_JIT_ENTRY+0xc5>
// a4: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 00000000000000a6:  R_X86_64_64  _JIT_OPERAND
// ae: 0f b7 d2                      movzwl  %dx, %edx
// b1: 48 8d 14 52                   leaq    (%rdx,%rdx,2), %rdx
// b5: 48 8d 0c d1                   leaq    (%rcx,%rdx,8), %rcx
// b9: 48 83 c1 10                   addq    $0x10, %rcx
// bd: 48 8b 09                      movq    (%rcx), %rcx
// c0: 48 85 c9                      testq   %rcx, %rcx
// c3: 75 26                         jne     0xeb <_JIT_ENTRY+0xeb>
// c5: 48 29 fe                      subq    %rdi, %rsi
// c8: 48 83 c6 c0                   addq    $-0x40, %rsi
// cc: 48 c1 ee 03                   shrq    $0x3, %rsi
// d0: 89 77 40                      movl    %esi, 0x40(%rdi)
// d3: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000d5:  R_X86_64_64  _JIT_TARGET
// dd: 89 c9                         movl    %ecx, %ecx
// df: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// e3: 48 05 c8 00 00 00             addq    $0xc8, %rax
// e9: 59                            popq    %rcx
// ea: c3                            retq
// eb: ff 01                         incl    (%rcx)
// ed: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ef:  R_X86_64_64  _Py_INCREF_IncRefTotal
// f7: ff d0                         callq   *%rax
// f9: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_WITH_HINT_code_body[250] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x48, 0x8b, 0x50, 0x20, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x48, 0x8b, 0x07, 0x48, 0x39, 0x4a, 0x18, 0x0f, 0x86, 0x97, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x40, 0x20, 0x49, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x81, 0xe1, 0xfe, 0xff, 0x00, 0x00, 0x0f, 0xb6, 0x4a, 0x09, 0x41, 0xba, 0x01, 0x00, 0x00, 0x00, 0x49, 0xd3, 0xe2, 0x4f, 0x8b, 0x44, 0x88, 0x18, 0x80, 0x7a, 0x0a, 0x00, 0x4a, 0x8d, 0x4c, 0x12, 0x20, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd2, 0x74, 0x2c, 0x48, 0xc1, 0xe2, 0x04, 0x4c, 0x39, 0x04, 0x11, 0x75, 0x4e, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd2, 0x48, 0xc1, 0xe2, 0x04, 0x48, 0x01, 0xd1, 0x48, 0x83, 0xc1, 0x08, 0x48, 0x8b, 0x09, 0x48, 0x85, 0xc9, 0x74, 0x2e, 0xeb, 0x52, 0x48, 0x8d, 0x14, 0x52, 0x4c, 0x39, 0x44, 0xd1, 0x08, 0x75, 0x21, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd2, 0x48, 0x8d, 0x14, 0x52, 0x48, 0x8d, 0x0c, 0xd1, 0x48, 0x83, 0xc1, 0x10, 0x48, 0x8b, 0x09, 0x48, 0x85, 0xc9, 0x75, 0x26, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x59, 0xc3, 0xff, 0x01, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_ATTR_WITH_HINT_code_holes[8] = {
    {0x16, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x34, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x79, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0xa6, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0xd5, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0xef, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_ATTR_WITH_HINT_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_ATTR_WITH_HINT_data_holes[1];

// _PUSH_NULLplus_LOAD_BUILD_CLASS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_BUILD_CLASS.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 48 83 ec 10                   subq    $0x10, %rsp
// 9: 49 89 d7                      movq    %rdx, %r15
// c: 48 89 f3                      movq    %rsi, %rbx
// f: 49 89 fe                      movq    %rdi, %r14
// 12: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 19: 48 8b 7f 20                   movq    0x20(%rdi), %rdi
// 1d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001f:  R_X86_64_64  PyMapping_GetOptionalItem
// 27: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 0000000000000029:  R_X86_64_64  _PyRuntime
// 31: 48 81 c6 40 a9 00 00          addq    $0xa940, %rsi           # imm = 0xA940
// 38: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 3d: ff d0                         callq   *%rax
// 3f: 85 c0                         testl   %eax, %eax
// 41: 78 56                         js      0x99 <_JIT_ENTRY+0x99>
// 43: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 48: 48 85 c0                      testq   %rax, %rax
// 4b: 74 26                         je      0x73 <_JIT_ENTRY+0x73>
// 4d: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 51: 48 83 c3 10                   addq    $0x10, %rbx
// 55: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000057:  R_X86_64_64  _JIT_CONTINUE
// 5f: 4c 89 f7                      movq    %r14, %rdi
// 62: 48 89 de                      movq    %rbx, %rsi
// 65: 4c 89 fa                      movq    %r15, %rdx
// 68: 48 83 c4 10                   addq    $0x10, %rsp
// 6c: 5b                            popq    %rbx
// 6d: 41 5e                         popq    %r14
// 6f: 41 5f                         popq    %r15
// 71: ff e0                         jmpq    *%rax
// 73: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000075:  R_X86_64_64  PyExc_NameError
// 7d: 48 8b 30                      movq    (%rax), %rsi
// 80: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000082:  R_X86_64_64  .rodata.str1.1
// 8a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000008c:  R_X86_64_64  _PyErr_SetString
// 94: 4c 89 ff                      movq    %r15, %rdi
// 97: ff d0                         callq   *%rax
// 99: 48 83 c3 08                   addq    $0x8, %rbx
// 9d: 4c 29 f3                      subq    %r14, %rbx
// a0: 48 83 c3 b8                   addq    $-0x48, %rbx
// a4: 48 c1 eb 03                   shrq    $0x3, %rbx
// a8: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// ac: 31 c0                         xorl    %eax, %eax
// ae: 48 83 c4 10                   addq    $0x10, %rsp
// b2: 5b                            popq    %rbx
// b3: 41 5e                         popq    %r14
// b5: 41 5f                         popq    %r15
// b7: c3                            retq
// b8: 
static const unsigned char _PUSH_NULLplus_LOAD_BUILD_CLASS_code_body[185] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x48, 0x83, 0xec, 0x10, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7f, 0x20, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x81, 0xc6, 0x40, 0xa9, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0x56, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x74, 0x26, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_BUILD_CLASS_code_holes[7] = {
    {0x1f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x29, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyRuntime, 0x0},
    {0x57, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x75, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x82, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x8c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetString, 0x0},
};
// 0: '__build_class__ not found\x00'
// 1a: 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_BUILD_CLASS_data_body[33] = {0x5f, 0x5f, 0x62, 0x75, 0x69, 0x6c, 0x64, 0x5f, 0x63, 0x6c, 0x61, 0x73, 0x73, 0x5f, 0x5f, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_BUILD_CLASS_data_holes[1];

// _PUSH_NULLplus_LOAD_CONST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_CONST.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 8b 07                      movq    (%rdi), %rax
// 1b: 48 8b 40 18                   movq    0x18(%rax), %rax
// 1f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000021:  R_X86_64_64  _JIT_OPARG
// 29: 0f b7 c9                      movzwl  %cx, %ecx
// 2c: 4c 8b 64 c8 18                movq    0x18(%rax,%rcx,8), %r12
// 31: 41 8b 04 24                   movl    (%r12), %eax
// 35: ff c0                         incl    %eax
// 37: 74 10                         je      0x49 <_JIT_ENTRY+0x49>
// 39: 41 89 04 24                   movl    %eax, (%r12)
// 3d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003f:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 47: ff d0                         callq   *%rax
// 49: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 4d: 49 83 c6 10                   addq    $0x10, %r14
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _JIT_CONTINUE
// 5b: 4c 89 ff                      movq    %r15, %rdi
// 5e: 4c 89 f6                      movq    %r14, %rsi
// 61: 48 89 da                      movq    %rbx, %rdx
// 64: 48 83 c4 08                   addq    $0x8, %rsp
// 68: 5b                            popq    %rbx
// 69: 41 5c                         popq    %r12
// 6b: 41 5e                         popq    %r14
// 6d: 41 5f                         popq    %r15
// 6f: ff e0                         jmpq    *%rax
// 71: 
static const unsigned char _PUSH_NULLplus_LOAD_CONST_code_body[114] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x18, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4c, 0x8b, 0x64, 0xc8, 0x18, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_CONST_code_holes[4] = {
    {0x21, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_CONST_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_CONST_data_holes[1];

// _PUSH_NULLplus_LOAD_DEREF
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_DEREF.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 48 8b 44 c7 48                movq    0x48(%rdi,%rax,8), %rax
// 2a: 4c 8b 60 10                   movq    0x10(%rax), %r12
// 2e: 4d 85 e4                      testq   %r12, %r12
// 31: 74 40                         je      0x73 <_JIT_ENTRY+0x73>
// 33: 41 8b 04 24                   movl    (%r12), %eax
// 37: ff c0                         incl    %eax
// 39: 74 10                         je      0x4b <_JIT_ENTRY+0x4b>
// 3b: 41 89 04 24                   movl    %eax, (%r12)
// 3f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000041:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 49: ff d0                         callq   *%rax
// 4b: 4c 89 63 08                   movq    %r12, 0x8(%rbx)
// 4f: 48 83 c3 10                   addq    $0x10, %rbx
// 53: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000055:  R_X86_64_64  _JIT_CONTINUE
// 5d: 4c 89 f7                      movq    %r14, %rdi
// 60: 48 89 de                      movq    %rbx, %rsi
// 63: 4c 89 fa                      movq    %r15, %rdx
// 66: 48 83 c4 08                   addq    $0x8, %rsp
// 6a: 5b                            popq    %rbx
// 6b: 41 5c                         popq    %r12
// 6d: 41 5e                         popq    %r14
// 6f: 41 5f                         popq    %r15
// 71: ff e0                         jmpq    *%rax
// 73: 48 83 c3 08                   addq    $0x8, %rbx
// 77: 49 8b 36                      movq    (%r14), %rsi
// 7a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007c:  R_X86_64_64  _JIT_OPARG
// 84: 0f b7 d0                      movzwl  %ax, %edx
// 87: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000089:  R_X86_64_64  _PyEval_FormatExcUnbound
// 91: 4c 89 ff                      movq    %r15, %rdi
// 94: ff d0                         callq   *%rax
// 96: 4c 29 f3                      subq    %r14, %rbx
// 99: 48 83 c3 b8                   addq    $-0x48, %rbx
// 9d: 48 c1 eb 03                   shrq    $0x3, %rbx
// a1: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// a5: 31 c0                         xorl    %eax, %eax
// a7: 48 83 c4 08                   addq    $0x8, %rsp
// ab: 5b                            popq    %rbx
// ac: 41 5c                         popq    %r12
// ae: 41 5e                         popq    %r14
// b0: 41 5f                         popq    %r15
// b2: c3                            retq
// b3: 
static const unsigned char _PUSH_NULLplus_LOAD_DEREF_code_body[180] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x44, 0xc7, 0x48, 0x4c, 0x8b, 0x60, 0x10, 0x4d, 0x85, 0xe4, 0x74, 0x40, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4c, 0x89, 0x63, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x49, 0x8b, 0x36, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_DEREF_code_holes[6] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x55, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x7c, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcUnbound, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_DEREF_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_DEREF_data_holes[1];

// _PUSH_NULLplus_LOAD_FAST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_FAST.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 4c 8b 64 c7 48                movq    0x48(%rdi,%rax,8), %r12
// 2a: 41 8b 04 24                   movl    (%r12), %eax
// 2e: ff c0                         incl    %eax
// 30: 74 10                         je      0x42 <_JIT_ENTRY+0x42>
// 32: 41 89 04 24                   movl    %eax, (%r12)
// 36: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000038:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 40: ff d0                         callq   *%rax
// 42: 4d 89 66 08                   movq    %r12, 0x8(%r14)
// 46: 49 83 c6 10                   addq    $0x10, %r14
// 4a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004c:  R_X86_64_64  _JIT_CONTINUE
// 54: 4c 89 ff                      movq    %r15, %rdi
// 57: 4c 89 f6                      movq    %r14, %rsi
// 5a: 48 89 da                      movq    %rbx, %rdx
// 5d: 48 83 c4 08                   addq    $0x8, %rsp
// 61: 5b                            popq    %rbx
// 62: 41 5c                         popq    %r12
// 64: 41 5e                         popq    %r14
// 66: 41 5f                         popq    %r15
// 68: ff e0                         jmpq    *%rax
// 6a: 
static const unsigned char _PUSH_NULLplus_LOAD_FAST_code_body[107] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x4c, 0x8b, 0x64, 0xc7, 0x48, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x66, 0x08, 0x49, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_FAST_code_holes[4] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x4c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_FAST_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_FAST_data_holes[1];

// _PUSH_NULLplus_LOAD_FAST_AND_CLEAR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_FAST_AND_CLEAR.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  _JIT_OPARG
// 11: 0f b7 c0                      movzwl  %ax, %eax
// 14: 48 8b 4c c7 48                movq    0x48(%rdi,%rax,8), %rcx
// 19: 48 c7 44 c7 48 00 00 00 00    movq    $0x0, 0x48(%rdi,%rax,8)
// 22: 48 89 4e 08                   movq    %rcx, 0x8(%rsi)
// 26: 48 83 c6 10                   addq    $0x10, %rsi
// 2a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002c:  R_X86_64_64  _JIT_CONTINUE
// 34: ff e0                         jmpq    *%rax
// 36: 
static const unsigned char _PUSH_NULLplus_LOAD_FAST_AND_CLEAR_code_body[55] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x4c, 0xc7, 0x48, 0x48, 0xc7, 0x44, 0xc7, 0x48, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x4e, 0x08, 0x48, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_FAST_AND_CLEAR_code_holes[3] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_FAST_AND_CLEAR_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_FAST_AND_CLEAR_data_holes[1];

// _PUSH_NULLplus_LOAD_FAST_CHECK
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_FAST_CHECK.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 4c 8b 64 c7 48                movq    0x48(%rdi,%rax,8), %r12
// 2a: 4d 85 e4                      testq   %r12, %r12
// 2d: 74 40                         je      0x6f <_JIT_ENTRY+0x6f>
// 2f: 41 8b 04 24                   movl    (%r12), %eax
// 33: ff c0                         incl    %eax
// 35: 74 10                         je      0x47 <_JIT_ENTRY+0x47>
// 37: 41 89 04 24                   movl    %eax, (%r12)
// 3b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 45: ff d0                         callq   *%rax
// 47: 4c 89 63 08                   movq    %r12, 0x8(%rbx)
// 4b: 48 83 c3 10                   addq    $0x10, %rbx
// 4f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000051:  R_X86_64_64  _JIT_CONTINUE
// 59: 4c 89 f7                      movq    %r14, %rdi
// 5c: 48 89 de                      movq    %rbx, %rsi
// 5f: 4c 89 fa                      movq    %r15, %rdx
// 62: 48 83 c4 08                   addq    $0x8, %rsp
// 66: 5b                            popq    %rbx
// 67: 41 5c                         popq    %r12
// 69: 41 5e                         popq    %r14
// 6b: 41 5f                         popq    %r15
// 6d: ff e0                         jmpq    *%rax
// 6f: 48 83 c3 08                   addq    $0x8, %rbx
// 73: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000075:  R_X86_64_64  PyExc_UnboundLocalError
// 7d: 4c 8b 20                      movq    (%rax), %r12
// 80: 49 8b 06                      movq    (%r14), %rax
// 83: 48 8b 78 60                   movq    0x60(%rax), %rdi
// 87: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000089:  R_X86_64_64  _JIT_OPARG
// 91: 0f b7 f0                      movzwl  %ax, %esi
// 94: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000096:  R_X86_64_64  PyTuple_GetItem
// 9e: ff d0                         callq   *%rax
// a0: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 00000000000000a2:  R_X86_64_64  .rodata.str1.1
// aa: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 00000000000000ac:  R_X86_64_64  _PyEval_FormatExcCheckArg
// b4: 4c 89 ff                      movq    %r15, %rdi
// b7: 4c 89 e6                      movq    %r12, %rsi
// ba: 48 89 c1                      movq    %rax, %rcx
// bd: 41 ff d0                      callq   *%r8
// c0: 4c 29 f3                      subq    %r14, %rbx
// c3: 48 83 c3 b8                   addq    $-0x48, %rbx
// c7: 48 c1 eb 03                   shrq    $0x3, %rbx
// cb: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// cf: 31 c0                         xorl    %eax, %eax
// d1: 48 83 c4 08                   addq    $0x8, %rsp
// d5: 5b                            popq    %rbx
// d6: 41 5c                         popq    %r12
// d8: 41 5e                         popq    %r14
// da: 41 5f                         popq    %r15
// dc: c3                            retq
// dd: 
static const unsigned char _PUSH_NULLplus_LOAD_FAST_CHECK_code_body[222] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x4c, 0x8b, 0x64, 0xc7, 0x48, 0x4d, 0x85, 0xe4, 0x74, 0x40, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4c, 0x89, 0x63, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x20, 0x49, 0x8b, 0x06, 0x48, 0x8b, 0x78, 0x60, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xf0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe6, 0x48, 0x89, 0xc1, 0x41, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_FAST_CHECK_code_holes[9] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x75, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_UnboundLocalError, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_GetItem, 0x0},
    {0xa2, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xac, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
};
// 0: "cannot access local variable '%s' where it is not associated with a value\x00"
// 4a: 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_FAST_CHECK_data_body[81] = {0x63, 0x61, 0x6e, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x20, 0x76, 0x61, 0x72, 0x69, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x27, 0x25, 0x73, 0x27, 0x20, 0x77, 0x68, 0x65, 0x72, 0x65, 0x20, 0x69, 0x74, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x73, 0x73, 0x6f, 0x63, 0x69, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_FAST_CHECK_data_holes[1];

// _PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 48 83 ec 10                   subq    $0x10, %rsp
// 9: 49 89 d7                      movq    %rdx, %r15
// c: 48 89 f3                      movq    %rsi, %rbx
// f: 49 89 fe                      movq    %rdi, %r14
// 12: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 19: 48 8b 07                      movq    (%rdi), %rax
// 1c: 48 8b 40 60                   movq    0x60(%rax), %rax
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  _JIT_OPARG
// 2a: 0f b7 c9                      movzwl  %cx, %ecx
// 2d: 48 8b 74 c8 18                movq    0x18(%rax,%rcx,8), %rsi
// 32: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000034:  R_X86_64_64  PyMapping_GetOptionalItem
// 3c: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 41: 31 ff                         xorl    %edi, %edi
// 43: ff d0                         callq   *%rax
// 45: 85 c0                         testl   %eax, %eax
// 47: 78 3f                         js      0x88 <_JIT_ENTRY+0x88>
// 49: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004b:  R_X86_64_64  _JIT_OPARG
// 53: 0f b7 c0                      movzwl  %ax, %eax
// 56: 49 8b 44 c6 48                movq    0x48(%r14,%rax,8), %rax
// 5b: 48 8b 40 10                   movq    0x10(%rax), %rax
// 5f: 48 89 44 24 08                movq    %rax, 0x8(%rsp)
// 64: 48 85 c0                      testq   %rax, %rax
// 67: 75 3a                         jne     0xa3 <_JIT_ENTRY+0xa3>
// 69: 49 8b 36                      movq    (%r14), %rsi
// 6c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006e:  R_X86_64_64  _JIT_OPARG
// 76: 0f b7 d0                      movzwl  %ax, %edx
// 79: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007b:  R_X86_64_64  _PyEval_FormatExcUnbound
// 83: 4c 89 ff                      movq    %r15, %rdi
// 86: ff d0                         callq   *%rax
// 88: 4c 29 f3                      subq    %r14, %rbx
// 8b: 48 83 c3 c0                   addq    $-0x40, %rbx
// 8f: 48 c1 eb 03                   shrq    $0x3, %rbx
// 93: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 97: 31 c0                         xorl    %eax, %eax
// 99: 48 83 c4 10                   addq    $0x10, %rsp
// 9d: 5b                            popq    %rbx
// 9e: 41 5e                         popq    %r14
// a0: 41 5f                         popq    %r15
// a2: c3                            retq
// a3: ff 00                         incl    (%rax)
// a5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a7:  R_X86_64_64  _Py_INCREF_IncRefTotal
// af: ff d0                         callq   *%rax
// b1: 
static const unsigned char _PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF_code_body[178] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x48, 0x83, 0xec, 0x10, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x60, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x74, 0xc8, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x31, 0xff, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0x3f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x49, 0x8b, 0x44, 0xc6, 0x48, 0x48, 0x8b, 0x40, 0x10, 0x48, 0x89, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x75, 0x3a, 0x49, 0x8b, 0x36, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0xff, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF_code_holes[7] = {
    {0x22, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x34, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x4b, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x6e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x7b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcUnbound, 0x0},
    {0xa7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF_data_holes[1];

// _PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 48 83 ec 10                   subq    $0x10, %rsp
// d: 49 89 d7                      movq    %rdx, %r15
// 10: 48 89 f3                      movq    %rsi, %rbx
// 13: 49 89 fe                      movq    %rdi, %r14
// 16: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1d: 48 8b 07                      movq    (%rdi), %rax
// 20: 48 8b 40 20                   movq    0x20(%rax), %rax
// 24: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000026:  R_X86_64_64  _JIT_OPARG
// 2e: 0f b7 c9                      movzwl  %cx, %ecx
// 31: 4c 8b 64 c8 18                movq    0x18(%rax,%rcx,8), %r12
// 36: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000038:  R_X86_64_64  PyMapping_GetOptionalItem
// 40: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 45: 31 ff                         xorl    %edi, %edi
// 47: 4c 89 e6                      movq    %r12, %rsi
// 4a: 41 ff d5                      callq   *%r13
// 4d: 85 c0                         testl   %eax, %eax
// 4f: 78 58                         js      0xa9 <_JIT_ENTRY+0xa9>
// 51: 49 8b 7e 18                   movq    0x18(%r14), %rdi
// 55: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000057:  R_X86_64_64  PyDict_GetItemRef
// 5f: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 64: 4c 89 e6                      movq    %r12, %rsi
// 67: ff d0                         callq   *%rax
// 69: 85 c0                         testl   %eax, %eax
// 6b: 78 3c                         js      0xa9 <_JIT_ENTRY+0xa9>
// 6d: 49 8b 7e 20                   movq    0x20(%r14), %rdi
// 71: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 76: 4c 89 e6                      movq    %r12, %rsi
// 79: 41 ff d5                      callq   *%r13
// 7c: 85 c0                         testl   %eax, %eax
// 7e: 78 29                         js      0xa9 <_JIT_ENTRY+0xa9>
// 80: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000082:  R_X86_64_64  PyExc_NameError
// 8a: 48 8b 30                      movq    (%rax), %rsi
// 8d: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000008f:  R_X86_64_64  .rodata.str1.1
// 97: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000099:  R_X86_64_64  _PyEval_FormatExcCheckArg
// a1: 4c 89 ff                      movq    %r15, %rdi
// a4: 4c 89 e1                      movq    %r12, %rcx
// a7: ff d0                         callq   *%rax
// a9: 4c 29 f3                      subq    %r14, %rbx
// ac: 48 83 c3 c0                   addq    $-0x40, %rbx
// b0: 48 c1 eb 03                   shrq    $0x3, %rbx
// b4: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// b8: 31 c0                         xorl    %eax, %eax
// ba: 48 83 c4 10                   addq    $0x10, %rsp
// be: 5b                            popq    %rbx
// bf: 41 5c                         popq    %r12
// c1: 41 5d                         popq    %r13
// c3: 41 5e                         popq    %r14
// c5: 41 5f                         popq    %r15
// c7: c3                            retq
// c8: 
static const unsigned char _PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS_code_body[201] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x10, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4c, 0x8b, 0x64, 0xc8, 0x18, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x31, 0xff, 0x4c, 0x89, 0xe6, 0x41, 0xff, 0xd5, 0x85, 0xc0, 0x78, 0x58, 0x49, 0x8b, 0x7e, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x4c, 0x89, 0xe6, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0x3c, 0x49, 0x8b, 0x7e, 0x20, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x4c, 0x89, 0xe6, 0x41, 0xff, 0xd5, 0x85, 0xc0, 0x78, 0x29, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe1, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS_code_holes[7] = {
    {0x26, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x57, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_GetItemRef, 0x0},
    {0x82, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x8f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x99, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
};
// 0: "name '%.200s' is not defined\x00"
// 1d: 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS_data_body[33] = {0x6e, 0x61, 0x6d, 0x65, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS_data_holes[1];

// _PUSH_NULLplus_LOAD_GLOBAL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_GLOBAL.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 d6                      movq    %rdx, %r14
// e: 49 89 f7                      movq    %rsi, %r15
// 11: 48 89 fb                      movq    %rdi, %rbx
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 4c 8d 6e 08                   leaq    0x8(%rsi), %r13
// 1f: 48 8b 07                      movq    (%rdi), %rax
// 22: 48 8b 7f 18                   movq    0x18(%rdi), %rdi
// 26: 48 8b 40 20                   movq    0x20(%rax), %rax
// 2a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002c:  R_X86_64_64  _JIT_OPARG
// 34: 81 e1 fe ff 00 00             andl    $0xfffe, %ecx           # imm = 0xFFFE
// 3a: 4c 8b 64 88 18                movq    0x18(%rax,%rcx,4), %r12
// 3f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000041:  R_X86_64_64  PyDict_Type
// 49: 48 39 47 08                   cmpq    %rax, 0x8(%rdi)
// 4d: 75 0e                         jne     0x5d <_JIT_ENTRY+0x5d>
// 4f: 48 8b 73 20                   movq    0x20(%rbx), %rsi
// 53: 48 39 46 08                   cmpq    %rax, 0x8(%rsi)
// 57: 0f 84 85 00 00 00             je      0xe2 <_JIT_ENTRY+0xe2>
// 5d: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 000000000000005f:  R_X86_64_64  PyMapping_GetOptionalItem
// 67: 48 89 e2                      movq    %rsp, %rdx
// 6a: 4c 89 e6                      movq    %r12, %rsi
// 6d: ff d5                         callq   *%rbp
// 6f: 85 c0                         testl   %eax, %eax
// 71: 0f 88 d9 00 00 00             js      0x150 <_JIT_ENTRY+0x150>
// 77: 48 8b 04 24                   movq    (%rsp), %rax
// 7b: 48 85 c0                      testq   %rax, %rax
// 7e: 74 47                         je      0xc7 <_JIT_ENTRY+0xc7>
// 80: 49 89 45 00                   movq    %rax, (%r13)
// 84: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000086:  R_X86_64_64  _JIT_OPARG
// 8e: a8 01                         testb   $0x1, %al
// 90: 74 08                         je      0x9a <_JIT_ENTRY+0x9a>
// 92: 49 c7 47 10 00 00 00 00       movq    $0x0, 0x10(%r15)
// 9a: 83 e0 01                      andl    $0x1, %eax
// 9d: ff c0                         incl    %eax
// 9f: 49 8d 34 c7                   leaq    (%r15,%rax,8), %rsi
// a3: 48 83 c6 08                   addq    $0x8, %rsi
// a7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a9:  R_X86_64_64  _JIT_CONTINUE
// b1: 48 89 df                      movq    %rbx, %rdi
// b4: 4c 89 f2                      movq    %r14, %rdx
// b7: 48 83 c4 08                   addq    $0x8, %rsp
// bb: 5b                            popq    %rbx
// bc: 41 5c                         popq    %r12
// be: 41 5d                         popq    %r13
// c0: 41 5e                         popq    %r14
// c2: 41 5f                         popq    %r15
// c4: 5d                            popq    %rbp
// c5: ff e0                         jmpq    *%rax
// c7: 48 8b 7b 20                   movq    0x20(%rbx), %rdi
// cb: 48 89 e2                      movq    %rsp, %rdx
// ce: 4c 89 e6                      movq    %r12, %rsi
// d1: ff d5                         callq   *%rbp
// d3: 85 c0                         testl   %eax, %eax
// d5: 78 79                         js      0x150 <_JIT_ENTRY+0x150>
// d7: 48 8b 04 24                   movq    (%rsp), %rax
// db: 48 85 c0                      testq   %rax, %rax
// de: 75 a0                         jne     0x80 <_JIT_ENTRY+0x80>
// e0: eb 45                         jmp     0x127 <_JIT_ENTRY+0x127>
// e2: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e4:  R_X86_64_64  _PyDict_LoadGlobal
// ec: 4c 89 e2                      movq    %r12, %rdx
// ef: ff d0                         callq   *%rax
// f1: 48 89 04 24                   movq    %rax, (%rsp)
// f5: 48 85 c0                      testq   %rax, %rax
// f8: 74 1d                         je      0x117 <_JIT_ENTRY+0x117>
// fa: 8b 08                         movl    (%rax), %ecx
// fc: ff c1                         incl    %ecx
// fe: 74 80                         je      0x80 <_JIT_ENTRY+0x80>
// 100: 89 08                         movl    %ecx, (%rax)
// 102: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000104:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 10c: ff d0                         callq   *%rax
// 10e: 48 8b 04 24                   movq    (%rsp), %rax
// 112: e9 69 ff ff ff                jmp     0x80 <_JIT_ENTRY+0x80>
// 117: 49 8b 46 68                   movq    0x68(%r14), %rax
// 11b: 48 85 c0                      testq   %rax, %rax
// 11e: 74 07                         je      0x127 <_JIT_ENTRY+0x127>
// 120: 48 83 78 08 00                cmpq    $0x0, 0x8(%rax)
// 125: 75 29                         jne     0x150 <_JIT_ENTRY+0x150>
// 127: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000129:  R_X86_64_64  PyExc_NameError
// 131: 48 8b 30                      movq    (%rax), %rsi
// 134: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000136:  R_X86_64_64  .rodata.str1.1
// 13e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000140:  R_X86_64_64  _PyEval_FormatExcCheckArg
// 148: 4c 89 f7                      movq    %r14, %rdi
// 14b: 4c 89 e1                      movq    %r12, %rcx
// 14e: ff d0                         callq   *%rax
// 150: 49 29 dd                      subq    %rbx, %r13
// 153: 49 83 c5 b8                   addq    $-0x48, %r13
// 157: 49 c1 ed 03                   shrq    $0x3, %r13
// 15b: 44 89 6b 40                   movl    %r13d, 0x40(%rbx)
// 15f: 31 c0                         xorl    %eax, %eax
// 161: 48 83 c4 08                   addq    $0x8, %rsp
// 165: 5b                            popq    %rbx
// 166: 41 5c                         popq    %r12
// 168: 41 5d                         popq    %r13
// 16a: 41 5e                         popq    %r14
// 16c: 41 5f                         popq    %r15
// 16e: 5d                            popq    %rbp
// 16f: c3                            retq
// 170: 
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_code_body[369] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd6, 0x49, 0x89, 0xf7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x6e, 0x08, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x7f, 0x18, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xe1, 0xfe, 0xff, 0x00, 0x00, 0x4c, 0x8b, 0x64, 0x88, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x47, 0x08, 0x75, 0x0e, 0x48, 0x8b, 0x73, 0x20, 0x48, 0x39, 0x46, 0x08, 0x0f, 0x84, 0x85, 0x00, 0x00, 0x00, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe2, 0x4c, 0x89, 0xe6, 0xff, 0xd5, 0x85, 0xc0, 0x0f, 0x88, 0xd9, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x47, 0x49, 0x89, 0x45, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x01, 0x74, 0x08, 0x49, 0xc7, 0x47, 0x10, 0x00, 0x00, 0x00, 0x00, 0x83, 0xe0, 0x01, 0xff, 0xc0, 0x49, 0x8d, 0x34, 0xc7, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf2, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0x8b, 0x7b, 0x20, 0x48, 0x89, 0xe2, 0x4c, 0x89, 0xe6, 0xff, 0xd5, 0x85, 0xc0, 0x78, 0x79, 0x48, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x75, 0xa0, 0xeb, 0x45, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x48, 0x89, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0x1d, 0x8b, 0x08, 0xff, 0xc1, 0x74, 0x80, 0x89, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x8b, 0x04, 0x24, 0xe9, 0x69, 0xff, 0xff, 0xff, 0x49, 0x8b, 0x46, 0x68, 0x48, 0x85, 0xc0, 0x74, 0x07, 0x48, 0x83, 0x78, 0x08, 0x00, 0x75, 0x29, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x4c, 0x89, 0xe1, 0xff, 0xd0, 0x49, 0x29, 0xdd, 0x49, 0x83, 0xc5, 0xb8, 0x49, 0xc1, 0xed, 0x03, 0x44, 0x89, 0x6b, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_code_holes[11] = {
    {0x2c, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x5f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x86, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xa9, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0xe4, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_LoadGlobal, 0x0},
    {0x104, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x129, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x136, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x140, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
};
// 0: "name '%.200s' is not defined\x00"
// 1d: 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_data_body[33] = {0x6e, 0x61, 0x6d, 0x65, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_data_holes[1];

// _PUSH_NULLplus_LOAD_GLOBAL_BUILTINS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_GLOBAL_BUILTINS.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 49 89 f6                      movq    %rsi, %r14
// c: 48 89 fb                      movq    %rdi, %rbx
// f: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 16: 48 8b 47 20                   movq    0x20(%rdi), %rax
// 1a: 48 8b 40 20                   movq    0x20(%rax), %rax
// 1e: 0f b6 48 09                   movzbl  0x9(%rax), %ecx
// 22: be 01 00 00 00                movl    $0x1, %esi
// 27: 48 d3 e6                      shlq    %cl, %rsi
// 2a: 4d 8d 66 08                   leaq    0x8(%r14), %r12
// 2e: 48 01 c6                      addq    %rax, %rsi
// 31: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000033:  R_X86_64_64  _JIT_OPERAND
// 3b: 0f b7 c0                      movzwl  %ax, %eax
// 3e: 48 c1 e0 04                   shlq    $0x4, %rax
// 42: 4c 8b 6c 30 28                movq    0x28(%rax,%rsi), %r13
// 47: 4d 85 ed                      testq   %r13, %r13
// 4a: 74 5d                         je      0xa9 <_JIT_ENTRY+0xa9>
// 4c: 49 89 d7                      movq    %rdx, %r15
// 4f: 41 8b 45 00                   movl    (%r13), %eax
// 53: ff c0                         incl    %eax
// 55: 74 10                         je      0x67 <_JIT_ENTRY+0x67>
// 57: 41 89 45 00                   movl    %eax, (%r13)
// 5b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 65: ff d0                         callq   *%rax
// 67: 4d 89 2c 24                   movq    %r13, (%r12)
// 6b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006d:  R_X86_64_64  _JIT_OPARG
// 75: a8 01                         testb   $0x1, %al
// 77: 74 08                         je      0x81 <_JIT_ENTRY+0x81>
// 79: 49 c7 46 10 00 00 00 00       movq    $0x0, 0x10(%r14)
// 81: 83 e0 01                      andl    $0x1, %eax
// 84: ff c0                         incl    %eax
// 86: 49 8d 34 c6                   leaq    (%r14,%rax,8), %rsi
// 8a: 48 83 c6 08                   addq    $0x8, %rsi
// 8e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000090:  R_X86_64_64  _JIT_CONTINUE
// 98: 48 89 df                      movq    %rbx, %rdi
// 9b: 4c 89 fa                      movq    %r15, %rdx
// 9e: 5b                            popq    %rbx
// 9f: 41 5c                         popq    %r12
// a1: 41 5d                         popq    %r13
// a3: 41 5e                         popq    %r14
// a5: 41 5f                         popq    %r15
// a7: ff e0                         jmpq    *%rax
// a9: 49 29 dc                      subq    %rbx, %r12
// ac: 49 83 c4 b8                   addq    $-0x48, %r12
// b0: 49 c1 ec 03                   shrq    $0x3, %r12
// b4: 44 89 63 40                   movl    %r12d, 0x40(%rbx)
// b8: 48 8b 03                      movq    (%rbx), %rax
// bb: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000bd:  R_X86_64_64  _JIT_TARGET
// c5: 89 c9                         movl    %ecx, %ecx
// c7: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// cf: 5b                            popq    %rbx
// d0: 41 5c                         popq    %r12
// d2: 41 5d                         popq    %r13
// d4: 41 5e                         popq    %r14
// d6: 41 5f                         popq    %r15
// d8: c3                            retq
// d9: 
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_BUILTINS_code_body[218] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x47, 0x20, 0x48, 0x8b, 0x40, 0x20, 0x0f, 0xb6, 0x48, 0x09, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0xd3, 0xe6, 0x4d, 0x8d, 0x66, 0x08, 0x48, 0x01, 0xc6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x04, 0x4c, 0x8b, 0x6c, 0x30, 0x28, 0x4d, 0x85, 0xed, 0x74, 0x5d, 0x49, 0x89, 0xd7, 0x41, 0x8b, 0x45, 0x00, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x45, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x2c, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x01, 0x74, 0x08, 0x49, 0xc7, 0x46, 0x10, 0x00, 0x00, 0x00, 0x00, 0x83, 0xe0, 0x01, 0xff, 0xc0, 0x49, 0x8d, 0x34, 0xc6, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x49, 0x29, 0xdc, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x63, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_BUILTINS_code_holes[6] = {
    {0x33, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x5d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x6d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x90, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0xbd, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_BUILTINS_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_BUILTINS_data_holes[1];

// _PUSH_NULLplus_LOAD_GLOBAL_MODULE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_GLOBAL_MODULE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 49 89 f6                      movq    %rsi, %r14
// c: 48 89 fb                      movq    %rdi, %rbx
// f: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 16: 48 8b 47 18                   movq    0x18(%rdi), %rax
// 1a: 48 8b 40 20                   movq    0x20(%rax), %rax
// 1e: 0f b6 48 09                   movzbl  0x9(%rax), %ecx
// 22: be 01 00 00 00                movl    $0x1, %esi
// 27: 48 d3 e6                      shlq    %cl, %rsi
// 2a: 4d 8d 66 08                   leaq    0x8(%r14), %r12
// 2e: 48 01 c6                      addq    %rax, %rsi
// 31: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000033:  R_X86_64_64  _JIT_OPERAND
// 3b: 0f b7 c0                      movzwl  %ax, %eax
// 3e: 48 c1 e0 04                   shlq    $0x4, %rax
// 42: 4c 8b 6c 30 28                movq    0x28(%rax,%rsi), %r13
// 47: 4d 85 ed                      testq   %r13, %r13
// 4a: 74 5d                         je      0xa9 <_JIT_ENTRY+0xa9>
// 4c: 49 89 d7                      movq    %rdx, %r15
// 4f: 41 8b 45 00                   movl    (%r13), %eax
// 53: ff c0                         incl    %eax
// 55: 74 10                         je      0x67 <_JIT_ENTRY+0x67>
// 57: 41 89 45 00                   movl    %eax, (%r13)
// 5b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 65: ff d0                         callq   *%rax
// 67: 4d 89 2c 24                   movq    %r13, (%r12)
// 6b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006d:  R_X86_64_64  _JIT_OPARG
// 75: a8 01                         testb   $0x1, %al
// 77: 74 08                         je      0x81 <_JIT_ENTRY+0x81>
// 79: 49 c7 46 10 00 00 00 00       movq    $0x0, 0x10(%r14)
// 81: 83 e0 01                      andl    $0x1, %eax
// 84: ff c0                         incl    %eax
// 86: 49 8d 34 c6                   leaq    (%r14,%rax,8), %rsi
// 8a: 48 83 c6 08                   addq    $0x8, %rsi
// 8e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000090:  R_X86_64_64  _JIT_CONTINUE
// 98: 48 89 df                      movq    %rbx, %rdi
// 9b: 4c 89 fa                      movq    %r15, %rdx
// 9e: 5b                            popq    %rbx
// 9f: 41 5c                         popq    %r12
// a1: 41 5d                         popq    %r13
// a3: 41 5e                         popq    %r14
// a5: 41 5f                         popq    %r15
// a7: ff e0                         jmpq    *%rax
// a9: 49 29 dc                      subq    %rbx, %r12
// ac: 49 83 c4 b8                   addq    $-0x48, %r12
// b0: 49 c1 ec 03                   shrq    $0x3, %r12
// b4: 44 89 63 40                   movl    %r12d, 0x40(%rbx)
// b8: 48 8b 03                      movq    (%rbx), %rax
// bb: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000bd:  R_X86_64_64  _JIT_TARGET
// c5: 89 c9                         movl    %ecx, %ecx
// c7: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// cf: 5b                            popq    %rbx
// d0: 41 5c                         popq    %r12
// d2: 41 5d                         popq    %r13
// d4: 41 5e                         popq    %r14
// d6: 41 5f                         popq    %r15
// d8: c3                            retq
// d9: 
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_MODULE_code_body[218] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x49, 0x89, 0xf6, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x47, 0x18, 0x48, 0x8b, 0x40, 0x20, 0x0f, 0xb6, 0x48, 0x09, 0xbe, 0x01, 0x00, 0x00, 0x00, 0x48, 0xd3, 0xe6, 0x4d, 0x8d, 0x66, 0x08, 0x48, 0x01, 0xc6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x04, 0x4c, 0x8b, 0x6c, 0x30, 0x28, 0x4d, 0x85, 0xed, 0x74, 0x5d, 0x49, 0x89, 0xd7, 0x41, 0x8b, 0x45, 0x00, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x45, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4d, 0x89, 0x2c, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x01, 0x74, 0x08, 0x49, 0xc7, 0x46, 0x10, 0x00, 0x00, 0x00, 0x00, 0x83, 0xe0, 0x01, 0xff, 0xc0, 0x49, 0x8d, 0x34, 0xc6, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x49, 0x29, 0xdc, 0x49, 0x83, 0xc4, 0xb8, 0x49, 0xc1, 0xec, 0x03, 0x44, 0x89, 0x63, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_MODULE_code_holes[6] = {
    {0x33, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x5d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x6d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x90, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0xbd, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_LOAD_GLOBAL_MODULE_data_body[1];
static const Hole _PUSH_NULLplus_LOAD_GLOBAL_MODULE_data_holes[1];

// _PUSH_NULLplus_LOAD_LOCALS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_LOCALS.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 4c 8b 67 28                   movq    0x28(%rdi), %r12
// 1c: 4d 85 e4                      testq   %r12, %r12
// 1f: 74 40                         je      0x61 <_JIT_ENTRY+0x61>
// 21: 41 8b 04 24                   movl    (%r12), %eax
// 25: ff c0                         incl    %eax
// 27: 74 10                         je      0x39 <_JIT_ENTRY+0x39>
// 29: 41 89 04 24                   movl    %eax, (%r12)
// 2d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002f:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 37: ff d0                         callq   *%rax
// 39: 4c 89 63 08                   movq    %r12, 0x8(%rbx)
// 3d: 48 83 c3 10                   addq    $0x10, %rbx
// 41: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000043:  R_X86_64_64  _JIT_CONTINUE
// 4b: 4c 89 f7                      movq    %r14, %rdi
// 4e: 48 89 de                      movq    %rbx, %rsi
// 51: 4c 89 fa                      movq    %r15, %rdx
// 54: 48 83 c4 08                   addq    $0x8, %rsp
// 58: 5b                            popq    %rbx
// 59: 41 5c                         popq    %r12
// 5b: 41 5e                         popq    %r14
// 5d: 41 5f                         popq    %r15
// 5f: ff e0                         jmpq    *%rax
// 61: 48 83 c3 08                   addq    $0x8, %rbx
// 65: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000067:  R_X86_64_64  PyExc_SystemError
// 6f: 48 8b 30                      movq    (%rax), %rsi
// 72: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000074:  R_X86_64_64  .rodata.str1.1
// 7c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007e:  R_X86_64_64  _PyErr_SetString
// 86: 4c 89 ff                      movq    %r15, %rdi
// 89: ff d0                         callq   *%rax
// 8b: 4c 29 f3                      subq    %r14, %rbx
// 8e: 48 83 c3 b8                   addq    $-0x48, %rbx
// 92: 48 c1 eb 03                   shrq    $0x3, %rbx
// 96: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 9a: 31 c0                         xorl    %eax, %eax
// 9c: 48 83 c4 08                   addq    $0x8, %rsp
// a0: 5b                            popq    %rbx
// a1: 41 5c                         popq    %r12
// a3: 41 5e                         popq    %r14
// a5: 41 5f                         popq    %r15
// a7: c3                            retq
// a8: 
static const unsigned char _PUSH_NULLplus_LOAD_LOCALS_code_body[169] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x67, 0x28, 0x4d, 0x85, 0xe4, 0x74, 0x40, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0x10, 0x41, 0x89, 0x04, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x4c, 0x89, 0x63, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_LOAD_LOCALS_code_holes[6] = {
    {0x2f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x67, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0x74, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x7e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetString, 0x0},
};
// 0: 'no locals found\x00'
// 10: 
static const unsigned char _PUSH_NULLplus_LOAD_LOCALS_data_body[17] = {0x6e, 0x6f, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x73, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0x00};
static const Hole _PUSH_NULLplus_LOAD_LOCALS_data_holes[1];

// _PUSH_NULLplus_LOAD_NAME
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_NAME.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 48 83 ec 10                   subq    $0x10, %rsp
// d: 49 89 d7                      movq    %rdx, %r15
// 10: 48 89 f3                      movq    %rsi, %rbx
// 13: 49 89 fe                      movq    %rdi, %r14
// 16: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1d: 48 8b 7f 28                   movq    0x28(%rdi), %rdi
// 21: 48 85 ff                      testq   %rdi, %rdi
// 24: 74 66                         je      0x8c <_JIT_ENTRY+0x8c>
// 26: 49 8b 06                      movq    (%r14), %rax
// 29: 48 8b 40 20                   movq    0x20(%rax), %rax
// 2d: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002f:  R_X86_64_64  _JIT_OPARG
// 37: 0f b7 c9                      movzwl  %cx, %ecx
// 3a: 4c 8b 64 c8 18                movq    0x18(%rax,%rcx,8), %r12
// 3f: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000041:  R_X86_64_64  PyMapping_GetOptionalItem
// 49: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 4e: 4c 89 e6                      movq    %r12, %rsi
// 51: 41 ff d5                      callq   *%r13
// 54: 85 c0                         testl   %eax, %eax
// 56: 78 5a                         js      0xb2 <_JIT_ENTRY+0xb2>
// 58: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 5d: 48 85 c0                      testq   %rax, %rax
// 60: 74 73                         je      0xd5 <_JIT_ENTRY+0xd5>
// 62: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 66: 48 83 c3 10                   addq    $0x10, %rbx
// 6a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006c:  R_X86_64_64  _JIT_CONTINUE
// 74: 4c 89 f7                      movq    %r14, %rdi
// 77: 48 89 de                      movq    %rbx, %rsi
// 7a: 4c 89 fa                      movq    %r15, %rdx
// 7d: 48 83 c4 10                   addq    $0x10, %rsp
// 81: 5b                            popq    %rbx
// 82: 41 5c                         popq    %r12
// 84: 41 5d                         popq    %r13
// 86: 41 5e                         popq    %r14
// 88: 41 5f                         popq    %r15
// 8a: ff e0                         jmpq    *%rax
// 8c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000008e:  R_X86_64_64  PyExc_SystemError
// 96: 48 8b 30                      movq    (%rax), %rsi
// 99: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000009b:  R_X86_64_64  .rodata.str1.1+0x1d
// a3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a5:  R_X86_64_64  _PyErr_SetString
// ad: 4c 89 ff                      movq    %r15, %rdi
// b0: ff d0                         callq   *%rax
// b2: 48 83 c3 08                   addq    $0x8, %rbx
// b6: 4c 29 f3                      subq    %r14, %rbx
// b9: 48 83 c3 b8                   addq    $-0x48, %rbx
// bd: 48 c1 eb 03                   shrq    $0x3, %rbx
// c1: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// c5: 31 c0                         xorl    %eax, %eax
// c7: 48 83 c4 10                   addq    $0x10, %rsp
// cb: 5b                            popq    %rbx
// cc: 41 5c                         popq    %r12
// ce: 41 5d                         popq    %r13
// d0: 41 5e                         popq    %r14
// d2: 41 5f                         popq    %r15
// d4: c3                            retq
// d5: 49 8b 7e 18                   movq    0x18(%r14), %rdi
// d9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000db:  R_X86_64_64  PyDict_GetItemRef
// e3: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// e8: 4c 89 e6                      movq    %r12, %rsi
// eb: ff d0                         callq   *%rax
// ed: 85 c0                         testl   %eax, %eax
// ef: 78 c1                         js      0xb2 <_JIT_ENTRY+0xb2>
// f1: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// f6: 48 85 c0                      testq   %rax, %rax
// f9: 0f 85 63 ff ff ff             jne     0x62 <_JIT_ENTRY+0x62>
// ff: 49 8b 7e 20                   movq    0x20(%r14), %rdi
// 103: 48 8d 54 24 08                leaq    0x8(%rsp), %rdx
// 108: 4c 89 e6                      movq    %r12, %rsi
// 10b: 41 ff d5                      callq   *%r13
// 10e: 85 c0                         testl   %eax, %eax
// 110: 78 a0                         js      0xb2 <_JIT_ENTRY+0xb2>
// 112: 48 8b 44 24 08                movq    0x8(%rsp), %rax
// 117: 48 85 c0                      testq   %rax, %rax
// 11a: 0f 85 42 ff ff ff             jne     0x62 <_JIT_ENTRY+0x62>
// 120: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000122:  R_X86_64_64  PyExc_NameError
// 12a: 48 8b 30                      movq    (%rax), %rsi
// 12d: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 000000000000012f:  R_X86_64_64  .rodata.str1.1
// 137: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000139:  R_X86_64_64  _PyEval_FormatExcCheckArg
// 141: 4c 89 ff                      movq    %r15, %rdi
// 144: 4c 89 e1                      movq    %r12, %rcx
// 147: ff d0                         callq   *%rax
// 149: e9 64 ff ff ff                jmp     0xb2 <_JIT_ENTRY+0xb2>
// 14e: 
static const unsigned char _PUSH_NULLplus_LOAD_NAME_code_body[335] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x10, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7f, 0x28, 0x48, 0x85, 0xff, 0x74, 0x66, 0x49, 0x8b, 0x06, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4c, 0x8b, 0x64, 0xc8, 0x18, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x4c, 0x89, 0xe6, 0x41, 0xff, 0xd5, 0x85, 0xc0, 0x78, 0x5a, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x74, 0x73, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0xff, 0xd0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x10, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x49, 0x8b, 0x7e, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x4c, 0x89, 0xe6, 0xff, 0xd0, 0x85, 0xc0, 0x78, 0xc1, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x0f, 0x85, 0x63, 0xff, 0xff, 0xff, 0x49, 0x8b, 0x7e, 0x20, 0x48, 0x8d, 0x54, 0x24, 0x08, 0x4c, 0x89, 0xe6, 0x41, 0xff, 0xd5, 0x85, 0xc0, 0x78, 0xa0, 0x48, 0x8b, 0x44, 0x24, 0x08, 0x48, 0x85, 0xc0, 0x0f, 0x85, 0x42, 0xff, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xe1, 0xff, 0xd0, 0xe9, 0x64, 0xff, 0xff, 0xff};
static const Hole _PUSH_NULLplus_LOAD_NAME_code_holes[11] = {
    {0x2f, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x6c, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x8e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x1d},
    {0xa5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_SetString, 0x0},
    {0xdb, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_GetItemRef, 0x0},
    {0x122, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_NameError, 0x0},
    {0x12f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x139, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FormatExcCheckArg, 0x0},
};
// 0: "name '%.200s' is not defined\x00no locals found\x00"
// 2d: 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_NAME_data_body[49] = {0x6e, 0x61, 0x6d, 0x65, 0x20, 0x27, 0x25, 0x2e, 0x32, 0x30, 0x30, 0x73, 0x27, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x00, 0x6e, 0x6f, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x73, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_NAME_data_holes[1];

// _PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// f: 49 be 00 00 00 00 00 00 00 00 movabsq $0x0, %r14
// 0000000000000011:  R_X86_64_64  PySuper_Type
// 19: 4c 39 76 f0                   cmpq    %r14, -0x10(%rsi)
// 1d: 75 11                         jne     0x30 <_JIT_ENTRY+0x30>
// 1f: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// 23: 48 8b 43 08                   movq    0x8(%rbx), %rax
// 27: f6 80 ab 00 00 00 80          testb   $-0x80, 0xab(%rax)
// 2e: 75 33                         jne     0x63 <_JIT_ENTRY+0x63>
// 30: 48 29 fe                      subq    %rdi, %rsi
// 33: 48 83 c6 c0                   addq    $-0x40, %rsi
// 37: 48 c1 ee 03                   shrq    $0x3, %rsi
// 3b: 89 77 40                      movl    %esi, 0x40(%rdi)
// 3e: 48 8b 07                      movq    (%rdi), %rax
// 41: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000043:  R_X86_64_64  _JIT_TARGET
// 4b: 89 c9                         movl    %ecx, %ecx
// 4d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 51: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 57: 48 83 c4 08                   addq    $0x8, %rsp
// 5b: 5b                            popq    %rbx
// 5c: 41 5c                         popq    %r12
// 5e: 41 5e                         popq    %r14
// 60: 41 5f                         popq    %r15
// 62: c3                            retq
// 63: 48 8b 07                      movq    (%rdi), %rax
// 66: 48 8b 40 20                   movq    0x20(%rax), %rax
// 6a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000006c:  R_X86_64_64  _JIT_OPARG
// 74: 81 e1 fc ff 00 00             andl    $0xfffc, %ecx           # imm = 0xFFFC
// 7a: 48 8b 54 48 18                movq    0x18(%rax,%rcx,2), %rdx
// 7f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000081:  R_X86_64_64  _PySuper_Lookup
// 89: 48 89 df                      movq    %rbx, %rdi
// 8c: 31 f6                         xorl    %esi, %esi
// 8e: 31 c9                         xorl    %ecx, %ecx
// 90: ff d0                         callq   *%rax
// 92: 49 8b 06                      movq    (%r14), %rax
// 95: 48 85 c0                      testq   %rax, %rax
// 98: 7f 21                         jg      0xbb <_JIT_ENTRY+0xbb>
// 9a: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000009c:  R_X86_64_64  .rodata.str1.1
// a4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a6:  R_X86_64_64  _Py_NegativeRefcount
// ae: be fc 05 00 00                movl    $0x5fc, %esi            # imm = 0x5FC
// b3: 4c 89 f2                      movq    %r14, %rdx
// b6: ff d0                         callq   *%rax
// b8: 49 8b 06                      movq    (%r14), %rax
// bb: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 00000000000000bd:  R_X86_64_64  _Py_DECREF_DecRefTotal
// c5: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 00000000000000c7:  R_X86_64_64  _Py_Dealloc
// cf: 85 c0                         testl   %eax, %eax
// d1: 78 15                         js      0xe8 <_JIT_ENTRY+0xe8>
// d3: 41 ff d4                      callq   *%r12
// d6: 49 ff 0e                      decq    (%r14)
// d9: 75 0d                         jne     0xe8 <_JIT_ENTRY+0xe8>
// db: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000dd:  R_X86_64_64  PySuper_Type
// e5: 41 ff d7                      callq   *%r15
// e8: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// ec: 7f 1e                         jg      0x10c <_JIT_ENTRY+0x10c>
// ee: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000f0:  R_X86_64_64  .rodata.str1.1
// f8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000fa:  R_X86_64_64  _Py_NegativeRefcount
// 102: be fd 05 00 00                movl    $0x5fd, %esi            # imm = 0x5FD
// 107: 48 89 da                      movq    %rbx, %rdx
// 10a: ff d0                         callq   *%rax
// 10c: 41 ff d4                      callq   *%r12
// 10f: 48 ff 0b                      decq    (%rbx)
// 112: 48 89 df                      movq    %rbx, %rdi
// 115: 41 ff d7                      callq   *%r15
// 118: 
static const unsigned char _PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR_code_body[281] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x39, 0x76, 0xf0, 0x75, 0x11, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0x8b, 0x43, 0x08, 0xf6, 0x80, 0xab, 0x00, 0x00, 0x00, 0x80, 0x75, 0x33, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xe1, 0xfc, 0xff, 0x00, 0x00, 0x48, 0x8b, 0x54, 0x48, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0x31, 0xc9, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7f, 0x21, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xfc, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x15, 0x41, 0xff, 0xd4, 0x49, 0xff, 0x0e, 0x75, 0x0d, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xff, 0xd7, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xfd, 0x05, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x41, 0xff, 0xd4, 0x48, 0xff, 0x0b, 0x48, 0x89, 0xdf, 0x41, 0xff, 0xd7};
static const Hole _PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR_code_holes[12] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySuper_Type, 0x0},
    {0x43, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x6c, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x81, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PySuper_Lookup, 0x0},
    {0x9c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xa6, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xbd, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xc7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xdd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySuper_Type, 0x0},
    {0xf0, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xfa, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR_data_holes[1];

// _PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %rbp
// 000000000000001a:  R_X86_64_64  PySuper_Type
// 22: 48 39 6e f0                   cmpq    %rbp, -0x10(%rsi)
// 26: 75 12                         jne     0x3a <_JIT_ENTRY+0x3a>
// 28: 4c 8b 63 f8                   movq    -0x8(%rbx), %r12
// 2c: 49 8b 44 24 08                movq    0x8(%r12), %rax
// 31: f6 80 ab 00 00 00 80          testb   $-0x80, 0xab(%rax)
// 38: 75 37                         jne     0x71 <_JIT_ENTRY+0x71>
// 3a: 4c 29 f3                      subq    %r14, %rbx
// 3d: 48 83 c3 c0                   addq    $-0x40, %rbx
// 41: 48 c1 eb 03                   shrq    $0x3, %rbx
// 45: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 49: 49 8b 06                      movq    (%r14), %rax
// 4c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004e:  R_X86_64_64  _JIT_TARGET
// 56: 89 c9                         movl    %ecx, %ecx
// 58: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 5c: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 62: 48 83 c4 08                   addq    $0x8, %rsp
// 66: 5b                            popq    %rbx
// 67: 41 5c                         popq    %r12
// 69: 41 5d                         popq    %r13
// 6b: 41 5e                         popq    %r14
// 6d: 41 5f                         popq    %r15
// 6f: 5d                            popq    %rbp
// 70: c3                            retq
// 71: 49 89 d7                      movq    %rdx, %r15
// 74: 49 8b 06                      movq    (%r14), %rax
// 77: 48 8b 40 20                   movq    0x20(%rax), %rax
// 7b: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000007d:  R_X86_64_64  _JIT_OPARG
// 85: 81 e1 fc ff 00 00             andl    $0xfffc, %ecx           # imm = 0xFFFC
// 8b: 48 8b 54 48 18                movq    0x18(%rax,%rcx,2), %rdx
// 90: c7 44 24 04 00 00 00 00       movl    $0x0, 0x4(%rsp)
// 98: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// a0: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000a2:  R_X86_64_64  PyObject_GenericGetAttr
// aa: 31 f6                         xorl    %esi, %esi
// ac: 48 39 88 90 00 00 00          cmpq    %rcx, 0x90(%rax)
// b3: 48 8d 4c 24 04                leaq    0x4(%rsp), %rcx
// b8: 48 0f 45 ce                   cmovneq %rsi, %rcx
// bc: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000be:  R_X86_64_64  _PySuper_Lookup
// c6: 4c 89 e7                      movq    %r12, %rdi
// c9: 31 f6                         xorl    %esi, %esi
// cb: ff d0                         callq   *%rax
// cd: 49 89 c5                      movq    %rax, %r13
// d0: 48 8b 45 00                   movq    (%rbp), %rax
// d4: 48 85 c0                      testq   %rax, %rax
// d7: 7f 22                         jg      0xfb <_JIT_ENTRY+0xfb>
// d9: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000db:  R_X86_64_64  .rodata.str1.1
// e3: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000e5:  R_X86_64_64  _Py_NegativeRefcount
// ed: be 18 06 00 00                movl    $0x618, %esi            # imm = 0x618
// f2: 48 89 ea                      movq    %rbp, %rdx
// f5: ff d0                         callq   *%rax
// f7: 48 8b 45 00                   movq    (%rbp), %rax
// fb: 85 c0                         testl   %eax, %eax
// fd: 78 28                         js      0x127 <_JIT_ENTRY+0x127>
// ff: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000101:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 109: ff d0                         callq   *%rax
// 10b: 48 ff 4d 00                   decq    (%rbp)
// 10f: 75 16                         jne     0x127 <_JIT_ENTRY+0x127>
// 111: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000113:  R_X86_64_64  PySuper_Type
// 11b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000011d:  R_X86_64_64  _Py_Dealloc
// 125: ff d0                         callq   *%rax
// 127: 49 8b 04 24                   movq    (%r12), %rax
// 12b: 48 85 c0                      testq   %rax, %rax
// 12e: 7f 22                         jg      0x152 <_JIT_ENTRY+0x152>
// 130: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000132:  R_X86_64_64  .rodata.str1.1
// 13a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000013c:  R_X86_64_64  _Py_NegativeRefcount
// 144: be 19 06 00 00                movl    $0x619, %esi            # imm = 0x619
// 149: 4c 89 e2                      movq    %r12, %rdx
// 14c: ff d0                         callq   *%rax
// 14e: 49 8b 04 24                   movq    (%r12), %rax
// 152: 85 c0                         testl   %eax, %eax
// 154: 78 21                         js      0x177 <_JIT_ENTRY+0x177>
// 156: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000158:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 160: ff d0                         callq   *%rax
// 162: 49 ff 0c 24                   decq    (%r12)
// 166: 75 0f                         jne     0x177 <_JIT_ENTRY+0x177>
// 168: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000016a:  R_X86_64_64  _Py_Dealloc
// 172: 4c 89 e7                      movq    %r12, %rdi
// 175: ff d0                         callq   *%rax
// 177: 4c 89 6b f0                   movq    %r13, -0x10(%rbx)
// 17b: 48 c7 43 f8 00 00 00 00       movq    $0x0, -0x8(%rbx)
// 183: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000185:  R_X86_64_64  _JIT_CONTINUE
// 18d: 4c 89 f7                      movq    %r14, %rdi
// 190: 48 89 de                      movq    %rbx, %rsi
// 193: 4c 89 fa                      movq    %r15, %rdx
// 196: 48 83 c4 08                   addq    $0x8, %rsp
// 19a: 5b                            popq    %rbx
// 19b: 41 5c                         popq    %r12
// 19d: 41 5d                         popq    %r13
// 19f: 41 5e                         popq    %r14
// 1a1: 41 5f                         popq    %r15
// 1a3: 5d                            popq    %rbp
// 1a4: ff e0                         jmpq    *%rax
// 1a6: 
static const unsigned char _PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD_code_body[423] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x6e, 0xf0, 0x75, 0x12, 0x4c, 0x8b, 0x63, 0xf8, 0x49, 0x8b, 0x44, 0x24, 0x08, 0xf6, 0x80, 0xab, 0x00, 0x00, 0x00, 0x80, 0x75, 0x37, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x49, 0x8b, 0x06, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x49, 0x89, 0xd7, 0x49, 0x8b, 0x06, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xe1, 0xfc, 0xff, 0x00, 0x00, 0x48, 0x8b, 0x54, 0x48, 0x18, 0xc7, 0x44, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0x48, 0x39, 0x88, 0x90, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x4c, 0x24, 0x04, 0x48, 0x0f, 0x45, 0xce, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x31, 0xf6, 0xff, 0xd0, 0x49, 0x89, 0xc5, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x18, 0x06, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x28, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x16, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x19, 0x06, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x4c, 0x89, 0x6b, 0xf0, 0x48, 0xc7, 0x43, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD_code_holes[16] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySuper_Type, 0x0},
    {0x4e, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x7d, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0xa2, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_GenericGetAttr, 0x0},
    {0xbe, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PySuper_Lookup, 0x0},
    {0xdb, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xe5, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x101, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x113, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySuper_Type, 0x0},
    {0x11d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x132, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x13c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x158, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x16a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x185, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD_data_holes[1];

// _PUSH_NULLplus_MAKE_CELL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MAKE_CELL.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 f3                      movq    %rsi, %rbx
// e: 49 89 fe                      movq    %rdi, %r14
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 83 c3 08                   addq    $0x8, %rbx
// 1c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001e:  R_X86_64_64  _JIT_OPARG
// 26: 0f b7 c0                      movzwl  %ax, %eax
// 29: 48 8b 7c c7 48                movq    0x48(%rdi,%rax,8), %rdi
// 2e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000030:  R_X86_64_64  PyCell_New
// 38: ff d0                         callq   *%rax
// 3a: 48 85 c0                      testq   %rax, %rax
// 3d: 74 2b                         je      0x6a <_JIT_ENTRY+0x6a>
// 3f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000041:  R_X86_64_64  _JIT_OPARG
// 49: 0f b7 c9                      movzwl  %cx, %ecx
// 4c: 4d 8b 64 ce 48                movq    0x48(%r14,%rcx,8), %r12
// 51: 49 89 44 ce 48                movq    %rax, 0x48(%r14,%rcx,8)
// 56: 4d 85 e4                      testq   %r12, %r12
// 59: 74 73                         je      0xce <_JIT_ENTRY+0xce>
// 5b: 49 8b 04 24                   movq    (%r12), %rax
// 5f: 48 85 c0                      testq   %rax, %rax
// 62: 7e 23                         jle     0x87 <_JIT_ENTRY+0x87>
// 64: 85 c0                         testl   %eax, %eax
// 66: 79 45                         jns     0xad <_JIT_ENTRY+0xad>
// 68: eb 64                         jmp     0xce <_JIT_ENTRY+0xce>
// 6a: 4c 29 f3                      subq    %r14, %rbx
// 6d: 48 83 c3 b8                   addq    $-0x48, %rbx
// 71: 48 c1 eb 03                   shrq    $0x3, %rbx
// 75: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 79: 31 c0                         xorl    %eax, %eax
// 7b: 48 83 c4 08                   addq    $0x8, %rsp
// 7f: 5b                            popq    %rbx
// 80: 41 5c                         popq    %r12
// 82: 41 5e                         popq    %r14
// 84: 41 5f                         popq    %r15
// 86: c3                            retq
// 87: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000089:  R_X86_64_64  .rodata.str1.1
// 91: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000093:  R_X86_64_64  _Py_NegativeRefcount
// 9b: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// a0: 4c 89 e2                      movq    %r12, %rdx
// a3: ff d0                         callq   *%rax
// a5: 49 8b 04 24                   movq    (%r12), %rax
// a9: 85 c0                         testl   %eax, %eax
// ab: 78 21                         js      0xce <_JIT_ENTRY+0xce>
// ad: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000af:  R_X86_64_64  _Py_DECREF_DecRefTotal
// b7: ff d0                         callq   *%rax
// b9: 49 ff 0c 24                   decq    (%r12)
// bd: 75 0f                         jne     0xce <_JIT_ENTRY+0xce>
// bf: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c1:  R_X86_64_64  _Py_Dealloc
// c9: 4c 89 e7                      movq    %r12, %rdi
// cc: ff d0                         callq   *%rax
// ce: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d0:  R_X86_64_64  _JIT_CONTINUE
// d8: 4c 89 f7                      movq    %r14, %rdi
// db: 48 89 de                      movq    %rbx, %rsi
// de: 4c 89 fa                      movq    %r15, %rdx
// e1: 48 83 c4 08                   addq    $0x8, %rsp
// e5: 5b                            popq    %rbx
// e6: 41 5c                         popq    %r12
// e8: 41 5e                         popq    %r14
// ea: 41 5f                         popq    %r15
// ec: ff e0                         jmpq    *%rax
// ee: 
static const unsigned char _PUSH_NULLplus_MAKE_CELL_code_body[239] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x7c, 0xc7, 0x48, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x2b, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x4d, 0x8b, 0x64, 0xce, 0x48, 0x49, 0x89, 0x44, 0xce, 0x48, 0x4d, 0x85, 0xe4, 0x74, 0x73, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x23, 0x85, 0xc0, 0x79, 0x45, 0xeb, 0x64, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_MAKE_CELL_code_holes[9] = {
    {0x1e, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x30, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyCell_New, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x93, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xaf, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xc1, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xd0, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Include/object.h\x00'
// 30: 
static const unsigned char _PUSH_NULLplus_MAKE_CELL_data_body[49] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00};
static const Hole _PUSH_NULLplus_MAKE_CELL_data_holes[1];

// _PUSH_NULLplus_MAKE_FUNCTION
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MAKE_FUNCTION.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 77 18                   movq    0x18(%rdi), %rsi
// c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000e:  R_X86_64_64  PyFunction_New
// 16: 31 ff                         xorl    %edi, %edi
// 18: ff d0                         callq   *%rax
// 1a: 
static const unsigned char _PUSH_NULLplus_MAKE_FUNCTION_code_body[27] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x77, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_MAKE_FUNCTION_code_holes[2] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyFunction_New, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_MAKE_FUNCTION_data_body[1];
static const Hole _PUSH_NULLplus_MAKE_FUNCTION_data_holes[1];

// _PUSH_NULLplus_MAP_ADD
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MAP_ADD.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 49 89 d7                      movq    %rdx, %r15
// b: 48 89 fb                      movq    %rdi, %rbx
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 4c 8d 76 08                   leaq    0x8(%rsi), %r14
// 19: 4c 8d 66 f8                   leaq    -0x8(%rsi), %r12
// 1d: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// 21: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000023:  R_X86_64_64  _JIT_OPARG
// 2b: 0f b7 c9                      movzwl  %cx, %ecx
// 2e: ba fe ff ff ff                movl    $0xfffffffe, %edx       # imm = 0xFFFFFFFE
// 33: 29 ca                         subl    %ecx, %edx
// 35: 48 63 ca                      movslq  %edx, %rcx
// 38: 48 8b 7c ce 08                movq    0x8(%rsi,%rcx,8), %rdi
// 3d: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003f:  R_X86_64_64  _PyDict_SetItem_Take2
// 47: 48 89 c6                      movq    %rax, %rsi
// 4a: 31 d2                         xorl    %edx, %edx
// 4c: ff d1                         callq   *%rcx
// 4e: 85 c0                         testl   %eax, %eax
// 50: 4d 0f 44 f4                   cmoveq  %r12, %r14
// 54: 74 1d                         je      0x73 <_JIT_ENTRY+0x73>
// 56: 49 29 de                      subq    %rbx, %r14
// 59: 49 83 c6 a8                   addq    $-0x58, %r14
// 5d: 49 c1 ee 03                   shrq    $0x3, %r14
// 61: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 65: 31 c0                         xorl    %eax, %eax
// 67: 48 83 c4 08                   addq    $0x8, %rsp
// 6b: 5b                            popq    %rbx
// 6c: 41 5c                         popq    %r12
// 6e: 41 5e                         popq    %r14
// 70: 41 5f                         popq    %r15
// 72: c3                            retq
// 73: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000075:  R_X86_64_64  _JIT_CONTINUE
// 7d: 48 89 df                      movq    %rbx, %rdi
// 80: 4c 89 f6                      movq    %r14, %rsi
// 83: 4c 89 fa                      movq    %r15, %rdx
// 86: 48 83 c4 08                   addq    $0x8, %rsp
// 8a: 5b                            popq    %rbx
// 8b: 41 5c                         popq    %r12
// 8d: 41 5e                         popq    %r14
// 8f: 41 5f                         popq    %r15
// 91: ff e0                         jmpq    *%rax
// 93: 
static const unsigned char _PUSH_NULLplus_MAP_ADD_code_body[148] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x76, 0x08, 0x4c, 0x8d, 0x66, 0xf8, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0xba, 0xfe, 0xff, 0xff, 0xff, 0x29, 0xca, 0x48, 0x63, 0xca, 0x48, 0x8b, 0x7c, 0xce, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xc6, 0x31, 0xd2, 0xff, 0xd1, 0x85, 0xc0, 0x4d, 0x0f, 0x44, 0xf4, 0x74, 0x1d, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xa8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_MAP_ADD_code_holes[4] = {
    {0x23, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_SetItem_Take2, 0x0},
    {0x75, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_MAP_ADD_data_body[1];
static const Hole _PUSH_NULLplus_MAP_ADD_data_holes[1];

// _PUSH_NULLplus_MATCH_CLASS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MATCH_CLASS.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d7                      movq    %rdx, %rdi
// b: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 12: 4c 8b 76 f0                   movq    -0x10(%rsi), %r14
// 16: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// 1a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001c:  R_X86_64_64  _JIT_OPARG
// 24: 0f b7 c8                      movzwl  %ax, %ecx
// 27: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000029:  R_X86_64_64  _PyEval_MatchClass
// 31: 4c 89 f6                      movq    %r14, %rsi
// 34: 48 89 da                      movq    %rbx, %rdx
// 37: 45 31 c0                      xorl    %r8d, %r8d
// 3a: ff d0                         callq   *%rax
// 3c: 49 8b 06                      movq    (%r14), %rax
// 3f: 48 85 c0                      testq   %rax, %rax
// 42: 7e 1a                         jle     0x5e <_JIT_ENTRY+0x5e>
// 44: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 0000000000000046:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4e: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 0000000000000050:  R_X86_64_64  _Py_Dealloc
// 58: 85 c0                         testl   %eax, %eax
// 5a: 79 3b                         jns     0x97 <_JIT_ENTRY+0x97>
// 5c: eb 41                         jmp     0x9f <_JIT_ENTRY+0x9f>
// 5e: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000060:  R_X86_64_64  .rodata.str1.1
// 68: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006a:  R_X86_64_64  _Py_NegativeRefcount
// 72: be 10 08 00 00                movl    $0x810, %esi            # imm = 0x810
// 77: 4c 89 f2                      movq    %r14, %rdx
// 7a: ff d0                         callq   *%rax
// 7c: 49 8b 06                      movq    (%r14), %rax
// 7f: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 0000000000000081:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 89: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000008b:  R_X86_64_64  _Py_Dealloc
// 93: 85 c0                         testl   %eax, %eax
// 95: 78 08                         js      0x9f <_JIT_ENTRY+0x9f>
// 97: 41 ff d4                      callq   *%r12
// 9a: 49 ff 0e                      decq    (%r14)
// 9d: 74 12                         je      0xb1 <_JIT_ENTRY+0xb1>
// 9f: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// a3: 7e 18                         jle     0xbd <_JIT_ENTRY+0xbd>
// a5: 41 ff d4                      callq   *%r12
// a8: 48 ff 0b                      decq    (%rbx)
// ab: 48 89 df                      movq    %rbx, %rdi
// ae: 41 ff d7                      callq   *%r15
// b1: 4c 89 f7                      movq    %r14, %rdi
// b4: 41 ff d7                      callq   *%r15
// b7: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// bb: 7f e8                         jg      0xa5 <_JIT_ENTRY+0xa5>
// bd: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000bf:  R_X86_64_64  .rodata.str1.1
// c7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c9:  R_X86_64_64  _Py_NegativeRefcount
// d1: be 11 08 00 00                movl    $0x811, %esi            # imm = 0x811
// d6: 48 89 da                      movq    %rbx, %rdx
// d9: ff d0                         callq   *%rax
// db: 41 ff d4                      callq   *%r12
// de: 48 ff 0b                      decq    (%rbx)
// e1: 48 89 df                      movq    %rbx, %rdi
// e4: 41 ff d7                      callq   *%r15
// e7: 
static const unsigned char _PUSH_NULLplus_MATCH_CLASS_code_body[232] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x76, 0xf0, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x45, 0x31, 0xc0, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x1a, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x79, 0x3b, 0xeb, 0x41, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x10, 0x08, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x08, 0x41, 0xff, 0xd4, 0x49, 0xff, 0x0e, 0x74, 0x12, 0x48, 0x83, 0x3b, 0x00, 0x7e, 0x18, 0x41, 0xff, 0xd4, 0x48, 0xff, 0x0b, 0x48, 0x89, 0xdf, 0x41, 0xff, 0xd7, 0x4c, 0x89, 0xf7, 0x41, 0xff, 0xd7, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0xe8, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x11, 0x08, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x41, 0xff, 0xd4, 0x48, 0xff, 0x0b, 0x48, 0x89, 0xdf, 0x41, 0xff, 0xd7};
static const Hole _PUSH_NULLplus_MATCH_CLASS_code_holes[11] = {
    {0x1c, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x29, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_MatchClass, 0x0},
    {0x46, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x50, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x81, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x8b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xbf, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xc9, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_MATCH_CLASS_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_MATCH_CLASS_data_holes[1];

// _PUSH_NULLplus_MATCH_KEYS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MATCH_KEYS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 49 89 d7                      movq    %rdx, %r15
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 49 89 fe                      movq    %rdi, %r14
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 48 8b 76 f8                   movq    -0x8(%rsi), %rsi
// 19: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001b:  R_X86_64_64  _PyEval_MatchKeys
// 23: 48 89 d7                      movq    %rdx, %rdi
// 26: 31 d2                         xorl    %edx, %edx
// 28: ff d0                         callq   *%rax
// 2a: 48 85 c0                      testq   %rax, %rax
// 2d: 74 22                         je      0x51 <_JIT_ENTRY+0x51>
// 2f: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// 33: 48 83 c3 10                   addq    $0x10, %rbx
// 37: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000039:  R_X86_64_64  _JIT_CONTINUE
// 41: 4c 89 f7                      movq    %r14, %rdi
// 44: 48 89 de                      movq    %rbx, %rsi
// 47: 4c 89 fa                      movq    %r15, %rdx
// 4a: 5b                            popq    %rbx
// 4b: 41 5e                         popq    %r14
// 4d: 41 5f                         popq    %r15
// 4f: ff e0                         jmpq    *%rax
// 51: 48 83 c3 08                   addq    $0x8, %rbx
// 55: 4c 29 f3                      subq    %r14, %rbx
// 58: 48 83 c3 b8                   addq    $-0x48, %rbx
// 5c: 48 c1 eb 03                   shrq    $0x3, %rbx
// 60: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 64: 31 c0                         xorl    %eax, %eax
// 66: 5b                            popq    %rbx
// 67: 41 5e                         popq    %r14
// 69: 41 5f                         popq    %r15
// 6b: c3                            retq
// 6c: 
static const unsigned char _PUSH_NULLplus_MATCH_KEYS_code_body[109] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x76, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x31, 0xd2, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x22, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_MATCH_KEYS_code_holes[3] = {
    {0x1b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_MatchKeys, 0x0},
    {0x39, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_MATCH_KEYS_data_body[1];
static const Hole _PUSH_NULLplus_MATCH_KEYS_data_holes[1];

// _PUSH_NULLplus_MATCH_MAPPING
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MATCH_MAPPING.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// f: f6 80 a8 00 00 00 40          testb   $0x40, 0xa8(%rax)
// 16: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000018:  R_X86_64_64  _Py_FalseStruct
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  _Py_TrueStruct
// 2a: 48 0f 44 c8                   cmoveq  %rax, %rcx
// 2e: 48 89 4e 08                   movq    %rcx, 0x8(%rsi)
// 32: 48 83 c6 10                   addq    $0x10, %rsi
// 36: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000038:  R_X86_64_64  _JIT_CONTINUE
// 40: ff e0                         jmpq    *%rax
// 42: 
static const unsigned char _PUSH_NULLplus_MATCH_MAPPING_code_body[67] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0xf6, 0x80, 0xa8, 0x00, 0x00, 0x00, 0x40, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x0f, 0x44, 0xc8, 0x48, 0x89, 0x4e, 0x08, 0x48, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_MATCH_MAPPING_code_holes[4] = {
    {0x18, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_FalseStruct, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_TrueStruct, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_MATCH_MAPPING_data_body[1];
static const Hole _PUSH_NULLplus_MATCH_MAPPING_data_holes[1];

// _PUSH_NULLplus_MATCH_SEQUENCE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_MATCH_SEQUENCE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 04 25 08 00 00 00       movq    0x8, %rax
// f: f6 80 a8 00 00 00 20          testb   $0x20, 0xa8(%rax)
// 16: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000018:  R_X86_64_64  _Py_FalseStruct
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  _Py_TrueStruct
// 2a: 48 0f 44 c8                   cmoveq  %rax, %rcx
// 2e: 48 89 4e 08                   movq    %rcx, 0x8(%rsi)
// 32: 48 83 c6 10                   addq    $0x10, %rsi
// 36: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000038:  R_X86_64_64  _JIT_CONTINUE
// 40: ff e0                         jmpq    *%rax
// 42: 
static const unsigned char _PUSH_NULLplus_MATCH_SEQUENCE_code_body[67] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0xf6, 0x80, 0xa8, 0x00, 0x00, 0x00, 0x20, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x0f, 0x44, 0xc8, 0x48, 0x89, 0x4e, 0x08, 0x48, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_MATCH_SEQUENCE_code_holes[4] = {
    {0x18, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_FalseStruct, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_TrueStruct, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_MATCH_SEQUENCE_data_body[1];
static const Hole _PUSH_NULLplus_MATCH_SEQUENCE_data_holes[1];

// _PUSH_NULLplus_NOP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_NOP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_CONTINUE
// 15: ff e0                         jmpq    *%rax
// 17: 
static const unsigned char _PUSH_NULLplus_NOP_code_body[24] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_NOP_code_holes[2] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_NOP_data_body[1];
static const Hole _PUSH_NULLplus_NOP_data_holes[1];

// _PUSH_NULLplus_POP_EXCEPT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_POP_EXCEPT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 8b 42 70                   movq    0x70(%rdx), %rax
// 1c: 4c 8b 20                      movq    (%rax), %r12
// 1f: 48 c7 00 00 00 00 00          movq    $0x0, (%rax)
// 26: 4d 85 e4                      testq   %r12, %r12
// 29: 74 56                         je      0x81 <_JIT_ENTRY+0x81>
// 2b: 49 8b 04 24                   movq    (%r12), %rax
// 2f: 48 85 c0                      testq   %rax, %rax
// 32: 7e 06                         jle     0x3a <_JIT_ENTRY+0x3a>
// 34: 85 c0                         testl   %eax, %eax
// 36: 79 28                         jns     0x60 <_JIT_ENTRY+0x60>
// 38: eb 47                         jmp     0x81 <_JIT_ENTRY+0x81>
// 3a: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000003c:  R_X86_64_64  .rodata.str1.1
// 44: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000046:  R_X86_64_64  _Py_NegativeRefcount
// 4e: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// 53: 4c 89 e2                      movq    %r12, %rdx
// 56: ff d0                         callq   *%rax
// 58: 49 8b 04 24                   movq    (%r12), %rax
// 5c: 85 c0                         testl   %eax, %eax
// 5e: 78 21                         js      0x81 <_JIT_ENTRY+0x81>
// 60: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000062:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 6a: ff d0                         callq   *%rax
// 6c: 49 ff 0c 24                   decq    (%r12)
// 70: 75 0f                         jne     0x81 <_JIT_ENTRY+0x81>
// 72: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000074:  R_X86_64_64  _Py_Dealloc
// 7c: 4c 89 e7                      movq    %r12, %rdi
// 7f: ff d0                         callq   *%rax
// 81: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000083:  R_X86_64_64  _JIT_CONTINUE
// 8b: 4c 89 ff                      movq    %r15, %rdi
// 8e: 4c 89 f6                      movq    %r14, %rsi
// 91: 48 89 da                      movq    %rbx, %rdx
// 94: 48 83 c4 08                   addq    $0x8, %rsp
// 98: 5b                            popq    %rbx
// 99: 41 5c                         popq    %r12
// 9b: 41 5e                         popq    %r14
// 9d: 41 5f                         popq    %r15
// 9f: ff e0                         jmpq    *%rax
// a1: 
static const unsigned char _PUSH_NULLplus_POP_EXCEPT_code_body[162] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x42, 0x70, 0x4c, 0x8b, 0x20, 0x48, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x85, 0xe4, 0x74, 0x56, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_POP_EXCEPT_code_holes[6] = {
    {0x3c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x46, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x62, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x74, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x83, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Include/object.h\x00'
// 30: 
static const unsigned char _PUSH_NULLplus_POP_EXCEPT_data_body[49] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00};
static const Hole _PUSH_NULLplus_POP_EXCEPT_data_holes[1];

// _PUSH_NULLplus_POP_FRAME
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_POP_FRAME.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 56                         pushq   %r14
// 2: 53                            pushq   %rbx
// 3: 50                            pushq   %rax
// 4: 48 89 d3                      movq    %rdx, %rbx
// 7: 48 89 f8                      movq    %rdi, %rax
// a: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 11: 48 29 fe                      subq    %rdi, %rsi
// 14: 48 83 c6 b8                   addq    $-0x48, %rsi
// 18: 48 c1 ee 03                   shrq    $0x3, %rsi
// 1c: 89 77 40                      movl    %esi, 0x40(%rdi)
// 1f: ff 42 24                      incl    0x24(%rdx)
// 22: 4c 8b 77 08                   movq    0x8(%rdi), %r14
// 26: 4c 89 72 40                   movq    %r14, 0x40(%rdx)
// 2a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000002c:  R_X86_64_64  _PyEval_FrameClearAndPop
// 34: 48 89 d7                      movq    %rdx, %rdi
// 37: 48 89 c6                      movq    %rax, %rsi
// 3a: ff d1                         callq   *%rcx
// 3c: 49 63 46 40                   movslq  0x40(%r14), %rax
// 40: 49 c7 44 c6 48 00 00 00 00    movq    $0x0, 0x48(%r14,%rax,8)
// 49: 49 8d 34 c6                   leaq    (%r14,%rax,8), %rsi
// 4d: 48 83 c6 50                   addq    $0x50, %rsi
// 51: 41 c7 46 40 ff ff ff ff       movl    $0xffffffff, 0x40(%r14) # imm = 0xFFFFFFFF
// 59: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005b:  R_X86_64_64  _JIT_CONTINUE
// 63: 4c 89 f7                      movq    %r14, %rdi
// 66: 48 89 da                      movq    %rbx, %rdx
// 69: 48 83 c4 08                   addq    $0x8, %rsp
// 6d: 5b                            popq    %rbx
// 6e: 41 5e                         popq    %r14
// 70: ff e0                         jmpq    *%rax
// 72: 
static const unsigned char _PUSH_NULLplus_POP_FRAME_code_body[115] = {0x41, 0x56, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x48, 0x89, 0xf8, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0xff, 0x42, 0x24, 0x4c, 0x8b, 0x77, 0x08, 0x4c, 0x89, 0x72, 0x40, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0xc6, 0xff, 0xd1, 0x49, 0x63, 0x46, 0x40, 0x49, 0xc7, 0x44, 0xc6, 0x48, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8d, 0x34, 0xc6, 0x48, 0x83, 0xc6, 0x50, 0x41, 0xc7, 0x46, 0x40, 0xff, 0xff, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5e, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_POP_FRAME_code_holes[3] = {
    {0x2c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_FrameClearAndPop, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_POP_FRAME_data_body[1];
static const Hole _PUSH_NULLplus_POP_FRAME_data_holes[1];

// _PUSH_NULLplus_POP_TOP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_POP_TOP.o:      file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_POP_TOP_code_body[1] = {};
static const Hole _PUSH_NULLplus_POP_TOP_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_POP_TOP_data_body[1];
static const Hole _PUSH_NULLplus_POP_TOP_data_holes[1];

// _PUSH_NULLplus_PUSH_EXC_INFO
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_PUSH_EXC_INFO.o:        file format elf64-x86-64
// 0: 
static const unsigned char _PUSH_NULLplus_PUSH_EXC_INFO_code_body[1] = {};
static const Hole _PUSH_NULLplus_PUSH_EXC_INFO_code_holes[1];
// 0: 
static const unsigned char _PUSH_NULLplus_PUSH_EXC_INFO_data_body[1];
static const Hole _PUSH_NULLplus_PUSH_EXC_INFO_data_holes[1];

// _PUSH_NULLplus_PUSH_FRAME
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_PUSH_FRAME.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 b8                   addq    $-0x48, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 89 3c 25 08 00 00 00       movq    %rdi, 0x8
// 1d: 48 c7 42 40 00 00 00 00       movq    $0x0, 0x40(%rdx)
// 25: ff 4a 24                      decl    0x24(%rdx)
// 28: 48 63 04 25 40 00 00 00       movslq  0x40, %rax
// 30: 48 8d 34 c5 48 00 00 00       leaq    0x48(,%rax,8), %rsi
// 38: c7 04 25 40 00 00 00 ff ff ff ff      movl    $0xffffffff, 0x40 # imm = 0xFFFFFFFF
// 43: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000045:  R_X86_64_64  _JIT_CONTINUE
// 4d: 31 ff                         xorl    %edi, %edi
// 4f: ff e0                         jmpq    *%rax
// 51: 
static const unsigned char _PUSH_NULLplus_PUSH_FRAME_code_body[82] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x89, 0x3c, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x42, 0x40, 0x00, 0x00, 0x00, 0x00, 0xff, 0x4a, 0x24, 0x48, 0x63, 0x04, 0x25, 0x40, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x34, 0xc5, 0x48, 0x00, 0x00, 0x00, 0xc7, 0x04, 0x25, 0x40, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_PUSH_FRAME_code_holes[2] = {
    {0x45, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_PUSH_FRAME_data_body[1];
static const Hole _PUSH_NULLplus_PUSH_FRAME_data_holes[1];

// _PUSH_NULLplus_PUSH_NULL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_PUSH_NULL.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 0f 57 c0                      xorps   %xmm0, %xmm0
// 3: 0f 11 06                      movups  %xmm0, (%rsi)
// 6: 48 83 c6 10                   addq    $0x10, %rsi
// a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000c:  R_X86_64_64  _JIT_CONTINUE
// 14: ff e0                         jmpq    *%rax
// 16: 
static const unsigned char _PUSH_NULLplus_PUSH_NULL_code_body[23] = {0x0f, 0x57, 0xc0, 0x0f, 0x11, 0x06, 0x48, 0x83, 0xc6, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_PUSH_NULL_code_holes[2] = {
    {0xc, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_PUSH_NULL_data_body[1];
static const Hole _PUSH_NULLplus_PUSH_NULL_data_holes[1];

// _PUSH_NULLplus_RESUME_CHECK
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_RESUME_CHECK.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 8b 42 10                   movq    0x10(%rdx), %rax
// f: 48 8b 08                      movq    (%rax), %rcx
// 12: 48 8b 07                      movq    (%rdi), %rax
// 15: 48 3b 88 a8 00 00 00          cmpq    0xa8(%rax), %rcx
// 1c: 75 0c                         jne     0x2a <_JIT_ENTRY+0x2a>
// 1e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000020:  R_X86_64_64  _JIT_CONTINUE
// 28: ff e0                         jmpq    *%rax
// 2a: 48 29 fe                      subq    %rdi, %rsi
// 2d: 48 83 c6 b8                   addq    $-0x48, %rsi
// 31: 48 c1 ee 03                   shrq    $0x3, %rsi
// 35: 89 77 40                      movl    %esi, 0x40(%rdi)
// 38: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000003a:  R_X86_64_64  _JIT_TARGET
// 42: 89 c9                         movl    %ecx, %ecx
// 44: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 48: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 4e: c3                            retq
// 4f: 
static const unsigned char _PUSH_NULLplus_RESUME_CHECK_code_body[80] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b, 0x42, 0x10, 0x48, 0x8b, 0x08, 0x48, 0x8b, 0x07, 0x48, 0x3b, 0x88, 0xa8, 0x00, 0x00, 0x00, 0x75, 0x0c, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_RESUME_CHECK_code_holes[3] = {
    {0x20, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_RESUME_CHECK_data_body[1];
static const Hole _PUSH_NULLplus_RESUME_CHECK_data_holes[1];

// _PUSH_NULLplus_SAVE_RETURN_OFFSET
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SAVE_RETURN_OFFSET.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  _JIT_OPARG
// 11: 66 89 47 44                   movw    %ax, 0x44(%rdi)
// 15: 48 83 c6 08                   addq    $0x8, %rsi
// 19: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001b:  R_X86_64_64  _JIT_CONTINUE
// 23: ff e0                         jmpq    *%rax
// 25: 
static const unsigned char _PUSH_NULLplus_SAVE_RETURN_OFFSET_code_body[38] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x89, 0x47, 0x44, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_SAVE_RETURN_OFFSET_code_holes[3] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x1b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_SAVE_RETURN_OFFSET_data_body[1];
static const Hole _PUSH_NULLplus_SAVE_RETURN_OFFSET_data_holes[1];

// _PUSH_NULLplus_SETUP_ANNOTATIONS
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SETUP_ANNOTATIONS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 49 89 d7                      movq    %rdx, %r15
// e: 48 89 f3                      movq    %rsi, %rbx
// 11: 49 89 fe                      movq    %rdi, %r14
// 14: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1b: 48 83 c3 08                   addq    $0x8, %rbx
// 1f: 48 8b 7f 28                   movq    0x28(%rdi), %rdi
// 23: 48 85 ff                      testq   %rdi, %rdi
// 26: 0f 84 95 00 00 00             je      0xc1 <_JIT_ENTRY+0xc1>
// 2c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002e:  R_X86_64_64  PyMapping_GetOptionalItem
// 36: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000038:  R_X86_64_64  _PyRuntime
// 40: 49 81 c5 a8 a7 00 00          addq    $0xa7a8, %r13           # imm = 0xA7A8
// 47: 48 89 e2                      movq    %rsp, %rdx
// 4a: 4c 89 ee                      movq    %r13, %rsi
// 4d: ff d0                         callq   *%rax
// 4f: 85 c0                         testl   %eax, %eax
// 51: 0f 88 92 00 00 00             js      0xe9 <_JIT_ENTRY+0xe9>
// 57: 4c 8b 24 24                   movq    (%rsp), %r12
// 5b: 4d 85 e4                      testq   %r12, %r12
// 5e: 0f 84 a5 00 00 00             je      0x109 <_JIT_ENTRY+0x109>
// 64: 49 8b 04 24                   movq    (%r12), %rax
// 68: 48 85 c0                      testq   %rax, %rax
// 6b: 7f 22                         jg      0x8f <_JIT_ENTRY+0x8f>
// 6d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000006f:  R_X86_64_64  .rodata.str1.1
// 77: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000079:  R_X86_64_64  _Py_NegativeRefcount
// 81: be 96 05 00 00                movl    $0x596, %esi            # imm = 0x596
// 86: 4c 89 e2                      movq    %r12, %rdx
// 89: ff d0                         callq   *%rax
// 8b: 49 8b 04 24                   movq    (%r12), %rax
// 8f: 85 c0                         testl   %eax, %eax
// 91: 0f 88 fb 00 00 00             js      0x192 <_JIT_ENTRY+0x192>
// 97: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000099:  R_X86_64_64  _Py_DECREF_DecRefTotal
// a1: ff d0                         callq   *%rax
// a3: 49 ff 0c 24                   decq    (%r12)
// a7: 0f 85 e5 00 00 00             jne     0x192 <_JIT_ENTRY+0x192>
// ad: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000af:  R_X86_64_64  _Py_Dealloc
// b7: 4c 89 e7                      movq    %r12, %rdi
// ba: ff d0                         callq   *%rax
// bc: e9 d1 00 00 00                jmp     0x192 <_JIT_ENTRY+0x192>
// c1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c3:  R_X86_64_64  PyExc_SystemError
// cb: 48 8b 30                      movq    (%rax), %rsi
// ce: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 00000000000000d0:  R_X86_64_64  .rodata.str1.1+0x39
// d8: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 00000000000000da:  R_X86_64_64  _PyErr_Format
// e2: 4c 89 ff                      movq    %r15, %rdi
// e5: 31 c0                         xorl    %eax, %eax
// e7: ff d1                         callq   *%rcx
// e9: 4c 29 f3                      subq    %r14, %rbx
// ec: 48 83 c3 b8                   addq    $-0x48, %rbx
// f0: 48 c1 eb 03                   shrq    $0x3, %rbx
// f4: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// f8: 31 c0                         xorl    %eax, %eax
// fa: 48 83 c4 08                   addq    $0x8, %rsp
// fe: 5b                            popq    %rbx
// ff: 41 5c                         popq    %r12
// 101: 41 5d                         popq    %r13
// 103: 41 5e                         popq    %r14
// 105: 41 5f                         popq    %r15
// 107: 5d                            popq    %rbp
// 108: c3                            retq
// 109: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000010b:  R_X86_64_64  PyDict_New
// 113: ff d0                         callq   *%rax
// 115: 48 89 04 24                   movq    %rax, (%rsp)
// 119: 48 85 c0                      testq   %rax, %rax
// 11c: 74 cb                         je      0xe9 <_JIT_ENTRY+0xe9>
// 11e: 49 8b 7e 28                   movq    0x28(%r14), %rdi
// 122: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000124:  R_X86_64_64  PyObject_SetItem
// 12c: 4c 89 ee                      movq    %r13, %rsi
// 12f: 48 89 c2                      movq    %rax, %rdx
// 132: ff d1                         callq   *%rcx
// 134: 89 c5                         movl    %eax, %ebp
// 136: 4c 8b 24 24                   movq    (%rsp), %r12
// 13a: 49 8b 04 24                   movq    (%r12), %rax
// 13e: 48 85 c0                      testq   %rax, %rax
// 141: 7f 22                         jg      0x165 <_JIT_ENTRY+0x165>
// 143: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000145:  R_X86_64_64  .rodata.str1.1
// 14d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000014f:  R_X86_64_64  _Py_NegativeRefcount
// 157: be 92 05 00 00                movl    $0x592, %esi            # imm = 0x592
// 15c: 4c 89 e2                      movq    %r12, %rdx
// 15f: ff d0                         callq   *%rax
// 161: 49 8b 04 24                   movq    (%r12), %rax
// 165: 85 c0                         testl   %eax, %eax
// 167: 78 21                         js      0x18a <_JIT_ENTRY+0x18a>
// 169: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000016b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 173: ff d0                         callq   *%rax
// 175: 49 ff 0c 24                   decq    (%r12)
// 179: 75 0f                         jne     0x18a <_JIT_ENTRY+0x18a>
// 17b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000017d:  R_X86_64_64  _Py_Dealloc
// 185: 4c 89 e7                      movq    %r12, %rdi
// 188: ff d0                         callq   *%rax
// 18a: 85 ed                         testl   %ebp, %ebp
// 18c: 0f 85 57 ff ff ff             jne     0xe9 <_JIT_ENTRY+0xe9>
// 192: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000194:  R_X86_64_64  _JIT_CONTINUE
// 19c: 4c 89 f7                      movq    %r14, %rdi
// 19f: 48 89 de                      movq    %rbx, %rsi
// 1a2: 4c 89 fa                      movq    %r15, %rdx
// 1a5: 48 83 c4 08                   addq    $0x8, %rsp
// 1a9: 5b                            popq    %rbx
// 1aa: 41 5c                         popq    %r12
// 1ac: 41 5d                         popq    %r13
// 1ae: 41 5e                         popq    %r14
// 1b0: 41 5f                         popq    %r15
// 1b2: 5d                            popq    %rbp
// 1b3: ff e0                         jmpq    *%rax
// 1b5: 
static const unsigned char _PUSH_NULLplus_SETUP_ANNOTATIONS_code_body[438] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc3, 0x08, 0x48, 0x8b, 0x7f, 0x28, 0x48, 0x85, 0xff, 0x0f, 0x84, 0x95, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x81, 0xc5, 0xa8, 0xa7, 0x00, 0x00, 0x48, 0x89, 0xe2, 0x4c, 0x89, 0xee, 0xff, 0xd0, 0x85, 0xc0, 0x0f, 0x88, 0x92, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x24, 0x24, 0x4d, 0x85, 0xe4, 0x0f, 0x84, 0xa5, 0x00, 0x00, 0x00, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x96, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x0f, 0x88, 0xfb, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x0f, 0x85, 0xe5, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0xe9, 0xd1, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x31, 0xc0, 0xff, 0xd1, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0x89, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x74, 0xcb, 0x49, 0x8b, 0x7e, 0x28, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xee, 0x48, 0x89, 0xc2, 0xff, 0xd1, 0x89, 0xc5, 0x4c, 0x8b, 0x24, 0x24, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0x22, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x92, 0x05, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x85, 0xed, 0x0f, 0x85, 0x57, 0xff, 0xff, 0xff, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_SETUP_ANNOTATIONS_code_holes[17] = {
    {0x2e, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyMapping_GetOptionalItem, 0x0},
    {0x38, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyRuntime, 0x0},
    {0x6f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x79, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x99, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xaf, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xc3, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0xd0, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x39},
    {0xda, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0x10b, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_New, 0x0},
    {0x124, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_SetItem, 0x0},
    {0x145, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x14f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x16b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x17d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x194, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00no locals found when setting up annotations\x00'
// 65: 00 00 00
static const unsigned char _PUSH_NULLplus_SETUP_ANNOTATIONS_data_body[105] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x6e, 0x6f, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x73, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0x20, 0x77, 0x68, 0x65, 0x6e, 0x20, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x75, 0x70, 0x20, 0x61, 0x6e, 0x6e, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_SETUP_ANNOTATIONS_data_holes[1];

// _PUSH_NULLplus_SET_ADD
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SET_ADD.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  _JIT_OPARG
// 12: f7 d0                         notl    %eax
// 14: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 19: 48 98                         cltq
// 1b: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 20: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000022:  R_X86_64_64  PySet_Add
// 2a: 31 f6                         xorl    %esi, %esi
// 2c: ff d0                         callq   *%rax
// 2e: 
static const unsigned char _PUSH_NULLplus_SET_ADD_code_body[47] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_SET_ADD_code_holes[3] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &PySet_Add, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_SET_ADD_data_body[1];
static const Hole _PUSH_NULLplus_SET_ADD_data_holes[1];

// _PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000000e:  R_X86_64_64  _JIT_OPARG
// 16: 0f b7 c9                      movzwl  %cx, %ecx
// 19: 83 f9 03                      cmpl    $0x3, %ecx
// 1c: 7f 27                         jg      0x45 <_JIT_ENTRY+0x45>
// 1e: 83 f9 01                      cmpl    $0x1, %ecx
// 21: 74 49                         je      0x6c <_JIT_ENTRY+0x6c>
// 23: 83 f9 02                      cmpl    $0x2, %ecx
// 26: 75 7e                         jne     0xa6 <_JIT_ENTRY+0xa6>
// 28: 48 89 04 25 40 00 00 00       movq    %rax, 0x40
// 30: 48 c7 46 f8 00 00 00 00       movq    $0x0, -0x8(%rsi)
// 38: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003a:  R_X86_64_64  _JIT_CONTINUE
// 42: 59                            popq    %rcx
// 43: ff e0                         jmpq    *%rax
// 45: 83 f9 04                      cmpl    $0x4, %ecx
// 48: 74 3f                         je      0x89 <_JIT_ENTRY+0x89>
// 4a: 83 f9 08                      cmpl    $0x8, %ecx
// 4d: 75 57                         jne     0xa6 <_JIT_ENTRY+0xa6>
// 4f: 48 89 04 25 48 00 00 00       movq    %rax, 0x48
// 57: 48 c7 46 f8 00 00 00 00       movq    $0x0, -0x8(%rsi)
// 5f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000061:  R_X86_64_64  _JIT_CONTINUE
// 69: 59                            popq    %rcx
// 6a: ff e0                         jmpq    *%rax
// 6c: 48 89 04 25 38 00 00 00       movq    %rax, 0x38
// 74: 48 c7 46 f8 00 00 00 00       movq    $0x0, -0x8(%rsi)
// 7c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000007e:  R_X86_64_64  _JIT_CONTINUE
// 86: 59                            popq    %rcx
// 87: ff e0                         jmpq    *%rax
// 89: 48 89 04 25 70 00 00 00       movq    %rax, 0x70
// 91: 48 c7 46 f8 00 00 00 00       movq    $0x0, -0x8(%rsi)
// 99: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000009b:  R_X86_64_64  _JIT_CONTINUE
// a3: 59                            popq    %rcx
// a4: ff e0                         jmpq    *%rax
// a6: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000a8:  R_X86_64_64  .rodata.str1.1
// b0: 48 be 00 00 00 00 00 00 00 00 movabsq $0x0, %rsi
// 00000000000000b2:  R_X86_64_64  .rodata.str1.1+0xb
// ba: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000bc:  R_X86_64_64  _Py_FatalErrorFunc
// c4: ff d0                         callq   *%rax
// c6: 
static const unsigned char _PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE_code_body[199] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x83, 0xf9, 0x03, 0x7f, 0x27, 0x83, 0xf9, 0x01, 0x74, 0x49, 0x83, 0xf9, 0x02, 0x75, 0x7e, 0x48, 0x89, 0x04, 0x25, 0x40, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x46, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0xff, 0xe0, 0x83, 0xf9, 0x04, 0x74, 0x3f, 0x83, 0xf9, 0x08, 0x75, 0x57, 0x48, 0x89, 0x04, 0x25, 0x48, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x46, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0xff, 0xe0, 0x48, 0x89, 0x04, 0x25, 0x38, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x46, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0xff, 0xe0, 0x48, 0x89, 0x04, 0x25, 0x70, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x46, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0xff, 0xe0, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE_code_holes[9] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3a, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x61, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x7e, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x9b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0xa8, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xb2, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0xb},
    {0xbc, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_FatalErrorFunc, 0x0},
};
// 0: "_JIT_ENTRY\x00We've reached an unreachable state. Anything is possible.\nThe limits were in our heads all along. Follow your dreams.\nhttps://xkcd.com/2200\x00"
// 97: 00
static const unsigned char _PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE_data_body[153] = {0x5f, 0x4a, 0x49, 0x54, 0x5f, 0x45, 0x4e, 0x54, 0x52, 0x59, 0x00, 0x57, 0x65, 0x27, 0x76, 0x65, 0x20, 0x72, 0x65, 0x61, 0x63, 0x68, 0x65, 0x64, 0x20, 0x61, 0x6e, 0x20, 0x75, 0x6e, 0x72, 0x65, 0x61, 0x63, 0x68, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x73, 0x74, 0x61, 0x74, 0x65, 0x2e, 0x20, 0x41, 0x6e, 0x79, 0x74, 0x68, 0x69, 0x6e, 0x67, 0x20, 0x69, 0x73, 0x20, 0x70, 0x6f, 0x73, 0x73, 0x69, 0x62, 0x6c, 0x65, 0x2e, 0x0a, 0x54, 0x68, 0x65, 0x20, 0x6c, 0x69, 0x6d, 0x69, 0x74, 0x73, 0x20, 0x77, 0x65, 0x72, 0x65, 0x20, 0x69, 0x6e, 0x20, 0x6f, 0x75, 0x72, 0x20, 0x68, 0x65, 0x61, 0x64, 0x73, 0x20, 0x61, 0x6c, 0x6c, 0x20, 0x61, 0x6c, 0x6f, 0x6e, 0x67, 0x2e, 0x20, 0x46, 0x6f, 0x6c, 0x6c, 0x6f, 0x77, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x64, 0x72, 0x65, 0x61, 0x6d, 0x73, 0x2e, 0x0a, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x78, 0x6b, 0x63, 0x64, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x32, 0x32, 0x30, 0x30, 0x00, 0x00};
static const Hole _PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE_data_holes[1];

// _PUSH_NULLplus_SET_IP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SET_IP.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 8b 07                      movq    (%rdi), %rax
// a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000000c:  R_X86_64_64  _JIT_OPARG
// 14: 0f b7 c9                      movzwl  %cx, %ecx
// 17: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 1b: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 21: 48 89 47 38                   movq    %rax, 0x38(%rdi)
// 25: 48 83 c6 08                   addq    $0x8, %rsi
// 29: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002b:  R_X86_64_64  _JIT_CONTINUE
// 33: ff e0                         jmpq    *%rax
// 35: 
static const unsigned char _PUSH_NULLplus_SET_IP_code_body[54] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x89, 0x47, 0x38, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_SET_IP_code_holes[3] = {
    {0xc, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2b, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_SET_IP_data_body[1];
static const Hole _PUSH_NULLplus_SET_IP_data_holes[1];

// _PUSH_NULLplus_SET_UPDATE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SET_UPDATE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  _JIT_OPARG
// 12: f7 d0                         notl    %eax
// 14: 0d 00 00 ff ff                orl     $0xffff0000, %eax       # imm = 0xFFFF0000
// 19: 48 98                         cltq
// 1b: 48 8b 7c c6 08                movq    0x8(%rsi,%rax,8), %rdi
// 20: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000022:  R_X86_64_64  _PySet_Update
// 2a: 31 f6                         xorl    %esi, %esi
// 2c: ff d0                         callq   *%rax
// 2e: 
static const unsigned char _PUSH_NULLplus_SET_UPDATE_code_body[47] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xd0, 0x0d, 0x00, 0x00, 0xff, 0xff, 0x48, 0x98, 0x48, 0x8b, 0x7c, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_SET_UPDATE_code_holes[3] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PySet_Update, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_SET_UPDATE_data_body[1];
static const Hole _PUSH_NULLplus_SET_UPDATE_data_holes[1];

// _PUSH_NULLplus_STORE_ATTR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_ATTR.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// c: 48 8b 07                      movq    (%rdi), %rax
// f: 48 8b 40 20                   movq    0x20(%rax), %rax
// 13: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000015:  R_X86_64_64  _JIT_OPARG
// 1d: 0f b7 c9                      movzwl  %cx, %ecx
// 20: 48 8b 74 c8 18                movq    0x18(%rax,%rcx,8), %rsi
// 25: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000027:  R_X86_64_64  PyObject_SetAttr
// 2f: 31 ff                         xorl    %edi, %edi
// 31: 48 89 da                      movq    %rbx, %rdx
// 34: ff d0                         callq   *%rax
// 36: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 3a: 7f 1e                         jg      0x5a <_JIT_ENTRY+0x5a>
// 3c: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000003e:  R_X86_64_64  .rodata.str1.1
// 46: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000048:  R_X86_64_64  _Py_NegativeRefcount
// 50: be c5 03 00 00                movl    $0x3c5, %esi            # imm = 0x3C5
// 55: 48 89 da                      movq    %rbx, %rdx
// 58: ff d0                         callq   *%rax
// 5a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005c:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 64: ff d0                         callq   *%rax
// 66: 48 ff 0b                      decq    (%rbx)
// 69: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006b:  R_X86_64_64  _Py_Dealloc
// 73: 48 89 df                      movq    %rbx, %rdi
// 76: ff d0                         callq   *%rax
// 78: 
static const unsigned char _PUSH_NULLplus_STORE_ATTR_code_body[121] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x74, 0xc8, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xc5, 0x03, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_ATTR_code_holes[7] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_SetAttr, 0x0},
    {0x3e, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x48, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x5c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x6b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_ATTR_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_ATTR_data_holes[1];

// _PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// c: 48 8b 0c 25 e8 ff ff ff       movq    -0x18, %rcx
// 14: 48 ba 00 00 00 00 00 00 00 00 movabsq $0x0, %rdx
// 0000000000000016:  R_X86_64_64  _JIT_OPERAND
// 1e: 0f b7 d2                      movzwl  %dx, %edx
// 21: 48 8b 5c d1 01                movq    0x1(%rcx,%rdx,8), %rbx
// 26: 48 89 44 d1 01                movq    %rax, 0x1(%rcx,%rdx,8)
// 2b: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 2f: 7f 1e                         jg      0x4f <_JIT_ENTRY+0x4f>
// 31: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000033:  R_X86_64_64  .rodata.str1.1
// 3b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003d:  R_X86_64_64  _Py_NegativeRefcount
// 45: be 16 07 00 00                movl    $0x716, %esi            # imm = 0x716
// 4a: 48 89 da                      movq    %rbx, %rdx
// 4d: ff d0                         callq   *%rax
// 4f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000051:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 59: ff d0                         callq   *%rax
// 5b: 48 ff 0b                      decq    (%rbx)
// 5e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000060:  R_X86_64_64  _Py_Dealloc
// 68: 48 89 df                      movq    %rbx, %rdi
// 6b: ff d0                         callq   *%rax
// 6d: 
static const unsigned char _PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE_code_body[110] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0x8b, 0x0c, 0x25, 0xe8, 0xff, 0xff, 0xff, 0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xd2, 0x48, 0x8b, 0x5c, 0xd1, 0x01, 0x48, 0x89, 0x44, 0xd1, 0x01, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x16, 0x07, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE_code_holes[6] = {
    {0x16, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x33, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x3d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x51, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x60, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE_data_holes[1];

// _PUSH_NULLplus_STORE_ATTR_SLOT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_ATTR_SLOT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// c: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000000e:  R_X86_64_64  _JIT_OPERAND
// 16: 0f b7 c9                      movzwl  %cx, %ecx
// 19: 48 8b 19                      movq    (%rcx), %rbx
// 1c: 48 89 01                      movq    %rax, (%rcx)
// 1f: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 23: 7f 1e                         jg      0x43 <_JIT_ENTRY+0x43>
// 25: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000027:  R_X86_64_64  .rodata.str1.1
// 2f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000031:  R_X86_64_64  _Py_NegativeRefcount
// 39: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// 3e: 48 89 da                      movq    %rbx, %rdx
// 41: ff d0                         callq   *%rax
// 43: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000045:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 4d: ff d0                         callq   *%rax
// 4f: 48 ff 0b                      decq    (%rbx)
// 52: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000054:  R_X86_64_64  _Py_Dealloc
// 5c: 48 89 df                      movq    %rbx, %rdi
// 5f: ff d0                         callq   *%rax
// 61: 
static const unsigned char _PUSH_NULLplus_STORE_ATTR_SLOT_code_body[98] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x19, 0x48, 0x89, 0x01, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_ATTR_SLOT_code_holes[6] = {
    {0xe, HoleKind_R_X86_64_64, HoleValue_OPERAND, NULL, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x31, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x45, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x54, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Include/object.h\x00'
// 30: 
static const unsigned char _PUSH_NULLplus_STORE_ATTR_SLOT_data_body[49] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00};
static const Hole _PUSH_NULLplus_STORE_ATTR_SLOT_data_holes[1];

// _PUSH_NULLplus_STORE_DEREF
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_DEREF.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 48 8b 44 c7 48                movq    0x48(%rdi,%rax,8), %rax
// 2a: 4c 8b 60 10                   movq    0x10(%rax), %r12
// 2e: 48 c7 40 10 00 00 00 00       movq    $0x0, 0x10(%rax)
// 36: 4d 85 e4                      testq   %r12, %r12
// 39: 74 56                         je      0x91 <_JIT_ENTRY+0x91>
// 3b: 49 8b 04 24                   movq    (%r12), %rax
// 3f: 48 85 c0                      testq   %rax, %rax
// 42: 7e 06                         jle     0x4a <_JIT_ENTRY+0x4a>
// 44: 85 c0                         testl   %eax, %eax
// 46: 79 28                         jns     0x70 <_JIT_ENTRY+0x70>
// 48: eb 47                         jmp     0x91 <_JIT_ENTRY+0x91>
// 4a: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000004c:  R_X86_64_64  .rodata.str1.1
// 54: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000056:  R_X86_64_64  _Py_NegativeRefcount
// 5e: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// 63: 4c 89 e2                      movq    %r12, %rdx
// 66: ff d0                         callq   *%rax
// 68: 49 8b 04 24                   movq    (%r12), %rax
// 6c: 85 c0                         testl   %eax, %eax
// 6e: 78 21                         js      0x91 <_JIT_ENTRY+0x91>
// 70: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000072:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 7a: ff d0                         callq   *%rax
// 7c: 49 ff 0c 24                   decq    (%r12)
// 80: 75 0f                         jne     0x91 <_JIT_ENTRY+0x91>
// 82: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000084:  R_X86_64_64  _Py_Dealloc
// 8c: 4c 89 e7                      movq    %r12, %rdi
// 8f: ff d0                         callq   *%rax
// 91: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000093:  R_X86_64_64  _JIT_CONTINUE
// 9b: 4c 89 ff                      movq    %r15, %rdi
// 9e: 4c 89 f6                      movq    %r14, %rsi
// a1: 48 89 da                      movq    %rbx, %rdx
// a4: 48 83 c4 08                   addq    $0x8, %rsp
// a8: 5b                            popq    %rbx
// a9: 41 5c                         popq    %r12
// ab: 41 5e                         popq    %r14
// ad: 41 5f                         popq    %r15
// af: ff e0                         jmpq    *%rax
// b1: 
static const unsigned char _PUSH_NULLplus_STORE_DEREF_code_body[178] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x8b, 0x44, 0xc7, 0x48, 0x4c, 0x8b, 0x60, 0x10, 0x48, 0xc7, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x85, 0xe4, 0x74, 0x56, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_STORE_DEREF_code_holes[7] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x56, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x72, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x84, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x93, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Include/object.h\x00'
// 30: 
static const unsigned char _PUSH_NULLplus_STORE_DEREF_data_body[49] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00};
static const Hole _PUSH_NULLplus_STORE_DEREF_data_holes[1];

// _PUSH_NULLplus_STORE_FAST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_FAST.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 d3                      movq    %rdx, %rbx
// b: 49 89 f6                      movq    %rsi, %r14
// e: 49 89 ff                      movq    %rdi, %r15
// 11: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 18: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001a:  R_X86_64_64  _JIT_OPARG
// 22: 0f b7 c0                      movzwl  %ax, %eax
// 25: 4c 8b 64 c7 48                movq    0x48(%rdi,%rax,8), %r12
// 2a: 48 c7 44 c7 48 00 00 00 00    movq    $0x0, 0x48(%rdi,%rax,8)
// 33: 4d 85 e4                      testq   %r12, %r12
// 36: 74 56                         je      0x8e <_JIT_ENTRY+0x8e>
// 38: 49 8b 04 24                   movq    (%r12), %rax
// 3c: 48 85 c0                      testq   %rax, %rax
// 3f: 7e 06                         jle     0x47 <_JIT_ENTRY+0x47>
// 41: 85 c0                         testl   %eax, %eax
// 43: 79 28                         jns     0x6d <_JIT_ENTRY+0x6d>
// 45: eb 47                         jmp     0x8e <_JIT_ENTRY+0x8e>
// 47: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000049:  R_X86_64_64  .rodata.str1.1
// 51: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000053:  R_X86_64_64  _Py_NegativeRefcount
// 5b: be ff 03 00 00                movl    $0x3ff, %esi            # imm = 0x3FF
// 60: 4c 89 e2                      movq    %r12, %rdx
// 63: ff d0                         callq   *%rax
// 65: 49 8b 04 24                   movq    (%r12), %rax
// 69: 85 c0                         testl   %eax, %eax
// 6b: 78 21                         js      0x8e <_JIT_ENTRY+0x8e>
// 6d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006f:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 77: ff d0                         callq   *%rax
// 79: 49 ff 0c 24                   decq    (%r12)
// 7d: 75 0f                         jne     0x8e <_JIT_ENTRY+0x8e>
// 7f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000081:  R_X86_64_64  _Py_Dealloc
// 89: 4c 89 e7                      movq    %r12, %rdi
// 8c: ff d0                         callq   *%rax
// 8e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000090:  R_X86_64_64  _JIT_CONTINUE
// 98: 4c 89 ff                      movq    %r15, %rdi
// 9b: 4c 89 f6                      movq    %r14, %rsi
// 9e: 48 89 da                      movq    %rbx, %rdx
// a1: 48 83 c4 08                   addq    $0x8, %rsp
// a5: 5b                            popq    %rbx
// a6: 41 5c                         popq    %r12
// a8: 41 5e                         popq    %r14
// aa: 41 5f                         popq    %r15
// ac: ff e0                         jmpq    *%rax
// ae: 
static const unsigned char _PUSH_NULLplus_STORE_FAST_code_body[175] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xd3, 0x49, 0x89, 0xf6, 0x49, 0x89, 0xff, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x4c, 0x8b, 0x64, 0xc7, 0x48, 0x48, 0xc7, 0x44, 0xc7, 0x48, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x85, 0xe4, 0x74, 0x56, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xff, 0x03, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xff, 0x4c, 0x89, 0xf6, 0x48, 0x89, 0xda, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_STORE_FAST_code_holes[7] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x49, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x53, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x6f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x81, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x90, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Include/object.h\x00'
// 30: 
static const unsigned char _PUSH_NULLplus_STORE_FAST_data_body[49] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x2f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x2e, 0x68, 0x00};
static const Hole _PUSH_NULLplus_STORE_FAST_data_holes[1];

// _PUSH_NULLplus_STORE_GLOBAL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_GLOBAL.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 07                      movq    (%rdi), %rax
// b: 48 8b 7f 18                   movq    0x18(%rdi), %rdi
// f: 48 8b 40 20                   movq    0x20(%rax), %rax
// 13: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000015:  R_X86_64_64  _JIT_OPARG
// 1d: 0f b7 c9                      movzwl  %cx, %ecx
// 20: 48 8b 74 c8 18                movq    0x18(%rax,%rcx,8), %rsi
// 25: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000027:  R_X86_64_64  PyDict_SetItem
// 2f: 31 d2                         xorl    %edx, %edx
// 31: ff d0                         callq   *%rax
// 33: 
static const unsigned char _PUSH_NULLplus_STORE_GLOBAL_code_body[52] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x7f, 0x18, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x74, 0xc8, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xd2, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_GLOBAL_code_holes[3] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x27, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_SetItem, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_STORE_GLOBAL_data_body[1];
static const Hole _PUSH_NULLplus_STORE_GLOBAL_data_holes[1];

// _PUSH_NULLplus_STORE_NAME
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_NAME.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 8b 07                      movq    (%rdi), %rax
// b: 48 8b 7f 28                   movq    0x28(%rdi), %rdi
// f: 48 8b 40 20                   movq    0x20(%rax), %rax
// 13: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000015:  R_X86_64_64  _JIT_OPARG
// 1d: 0f b7 c9                      movzwl  %cx, %ecx
// 20: 48 8b 4c c8 18                movq    0x18(%rax,%rcx,8), %rcx
// 25: 48 85 ff                      testq   %rdi, %rdi
// 28: 74 21                         je      0x4b <_JIT_ENTRY+0x4b>
// 2a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002c:  R_X86_64_64  PyDict_Type
// 34: 48 39 47 08                   cmpq    %rax, 0x8(%rdi)
// 38: 74 3d                         je      0x77 <_JIT_ENTRY+0x77>
// 3a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003c:  R_X86_64_64  PyObject_SetItem
// 44: 48 89 ce                      movq    %rcx, %rsi
// 47: 31 d2                         xorl    %edx, %edx
// 49: ff d0                         callq   *%rax
// 4b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000004d:  R_X86_64_64  PyExc_SystemError
// 55: 48 8b 30                      movq    (%rax), %rsi
// 58: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000005a:  R_X86_64_64  .rodata.str1.1
// 62: 49 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %r8
// 0000000000000064:  R_X86_64_64  _PyErr_Format
// 6c: 48 89 d7                      movq    %rdx, %rdi
// 6f: 48 89 c2                      movq    %rax, %rdx
// 72: 31 c0                         xorl    %eax, %eax
// 74: 41 ff d0                      callq   *%r8
// 77: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000079:  R_X86_64_64  PyDict_SetItem
// 81: 48 89 ce                      movq    %rcx, %rsi
// 84: 31 d2                         xorl    %edx, %edx
// 86: ff d0                         callq   *%rax
// 88: 
static const unsigned char _PUSH_NULLplus_STORE_NAME_code_body[137] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x07, 0x48, 0x8b, 0x7f, 0x28, 0x48, 0x8b, 0x40, 0x20, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc9, 0x48, 0x8b, 0x4c, 0xc8, 0x18, 0x48, 0x85, 0xff, 0x74, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x47, 0x08, 0x74, 0x3d, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xce, 0x31, 0xd2, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x30, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xd7, 0x48, 0x89, 0xc2, 0x31, 0xc0, 0x41, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xce, 0x31, 0xd2, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_NAME_code_holes[8] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x2c, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x3c, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_SetItem, 0x0},
    {0x4d, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyExc_SystemError, 0x0},
    {0x5a, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x64, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyErr_Format, 0x0},
    {0x79, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_SetItem, 0x0},
};
// 0: 'no locals found when storing %R\x00'
// 20: 
static const unsigned char _PUSH_NULLplus_STORE_NAME_data_body[33] = {0x6e, 0x6f, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x73, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0x20, 0x77, 0x68, 0x65, 0x6e, 0x20, 0x73, 0x74, 0x6f, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x25, 0x52, 0x00};
static const Hole _PUSH_NULLplus_STORE_NAME_data_holes[1];

// _PUSH_NULLplus_STORE_SLICE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_SLICE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 14 24                   movq    %rdx, (%rsp)
// f: 49 89 f7                      movq    %rsi, %r15
// 12: 49 89 fe                      movq    %rdi, %r14
// 15: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1c: 48 8b 7e f8                   movq    -0x8(%rsi), %rdi
// 20: 4c 8b 6e e8                   movq    -0x18(%rsi), %r13
// 24: 4c 8b 66 f0                   movq    -0x10(%rsi), %r12
// 28: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002a:  R_X86_64_64  _PyBuildSlice_ConsumeRefs
// 32: 31 db                         xorl    %ebx, %ebx
// 34: 31 f6                         xorl    %esi, %esi
// 36: ff d0                         callq   *%rax
// 38: 48 85 c0                      testq   %rax, %rax
// 3b: 74 75                         je      0xb2 <_JIT_ENTRY+0xb2>
// 3d: 48 89 c5                      movq    %rax, %rbp
// 40: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000042:  R_X86_64_64  PyObject_SetItem
// 4a: 4c 89 e7                      movq    %r12, %rdi
// 4d: 48 89 ee                      movq    %rbp, %rsi
// 50: 4c 89 ea                      movq    %r13, %rdx
// 53: ff d0                         callq   *%rax
// 55: 89 c3                         movl    %eax, %ebx
// 57: 48 8b 45 00                   movq    (%rbp), %rax
// 5b: 48 85 c0                      testq   %rax, %rax
// 5e: 7e 06                         jle     0x66 <_JIT_ENTRY+0x66>
// 60: 85 c0                         testl   %eax, %eax
// 62: 79 28                         jns     0x8c <_JIT_ENTRY+0x8c>
// 64: eb 47                         jmp     0xad <_JIT_ENTRY+0xad>
// 66: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000068:  R_X86_64_64  .rodata.str1.1
// 70: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000072:  R_X86_64_64  _Py_NegativeRefcount
// 7a: be b2 01 00 00                movl    $0x1b2, %esi            # imm = 0x1B2
// 7f: 48 89 ea                      movq    %rbp, %rdx
// 82: ff d0                         callq   *%rax
// 84: 48 8b 45 00                   movq    (%rbp), %rax
// 88: 85 c0                         testl   %eax, %eax
// 8a: 78 21                         js      0xad <_JIT_ENTRY+0xad>
// 8c: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000008e:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 96: ff d0                         callq   *%rax
// 98: 48 ff 4d 00                   decq    (%rbp)
// 9c: 75 0f                         jne     0xad <_JIT_ENTRY+0xad>
// 9e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a0:  R_X86_64_64  _Py_Dealloc
// a8: 48 89 ef                      movq    %rbp, %rdi
// ab: ff d0                         callq   *%rax
// ad: 85 db                         testl   %ebx, %ebx
// af: 0f 94 c3                      sete    %bl
// b2: 4c 89 f5                      movq    %r14, %rbp
// b5: 49 8b 45 00                   movq    (%r13), %rax
// b9: 48 85 c0                      testq   %rax, %rax
// bc: 7e 06                         jle     0xc4 <_JIT_ENTRY+0xc4>
// be: 85 c0                         testl   %eax, %eax
// c0: 79 28                         jns     0xea <_JIT_ENTRY+0xea>
// c2: eb 38                         jmp     0xfc <_JIT_ENTRY+0xfc>
// c4: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000c6:  R_X86_64_64  .rodata.str1.1
// ce: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000d0:  R_X86_64_64  _Py_NegativeRefcount
// d8: be b4 01 00 00                movl    $0x1b4, %esi            # imm = 0x1B4
// dd: 4c 89 ea                      movq    %r13, %rdx
// e0: ff d0                         callq   *%rax
// e2: 49 8b 45 00                   movq    (%r13), %rax
// e6: 85 c0                         testl   %eax, %eax
// e8: 78 12                         js      0xfc <_JIT_ENTRY+0xfc>
// ea: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ec:  R_X86_64_64  _Py_DECREF_DecRefTotal
// f4: ff d0                         callq   *%rax
// f6: 49 ff 4d 00                   decq    (%r13)
// fa: 74 17                         je      0x113 <_JIT_ENTRY+0x113>
// fc: 49 8b 04 24                   movq    (%r12), %rax
// 100: 48 85 c0                      testq   %rax, %rax
// 103: 7e 26                         jle     0x12b <_JIT_ENTRY+0x12b>
// 105: 4d 8d 77 08                   leaq    0x8(%r15), %r14
// 109: 49 83 c7 e8                   addq    $-0x18, %r15
// 10d: 85 c0                         testl   %eax, %eax
// 10f: 79 48                         jns     0x159 <_JIT_ENTRY+0x159>
// 111: eb 58                         jmp     0x16b <_JIT_ENTRY+0x16b>
// 113: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000115:  R_X86_64_64  _Py_Dealloc
// 11d: 4c 89 ef                      movq    %r13, %rdi
// 120: ff d0                         callq   *%rax
// 122: 49 8b 04 24                   movq    (%r12), %rax
// 126: 48 85 c0                      testq   %rax, %rax
// 129: 7f da                         jg      0x105 <_JIT_ENTRY+0x105>
// 12b: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000012d:  R_X86_64_64  .rodata.str1.1
// 135: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000137:  R_X86_64_64  _Py_NegativeRefcount
// 13f: be b5 01 00 00                movl    $0x1b5, %esi            # imm = 0x1B5
// 144: 4c 89 e2                      movq    %r12, %rdx
// 147: ff d0                         callq   *%rax
// 149: 49 8b 04 24                   movq    (%r12), %rax
// 14d: 4d 8d 77 08                   leaq    0x8(%r15), %r14
// 151: 49 83 c7 e8                   addq    $-0x18, %r15
// 155: 85 c0                         testl   %eax, %eax
// 157: 78 12                         js      0x16b <_JIT_ENTRY+0x16b>
// 159: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000015b:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 163: ff d0                         callq   *%rax
// 165: 49 ff 0c 24                   decq    (%r12)
// 169: 74 2c                         je      0x197 <_JIT_ENTRY+0x197>
// 16b: 84 db                         testb   %bl, %bl
// 16d: 4d 0f 45 f7                   cmovneq %r15, %r14
// 171: 74 3b                         je      0x1ae <_JIT_ENTRY+0x1ae>
// 173: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000175:  R_X86_64_64  _JIT_CONTINUE
// 17d: 48 89 ef                      movq    %rbp, %rdi
// 180: 4c 89 f6                      movq    %r14, %rsi
// 183: 48 8b 14 24                   movq    (%rsp), %rdx
// 187: 48 83 c4 08                   addq    $0x8, %rsp
// 18b: 5b                            popq    %rbx
// 18c: 41 5c                         popq    %r12
// 18e: 41 5d                         popq    %r13
// 190: 41 5e                         popq    %r14
// 192: 41 5f                         popq    %r15
// 194: 5d                            popq    %rbp
// 195: ff e0                         jmpq    *%rax
// 197: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000199:  R_X86_64_64  _Py_Dealloc
// 1a1: 4c 89 e7                      movq    %r12, %rdi
// 1a4: ff d0                         callq   *%rax
// 1a6: 84 db                         testb   %bl, %bl
// 1a8: 4d 0f 45 f7                   cmovneq %r15, %r14
// 1ac: 75 c5                         jne     0x173 <_JIT_ENTRY+0x173>
// 1ae: 49 29 ee                      subq    %rbp, %r14
// 1b1: 49 83 c6 98                   addq    $-0x68, %r14
// 1b5: 49 c1 ee 03                   shrq    $0x3, %r14
// 1b9: 44 89 75 40                   movl    %r14d, 0x40(%rbp)
// 1bd: 31 c0                         xorl    %eax, %eax
// 1bf: 48 83 c4 08                   addq    $0x8, %rsp
// 1c3: 5b                            popq    %rbx
// 1c4: 41 5c                         popq    %r12
// 1c6: 41 5d                         popq    %r13
// 1c8: 41 5e                         popq    %r14
// 1ca: 41 5f                         popq    %r15
// 1cc: 5d                            popq    %rbp
// 1cd: c3                            retq
// 1ce: 
static const unsigned char _PUSH_NULLplus_STORE_SLICE_code_body[463] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0x14, 0x24, 0x49, 0x89, 0xf7, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x7e, 0xf8, 0x4c, 0x8b, 0x6e, 0xe8, 0x4c, 0x8b, 0x66, 0xf0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xdb, 0x31, 0xf6, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x75, 0x48, 0x89, 0xc5, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0x48, 0x89, 0xee, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x89, 0xc3, 0x48, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xb2, 0x01, 0x00, 0x00, 0x48, 0x89, 0xea, 0xff, 0xd0, 0x48, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0xff, 0xd0, 0x85, 0xdb, 0x0f, 0x94, 0xc3, 0x4c, 0x89, 0xf5, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x38, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xb4, 0x01, 0x00, 0x00, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x74, 0x17, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7e, 0x26, 0x4d, 0x8d, 0x77, 0x08, 0x49, 0x83, 0xc7, 0xe8, 0x85, 0xc0, 0x79, 0x48, 0xeb, 0x58, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x48, 0x85, 0xc0, 0x7f, 0xda, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xb5, 0x01, 0x00, 0x00, 0x4c, 0x89, 0xe2, 0xff, 0xd0, 0x49, 0x8b, 0x04, 0x24, 0x4d, 0x8d, 0x77, 0x08, 0x49, 0x83, 0xc7, 0xe8, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x0c, 0x24, 0x74, 0x2c, 0x84, 0xdb, 0x4d, 0x0f, 0x45, 0xf7, 0x74, 0x3b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xef, 0x4c, 0x89, 0xf6, 0x48, 0x8b, 0x14, 0x24, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xe7, 0xff, 0xd0, 0x84, 0xdb, 0x4d, 0x0f, 0x45, 0xf7, 0x75, 0xc5, 0x49, 0x29, 0xee, 0x49, 0x83, 0xc6, 0x98, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x75, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_STORE_SLICE_code_holes[16] = {
    {0x2a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyBuildSlice_ConsumeRefs, 0x0},
    {0x42, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_SetItem, 0x0},
    {0x68, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x72, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x8e, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xa0, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xc6, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xd0, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xec, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x115, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x12d, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x137, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x15b, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x175, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
    {0x199, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_SLICE_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_SLICE_data_holes[1];

// _PUSH_NULLplus_STORE_SUBSCR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_SUBSCR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// f: 4c 8b 76 f0                   movq    -0x10(%rsi), %r14
// 13: 48 8b 5e f8                   movq    -0x8(%rsi), %rbx
// 17: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000019:  R_X86_64_64  PyObject_SetItem
// 21: 48 89 df                      movq    %rbx, %rdi
// 24: 31 f6                         xorl    %esi, %esi
// 26: 4c 89 f2                      movq    %r14, %rdx
// 29: ff d0                         callq   *%rax
// 2b: 49 8b 06                      movq    (%r14), %rax
// 2e: 48 85 c0                      testq   %rax, %rax
// 31: 7e 1a                         jle     0x4d <_JIT_ENTRY+0x4d>
// 33: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 0000000000000035:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 3d: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000003f:  R_X86_64_64  _Py_Dealloc
// 47: 85 c0                         testl   %eax, %eax
// 49: 79 3b                         jns     0x86 <_JIT_ENTRY+0x86>
// 4b: eb 41                         jmp     0x8e <_JIT_ENTRY+0x8e>
// 4d: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000004f:  R_X86_64_64  .rodata.str1.1
// 57: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000059:  R_X86_64_64  _Py_NegativeRefcount
// 61: be 38 02 00 00                movl    $0x238, %esi            # imm = 0x238
// 66: 4c 89 f2                      movq    %r14, %rdx
// 69: ff d0                         callq   *%rax
// 6b: 49 8b 06                      movq    (%r14), %rax
// 6e: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 0000000000000070:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 78: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000007a:  R_X86_64_64  _Py_Dealloc
// 82: 85 c0                         testl   %eax, %eax
// 84: 78 08                         js      0x8e <_JIT_ENTRY+0x8e>
// 86: 41 ff d4                      callq   *%r12
// 89: 49 ff 0e                      decq    (%r14)
// 8c: 74 12                         je      0xa0 <_JIT_ENTRY+0xa0>
// 8e: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 92: 7e 18                         jle     0xac <_JIT_ENTRY+0xac>
// 94: 41 ff d4                      callq   *%r12
// 97: 48 ff 0b                      decq    (%rbx)
// 9a: 48 89 df                      movq    %rbx, %rdi
// 9d: 41 ff d7                      callq   *%r15
// a0: 4c 89 f7                      movq    %r14, %rdi
// a3: 41 ff d7                      callq   *%r15
// a6: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// aa: 7f e8                         jg      0x94 <_JIT_ENTRY+0x94>
// ac: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 00000000000000ae:  R_X86_64_64  .rodata.str1.1
// b6: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b8:  R_X86_64_64  _Py_NegativeRefcount
// c0: be 39 02 00 00                movl    $0x239, %esi            # imm = 0x239
// c5: 48 89 da                      movq    %rbx, %rdx
// c8: ff d0                         callq   *%rax
// ca: 41 ff d4                      callq   *%r12
// cd: 48 ff 0b                      decq    (%rbx)
// d0: 48 89 df                      movq    %rbx, %rdi
// d3: 41 ff d7                      callq   *%r15
// d6: 
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_code_body[215] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x76, 0xf0, 0x48, 0x8b, 0x5e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x31, 0xf6, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x48, 0x85, 0xc0, 0x7e, 0x1a, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x79, 0x3b, 0xeb, 0x41, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x38, 0x02, 0x00, 0x00, 0x4c, 0x89, 0xf2, 0xff, 0xd0, 0x49, 0x8b, 0x06, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xc0, 0x78, 0x08, 0x41, 0xff, 0xd4, 0x49, 0xff, 0x0e, 0x74, 0x12, 0x48, 0x83, 0x3b, 0x00, 0x7e, 0x18, 0x41, 0xff, 0xd4, 0x48, 0xff, 0x0b, 0x48, 0x89, 0xdf, 0x41, 0xff, 0xd7, 0x4c, 0x89, 0xf7, 0x41, 0xff, 0xd7, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0xe8, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x39, 0x02, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x41, 0xff, 0xd4, 0x48, 0xff, 0x0b, 0x48, 0x89, 0xdf, 0x41, 0xff, 0xd7};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_code_holes[10] = {
    {0x19, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_SetItem, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x4f, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x59, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x70, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x7a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xae, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0xb8, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_data_holes[1];

// _PUSH_NULLplus_STORE_SUBSCR_DICT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_SUBSCR_DICT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 50                            pushq   %rax
// b: 48 89 fb                      movq    %rdi, %rbx
// e: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 15: 4c 8d 76 08                   leaq    0x8(%rsi), %r14
// 19: 4c 8b 6e f8                   movq    -0x8(%rsi), %r13
// 1d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000001f:  R_X86_64_64  PyDict_Type
// 27: 49 39 45 08                   cmpq    %rax, 0x8(%r13)
// 2b: 74 2d                         je      0x5a <_JIT_ENTRY+0x5a>
// 2d: 49 29 de                      subq    %rbx, %r14
// 30: 49 83 c6 b8                   addq    $-0x48, %r14
// 34: 49 c1 ee 03                   shrq    $0x3, %r14
// 38: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// 3c: 48 8b 03                      movq    (%rbx), %rax
// 3f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000041:  R_X86_64_64  _JIT_TARGET
// 49: 89 c9                         movl    %ecx, %ecx
// 4b: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 4f: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 55: e9 81 00 00 00                jmp     0xdb <_JIT_ENTRY+0xdb>
// 5a: 49 89 d7                      movq    %rdx, %r15
// 5d: 49 89 f4                      movq    %rsi, %r12
// 60: 49 83 c4 f0                   addq    $-0x10, %r12
// 64: 49 8b 14 24                   movq    (%r12), %rdx
// 68: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000006a:  R_X86_64_64  _PyDict_SetItem_Take2
// 72: 4c 89 ef                      movq    %r13, %rdi
// 75: 31 f6                         xorl    %esi, %esi
// 77: ff d0                         callq   *%rax
// 79: 89 c5                         movl    %eax, %ebp
// 7b: 49 8b 45 00                   movq    (%r13), %rax
// 7f: 48 85 c0                      testq   %rax, %rax
// 82: 7e 06                         jle     0x8a <_JIT_ENTRY+0x8a>
// 84: 85 c0                         testl   %eax, %eax
// 86: 79 28                         jns     0xb0 <_JIT_ENTRY+0xb0>
// 88: eb 38                         jmp     0xc2 <_JIT_ENTRY+0xc2>
// 8a: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000008c:  R_X86_64_64  .rodata.str1.1
// 94: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000096:  R_X86_64_64  _Py_NegativeRefcount
// 9e: be 63 02 00 00                movl    $0x263, %esi            # imm = 0x263
// a3: 4c 89 ea                      movq    %r13, %rdx
// a6: ff d0                         callq   *%rax
// a8: 49 8b 45 00                   movq    (%r13), %rax
// ac: 85 c0                         testl   %eax, %eax
// ae: 78 12                         js      0xc2 <_JIT_ENTRY+0xc2>
// b0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b2:  R_X86_64_64  _Py_DECREF_DecRefTotal
// ba: ff d0                         callq   *%rax
// bc: 49 ff 4d 00                   decq    (%r13)
// c0: 74 28                         je      0xea <_JIT_ENTRY+0xea>
// c2: 85 ed                         testl   %ebp, %ebp
// c4: 4d 0f 44 f4                   cmoveq  %r12, %r14
// c8: 74 37                         je      0x101 <_JIT_ENTRY+0x101>
// ca: 49 29 de                      subq    %rbx, %r14
// cd: 49 83 c6 a0                   addq    $-0x60, %r14
// d1: 49 c1 ee 03                   shrq    $0x3, %r14
// d5: 44 89 73 40                   movl    %r14d, 0x40(%rbx)
// d9: 31 c0                         xorl    %eax, %eax
// db: 48 83 c4 08                   addq    $0x8, %rsp
// df: 5b                            popq    %rbx
// e0: 41 5c                         popq    %r12
// e2: 41 5d                         popq    %r13
// e4: 41 5e                         popq    %r14
// e6: 41 5f                         popq    %r15
// e8: 5d                            popq    %rbp
// e9: c3                            retq
// ea: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000ec:  R_X86_64_64  _Py_Dealloc
// f4: 4c 89 ef                      movq    %r13, %rdi
// f7: ff d0                         callq   *%rax
// f9: 85 ed                         testl   %ebp, %ebp
// fb: 4d 0f 44 f4                   cmoveq  %r12, %r14
// ff: 75 c9                         jne     0xca <_JIT_ENTRY+0xca>
// 101: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000103:  R_X86_64_64  _JIT_CONTINUE
// 10b: 48 89 df                      movq    %rbx, %rdi
// 10e: 4c 89 f6                      movq    %r14, %rsi
// 111: 4c 89 fa                      movq    %r15, %rdx
// 114: 48 83 c4 08                   addq    $0x8, %rsp
// 118: 5b                            popq    %rbx
// 119: 41 5c                         popq    %r12
// 11b: 41 5d                         popq    %r13
// 11d: 41 5e                         popq    %r14
// 11f: 41 5f                         popq    %r15
// 121: 5d                            popq    %rbp
// 122: ff e0                         jmpq    *%rax
// 124: 
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_DICT_code_body[293] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xfb, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x76, 0x08, 0x4c, 0x8b, 0x6e, 0xf8, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x39, 0x45, 0x08, 0x74, 0x2d, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xb8, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x48, 0x8b, 0x03, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xe9, 0x81, 0x00, 0x00, 0x00, 0x49, 0x89, 0xd7, 0x49, 0x89, 0xf4, 0x49, 0x83, 0xc4, 0xf0, 0x49, 0x8b, 0x14, 0x24, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0x31, 0xf6, 0xff, 0xd0, 0x89, 0xc5, 0x49, 0x8b, 0x45, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x06, 0x85, 0xc0, 0x79, 0x28, 0xeb, 0x38, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x63, 0x02, 0x00, 0x00, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x12, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x74, 0x28, 0x85, 0xed, 0x4d, 0x0f, 0x44, 0xf4, 0x74, 0x37, 0x49, 0x29, 0xde, 0x49, 0x83, 0xc6, 0xa0, 0x49, 0xc1, 0xee, 0x03, 0x44, 0x89, 0x73, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x85, 0xed, 0x4d, 0x0f, 0x44, 0xf4, 0x75, 0xc9, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0x4c, 0x89, 0xf6, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_DICT_code_holes[9] = {
    {0x1f, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyDict_Type, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x6a, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyDict_SetItem_Take2, 0x0},
    {0x8c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xb2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xec, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0x103, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_DICT_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_DICT_data_holes[1];

// _PUSH_NULLplus_STORE_SUBSCR_LIST_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_STORE_SUBSCR_LIST_INT.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 53                            pushq   %rbx
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyLong_Type
// 12: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1a: 75 2c                         jne     0x48 <_JIT_ENTRY+0x48>
// 1c: 48 8b 46 f8                   movq    -0x8(%rsi), %rax
// 20: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000022:  R_X86_64_64  PyList_Type
// 2a: 48 39 48 08                   cmpq    %rcx, 0x8(%rax)
// 2e: 75 18                         jne     0x48 <_JIT_ENTRY+0x48>
// 30: 48 83 3c 25 10 00 00 00 08    cmpq    $0x8, 0x10
// 39: 77 0d                         ja      0x48 <_JIT_ENTRY+0x48>
// 3b: 8b 0c 25 18 00 00 00          movl    0x18, %ecx
// 42: 48 39 48 10                   cmpq    %rcx, 0x10(%rax)
// 46: 7f 29                         jg      0x71 <_JIT_ENTRY+0x71>
// 48: 48 29 fe                      subq    %rdi, %rsi
// 4b: 48 83 c6 c0                   addq    $-0x40, %rsi
// 4f: 48 c1 ee 03                   shrq    $0x3, %rsi
// 53: 89 77 40                      movl    %esi, 0x40(%rdi)
// 56: 48 8b 07                      movq    (%rdi), %rax
// 59: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000005b:  R_X86_64_64  _JIT_TARGET
// 63: 89 c9                         movl    %ecx, %ecx
// 65: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 69: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 6f: 5b                            popq    %rbx
// 70: c3                            retq
// 71: 48 8b 56 f0                   movq    -0x10(%rsi), %rdx
// 75: 48 8b 40 18                   movq    0x18(%rax), %rax
// 79: 48 8b 1c c8                   movq    (%rax,%rcx,8), %rbx
// 7d: 48 89 14 c8                   movq    %rdx, (%rax,%rcx,8)
// 81: 48 83 3b 00                   cmpq    $0x0, (%rbx)
// 85: 7f 1e                         jg      0xa5 <_JIT_ENTRY+0xa5>
// 87: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 0000000000000089:  R_X86_64_64  .rodata.str1.1
// 91: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000093:  R_X86_64_64  _Py_NegativeRefcount
// 9b: be 52 02 00 00                movl    $0x252, %esi            # imm = 0x252
// a0: 48 89 da                      movq    %rbx, %rdx
// a3: ff d0                         callq   *%rax
// a5: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000a7:  R_X86_64_64  _Py_DECREF_DecRefTotal
// af: ff d0                         callq   *%rax
// b1: 48 ff 0b                      decq    (%rbx)
// b4: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000b6:  R_X86_64_64  _Py_Dealloc
// be: 48 89 df                      movq    %rbx, %rdi
// c1: ff d0                         callq   *%rax
// c3: 
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_LIST_INT_code_body[196] = {0x53, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x2c, 0x48, 0x8b, 0x46, 0xf8, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x08, 0x75, 0x18, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x08, 0x77, 0x0d, 0x8b, 0x0c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x48, 0x39, 0x48, 0x10, 0x7f, 0x29, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0xc3, 0x48, 0x8b, 0x56, 0xf0, 0x48, 0x8b, 0x40, 0x18, 0x48, 0x8b, 0x1c, 0xc8, 0x48, 0x89, 0x14, 0xc8, 0x48, 0x83, 0x3b, 0x00, 0x7f, 0x1e, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x52, 0x02, 0x00, 0x00, 0x48, 0x89, 0xda, 0xff, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x48, 0xff, 0x0b, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xdf, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_LIST_INT_code_holes[8] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x22, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyList_Type, 0x0},
    {0x5b, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x89, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x93, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0xa7, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0xb6, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_STORE_SUBSCR_LIST_INT_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_STORE_SUBSCR_LIST_INT_data_holes[1];

// _PUSH_NULLplus_SWAP
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_SWAP.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000009:  R_X86_64_64  _JIT_OPARG
// 11: 0f b7 c0                      movzwl  %ax, %eax
// 14: 48 c1 e0 03                   shlq    $0x3, %rax
// 18: 48 89 f1                      movq    %rsi, %rcx
// 1b: 48 29 c1                      subq    %rax, %rcx
// 1e: 48 f7 d8                      negq    %rax
// 21: 48 8b 49 08                   movq    0x8(%rcx), %rcx
// 25: 48 c7 44 06 08 00 00 00 00    movq    $0x0, 0x8(%rsi,%rax)
// 2e: 48 89 0e                      movq    %rcx, (%rsi)
// 31: 48 83 c6 08                   addq    $0x8, %rsi
// 35: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000037:  R_X86_64_64  _JIT_CONTINUE
// 3f: ff e0                         jmpq    *%rax
// 41: 
static const unsigned char _PUSH_NULLplus_SWAP_code_body[66] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0xc1, 0xe0, 0x03, 0x48, 0x89, 0xf1, 0x48, 0x29, 0xc1, 0x48, 0xf7, 0xd8, 0x48, 0x8b, 0x49, 0x08, 0x48, 0xc7, 0x44, 0x06, 0x08, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x0e, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_SWAP_code_holes[3] = {
    {0x9, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x37, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_SWAP_data_body[1];
static const Hole _PUSH_NULLplus_SWAP_data_holes[1];

// _PUSH_NULLplus_TO_BOOL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyObject_IsTrue
// 12: 31 ff                         xorl    %edi, %edi
// 14: ff d0                         callq   *%rax
// 16: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_code_body[23] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_TO_BOOL_code_holes[2] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_IsTrue, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_BOOL
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_BOOL.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 83 c6 08                   addq    $0x8, %rsi
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  PyBool_Type
// 15: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 1d: 74 28                         je      0x47 <_JIT_ENTRY+0x47>
// 1f: 48 29 fe                      subq    %rdi, %rsi
// 22: 48 83 c6 b8                   addq    $-0x48, %rsi
// 26: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2a: 89 77 40                      movl    %esi, 0x40(%rdi)
// 2d: 48 8b 07                      movq    (%rdi), %rax
// 30: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000032:  R_X86_64_64  _JIT_TARGET
// 3a: 89 c9                         movl    %ecx, %ecx
// 3c: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 40: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 46: c3                            retq
// 47: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000049:  R_X86_64_64  _JIT_CONTINUE
// 51: ff e0                         jmpq    *%rax
// 53: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_BOOL_code_body[84] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_TO_BOOL_BOOL_code_holes[4] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyBool_Type, 0x0},
    {0x32, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x49, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_BOOL_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_BOOL_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_INT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_INT.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 89 f0                      movq    %rsi, %rax
// 3: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// a: 48 83 c6 08                   addq    $0x8, %rsi
// e: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000010:  R_X86_64_64  PyLong_Type
// 18: 48 39 0c 25 08 00 00 00       cmpq    %rcx, 0x8
// 20: 74 28                         je      0x4a <_JIT_ENTRY+0x4a>
// 22: 48 29 fe                      subq    %rdi, %rsi
// 25: 48 83 c6 b8                   addq    $-0x48, %rsi
// 29: 48 c1 ee 03                   shrq    $0x3, %rsi
// 2d: 89 77 40                      movl    %esi, 0x40(%rdi)
// 30: 48 8b 07                      movq    (%rdi), %rax
// 33: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000035:  R_X86_64_64  _JIT_TARGET
// 3d: 89 c9                         movl    %ecx, %ecx
// 3f: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 43: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 49: c3                            retq
// 4a: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000004c:  R_X86_64_64  _Py_FalseStruct
// 54: 48 89 08                      movq    %rcx, (%rax)
// 57: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000059:  R_X86_64_64  _JIT_CONTINUE
// 61: ff e0                         jmpq    *%rax
// 63: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_INT_code_body[100] = {0x48, 0x89, 0xf0, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x0c, 0x25, 0x08, 0x00, 0x00, 0x00, 0x74, 0x28, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_TO_BOOL_INT_code_holes[5] = {
    {0x10, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyLong_Type, 0x0},
    {0x35, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x4c, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_FalseStruct, 0x0},
    {0x59, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_INT_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_INT_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_LIST.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_LIST_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_TO_BOOL_LIST_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_LIST_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_LIST_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_NONE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_NONE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_NONE_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_TO_BOOL_NONE_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_NONE_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_NONE_data_holes[1];

// _PUSH_NULLplus_TO_BOOL_STR
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_TO_BOOL_STR.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 7: 48 29 fe                      subq    %rdi, %rsi
// a: 48 83 c6 c0                   addq    $-0x40, %rsi
// e: 48 c1 ee 03                   shrq    $0x3, %rsi
// 12: 89 77 40                      movl    %esi, 0x40(%rdi)
// 15: 48 8b 07                      movq    (%rdi), %rax
// 18: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 000000000000001a:  R_X86_64_64  _JIT_TARGET
// 22: 89 c9                         movl    %ecx, %ecx
// 24: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 28: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 2e: c3                            retq
// 2f: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_STR_code_body[48] = {0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xc0, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _PUSH_NULLplus_TO_BOOL_STR_code_holes[2] = {
    {0x1a, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_TO_BOOL_STR_data_body[1];
static const Hole _PUSH_NULLplus_TO_BOOL_STR_data_holes[1];

// _PUSH_NULLplus_UNARY_INVERT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNARY_INVERT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyNumber_Invert
// 12: 31 ff                         xorl    %edi, %edi
// 14: ff d0                         callq   *%rax
// 16: 
static const unsigned char _PUSH_NULLplus_UNARY_INVERT_code_body[23] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_UNARY_INVERT_code_holes[2] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyNumber_Invert, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNARY_INVERT_data_body[1];
static const Hole _PUSH_NULLplus_UNARY_INVERT_data_holes[1];

// _PUSH_NULLplus_UNARY_NEGATIVE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNARY_NEGATIVE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 8: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000a:  R_X86_64_64  PyNumber_Negative
// 12: 31 ff                         xorl    %edi, %edi
// 14: ff d0                         callq   *%rax
// 16: 
static const unsigned char _PUSH_NULLplus_UNARY_NEGATIVE_code_body[23] = {0x50, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_UNARY_NEGATIVE_code_holes[2] = {
    {0xa, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyNumber_Negative, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNARY_NEGATIVE_data_body[1];
static const Hole _PUSH_NULLplus_UNARY_NEGATIVE_data_holes[1];

// _PUSH_NULLplus_UNARY_NOT
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNARY_NOT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000002:  R_X86_64_64  _Py_FalseStruct
// a: 48 89 06                      movq    %rax, (%rsi)
// d: 48 83 c6 08                   addq    $0x8, %rsi
// 11: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000013:  R_X86_64_64  _JIT_CONTINUE
// 1b: ff e0                         jmpq    *%rax
// 1d: 
static const unsigned char _PUSH_NULLplus_UNARY_NOT_code_body[30] = {0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x06, 0x48, 0x83, 0xc6, 0x08, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
static const Hole _PUSH_NULLplus_UNARY_NOT_code_holes[3] = {
    {0x2, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_FalseStruct, 0x0},
    {0x13, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNARY_NOT_data_body[1];
static const Hole _PUSH_NULLplus_UNARY_NOT_data_holes[1];

// _PUSH_NULLplus_UNPACK_EX
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNPACK_EX.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 89 d7                      movq    %rdx, %rdi
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_OPARG
// 15: 0f b6 cc                      movzbl  %ah, %ecx
// 18: 0f b6 d0                      movzbl  %al, %edx
// 1b: 8d 04 0a                      leal    (%rdx,%rcx), %eax
// 1e: ff c0                         incl    %eax
// 20: 4c 8d 04 c6                   leaq    (%rsi,%rax,8), %r8
// 24: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000026:  R_X86_64_64  _PyEval_UnpackIterable
// 2e: 31 f6                         xorl    %esi, %esi
// 30: ff d0                         callq   *%rax
// 32: 
static const unsigned char _PUSH_NULLplus_UNPACK_EX_code_body[51] = {0x50, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb6, 0xcc, 0x0f, 0xb6, 0xd0, 0x8d, 0x04, 0x0a, 0xff, 0xc0, 0x4c, 0x8d, 0x04, 0xc6, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_UNPACK_EX_code_holes[3] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x26, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_UnpackIterable, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNPACK_EX_data_body[1];
static const Hole _PUSH_NULLplus_UNPACK_EX_data_holes[1];

// _PUSH_NULLplus_UNPACK_SEQUENCE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNPACK_SEQUENCE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 50                            pushq   %rax
// 1: 48 89 d7                      movq    %rdx, %rdi
// 4: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// b: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000000d:  R_X86_64_64  _JIT_OPARG
// 15: 0f b7 c8                      movzwl  %ax, %ecx
// 18: 4c 8d 04 ce                   leaq    (%rsi,%rcx,8), %r8
// 1c: 0f b7 d0                      movzwl  %ax, %edx
// 1f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000021:  R_X86_64_64  _PyEval_UnpackIterable
// 29: 31 f6                         xorl    %esi, %esi
// 2b: b9 ff ff ff ff                movl    $0xffffffff, %ecx       # imm = 0xFFFFFFFF
// 30: ff d0                         callq   *%rax
// 32: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_code_body[51] = {0x50, 0x48, 0x89, 0xd7, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc8, 0x4c, 0x8d, 0x04, 0xce, 0x0f, 0xb7, 0xd0, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xf6, 0xb9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0};
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_code_holes[3] = {
    {0xd, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x21, HoleKind_R_X86_64_64, HoleValue_ZERO, &_PyEval_UnpackIterable, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_data_body[1];
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_data_holes[1];

// _PUSH_NULLplus_UNPACK_SEQUENCE_LIST
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNPACK_SEQUENCE_LIST.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 55                         pushq   %r13
// 6: 41 54                         pushq   %r12
// 8: 53                            pushq   %rbx
// 9: 48 89 f3                      movq    %rsi, %rbx
// c: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 13: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000015:  R_X86_64_64  PyList_Type
// 1d: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 25: 75 58                         jne     0x7f <_JIT_ENTRY+0x7f>
// 27: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000029:  R_X86_64_64  _JIT_OPARG
// 31: 0f b7 c0                      movzwl  %ax, %eax
// 34: 48 39 04 25 10 00 00 00       cmpq    %rax, 0x10
// 3c: 75 41                         jne     0x7f <_JIT_ENTRY+0x7f>
// 3e: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000040:  R_X86_64_64  _JIT_OPARG
// 48: 44 0f b7 f0                   movzwl  %ax, %r14d
// 4c: 4c 8b 3c 25 18 00 00 00       movq    0x18, %r15
// 54: 49 bc 00 00 00 00 00 00 00 00 movabsq $0x0, %r12
// 0000000000000056:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 5e: eb 07                         jmp     0x67 <_JIT_ENTRY+0x67>
// 60: 4c 89 2b                      movq    %r13, (%rbx)
// 63: 48 83 c3 08                   addq    $0x8, %rbx
// 67: 41 ff ce                      decl    %r14d
// 6a: 4f 8b 2c f7                   movq    (%r15,%r14,8), %r13
// 6e: 41 8b 45 00                   movl    (%r13), %eax
// 72: ff c0                         incl    %eax
// 74: 74 ea                         je      0x60 <_JIT_ENTRY+0x60>
// 76: 41 89 45 00                   movl    %eax, (%r13)
// 7a: 41 ff d4                      callq   *%r12
// 7d: eb e1                         jmp     0x60 <_JIT_ENTRY+0x60>
// 7f: 48 29 fb                      subq    %rdi, %rbx
// 82: 48 83 c3 c0                   addq    $-0x40, %rbx
// 86: 48 c1 eb 03                   shrq    $0x3, %rbx
// 8a: 89 5f 40                      movl    %ebx, 0x40(%rdi)
// 8d: 48 8b 07                      movq    (%rdi), %rax
// 90: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000092:  R_X86_64_64  _JIT_TARGET
// 9a: 89 c9                         movl    %ecx, %ecx
// 9c: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// a4: 5b                            popq    %rbx
// a5: 41 5c                         popq    %r12
// a7: 41 5d                         popq    %r13
// a9: 41 5e                         popq    %r14
// ab: 41 5f                         popq    %r15
// ad: c3                            retq
// ae: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_LIST_code_body[175] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x89, 0xf3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x58, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x39, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x75, 0x41, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xf0, 0x4c, 0x8b, 0x3c, 0x25, 0x18, 0x00, 0x00, 0x00, 0x49, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x07, 0x4c, 0x89, 0x2b, 0x48, 0x83, 0xc3, 0x08, 0x41, 0xff, 0xce, 0x4f, 0x8b, 0x2c, 0xf7, 0x41, 0x8b, 0x45, 0x00, 0xff, 0xc0, 0x74, 0xea, 0x41, 0x89, 0x45, 0x00, 0x41, 0xff, 0xd4, 0xeb, 0xe1, 0x48, 0x29, 0xfb, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x89, 0x5f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_LIST_code_holes[6] = {
    {0x15, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyList_Type, 0x0},
    {0x29, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x40, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x56, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x92, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_LIST_data_body[1];
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_LIST_data_holes[1];

// _PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 41 54                         pushq   %r12
// 6: 53                            pushq   %rbx
// 7: 50                            pushq   %rax
// 8: 48 89 f3                      movq    %rsi, %rbx
// b: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 12: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000014:  R_X86_64_64  PyTuple_Type
// 1c: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 24: 75 5d                         jne     0x83 <_JIT_ENTRY+0x83>
// 26: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000028:  R_X86_64_64  _JIT_OPARG
// 30: 0f b7 c0                      movzwl  %ax, %eax
// 33: 48 39 04 25 10 00 00 00       cmpq    %rax, 0x10
// 3b: 75 46                         jne     0x83 <_JIT_ENTRY+0x83>
// 3d: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000003f:  R_X86_64_64  _JIT_OPARG
// 47: 44 0f b7 f0                   movzwl  %ax, %r14d
// 4b: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 000000000000004d:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 55: eb 10                         jmp     0x67 <_JIT_ENTRY+0x67>
// 57: 66 0f 1f 84 00 00 00 00 00    nopw    (%rax,%rax)
// 60: 4c 89 23                      movq    %r12, (%rbx)
// 63: 48 83 c3 08                   addq    $0x8, %rbx
// 67: 41 ff ce                      decl    %r14d
// 6a: 4e 8b 24 f5 18 00 00 00       movq    0x18(,%r14,8), %r12
// 72: 41 8b 04 24                   movl    (%r12), %eax
// 76: ff c0                         incl    %eax
// 78: 74 e6                         je      0x60 <_JIT_ENTRY+0x60>
// 7a: 41 89 04 24                   movl    %eax, (%r12)
// 7e: 41 ff d7                      callq   *%r15
// 81: eb dd                         jmp     0x60 <_JIT_ENTRY+0x60>
// 83: 48 29 fb                      subq    %rdi, %rbx
// 86: 48 83 c3 c0                   addq    $-0x40, %rbx
// 8a: 48 c1 eb 03                   shrq    $0x3, %rbx
// 8e: 89 5f 40                      movl    %ebx, 0x40(%rdi)
// 91: 48 8b 07                      movq    (%rdi), %rax
// 94: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000096:  R_X86_64_64  _JIT_TARGET
// 9e: 89 c9                         movl    %ecx, %ecx
// a0: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// a4: 48 05 c8 00 00 00             addq    $0xc8, %rax
// aa: 48 83 c4 08                   addq    $0x8, %rsp
// ae: 5b                            popq    %rbx
// af: 41 5c                         popq    %r12
// b1: 41 5e                         popq    %r14
// b3: 41 5f                         popq    %r15
// b5: c3                            retq
// b6: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE_code_body[183] = {0x41, 0x57, 0x41, 0x56, 0x41, 0x54, 0x53, 0x50, 0x48, 0x89, 0xf3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x5d, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x48, 0x39, 0x04, 0x25, 0x10, 0x00, 0x00, 0x00, 0x75, 0x46, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x0f, 0xb7, 0xf0, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x10, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0x23, 0x48, 0x83, 0xc3, 0x08, 0x41, 0xff, 0xce, 0x4e, 0x8b, 0x24, 0xf5, 0x18, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x04, 0x24, 0xff, 0xc0, 0x74, 0xe6, 0x41, 0x89, 0x04, 0x24, 0x41, 0xff, 0xd7, 0xeb, 0xdd, 0x48, 0x29, 0xfb, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x89, 0x5f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc4, 0x08, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5f, 0xc3};
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE_code_holes[6] = {
    {0x14, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x28, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x3f, HoleKind_R_X86_64_64, HoleValue_OPARG, NULL, 0x0},
    {0x4d, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
    {0x96, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE_data_holes[1];

// _PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 41 57                         pushq   %r15
// 2: 41 56                         pushq   %r14
// 4: 53                            pushq   %rbx
// 5: 48 89 f3                      movq    %rsi, %rbx
// 8: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// f: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000011:  R_X86_64_64  PyTuple_Type
// 19: 48 39 04 25 08 00 00 00       cmpq    %rax, 0x8
// 21: 75 0b                         jne     0x2e <_JIT_ENTRY+0x2e>
// 23: 48 83 3c 25 10 00 00 00 02    cmpq    $0x2, 0x10
// 2c: 74 2b                         je      0x59 <_JIT_ENTRY+0x59>
// 2e: 48 29 fb                      subq    %rdi, %rbx
// 31: 48 83 c3 c0                   addq    $-0x40, %rbx
// 35: 48 c1 eb 03                   shrq    $0x3, %rbx
// 39: 89 5f 40                      movl    %ebx, 0x40(%rdi)
// 3c: 48 8b 07                      movq    (%rdi), %rax
// 3f: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000041:  R_X86_64_64  _JIT_TARGET
// 49: 89 c9                         movl    %ecx, %ecx
// 4b: 48 8d 84 48 c8 00 00 00       leaq    0xc8(%rax,%rcx,2), %rax
// 53: 5b                            popq    %rbx
// 54: 41 5e                         popq    %r14
// 56: 41 5f                         popq    %r15
// 58: c3                            retq
// 59: 4c 8b 34 25 20 00 00 00       movq    0x20, %r14
// 61: 41 8b 06                      movl    (%r14), %eax
// 64: 49 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %r15
// 0000000000000066:  R_X86_64_64  _Py_INCREF_IncRefTotal
// 6e: ff c0                         incl    %eax
// 70: 74 06                         je      0x78 <_JIT_ENTRY+0x78>
// 72: 41 89 06                      movl    %eax, (%r14)
// 75: 41 ff d7                      callq   *%r15
// 78: 4c 89 33                      movq    %r14, (%rbx)
// 7b: 48 8b 04 25 18 00 00 00       movq    0x18, %rax
// 83: ff 00                         incl    (%rax)
// 85: 41 ff d7                      callq   *%r15
// 88: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE_code_body[137] = {0x41, 0x57, 0x41, 0x56, 0x53, 0x48, 0x89, 0xf3, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x39, 0x04, 0x25, 0x08, 0x00, 0x00, 0x00, 0x75, 0x0b, 0x48, 0x83, 0x3c, 0x25, 0x10, 0x00, 0x00, 0x00, 0x02, 0x74, 0x2b, 0x48, 0x29, 0xfb, 0x48, 0x83, 0xc3, 0xc0, 0x48, 0xc1, 0xeb, 0x03, 0x89, 0x5f, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x84, 0x48, 0xc8, 0x00, 0x00, 0x00, 0x5b, 0x41, 0x5e, 0x41, 0x5f, 0xc3, 0x4c, 0x8b, 0x34, 0x25, 0x20, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x06, 0x49, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x74, 0x06, 0x41, 0x89, 0x06, 0x41, 0xff, 0xd7, 0x4c, 0x89, 0x33, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x00, 0x00, 0xff, 0x00, 0x41, 0xff, 0xd7};
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE_code_holes[4] = {
    {0x11, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyTuple_Type, 0x0},
    {0x41, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
    {0x66, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_INCREF_IncRefTotal, 0x0},
};
// 0: 
static const unsigned char _PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE_data_body[1];
static const Hole _PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE_data_holes[1];

// _PUSH_NULLplus_WITH_EXCEPT_START
// 
// /tmp/tmpvnkmy6hl/_PUSH_NULLplus_WITH_EXCEPT_START.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 55                            pushq   %rbp
// 1: 41 57                         pushq   %r15
// 3: 41 56                         pushq   %r14
// 5: 41 55                         pushq   %r13
// 7: 41 54                         pushq   %r12
// 9: 53                            pushq   %rbx
// a: 48 83 ec 28                   subq    $0x28, %rsp
// e: 49 89 d7                      movq    %rdx, %r15
// 11: 48 89 f3                      movq    %rsi, %rbx
// 14: 49 89 fe                      movq    %rdi, %r14
// 17: 48 c7 06 00 00 00 00          movq    $0x0, (%rsi)
// 1e: 4c 8b 66 e8                   movq    -0x18(%rsi), %r12
// 22: 48 8b 2c 25 08 00 00 00       movq    0x8, %rbp
// 2a: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 000000000000002c:  R_X86_64_64  PyException_GetTraceback
// 34: 31 ff                         xorl    %edi, %edi
// 36: ff d0                         callq   *%rax
// 38: 48 85 c0                      testq   %rax, %rax
// 3b: 74 11                         je      0x4e <_JIT_ENTRY+0x4e>
// 3d: 49 89 c5                      movq    %rax, %r13
// 40: 48 8b 00                      movq    (%rax), %rax
// 43: 48 85 c0                      testq   %rax, %rax
// 46: 7e 12                         jle     0x5a <_JIT_ENTRY+0x5a>
// 48: 85 c0                         testl   %eax, %eax
// 4a: 79 34                         jns     0x80 <_JIT_ENTRY+0x80>
// 4c: eb 53                         jmp     0xa1 <_JIT_ENTRY+0xa1>
// 4e: 49 bd 00 00 00 00 00 00 00 00 movabsq $0x0, %r13
// 0000000000000050:  R_X86_64_64  _Py_NoneStruct
// 58: eb 47                         jmp     0xa1 <_JIT_ENTRY+0xa1>
// 5a: 48 bf 00 00 00 00 00 00 00 00 movabsq $0x0, %rdi
// 000000000000005c:  R_X86_64_64  .rodata.str1.1
// 64: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000066:  R_X86_64_64  _Py_NegativeRefcount
// 6e: be 64 09 00 00                movl    $0x964, %esi            # imm = 0x964
// 73: 4c 89 ea                      movq    %r13, %rdx
// 76: ff d0                         callq   *%rax
// 78: 49 8b 45 00                   movq    (%r13), %rax
// 7c: 85 c0                         testl   %eax, %eax
// 7e: 78 21                         js      0xa1 <_JIT_ENTRY+0xa1>
// 80: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000082:  R_X86_64_64  _Py_DECREF_DecRefTotal
// 8a: ff d0                         callq   *%rax
// 8c: 49 ff 4d 00                   decq    (%r13)
// 90: 75 0f                         jne     0xa1 <_JIT_ENTRY+0xa1>
// 92: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 0000000000000094:  R_X86_64_64  _Py_Dealloc
// 9c: 4c 89 ef                      movq    %r13, %rdi
// 9f: ff d0                         callq   *%rax
// a1: 48 c7 04 24 00 00 00 00       movq    $0x0, (%rsp)
// a9: 48 8d 74 24 08                leaq    0x8(%rsp), %rsi
// ae: 48 89 6c 24 08                movq    %rbp, 0x8(%rsp)
// b3: 48 c7 44 24 10 00 00 00 00    movq    $0x0, 0x10(%rsp)
// bc: 4c 89 6c 24 18                movq    %r13, 0x18(%rsp)
// c1: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000c3:  R_X86_64_64  PyObject_Vectorcall
// cb: 48 ba 03 00 00 00 00 00 00 80 movabsq $-0x7ffffffffffffffd, %rdx # imm = 0x8000000000000003
// d5: 4c 89 e7                      movq    %r12, %rdi
// d8: 31 c9                         xorl    %ecx, %ecx
// da: ff d0                         callq   *%rax
// dc: 48 85 c0                      testq   %rax, %rax
// df: 74 2b                         je      0x10c <_JIT_ENTRY+0x10c>
// e1: 48 89 43 08                   movq    %rax, 0x8(%rbx)
// e5: 48 83 c3 10                   addq    $0x10, %rbx
// e9: 48 b8 00 00 00 00 00 00 00 00 movabsq $0x0, %rax
// 00000000000000eb:  R_X86_64_64  _JIT_CONTINUE
// f3: 4c 89 f7                      movq    %r14, %rdi
// f6: 48 89 de                      movq    %rbx, %rsi
// f9: 4c 89 fa                      movq    %r15, %rdx
// fc: 48 83 c4 28                   addq    $0x28, %rsp
// 100: 5b                            popq    %rbx
// 101: 41 5c                         popq    %r12
// 103: 41 5d                         popq    %r13
// 105: 41 5e                         popq    %r14
// 107: 41 5f                         popq    %r15
// 109: 5d                            popq    %rbp
// 10a: ff e0                         jmpq    *%rax
// 10c: 48 83 c3 08                   addq    $0x8, %rbx
// 110: 4c 29 f3                      subq    %r14, %rbx
// 113: 48 83 c3 b8                   addq    $-0x48, %rbx
// 117: 48 c1 eb 03                   shrq    $0x3, %rbx
// 11b: 41 89 5e 40                   movl    %ebx, 0x40(%r14)
// 11f: 31 c0                         xorl    %eax, %eax
// 121: 48 83 c4 28                   addq    $0x28, %rsp
// 125: 5b                            popq    %rbx
// 126: 41 5c                         popq    %r12
// 128: 41 5d                         popq    %r13
// 12a: 41 5e                         popq    %r14
// 12c: 41 5f                         popq    %r15
// 12e: 5d                            popq    %rbp
// 12f: c3                            retq
// 130: 
static const unsigned char _PUSH_NULLplus_WITH_EXCEPT_START_code_body[305] = {0x55, 0x41, 0x57, 0x41, 0x56, 0x41, 0x55, 0x41, 0x54, 0x53, 0x48, 0x83, 0xec, 0x28, 0x49, 0x89, 0xd7, 0x48, 0x89, 0xf3, 0x49, 0x89, 0xfe, 0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x8b, 0x66, 0xe8, 0x48, 0x8b, 0x2c, 0x25, 0x08, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x11, 0x49, 0x89, 0xc5, 0x48, 0x8b, 0x00, 0x48, 0x85, 0xc0, 0x7e, 0x12, 0x85, 0xc0, 0x79, 0x34, 0xeb, 0x53, 0x49, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x47, 0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x64, 0x09, 0x00, 0x00, 0x4c, 0x89, 0xea, 0xff, 0xd0, 0x49, 0x8b, 0x45, 0x00, 0x85, 0xc0, 0x78, 0x21, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x49, 0xff, 0x4d, 0x00, 0x75, 0x0f, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xef, 0xff, 0xd0, 0x48, 0xc7, 0x04, 0x24, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8d, 0x74, 0x24, 0x08, 0x48, 0x89, 0x6c, 0x24, 0x08, 0x48, 0xc7, 0x44, 0x24, 0x10, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0x6c, 0x24, 0x18, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xba, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x4c, 0x89, 0xe7, 0x31, 0xc9, 0xff, 0xd0, 0x48, 0x85, 0xc0, 0x74, 0x2b, 0x48, 0x89, 0x43, 0x08, 0x48, 0x83, 0xc3, 0x10, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x89, 0xf7, 0x48, 0x89, 0xde, 0x4c, 0x89, 0xfa, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xff, 0xe0, 0x48, 0x83, 0xc3, 0x08, 0x4c, 0x29, 0xf3, 0x48, 0x83, 0xc3, 0xb8, 0x48, 0xc1, 0xeb, 0x03, 0x41, 0x89, 0x5e, 0x40, 0x31, 0xc0, 0x48, 0x83, 0xc4, 0x28, 0x5b, 0x41, 0x5c, 0x41, 0x5d, 0x41, 0x5e, 0x41, 0x5f, 0x5d, 0xc3};
static const Hole _PUSH_NULLplus_WITH_EXCEPT_START_code_holes[9] = {
    {0x2c, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyException_GetTraceback, 0x0},
    {0x50, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NoneStruct, 0x0},
    {0x5c, HoleKind_R_X86_64_64, HoleValue_DATA, NULL, 0x0},
    {0x66, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_NegativeRefcount, 0x0},
    {0x82, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_DECREF_DecRefTotal, 0x0},
    {0x94, HoleKind_R_X86_64_64, HoleValue_ZERO, &_Py_Dealloc, 0x0},
    {0xc3, HoleKind_R_X86_64_64, HoleValue_ZERO, &PyObject_Vectorcall, 0x0},
    {0xeb, HoleKind_R_X86_64_64, HoleValue_CONTINUE, NULL, 0x0},
};
// 0: '/home/jglass/Documents/cpython/Python/executor_cases.c.h\x00'
// 39: 00 00 00 00 00 00 00
static const unsigned char _PUSH_NULLplus_WITH_EXCEPT_START_data_body[65] = {0x2f, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6a, 0x67, 0x6c, 0x61, 0x73, 0x73, 0x2f, 0x44, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x2f, 0x63, 0x70, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x50, 0x79, 0x74, 0x68, 0x6f, 0x6e, 0x2f, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x61, 0x73, 0x65, 0x73, 0x2e, 0x63, 0x2e, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const Hole _PUSH_NULLplus_WITH_EXCEPT_START_data_holes[1];

#define INIT_STENCIL(STENCIL) {                         \
    .body_size = Py_ARRAY_LENGTH(STENCIL##_body) - 1,   \
    .body = STENCIL##_body,                             \
    .holes_size = Py_ARRAY_LENGTH(STENCIL##_holes) - 1, \
    .holes = STENCIL##_holes,                           \
}

#define INIT_STENCIL_GROUP(OP) {     \
    .code = INIT_STENCIL(OP##_code), \
    .data = INIT_STENCIL(OP##_data), \
}

static const StencilGroup stencil_groups[512] = {
    [_PUSH_NULLplus_BEFORE_ASYNC_WITH] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BEFORE_ASYNC_WITH),
    [_PUSH_NULLplus_BEFORE_WITH] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BEFORE_WITH),
    [_PUSH_NULLplus_BINARY_OP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP),
    [_PUSH_NULLplus_BINARY_OP_ADD_FLOAT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_ADD_FLOAT),
    [_PUSH_NULLplus_BINARY_OP_ADD_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_ADD_INT),
    [_PUSH_NULLplus_BINARY_OP_ADD_UNICODE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_ADD_UNICODE),
    [_PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_MULTIPLY_FLOAT),
    [_PUSH_NULLplus_BINARY_OP_MULTIPLY_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_MULTIPLY_INT),
    [_PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_SUBTRACT_FLOAT),
    [_PUSH_NULLplus_BINARY_OP_SUBTRACT_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_OP_SUBTRACT_INT),
    [_PUSH_NULLplus_BINARY_SLICE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SLICE),
    [_PUSH_NULLplus_BINARY_SUBSCR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SUBSCR),
    [_PUSH_NULLplus_BINARY_SUBSCR_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SUBSCR_DICT),
    [_PUSH_NULLplus_BINARY_SUBSCR_LIST_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SUBSCR_LIST_INT),
    [_PUSH_NULLplus_BINARY_SUBSCR_STR_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SUBSCR_STR_INT),
    [_PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BINARY_SUBSCR_TUPLE_INT),
    [_PUSH_NULLplus_BUILD_CONST_KEY_MAP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_CONST_KEY_MAP),
    [_PUSH_NULLplus_BUILD_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_LIST),
    [_PUSH_NULLplus_BUILD_MAP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_MAP),
    [_PUSH_NULLplus_BUILD_SET] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_SET),
    [_PUSH_NULLplus_BUILD_SLICE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_SLICE),
    [_PUSH_NULLplus_BUILD_STRING] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_STRING),
    [_PUSH_NULLplus_BUILD_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_BUILD_TUPLE),
    [_PUSH_NULLplus_CALL_BUILTIN_CLASS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_BUILTIN_CLASS),
    [_PUSH_NULLplus_CALL_BUILTIN_FAST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_BUILTIN_FAST),
    [_PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_BUILTIN_FAST_WITH_KEYWORDS),
    [_PUSH_NULLplus_CALL_BUILTIN_O] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_BUILTIN_O),
    [_PUSH_NULLplus_CALL_INTRINSIC_1] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_INTRINSIC_1),
    [_PUSH_NULLplus_CALL_INTRINSIC_2] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_INTRINSIC_2),
    [_PUSH_NULLplus_CALL_ISINSTANCE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_ISINSTANCE),
    [_PUSH_NULLplus_CALL_LEN] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_LEN),
    [_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST),
    [_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS),
    [_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_NOARGS),
    [_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_METHOD_DESCRIPTOR_O),
    [_PUSH_NULLplus_CALL_STR_1] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_STR_1),
    [_PUSH_NULLplus_CALL_TUPLE_1] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_TUPLE_1),
    [_PUSH_NULLplus_CALL_TYPE_1] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CALL_TYPE_1),
    [_PUSH_NULLplus_CHECK_ATTR_CLASS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_ATTR_CLASS),
    [_PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_ATTR_METHOD_LAZY_DICT),
    [_PUSH_NULLplus_CHECK_ATTR_MODULE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_ATTR_MODULE),
    [_PUSH_NULLplus_CHECK_ATTR_WITH_HINT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_ATTR_WITH_HINT),
    [_PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS),
    [_PUSH_NULLplus_CHECK_EG_MATCH] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_EG_MATCH),
    [_PUSH_NULLplus_CHECK_EXC_MATCH] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_EXC_MATCH),
    [_PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_FUNCTION_EXACT_ARGS),
    [_PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_MANAGED_OBJECT_HAS_VALUES),
    [_PUSH_NULLplus_CHECK_PEP_523] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_PEP_523),
    [_PUSH_NULLplus_CHECK_STACK_SPACE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_STACK_SPACE),
    [_PUSH_NULLplus_CHECK_VALIDITY] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CHECK_VALIDITY),
    [_PUSH_NULLplus_COMPARE_OP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COMPARE_OP),
    [_PUSH_NULLplus_COMPARE_OP_FLOAT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COMPARE_OP_FLOAT),
    [_PUSH_NULLplus_COMPARE_OP_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COMPARE_OP_INT),
    [_PUSH_NULLplus_COMPARE_OP_STR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COMPARE_OP_STR),
    [_PUSH_NULLplus_CONTAINS_OP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CONTAINS_OP),
    [_PUSH_NULLplus_CONVERT_VALUE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_CONVERT_VALUE),
    [_PUSH_NULLplus_COPY] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COPY),
    [_PUSH_NULLplus_COPY_FREE_VARS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_COPY_FREE_VARS),
    [_PUSH_NULLplus_DELETE_ATTR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_ATTR),
    [_PUSH_NULLplus_DELETE_DEREF] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_DEREF),
    [_PUSH_NULLplus_DELETE_FAST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_FAST),
    [_PUSH_NULLplus_DELETE_GLOBAL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_GLOBAL),
    [_PUSH_NULLplus_DELETE_NAME] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_NAME),
    [_PUSH_NULLplus_DELETE_SUBSCR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DELETE_SUBSCR),
    [_PUSH_NULLplus_DICT_MERGE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DICT_MERGE),
    [_PUSH_NULLplus_DICT_UPDATE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_DICT_UPDATE),
    [_PUSH_NULLplus_END_SEND] = INIT_STENCIL_GROUP(_PUSH_NULLplus_END_SEND),
    [_PUSH_NULLplus_EXIT_INIT_CHECK] = INIT_STENCIL_GROUP(_PUSH_NULLplus_EXIT_INIT_CHECK),
    [_PUSH_NULLplus_EXIT_TRACE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_EXIT_TRACE),
    [_PUSH_NULLplus_FORMAT_SIMPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_FORMAT_SIMPLE),
    [_PUSH_NULLplus_FORMAT_WITH_SPEC] = INIT_STENCIL_GROUP(_PUSH_NULLplus_FORMAT_WITH_SPEC),
    [_PUSH_NULLplus_FOR_ITER_TIER_TWO] = INIT_STENCIL_GROUP(_PUSH_NULLplus_FOR_ITER_TIER_TWO),
    [_PUSH_NULLplus_GET_AITER] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_AITER),
    [_PUSH_NULLplus_GET_ANEXT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_ANEXT),
    [_PUSH_NULLplus_GET_AWAITABLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_AWAITABLE),
    [_PUSH_NULLplus_GET_ITER] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_ITER),
    [_PUSH_NULLplus_GET_LEN] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_LEN),
    [_PUSH_NULLplus_GET_YIELD_FROM_ITER] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GET_YIELD_FROM_ITER),
    [_PUSH_NULLplus_GUARD_BOTH_FLOAT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_BOTH_FLOAT),
    [_PUSH_NULLplus_GUARD_BOTH_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_BOTH_INT),
    [_PUSH_NULLplus_GUARD_BOTH_UNICODE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_BOTH_UNICODE),
    [_PUSH_NULLplus_GUARD_BUILTINS_VERSION] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_BUILTINS_VERSION),
    [_PUSH_NULLplus_GUARD_DORV_VALUES] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_DORV_VALUES),
    [_PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT),
    [_PUSH_NULLplus_GUARD_GLOBALS_VERSION] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_GLOBALS_VERSION),
    [_PUSH_NULLplus_GUARD_IS_FALSE_POP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_IS_FALSE_POP),
    [_PUSH_NULLplus_GUARD_IS_NONE_POP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_IS_NONE_POP),
    [_PUSH_NULLplus_GUARD_IS_NOT_NONE_POP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_IS_NOT_NONE_POP),
    [_PUSH_NULLplus_GUARD_IS_TRUE_POP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_IS_TRUE_POP),
    [_PUSH_NULLplus_GUARD_KEYS_VERSION] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_KEYS_VERSION),
    [_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_LIST),
    [_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_RANGE),
    [_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_NOT_EXHAUSTED_TUPLE),
    [_PUSH_NULLplus_GUARD_TYPE_VERSION] = INIT_STENCIL_GROUP(_PUSH_NULLplus_GUARD_TYPE_VERSION),
    [_PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS),
    [_PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_INIT_CALL_PY_EXACT_ARGS),
    [_PUSH_NULLplus_INSERT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_INSERT),
    [_PUSH_NULLplus_IS_NONE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_IS_NONE),
    [_PUSH_NULLplus_IS_OP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_IS_OP),
    [_PUSH_NULLplus_ITER_CHECK_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_CHECK_LIST),
    [_PUSH_NULLplus_ITER_CHECK_RANGE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_CHECK_RANGE),
    [_PUSH_NULLplus_ITER_CHECK_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_CHECK_TUPLE),
    [_PUSH_NULLplus_ITER_NEXT_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_NEXT_LIST),
    [_PUSH_NULLplus_ITER_NEXT_RANGE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_NEXT_RANGE),
    [_PUSH_NULLplus_ITER_NEXT_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_ITER_NEXT_TUPLE),
    [_PUSH_NULLplus_JUMP_TO_TOP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_JUMP_TO_TOP),
    [_PUSH_NULLplus_LIST_APPEND] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LIST_APPEND),
    [_PUSH_NULLplus_LIST_EXTEND] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LIST_EXTEND),
    [_PUSH_NULLplus_LOAD_ASSERTION_ERROR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ASSERTION_ERROR),
    [_PUSH_NULLplus_LOAD_ATTR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR),
    [_PUSH_NULLplus_LOAD_ATTR_CLASS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_CLASS),
    [_PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_INSTANCE_VALUE),
    [_PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_METHOD_LAZY_DICT),
    [_PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_METHOD_NO_DICT),
    [_PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_METHOD_WITH_VALUES),
    [_PUSH_NULLplus_LOAD_ATTR_MODULE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_MODULE),
    [_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT),
    [_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES),
    [_PUSH_NULLplus_LOAD_ATTR_SLOT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_SLOT),
    [_PUSH_NULLplus_LOAD_ATTR_WITH_HINT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_ATTR_WITH_HINT),
    [_PUSH_NULLplus_LOAD_BUILD_CLASS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_BUILD_CLASS),
    [_PUSH_NULLplus_LOAD_CONST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_CONST),
    [_PUSH_NULLplus_LOAD_DEREF] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_DEREF),
    [_PUSH_NULLplus_LOAD_FAST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_FAST),
    [_PUSH_NULLplus_LOAD_FAST_AND_CLEAR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_FAST_AND_CLEAR),
    [_PUSH_NULLplus_LOAD_FAST_CHECK] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_FAST_CHECK),
    [_PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_FROM_DICT_OR_DEREF),
    [_PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_FROM_DICT_OR_GLOBALS),
    [_PUSH_NULLplus_LOAD_GLOBAL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_GLOBAL),
    [_PUSH_NULLplus_LOAD_GLOBAL_BUILTINS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_GLOBAL_BUILTINS),
    [_PUSH_NULLplus_LOAD_GLOBAL_MODULE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_GLOBAL_MODULE),
    [_PUSH_NULLplus_LOAD_LOCALS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_LOCALS),
    [_PUSH_NULLplus_LOAD_NAME] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_NAME),
    [_PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_SUPER_ATTR_ATTR),
    [_PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD] = INIT_STENCIL_GROUP(_PUSH_NULLplus_LOAD_SUPER_ATTR_METHOD),
    [_PUSH_NULLplus_MAKE_CELL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MAKE_CELL),
    [_PUSH_NULLplus_MAKE_FUNCTION] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MAKE_FUNCTION),
    [_PUSH_NULLplus_MAP_ADD] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MAP_ADD),
    [_PUSH_NULLplus_MATCH_CLASS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MATCH_CLASS),
    [_PUSH_NULLplus_MATCH_KEYS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MATCH_KEYS),
    [_PUSH_NULLplus_MATCH_MAPPING] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MATCH_MAPPING),
    [_PUSH_NULLplus_MATCH_SEQUENCE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_MATCH_SEQUENCE),
    [_PUSH_NULLplus_NOP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_NOP),
    [_PUSH_NULLplus_POP_EXCEPT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_POP_EXCEPT),
    [_PUSH_NULLplus_POP_FRAME] = INIT_STENCIL_GROUP(_PUSH_NULLplus_POP_FRAME),
    [_PUSH_NULLplus_POP_TOP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_POP_TOP),
    [_PUSH_NULLplus_PUSH_EXC_INFO] = INIT_STENCIL_GROUP(_PUSH_NULLplus_PUSH_EXC_INFO),
    [_PUSH_NULLplus_PUSH_FRAME] = INIT_STENCIL_GROUP(_PUSH_NULLplus_PUSH_FRAME),
    [_PUSH_NULLplus_PUSH_NULL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_PUSH_NULL),
    [_PUSH_NULLplus_RESUME_CHECK] = INIT_STENCIL_GROUP(_PUSH_NULLplus_RESUME_CHECK),
    [_PUSH_NULLplus_SAVE_RETURN_OFFSET] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SAVE_RETURN_OFFSET),
    [_PUSH_NULLplus_SETUP_ANNOTATIONS] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SETUP_ANNOTATIONS),
    [_PUSH_NULLplus_SET_ADD] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SET_ADD),
    [_PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SET_FUNCTION_ATTRIBUTE),
    [_PUSH_NULLplus_SET_IP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SET_IP),
    [_PUSH_NULLplus_SET_UPDATE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SET_UPDATE),
    [_PUSH_NULLplus_STORE_ATTR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_ATTR),
    [_PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_ATTR_INSTANCE_VALUE),
    [_PUSH_NULLplus_STORE_ATTR_SLOT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_ATTR_SLOT),
    [_PUSH_NULLplus_STORE_DEREF] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_DEREF),
    [_PUSH_NULLplus_STORE_FAST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_FAST),
    [_PUSH_NULLplus_STORE_GLOBAL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_GLOBAL),
    [_PUSH_NULLplus_STORE_NAME] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_NAME),
    [_PUSH_NULLplus_STORE_SLICE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_SLICE),
    [_PUSH_NULLplus_STORE_SUBSCR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_SUBSCR),
    [_PUSH_NULLplus_STORE_SUBSCR_DICT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_SUBSCR_DICT),
    [_PUSH_NULLplus_STORE_SUBSCR_LIST_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_STORE_SUBSCR_LIST_INT),
    [_PUSH_NULLplus_SWAP] = INIT_STENCIL_GROUP(_PUSH_NULLplus_SWAP),
    [_PUSH_NULLplus_TO_BOOL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL),
    [_PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_ALWAYS_TRUE),
    [_PUSH_NULLplus_TO_BOOL_BOOL] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_BOOL),
    [_PUSH_NULLplus_TO_BOOL_INT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_INT),
    [_PUSH_NULLplus_TO_BOOL_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_LIST),
    [_PUSH_NULLplus_TO_BOOL_NONE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_NONE),
    [_PUSH_NULLplus_TO_BOOL_STR] = INIT_STENCIL_GROUP(_PUSH_NULLplus_TO_BOOL_STR),
    [_PUSH_NULLplus_UNARY_INVERT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNARY_INVERT),
    [_PUSH_NULLplus_UNARY_NEGATIVE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNARY_NEGATIVE),
    [_PUSH_NULLplus_UNARY_NOT] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNARY_NOT),
    [_PUSH_NULLplus_UNPACK_EX] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNPACK_EX),
    [_PUSH_NULLplus_UNPACK_SEQUENCE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNPACK_SEQUENCE),
    [_PUSH_NULLplus_UNPACK_SEQUENCE_LIST] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNPACK_SEQUENCE_LIST),
    [_PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNPACK_SEQUENCE_TUPLE),
    [_PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE] = INIT_STENCIL_GROUP(_PUSH_NULLplus_UNPACK_SEQUENCE_TWO_TUPLE),
    [_PUSH_NULLplus_WITH_EXCEPT_START] = INIT_STENCIL_GROUP(_PUSH_NULLplus_WITH_EXCEPT_START),
};

#define GET_PATCHES() { \
    [HoleValue_CODE] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_CONTINUE] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_DATA] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_EXECUTOR] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_GOT] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_OPARG] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_OPERAND] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_TARGET] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_TOP] = (uint64_t)0xBADBADBADBADBADB, \
    [HoleValue_ZERO] = (uint64_t)0xBADBADBADBADBADB, \
}
