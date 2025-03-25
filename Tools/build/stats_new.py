import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional, Set, Generator

DEFUALT_ROOT_NAME = "PyStats"
CPYTHON_ROOT_DIR = Path(__file__).parent.parent.parent
PYSTATS_FILE = CPYTHON_ROOT_DIR / "Include" / "cpython" / "pystats.h"

@dataclass
class Field:
    type: str
    name: str
    array_size: Optional[str] = None

@dataclass
class Struct:
    name: str
    fields: List[Field]

def parse_structs(content: str) -> List[Struct]:
    # Remove comments
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    content = re.sub(r'//.*$', '', content, flags=re.MULTILINE)

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

            # Remove semicolon and split into type and name
            field_def = line.rstrip(';').strip()

            # Handle array fields
            array_match = re.match(r'(.+?)\s+(\w+)\s*\[([\d\w\s+_]+)\]', field_def)
            if array_match:
                field_type = array_match.group(1).strip()
                field_name = array_match.group(2)
                array_size = array_match.group(3)
                fields.append(Field(field_type, field_name, array_size))
            else:
                # Regular field
                parts = field_def.rsplit(' ', 1)
                if len(parts) == 2:
                    field_type = parts[0].strip()
                    field_name = parts[1]
                    fields.append(Field(field_type, field_name))

        structs.append(Struct(struct_name, fields))

    return structs

def print_struct(struct: Struct) -> None:
    indent = "  "
    print(f"Struct: {struct.name}")
    for field in struct.fields:
        if field.array_size is not None:
            print(f"{indent}{field.type} {field.name}[{field.array_size}]")
        else:
            print(f"{indent}{field.type} {field.name}")

def loop_var(index: int) -> str:
    return chr(ord('i') + index)

def traverse_struct(struct_name: str, structs: List[Struct], visited: Optional[Set[str]] = None, parent_path: List[Field] | None = None, loop_index:int = 0) -> Generator[str]:
    """
    Recursively traverse a struct and all its nested structs, yielding each field.

    Args:
        struct_name: Name of the struct to traverse
        structs: List of all available structs
        visited: Set of already visited struct names to prevent cycles
        parent_path: Path to the current field (for nested structs)

    Yields:
        Tuple[str, Field]: A tuple containing (path_to_field, field)
    """
    if loop_index == 0: yield f"// {struct_name}"
    if visited is None:
        visited = set()

    # Prevent infinite recursion in case of circular references
    if struct_name in visited:
        return

    visited.add(struct_name)

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
            yield from traverse_struct(field_type, structs, visited=visited, parent_path=field_path, loop_index=loop_index+1)
        else:
            yield generate_print_from_path(field_path, loop_index + 1)

        if field.array_size: yield f"{"  " * loop_index}}}"
    if loop_index == 0: yield ""

def generate_print_from_path(field_path: List[Field], loop_index:int=0) -> str:
    stat_path = field_path[0].name
    stat_name = field_path[0].name
    loop_vars: list[str] = []
    for i, field in enumerate(field_path[1:]):
        previous_field_name = field_path[i-1+1].name
        if "*" in previous_field_name or previous_field_name == 'stats':
            stat_path += "->"
        else:
            stat_path += "."
        stat_path += field.name.strip("*")
        stat_name += "." + field.name.strip("*")

        if field.array_size: 
            stat_path += f"[{loop_var(i)}]"
            stat_name += f"[%d]"
            loop_vars.append(loop_var(i))

    #fprintf(out, "GC[%d] objects reachable from roots: %" PRIu64 "\n", i, stats[i].objects_transitively_reachable);
    return f"""if ({stat_path} != 0) {{fprintf(out, \"{stat_name}: %" PRIu64 "\\n", {",".join(loop_vars) + "," if loop_vars else ""} {stat_path});}}"""
    return f"NONZERO_PRINT({stat_path.replace("->", ".")}, {stat_path});"

def main():
    # Read the header file
    with open(PYSTATS_FILE, 'r') as f:
        content = f.read()

    # Parse structs
    structs = parse_structs(content)
    root = next(s for s in structs if s.name == DEFUALT_ROOT_NAME)
    assert root
    root.name = "stats" # need to refer to the 

    for line in traverse_struct("stats", structs,  parent_path=[root]):
        print(line)

if __name__ == "__main__":
    main()
