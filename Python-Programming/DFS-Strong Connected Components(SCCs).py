from collections import defaultdict

class GNode:
    def __init__(self, data, c="W"):
        self.data = data
        self.color = c

# Strongly Connected Component(SCCs); Kosaraju's Algorithm
# Find the maximum set of nodes that are mutually reachable within a set

def find_SCCs(graph):
    # 1. DFS, tracking paths with stack
    def DFS(currNode, stack):
        currNode.color = "B"  # visited
        for nei in graph[currNode]:
            if nei.color == "W":
                DFS(nei, stack)
        stack.append(currNode)

    # 2. Reverse edges
    def reverse_edges():
        reversed_graph = defaultdict(list)
        for node, neis in graph.items():
            for nei in neis:
                reversed_graph[nei].append(node)
        return reversed_graph

    # 3. SCCs with DFS
    def DFS_SCC(currNode, scc):
        currNode.color = "B"
        scc.append(currNode.data)
        for nei in reversed_graph[currNode]:
            if nei.color == "W":
                DFS_SCC(nei, scc)

    # 1. DFS
    paths = []
    for node in graph:
        if node.color == "W":
            DFS(node, paths)

    print("DFS Elements(Stack) : ", " ".join([node.data for node in paths][::-1]))

    # 2. Reverse edges
    reversed_graph = reverse_edges()

    # Reset colors for the second DFS
    for node in graph:
        node.color = "W"

    # 3. Find SCCs
    strong_connect = []
    for node in paths[::-1]:
        if node.color == "W":
            scc = []
            DFS_SCC(node, scc)
            strong_connect.append(scc)

    print("SSCs : ", strong_connect)

    return strong_connect


A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G, H = GNode('E'), GNode('F'), GNode('G'), GNode('H')

Graph = {
    A: [B],
    B: [C, D, E],
    C: [A, F],
    D: [E],
    E: [D],
    F: [G],
    G: [H],
    H: [F],
}

find_SCCs(Graph)
