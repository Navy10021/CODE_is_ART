class GNode:
    def __init__(self, data, color="W", parent=None):
        self.data = data
        self.color = color
        self.parent = parent

def find_leaf_node(G):
    leaf_nodes = set()

    def DFS(curr):
        nonlocal leaf_nodes
        curr.color = "B"
        # Correctly identifying neighbors given the structure of G
        neighbors = [nei for nei in G[curr] if nei.color == "W"]
        if len(neighbors) == 0:  # If no unvisited neighbors, it's a leaf
            leaf_nodes.add(curr.data)
        for nei in neighbors:
            #nei.parent = curr
            DFS(nei)

    # Start DFS for each node not already visited
    for start in G:
        if start.color == "W":
            DFS(start)

    return list(leaf_nodes)

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = {A: [C, B], B: [A, D], C: [A], D: [B, E, F], E: [D], F: [D]}

leaf_nodes = find_leaf_node(G)

print("Leaf nodes:", leaf_nodes)
