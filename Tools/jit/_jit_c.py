import itertools
import string
import typing

import _supernode
 
INDENT_UNIT = '  '

def _patch_jit_c(supernodes: list[_supernode.SuperNode]):
    from _targets import CPYTHON

    jit_template = CPYTHON / "Python" / "_jit_template.c"
    jit_c = CPYTHON / "Python" / "jit.c"

    with open(jit_template, "r") as infile, open(jit_c, "w") as outfile:
        for line in infile:
            outfile.write(line)
            if line.strip() == "// SIZE LOOP HERE":
                for func_line in _create_size_loop(supernodes):
                    outfile.write(f"\t{func_line}\n")
            if line.strip() == "// PATCH LOOP INIT HERE":
                 for func_line in _create_patch_loop(supernodes):
                    outfile.write(f"\t{func_line}\n")
            if line.strip() == "// _JIT_INDEX HERE":
                for func_line in _create_jit_index(supernodes):
                    outfile.write(f"{func_line}\n")
    ...

def _create_size_loop(supernodes: list[_supernode.SuperNode]) -> typing.Generator[str, None, None]:
    """ //Original:
    for (Py_ssize_t i = 0; i < Py_SIZE(executor);) {
        _PyUOpInstruction *instruction = &executor->trace[i];
        const StencilGroup *group = &stencil_groups[instruction->opcode];
        code_size += group->code.body_size;
        data_size += group->data.body_size;
    } """

    depth = max(len(node.ops) for node in supernodes)

    yield f"for (Py_ssize_t i = 0; i <= Py_SIZE(executor)-{depth};) {{"
    for d in range(depth):
        yield f"\t_PyUOpInstruction *instruction{d} = &executor->trace[i+{d}];"
    yield f"\tconst SuperNode node = _JIT_INDEX({', '.join(f'instruction{i}->opcode' for i in range(depth))});"
    yield f'DPRINTF("\\nLooking at {depth} opcodes starting at index %ld:", i )'
    for d in range(depth):
        yield f"""DPRINTF("\\n\t%ld: uop %s, oparg %d, operand %" PRIu64 ", target %d", i + {d} , _PyUOpName(instruction{d}->opcode), instruction{d}->oparg, instruction{d}->operand, instruction{d}->target);"""
    yield f"""DPRINTF("\\n\tChosen Node index: %ld (PyUOpName: %s)", node.index, _PyUOpName(node.index));"""
    yield f"\t\tconst StencilGroup *group = &stencil_groups[node.index];"
    yield "\t\tcode_size += group->code.body_size;"
    yield "\t\tdata_size += group->data.body_size;"
    yield "\t\ti += node.length;"
    yield "\t\tfinal_index = i;"
    yield '''DPRINTF("\\n\tAfter loop, i = %ld (Py_SIZE(executor) is %ld)", i, Py_SIZE(executor));'''
    yield "\t}"
    yield "\t// Once we're closer to the end of the stencil than the depth of our"
    yield "\t// longest stencil, just single-jit the remaining opcodes. This can be"
    yield "\t// improved to look only at short-enough patterns by passing, say, -1"
    yield "\t// to any instructions past the end of the trace; since the longest"
    yield "\t// superinstruction is likely to still be short, the current approach sholdn't"
    yield "\t// be too awful."
    yield ""
    yield f""" for (Py_ssize_t i = final_index; i < Py_SIZE(executor); i++) {{
        _PyUOpInstruction *instruction = &executor->trace[i];
        const SuperNode node = _JIT_INDEX({', '.join(['instruction->opcode', *["-1" for _ in range(depth-1)]])});
        // DPRINTF("\\n(Single Node @ index %ld ) chosen UOp index: %ld (PyUOpName: %s)", i, node.index, _PyUOpName(node.index));
        const StencilGroup *group = &stencil_groups[node.index];
        code_size += group->code.body_size;
        data_size += group->data.body_size;
        // DPRINTF(" - OP COMPLETE");
    }} """


def _create_patch_loop(supernodes):
        depth = max(len(node.ops) for node in supernodes) 
        yield f"for (Py_ssize_t i = 0; i <= Py_SIZE(executor) - {depth}; ) {{"
        for i in range(depth):
            yield f"\t_PyUOpInstruction *instruction{i} = &executor->trace[i+{i}];"

        yield f"\tconst SuperNode node = _JIT_INDEX({', '.join(f'instruction{i}->opcode' for i in range(depth))});"
        yield f'DPRINTF("\\nLooking at {depth} opcodes starting at index %ld:", i )'
        for d in range(depth):
            yield f"""DPRINTF("\\n\t%ld: uop %s, oparg %d, operand %" PRIu64 ", target %d", i + {d} , _PyUOpName(instruction{d}->opcode), instruction{d}->oparg, instruction{d}->operand, instruction{d}->target);"""
        yield f"""DPRINTF("\\n\tChosen Node index: %ld (PyUOpName: %s)", node.index, _PyUOpName(node.index));"""
        yield f"\t\tconst StencilGroup *group = &stencil_groups[node.index];"
        yield "\t// Think of patches as a dictionary mapping HoleValue to uint64_t:"
        yield "\t\tuint64_t patches[] = GET_PATCHES();"
        for i in range(depth):
            yield f"\t\tpatches[HoleValue_OPARG{i}] = instruction{i}->oparg;"
            yield f"\t\tpatches[HoleValue_OPERAND{i}] = instruction{i}->operand;"
            yield f"\t\tpatches[HoleValue_TARGET{i}] = instruction{i}->target;"
        yield """\t\tpatches[HoleValue_CODE] = (uint64_t)code;
        patches[HoleValue_CONTINUE] = (uint64_t)code + group->code.body_size;
        patches[HoleValue_DATA] = (uint64_t)data;
        patches[HoleValue_EXECUTOR] = (uint64_t)executor;
        patches[HoleValue_TOP] = (uint64_t)memory;
        patches[HoleValue_ZERO] = 0;
        emit(group, patches);
        code += group->code.body_size;
        data += group->data.body_size;
        i += node.length;
        final_index = i;
        DPRINTF("\\n\tAfter loop, i = %ld (Py_SIZE(executor) is %ld)", i, Py_SIZE(executor));
        
}"""
        yield "\t// Once we're closer to the end of the stencil than the depth of our"
        yield "\t// longest stencil, just single-jit the remaining opcodes. This can be"
        yield "\t// improved to look only at short-enough patterns by passing, say, -1"
        yield "\t// to any instructions past the end of the trace; since the longest"
        yield "\t// superinstruction is likely to still be short, the current approach sholdn't"
        yield "\t// be too awful."
        yield ""
        yield f"""for (Py_ssize_t i = final_index; i < Py_SIZE(executor); i++) {{
		_PyUOpInstruction *instruction = &executor->trace[i];
		const SuperNode node = _JIT_INDEX({', '.join(['instruction->opcode', *["-1" for _ in range(depth-1)]])});
        // DPRINTF("\\n(Single Node @ index %ld ) chosen UOp index: %ld (PyUOpName: %s)", i, node.index, _PyUOpName(node.index));
        // DPRINTF("\\n\t%ld: uop %s, oparg %d, operand %" PRIu64 ", target %d", i, _PyUOpName(instruction->opcode), instruction->oparg, instruction->operand, instruction->target);
        const StencilGroup *group = &stencil_groups[node.index];
		// Think of patches as a dictionary mapping HoleValue to uint64_t:
			uint64_t patches[] = GET_PATCHES();
			patches[HoleValue_OPARG0] = instruction->oparg;
			patches[HoleValue_OPERAND0] = instruction->operand;
			patches[HoleValue_TARGET0] = instruction->target;
        // END PATCH LOOP
        patches[HoleValue_CODE] = (uint64_t)code;
        patches[HoleValue_CONTINUE] = (uint64_t)code + group->code.body_size;
        patches[HoleValue_DATA] = (uint64_t)data;
        patches[HoleValue_EXECUTOR] = (uint64_t)executor;
        patches[HoleValue_TOP] = (uint64_t)memory;
        patches[HoleValue_ZERO] = 0;
        emit(group, patches);
        code += group->code.body_size;
        data += group->data.body_size;
        // DPRINTF(" - OP COMPLETE")
    }}"""

 

def _create_jit_index(supernodes: list[_supernode.SuperNode]) -> typing.Generator[str, None, None]:
    depth = max(len(node.ops) for node in supernodes)
    yield "SuperNode"
    param_names = list(_parameter_names(depth))

    yield f"_JIT_INDEX({', '.join(f'uint16_t {name}' for name in param_names)}) {{"
    yield from _generate_jit_switch_or_compare(supernodes, param_names, level=0, indent_level=1)

    yield "}" # _JIT_INDEX

def _generate_jit_switch_or_compare(supernodes: list[_supernode.SuperNode], var_names, level, indent_level) -> typing.Generator[str, None, None]:
    # Stategy for generating a switch statement at a given level:
    #   Identify all potential opcodes at index 'level'
    #   For each opcode:
    #       If there's only one supernode with this starting opcode:
    #           Do direct comparison with the remainder of operations (if any)
    #               If true, return supernode
    #               If not, return first opcode
    #       else (there are multiple supernodes remaining that start with this opcode):
    #          Add switch statement for nodes of next level
    initial_opcodes = set(node.ops[0] for node in supernodes)
    yield f"{INDENT_UNIT * indent_level}switch ({var_names[level]}) {{"

    for initial_op in initial_opcodes:
        yield f"{INDENT_UNIT * 2 * indent_level}case {initial_op}:"
        next_nodes = [node.pop_front() for node in supernodes if node.length > 1 and node.ops[0] == initial_op]
        if next_nodes: yield from _generate_jit_switch_or_compare(next_nodes, var_names, level+1, indent_level + 2)
        else: 
            yield f'DPRINTF("Jitting {supernodes[0].top_parent().name}\\n")'
            yield f"{INDENT_UNIT * 3 * indent_level}return (SuperNode) {{.index = {supernodes[0].top_parent().name}, .length = {supernodes[0].top_parent().length}}};"
        yield f"{INDENT_UNIT * 3 * indent_level}break;"

    yield f"{INDENT_UNIT * 2   * indent_level}default:"
    yield f"{INDENT_UNIT * 3 * indent_level}return (SuperNode) {{.index = {var_names[0]}, .length = 1}};"
    yield f"{INDENT_UNIT * indent_level}}}" # switch


"""
With the following oplist:

_GUARD_BOTH_INT,_BINARY_OP_ADD_INT
_ITER_CHECK_LIST,_GUARD_NOT_EXHAUSTED_LIST,_ITER_NEXT_LIST
_ITER_CHECK_LIST, _CHECK_ATTR_WITH_HINT, _BINARY_OP_ADD_INT, 

_JIT_INDEX should look like:

// Two levels of switch
int
_JIT_INDEX(uint16 a, uint16 b, uint16 c){
    switch (a){
        case _GUARD_BOTH_INT:
            switch (b){
                case _BINARY_OP_ADD_INT:
                    return _GUARD_BOTH_INTplus_BINARY_OP_ADD_INT;
                default:
                    return a;
            }
            break;
        case _ITER_CHECK_LIST:
            switch (b){
                case _GUARD_NOT_EXHAUSTED_LIST:
                    break;
                case _CHECK_ATTR_WITH_HINT:
                    ...
                    break;
                default:
                    return a;
            }
            break;
        default:
            return a;
    }
}


//// One level of switch
int
_JIT_INDEX(uint16 a, uint16 b, uint16 c){
    switch (a){
        case _GUARD_BOTH_INT:
            ...
            break;
        case _ITER_CHECK_LIST:
            ...
            break;
        default:
            return a;
    }
}


"""
            
def _parameter_names(num):
    """Generate single-letter arg names, following by two-letter arg names if
    necessary

    Args:
        num (_type_): How many argument names to create

    Yields:
        Generatoor[str]: The returned argument names
    """
    for i in range(min(num, 26)):
        yield string.ascii_lowercase[i]
    if num <= 26: return

    for i in range(num**2):
        yield from itertools.combinations_with_replacement(string.ascii_lowercase)

if __name__== "__main__":
    import _opfile
    supernodes = _opfile._retrieve_ops_from_path("/home/jglass/Documents/cpython/Tools/jit/ops.csv")
    depth = max(node.length for node in supernodes)
    varnames = list(_parameter_names(depth))
    print("-----")
    for line in _create_jit_index(supernodes):
        print(line)