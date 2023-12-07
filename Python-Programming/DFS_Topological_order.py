class GNode:
    def __init__(self, data, color="W"):
        self.data = data
        self.color = color

    def __str__(self):
        return "(" + self.data + ")"
    
    
    
def DFS(graph, curr, path):
    curr.color = "G"
    #path.append(curr)
    
    for nxt in graph[curr]:
        if nxt.color == "W":
            DFS(graph, nxt, path)
            
    #path.append(curr)
    path.insert(0, curr)
    
def topological(graph):
    stack = []
    for node in graph:
        if node.color == "W":
            DFS(graph, node, stack)
    
    #return stack[::-1]
    return stack
    
    

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Directed edges
G = dict()
G[A] = [B,C]
G[B] = [D]
G[C] = [D]
G[D] = [E]
G[E] = []

res = topological(G)
print("Topological sort order : ", [node.data for node in res])
