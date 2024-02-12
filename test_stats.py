import difflib
import inspect
import multiprocessing as mp
import subprocess
import pathlib
import os
import sys
import tempfile
import textwrap
import typing
import uuid

STATS_FOLDER = pathlib.Path("/tmp/py_stats")

def get_stats(c: typing.Callable[..., typing.Any]) -> list[str]:
    initial_stats_files = set(p for p in STATS_FOLDER.iterdir() if p.is_file())
    source = ''.join(inspect.getsourcelines(c)[0][1:])
    print(f"Getting stats for callable with code\n{source}")

    #filename = str(uuid.uuid4()) + ".py"
    #with open("./" + filename, "w") as temp:
    with tempfile.NamedTemporaryFile(suffix=".py", mode="w") as temp:
        temp.write(textwrap.dedent(source))

        #sys._stats_clear()
        #sys._stats_on()
        #subprocess.run(["./python", "-X", "pystats", temp.name], shell=True, env={"PYTHON_UOPS": "1"}, timeout=1)
        #subprocess.run([f"PYTHON_UOPS=1 ./python -X pystats {temp.name}"], shell=True, env={"PYTHON_UOPS": "1"}, timeout=1, capture_output=True)
        #p.start()
        #p.join(1)
        #os.environ['PYTHON_UOPS'] = "1"
        #with mp.get_context('spawn').Pool() as p:
        #    #p.apply_async(c).get()

        #p = subprocess.Popen(f"PYTHON_UOPS=1; ./python -X pystats {temp.name}")
        #p.wait()
        os.system(f"PYTHON_UOPS=1 /home/jglass/Documents/cpython/python -X pystats {temp.name} &> /home/jglass/Documents/cpython/out.txt")
        #os.spawnve(os.P_WAIT, "./python", ["./python", "-X pystats", temp.name], {"PYTHON_UOPS": "1"})
        #os.spawnvpe(os.P_NOWAIT, "./python", ["./python", "-X pystats", temp], {"PYTHON_UOPS": 1})

        while not (maybe_a_new_file := set(p for p in STATS_FOLDER.iterdir() if p.is_file()) - initial_stats_files):
            pass
        #sys._stats_off()
        #sys._stats_dump()
    
    #maybe_a_new_file = set(p for p in STATS_FOLDER.iterdir() if p.is_file()) - initial_stats_files
    if maybe_a_new_file:
        a_new_file = maybe_a_new_file.pop()
        print(f"Found a new stats file {a_new_file}")
        with open(a_new_file, "r") as f:
            return f.readlines()
    else:
        print("No new stats file found")
        return []
    
def select_uop_lines(l: typing.Iterable[str]) -> list[str]:
    result = [line for line in l if line.startswith("UOp sequence count")]
    print(f"Selected {len(result)} uop lines")
    return result

def compare_stats(a: typing.Callable[..., typing.Any], b: typing.Callable[..., typing.Any]) -> typing.Generator[str, None, None]:
    #print("Comparing stats")
    return (line for line in difflib.context_diff(select_uop_lines(get_stats(a)), select_uop_lines((get_stats(b)))))
    

def _a():
    import os
    print(f"{os.environ['PYTHON_UOPS']=}")
    x = 0
    for i in range(1000):
        x+=i
    print(f"{x=}")

def _b():
    import os
    print(f"{os.environ['PYTHON_UOPS']=}")
    y = []
    for i in range(1000):
        if i % 2: y.append(i)
    print(f"{y=}")

if __name__ == "__main__":
    ...
    #Create command line interface for comparing stats output for two files as callables
    os.environ['PYTHON_UOPS'] = "1"
    #mp.set_start_method("fork")
    for line in compare_stats(_a, _b):
        print(line)