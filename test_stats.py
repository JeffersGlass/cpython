import difflib
import pathlib
import sys
import typing

STATS_FOLDER = pathlib.Path("/tmp/py_stats")

def get_stats(a: typing.Callable[..., typing.Any]) -> list[str]:
    initial_stats_files = set(p for p in STATS_FOLDER.iterdir() if p.is_file())
    #sys._stats_clear()
    sys._stats_on()
    a()
    sys._stats_off()
    #sys._stats_dump()
    maybe_a_new_file = set(p for p in STATS_FOLDER.iterdir() if p.is_file()) - initial_stats_files
    if maybe_a_new_file:
        a_new_file = maybe_a_new_file.pop()
        with open(a_new_file, "r") as f:
            return f.readlines()
    else:
        return ["foo", "bar"]
    
def select_uop_lines(l: typing.Iterable[str]) -> list[str]:
    return [line for line in l if line.startswith("Uop sequence count")]

def compare_stats(a: typing.Callable[..., typing.Any], b: typing.Callable[..., typing.Any]):
    for line in difflib.context_diff(select_uop_lines(get_stats(a)), select_uop_lines((get_stats(b)))):
        print(line)
    

def _a():
    x = 0
    for i in range(1000):
        x+=i

def _b():
    y = []
    for i in range(1000):
        if i % 2: y.append(i)

if __name__ == "__main__":
    ...
    #Create command line interface for comparing stats output for two files as callables
    compare_stats(_a, _b)