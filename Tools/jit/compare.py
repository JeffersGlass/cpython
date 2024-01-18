import argparse
import collections
from dataclasses import dataclass
import os
import pathlib
import re

from build import CPYTHON, PYTHON_EXECUTOR_CASES_C_H, TOOLS_JIT

STENCILS = CPYTHON / "stencils"

class colors:
    GREEN = '\033[92m'
    NUETRAL = '\033[95m'
    RED = '\033[91m'
    ENDC = '\033[0m'

@dataclass
class OpcodeData:
    data_body_length: int = -1
    code_body_length: int = -1

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", help="a PEP 11 target triple to compile for")
    args = parser.parse_args()

    generated_cases = PYTHON_EXECUTOR_CASES_C_H.read_text()
    opnames = sorted(re.findall(r"\n {8}case (\w+): \{\n", generated_cases))
    
    # Extract data about single ops
    with open(CPYTHON / "jit_stencils.h", "r") as f:
        single_ops = extract_opcode_data(f.readlines())


    # Check that all single op data is in generated cased
    for op in single_ops:
        if op not in opnames:
            raise ValueError(f"Captured data for {op} which is not a generated case")
    
    folder = STENCILS / args.target
    if not os.path.isdir(folder):
        raise ValueError(f"{folder} folder does not exist")
    
    run_data_file = pathlib.Path.cwd() / "data.csv"
    data_files = pathlib.Path.iterdir(folder)
    for file_path in data_files:
        if (path:= pathlib.Path(file_path)).suffix != '.h': continue

        first_opcode = path.stem
        if not first_opcode in single_ops:
            raise ValueError(f"Opened file {file_path}, which doesn't correspond to a known opcode with data")
        
        with open(file_path, "r") as f:
            second_opcode_data = extract_opcode_data(f.readlines())
        
        TABLE = "{kind: <17}{first: >30}:{first_val:<3}  {second: >30}:{second_val:<3}  {combined: >69}:{combined_val:<3}  {math}"
        for second_opcode in second_opcode_data:
            print_comparison(first_opcode, second_opcode, single_ops, second_opcode_data, "data_body_length", TABLE)
            print_comparison(first_opcode, second_opcode, single_ops, second_opcode_data, "code_body_length", TABLE)

        
        
def print_comparison(first_opcode: str, second_opcode: str, single_ops, second_opcode_data, attribute, TABLE):
    first_length = getattr(single_ops[second_opcode], attribute)
    second_length = getattr(single_ops[second_opcode], attribute)
    seperate_total = first_length + second_length
    combined_length = getattr(second_opcode_data[second_opcode], attribute)
    color = colors.GREEN if seperate_total > combined_length else (colors.NUETRAL if seperate_total == combined_length else colors.RED)
    math = f"{color}{first_length} + {second_length} {">" if seperate_total > combined_length else ("=" if seperate_total == combined_length else "<")} \t{combined_length}{colors.ENDC}"
    print(TABLE.format(kind=attribute,
                        first=first_opcode,
                        first_val=first_length,
                        second=second_opcode,
                        second_val=second_length,
                        combined=f"{first_opcode}{second_opcode}",
                        combined_val = combined_length,
                        math=math
                        ))
        
def extract_opcode_data(header: list[str]) -> dict[str: OpcodeData]:
    result = {}
    for line in header:
        if m:= re.search(r"(?P<name>[A-Z0-9_]+)_code_body\[(?P<num>\d+)]", line):
            if (name:= m.group("name")) in result: result[name].code_body_length = int(m.group("num"))
            else: result[name] = OpcodeData(code_body_length=int(m.group("num")))
        elif m:= re.search(r"(?P<name>[A-Z0-9_]+)_data_body\[(?P<num>\d+)]", line):
            if (name:= m.group("name")) in result: result[name].data_body_length = int(m.group("num"))
            else: result[name] = OpcodeData(data_body_length=int(m.group("num")))
    
    return result
    

                
    

    


    

if __name__ == "__main__":
    main()