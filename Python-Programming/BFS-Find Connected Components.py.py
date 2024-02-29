from collections import deque
# BFS-Find Connected Components
# BFS 이용 연결된 노드들의 그룹을 확인하는 함수 / return [[group1], [group2] ... ]
class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p
    
def BFS_connected_components(G):
    components = []
    
    for node in G:
        if node.color == "W":
            component = []
            Q = deque()
            Q.append(node)
            node.color = "G"
            
            while (Q):
                curr = Q.popleft()
                # Lexicographical order
                G[curr] = sorted(G[curr], key = lambda x: x.data)
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
