"""Build an experimental just-in-time compiler for CPython."""

import argparse
import pathlib

import _targets
import _opfile

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "target", type=_targets.get_target, help="a PEP 11 target triple to compile for"
    )
    parser.add_argument(
        "--file", default='', help="Filepath to a csv of opname combinations to build" 
    )
    parser.add_argument(
        "-F", "--force", action="store_true", help="force a rebuild even if nothing's changed"
    )
    parser.add_argument(
        "-d", "--debug", action="store_true", help="compile for a debug build of Python"
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="echo commands as they are run"
    )
    args = parser.parse_args()
    args.target.debug = args.debug
    args.target.verbose = args.verbose
    args.target.build(pathlib.Path.cwd(), _opfile._retrieve_ops_from_path(args.file) if args.file else None, force=args.force)
