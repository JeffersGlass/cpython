## GC stats

<details>
<summary> GC collections and effectiveness </summary>


Collected/visits gives some measure of efficiency.

<table>
<thead>
<tr>
<th align="right">Generation</th>
<th align="right">Collections</th>
<th align="right">Objects collected</th>
<th align="right">Object visits</th>
<th align="right">Reachable from roots</th>
<th align="right">Not reachable from roots</th>
</tr>
</thead>
<tbody>
<tr>
<td align="right">0</td>
<td align="right">0</td>
<td align="right">0</td>
<td align="right">0</td>
<td align="right">0</td>
<td align="right">0</td>
</tr>
<tr>
<td align="right">1</td>
<td align="right">28</td>
<td align="right">380</td>
<td align="right">498,281</td>
<td align="right">52,254</td>
<td align="right">17,600</td>
</tr>
<tr>
<td align="right">2</td>
<td align="right">6</td>
<td align="right">13,922</td>
<td align="right">1,097,402</td>
<td align="right">0</td>
<td align="right">0</td>
</tr>
</tbody>
</table>


</details>

## Optimization (Tier 2) stats

<details>
<summary> statistics about the Tier 2 optimizer </summary>

<table>
<thead>
<tr>
<th align="left"></th>
<th align="right">Count</th>
<th align="right">Ratio</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">
Optimization attempts
<details>
<summary>ⓘ</summary>

The number of times a potential trace is identified.  Specifically, this occurs in the JUMP BACKWARD instruction when the counter reaches a threshold.
</details>
</td>
<td align="right">18</td>
<td align="right"></td>
</tr>
<tr>
<td align="left">
Traces created
<details>
<summary>ⓘ</summary>

The number of traces that were successfully created.
</details>
</td>
<td align="right">3</td>
<td align="right">16.7%</td>
</tr>
<tr>
<td align="left">
Trace stack overflow
<details>
<summary>ⓘ</summary>

A trace is truncated because it would require more than 5 stack frames.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Trace stack underflow
<details>
<summary>ⓘ</summary>

A potential trace is abandoned because it pops more frames than it pushes.
</details>
</td>
<td align="right">13</td>
<td align="right">72.2%</td>
</tr>
<tr>
<td align="left">
Trace too long
<details>
<summary>ⓘ</summary>

A trace is truncated because it is longer than the instruction buffer.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Trace too short
<details>
<summary>ⓘ</summary>

A potential trace is abandoned because it it too short.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Inner loop found
<details>
<summary>ⓘ</summary>

A trace is truncated because it has an inner loop
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Recursive call
<details>
<summary>ⓘ</summary>

A trace is truncated because it has a recursive call.
</details>
</td>
<td align="right">3</td>
<td align="right">16.7%</td>
</tr>
<tr>
<td align="left">
Low confidence
<details>
<summary>ⓘ</summary>

A trace is abandoned because the likelihood of the jump to top being taken is too low.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Unknown callee
<details>
<summary>ⓘ</summary>

A trace is abandoned because the target of a call is unknown.
</details>
</td>
<td align="right">2</td>
<td align="right">11.1%</td>
</tr>
<tr>
<td align="left">
Executors invalidated
<details>
<summary>ⓘ</summary>

The number of executors that were invalidated due to watched dictionary changes.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Traces executed
<details>
<summary>ⓘ</summary>

The number of traces that were executed
</details>
</td>
<td align="right">55,408</td>
<td align="right"></td>
</tr>
<tr>
<td align="left">
Uops executed
<details>
<summary>ⓘ</summary>

The total number of uops (micro-operations) that were executed
</details>
</td>
<td align="right">1,326,112</td>
<td align="right">2,393.4%</td>
</tr>
</tbody>
</table>

<table>
<thead>
<tr>
<th align="left"></th>
<th align="right">Count</th>
<th align="right">Ratio</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">
Optimizer attempts
<details>
<summary>ⓘ</summary>

The number of times the trace optimizer (_Py_uop_analyze_and_optimize) was run.
</details>
</td>
<td align="right">3</td>
<td align="right"></td>
</tr>
<tr>
<td align="left">
Optimizer successes
<details>
<summary>ⓘ</summary>

The number of traces that were successfully optimized.
</details>
</td>
<td align="right">3</td>
<td align="right">100.0%</td>
</tr>
<tr>
<td align="left">
Optimizer no memory
<details>
<summary>ⓘ</summary>

The number of optimizations that failed due to no memory.
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Remove globals builtins changed
<details>
<summary>ⓘ</summary>

The builtins changed during optimization
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
<tr>
<td align="left">
Remove globals incorrect keys
<details>
<summary>ⓘ</summary>

The keys in the globals dictionary aren't what was expected
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
</tbody>
</table>

### JIT memory stats

<details>
<summary> JIT memory stats </summary>

<table>
<thead>
<tr>
<th align="left"></th>
<th align="right">Size (bytes)</th>
<th align="right">Ratio</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">
Total memory size
<details>
<summary>ⓘ</summary>

The total size of the memory allocated for the JIT traces
</details>
</td>
<td align="right">73,728</td>
<td align="right"></td>
</tr>
<tr>
<td align="left">
Code size
<details>
<summary>ⓘ</summary>

The size of the memory allocated for the code of the JIT traces
</details>
</td>
<td align="right">35,529</td>
<td align="right">48.2%</td>
</tr>
<tr>
<td align="left">
Trampoline size
<details>
<summary>ⓘ</summary>

The size of the memory allocated for the trampolines of the JIT traces
</details>
</td>
<td align="right">27,504</td>
<td align="right">37.3%</td>
</tr>
<tr>
<td align="left">
Data size
<details>
<summary>ⓘ</summary>

The size of the memory allocated for the data of the JIT traces
</details>
</td>
<td align="right">10,695</td>
<td align="right">14.5%</td>
</tr>
<tr>
<td align="left">
Padding size
<details>
<summary>ⓘ</summary>

The size of the memory allocated for the padding of the JIT traces
</details>
</td>
<td align="right">73,728</td>
<td align="right">100.0%</td>
</tr>
<tr>
<td align="left">
Freed memory size
<details>
<summary>ⓘ</summary>

The size of the memory freed from the JIT traces
</details>
</td>
<td align="right">0</td>
<td align="right">0.0%</td>
</tr>
</tbody>
</table>


</details>

### JIT trace total memory histogram

<details>
<summary> JIT trace total memory histogram </summary>


</details>

### Trace length histogram

<details>
<summary> trace length histogram </summary>


</details>

### Optimized trace length histogram

<details>
<summary> optimized trace length histogram </summary>


</details>

### Trace run length histogram

<details>
<summary> trace run length histogram </summary>


</details>

### Uop execution stats

<details>
<summary> uop execution stats </summary>


</details>

### Pair counts

<details>
<summary> Pair counts for top 100 Non-JIT uop pairs </summary>


Pairs of specialized operations that deoptimize and are then followed by
the corresponding unspecialized instruction are not counted as pairs.


</details>

### Unsupported opcodes

<details>
<summary> unsupported opcodes </summary>


</details>

### Optimizer errored out with opcode

<details>
<summary> Optimization stopped after encountering this opcode </summary>


</details>

### Unvisited Stats

<details>
<summary> Stats that have the same prefix as this section but are not read by any other stat </summary>

<table>
<thead>
<tr>
<th align="left">Stat Name</th>
<th align="right">Value</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">PyStats.optimization_stats.FOO</td>
<td align="right">6,969,420</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_FUNCTION].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_FUNCTION_VERSION_INLINE].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_PERIODIC].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_STACK_SPACE].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_VALIDITY].execution_count</td>
<td align="right">110,586</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_CHECK_VALIDITY_AND_SET_IP].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_EXIT_TRACE].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_GUARD_NOT_EXHAUSTED_TUPLE].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_GUARD_NOT_EXHAUSTED_TUPLE].miss</td>
<td align="right">230</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_INIT_CALL_PY_EXACT_ARGS_2].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_ITER_CHECK_TUPLE].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_ITER_NEXT_TUPLE].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_LOAD_CONST_INLINE].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_LOAD_DEREF].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_LOAD_FAST_4].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_MAKE_WARM].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_PUSH_FRAME].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_PUSH_NULL].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_SAVE_RETURN_OFFSET].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_SET_IP].execution_count</td>
<td align="right">165,764</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_START_EXECUTOR].execution_count</td>
<td align="right">55,408</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.opcode[_STORE_FAST_4].execution_count</td>
<td align="right">55,178</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.optimized_trace_length_hist[5]</td>
<td align="right">3</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.trace_length_hist[5]</td>
<td align="right">3</td>
</tr>
<tr>
<td align="left">PyStats.optimization_stats.trace_total_memory_hist[15]</td>
<td align="right">3</td>
</tr>
</tbody>
</table>


</details>


</details>

## Rare events

<details>
<summary> Counts of rare/unlikely events </summary>

<table>
<thead>
<tr>
<th align="left">Event</th>
<th align="right">Count</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">
func_modification
<details>
<summary>ⓘ</summary>

Modifying a function, e.g. `func.__defaults__ = ...`, etc.
</details>
</td>
<td align="right">32</td>
</tr>
<tr>
<td align="left">
watched_dict_modification
<details>
<summary>ⓘ</summary>

A watched dict has been modified
</details>
</td>
<td align="right">3</td>
</tr>
<tr>
<td align="left">
watched_globals_modification
<details>
<summary>ⓘ</summary>

A watched `globals()` dict has been modified
</details>
</td>
<td align="right">3</td>
</tr>
</tbody>
</table>


</details>

## Meta stats

<details>
<summary> Meta statistics </summary>

<table>
<thead>
<tr>
<th align="left"></th>
<th align="right">Count</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left">Number of data files</td>
<td align="right">8</td>
</tr>
</tbody>
</table>


</details>

---
Stats gathered on: 2025-04-01
