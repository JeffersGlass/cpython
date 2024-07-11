import argparse
import csv
import enum
import functools
import operator
import pathlib
import re
import typing

TOOLS_SCRIPTS = pathlib.Path(__file__).resolve().parent
TOOLS = TOOLS_SCRIPTS.parent
CPYTHON = TOOLS.parent
JIT_STENCILS = CPYTHON / "jit_stencils.h"

class Result(enum.Enum):
    over = 31
    same = 33
    under = 32

class ScoreSet(typing.NamedTuple):
    ops: typing.List[str]
    singles_score: int
    sequence_score: int
    ratio: float
    result: Result

supernode_pattern = re.compile(r"static const unsigned char (?P<fullname>([A-Z0-9_]+)(_PLUS_([A-Z_]+))+)_code_body\[(?P<length>\d+)\] = {")
op_pattern = re.compile(r"static const unsigned char (?P<fullname>[A-Z0-9_]+)_code_body\[(?P<length>\d+)\] = {")
anynode_pattern = re.compile(r"\s*\[(?P<fullname>_([A-Z0-9_]+)+)\] = \{emit_(?P=fullname), (?P<length>\d+)")

"""Copied wholesale from pyperf, under the MIT license

The MIT License (MIT)
Copyright 2016, Red Hat, Inc. and Google Inc.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

"""
class MarkDownTable:
    def __init__(self, headers, rows):
        self.headers = headers
        self.rows = rows
        self.widths = [len(header) for header in self.headers]
        for row in self.rows:
            for column, cell in enumerate(row):
                self.widths[column] = max(self.widths[column], len(cell))

    def _render_line(self, char='-'):
        parts = ['']
        for idx, width in enumerate(self.widths):
            if idx == 0:
                parts.append(char * (width + 2))
            else:
                parts.append(f':{char * width}:')
        parts.append('')
        return '|'.join(parts)

    def _render_row(self, row):
        parts = ['']
        for width, cell in zip(self.widths, row):
            parts.append(" %s " % cell.ljust(width))
        parts.append('')
        return '|'.join(parts)

    def render(self, write_line):
        write_line(self._render_row(self.headers))
        write_line(self._render_line('-'))
        for row in self.rows:
            write_line(self._render_row(row))

def output_scores(
        sequences: typing.Iterable[typing.Iterable[str]],
        factor: float,
        output_mode = "text",
        output_means = print
    ) -> None:
    factor = (1-factor) # Work with a total percentage, rather than a percentage difference
    scores = sorted(calculate_scores(sequences, factor), key=operator.itemgetter(3))
    match output_mode:
        case "text":
            for scoreset in scores:
                print(f"\033[{scoreset.result.value}mUOps {", ".join(scoreset.ops)}\n\t  Percentage:  %{round(100 * scoreset.ratio, 2)}\n\tSum of Parts: {scoreset.singles_score:> 3}\n\t    Together: {scoreset.sequence_score:> 4}\033[0m\n")
        case "table":
            headers = ["UOps", "Sum of Individual Ops", "Lengths When Compiled Together", "Percentage"]
            rows = [(' / '.join(s.ops), str(s.singles_score), str(s.sequence_score), str(round(s.ratio*100, 2)) + "%") for s in scores]
            MarkDownTable(headers, rows).render(output_means)
        case "raw":
            headers = ["uops", "individual_sum", "compiled_together", "ratio"]
            for scoreset in scores:
                print(",".join([" + ".join(scoreset.ops),str(scoreset.singles_score),str(scoreset.sequence_score),str(scoreset.ratio)]))
        case _:
            raise ValueError(f"No output mode called {output_mode}")

def calculate_scores(sequences: typing.Iterable[typing.Iterable[str]], factor) -> typing.List[ScoreSet]:
    scores = []
    for s in sequences:
        opscores = [score_single_instruction(op) for op in s]
        sequence_score = score_sequence(s)
        ratio = sequence_score / sum(opscores)
        result = Result.over if ratio > (1/factor) else (Result.under if ratio < factor else Result.same)
        scores.append(ScoreSet(
            ops = s,
            singles_score = sum(opscores),
            sequence_score=sequence_score,
            ratio = ratio,
            result = result
        ))
    return scores


def score_sequence(uops: typing.Iterable[str]) -> int:
    if stencil_scores := get_scores_from_stencils_h():
        return stencil_scores['_PLUS_'.join(uops)]
    else:
        raise NotImplementedError("Have not yet implemented scoring sequences of uops by hand")

@functools.cache
def get_scores_from_stencils_h() -> dict[str, int] | None:
    scores = {}
    if JIT_STENCILS.exists():
        with open(JIT_STENCILS, "r") as f:
            for line in f.readlines():
                if m:= re.match(anynode_pattern, line):
                    scores[m.group("fullname")] = int(m.group("length"))

    return scores

def score_single_instruction(uop: str) -> int:
    if stencil_scores := get_scores_from_stencils_h():
        return stencil_scores[uop]
    else:
        raise NotImplementedError(f"No score for {uop} (Have not yet implemented scoring individual uops by hand)")


def get_sequences_from_files(inp: pathlib.Path | str):
    sequences = []
    file = pathlib.Path(inp).resolve()
    if not file.exists(): raise ValueError(f"Input '{inp}' does not match any known file")

    match file.suffix.lower():
        case '.csv':
            sequences.extend(get_sequences_from_csv(file))
        case '.h':
            sequences.extend(get_sequences_from_stencil_file(file))
        case _:
            raise ValueError(f"Input '{inp} must have file extension .csv or .h'")
    return sequences


def get_sequences_from_csv(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    path = pathlib.Path(path)
    with open(path, "r") as f:
        return [line for line in csv.reader(f)]


def get_sequences_from_stencil_file(path: pathlib.Path | str) -> typing.List[typing.List[str]]:
    path = pathlib.Path(path)
    sequences = []
    #supernode_pattern = re.compile(r"static const unsigned char (?P<fullname>([A-Z_]+)(plus([A-Z_]+))+)_code_body\[(\d+)\] = {")
    supernode_pattern = re.compile(r"\s*\[(?P<fullname>_([A-Z0-9_]+)(PLUS([A-Z0-9_]+))+)\] = \{emit_(?P=fullname), (?P<length>\d+)")
    with open(path, "r") as f:
        for line in f.readlines():
            if m:= re.match(supernode_pattern, line):
                sequences.append(m.group("fullname").split("_PLUS_"))

    return sequences

def get_sequences_from_string(s: str) -> typing.List[typing.List[str]]:
    return [[op.strip() for op in s.split(",")], ]

def configure_parser(p: argparse.ArgumentParser):
    p.add_argument(
        "--input",
        type=str,
        default=[JIT_STENCILS],
        help="""
        Input files(s).
        Each file may be:
            (1) A .csv file containing lists of UOps
            (2) A .h file that 'looks like' jit_stencils.h - all multi-uop pairs
                will be scored
        """,
    )

    p.add_argument(
        "-s",
        "--string",
        type=str,
        help=f"""
        A comma-separated list of UOp names
        """,
        required=False
    )

    p.add_argument(
        "--significance-factor",
        type=float,
        default=0.1,
        help="""
            The factor by which the change in score must be different to apply
            coloring rules. Defaults to .1.
        """
    )

    p.add_argument(
        "--output_mode",
        type = str,
        required=False,
        choices = ["text", "table", "raw"],
        help = """
            The formatting of the output contents.
        """,
    )

    p.add_argument(
        "--table",
        action="store_true",
        help = """
            Shorthand for output_mode = "table"
        """
    )

    return p

def main():
    parser = argparse.ArgumentParser(description="Score JIT sequences for condensability.")
    configure_parser(parser)

    args = parser.parse_args()
    if args.string and args.inputs:
        raise parser.error("Cannot provide both a -s string and file inputs")

    if args.inputs:
        input_func = get_sequences_from_files
    elif args.string:\
        input_func = get_sequences_from_string
    else:
        raise parser.error("Must provide at least one file input or -s string")

    if args.output_mode and args.output_mode != "table" and args.table:
        parser.error(f"Cannot provide --output_mode={args.output_mode}")
    if not args.output_mode:
        output_mode = "table" if args.table else "text"

    output_scores(input_func(args.inputs), args.significance_factor, output_mode=args.output_mode or output_mode)

if __name__ == "__main__":
    main()
