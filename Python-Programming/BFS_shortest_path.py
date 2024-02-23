from collections import deque
# BFS-Find Shortest Path-II
# 최단경로를 찾되 알파벳 정렬순으로 방문
class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p


def BFS_shortest_path(graph, start, target):
    # 1. Store all connected Node's distances from start Node using BFS
    #distances = {vertex.data: float('inf') for vertex in graph}
    start.color = "G"
    start.distance = 0
    #distances[start] = 0
    
    Q = deque()
    Q.append(start)
    #distances[start.data] = start.distance

    while Q:
        curr = Q.popleft()
        # Lexicographical order
        graph[curr] = sorted(graph[curr], key = lambda x: x.data)
        for nxt in graph[curr]:
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                #distances[nxt.data] = nxt.distance
                Q.append(nxt)
        curr.color = "B"  # current Vertex Queue out
	
    # Tracking Path using parent
    #if distances[target.data] == float('inf'):
    if target.distance == -1:
        print("No path found between {} and {}".format(start.data, target.data))
    else:
        print_shortest_path(start, target)     # Backtrace
        
    #return distances

def print_shortest_path(start, target):
    path = []
    while target:
        path.insert(0, target.data)
        target = target.parent
    print("Shortest path:", " -> ".join(path))
  
    return path if path[0] == start.data else None 

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")
H = GNode("H")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, E, F]
G[E] = [D, F]
G[F] = [D, E]
G[H] = []

start_vertex = A
target_vertex = E

BFS_shortest_path(G, start_vertex, target_vertex)
