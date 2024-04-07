"""Build an experimental just-in-time compiler for CPython."""
import argparse
import pathlib
import shlex
import sys

import _opfile
import _targets

if __name__ == "__main__":
    comment = f"$ {shlex.join([sys.executable] + sys.argv)}"
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "target", type=_targets.get_target, help="a PEP 11 target triple to compile for"
    )
    parser.add_argument(
        "-d", "--debug", action="store_true", help="compile for a debug build of Python"
    )
    parser.add_argument(
        "-f", "--force", action="store_true", help="force the entire JIT to be rebuilt"
    )
    parser.add_argument(
        "--file", default='', help="Filepath to a csv of superinstructions to build" 
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="echo commands as they are run"
    )
    args = parser.parse_args()
    args.target.debug = args.debug
    args.target.force = args.force
    args.target.verbose = args.verbose
    args.target.build(pathlib.Path.cwd(), _opfile._retrieve_ops_from_path(args.file) if args.file else None, comment=comment)
