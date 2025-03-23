from dataclasses import dataclass, field
from pathlib import Path
import re
from typing import Self, Generator, Union

DEFUALT_ROOT_NAME = "PyStats"
CPYTHON_ROOT_DIR = Path(__file__).parent.parent.parent

@dataclass
class Stat:
    _type: str
    array_size: str = ""

@dataclass
class Unresolved:
    _type: str
    name: str
    array_size: str = ""

@dataclass
class Struct(Stat):
    name: str = ""
    members: dict[str, Stat | Self] = field(default_factory=dict)
    unresolved_members: list[Unresolved] = field(default_factory=list)

def text_to_struct(text: str, root=False) -> Struct | None:
    lines = [line.strip() for line in text.split("\n")] # remove blank links
    if not re.match(r"typedef struct [_a-zA-Z]+ {", lines[0]): return
    if not (m := re.match(r"} (?P<type>[_a-zA-Z]+)", lines[-1])): return
    struct_type = m.group("type")

    members: dict[str, Stat | Struct] = {}
    unresolved: list[Unresolved] = []

    for line in lines[1:-1]:
        m = re.match(r"(?P<type>[_a-zA-Z0-9]+) (?P<name>[_a-zA-Z0-9]+)(\[(?P<array>[a-zA-Z_ +0-9]+)\])?", line)
        if not m: continue
        _type, _name = m.group("type"), m.group("name")

        if a:= m.group("array"): # Some kind of array or histogram type
            array_size = a
        if _type == "uint64_t":
            members[_name] = Stat(_type=_type)
            if a: members[_name].array_size = a
        else:
            unresolved.append(Unresolved(_type=_type, name=_name, array_size=a if a else ""))

    return Struct(_type=struct_type, members=members, unresolved_members=unresolved)

def analyze_file(p: str | Path) -> Struct:
    with open(p, "r") as f:
        return analyze_contents(f.read())

def analyze_contents(contents: str, root_name = DEFUALT_ROOT_NAME) -> Struct:
    root = None
    structs: list[Struct] = []
    for block in contents.split("\n\n"):
        if struct:= text_to_struct(block):
            if struct._type == root_name:
                struct.name = root_name
                root = struct
            structs.append(struct)

    if not root: raise ValueError(f"Did not find root with name {root_name} in contents")

    process_list = [root]
    while process_list:
        #print("===========")
        #print(f"{process_list=}")
        working_on = process_list.pop()
        #print(f"{working_on=}")
        for un in working_on.unresolved_members:
            #print(f"{un=}")
            matching_struct_list = [t for t in structs if t._type == un._type]
            if not matching_struct_list: raise ValueError(f"No known structs of type {un._type}")
            assert len(matching_struct_list) == 1, f"Struct {un._type} was defined multiple times"
            m = matching_struct_list[0]
            working_on.members[un.name] = m
            if un.array_size: working_on.members[un.name].array_size = un.array_size
            if working_on.members[un.name].unresolved_members: process_list.append(working_on.members[un.name])
        working_on.unresolved_members = []

    return root

def generate_print_statements_from_struct(s: Struct, path: list[Stat] | None = None, loop_index=0) -> Generator[str]:
    #print(f"Generating print statements from struct {s} and path {path}")
    assert not s.unresolved_members
    if path is None: path = []
    for name, member in s.members.items():
        #print(f">Examining member {name} : {member}")
        if member._type == "uint64_t":
            if not member.array_size:
                #print(">>member is simple uint64 and has no array size")
                yield generate_print_from_path(path + [name])
            else:
                loop_var = chr(loop_index + ord('i'))
                yield f"for (int {loop_var} = 0; {loop_var} < {member.array_size}; {loop_var}++){{"
                yield generate_print_from_path(path + [name], loop_var)
                yield "}"
        else: # Sub-struct
            if not member.array_size:
                yield from generate_print_statements_from_struct(member, path + [name], loop_var)
            else: #array of structs
                loop_var = chr(loop_index + ord('i'))
                yield f"for (int {loop_var} = 0; {loop_var} < {member.array_size}; {loop_var}++){{"
                generate_print_statements_from_struct(member, path + [name], loop_var)
                yield "}"
    ## TODO Working here


    #"""fprintf(out, foo.bar": %" PRIu64 "\\n", stats->foo->bar);"""

def generate_print_from_path(path: list[Stat], index: str | None =None) -> str:
    #print(f">>printing from path {path}")
    index_string = f"[{index}]" if index else ""
    namer = lambda x: x.name if hasattr(x, 'name') else x
    return f"""fprintf(out, {'.'.join((namer(p) if namer(p) != "PyStats" else "stats") for p in path)}{index_string}": %" PRIu64 "\\n", {'->'.join((namer(p) if namer(p) != "PyStats" else "stats") for p in path)}{index_string});"""

def main():
    root = analyze_file(CPYTHON_ROOT_DIR / "Include/cpython/pystats.h")
    with open("print_stat.c or something", "w+") as f:
        for line in generate_print_statements_from_struct(root, [root]):
            f.write(line)

if __name__ == "__main__":
    main()


class Tests:
    def test_generate_simple_print(self):
        ...

    def test_simple_text_to_struct(self):
        a = """\
            typedef struct _gc_stats {
                uint64_t collections;
                uint64_t object_visits;
                uint64_t objects_collected;
                uint64_t objects_transitively_reachable;
                uint64_t objects_not_transitively_reachable;
            } GCStats;"""
        result = text_to_struct(a)
        assert result._type == "GCStats"
        assert result.name == ""
        assert len(result.members) == 5
        assert all(type(member) == Stat for member in result.members.values())

        assert not result.unresolved_members

    def test_complex_text_to_struct(self):
        a = """\
            typedef struct _optimization_stats {
                uint64_t attempts;
                UOpStats opcode[PYSTATS_MAX_UOP_ID + 1];
                uint64_t unsupported_opcode[256];
                uint64_t dummy_hist[512];
                uint64_t trace_length_hist[_Py_UOP_HIST_SIZE]
            } OptimizationStats;"""

        result = text_to_struct(a)

        assert result.name == ""
        assert result._type == "OptimizationStats"
        assert len(result.members) == 4
        assert all(isinstance(member, Stat) for member in result.members.values())

        assert len(result.unresolved_members) == 1
        assert type(r := result.unresolved_members[0]) == Unresolved
        assert r._type == "UOpStats"
        assert r.name == "opcode"

    def test_analyze_contents(self):
        a = """\
            typedef struct _foo {
                uint64_t a;
            } Foo;

            #define _Py_UOP_HIST_SIZE 32

            typedef struct _uop_stats {
                uint64_t d;
                uint64_t e;
                uint64_t f[100];
            } UOpStats;

            # A Stray comment

            '''A multiline comment
            Just for flavor
            let's see if it breaks'''

            typedef struct _stats {
                uint64_t attempts;
                Foo foo;
                UOpStats opcode[PYSTATS_MAX_UOP_ID + 1];
                uint64_t unsupported_opcode[256];
                uint64_t dummy_hist[512];
                uint64_t trace_length_hist[_Py_UOP_HIST_SIZE]
            } PyStats;"""

        result = analyze_contents(a)
        assert type(result) == Struct
        assert result._type == "PyStats"
        assert result.name == "PyStats"
        assert len(result.members) == 6
        assert not result.unresolved_members

        #for r in result.members.values():
        #    print(r)

        assert sum(1 for m in result.members.values() if m._type == "uint64_t") == 4
        assert sum(1 for m in result.members.values() if m._type == "UOpStats") == 1
        assert sum(1 for m in result.members.values() if m._type == "Foo") == 1
        assert sum(1 for m in result.members.values() if m.array_size) == 4

    def test_generate_print_statements_from_struct(self):
        a = """\
            typedef struct _foo {
                uint64_t foo_a;
            } Foo;

            #define _Py_UOP_HIST_SIZE 32

            typedef struct _uop_stats {
                uint64_t d;
                uint64_t e;
                uint64_t f[100];
            } UOpStats;

            # A Stray comment

            '''A multiline comment
            Just for flavor
            let's see if it breaks'''

            typedef struct _stats {
                uint64_t attempts;
                Foo foo;
                UOpStats opcode[PYSTATS_MAX_UOP_ID + 1];
                uint64_t unsupported_opcode[256];
                uint64_t dummy_hist[512];
                uint64_t trace_length_hist[_Py_UOP_HIST_SIZE]
            } PyStats;"""

        result = analyze_contents(a)
        lines = list(generate_print_statements_from_struct(result, [result]))
        
        for l in lines:
            print(l)

        # The stats which are single variables in PyStats, or arrays in PyStats,
        # Only have one print statement associated with them
        for solo in ['attempts', 'unsupported_opcode', 'dummy_hist', 'trace_length_hist']:
            assert sum((1 if solo in line else 0) for line in lines) == 1

        

        # There is only one copy of the Foo struct, so it's stats should only be printed once
        for foostat in ['foo_a']:
            assert sum([(1 if foostat in line else 0) for line in lines]) == 1

        # TODO continue fleshing out these tests, and get arrays of structs printing
        