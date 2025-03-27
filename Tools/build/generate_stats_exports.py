from collections.abc import Callable, Iterable, Generator
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional, Set, Protocol

DEFAULT_ROOT_NAME = "PyStats"
CPYTHON_ROOT_DIR = Path(__file__).parent.parent.parent
PYSTATS_FILE = CPYTHON_ROOT_DIR / "Include" / "cpython" / "pystats.h"
OUTPUT_FILE = CPYTHON_ROOT_DIR / "Python" / "output_stats.c"

PREAMBLE =  """\
#include "Python.h"

#include "pycore_opcode_metadata.h" // _PyOpcode_Caches
#include "pycore_uop_metadata.h"    // _PyOpcode_uop_name

const void
_Output_Stats(FILE *out, PyStats *PyStats){"""

POSTAMBLE = """\
}"""

class HasName(Protocol):
    name: str

@dataclass
class Field:
    name: str
    type: str
    array_size: Optional[str] = None
    array_index_name: Optional[str] = None

@dataclass
class Struct:
    name: str
    fields: List[Field]

def parse_structs(content: str) -> List[Struct]:
    # Remove multiline comments comments
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)

    # Find all struct definitions
    struct_pattern = r'typedef\s+struct\s+_(?P<name>\w+)\s*{(?P<content>[^}]+)}\s+(?P<alias>\w+)'
    structs = []

    for match in re.finditer(struct_pattern, content):
        struct_name = match.group("alias")
        fields_content = match.group("content")

        # Parse fields
        fields: list[Field] = []
        field_lines: list[str] = [line.strip() for line in fields_content.split('\n') if line.strip()]

        for line in field_lines:
            # Skip empty lines and lines without semicolons
            if not line or ';' not in line:
                continue

            # match field type, name, array size (if any), and index namer (if any)
            parts_pattern = re.compile(r"(?P<type>.+?)\s+(?P<name>[*\w]+)\s*(\[(?P<array_size>[\d\w\s+_]+)\])?;(\s*//\s*index:\s*(?P<indexname>\w+))?")
            parts_match = re.search(parts_pattern, line)
            if not parts_match: continue
            if array_match:= parts_match.group("array_size"):
                field_type = parts_match.group("type").strip()
                field_name = parts_match.group("name")
                array_size = array_match
                fields.append(Field(name=field_name, type=field_type, array_size=array_size, array_index_name=parts_match.group("indexname")))
            else:
                # Regular field
                parts = parts_match.group("type"), parts_match.group("name")
                if len(parts) == 2:
                    field_type = parts[0].strip()
                    field_name = parts[1]
                    fields.append(Field(type=field_type, name=field_name))

        structs.append(Struct(struct_name, fields))

    return structs

def print_struct(struct: Struct) -> None:
    indent = "  "
    print(f"Struct: {struct.name}")
    for field in struct.fields:
        if field.array_size is not None:
            indexname:str = field.array_index_name if field.array_index_name else ""
            print(f"{indent}{field.type} {field.name}[{indexname}{"(" if indexname else ""}{field.array_size}{")" if indexname else ""}]")
        else:
            print(f"{indent}{field.type} {field.name}")

def loop_var(index: int) -> str:
    return chr(ord('i') + index)

def traverse_struct(struct_name: str, structs: List[Struct], visited: Optional[Set[str]] = None, parent_path: List[HasName] | None = None, loop_index:int = 0, loop_name_funcs: Iterable[str] | None = None) -> Generator[str]:
    """
    Recursively traverse a struct and all its nested structs, yielding print statements
    to export each nonzero field.

    Args:
        struct_name: Name of the struct to traverse
        structs: List of all available structs
        visited: Set of already visited struct names to prevent cycles
        parent_path: Path to the current field (for nested structs)

    Yields:
        Tuple[str, Field]: A tuple containing (path_to_field, field)
    """
    if visited is None:
        visited = set()

    # Prevent infinite recursion in case of circular references
    if struct_name in visited:
        return

    visited.add(struct_name)

    if loop_name_funcs is None:
        loop_name_funcs = []

    # Find the named struct
    target_struct = next((s for s in structs if s.name == struct_name), None)
    if not target_struct:
        raise ValueError(f"Could not find struct with name {struct_name}")

    for field in target_struct.fields:
        if field.array_size: yield f"{"  " * loop_index}for (int {loop_var(loop_index)} = 0; {loop_var(loop_index)} < {field.array_size}; {loop_var(loop_index)}++){{"
        # Create the path to this field
        field_path = parent_path + [field] if parent_path else [field]

        # Check if field type is another struct
        field_type = field.type.strip()
        if field_type in [s.name for s in structs]:
            # For nested structs, yield their fields with updated path
            yield from traverse_struct(field_type, structs, visited=visited, parent_path=field_path, loop_index=loop_index+1, loop_name_funcs=loop_name_funcs + [field.array_index_name])
        else:
            yield generate_print_from_path(field_path, loop_index + 1, loop_name_funcs + [field.array_index_name])

        if field.array_size: yield f"{"  " * loop_index}}}" # Closing } for loop
    if loop_index == 0: yield "" # Put empty lines between top-level Structs

def generate_print_from_path(field_path: List[HasName], loop_index:int=0, loop_name_funcs: Iterable[str] | None = None) -> str:
    """Given a list of Fields in the order they are nested within Structs,
    Generate the appropriate print statement
    """
    stat_path = field_path[0].name
    stat_name = field_path[0].name
    loop_vars: list[str] = []
    for i, field in enumerate(field_path[1:]):
        previous_field_name = field_path[i].name
        if "*" in previous_field_name or previous_field_name == DEFAULT_ROOT_NAME:
            stat_path += "->"
        else:
            stat_path += "."
        stat_path += field.name.strip("*")
        stat_name += "." + field.name.strip("*")

        if isinstance(field, Field) and field.array_size:
            stat_path += f"[{loop_var(i)}]"
            if loop_name_funcs[i]: # Look up indices by name
                stat_name += "[%s]"
                loop_vars.append(f"{loop_name_funcs[i]}[{loop_var(i)}]")
            else:
                stat_name += f"[%d]"
                loop_vars.append(loop_var(i))
    return f"""if ({stat_path} != 0) {{fprintf(out, \"{stat_name}: %" PRIu64 "\\n", {",".join(loop_vars) + "," if loop_vars else ""} {stat_path});}}"""

def main():
    with open(PYSTATS_FILE, 'r') as f:
        content = f.read()

    structs = parse_structs(content)
    root = next(s for s in structs if s.name == DEFAULT_ROOT_NAME)
    assert root

    with open(OUTPUT_FILE, "w+") as f:
        f.write(PREAMBLE + "\n")
        for line in traverse_struct(DEFAULT_ROOT_NAME, structs,  parent_path=[root]):
            f.write(line + "\n")
        f.write(POSTAMBLE)

if __name__ == "__main__":
    # TODO implement some argument parsing to allow different
    # input and output files, while maintaining the defaults
    main()
