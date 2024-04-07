
// Supernode Indices
#define _GUARD_NOT_EXHAUSTED_LISTplus_ITER_NEXT_LIST 440
#define _GUARD_NOT_EXHAUSTED_LISTplus_ITER_NEXT_LIST_length 2

typedef struct {
    const uint64_t index;
    const uint16_t length;
} SuperNode;

SuperNode _JIT_INDEX(uint16_t a, uint16_t b);
#define MAX_SUPERINST_ID 440