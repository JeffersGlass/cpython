import itertools
import string
import typing

import _supernode


def _patch_jit_c(op_indices: dict[str, int], max_uop_id):
    from _targets import CPYTHON

    jit_template = CPYTHON / "Python" / "_jit_template.c"
    jit_c = CPYTHON / "Python" / "jit.c"
    ...

def _create_jit_index(supernode_ops: list[_supernode.SuperNode]):
    depth = max(len(node) for node in supernode_ops)
    yield "int"
    param_names = list(_parameter_names(depth))
    yield f"_JIT_INDEX({','.join(f'uint16_t {name}' for name in param_names)} {{"

    # TODO This is incomplete, and the 'goto' idea is maybe a bad one... should do this recursively
    # for now, and maybe change to tree-matching later
        
    # Stategy for generating a switch statement at a given level:
    #   Identify all potential opcodes at index 'level'
    #   For each opcode:
    #       If there's only one supernode with this starting opcode:
    #           Do direct comparison with the remainder of operations (if any)
    #               If true, return supernode
    #               If not, return first opcode
    #       else (there are multiple supernodes remaining that start with this opcode):
    #          Add switch statement for nodes of next level

    yield "}" # _JIT_INDEX

def _generate_jit_switch_or_compare(supernodes: list[_supernode.SuperNode], var_names, indent=0) -> typing.Generator[str, None, None]:
    initial_opcodes = set(node.ops[0] for node in supernodes)
    yield f"switch ({var_names[0]}) {{"

    for initial_op in initial_opcodes:
        yield f"{'  '*indent}case {initial_op}:"
        yield f"{'    ' * indent}...;"
        #yield from _generate_jit_switch_or_compare([node.pop_front() for node in supernodes if node.length > 1], var_names[1:], indent + 1)
        yield f"{'    ' * indent}break;"

    yield f"{'  ' * indent}default:"
    yield f"{'    ' * indent} return {var_names[0]};"
    yield "}" # switch


"""
With the following oplist:

_GUARD_BOTH_INT,_BINARY_OP_ADD_INT
_ITER_CHECK_LIST,_GUARD_NOT_EXHAUSTED_LIST,_ITER_NEXT_LIST
_ITER_CHECK_LIST, _CHECK_ATTR_WITH_HINT, _BINARY_OP_ADD_INT, 

_JIT_INDEX should look like:

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
    for line in _generate_jit_switch_or_compare(supernodes, varnames, indent = 2):
        print(line)