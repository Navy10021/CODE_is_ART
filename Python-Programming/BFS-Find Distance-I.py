from collections import deque
# BFS-Find Distance-I
# 시작노드로 부터 거리를 확인하는 함수 / 리턴값 {노드 : 거리}
class GNode:
    def __init__(self, data, c="W", d=-1, p=None):
        self.data = data
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d
        self.parent = p

    def __str__(self):
        return "(" + self.data + ")"


def BFS(graph, start):
    start.color = "G"
    start.distance += 1  # distance == 0
    Q = deque()
    Q.append(start)

    while Q:
        curr = Q.popleft()
        #print(curr.data + "[" + str(curr.distance) + "]", end=" -> ")
        for nxt in graph[curr]:
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                Q.append(nxt)
        curr.color = "B"  # current Vertex Queue out
    
    return {vertex.data : vertex.distance for vertex in graph}

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, E, F]
G[E] = [D, F]
G[F] = [D, E]

start_vertex = A
distance_dict = BFS(G, start_vertex)
print("BFS is Done.", end = "\n")
print(distance_dict)
