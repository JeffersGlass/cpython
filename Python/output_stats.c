#include "Python.h"

#include "pycore_opcode_metadata.h" // _PyOpcode_Caches
#include "pycore_uop_metadata.h"    // _PyOpcode_uop_name

const void
_Output_Stats(FILE *out, PyStats *PyStats){
for (int i = 0; i < 256; i++){
if (PyStats->opcode_stats[i].specialization.success != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.success: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.success);}
if (PyStats->opcode_stats[i].specialization.failure != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.failure: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.failure);}
if (PyStats->opcode_stats[i].specialization.hit != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.hit: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.hit);}
if (PyStats->opcode_stats[i].specialization.deferred != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.deferred: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.deferred);}
if (PyStats->opcode_stats[i].specialization.miss != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.miss: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.miss);}
if (PyStats->opcode_stats[i].specialization.deopt != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.deopt: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].specialization.deopt);}
    for (int k = 0; k < SPECIALIZATION_FAILURE_KINDS; k++){
if (PyStats->opcode_stats[i].specialization.failure_kinds[k] != 0) {fprintf(out, "PyStats.opcode_stats[%s].specialization.failure_kinds[%d]: %" PRIu64 "\n", _PyOpcode_OpName[i],k, PyStats->opcode_stats[i].specialization.failure_kinds[k]);}
    }
if (PyStats->opcode_stats[i].execution_count != 0) {fprintf(out, "PyStats.opcode_stats[%s].execution_count: %" PRIu64 "\n", _PyOpcode_OpName[i], PyStats->opcode_stats[i].execution_count);}
  for (int j = 0; j < 256; j++){
if (PyStats->opcode_stats[i].pair_count[j] != 0) {fprintf(out, "PyStats.opcode_stats[%s].pair_count[%s]: %" PRIu64 "\n", _PyOpcode_OpName[i],_PyOpcode_OpName[j], PyStats->opcode_stats[i].pair_count[j]);}
  }
}
if (PyStats->call_stats.inlined_py_calls != 0) {fprintf(out, "PyStats.call_stats.inlined_py_calls: %" PRIu64 "\n",  PyStats->call_stats.inlined_py_calls);}
if (PyStats->call_stats.pyeval_calls != 0) {fprintf(out, "PyStats.call_stats.pyeval_calls: %" PRIu64 "\n",  PyStats->call_stats.pyeval_calls);}
if (PyStats->call_stats.frames_pushed != 0) {fprintf(out, "PyStats.call_stats.frames_pushed: %" PRIu64 "\n",  PyStats->call_stats.frames_pushed);}
if (PyStats->call_stats.frame_objects_created != 0) {fprintf(out, "PyStats.call_stats.frame_objects_created: %" PRIu64 "\n",  PyStats->call_stats.frame_objects_created);}
  for (int j = 0; j < EVAL_CALL_KINDS; j++){
if (PyStats->call_stats.eval_calls[j] != 0) {fprintf(out, "PyStats.call_stats.eval_calls[%d]: %" PRIu64 "\n", j, PyStats->call_stats.eval_calls[j]);}
  }
if (PyStats->object_stats.increfs != 0) {fprintf(out, "PyStats.object_stats.increfs: %" PRIu64 "\n",  PyStats->object_stats.increfs);}
if (PyStats->object_stats.decrefs != 0) {fprintf(out, "PyStats.object_stats.decrefs: %" PRIu64 "\n",  PyStats->object_stats.decrefs);}
if (PyStats->object_stats.interpreter_increfs != 0) {fprintf(out, "PyStats.object_stats.interpreter_increfs: %" PRIu64 "\n",  PyStats->object_stats.interpreter_increfs);}
if (PyStats->object_stats.interpreter_decrefs != 0) {fprintf(out, "PyStats.object_stats.interpreter_decrefs: %" PRIu64 "\n",  PyStats->object_stats.interpreter_decrefs);}
if (PyStats->object_stats.immortal_increfs != 0) {fprintf(out, "PyStats.object_stats.immortal_increfs: %" PRIu64 "\n",  PyStats->object_stats.immortal_increfs);}
if (PyStats->object_stats.immortal_decrefs != 0) {fprintf(out, "PyStats.object_stats.immortal_decrefs: %" PRIu64 "\n",  PyStats->object_stats.immortal_decrefs);}
if (PyStats->object_stats.interpreter_immortal_increfs != 0) {fprintf(out, "PyStats.object_stats.interpreter_immortal_increfs: %" PRIu64 "\n",  PyStats->object_stats.interpreter_immortal_increfs);}
if (PyStats->object_stats.interpreter_immortal_decrefs != 0) {fprintf(out, "PyStats.object_stats.interpreter_immortal_decrefs: %" PRIu64 "\n",  PyStats->object_stats.interpreter_immortal_decrefs);}
if (PyStats->object_stats.allocations != 0) {fprintf(out, "PyStats.object_stats.allocations: %" PRIu64 "\n",  PyStats->object_stats.allocations);}
if (PyStats->object_stats.allocations512 != 0) {fprintf(out, "PyStats.object_stats.allocations512: %" PRIu64 "\n",  PyStats->object_stats.allocations512);}
if (PyStats->object_stats.allocations4k != 0) {fprintf(out, "PyStats.object_stats.allocations4k: %" PRIu64 "\n",  PyStats->object_stats.allocations4k);}
if (PyStats->object_stats.allocations_big != 0) {fprintf(out, "PyStats.object_stats.allocations_big: %" PRIu64 "\n",  PyStats->object_stats.allocations_big);}
if (PyStats->object_stats.frees != 0) {fprintf(out, "PyStats.object_stats.frees: %" PRIu64 "\n",  PyStats->object_stats.frees);}
if (PyStats->object_stats.to_freelist != 0) {fprintf(out, "PyStats.object_stats.to_freelist: %" PRIu64 "\n",  PyStats->object_stats.to_freelist);}
if (PyStats->object_stats.from_freelist != 0) {fprintf(out, "PyStats.object_stats.from_freelist: %" PRIu64 "\n",  PyStats->object_stats.from_freelist);}
if (PyStats->object_stats.inline_values != 0) {fprintf(out, "PyStats.object_stats.inline_values: %" PRIu64 "\n",  PyStats->object_stats.inline_values);}
if (PyStats->object_stats.dict_materialized_on_request != 0) {fprintf(out, "PyStats.object_stats.dict_materialized_on_request: %" PRIu64 "\n",  PyStats->object_stats.dict_materialized_on_request);}
if (PyStats->object_stats.dict_materialized_new_key != 0) {fprintf(out, "PyStats.object_stats.dict_materialized_new_key: %" PRIu64 "\n",  PyStats->object_stats.dict_materialized_new_key);}
if (PyStats->object_stats.dict_materialized_too_big != 0) {fprintf(out, "PyStats.object_stats.dict_materialized_too_big: %" PRIu64 "\n",  PyStats->object_stats.dict_materialized_too_big);}
if (PyStats->object_stats.dict_materialized_str_subclass != 0) {fprintf(out, "PyStats.object_stats.dict_materialized_str_subclass: %" PRIu64 "\n",  PyStats->object_stats.dict_materialized_str_subclass);}
if (PyStats->object_stats.type_cache_hits != 0) {fprintf(out, "PyStats.object_stats.type_cache_hits: %" PRIu64 "\n",  PyStats->object_stats.type_cache_hits);}
if (PyStats->object_stats.type_cache_misses != 0) {fprintf(out, "PyStats.object_stats.type_cache_misses: %" PRIu64 "\n",  PyStats->object_stats.type_cache_misses);}
if (PyStats->object_stats.type_cache_dunder_hits != 0) {fprintf(out, "PyStats.object_stats.type_cache_dunder_hits: %" PRIu64 "\n",  PyStats->object_stats.type_cache_dunder_hits);}
if (PyStats->object_stats.type_cache_dunder_misses != 0) {fprintf(out, "PyStats.object_stats.type_cache_dunder_misses: %" PRIu64 "\n",  PyStats->object_stats.type_cache_dunder_misses);}
if (PyStats->object_stats.type_cache_collisions != 0) {fprintf(out, "PyStats.object_stats.type_cache_collisions: %" PRIu64 "\n",  PyStats->object_stats.type_cache_collisions);}
if (PyStats->object_stats.object_visits != 0) {fprintf(out, "PyStats.object_stats.object_visits: %" PRIu64 "\n",  PyStats->object_stats.object_visits);}
if (PyStats->optimization_stats.attempts != 0) {fprintf(out, "PyStats.optimization_stats.attempts: %" PRIu64 "\n",  PyStats->optimization_stats.attempts);}
if (PyStats->optimization_stats.traces_created != 0) {fprintf(out, "PyStats.optimization_stats.traces_created: %" PRIu64 "\n",  PyStats->optimization_stats.traces_created);}
if (PyStats->optimization_stats.traces_executed != 0) {fprintf(out, "PyStats.optimization_stats.traces_executed: %" PRIu64 "\n",  PyStats->optimization_stats.traces_executed);}
if (PyStats->optimization_stats.uops_executed != 0) {fprintf(out, "PyStats.optimization_stats.uops_executed: %" PRIu64 "\n",  PyStats->optimization_stats.uops_executed);}
if (PyStats->optimization_stats.trace_stack_overflow != 0) {fprintf(out, "PyStats.optimization_stats.trace_stack_overflow: %" PRIu64 "\n",  PyStats->optimization_stats.trace_stack_overflow);}
if (PyStats->optimization_stats.trace_stack_underflow != 0) {fprintf(out, "PyStats.optimization_stats.trace_stack_underflow: %" PRIu64 "\n",  PyStats->optimization_stats.trace_stack_underflow);}
if (PyStats->optimization_stats.trace_too_long != 0) {fprintf(out, "PyStats.optimization_stats.trace_too_long: %" PRIu64 "\n",  PyStats->optimization_stats.trace_too_long);}
if (PyStats->optimization_stats.trace_too_short != 0) {fprintf(out, "PyStats.optimization_stats.trace_too_short: %" PRIu64 "\n",  PyStats->optimization_stats.trace_too_short);}
if (PyStats->optimization_stats.inner_loop != 0) {fprintf(out, "PyStats.optimization_stats.inner_loop: %" PRIu64 "\n",  PyStats->optimization_stats.inner_loop);}
if (PyStats->optimization_stats.recursive_call != 0) {fprintf(out, "PyStats.optimization_stats.recursive_call: %" PRIu64 "\n",  PyStats->optimization_stats.recursive_call);}
if (PyStats->optimization_stats.low_confidence != 0) {fprintf(out, "PyStats.optimization_stats.low_confidence: %" PRIu64 "\n",  PyStats->optimization_stats.low_confidence);}
if (PyStats->optimization_stats.unknown_callee != 0) {fprintf(out, "PyStats.optimization_stats.unknown_callee: %" PRIu64 "\n",  PyStats->optimization_stats.unknown_callee);}
if (PyStats->optimization_stats.executors_invalidated != 0) {fprintf(out, "PyStats.optimization_stats.executors_invalidated: %" PRIu64 "\n",  PyStats->optimization_stats.executors_invalidated);}
  for (int j = 0; j < PYSTATS_MAX_UOP_ID + 1; j++){
if (PyStats->optimization_stats.opcode[j].execution_count != 0) {fprintf(out, "PyStats.optimization_stats.opcode[%s].execution_count: %" PRIu64 "\n", _PyOpcode_uop_name[j], PyStats->optimization_stats.opcode[j].execution_count);}
if (PyStats->optimization_stats.opcode[j].miss != 0) {fprintf(out, "PyStats.optimization_stats.opcode[%s].miss: %" PRIu64 "\n", _PyOpcode_uop_name[j], PyStats->optimization_stats.opcode[j].miss);}
    for (int k = 0; k < PYSTATS_MAX_UOP_ID + 1; k++){
if (PyStats->optimization_stats.opcode[j].pair_count[k] != 0) {fprintf(out, "PyStats.optimization_stats.opcode[%s].pair_count[%s]: %" PRIu64 "\n", _PyOpcode_uop_name[j],_PyOpcode_uop_name[k], PyStats->optimization_stats.opcode[j].pair_count[k]);}
    }
  }
  for (int j = 0; j < 256; j++){
if (PyStats->optimization_stats.unsupported_opcode[j] != 0) {fprintf(out, "PyStats.optimization_stats.unsupported_opcode[%s]: %" PRIu64 "\n", _PyOpcode_OpName[j], PyStats->optimization_stats.unsupported_opcode[j]);}
  }
  for (int j = 0; j < _Py_UOP_HIST_SIZE; j++){
if (PyStats->optimization_stats.trace_length_hist[j] != 0) {fprintf(out, "PyStats.optimization_stats.trace_length_hist[%d]: %" PRIu64 "\n", j, PyStats->optimization_stats.trace_length_hist[j]);}
  }
  for (int j = 0; j < _Py_UOP_HIST_SIZE; j++){
if (PyStats->optimization_stats.trace_run_length_hist[j] != 0) {fprintf(out, "PyStats.optimization_stats.trace_run_length_hist[%d]: %" PRIu64 "\n", j, PyStats->optimization_stats.trace_run_length_hist[j]);}
  }
  for (int j = 0; j < _Py_UOP_HIST_SIZE; j++){
if (PyStats->optimization_stats.optimized_trace_length_hist[j] != 0) {fprintf(out, "PyStats.optimization_stats.optimized_trace_length_hist[%d]: %" PRIu64 "\n", j, PyStats->optimization_stats.optimized_trace_length_hist[j]);}
  }
if (PyStats->optimization_stats.optimizer_attempts != 0) {fprintf(out, "PyStats.optimization_stats.optimizer_attempts: %" PRIu64 "\n",  PyStats->optimization_stats.optimizer_attempts);}
if (PyStats->optimization_stats.optimizer_successes != 0) {fprintf(out, "PyStats.optimization_stats.optimizer_successes: %" PRIu64 "\n",  PyStats->optimization_stats.optimizer_successes);}
if (PyStats->optimization_stats.optimizer_failure_reason_no_memory != 0) {fprintf(out, "PyStats.optimization_stats.optimizer_failure_reason_no_memory: %" PRIu64 "\n",  PyStats->optimization_stats.optimizer_failure_reason_no_memory);}
if (PyStats->optimization_stats.remove_globals_builtins_changed != 0) {fprintf(out, "PyStats.optimization_stats.remove_globals_builtins_changed: %" PRIu64 "\n",  PyStats->optimization_stats.remove_globals_builtins_changed);}
if (PyStats->optimization_stats.remove_globals_incorrect_keys != 0) {fprintf(out, "PyStats.optimization_stats.remove_globals_incorrect_keys: %" PRIu64 "\n",  PyStats->optimization_stats.remove_globals_incorrect_keys);}
  for (int j = 0; j < PYSTATS_MAX_UOP_ID + 1; j++){
if (PyStats->optimization_stats.error_in_opcode[j] != 0) {fprintf(out, "PyStats.optimization_stats.error_in_opcode[%s]: %" PRIu64 "\n", _PyOpcode_uop_name[j], PyStats->optimization_stats.error_in_opcode[j]);}
  }
if (PyStats->optimization_stats.jit_total_memory_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_total_memory_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_total_memory_size);}
if (PyStats->optimization_stats.jit_code_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_code_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_code_size);}
if (PyStats->optimization_stats.jit_trampoline_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_trampoline_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_trampoline_size);}
if (PyStats->optimization_stats.jit_data_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_data_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_data_size);}
if (PyStats->optimization_stats.jit_padding_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_padding_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_padding_size);}
if (PyStats->optimization_stats.jit_freed_memory_size != 0) {fprintf(out, "PyStats.optimization_stats.jit_freed_memory_size: %" PRIu64 "\n",  PyStats->optimization_stats.jit_freed_memory_size);}
  for (int j = 0; j < _Py_UOP_HIST_SIZE; j++){
if (PyStats->optimization_stats.trace_total_memory_hist[j] != 0) {fprintf(out, "PyStats.optimization_stats.trace_total_memory_hist[%d]: %" PRIu64 "\n", j, PyStats->optimization_stats.trace_total_memory_hist[j]);}
  }
if (PyStats->rare_event_stats.set_class != 0) {fprintf(out, "PyStats.rare_event_stats.set_class: %" PRIu64 "\n",  PyStats->rare_event_stats.set_class);}
if (PyStats->rare_event_stats.set_bases != 0) {fprintf(out, "PyStats.rare_event_stats.set_bases: %" PRIu64 "\n",  PyStats->rare_event_stats.set_bases);}
if (PyStats->rare_event_stats.set_eval_frame_func != 0) {fprintf(out, "PyStats.rare_event_stats.set_eval_frame_func: %" PRIu64 "\n",  PyStats->rare_event_stats.set_eval_frame_func);}
if (PyStats->rare_event_stats.builtin_dict != 0) {fprintf(out, "PyStats.rare_event_stats.builtin_dict: %" PRIu64 "\n",  PyStats->rare_event_stats.builtin_dict);}
if (PyStats->rare_event_stats.func_modification != 0) {fprintf(out, "PyStats.rare_event_stats.func_modification: %" PRIu64 "\n",  PyStats->rare_event_stats.func_modification);}
if (PyStats->rare_event_stats.watched_dict_modification != 0) {fprintf(out, "PyStats.rare_event_stats.watched_dict_modification: %" PRIu64 "\n",  PyStats->rare_event_stats.watched_dict_modification);}
if (PyStats->rare_event_stats.watched_globals_modification != 0) {fprintf(out, "PyStats.rare_event_stats.watched_globals_modification: %" PRIu64 "\n",  PyStats->rare_event_stats.watched_globals_modification);}
for (int i = 0; i < NUM_GENERATIONS; i++){
if (PyStats->gc_stats[i].collections != 0) {fprintf(out, "PyStats.gc_stats[%d].collections: %" PRIu64 "\n", i, PyStats->gc_stats[i].collections);}
if (PyStats->gc_stats[i].object_visits != 0) {fprintf(out, "PyStats.gc_stats[%d].object_visits: %" PRIu64 "\n", i, PyStats->gc_stats[i].object_visits);}
if (PyStats->gc_stats[i].objects_collected != 0) {fprintf(out, "PyStats.gc_stats[%d].objects_collected: %" PRIu64 "\n", i, PyStats->gc_stats[i].objects_collected);}
if (PyStats->gc_stats[i].objects_transitively_reachable != 0) {fprintf(out, "PyStats.gc_stats[%d].objects_transitively_reachable: %" PRIu64 "\n", i, PyStats->gc_stats[i].objects_transitively_reachable);}
if (PyStats->gc_stats[i].objects_not_transitively_reachable != 0) {fprintf(out, "PyStats.gc_stats[%d].objects_not_transitively_reachable: %" PRIu64 "\n", i, PyStats->gc_stats[i].objects_not_transitively_reachable);}
}

}