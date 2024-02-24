# DFS-Find Cycle in DAG
# 사이클을 탐지하고, 탐지된 사이클을 출력까지하는 함수
class GNode:
    def __init__(self, data, color="W", dist=-1, fin=-1, parent=None):
        self.data = data
        self.color = color
        

def DFS(graph, curr, path):
    if curr.color == "B":  # 이미 방문한 곳이면 사이클!
        return True        # Cycle detected: Already visited

    curr.color = "B"        # Mark as visited
    path.append(curr)       # path를 visit List와 처럼 함께 사용

    for nxt in graph[curr]:
        if nxt.color == "W":
        #if nxt not in path:
            if DFS(graph, nxt, path):
                return True

        elif nxt.color == "B":
        #elif nxt in path:
            # Cycle detected: The neighbor is already in the current path. 이미 방문한 곳이면 사이클(path[-1] == path[0])
            print("Cycle found : ", [vertex.data for vertex in path] + [path[0].data], end = "\n")
            return True

    path.pop()          # Backtrack : This step is crucial in DFS! -> Explore Other possible paths(Cycle) in the Graph.
    curr.color = "W"    # Backtrack
    return False


def has_cycle(graph):
    # 모든 노드를 시작점으로 돌면서 사이클 확인
    for node in graph:
        if node.color == "W":
            path = []
            if DFS(graph, node, path):
                return True

    return False


# Example Usage:
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

# Directed edges
G = dict()
G[A] = [E]
G[B] = [C]
G[C] = [D]
G[D] = [A, B, E]
G[E] = []

if has_cycle(G):
    print("The graph has a cycle.")
else:
    print("The graph does not have a cycle.")
