""" Utilities to create '/jit_defines.h', which contains constants and
    other static information for jit.c's use.
"""

import textwrap
import typing

import _jit_c
import _supernode
import _targets


def create_jit_defines_h(supernodes: typing.Iterable[_supernode.SuperNode]):    
    # Define superopcodes for supernodes
    jit_defines = _targets.CPYTHON / "jit_defines.h"
    with open(jit_defines, "w") as f:
        f.write("\n// Supernode Indices\n")
        for node in supernodes:
            f.write(f"#define {node.name} {node.index}\n")
            f.write(f"#define {node.name}_length {node.length}\n")
        
        f.write(textwrap.dedent("""
                typedef struct {
                    const uint64_t index;
                    const uint16_t length;
                } SuperNode;
                                        
                SuperNode _JIT_INDEX("""))
        
        depth = _supernode.SuperNode.max_depth(supernodes)
        f.write(", ".join(f"uint16_t {param}" for param in _jit_c._parameter_names(depth)))
        f.write(");\n")

        f.write(f"#define MAX_SUPERINST_ID {_targets.max_uop_id()+len(supernodes)}")