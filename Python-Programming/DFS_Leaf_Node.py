# Find leaf node
class GNode:
    def __init__(self, data, color="W", parent=None):
        self.data = data
        self.color = color
        self.parent = parent


def find_leaf_node(G):
    leaf_nodes = set()

    def DFS(curr):
        nonlocal leaf_nodes
        curr.color ="B"
        neighbors = [nei for nei in G[curr] if nei != curr.parent]
        if not neighbors:
            leaf_nodes.add(curr.data)
            return
        for nei in neighbors:
            if (nei.color == "W"):
                nei.parent = curr
                DFS(nei)

    for start in G:
        # initialize 
        for node in G :
            node.color = "W"
            node.parent = None
            
        if start.data not in leaf_nodes:
            DFS(start)

    return list(leaf_nodes)


A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A]
G[D] = [B, E, F]
G[E] = [D]
G[F] = [D]

leaf_nodes = find_leaf_node(G)

print("Leaf nodes:", leaf_nodes)
