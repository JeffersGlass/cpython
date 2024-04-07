""" Functions for turning _jit_template.c into a fully realized jit.c.
    This is done at build time, to allow jit.c to be customized to accomodate 
    the longest superinstructions.
"""

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
    """
    /*for (size_t i = 0; i < length; i++) {
        _PyUOpInstruction *instruction = (_PyUOpInstruction *)&trace[i];
        const StencilGroup *group = &stencil_groups[instruction->opcode];
        instruction_starts[i] = code_size;
        code_size += group->code.body_size;
        data_size += group->data.body_size;
    }*/"""

    depth = _supernode.SuperNode.max_depth(supernodes)
    yield f'if (length > {depth}){{'
    yield '//printf("About to run size loop on executor of size %ld\\n", length);'
    yield f"for (size_t i = 0; i <= length-{depth};) {{"
    for d in range(depth):
        yield f"\t_PyUOpInstruction *instruction{d} = (_PyUOpInstruction *)&trace[i+{d}];"
    yield '//printf("Calling _JIT_INDEX from primary size loop:");'
    yield f"\tconst SuperNode node = _JIT_INDEX({', '.join(f'instruction{i}->opcode' for i in range(depth))});"
    yield f"\t\tconst StencilGroup *group = &stencil_groups[node.index];"
    yield '\t\t//printf("Node index: %ld\\n", node.index);'
    yield "\t\tcode_size += group->code.body_size;"
    yield "\t\tdata_size += group->data.body_size;"
    yield "\t\ti += node.length;"
    yield "\t\tfinal_index = i;"
    yield '\t\t//printf("At end of loop: node.length: %d, i: %ld, final_index: %ld\\n", node.length, i, final_index);'
    yield "\t}"
    yield "}"
    yield ""
    yield "\t// Once we're closer to the end of the stencil than the depth of our"
    yield "\t// longest stencil, just single-jit the remaining opcodes. This can be"
    yield "\t// improved to look only at short-enough patterns by passing, say, -1"
    yield "\t// to any instructions past the end of the trace; since the longest"
    yield "\t// superinstruction is likely to still be short, the current approach sholdn't"
    yield "\t// be too awful."
    yield ""
    yield '//printf("After primary size loop for executor of size %ld, final_index is %ld", length, final_index);'
    yield f""" for (size_t i = final_index; i < length; i++) {{
        _PyUOpInstruction *instruction = (_PyUOpInstruction *)&trace[i];
        //printf("Calling _JIT_INDEX from secondary size loop:");
        const SuperNode node = _JIT_INDEX({', '.join(['instruction->opcode', *["-1" for _ in range(depth-1)]])});
        const StencilGroup *group = &stencil_groups[node.index];
        code_size += group->code.body_size;
        data_size += group->data.body_size;
    }} """


def _create_patch_loop(supernodes):
        """ Original

    /* for (size_t i = 0; i < legth; i++) {
        _PyUOpInstruction *instruction = (_PyUOpInstruction *)&trace[i];
        const StencilGroup *group = &stencil_groups[instruction->opcode];
        // Think of patches as a dictionary mapping HoleValue to uintptr_t:
        uintptr_t patches[] = GET_PATCHES();
        patches[HoleValue_CODE] = (uintptr_t)code;
        patches[HoleValue_CONTINUE] = (uintptr_t)code + group->code.body_size;
        patches[HoleValue_DATA] = (uintptr_t)data;
        patches[HoleValue_EXECUTOR] = (uintptr_t)executor;
        patches[HoleValue_OPARG] = instruction->oparg;
    #if SIZEOF_VOID_P == 8
        patches[HoleValue_OPERAND] = instruction->operand;
    #else
        assert(SIZEOF_VOID_P == 4);
        patches[HoleValue_OPERAND_HI] = instruction->operand >> 32;
        patches[HoleValue_OPERAND_LO] = instruction->operand & UINT32_MAX;
    #endif
        switch (instruction->format) {
            case UOP_FORMAT_TARGET:
                patches[HoleValue_TARGET] = instruction->target;
                break;
            case UOP_FORMAT_EXIT:
                assert(instruction->exit_index < executor->exit_count);
                patches[HoleValue_EXIT_INDEX] = instruction->exit_index;
                if (instruction->error_target < length) {
                    patches[HoleValue_ERROR_TARGET] = (uintptr_t)memory + instruction_starts[instruction->error_target];
                }
                break;
            case UOP_FORMAT_JUMP:
                assert(instruction->jump_target < length);
                patches[HoleValue_JUMP_TARGET] = (uintptr_t)memory + instruction_starts[instruction->jump_target];
                if (instruction->error_target < length) {
                    patches[HoleValue_ERROR_TARGET] = (uintptr_t)memory + instruction_starts[instruction->error_target];
                }
                break;
            default:
                assert(0);
                Py_FatalError("Illegal instruction format");
        } 
        patches[HoleValue_TOP] = (uintptr_t)memory + instruction_starts[1];
        patches[HoleValue_ZERO] = 0;
        emit(group, patches);
        code += group->code.body_size;
        data += group->data.body_size;
    } */        
        
        """
        depth = _supernode.SuperNode.max_depth(supernodes)
        yield f'if (length > {depth}){{'
        yield '//printf("About to run patch loop\\n");'
        yield f"for (size_t i = 0; i <= length - {depth}; ) {{"
        for i in range(depth):
            yield f"\t_PyUOpInstruction *instruction{i} = (_PyUOpInstruction *)&trace[i+{i}];"
        yield '//printf("Calling _JIT_INDEX from primary patch loop:");'
        yield f"\tconst SuperNode node = _JIT_INDEX({', '.join(f'instruction{i}->opcode' for i in range(depth))});"
        yield f"\t\tconst StencilGroup *group = &stencil_groups[node.index];"
        yield "\t// Think of patches as a dictionary mapping HoleValue to uint64_t:"
        yield "\t\tuint64_t patches[] = GET_PATCHES();"
        yield "patches[HoleValue_CODE] = (uintptr_t)code;"
        yield "patches[HoleValue_CONTINUE] = (uintptr_t)code + group->code.body_size;"
        yield "patches[HoleValue_DATA] = (uintptr_t)data;"
        yield "patches[HoleValue_EXECUTOR] = (uintptr_t)executor;"
        for i in range(depth):
            yield f"\t\tpatches[HoleValue_OPARG{i}] = instruction{i}->oparg;"
            yield f"\t\tpatches[HoleValue_TARGET{i}] = instruction{i}->target;"
            yield f"""#if SIZEOF_VOID_P == 8
                        patches[HoleValue_OPERAND{i}] = instruction{i}->operand;
                    #else
                        assert(SIZEOF_VOID_P == 4);
                        patches[HoleValue_OPERAND_HI{i}] = instruction{i}->operand >> 32;
                        patches[HoleValue_OPERAND_LO{i}] = instruction{i}->operand & UINT32_MAX;
                    #endif

                    switch (instruction{i}->format) {{
                        case UOP_FORMAT_TARGET:
                            patches[HoleValue_TARGET{i}] = instruction{i}->target;
                            break;
                        case UOP_FORMAT_EXIT:
                            assert(instruction{i}->exit_index < executor->exit_count);
                            patches[HoleValue_EXIT_INDEX{i}] = instruction{i}->exit_index;
                            if (instruction{i}->error_target < length) {{
                                patches[HoleValue_ERROR_TARGET{i}] = (uintptr_t)memory + instruction_starts[instruction{i}->error_target];
                            }}
                            break;
                        case UOP_FORMAT_JUMP:
                            assert(instruction{i}->jump_target < length);
                            patches[HoleValue_JUMP_TARGET{i}] = (uintptr_t)memory + instruction_starts[instruction{i}->jump_target];
                            if (instruction{i}->error_target < length) {{
                                patches[HoleValue_ERROR_TARGET{i}] = (uintptr_t)memory + instruction_starts[instruction{i}->error_target];
                            }}
                            break;
                        default:
                            assert(0);
                            Py_FatalError("Illegal instruction format");
                    }}                     
                    """
        
        yield """patches[HoleValue_TOP] = (uintptr_t)memory + instruction_starts[1];
        patches[HoleValue_ZERO] = 0;
        emit(group, patches);
        code += group->code.body_size;
        data += group->data.body_size;
        i += node.length;
        final_index = i;
    }
}"""
        
        yield "\t// Once we're closer to the end of the stencil than the depth of our"
        yield "\t// longest stencil, just single-jit the remaining opcodes. This can be"
        yield "\t// improved to look only at short-enough patterns by passing, say, -1"
        yield "\t// to any instructions past the end of the trace; since the longest"
        yield "\t// superinstruction is likely to still be short, the current approach sholdn't"
        yield "\t// be too awful."
        yield ""
        yield f"""for (size_t i = final_index; i < length; i++) {{
        _PyUOpInstruction *instruction = (_PyUOpInstruction *)&trace[i];
        //printf("Calling _JIT_INDEX from secondary patch loop: ");
		const SuperNode node = _JIT_INDEX({', '.join(['instruction->opcode', *["-1" for _ in range(depth-1)]])});
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
        patches[HoleValue_TOP] = (uintptr_t)memory + instruction_starts[1];
        patches[HoleValue_ZERO] = 0;
        emit(group, patches);
        code += group->code.body_size;
        data += group->data.body_size;
    }}"""

 

def _create_jit_index(supernodes: list[_supernode.SuperNode]) -> typing.Generator[str, None, None]:
    depth = _supernode.SuperNode.max_depth(supernodes)
    yield "SuperNode"
    param_names = list(_parameter_names(depth))

    yield f"_JIT_INDEX({', '.join(f'uint16_t {name}' for name in param_names)}) {{"
    yield from _generate_jit_switch_or_compare(supernodes, param_names, level=0, indent_level=1)

    yield "}" # _JIT_INDEX

def _generate_jit_switch_or_compare(supernodes: list[_supernode.SuperNode], var_names, level, indent_level) -> typing.Generator[str, None, None]:
    # Stategy for generating a switch statement at a given level:
    #   Identify all potential opcodes at index 'level'
    #   For each opcode:
    #       if there are multiple supernodes starting with this opcode:
    #          Add switch statement for nodes of next level
    #       else (there's only one supernode with this starting opcode):
    #           ...
    
    initial_opcodes = []
    for node in supernodes:
        if node.ops[0] not in initial_opcodes: initial_opcodes.append(node.ops[0])
    
    yield f"{INDENT_UNIT * indent_level}switch ({var_names[level]}) {{"

    for initial_op in initial_opcodes:
        yield f"{INDENT_UNIT * (indent_level + 1)}case {initial_op}:"
        next_nodes = [node.pop_front() for node in supernodes if node.length > 1 and node.ops[0] == initial_op]
        if next_nodes: yield from _generate_jit_switch_or_compare(next_nodes, var_names, level+1, indent_level + 2)
        else: 
            first_nodes = [node for node in supernodes if node.ops[0] == initial_op]
            if len(first_nodes) != 1:
                raise ValueError(f"Wrong number of first_nodes") # {len(first_nodes)=}\n{'\n'.join(str(f) for f in first_nodes)}")
            only_node = first_nodes[0]
            yield f"{INDENT_UNIT * (indent_level + 2)}return (SuperNode) {{.index = {only_node.top_parent().name}, .length = {only_node.top_parent().length}}};"
        yield f"{INDENT_UNIT * (indent_level + 2)}break;"

    yield f"{INDENT_UNIT * (indent_level + 1)}default:"
    yield f"{INDENT_UNIT * (indent_level + 2)}return (SuperNode) {{.index = {var_names[0]}, .length = 1}};"
    yield f"{INDENT_UNIT * indent_level}}}" # switch
            
def _parameter_names(num):
    """Generate single-letter arg names, following by two-letter arg names if
    necessary. (a, b, c, ..., z, aa, ab, ...)

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
    # Run this file as a module to output `jit.c` for the current set of opcodes
    import _opfile
    from _targets import TOOLS_JIT
    supernodes = _opfile._retrieve_ops_from_path(f"{TOOLS_JIT}/superinstructions.csv")
    for line in _create_jit_index(supernodes):
        print(line)