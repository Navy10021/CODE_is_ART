class GNode:
    def __init__(self, id):
        self.id = id
        self.color = "W"

def findConnectedComponents(G):
    def DFS(curr, stack):
        stack.append(curr.id)        
        curr.color = "G"
    
        for neighbor in G[curr]:
            if neighbor.color == "W":
                DFS(neighbor, stack)

    stack = []
    
    for vertex in G:
        if vertex.color == "W":
            component = []
            DFS(vertex, component)
            stack.append(component)

    return stack

# Create nodes
a = GNode("a")
b = GNode("b")
c = GNode("c")
d = GNode("d")
e = GNode("e")
f = GNode("f")

# Create an adjacency list
G = {
    a: [b, c],
    b: [a, d],
    c: [a],
    d: [b],
    e: [f],
    f: [e]
}

connected_components = findConnectedComponents(G)
for i in connected_components:
    print(i)
