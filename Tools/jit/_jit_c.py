import itertools
import string



def _patch_jit_c(op_indices: dict[str, int], max_uop_id):
    from _targets import CPYTHON

    jit_template = CPYTHON / "Python" / "_jit_template.c"
    jit_c = CPYTHON / "Python" / "jit.c"
    ...

def _create_jit_index(supernode_ops, op_indices):
    depth = max(len(opset) for opset in supernode_ops)
    yield "int"
    yield f"_JIT_INDEX({','.join(f'uint16_t {name}' for name in _parameter_names(depth))}) {{"

    yield "}"


def _parameter_names(num):
    for i in range(min(num, 26)):
        yield string.ascii_lowercase[i]
    if num <= 26: return

    for i in range(num**2):
        yield from itertools.combinations_with_replacement(string.ascii_lowercase)

if __name__ == "__main__":
    from _opfile import _retrieve_ops_from_path
    supernode_ops = _retrieve_ops_from_path("ops.csv")
    for line in _create_jit_index(supernode_ops, ):
        pass