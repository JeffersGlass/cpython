from dataclasses import dataclass, field
from pathlib import Path
import re
from typing import Self, Generator, Union


## TODO
## Think about a refactor: structs have dictionaries of members, where the key the name of the attribute
## And the values are the members
## A "STAT" has a type (uint64_t, or another struct) and may or may not be an array
## Stats themselves do not have names
##

DEFUALT_ROOT_NAME = "PyStats"

@dataclass
class Stat:
    name: str


@dataclass
class SimpleStat(Stat):
    ...

@dataclass
class ArrayStat(Stat):
    value_type: Union[str, "Struct"]
    #size: str


@dataclass
class HistogramStat(Stat):
    value_type: Union[str, "Struct"]
    #size: str

@dataclass
class Unresolved:
    _type: str
    name: str

@dataclass
class Struct:
    _type: str
    name: str = ""
    members: list[Stat | Self] = field(default_factory=list)
    unresolved_members: list[Unresolved] = field(default_factory=list)

def text_to_struct(text: str, root=False) -> Struct:
    lines = [line.strip() for line in text.split("\n")] # remove blank links
    assert re.match(r"typedef struct [_a-zA-Z]+ {", lines[0])
    assert (m := re.match(r"} (?P<type>[_a-zA-Z]+)", lines[-1]))
    struct_type = m.group("type")

    members: list[Stat | Struct] = []
    unresolved: list[str] = []
    for line in lines[1:-1]:
        m = re.match(r"(?P<type>[_a-zA-Z0-9]+) (?P<name>[_a-zA-Z0-9]+)", line)
        if not m: continue
        _type, _name = m.group("type"), m.group("name")

        if _type == "uint64_t":
            if "[" in line: # Some kind of array or histogram type
                if "_hist" in _name:
                    members.append(HistogramStat(name = _name, value_type=_type))
                else:
                    members.append(ArrayStat(name = _name, value_type=_type))
            else:
                members.append(SimpleStat(name = _name))
        else:
            unresolved.append(Unresolved(_type=_type, name=_name))

    if root: name = "ROOT"
    else: name = ""

    return Struct(_type=struct_type, members=members, unresolved_members=unresolved)

def generate_prints_from_tree(s: Struct) -> Generator[str]:
    """Given a struct, walk its members and yield print statements for any stats encountered"""
    ...

def analyze_file(f: str | Path, root_name = DEFUALT_ROOT_NAME) -> Struct:
    """Parse the tree of structs from pystats.h and return the root Struct"""
    ...

def generate_print_statement(path: list[Stat | Struct]) -> str:
    return f"""fprintf(out, {'.'.join(p.name for p in path)}": %" PRIu64 "\\n", stats->{'->'.join(p.name for p in path)});"""

def main():
    tree = analyze_file("Include/CPython/pystats.h")
    with open("print_stat.c or something", "w+") as f:
        for line in generate_prints_from_tree(tree):
            f.write(line)

if __name__ == "__main__":
    main()


class Tests:
    def test_generate_simple_print(self):
        a = Stat("foo")
        b = SimpleStat("bar")
        c = HistogramStat("baz", value_type="uint64_t")
        d = Struct("_root", "bok", [a, b])

        assert generate_print_statement([a, b]) == """fprintf(out, foo.bar": %" PRIu64 "\\n", stats->foo->bar);"""
        assert generate_print_statement([a, b, c]) == """fprintf(out, foo.bar.baz": %" PRIu64 "\\n", stats->foo->bar->baz);"""
        assert generate_print_statement([a, b, c, d]) == """fprintf(out, foo.bar.baz.bok": %" PRIu64 "\\n", stats->foo->bar->baz->bok);"""

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
        assert all(type(member) == SimpleStat for member in result.members)

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
        assert all(isinstance(member, Stat) for member in result.members)

        assert len(result.unresolved_members) == 1
        assert type(r := result.unresolved_members[0]) == Unresolved
        assert r._type == "UOpStats"
        assert r.name == "opcode"
