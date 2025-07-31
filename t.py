from io import StringIO
from pdb import _PdbClient, attach
import subprocess
import sys
from time import sleep
from tempfile import NamedTemporaryFile, TemporaryFile

from textual.app import App, ComposeResult
from textual.widgets import Header, Footer, Label, Log

class TdbApp(App):

    def __init__(self):
        self.client = _PdbClient()

    def compose(self) -> ComposeResult:
        yield Header()
        yield Label("This is the output of the program")
        yield Log()
        yield Footer()

    def foo():
        ...

def test7():
    with TemporaryFile("w+") as t:
        proc = subprocess.Popen([sys.executable, 'x.py'],
                                stdout=t,
                                stderr=subprocess.STDOUT,
                                stdin=None,
                                env = {"PYTHONUNBUFFERED": "1"})
        print(f"{proc.pid=}")
        sleep(.5)
        import pdb
        pdb.attach(proc.pid)

test7()
