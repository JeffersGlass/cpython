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

// _EXIT_TRACEplus_BEFORE_ASYNC_WITH
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BEFORE_ASYNC_WITH.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BEFORE_ASYNC_WITH_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BEFORE_ASYNC_WITH_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BEFORE_ASYNC_WITH_data_body[1];
static const Hole _EXIT_TRACEplus_BEFORE_ASYNC_WITH_data_holes[1];

// _EXIT_TRACEplus_BEFORE_WITH
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BEFORE_WITH.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BEFORE_WITH_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BEFORE_WITH_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BEFORE_WITH_data_body[1];
static const Hole _EXIT_TRACEplus_BEFORE_WITH_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_ADD_FLOAT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_ADD_FLOAT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_FLOAT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_FLOAT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_FLOAT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_FLOAT_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_ADD_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_ADD_INT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_INT_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_ADD_UNICODE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_ADD_UNICODE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_UNICODE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_UNICODE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_ADD_UNICODE_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_ADD_UNICODE_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT_data_holes[1];

// _EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT_data_holes[1];

// _EXIT_TRACEplus_BINARY_SLICE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SLICE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SLICE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SLICE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SLICE_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SLICE_data_holes[1];

// _EXIT_TRACEplus_BINARY_SUBSCR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SUBSCR.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_data_holes[1];

// _EXIT_TRACEplus_BINARY_SUBSCR_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SUBSCR_DICT.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_DICT_data_holes[1];

// _EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT_data_holes[1];

// _EXIT_TRACEplus_BINARY_SUBSCR_STR_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SUBSCR_STR_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_STR_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_STR_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_STR_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_STR_INT_data_holes[1];

// _EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT_data_body[1];
static const Hole _EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT_data_holes[1];

// _EXIT_TRACEplus_BUILD_CONST_KEY_MAP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_CONST_KEY_MAP.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_CONST_KEY_MAP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_CONST_KEY_MAP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_CONST_KEY_MAP_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_CONST_KEY_MAP_data_holes[1];

// _EXIT_TRACEplus_BUILD_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_LIST.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_LIST_data_holes[1];

// _EXIT_TRACEplus_BUILD_MAP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_MAP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_MAP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_MAP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_MAP_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_MAP_data_holes[1];

// _EXIT_TRACEplus_BUILD_SET
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_SET.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_SET_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_SET_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_SET_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_SET_data_holes[1];

// _EXIT_TRACEplus_BUILD_SLICE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_SLICE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_SLICE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_SLICE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_SLICE_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_SLICE_data_holes[1];

// _EXIT_TRACEplus_BUILD_STRING
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_STRING.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_STRING_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_STRING_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_STRING_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_STRING_data_holes[1];

// _EXIT_TRACEplus_BUILD_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_BUILD_TUPLE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_BUILD_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_BUILD_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_BUILD_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_BUILD_TUPLE_data_holes[1];

// _EXIT_TRACEplus_CALL_BUILTIN_CLASS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_BUILTIN_CLASS.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_CLASS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_CLASS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_CLASS_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_CLASS_data_holes[1];

// _EXIT_TRACEplus_CALL_BUILTIN_FAST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_BUILTIN_FAST.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_FAST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_FAST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_FAST_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_FAST_data_holes[1];

// _EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS_data_holes[1];

// _EXIT_TRACEplus_CALL_BUILTIN_O
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_BUILTIN_O.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_O_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_O_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_BUILTIN_O_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_BUILTIN_O_data_holes[1];

// _EXIT_TRACEplus_CALL_INTRINSIC_1
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_INTRINSIC_1.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_INTRINSIC_1_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_INTRINSIC_1_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_INTRINSIC_1_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_INTRINSIC_1_data_holes[1];

// _EXIT_TRACEplus_CALL_INTRINSIC_2
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_INTRINSIC_2.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_INTRINSIC_2_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_INTRINSIC_2_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_INTRINSIC_2_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_INTRINSIC_2_data_holes[1];

// _EXIT_TRACEplus_CALL_ISINSTANCE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_ISINSTANCE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_ISINSTANCE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_ISINSTANCE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_ISINSTANCE_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_ISINSTANCE_data_holes[1];

// _EXIT_TRACEplus_CALL_LEN
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_LEN.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_LEN_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_LEN_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_LEN_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_LEN_data_holes[1];

// _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_data_holes[1];

// _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS_data_holes[1];

// _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS_data_holes[1];

// _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O_data_holes[1];

// _EXIT_TRACEplus_CALL_STR_1
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_STR_1.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_STR_1_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_STR_1_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_STR_1_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_STR_1_data_holes[1];

// _EXIT_TRACEplus_CALL_TUPLE_1
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_TUPLE_1.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_TUPLE_1_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_TUPLE_1_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_TUPLE_1_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_TUPLE_1_data_holes[1];

// _EXIT_TRACEplus_CALL_TYPE_1
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CALL_TYPE_1.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CALL_TYPE_1_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CALL_TYPE_1_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CALL_TYPE_1_data_body[1];
static const Hole _EXIT_TRACEplus_CALL_TYPE_1_data_holes[1];

// _EXIT_TRACEplus_CHECK_ATTR_CLASS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_ATTR_CLASS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_CLASS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_ATTR_CLASS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_CLASS_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_ATTR_CLASS_data_holes[1];

// _EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT_data_holes[1];

// _EXIT_TRACEplus_CHECK_ATTR_MODULE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_ATTR_MODULE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_MODULE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_ATTR_MODULE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_MODULE_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_ATTR_MODULE_data_holes[1];

// _EXIT_TRACEplus_CHECK_ATTR_WITH_HINT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_ATTR_WITH_HINT.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_WITH_HINT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_ATTR_WITH_HINT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_ATTR_WITH_HINT_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_ATTR_WITH_HINT_data_holes[1];

// _EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS_data_holes[1];

// _EXIT_TRACEplus_CHECK_EG_MATCH
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_EG_MATCH.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_EG_MATCH_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_EG_MATCH_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_EG_MATCH_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_EG_MATCH_data_holes[1];

// _EXIT_TRACEplus_CHECK_EXC_MATCH
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_EXC_MATCH.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_EXC_MATCH_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_EXC_MATCH_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_EXC_MATCH_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_EXC_MATCH_data_holes[1];

// _EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS_data_holes[1];

// _EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES_data_holes[1];

// _EXIT_TRACEplus_CHECK_PEP_523
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_PEP_523.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_PEP_523_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_PEP_523_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_PEP_523_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_PEP_523_data_holes[1];

// _EXIT_TRACEplus_CHECK_STACK_SPACE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_STACK_SPACE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_STACK_SPACE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_STACK_SPACE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_STACK_SPACE_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_STACK_SPACE_data_holes[1];

// _EXIT_TRACEplus_CHECK_VALIDITY
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CHECK_VALIDITY.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CHECK_VALIDITY_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CHECK_VALIDITY_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CHECK_VALIDITY_data_body[1];
static const Hole _EXIT_TRACEplus_CHECK_VALIDITY_data_holes[1];

// _EXIT_TRACEplus_COMPARE_OP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COMPARE_OP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COMPARE_OP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_data_body[1];
static const Hole _EXIT_TRACEplus_COMPARE_OP_data_holes[1];

// _EXIT_TRACEplus_COMPARE_OP_FLOAT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COMPARE_OP_FLOAT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_FLOAT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COMPARE_OP_FLOAT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_FLOAT_data_body[1];
static const Hole _EXIT_TRACEplus_COMPARE_OP_FLOAT_data_holes[1];

// _EXIT_TRACEplus_COMPARE_OP_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COMPARE_OP_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COMPARE_OP_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_INT_data_body[1];
static const Hole _EXIT_TRACEplus_COMPARE_OP_INT_data_holes[1];

// _EXIT_TRACEplus_COMPARE_OP_STR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COMPARE_OP_STR.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_STR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COMPARE_OP_STR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COMPARE_OP_STR_data_body[1];
static const Hole _EXIT_TRACEplus_COMPARE_OP_STR_data_holes[1];

// _EXIT_TRACEplus_CONTAINS_OP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CONTAINS_OP.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CONTAINS_OP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CONTAINS_OP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CONTAINS_OP_data_body[1];
static const Hole _EXIT_TRACEplus_CONTAINS_OP_data_holes[1];

// _EXIT_TRACEplus_CONVERT_VALUE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_CONVERT_VALUE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_CONVERT_VALUE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_CONVERT_VALUE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_CONVERT_VALUE_data_body[1];
static const Hole _EXIT_TRACEplus_CONVERT_VALUE_data_holes[1];

// _EXIT_TRACEplus_COPY
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COPY.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COPY_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COPY_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COPY_data_body[1];
static const Hole _EXIT_TRACEplus_COPY_data_holes[1];

// _EXIT_TRACEplus_COPY_FREE_VARS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_COPY_FREE_VARS.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_COPY_FREE_VARS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_COPY_FREE_VARS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_COPY_FREE_VARS_data_body[1];
static const Hole _EXIT_TRACEplus_COPY_FREE_VARS_data_holes[1];

// _EXIT_TRACEplus_DELETE_ATTR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_ATTR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_ATTR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_ATTR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_ATTR_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_ATTR_data_holes[1];

// _EXIT_TRACEplus_DELETE_DEREF
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_DEREF.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_DEREF_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_DEREF_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_DEREF_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_DEREF_data_holes[1];

// _EXIT_TRACEplus_DELETE_FAST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_FAST.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_FAST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_FAST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_FAST_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_FAST_data_holes[1];

// _EXIT_TRACEplus_DELETE_GLOBAL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_GLOBAL.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_GLOBAL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_GLOBAL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_GLOBAL_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_GLOBAL_data_holes[1];

// _EXIT_TRACEplus_DELETE_NAME
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_NAME.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_NAME_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_NAME_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_NAME_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_NAME_data_holes[1];

// _EXIT_TRACEplus_DELETE_SUBSCR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DELETE_SUBSCR.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DELETE_SUBSCR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DELETE_SUBSCR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DELETE_SUBSCR_data_body[1];
static const Hole _EXIT_TRACEplus_DELETE_SUBSCR_data_holes[1];

// _EXIT_TRACEplus_DICT_MERGE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DICT_MERGE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DICT_MERGE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DICT_MERGE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DICT_MERGE_data_body[1];
static const Hole _EXIT_TRACEplus_DICT_MERGE_data_holes[1];

// _EXIT_TRACEplus_DICT_UPDATE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_DICT_UPDATE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_DICT_UPDATE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_DICT_UPDATE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_DICT_UPDATE_data_body[1];
static const Hole _EXIT_TRACEplus_DICT_UPDATE_data_holes[1];

// _EXIT_TRACEplus_END_SEND
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_END_SEND.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_END_SEND_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_END_SEND_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_END_SEND_data_body[1];
static const Hole _EXIT_TRACEplus_END_SEND_data_holes[1];

// _EXIT_TRACEplus_EXIT_INIT_CHECK
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_EXIT_INIT_CHECK.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_EXIT_INIT_CHECK_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_EXIT_INIT_CHECK_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_EXIT_INIT_CHECK_data_body[1];
static const Hole _EXIT_TRACEplus_EXIT_INIT_CHECK_data_holes[1];

// _EXIT_TRACEplus_EXIT_TRACE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_EXIT_TRACE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_EXIT_TRACE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_EXIT_TRACE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_EXIT_TRACE_data_body[1];
static const Hole _EXIT_TRACEplus_EXIT_TRACE_data_holes[1];

// _EXIT_TRACEplus_FORMAT_SIMPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_FORMAT_SIMPLE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_FORMAT_SIMPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_FORMAT_SIMPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_FORMAT_SIMPLE_data_body[1];
static const Hole _EXIT_TRACEplus_FORMAT_SIMPLE_data_holes[1];

// _EXIT_TRACEplus_FORMAT_WITH_SPEC
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_FORMAT_WITH_SPEC.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_FORMAT_WITH_SPEC_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_FORMAT_WITH_SPEC_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_FORMAT_WITH_SPEC_data_body[1];
static const Hole _EXIT_TRACEplus_FORMAT_WITH_SPEC_data_holes[1];

// _EXIT_TRACEplus_FOR_ITER_TIER_TWO
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_FOR_ITER_TIER_TWO.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_FOR_ITER_TIER_TWO_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_FOR_ITER_TIER_TWO_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_FOR_ITER_TIER_TWO_data_body[1];
static const Hole _EXIT_TRACEplus_FOR_ITER_TIER_TWO_data_holes[1];

// _EXIT_TRACEplus_GET_AITER
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_AITER.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_AITER_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_AITER_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_AITER_data_body[1];
static const Hole _EXIT_TRACEplus_GET_AITER_data_holes[1];

// _EXIT_TRACEplus_GET_ANEXT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_ANEXT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_ANEXT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_ANEXT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_ANEXT_data_body[1];
static const Hole _EXIT_TRACEplus_GET_ANEXT_data_holes[1];

// _EXIT_TRACEplus_GET_AWAITABLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_AWAITABLE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_AWAITABLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_AWAITABLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_AWAITABLE_data_body[1];
static const Hole _EXIT_TRACEplus_GET_AWAITABLE_data_holes[1];

// _EXIT_TRACEplus_GET_ITER
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_ITER.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_ITER_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_ITER_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_ITER_data_body[1];
static const Hole _EXIT_TRACEplus_GET_ITER_data_holes[1];

// _EXIT_TRACEplus_GET_LEN
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_LEN.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_LEN_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_LEN_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_LEN_data_body[1];
static const Hole _EXIT_TRACEplus_GET_LEN_data_holes[1];

// _EXIT_TRACEplus_GET_YIELD_FROM_ITER
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GET_YIELD_FROM_ITER.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GET_YIELD_FROM_ITER_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GET_YIELD_FROM_ITER_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GET_YIELD_FROM_ITER_data_body[1];
static const Hole _EXIT_TRACEplus_GET_YIELD_FROM_ITER_data_holes[1];

// _EXIT_TRACEplus_GUARD_BOTH_FLOAT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_BOTH_FLOAT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_FLOAT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_BOTH_FLOAT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_FLOAT_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_BOTH_FLOAT_data_holes[1];

// _EXIT_TRACEplus_GUARD_BOTH_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_BOTH_INT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_BOTH_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_INT_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_BOTH_INT_data_holes[1];

// _EXIT_TRACEplus_GUARD_BOTH_UNICODE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_BOTH_UNICODE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_UNICODE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_BOTH_UNICODE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_BOTH_UNICODE_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_BOTH_UNICODE_data_holes[1];

// _EXIT_TRACEplus_GUARD_BUILTINS_VERSION
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_BUILTINS_VERSION.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_BUILTINS_VERSION_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_BUILTINS_VERSION_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_BUILTINS_VERSION_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_BUILTINS_VERSION_data_holes[1];

// _EXIT_TRACEplus_GUARD_DORV_VALUES
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_DORV_VALUES.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_DORV_VALUES_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_DORV_VALUES_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_DORV_VALUES_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_DORV_VALUES_data_holes[1];

// _EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT_data_holes[1];

// _EXIT_TRACEplus_GUARD_GLOBALS_VERSION
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_GLOBALS_VERSION.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_GLOBALS_VERSION_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_GLOBALS_VERSION_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_GLOBALS_VERSION_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_GLOBALS_VERSION_data_holes[1];

// _EXIT_TRACEplus_GUARD_IS_FALSE_POP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_IS_FALSE_POP.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_FALSE_POP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_IS_FALSE_POP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_FALSE_POP_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_IS_FALSE_POP_data_holes[1];

// _EXIT_TRACEplus_GUARD_IS_NONE_POP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_IS_NONE_POP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_NONE_POP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_IS_NONE_POP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_NONE_POP_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_IS_NONE_POP_data_holes[1];

// _EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP_data_holes[1];

// _EXIT_TRACEplus_GUARD_IS_TRUE_POP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_IS_TRUE_POP.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_TRUE_POP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_IS_TRUE_POP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_IS_TRUE_POP_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_IS_TRUE_POP_data_holes[1];

// _EXIT_TRACEplus_GUARD_KEYS_VERSION
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_KEYS_VERSION.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_KEYS_VERSION_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_KEYS_VERSION_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_KEYS_VERSION_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_KEYS_VERSION_data_holes[1];

// _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST_data_holes[1];

// _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE_data_holes[1];

// _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE_data_holes[1];

// _EXIT_TRACEplus_GUARD_TYPE_VERSION
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_GUARD_TYPE_VERSION.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_GUARD_TYPE_VERSION_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_GUARD_TYPE_VERSION_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_GUARD_TYPE_VERSION_data_body[1];
static const Hole _EXIT_TRACEplus_GUARD_TYPE_VERSION_data_holes[1];

// _EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_data_body[1];
static const Hole _EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS_data_holes[1];

// _EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS_data_body[1];
static const Hole _EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS_data_holes[1];

// _EXIT_TRACEplus_INSERT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_INSERT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_INSERT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_INSERT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_INSERT_data_body[1];
static const Hole _EXIT_TRACEplus_INSERT_data_holes[1];

// _EXIT_TRACEplus_IS_NONE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_IS_NONE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_IS_NONE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_IS_NONE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_IS_NONE_data_body[1];
static const Hole _EXIT_TRACEplus_IS_NONE_data_holes[1];

// _EXIT_TRACEplus_IS_OP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_IS_OP.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_IS_OP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_IS_OP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_IS_OP_data_body[1];
static const Hole _EXIT_TRACEplus_IS_OP_data_holes[1];

// _EXIT_TRACEplus_ITER_CHECK_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_CHECK_LIST.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_CHECK_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_CHECK_LIST_data_holes[1];

// _EXIT_TRACEplus_ITER_CHECK_RANGE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_CHECK_RANGE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_RANGE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_CHECK_RANGE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_RANGE_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_CHECK_RANGE_data_holes[1];

// _EXIT_TRACEplus_ITER_CHECK_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_CHECK_TUPLE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_CHECK_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_CHECK_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_CHECK_TUPLE_data_holes[1];

// _EXIT_TRACEplus_ITER_NEXT_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_NEXT_LIST.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_NEXT_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_NEXT_LIST_data_holes[1];

// _EXIT_TRACEplus_ITER_NEXT_RANGE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_NEXT_RANGE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_RANGE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_NEXT_RANGE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_RANGE_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_NEXT_RANGE_data_holes[1];

// _EXIT_TRACEplus_ITER_NEXT_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_ITER_NEXT_TUPLE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_ITER_NEXT_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_ITER_NEXT_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_ITER_NEXT_TUPLE_data_holes[1];

// _EXIT_TRACEplus_JUMP_TO_TOP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_JUMP_TO_TOP.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_JUMP_TO_TOP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_JUMP_TO_TOP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_JUMP_TO_TOP_data_body[1];
static const Hole _EXIT_TRACEplus_JUMP_TO_TOP_data_holes[1];

// _EXIT_TRACEplus_LIST_APPEND
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LIST_APPEND.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LIST_APPEND_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LIST_APPEND_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LIST_APPEND_data_body[1];
static const Hole _EXIT_TRACEplus_LIST_APPEND_data_holes[1];

// _EXIT_TRACEplus_LIST_EXTEND
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LIST_EXTEND.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LIST_EXTEND_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LIST_EXTEND_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LIST_EXTEND_data_body[1];
static const Hole _EXIT_TRACEplus_LIST_EXTEND_data_holes[1];

// _EXIT_TRACEplus_LOAD_ASSERTION_ERROR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ASSERTION_ERROR.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ASSERTION_ERROR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ASSERTION_ERROR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ASSERTION_ERROR_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ASSERTION_ERROR_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_CLASS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_CLASS.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_CLASS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_CLASS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_CLASS_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_CLASS_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_MODULE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_MODULE.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_MODULE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_MODULE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_MODULE_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_MODULE_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_SLOT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_SLOT.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_SLOT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_SLOT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_SLOT_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_SLOT_data_holes[1];

// _EXIT_TRACEplus_LOAD_ATTR_WITH_HINT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_ATTR_WITH_HINT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_WITH_HINT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_ATTR_WITH_HINT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_ATTR_WITH_HINT_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_ATTR_WITH_HINT_data_holes[1];

// _EXIT_TRACEplus_LOAD_BUILD_CLASS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_BUILD_CLASS.o:    file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_BUILD_CLASS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_BUILD_CLASS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_BUILD_CLASS_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_BUILD_CLASS_data_holes[1];

// _EXIT_TRACEplus_LOAD_CONST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_CONST.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_CONST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_CONST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_CONST_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_CONST_data_holes[1];

// _EXIT_TRACEplus_LOAD_DEREF
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_DEREF.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_DEREF_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_DEREF_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_DEREF_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_DEREF_data_holes[1];

// _EXIT_TRACEplus_LOAD_FAST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_FAST.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_FAST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_FAST_data_holes[1];

// _EXIT_TRACEplus_LOAD_FAST_AND_CLEAR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_FAST_AND_CLEAR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_AND_CLEAR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_FAST_AND_CLEAR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_AND_CLEAR_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_FAST_AND_CLEAR_data_holes[1];

// _EXIT_TRACEplus_LOAD_FAST_CHECK
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_FAST_CHECK.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_CHECK_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_FAST_CHECK_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_FAST_CHECK_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_FAST_CHECK_data_holes[1];

// _EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF_data_holes[1];

// _EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS_data_holes[1];

// _EXIT_TRACEplus_LOAD_GLOBAL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_GLOBAL.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_data_holes[1];

// _EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS_data_holes[1];

// _EXIT_TRACEplus_LOAD_GLOBAL_MODULE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_GLOBAL_MODULE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_MODULE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_MODULE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_GLOBAL_MODULE_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_GLOBAL_MODULE_data_holes[1];

// _EXIT_TRACEplus_LOAD_LOCALS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_LOCALS.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_LOCALS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_LOCALS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_LOCALS_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_LOCALS_data_holes[1];

// _EXIT_TRACEplus_LOAD_NAME
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_NAME.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_NAME_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_NAME_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_NAME_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_NAME_data_holes[1];

// _EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR_data_holes[1];

// _EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD_data_body[1];
static const Hole _EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD_data_holes[1];

// _EXIT_TRACEplus_MAKE_CELL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MAKE_CELL.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MAKE_CELL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MAKE_CELL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MAKE_CELL_data_body[1];
static const Hole _EXIT_TRACEplus_MAKE_CELL_data_holes[1];

// _EXIT_TRACEplus_MAKE_FUNCTION
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MAKE_FUNCTION.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MAKE_FUNCTION_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MAKE_FUNCTION_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MAKE_FUNCTION_data_body[1];
static const Hole _EXIT_TRACEplus_MAKE_FUNCTION_data_holes[1];

// _EXIT_TRACEplus_MAP_ADD
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MAP_ADD.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MAP_ADD_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MAP_ADD_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MAP_ADD_data_body[1];
static const Hole _EXIT_TRACEplus_MAP_ADD_data_holes[1];

// _EXIT_TRACEplus_MATCH_CLASS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MATCH_CLASS.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MATCH_CLASS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MATCH_CLASS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MATCH_CLASS_data_body[1];
static const Hole _EXIT_TRACEplus_MATCH_CLASS_data_holes[1];

// _EXIT_TRACEplus_MATCH_KEYS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MATCH_KEYS.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MATCH_KEYS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MATCH_KEYS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MATCH_KEYS_data_body[1];
static const Hole _EXIT_TRACEplus_MATCH_KEYS_data_holes[1];

// _EXIT_TRACEplus_MATCH_MAPPING
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MATCH_MAPPING.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MATCH_MAPPING_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MATCH_MAPPING_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MATCH_MAPPING_data_body[1];
static const Hole _EXIT_TRACEplus_MATCH_MAPPING_data_holes[1];

// _EXIT_TRACEplus_MATCH_SEQUENCE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_MATCH_SEQUENCE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_MATCH_SEQUENCE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_MATCH_SEQUENCE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_MATCH_SEQUENCE_data_body[1];
static const Hole _EXIT_TRACEplus_MATCH_SEQUENCE_data_holes[1];

// _EXIT_TRACEplus_NOP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_NOP.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_NOP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_NOP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_NOP_data_body[1];
static const Hole _EXIT_TRACEplus_NOP_data_holes[1];

// _EXIT_TRACEplus_POP_EXCEPT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_POP_EXCEPT.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_POP_EXCEPT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_POP_EXCEPT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_POP_EXCEPT_data_body[1];
static const Hole _EXIT_TRACEplus_POP_EXCEPT_data_holes[1];

// _EXIT_TRACEplus_POP_FRAME
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_POP_FRAME.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_POP_FRAME_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_POP_FRAME_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_POP_FRAME_data_body[1];
static const Hole _EXIT_TRACEplus_POP_FRAME_data_holes[1];

// _EXIT_TRACEplus_POP_TOP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_POP_TOP.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_POP_TOP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_POP_TOP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_POP_TOP_data_body[1];
static const Hole _EXIT_TRACEplus_POP_TOP_data_holes[1];

// _EXIT_TRACEplus_PUSH_EXC_INFO
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_PUSH_EXC_INFO.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_PUSH_EXC_INFO_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_PUSH_EXC_INFO_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_PUSH_EXC_INFO_data_body[1];
static const Hole _EXIT_TRACEplus_PUSH_EXC_INFO_data_holes[1];

// _EXIT_TRACEplus_PUSH_FRAME
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_PUSH_FRAME.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_PUSH_FRAME_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_PUSH_FRAME_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_PUSH_FRAME_data_body[1];
static const Hole _EXIT_TRACEplus_PUSH_FRAME_data_holes[1];

// _EXIT_TRACEplus_PUSH_NULL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_PUSH_NULL.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_PUSH_NULL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_PUSH_NULL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_PUSH_NULL_data_body[1];
static const Hole _EXIT_TRACEplus_PUSH_NULL_data_holes[1];

// _EXIT_TRACEplus_RESUME_CHECK
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_RESUME_CHECK.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_RESUME_CHECK_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_RESUME_CHECK_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_RESUME_CHECK_data_body[1];
static const Hole _EXIT_TRACEplus_RESUME_CHECK_data_holes[1];

// _EXIT_TRACEplus_SAVE_RETURN_OFFSET
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SAVE_RETURN_OFFSET.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SAVE_RETURN_OFFSET_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SAVE_RETURN_OFFSET_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SAVE_RETURN_OFFSET_data_body[1];
static const Hole _EXIT_TRACEplus_SAVE_RETURN_OFFSET_data_holes[1];

// _EXIT_TRACEplus_SETUP_ANNOTATIONS
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SETUP_ANNOTATIONS.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SETUP_ANNOTATIONS_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SETUP_ANNOTATIONS_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SETUP_ANNOTATIONS_data_body[1];
static const Hole _EXIT_TRACEplus_SETUP_ANNOTATIONS_data_holes[1];

// _EXIT_TRACEplus_SET_ADD
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SET_ADD.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SET_ADD_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SET_ADD_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SET_ADD_data_body[1];
static const Hole _EXIT_TRACEplus_SET_ADD_data_holes[1];

// _EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE_data_body[1];
static const Hole _EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE_data_holes[1];

// _EXIT_TRACEplus_SET_IP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SET_IP.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SET_IP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SET_IP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SET_IP_data_body[1];
static const Hole _EXIT_TRACEplus_SET_IP_data_holes[1];

// _EXIT_TRACEplus_SET_UPDATE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SET_UPDATE.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SET_UPDATE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SET_UPDATE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SET_UPDATE_data_body[1];
static const Hole _EXIT_TRACEplus_SET_UPDATE_data_holes[1];

// _EXIT_TRACEplus_STORE_ATTR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_ATTR.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_ATTR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_ATTR_data_holes[1];

// _EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE_data_holes[1];

// _EXIT_TRACEplus_STORE_ATTR_SLOT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_ATTR_SLOT.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_SLOT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_ATTR_SLOT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_ATTR_SLOT_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_ATTR_SLOT_data_holes[1];

// _EXIT_TRACEplus_STORE_DEREF
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_DEREF.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_DEREF_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_DEREF_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_DEREF_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_DEREF_data_holes[1];

// _EXIT_TRACEplus_STORE_FAST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_FAST.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_FAST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_FAST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_FAST_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_FAST_data_holes[1];

// _EXIT_TRACEplus_STORE_GLOBAL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_GLOBAL.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_GLOBAL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_GLOBAL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_GLOBAL_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_GLOBAL_data_holes[1];

// _EXIT_TRACEplus_STORE_NAME
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_NAME.o:  file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_NAME_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_NAME_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_NAME_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_NAME_data_holes[1];

// _EXIT_TRACEplus_STORE_SLICE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_SLICE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_SLICE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_SLICE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_SLICE_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_SLICE_data_holes[1];

// _EXIT_TRACEplus_STORE_SUBSCR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_SUBSCR.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_data_holes[1];

// _EXIT_TRACEplus_STORE_SUBSCR_DICT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_SUBSCR_DICT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_DICT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_DICT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_DICT_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_DICT_data_holes[1];

// _EXIT_TRACEplus_STORE_SUBSCR_LIST_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_STORE_SUBSCR_LIST_INT.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_LIST_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_LIST_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_STORE_SUBSCR_LIST_INT_data_body[1];
static const Hole _EXIT_TRACEplus_STORE_SUBSCR_LIST_INT_data_holes[1];

// _EXIT_TRACEplus_SWAP
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_SWAP.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_SWAP_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_SWAP_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_SWAP_data_body[1];
static const Hole _EXIT_TRACEplus_SWAP_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_BOOL
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_BOOL.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_BOOL_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_BOOL_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_BOOL_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_BOOL_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_INT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_INT.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_INT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_INT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_INT_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_INT_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_LIST.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_LIST_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_NONE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_NONE.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_NONE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_NONE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_NONE_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_NONE_data_holes[1];

// _EXIT_TRACEplus_TO_BOOL_STR
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_TO_BOOL_STR.o: file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_STR_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_TO_BOOL_STR_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_TO_BOOL_STR_data_body[1];
static const Hole _EXIT_TRACEplus_TO_BOOL_STR_data_holes[1];

// _EXIT_TRACEplus_UNARY_INVERT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNARY_INVERT.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNARY_INVERT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNARY_INVERT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNARY_INVERT_data_body[1];
static const Hole _EXIT_TRACEplus_UNARY_INVERT_data_holes[1];

// _EXIT_TRACEplus_UNARY_NEGATIVE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNARY_NEGATIVE.o:      file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNARY_NEGATIVE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNARY_NEGATIVE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNARY_NEGATIVE_data_body[1];
static const Hole _EXIT_TRACEplus_UNARY_NEGATIVE_data_holes[1];

// _EXIT_TRACEplus_UNARY_NOT
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNARY_NOT.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNARY_NOT_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNARY_NOT_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNARY_NOT_data_body[1];
static const Hole _EXIT_TRACEplus_UNARY_NOT_data_holes[1];

// _EXIT_TRACEplus_UNPACK_EX
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNPACK_EX.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNPACK_EX_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNPACK_EX_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNPACK_EX_data_body[1];
static const Hole _EXIT_TRACEplus_UNPACK_EX_data_holes[1];

// _EXIT_TRACEplus_UNPACK_SEQUENCE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNPACK_SEQUENCE.o:     file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_data_body[1];
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_data_holes[1];

// _EXIT_TRACEplus_UNPACK_SEQUENCE_LIST
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNPACK_SEQUENCE_LIST.o:        file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_LIST_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_LIST_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_LIST_data_body[1];
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_LIST_data_holes[1];

// _EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE.o:       file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE_data_holes[1];

// _EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE_data_body[1];
static const Hole _EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE_data_holes[1];

// _EXIT_TRACEplus_WITH_EXCEPT_START
// 
// /tmp/tmpdqjc2jsw/_EXIT_TRACEplus_WITH_EXCEPT_START.o:   file format elf64-x86-64
// 
// Disassembly of section .text:
// 
// 0000000000000000 <_JIT_ENTRY>:
// 0: 48 29 fe                      subq    %rdi, %rsi
// 3: 48 83 c6 b8                   addq    $-0x48, %rsi
// 7: 48 c1 ee 03                   shrq    $0x3, %rsi
// b: 89 77 40                      movl    %esi, 0x40(%rdi)
// e: 48 8b 07                      movq    (%rdi), %rax
// 11: 48 b9 00 00 00 00 00 00 00 00 movabsq $0x0, %rcx
// 0000000000000013:  R_X86_64_64  _JIT_TARGET
// 1b: 89 c9                         movl    %ecx, %ecx
// 1d: 48 8d 04 48                   leaq    (%rax,%rcx,2), %rax
// 21: 48 05 c8 00 00 00             addq    $0xc8, %rax
// 27: c3                            retq
// 28: 
static const unsigned char _EXIT_TRACEplus_WITH_EXCEPT_START_code_body[41] = {0x48, 0x29, 0xfe, 0x48, 0x83, 0xc6, 0xb8, 0x48, 0xc1, 0xee, 0x03, 0x89, 0x77, 0x40, 0x48, 0x8b, 0x07, 0x48, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0xc9, 0x48, 0x8d, 0x04, 0x48, 0x48, 0x05, 0xc8, 0x00, 0x00, 0x00, 0xc3};
static const Hole _EXIT_TRACEplus_WITH_EXCEPT_START_code_holes[2] = {
    {0x13, HoleKind_R_X86_64_64, HoleValue_TARGET, NULL, 0x0},
};
// 0: 
static const unsigned char _EXIT_TRACEplus_WITH_EXCEPT_START_data_body[1];
static const Hole _EXIT_TRACEplus_WITH_EXCEPT_START_data_holes[1];

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
    [_EXIT_TRACEplus_BEFORE_ASYNC_WITH] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BEFORE_ASYNC_WITH),
    [_EXIT_TRACEplus_BEFORE_WITH] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BEFORE_WITH),
    [_EXIT_TRACEplus_BINARY_OP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP),
    [_EXIT_TRACEplus_BINARY_OP_ADD_FLOAT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_ADD_FLOAT),
    [_EXIT_TRACEplus_BINARY_OP_ADD_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_ADD_INT),
    [_EXIT_TRACEplus_BINARY_OP_ADD_UNICODE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_ADD_UNICODE),
    [_EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_MULTIPLY_FLOAT),
    [_EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_MULTIPLY_INT),
    [_EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_SUBTRACT_FLOAT),
    [_EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_OP_SUBTRACT_INT),
    [_EXIT_TRACEplus_BINARY_SLICE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SLICE),
    [_EXIT_TRACEplus_BINARY_SUBSCR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SUBSCR),
    [_EXIT_TRACEplus_BINARY_SUBSCR_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SUBSCR_DICT),
    [_EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SUBSCR_LIST_INT),
    [_EXIT_TRACEplus_BINARY_SUBSCR_STR_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SUBSCR_STR_INT),
    [_EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BINARY_SUBSCR_TUPLE_INT),
    [_EXIT_TRACEplus_BUILD_CONST_KEY_MAP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_CONST_KEY_MAP),
    [_EXIT_TRACEplus_BUILD_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_LIST),
    [_EXIT_TRACEplus_BUILD_MAP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_MAP),
    [_EXIT_TRACEplus_BUILD_SET] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_SET),
    [_EXIT_TRACEplus_BUILD_SLICE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_SLICE),
    [_EXIT_TRACEplus_BUILD_STRING] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_STRING),
    [_EXIT_TRACEplus_BUILD_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_BUILD_TUPLE),
    [_EXIT_TRACEplus_CALL_BUILTIN_CLASS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_BUILTIN_CLASS),
    [_EXIT_TRACEplus_CALL_BUILTIN_FAST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_BUILTIN_FAST),
    [_EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_BUILTIN_FAST_WITH_KEYWORDS),
    [_EXIT_TRACEplus_CALL_BUILTIN_O] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_BUILTIN_O),
    [_EXIT_TRACEplus_CALL_INTRINSIC_1] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_INTRINSIC_1),
    [_EXIT_TRACEplus_CALL_INTRINSIC_2] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_INTRINSIC_2),
    [_EXIT_TRACEplus_CALL_ISINSTANCE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_ISINSTANCE),
    [_EXIT_TRACEplus_CALL_LEN] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_LEN),
    [_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST),
    [_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_FAST_WITH_KEYWORDS),
    [_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_NOARGS),
    [_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_METHOD_DESCRIPTOR_O),
    [_EXIT_TRACEplus_CALL_STR_1] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_STR_1),
    [_EXIT_TRACEplus_CALL_TUPLE_1] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_TUPLE_1),
    [_EXIT_TRACEplus_CALL_TYPE_1] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CALL_TYPE_1),
    [_EXIT_TRACEplus_CHECK_ATTR_CLASS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_ATTR_CLASS),
    [_EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_ATTR_METHOD_LAZY_DICT),
    [_EXIT_TRACEplus_CHECK_ATTR_MODULE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_ATTR_MODULE),
    [_EXIT_TRACEplus_CHECK_ATTR_WITH_HINT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_ATTR_WITH_HINT),
    [_EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_CALL_BOUND_METHOD_EXACT_ARGS),
    [_EXIT_TRACEplus_CHECK_EG_MATCH] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_EG_MATCH),
    [_EXIT_TRACEplus_CHECK_EXC_MATCH] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_EXC_MATCH),
    [_EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_FUNCTION_EXACT_ARGS),
    [_EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_MANAGED_OBJECT_HAS_VALUES),
    [_EXIT_TRACEplus_CHECK_PEP_523] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_PEP_523),
    [_EXIT_TRACEplus_CHECK_STACK_SPACE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_STACK_SPACE),
    [_EXIT_TRACEplus_CHECK_VALIDITY] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CHECK_VALIDITY),
    [_EXIT_TRACEplus_COMPARE_OP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COMPARE_OP),
    [_EXIT_TRACEplus_COMPARE_OP_FLOAT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COMPARE_OP_FLOAT),
    [_EXIT_TRACEplus_COMPARE_OP_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COMPARE_OP_INT),
    [_EXIT_TRACEplus_COMPARE_OP_STR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COMPARE_OP_STR),
    [_EXIT_TRACEplus_CONTAINS_OP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CONTAINS_OP),
    [_EXIT_TRACEplus_CONVERT_VALUE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_CONVERT_VALUE),
    [_EXIT_TRACEplus_COPY] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COPY),
    [_EXIT_TRACEplus_COPY_FREE_VARS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_COPY_FREE_VARS),
    [_EXIT_TRACEplus_DELETE_ATTR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_ATTR),
    [_EXIT_TRACEplus_DELETE_DEREF] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_DEREF),
    [_EXIT_TRACEplus_DELETE_FAST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_FAST),
    [_EXIT_TRACEplus_DELETE_GLOBAL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_GLOBAL),
    [_EXIT_TRACEplus_DELETE_NAME] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_NAME),
    [_EXIT_TRACEplus_DELETE_SUBSCR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DELETE_SUBSCR),
    [_EXIT_TRACEplus_DICT_MERGE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DICT_MERGE),
    [_EXIT_TRACEplus_DICT_UPDATE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_DICT_UPDATE),
    [_EXIT_TRACEplus_END_SEND] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_END_SEND),
    [_EXIT_TRACEplus_EXIT_INIT_CHECK] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_EXIT_INIT_CHECK),
    [_EXIT_TRACEplus_EXIT_TRACE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_EXIT_TRACE),
    [_EXIT_TRACEplus_FORMAT_SIMPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_FORMAT_SIMPLE),
    [_EXIT_TRACEplus_FORMAT_WITH_SPEC] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_FORMAT_WITH_SPEC),
    [_EXIT_TRACEplus_FOR_ITER_TIER_TWO] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_FOR_ITER_TIER_TWO),
    [_EXIT_TRACEplus_GET_AITER] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_AITER),
    [_EXIT_TRACEplus_GET_ANEXT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_ANEXT),
    [_EXIT_TRACEplus_GET_AWAITABLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_AWAITABLE),
    [_EXIT_TRACEplus_GET_ITER] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_ITER),
    [_EXIT_TRACEplus_GET_LEN] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_LEN),
    [_EXIT_TRACEplus_GET_YIELD_FROM_ITER] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GET_YIELD_FROM_ITER),
    [_EXIT_TRACEplus_GUARD_BOTH_FLOAT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_BOTH_FLOAT),
    [_EXIT_TRACEplus_GUARD_BOTH_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_BOTH_INT),
    [_EXIT_TRACEplus_GUARD_BOTH_UNICODE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_BOTH_UNICODE),
    [_EXIT_TRACEplus_GUARD_BUILTINS_VERSION] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_BUILTINS_VERSION),
    [_EXIT_TRACEplus_GUARD_DORV_VALUES] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_DORV_VALUES),
    [_EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_DORV_VALUES_INST_ATTR_FROM_DICT),
    [_EXIT_TRACEplus_GUARD_GLOBALS_VERSION] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_GLOBALS_VERSION),
    [_EXIT_TRACEplus_GUARD_IS_FALSE_POP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_IS_FALSE_POP),
    [_EXIT_TRACEplus_GUARD_IS_NONE_POP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_IS_NONE_POP),
    [_EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_IS_NOT_NONE_POP),
    [_EXIT_TRACEplus_GUARD_IS_TRUE_POP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_IS_TRUE_POP),
    [_EXIT_TRACEplus_GUARD_KEYS_VERSION] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_KEYS_VERSION),
    [_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_LIST),
    [_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_RANGE),
    [_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_NOT_EXHAUSTED_TUPLE),
    [_EXIT_TRACEplus_GUARD_TYPE_VERSION] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_GUARD_TYPE_VERSION),
    [_EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_INIT_CALL_BOUND_METHOD_EXACT_ARGS),
    [_EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_INIT_CALL_PY_EXACT_ARGS),
    [_EXIT_TRACEplus_INSERT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_INSERT),
    [_EXIT_TRACEplus_IS_NONE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_IS_NONE),
    [_EXIT_TRACEplus_IS_OP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_IS_OP),
    [_EXIT_TRACEplus_ITER_CHECK_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_CHECK_LIST),
    [_EXIT_TRACEplus_ITER_CHECK_RANGE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_CHECK_RANGE),
    [_EXIT_TRACEplus_ITER_CHECK_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_CHECK_TUPLE),
    [_EXIT_TRACEplus_ITER_NEXT_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_NEXT_LIST),
    [_EXIT_TRACEplus_ITER_NEXT_RANGE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_NEXT_RANGE),
    [_EXIT_TRACEplus_ITER_NEXT_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_ITER_NEXT_TUPLE),
    [_EXIT_TRACEplus_JUMP_TO_TOP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_JUMP_TO_TOP),
    [_EXIT_TRACEplus_LIST_APPEND] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LIST_APPEND),
    [_EXIT_TRACEplus_LIST_EXTEND] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LIST_EXTEND),
    [_EXIT_TRACEplus_LOAD_ASSERTION_ERROR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ASSERTION_ERROR),
    [_EXIT_TRACEplus_LOAD_ATTR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR),
    [_EXIT_TRACEplus_LOAD_ATTR_CLASS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_CLASS),
    [_EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_INSTANCE_VALUE),
    [_EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_METHOD_LAZY_DICT),
    [_EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_METHOD_NO_DICT),
    [_EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_METHOD_WITH_VALUES),
    [_EXIT_TRACEplus_LOAD_ATTR_MODULE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_MODULE),
    [_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_NO_DICT),
    [_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_NONDESCRIPTOR_WITH_VALUES),
    [_EXIT_TRACEplus_LOAD_ATTR_SLOT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_SLOT),
    [_EXIT_TRACEplus_LOAD_ATTR_WITH_HINT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_ATTR_WITH_HINT),
    [_EXIT_TRACEplus_LOAD_BUILD_CLASS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_BUILD_CLASS),
    [_EXIT_TRACEplus_LOAD_CONST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_CONST),
    [_EXIT_TRACEplus_LOAD_DEREF] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_DEREF),
    [_EXIT_TRACEplus_LOAD_FAST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_FAST),
    [_EXIT_TRACEplus_LOAD_FAST_AND_CLEAR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_FAST_AND_CLEAR),
    [_EXIT_TRACEplus_LOAD_FAST_CHECK] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_FAST_CHECK),
    [_EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_FROM_DICT_OR_DEREF),
    [_EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_FROM_DICT_OR_GLOBALS),
    [_EXIT_TRACEplus_LOAD_GLOBAL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_GLOBAL),
    [_EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_GLOBAL_BUILTINS),
    [_EXIT_TRACEplus_LOAD_GLOBAL_MODULE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_GLOBAL_MODULE),
    [_EXIT_TRACEplus_LOAD_LOCALS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_LOCALS),
    [_EXIT_TRACEplus_LOAD_NAME] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_NAME),
    [_EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_SUPER_ATTR_ATTR),
    [_EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_LOAD_SUPER_ATTR_METHOD),
    [_EXIT_TRACEplus_MAKE_CELL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MAKE_CELL),
    [_EXIT_TRACEplus_MAKE_FUNCTION] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MAKE_FUNCTION),
    [_EXIT_TRACEplus_MAP_ADD] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MAP_ADD),
    [_EXIT_TRACEplus_MATCH_CLASS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MATCH_CLASS),
    [_EXIT_TRACEplus_MATCH_KEYS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MATCH_KEYS),
    [_EXIT_TRACEplus_MATCH_MAPPING] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MATCH_MAPPING),
    [_EXIT_TRACEplus_MATCH_SEQUENCE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_MATCH_SEQUENCE),
    [_EXIT_TRACEplus_NOP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_NOP),
    [_EXIT_TRACEplus_POP_EXCEPT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_POP_EXCEPT),
    [_EXIT_TRACEplus_POP_FRAME] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_POP_FRAME),
    [_EXIT_TRACEplus_POP_TOP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_POP_TOP),
    [_EXIT_TRACEplus_PUSH_EXC_INFO] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_PUSH_EXC_INFO),
    [_EXIT_TRACEplus_PUSH_FRAME] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_PUSH_FRAME),
    [_EXIT_TRACEplus_PUSH_NULL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_PUSH_NULL),
    [_EXIT_TRACEplus_RESUME_CHECK] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_RESUME_CHECK),
    [_EXIT_TRACEplus_SAVE_RETURN_OFFSET] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SAVE_RETURN_OFFSET),
    [_EXIT_TRACEplus_SETUP_ANNOTATIONS] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SETUP_ANNOTATIONS),
    [_EXIT_TRACEplus_SET_ADD] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SET_ADD),
    [_EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SET_FUNCTION_ATTRIBUTE),
    [_EXIT_TRACEplus_SET_IP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SET_IP),
    [_EXIT_TRACEplus_SET_UPDATE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SET_UPDATE),
    [_EXIT_TRACEplus_STORE_ATTR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_ATTR),
    [_EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_ATTR_INSTANCE_VALUE),
    [_EXIT_TRACEplus_STORE_ATTR_SLOT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_ATTR_SLOT),
    [_EXIT_TRACEplus_STORE_DEREF] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_DEREF),
    [_EXIT_TRACEplus_STORE_FAST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_FAST),
    [_EXIT_TRACEplus_STORE_GLOBAL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_GLOBAL),
    [_EXIT_TRACEplus_STORE_NAME] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_NAME),
    [_EXIT_TRACEplus_STORE_SLICE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_SLICE),
    [_EXIT_TRACEplus_STORE_SUBSCR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_SUBSCR),
    [_EXIT_TRACEplus_STORE_SUBSCR_DICT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_SUBSCR_DICT),
    [_EXIT_TRACEplus_STORE_SUBSCR_LIST_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_STORE_SUBSCR_LIST_INT),
    [_EXIT_TRACEplus_SWAP] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_SWAP),
    [_EXIT_TRACEplus_TO_BOOL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL),
    [_EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_ALWAYS_TRUE),
    [_EXIT_TRACEplus_TO_BOOL_BOOL] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_BOOL),
    [_EXIT_TRACEplus_TO_BOOL_INT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_INT),
    [_EXIT_TRACEplus_TO_BOOL_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_LIST),
    [_EXIT_TRACEplus_TO_BOOL_NONE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_NONE),
    [_EXIT_TRACEplus_TO_BOOL_STR] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_TO_BOOL_STR),
    [_EXIT_TRACEplus_UNARY_INVERT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNARY_INVERT),
    [_EXIT_TRACEplus_UNARY_NEGATIVE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNARY_NEGATIVE),
    [_EXIT_TRACEplus_UNARY_NOT] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNARY_NOT),
    [_EXIT_TRACEplus_UNPACK_EX] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNPACK_EX),
    [_EXIT_TRACEplus_UNPACK_SEQUENCE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNPACK_SEQUENCE),
    [_EXIT_TRACEplus_UNPACK_SEQUENCE_LIST] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNPACK_SEQUENCE_LIST),
    [_EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNPACK_SEQUENCE_TUPLE),
    [_EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_UNPACK_SEQUENCE_TWO_TUPLE),
    [_EXIT_TRACEplus_WITH_EXCEPT_START] = INIT_STENCIL_GROUP(_EXIT_TRACEplus_WITH_EXCEPT_START),
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
