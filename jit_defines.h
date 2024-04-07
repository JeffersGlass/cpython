
// Supernode Indices
#define _SET_IPplus_STORE_NAME 440
#define _SET_IPplus_STORE_NAME_length 2
#define _SET_IPplus_GUARD_BOTH_UNICODE 441
#define _SET_IPplus_GUARD_BOTH_UNICODE_length 2
#define _GUARD_NOT_EXHAUSTED_LISTplus_ITER_NEXT_LIST 442
#define _GUARD_NOT_EXHAUSTED_LISTplus_ITER_NEXT_LIST_length 2

typedef struct {
    const uint64_t index;
    const uint16_t length;
} SuperNode;

SuperNode _JIT_INDEX(uint16_t a, uint16_t b);
#define MAX_SUPERINST_ID 442