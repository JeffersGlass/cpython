import itertools
import string



def _patch_jit_c(op_indices: dict[str, int], max_uop_id):
    from _targets import CPYTHON

    jit_template = CPYTHON / "Python" / "_jit_template.c"
    jit_c = CPYTHON / "Python" / "jit.c"
    ...

def _create_jit_index(supernode_ops):
    depth = max(len(node) for node in supernode_ops)
    yield "int"
    param_names = list(_parameter_names(depth))
    yield f"_JIT_INDEX({','.join(f'uint16_t {name}' for name in param_names}) {{"
    for level in range(depth):
        relevant_nodes = (node for node in supernode_ops if node.length <= level + 1)
        yield f"switch ({param_names[level]}) {{"
        for node in relevant_nodes:
            yield f"\tcase {node.ops[level]}:"
            if node.length == level:
                yield f"\t\t return {node.name};"
            else:
                yield f"\t\t goto {'plus'.join(node.ops[:level+1])};"
        yield "}" # switch

    # TODO This is incomplete, and the 'goto' idea is maybe a bad one... should do this recursively
    # for now, and maybe change to tree-matching later

    yield "}" # _JIT_INDEX


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