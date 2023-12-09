from collections import deque

class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p

    def __str__(self):
        return "(" + self.data + ")"
    
def BFS_connected_components(graph):
    components = []
    
    for node in G:
        if node.color == "W":
            component = []
            Q = deque()
            Q.append(node)
            node.color = "G"
            
            while (Q):
                curr = Q.popleft()
                component.append(curr.data)
                
                for nxt in G[curr]:
                    if nxt.color == "W":
                        nxt.color = "G"
                        nxt.parent = curr
                        Q.append(nxt)
            
            components.append(component)
    
    return components


A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")
H, I, J = GNode("H"), GNode("I"), GNode("J")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, E, F]
G[E] = [D, F]
G[F] = [D, E]
G[H] = [I, J]
G[I] = [H]
G[J] = [H]

start_vertex = A
target_vertex = F

res = BFS_connected_components(G)
print(res)
