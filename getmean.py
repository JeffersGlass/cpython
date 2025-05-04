import argparse
import re

parser = argparse.ArgumentParser()
parser.add_argument("file")
args = parser.parse_args()

with open(args.file) as f:
    data = f.readlines()

comparison_line = next(line for line in data if line.startswith("Mean +-"))
value_string = comparison_line.split(":")[-1].strip()
m = re.match(r"([\d.-]+)x (faster|slower)", value_string)
if m:
    if m.group(2) == 'slower':
        print(1/float(m.group(1)))
    else:
        print((m.group(1)))
else:
    print(f"No match found in line {comparison_line}")
