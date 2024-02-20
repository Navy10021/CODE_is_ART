class GNode:
    def __init__(self, id, c="W", p = None):
        self.id = id 
        self.color = c  # "W", "R", "B"
        self.parent = p
        
def is_biparti(graph, start_node):
    def DFS(node):
        for nei in graph[node]:
            # if adj is same color, graph is not biparti
            if nei.color == node.color:
                return False 
            if nei.color == "W":
                if node.color == "B":
                    nei.color = "R"
                else:
                    nei.color = "B"
                nei.parent = node 
                if not DFS(nei):
                    return False
        return True
    
    start_node.color = "R"
    if not DFS(start_node):
        return False
    
    # Check all node have been visited
    for node in graph:
        if node.color == "W":
            node.color = "R"
            if not DFS(node):
                return False 
    return True 

r, s, t, u = GNode("r"), GNode("s"), GNode("t"), GNode("u")
v, w, x, y = GNode("v"), GNode("w"), GNode("x"), GNode("y")

G = dict()
G[r] = [s, v]
G[s] = [r, w]
G[t] = [u, w, x]
G[u] = [t, x, y]
G[v] = [r]
G[w] = [s, t]
G[x] = [t, u, y]
G[y] = [u, x] 

start = v
if is_biparti(G, start):
    print("Is biparti")
else:
    print("Is NOT biparti")
