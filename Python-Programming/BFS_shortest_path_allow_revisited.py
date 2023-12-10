from collections import deque

class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p

    def __str__(self):
        return "(" + self.data + ")"

def BFS_shortest_path(graph, start, target):
    distances = {vertex.data: float('inf') for vertex in graph}
    start.color = "G"
    start.distance = 0
    distances[start] = 0

    Q = deque()
    Q.append(start)
    distances[start.data] = start.distance

    while Q:
        curr = Q.popleft()
        # If Lexicographical order
        graph[curr] = sorted(graph[curr], key = lambda x: x.data)
        for nxt in graph[curr]:
            if nxt.color == "W" or nxt.distance > curr.distance + 1:    # Allow revisiting vertices if the new path to them is shorter thatn previously.
                nxt.color = "G"
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                distances[nxt.data] = nxt.distance
                Q.append(nxt)
        curr.color = "B"  # current Vertex Queue out

    if distances[target.data] == float('inf'):
        print("No path found between {} and {}".format(start.data, target.data))
    else:
        print_shortest_path(start, target)     # Backtrace
        
    #return distances

def print_shortest_path(start, target):
    path = []
    while target:
        path.insert(0, target.data)
        target = target.parent
    print("Shortest path (allow revisit):", " -> ".join(path))
  
    return path if path[0] == start.data else None 

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [D, C, B]
G[B] = [A]
G[C] = [A]
G[D] = [A]
#G[E] = [D, F]
#G[F] = [D, E]

start_vertex = A
target_vertex = D

BFS_shortest_path(G, start_vertex, target_vertex)
