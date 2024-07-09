import argparse
from collections import defaultdict
from dataclasses import dataclass, field
import enum
from functools import cache
from itertools import chain
import pathlib

from supernode_analysis import SuperNode

DEFAULT_FILE = pathlib.Path(__file__).parent.parent.parent / "out.txt"

class Operation(enum.Enum):
    ADDED = enum.auto()
    RETAINED = enum.auto()
    DECLINED = enum.auto()
    REMOVED = enum.auto()
    Rejecting = enum.auto()

def demo():
    import plotly.graph_objects as go

    fig = go.Figure(go.Sankey(
        arrangement = "snap",
        node = {
            "label": ["A", "B", "C", "D", "E", "F"],
            "x": [0.2, 0.1, 0.5, 0.7, 0.3, 0.5],
            "y": [0.7, 0.5, 0.2, 0.4, 0.2, 0.3],
            'pad':10},  # 10 Pixels
        link = {
            "source": [0, 0, 1, 2, 5, 4, 3, 5],
            "target": [5, 3, 4, 3, 0, 2, 2, 3],
            "value": [1, 2, 1, 1, 1, 1, 1, 2]}))

    fig.show()

@dataclass(unsafe_hash=True, frozen=True)
class GraphNode:
    label: str
    x: float
    y: float

@dataclass
class GraphData:
    generation_nodes: list[list[GraphNode]] = field(default_factory=list)

# THIS IS BROKEN
def parse_stat_dump(src: str) -> GraphData:
    lines = src.split('\n')

    #Find the lines in the dump file corresponding to the results of a stat run
    stat_calc_starts = [index + 1 for index, line in enumerate(lines) if "Calculating supernodes from stats" in line]
    stat_calc_ends = [index for index, line in enumerate(lines) if "possible supernodes that make up more than" in line]
    calc_lines = list(zip(stat_calc_starts, stat_calc_ends, strict=True))
    num_generations = len(calc_lines) + 1

    graph = GraphData()

    # bootstrap data for first generation
    gen_start, gen_end = calc_lines[0]
    nodes = [line_to_supernode(line) for line in lines[gen_start: gen_end]]
    end_ops: list[SuperNode] = [node for node, op in nodes if op in (Operation.REMOVED, Operation.RETAINED)]

    min_depth = min(node.depth for node in end_ops)
    max_depth = max(node.depth for node in end_ops)

    counts = {}
    for length in range(min_depth, max_depth+1):
        counts[length] = sum(1 if node.depth == length else 0 for node in end_ops)

    first_gen_nodes = [GraphNode(label = length, x = 0, y = i * (1/len(counts))) for i, length in enumerate(counts.keys())]
    graph.generation_nodes.append(first_gen_nodes)

    for igen, generation_bounds in enumerate(calc_lines):
        gen_start, gen_end = generation_bounds
        nodes = [line_to_supernode(line) for line in lines[gen_start: gen_end]]

        # Generate new nodes for this gen
        start_ops = end_ops
        end_ops = [node for node, op in nodes if op in (Operation.ADDED, Operation.RETAINED)]
        min_depth = min(node.depth for node in end_ops)
        max_depth = max(node.depth for node in end_ops)
        counts = {}
        for length in range(min_depth, max_depth+1):
            counts[length] = sum(1 if node.depth == length else 0 for node in end_ops)
        new_graph_nodes: list[GraphNode] = [GraphNode(label = str(length), x = igen * (1/num_generations), y = (i+1) * (1/(len(counts)+1))) for i, length in enumerate(counts.keys())]
        new_graph_nodes.append(GraphNode(label='Removed', x = igen * (1/num_generations), y = 0))

        graph.generation_nodes.append(new_graph_nodes)

    return graph
    """ #calculate link sizes
        link_counter: dict[tuple[int, int], int] = defaultdict(default_factory=int)
        for s in start_ops:
            for e in end_ops:
                if s.is_subop_of(e) and s != e:
                    link_counter[(s.depth, e.depth)] += 1

        #calculate links
        for (startval, endval), thickess in link_counter.items():
            start_node = next(n for n in graph.generation_nodes[-1] if n.label == str(startval))
            end_node = next(n for n in new_graph_nodes if n.label == str(endval))
            graph.links[(start_node, end_node)] = thickess

        #............ HMMMMMM

        graph.generation_nodes.append(new_graph_nodes) """


def line_to_supernode(src: str) -> tuple[SuperNode, Operation]:
    """ Turns a line like

    DECLINED Pair ('_BINARY_SUBSCR_LIST_INT', '_LOAD_CONST_INLINE')

    Into a SuperNode

    Args:
        src (str): The raw line to be processed

    Returns:
        SuperNode: A SuperNode as described by the listed ops
        Operation: An operation described what happened with the given node

    """
    names = src[src.index("(")+1: src.index(")")]
    node = SuperNode.from_supernode_names(*[name.strip("'") for name in names.split(",")])

    op = src.strip().split(" ")[0]
    return node, Operation[op]

def display(graph: GraphData) -> None:
    import plotly.graph_objects as go

    fig = go.Figure(go.Sankey(
        arrangement = "freeform",
        node = {
            "label": [node.label for node in chain.from_iterable(graph.generation_nodes)],
            "x": [node.x for node in chain.from_iterable(graph.generation_nodes)],
            "y": [node.y for node in chain.from_iterable(graph.generation_nodes)],
            'pad':10},  # 10 Pixels
        link = {
            "source": [n for n in range(len(list(chain.from_iterable(graph.generation_nodes)))-1)],
            "target": [n+1 for n in range(len(list(chain.from_iterable(graph.generation_nodes))))],
            "value": [1 for _ in range(len(list(chain.from_iterable(graph.generation_nodes)))-1)]}))

    fig.show()


def main(file) -> None:
    with open(file, "r") as f:
        g = parse_stat_dump(f.read())
        display(g)

if __name__ == "__main__":

    parser = argparse.ArgumentParser(
        prog="Graph the results of iterating over supernodes", add_help=False
    )

    parser.add_argument(
        "--file",
        type=str,
        default=DEFAULT_FILE,
        help=f"""
        Input source - generated from `supernode_analysis iterate` command
        Default is {DEFAULT_FILE}.
        """,
    )

    args = parser.parse_args()

    #demo()
    main(file = args.file)
