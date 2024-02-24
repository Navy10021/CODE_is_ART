# DFS-Find All Paths-II(Long and Short)
# 시작노드 ~ 끝노드간 가장 긴 경로(Longest path)와 가장 짧은 경로(Shortest path)를 찾는 함수
# 접근법 : 주어진 시작노드와 끝노드에서 가능한 모든 경로를 찾고, 가장 긴 경로와 짧은 경로를 리턴 
class GNode:
    def __init__(self, data, color = "W"):
        self.data = data 
        self.color = color 
    
def find_all_paths(G, start, end, path = None):
    if path is None:
        path = []
    # Base case 
    #path = path + [start.data]
    path.append(start.data)
    if start == end:
        return [path]
    
    if start not in G:
        return []
    
    paths = []
    for nxt in G[start]:
        if nxt.data not in path:                                    # Need to not modifiy original path.
            new_paths = find_all_paths(G, nxt, end, path.copy())    # "new copy path" preventing the issue of modifying the Original path
            for p in new_paths:
                paths.append(p)
    return paths

def longest_shortest_path(G, st, en):
    all_paths = find_all_paths(G, st, en)
    max_depth = 0
    min_depth = len(G)
    longest = []
    shortest = []
    for path in all_paths:
        if len(path) < min_depth:
            min_depth = len(path)
            shortest = path 
        if len(path) > max_depth:
            max_depth = len(path)
            longest = path 
    
    print("The Longest Path : ", '->'.join(longest))
    print("The Shortest Path : ", '->'.join(shortest))

A, B, C, D = GNode("A"), GNode("B"), GNode("C"), GNode("D")
E, F, G, H = GNode("E"), GNode("F"), GNode("G"), GNode("H")

Graph = dict()
Graph[A] = [B]
Graph[B] = [C, D]
Graph[C] = [D]
Graph[D] = [E, F]
Graph[E] = [G]
Graph[F] = [E]
Graph[G] = []
Graph[H] = []

st = A 
en = G
longest_shortest_path(Graph, A, G)
    
    
