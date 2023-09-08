class GNode:
    def __init__(self, id):
        self.id = id
        self.color = "W"

def hasCycle(G):
    def DFS(curr):
        curr.color = "G"    # visiting

        for neighbor in G[curr]:
            if neighbor.color == "W":
                if DFS(neighbor):
                    return True
            elif neighbor.color == "G":
                return True

        curr.color = "B"    # visited
        return False

    for vertex in G:
        if vertex.color == "W":
            if DFS(vertex):
                return True
    return False

# Create nodes
a = GNode("a")
b = GNode("b")
c = GNode("c")
d = GNode("d")
e = GNode("e")

# Create an adjacency list
G = {
    a: [b],
    b: [c],
    c: [d],
    d: [e],
    e: [a]
}

if hasCycle(G):
    print("Graph has a cycle")
else:
    print("No cycle in the graph")
