from collections import deque
# BFS-Find shortest path-I
# 시작노드(start)부터 끝노드(end|target)까지 최단거리와 경로(The Shortest Path)를 찾는함수
class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p


def BFS(graph, start, target):
    # 1. Store all connected Node's distances from start Node using BFS
    start.color = "G"
    start.distance = 0
    Q = deque()
    Q.append(start)

    while Q:
        curr = Q.popleft()
        # If Lexicographical order
        graph[curr] = sorted(graph[curr], key = lambda x: x.data)
        for nxt in graph[curr]:
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                Q.append(nxt)
        curr.color = "B"  # current Vertex Queue out
	
    # Check is Vaid Path & Find the shortest path.
    if target.distance == -1:
        print("No path found between {} and {}".format(start.data, target.data))
        return False
    else:
        path = []
        while target:
            path.insert(0, target.data)
            target = target.parent
        if path[0] == start.data:
            print("The shortest path : ", " -> ".join(path))
            return True
        else:
            return False
        
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
target_vertex = H

if BFS(G, start_vertex, target_vertex):
    print("Is valid path!")
else:
    print("Is NOT valid path.")
