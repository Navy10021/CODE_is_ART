class GNode:
    def __init__(self, id):
        self.id = id
        self.color = "W"

def topologicalSort(G):
    def DFS(curr, stack):
        curr.color = "G"

        for neighbor in G[curr]:
            if neighbor.color == "W":
                DFS(neighbor, stack)

        stack.insert(0, curr)  # Insert at the beginning to get topological order.

    stack = []
    for vertex in G:
        if vertex.color == "W":
            DFS(vertex, stack)

    return stack

# Create nodes
a = GNode("a")
b = GNode("b")
c = GNode("c")
d = GNode("d")
e = GNode("e")

# Create an adjacency list
G = {
    a: [b, c],
    b: [d],
    c: [d],
    d: [e],
    e: []
}

topological_order = topologicalSort(G)
print("Topological Sort Order:", [node.id for node in topological_order])
