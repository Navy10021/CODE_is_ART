import heapq
from collections import defaultdict

class GNode:
    def __init__(self, data):
        self.data = data
        self.neighbors = []
        self.visited = False

    def __lt__(self, other):
        return False

def print_graph(graph):
    for node, neighbors in graph.items():
        print(f"{node.data}: {[(neighbor.data, weight) for neighbor, weight in neighbors]}")

def prim(graph, start_node):
    min_spanning_tree = defaultdict(list)
    priority_queue = [(0, None, start_node)]  # (weight, parent, node)

    while priority_queue:
        weight, parent, current_node = heapq.heappop(priority_queue)

        if current_node.visited:
            continue

        current_node.visited = True
        if parent:
            min_spanning_tree[parent].append((current_node, weight))
            min_spanning_tree[current_node].append((parent, weight))

        for neighbor, edge_weight in current_node.neighbors:
            if not neighbor.visited:
                heapq.heappush(priority_queue, (edge_weight, current_node, neighbor))

    return min_spanning_tree

# Example graph for Minimum Spanning Tree
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

graph = {
    A: [(B, 1), (C, 4)],
    B: [(A, 1), (C, 2), (D, 5)],
    C: [(A, 4), (B, 2), (D, 1), (E, 7)],
    D: [(B, 5), (C, 1), (E, 3)],
    E: [(C, 7), (D, 3)]
}

# Adding neighbors to nodes
for node, neighbors in graph.items():
    for neighbor, weight in neighbors:
        node.neighbors.append((neighbor, weight))
        neighbor.neighbors.append((node, weight))

print("Original Graph:")
print_graph(graph)

start_node = A  # Choose any starting node

min_spanning_tree = prim(graph, start_node)

print("\nMinimum Spanning Tree:")
print_graph(min_spanning_tree)
