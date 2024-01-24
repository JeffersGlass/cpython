from collections import defaultdict
import csv

from build import CPYTHON

with open(CPYTHON / "dual_opcode_data.csv", "r+") as infile, open(CPYTHON / "dual_opcode_stats.csv", "w") as outfile:
    reader = csv.DictReader(infile)
    read_list = list(reader)
    first_opcode_inst_count = defaultdict(int)
    for line in read_list:
        first_opcode_inst_count[line['first_opcode']] += int(line['combined'])
        line['efficiency'] = str(int(line['combined'])/int(line['sum']))

    ascending = sorted(read_list, key=lambda k: k['efficiency'])

    fields = list(reader.fieldnames)
    fields.append('efficiency')
    outfile.write(','.join(fields))
    for line in ascending:
        outfile.write(','.join(line[field] for field in fields) + "\n")

    for line in ascending[500:600]:
        print(f"{round(int(line['combined'])/int(line['sum']), 2)} {line}")

print("Done")