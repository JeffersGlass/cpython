from dataclasses import dataclass, field
from pathlib import Path
import re
from typing import Self, Generator, Union, Literal, cast, NamedTuple
from enum import Enum

DEFUALT_ROOT_NAME = "PyStats"
CPYTHON_ROOT_DIR = Path(__file__).parent.parent.parent
PYSTATS_FILE = CPYTHON_ROOT_DIR / "Include" / "cpython" / "pystats.h"

@dataclass
class Stat:
    _type: str
    array_size: str = ""

class LinkType(Enum):
    pointer = 1
    attribute = 2

@dataclass
class Unresolved:
    _type: str
    name: str
    link_type: LinkType
    array_size: str = ""


Link = NamedTuple("Link", (('link_type', LinkType), ('points_to', Union[Stat, "Struct"])))

@dataclass
class Struct(Stat):
    name: str = ""
    members: dict[str, Link] = field(default_factory=dict)
    unresolved_links: list[Unresolved] = field(default_factory=list)

def text_to_struct(text: str, root=False) -> Struct | None:
    lines = [line.strip() for line in text.split("\n")] # remove blank links
    if not re.match(r"typedef struct [_a-zA-Z]+ {", lines[0]): return None
    if not (m := re.match(r"} (?P<type>[_a-zA-Z]+)", lines[-1])): return None
    struct_type = m.group("type")

    members: dict[str, Link] = {}
    unresolved: list[Unresolved] = []

    for line in lines[1:-1]:
        m = re.match(r"(?P<type>[_a-zA-Z0-9]+)(?P<pointer1>)? (?P<pointer2>)?(?P<name>[_a-zA-Z0-9)]+)(\[(?P<array>[a-zA-Z_ +0-9]+)\])?", line)
        if not m: continue
        _type, _name = m.group("type").replace("*", ""), m.group("name").replace("*", "")

        if m.group('pointer1') or m.group('pointer2'): link_type = LinkType.pointer
        else: link_type = LinkType.attribute

        if a:= m.group("array"): # Some kind of array or histogram type
            array_size = a
        if _type == "uint64_t":
            members[_name] = Link(link_type=link_type, points_to=Stat(_type=_type))
            if a: members[_name].points_to.array_size = a
        else:
            unresolved.append(Unresolved(_type=_type, name=_name, array_size=a if a else "", link_type=link_type))

    return Struct(_type=struct_type, members=members, unresolved_links=unresolved)

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
        working_on = process_list.pop()
        for un in working_on.unresolved_links:
            matching_struct_list = [t for t in structs if t._type == un._type]
            if not matching_struct_list: raise ValueError(f"No known structs of type {un._type}")
            assert len(matching_struct_list) == 1, f"Struct {un._type} was defined multiple times"
            m = matching_struct_list[0]
            working_on.members[un.name] = Link(link_type=un.link_type, points_to=m)
            if un.array_size: working_on.members[un.name].points_to.array_size = un.array_size
            if type(working_on.members[un.name].points_to) == Struct:
                if working_on.members[un.name].points_to.unresolved_links: process_list.append(working_on.members[un.name])  #type: ignore[arg-type, union-attr, attr-defined]
        working_on.unresolved_links = []

    return root

def generate_print_statements_from_struct(s: Link, path: list[str | Stat] | None = None, loop_index=0) -> Generator[str]:
    #print(f"Generating print statements from struct {s} and path {path}")
    assert type(s.points_to) == Stat or not s.points_to.unresolved_links
    if path is None: path = []
    loop_var = chr(loop_index + ord('i'))
    for name, link in s.points_to.members.items():
        #print(f">Examining member {name} : {member}")
        if link.points_to._type == "uint64_t":
            if not link.points_to.array_size:
                #print(">>member is simple uint64 and has no array size")
                yield generate_print_from_path(path + [name])
            else:
                yield f"for (int {loop_var} = 0; {loop_var} < {link.points_to.array_size}; {loop_var}++){{"
                yield generate_print_from_path(path + [name], loop_var)
                yield "}"
        else:
            if not link.points_to.array_size:
                yield from generate_print_statements_from_struct(link, path + [name], loop_index + 1)
            else: #array of structs
                yield f"for (int {loop_var} = 0; {loop_var} < {link.points_to.array_size}; {loop_var}++){{"
                yield from generate_print_statements_from_struct(link, path + [name + f"[{loop_var}]"], loop_index + 1)
                yield "}"

    ## TODO only partly through re-categorizing things from Structs to Links
    ## Maybe there's a better way to do this as a single pass through the input...
    ## pushing and popping IDs from a stack...

    #"""fprintf(out, foo.bar": %" PRIu64 "\\n", stats->foo->bar);"""

def generate_print_from_path(path: list[str | Stat], index: str | None =None) -> str:
    #print(f">>printing from path {path}")
    index_string = f"[{index}]" if index else ""
    namer = lambda x: x.name if hasattr(x, 'name') else x
    return f"""\tfprintf(out, "{'.'.join((namer(p) if namer(p) != "PyStats" else "stats") for p in path)}{index_string}: %" PRIu64 "\\n", {'.'.join((namer(p) if namer(p) != "PyStats" else "stats") for p in path)}{index_string});"""

def main():
    root = analyze_file(PYSTATS_FILE)
    with open(CPYTHON_ROOT_DIR / "data.txt", "w+") as f:
        for line in generate_print_statements_from_struct(root, [root]):
            f.write(line + "\n")

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

        assert not result.unresolved_links

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

        assert len(result.unresolved_links) == 1
        assert type(r := result.unresolved_links[0]) == Unresolved
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

        root = analyze_contents(a)
        assert type(root) == Struct
        assert root._type == "PyStats"
        assert root.name == "PyStats"
        assert len(root.members) == 6
        assert not root.unresolved_links

        #for r in result.members.values():
        #    print(r)

        assert sum(1 for m in root.members.values() if m._type == "uint64_t") == 4
        assert sum(1 for m in root.members.values() if m._type == "UOpStats") == 1
        assert sum(1 for m in root.members.values() if m._type == "Foo") == 1
        assert sum(1 for m in root.members.values() if m.array_size) == 4

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

        #for l in lines:
        #    print(l)

        # The stats which are single variables in PyStats, or arrays in PyStats,
        # Only have one print statement associated with them
        for name in ['attempts', 'unsupported_opcode', 'dummy_hist', 'trace_length_hist']:
            assert sum((1 if name in line else 0) for line in lines) == 1

        # There is only one copy of the Foo struct, so it's stats should only be printed once
        for foo in ['foo_a']:
            assert sum([(1 if foo in line else 0) for line in lines]) == 1

        ## Check that attributes of structs, and attribute sof structs that are arrays, do print
        assert sum((1 if """fprintf(out, stats.opcode[i].d": %" PRIu64 "\\n", stats->opcode[i]->d);""" in line else 0) for line in lines) == 1
        assert sum((1 if """fprintf(out, stats.opcode[i].f[j]": %" PRIu64 "\\n", stats->opcode[i]->f[j]);""" in line else 0) for line in lines) == 1

    def test_parse_pystat_h(self):
        with open(PYSTATS_FILE, "r") as f:
            data = f.read()

        root = analyze_contents(data)

        assert type(root) == Struct
        assert root._type == "PyStats"
        assert root.name == "PyStats"
        assert len(root.members) == 6
        assert not root.unresolved_links
