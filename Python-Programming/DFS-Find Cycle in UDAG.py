#DFS-Find Cycle in UDAG
# DFS 이용 사이클을 탐지 및 사이클 경로를 출력하는 함수
class GNode:
    def __init__(self, data, color="W", parent=None):
        self.data = data
        self.color = color
        self.parent = parent


def DFS(graph, curr, path):
    curr.color = "G"                # 방문표시 
    
    for nxt in graph[curr]:
        if nxt.color == "W":
            nxt.parent = curr
            path.append(nxt)
            if DFS(graph, nxt, path):
                return True
            
        elif nxt != curr.parent:    # 이미 방문한 곳에 왔는데, nxt가 curr vertex의 부모가 아니라면 사이클이 존재함.
            path.append(nxt)        # 사이클 노드 시각화를 위해 Path 리스트에 vertex를 저장
            return True             # Cycle detected.
    
    path.pop()          # Backtrack if no cycle is found
    curr.color = "W"    # Backtrack
    return False


def has_cycle(graph):
    for node in graph:          # Traverse all vertex as start.
        if node.color == "W":
            path = [node]       # append start node
            if DFS(graph, node, path):
                print("Cycle found : ", [vertex.data for vertex in path], end = "\n")
                return True  
    
    return False 

# Example Usage:
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

# Undirected edges
G = dict()
G[A] = [B, C]
G[B] = [A, D]
G[C] = [A, D, E]
G[D] = [B, C, E]
G[E] = [C, D]


if has_cycle(G):
    print("The graph has a cycle.")
else:
    print("The graph does not have a cycle.")
