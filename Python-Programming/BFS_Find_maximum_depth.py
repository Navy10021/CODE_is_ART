from collections import deque
# 시작노드로 부터 가장 멀리있는 노드(Maximum Distiance)를 찾는 함수

class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p


def BFS(graph, start):
    start.color = "G"
    start.distance += 1  # distance == 0
    Q = deque()
    Q.append(start)

    while Q:
        curr = Q.popleft()
        for nxt in graph[curr]:
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                Q.append(nxt)
        curr.color = "B"  
    
    distance_dict = {vertex.data : vertex.distance for vertex in graph}
    max_val = max(distance_dict.values())
    #max_key = max(distance_dict, key=lambda k: distance_dict[k])
    return max_val

def find_max_depht(graph):
    max_depth = 0
    for start_node in graph:
        # initialize
        for node in graph:
            node.color = "W"
            node.distance = -1
            node.parent = None 
        
        res = BFS(graph, start_node)
        if max_depth < res:
            max_depth = res 
    return max_depth

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A]
G[D] = [B, E, F]
G[E] = [D, F]
G[F] = [D, E]

#start_vertex = A
#max_depth = BFS(G, start_vertex)
max_depth = find_max_depht(G)
print("All BFS is Done.")
print("Maximum Depth:", max_depth)
