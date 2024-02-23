# DFS-Find path(start~end)
# 시작노드로 부터 끝노드까지 알파벳순으로 방문하며 DFS 탐색 경로를 찾는 함수
class GNode:
    def __init__(self, data, color="W", dist=-1, fin=-1, parent=None):
        self.data = data
        self.color = color
        self.dist = dist
        self.fin = fin
        self.parent = parent

def DFS(graph, curr, end_vertex, path):
    global time
    time += 1
    curr.dist = time
    curr.color = "G"
    path.append(curr)

    if curr == end_vertex:
        print("Path found:", end=" ")
        for node in path:
            print(node.data, end=" -> ")
        print("")
        return True     # Indicate that a path is found
    
    # Lexicographical order : Sorting adj List
    graph[curr] = sorted(graph[curr], key = lambda x: x.data)
    # UnLexicographical order : Sorting adj List
    #graph[curr] = sorted(graph[curr], key = lambda x: x.data, reverse=True)
    
    for nxt in graph[curr]:
        if nxt.color == "W":
            nxt.parent = curr
            if DFS(graph, nxt, end_vertex, path):
                return True 

    curr.color = "B"
    time += 1
    curr.fin = time
    path.pop()         # Essential to backtrack and explore other possible paths in Graph!
    
    return False       # Indicate that a path is NOT found


def find_path(graph, start_vertex, end_vertex):
    global time 
    time = 0
    path = list()
    
    if DFS(graph, start_vertex, end_vertex, path):
        return path 
    else:
        print("No path found.")
        return None

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Directed edges
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, F, E]
G[E] = [D, F]
G[F] = [D, E]
printG(G)

start_vertex = A
end_vertex = F

find_path(G, start_vertex, end_vertex)
#DFS(G, start_vertex, end_vertex, path)
