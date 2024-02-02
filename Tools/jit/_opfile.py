""" Utilities for loading a list of UOp sequences from file that
    should be turned into superinstructions
"""

import csv
import pathlib
import typing

import _supernode

def _retrieve_ops_from_path(path: pathlib.Path | str) -> list[_supernode.SuperNode]:
    path = pathlib.Path(path)
    with open(path, "r") as f:
        match path.suffix:
            case ".csv":
                return _retreive_ops_from_csv(path)
            case _:
                raise ValueError(f"File type '{path.suffix}' must be .csv")
            # TODO add more types. .py?
            
def _retreive_ops_from_csv(path: pathlib.Path) -> list[typing.Iterable[str]]:
    with open(path, "r") as f:
        return [_supernode.SuperNode(ops=line) for line in csv.reader(f)]