import contextlib
import io
import pdb

def test1():
    out = io.StringIO()

    with contextlib.redirect_stdout(out) as f:
        print("Hello, world!")
            

    print("---")
    print(f"Out was: {out.getvalue()}")

def test2():
    out = io.StringIO()

    with contextlib.redirect_stdout(out) as f:
        exec("print('hello, world!')")

    print("---")
    print(f"Out was: {out.getvalue()}")


def test3():
    out = io.StringIO()

    with contextlib.redirect_stdout(out) as f:
        pass#    exec("""pdb.run('print("hello, word!")')""")

    print("---")
    print(f"Out was: {out.getvalue()}")

def test4():
    out = io.StringIO()

    exec("""pdb.run('print("hello, word!")')""")

    print("---")
    print(f"Out was: {out.getvalue()}")

#test4()

import os
import sys
def test5():
    c = io.StringIO()
    with contextlib.redirect_stdout(c):
        print("Hello, world!")

    print(f"Out was: {c.getvalue()}")

#test5()

import typing
import textual

class Callbacker(io.StringIO):
    def __init__(self, out, callback=None, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._out: io.BufferedIOBase = out
        self._callback: typing.Callable = callback

    def __enter__(self, out):
        self._out = out

    def __exit__(self):
        pass

        
    def write(self, *args, **kwargs):
        #self._out.write(*args, **kwargs)
        if self._callback: self._callback()

def test6():
    c = Callbacker(sys.stdout, lambda: 0)
    with contextlib.redirect_stdout(c) as f:
        print("Hello!")

test6()

