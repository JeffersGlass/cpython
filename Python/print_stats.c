#include "Python.h"

#include "pycore_interp_structs.h"  //NUM_GENERATIONS
#include "pycore_opcode_metadata.h" // _PyOpcode_Caches
#include "pycore_pylifecycle.h"   // _PyOS_URandomNonblock()
#include "pycore_uop_metadata.h"    // _PyOpcode_uop_nam
#include "pystats.h"


extern const char *_PyUOpName(int index);

#ifdef Py_STATS
GCStats _py_gc_stats[NUM_GENERATIONS] = { 0 };
static PyStats _Py_stats_struct = { .gc_stats = _py_gc_stats };
PyStats *_Py_stats = NULL;

#if PYSTATS_MAX_UOP_ID < MAX_UOP_ID
#error "Not enough space allocated for pystats. Increase PYSTATS_MAX_UOP_ID to at least MAX_UOP_ID"
#endif

#define ADD_STAT_TO_DICT(res, field) \
    do { \
        PyObject *val = PyLong_FromUnsignedLongLong(stats->field); \
        if (val == NULL) { \
            Py_DECREF(res); \
            return NULL; \
        } \
        if (PyDict_SetItemString(res, #field, val) == -1) { \
            Py_DECREF(res); \
            Py_DECREF(val); \
            return NULL; \
        } \
        Py_DECREF(val); \
    } while(0);

static PyObject*
stats_to_dict(SpecializationStats *stats)
{
    PyObject *res = PyDict_New();
    if (res == NULL) {
        return NULL;
    }
    ADD_STAT_TO_DICT(res, success);
    ADD_STAT_TO_DICT(res, failure);
    ADD_STAT_TO_DICT(res, hit);
    ADD_STAT_TO_DICT(res, deferred);
    ADD_STAT_TO_DICT(res, miss);
    ADD_STAT_TO_DICT(res, deopt);
    PyObject *failure_kinds = PyTuple_New(SPECIALIZATION_FAILURE_KINDS);
    if (failure_kinds == NULL) {
        Py_DECREF(res);
        return NULL;
    }
    for (int i = 0; i < SPECIALIZATION_FAILURE_KINDS; i++) {
        PyObject *stat = PyLong_FromUnsignedLongLong(stats->failure_kinds[i]);
        if (stat == NULL) {
            Py_DECREF(res);
            Py_DECREF(failure_kinds);
            return NULL;
        }
        PyTuple_SET_ITEM(failure_kinds, i, stat);
    }
    if (PyDict_SetItemString(res, "failure_kinds", failure_kinds)) {
        Py_DECREF(res);
        Py_DECREF(failure_kinds);
        return NULL;
    }
    Py_DECREF(failure_kinds);
    return res;
}
#undef ADD_STAT_TO_DICT

static int
add_stat_dict(
    PyObject *res,
    int opcode,
    const char *name) {

    SpecializationStats *stats = &_Py_stats_struct.opcode_stats[opcode].specialization;
    PyObject *d = stats_to_dict(stats);
    if (d == NULL) {
        return -1;
    }
    int err = PyDict_SetItemString(res, name, d);
    Py_DECREF(d);
    return err;
}

PyObject*
_Py_GetSpecializationStats(void) {
    PyObject *stats = PyDict_New();
    if (stats == NULL) {
        return NULL;
    }
    int err = 0;
    err += add_stat_dict(stats, CONTAINS_OP, "contains_op");
    err += add_stat_dict(stats, LOAD_SUPER_ATTR, "load_super_attr");
    err += add_stat_dict(stats, LOAD_ATTR, "load_attr");
    err += add_stat_dict(stats, LOAD_GLOBAL, "load_global");
    err += add_stat_dict(stats, STORE_SUBSCR, "store_subscr");
    err += add_stat_dict(stats, STORE_ATTR, "store_attr");
    err += add_stat_dict(stats, CALL, "call");
    err += add_stat_dict(stats, CALL_KW, "call_kw");
    err += add_stat_dict(stats, BINARY_OP, "binary_op");
    err += add_stat_dict(stats, COMPARE_OP, "compare_op");
    err += add_stat_dict(stats, UNPACK_SEQUENCE, "unpack_sequence");
    err += add_stat_dict(stats, FOR_ITER, "for_iter");
    err += add_stat_dict(stats, TO_BOOL, "to_bool");
    err += add_stat_dict(stats, SEND, "send");
    if (err < 0) {
        Py_DECREF(stats);
        return NULL;
    }
    return stats;
}


#define PRINT_STAT(i, field) \
    if (stats[i].field) { \
        fprintf(out, "    opcode[%s]." #field " : %" PRIu64 "\n", _PyOpcode_OpName[i], stats[i].field); \
    }

static void
print_spec_stats(FILE *out, OpcodeStats *stats)
{
    /* Mark some opcodes as specializable for stats,
     * even though we don't specialize them yet. */
    fprintf(out, "opcode[BINARY_SLICE].specializable : 1\n");
    fprintf(out, "opcode[STORE_SLICE].specializable : 1\n");
    for (int i = 0; i < 256; i++) {
        if (_PyOpcode_Caches[i]) {
            /* Ignore jumps as they cannot be specialized */
            switch (i) {
                case POP_JUMP_IF_FALSE:
                case POP_JUMP_IF_TRUE:
                case POP_JUMP_IF_NONE:
                case POP_JUMP_IF_NOT_NONE:
                case JUMP_BACKWARD:
                    break;
                default:
                    fprintf(out, "opcode[%s].specializable : 1\n", _PyOpcode_OpName[i]);
            }
        }
        PRINT_STAT(i, specialization.success);
        PRINT_STAT(i, specialization.failure);
        PRINT_STAT(i, specialization.hit);
        PRINT_STAT(i, specialization.deferred);
        PRINT_STAT(i, specialization.miss);
        PRINT_STAT(i, specialization.deopt);
        PRINT_STAT(i, execution_count);
        for (int j = 0; j < SPECIALIZATION_FAILURE_KINDS; j++) {
            uint64_t val = stats[i].specialization.failure_kinds[j];
            if (val) {
                fprintf(out, "    opcode[%s].specialization.failure_kinds[%d] : %"
                    PRIu64 "\n", _PyOpcode_OpName[i], j, val);
            }
        }
        for (int j = 0; j < 256; j++) {
            if (stats[i].pair_count[j]) {
                fprintf(out, "opcode[%s].pair_count[%s] : %" PRIu64 "\n",
                        _PyOpcode_OpName[i], _PyOpcode_OpName[j], stats[i].pair_count[j]);
            }
        }
    }
}
#undef PRINT_STAT


static void
print_call_stats(FILE *out, CallStats *stats)
{
    fprintf(out, "Calls to PyEval_EvalDefault: %" PRIu64 "\n", stats->pyeval_calls);
    fprintf(out, "Calls to Python functions inlined: %" PRIu64 "\n", stats->inlined_py_calls);
    fprintf(out, "Frames pushed: %" PRIu64 "\n", stats->frames_pushed);
    fprintf(out, "Frame objects created: %" PRIu64 "\n", stats->frame_objects_created);
    for (int i = 0; i < EVAL_CALL_KINDS; i++) {
        fprintf(out, "Calls via PyEval_EvalFrame[%d] : %" PRIu64 "\n", i, stats->eval_calls[i]);
    }
}

static void
print_object_stats(FILE *out, ObjectStats *stats)
{
    fprintf(out, "Object allocations from freelist: %" PRIu64 "\n", stats->from_freelist);
    fprintf(out, "Object frees to freelist: %" PRIu64 "\n", stats->to_freelist);
    fprintf(out, "Object allocations: %" PRIu64 "\n", stats->allocations);
    fprintf(out, "Object allocations to 512 bytes: %" PRIu64 "\n", stats->allocations512);
    fprintf(out, "Object allocations to 4 kbytes: %" PRIu64 "\n", stats->allocations4k);
    fprintf(out, "Object allocations over 4 kbytes: %" PRIu64 "\n", stats->allocations_big);
    fprintf(out, "Object frees: %" PRIu64 "\n", stats->frees);
    fprintf(out, "Object inline values: %" PRIu64 "\n", stats->inline_values);
    fprintf(out, "Object interpreter mortal increfs: %" PRIu64 "\n", stats->interpreter_increfs);
    fprintf(out, "Object interpreter mortal decrefs: %" PRIu64 "\n", stats->interpreter_decrefs);
    fprintf(out, "Object mortal increfs: %" PRIu64 "\n", stats->increfs);
    fprintf(out, "Object mortal decrefs: %" PRIu64 "\n", stats->decrefs);
    fprintf(out, "Object interpreter immortal increfs: %" PRIu64 "\n", stats->interpreter_immortal_increfs);
    fprintf(out, "Object interpreter immortal decrefs: %" PRIu64 "\n", stats->interpreter_immortal_decrefs);
    fprintf(out, "Object immortal increfs: %" PRIu64 "\n", stats->immortal_increfs);
    fprintf(out, "Object immortal decrefs: %" PRIu64 "\n", stats->immortal_decrefs);
    fprintf(out, "Object materialize dict (on request): %" PRIu64 "\n", stats->dict_materialized_on_request);
    fprintf(out, "Object materialize dict (new key): %" PRIu64 "\n", stats->dict_materialized_new_key);
    fprintf(out, "Object materialize dict (too big): %" PRIu64 "\n", stats->dict_materialized_too_big);
    fprintf(out, "Object materialize dict (str subclass): %" PRIu64 "\n", stats->dict_materialized_str_subclass);
    fprintf(out, "Object method cache hits: %" PRIu64 "\n", stats->type_cache_hits);
    fprintf(out, "Object method cache misses: %" PRIu64 "\n", stats->type_cache_misses);
    fprintf(out, "Object method cache collisions: %" PRIu64 "\n", stats->type_cache_collisions);
    fprintf(out, "Object method cache dunder hits: %" PRIu64 "\n", stats->type_cache_dunder_hits);
    fprintf(out, "Object method cache dunder misses: %" PRIu64 "\n", stats->type_cache_dunder_misses);
}

static void
print_gc_stats(FILE *out, GCStats *stats)
{
    for (int i = 0; i < NUM_GENERATIONS; i++) {
        fprintf(out, "GC[%d] collections: %" PRIu64 "\n", i, stats[i].collections);
        fprintf(out, "GC[%d] object visits: %" PRIu64 "\n", i, stats[i].object_visits);
        fprintf(out, "GC[%d] objects collected: %" PRIu64 "\n", i, stats[i].objects_collected);
        fprintf(out, "GC[%d] objects reachable from roots: %" PRIu64 "\n", i, stats[i].objects_transitively_reachable);
        fprintf(out, "GC[%d] objects not reachable from roots: %" PRIu64 "\n", i, stats[i].objects_not_transitively_reachable);
    }
}

#ifdef _Py_TIER2
static void
print_histogram(FILE *out, const char *name, uint64_t hist[_Py_UOP_HIST_SIZE])
{
    for (int i = 0; i < _Py_UOP_HIST_SIZE; i++) {
        fprintf(out, "%s[%" PRIu64"]: %" PRIu64 "\n", name, (uint64_t)1 << i, hist[i]);
    }
}

static void
print_optimization_stats(FILE *out, OptimizationStats *stats)
{
    fprintf(out, "Optimization attempts: %" PRIu64 "\n", stats->attempts);
    fprintf(out, "Optimization traces created: %" PRIu64 "\n", stats->traces_created);
    fprintf(out, "Optimization traces executed: %" PRIu64 "\n", stats->traces_executed);
    fprintf(out, "Optimization uops executed: %" PRIu64 "\n", stats->uops_executed);
    fprintf(out, "Optimization trace stack overflow: %" PRIu64 "\n", stats->trace_stack_overflow);
    fprintf(out, "Optimization trace stack underflow: %" PRIu64 "\n", stats->trace_stack_underflow);
    fprintf(out, "Optimization trace too long: %" PRIu64 "\n", stats->trace_too_long);
    fprintf(out, "Optimization trace too short: %" PRIu64 "\n", stats->trace_too_short);
    fprintf(out, "Optimization inner loop: %" PRIu64 "\n", stats->inner_loop);
    fprintf(out, "Optimization recursive call: %" PRIu64 "\n", stats->recursive_call);
    fprintf(out, "Optimization low confidence: %" PRIu64 "\n", stats->low_confidence);
    fprintf(out, "Optimization unknown callee: %" PRIu64 "\n", stats->unknown_callee);
    fprintf(out, "Executors invalidated: %" PRIu64 "\n", stats->executors_invalidated);

    print_histogram(out, "Trace length", stats->trace_length_hist);
    print_histogram(out, "Trace run length", stats->trace_run_length_hist);
    print_histogram(out, "Optimized trace length", stats->optimized_trace_length_hist);

    fprintf(out, "Optimization optimizer attempts: %" PRIu64 "\n", stats->optimizer_attempts);
    fprintf(out, "Optimization optimizer successes: %" PRIu64 "\n", stats->optimizer_successes);
    fprintf(out, "Optimization optimizer failure no memory: %" PRIu64 "\n",
            stats->optimizer_failure_reason_no_memory);
    fprintf(out, "Optimizer remove globals builtins changed: %" PRIu64 "\n", stats->remove_globals_builtins_changed);
    fprintf(out, "Optimizer remove globals incorrect keys: %" PRIu64 "\n", stats->remove_globals_incorrect_keys);
    for (int i = 0; i <= MAX_UOP_ID; i++) {
        if (stats->opcode[i].execution_count) {
            fprintf(out, "uops[%s].execution_count : %" PRIu64 "\n", _PyUOpName(i), stats->opcode[i].execution_count);
        }
        if (stats->opcode[i].miss) {
            fprintf(out, "uops[%s].specialization.miss : %" PRIu64 "\n", _PyUOpName(i), stats->opcode[i].miss);
        }
    }
    for (int i = 0; i < 256; i++) {
        if (stats->unsupported_opcode[i]) {
            fprintf(
                out,
                "unsupported_opcode[%s].count : %" PRIu64 "\n",
                _PyOpcode_OpName[i],
                stats->unsupported_opcode[i]
            );
        }
    }

    for (int i = 1; i <= MAX_UOP_ID; i++){
        for (int j = 1; j <= MAX_UOP_ID; j++) {
            if (stats->opcode[i].pair_count[j]) {
                fprintf(out, "uop[%s].pair_count[%s] : %" PRIu64 "\n",
                        _PyOpcode_uop_name[i], _PyOpcode_uop_name[j], stats->opcode[i].pair_count[j]);
            }
        }
    }
    for (int i = 0; i < MAX_UOP_ID; i++) {
        if (stats->error_in_opcode[i]) {
            fprintf(
                out,
                "error_in_opcode[%s].count : %" PRIu64 "\n",
                _PyUOpName(i),
                stats->error_in_opcode[i]
            );
        }
    }
    fprintf(out, "JIT total memory size: %" PRIu64 "\n", stats->jit_total_memory_size);
    fprintf(out, "JIT code size: %" PRIu64 "\n", stats->jit_code_size);
    fprintf(out, "JIT trampoline size: %" PRIu64 "\n", stats->jit_trampoline_size);
    fprintf(out, "JIT data size: %" PRIu64 "\n", stats->jit_data_size);
    fprintf(out, "JIT padding size: %" PRIu64 "\n", stats->jit_padding_size);
    fprintf(out, "JIT freed memory size: %" PRIu64 "\n", stats->jit_freed_memory_size);

    print_histogram(out, "Trace total memory size", stats->trace_total_memory_hist);
}
#endif

static void
print_rare_event_stats(FILE *out, RareEventStats *stats)
{
    fprintf(out, "Rare event (set_class): %" PRIu64 "\n", stats->set_class);
    fprintf(out, "Rare event (set_bases): %" PRIu64 "\n", stats->set_bases);
    fprintf(out, "Rare event (set_eval_frame_func): %" PRIu64 "\n", stats->set_eval_frame_func);
    fprintf(out, "Rare event (builtin_dict): %" PRIu64 "\n", stats->builtin_dict);
    fprintf(out, "Rare event (func_modification): %" PRIu64 "\n", stats->func_modification);
    fprintf(out, "Rare event (watched_dict_modification): %" PRIu64 "\n", stats->watched_dict_modification);
    fprintf(out, "Rare event (watched_globals_modification): %" PRIu64 "\n", stats->watched_globals_modification);
}

static void
print_stats(FILE *out, PyStats *stats)
{
    print_spec_stats(out, stats->opcode_stats);
    print_call_stats(out, &stats->call_stats);
    print_object_stats(out, &stats->object_stats);
    print_gc_stats(out, stats->gc_stats);
#ifdef _Py_TIER2
    print_optimization_stats(out, &stats->optimization_stats);
#endif
    print_rare_event_stats(out, &stats->rare_event_stats);
}

void
_Py_StatsOn(void)
{
    _Py_stats = &_Py_stats_struct;
}

void
_Py_StatsOff(void)
{
    _Py_stats = NULL;
}

void
_Py_StatsClear(void)
{
    memset(&_py_gc_stats, 0, sizeof(_py_gc_stats));
    memset(&_Py_stats_struct, 0, sizeof(_Py_stats_struct));
    _Py_stats_struct.gc_stats = _py_gc_stats;
}

static int
mem_is_zero(unsigned char *ptr, size_t size)
{
    for (size_t i=0; i < size; i++) {
        if (*ptr != 0) {
            return 0;
        }
        ptr++;
    }
    return 1;
}

int
_Py_PrintSpecializationStats(int to_file)
{
    PyStats *stats = &_Py_stats_struct;
#define MEM_IS_ZERO(DATA) mem_is_zero((unsigned char*)DATA, sizeof(*(DATA)))
    int is_zero = (
        MEM_IS_ZERO(stats->gc_stats)  // is a pointer
        && MEM_IS_ZERO(&stats->opcode_stats)
        && MEM_IS_ZERO(&stats->call_stats)
        && MEM_IS_ZERO(&stats->object_stats)
    );
#undef MEM_IS_ZERO
    if (is_zero) {
        // gh-108753: -X pystats command line was used, but then _stats_off()
        // and _stats_clear() have been called: in this case, avoid printing
        // useless "all zeros" statistics.
        return 0;
    }

    FILE *out = stderr;
    if (to_file) {
        /* Write to a file instead of stderr. */
# ifdef MS_WINDOWS
        const char *dirname = "c:\\temp\\py_stats\\";
# else
        const char *dirname = "/tmp/py_stats/";
# endif
        /* Use random 160 bit number as file name,
        * to avoid both accidental collisions and
        * symlink attacks. */
        unsigned char rand[20];
        char hex_name[41];
        _PyOS_URandomNonblock(rand, 20);
        for (int i = 0; i < 20; i++) {
            hex_name[2*i] = Py_hexdigits[rand[i]&15];
            hex_name[2*i+1] = Py_hexdigits[(rand[i]>>4)&15];
        }
        hex_name[40] = '\0';
        char buf[64];
        assert(strlen(dirname) + 40 + strlen(".txt") < 64);
        sprintf(buf, "%s%s.txt", dirname, hex_name);
        FILE *fout = fopen(buf, "w");
        if (fout) {
            out = fout;
        }
    }
    else {
        fprintf(out, "Specialization stats:\n");
    }
    print_stats(out, stats);
    if (out != stderr) {
        fclose(out);
    }
    return 1;
}

#endif  // Py_STATS