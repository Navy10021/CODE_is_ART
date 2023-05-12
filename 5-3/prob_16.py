# start Node에서 특정거리(K)에 있는 최단경로 노드 찾기, 동일한 weight
from collections import deque

def find_node(graph, node_num, K, start_node):
    adj = [[] for _ in range(node_num + 1)]
    for (u, v) in graph:
        adj[u].append(v)

    # Node 값이 작은 것부터 방문
    for i in range(node_num+1):
        adj[i].sort()

    # 방문 리스트
    visited = [-1] * (node_num + 1)
    
    def BFS(start_node):
        queue = deque()
        queue.append(start_node)
        visited[start_node] = 0
        while queue:
            curNode = queue.popleft()
            for nei in adj[curNode]:
                if visited[nei] == -1:
                    visited[nei] = visited[curNode] + 1
                    queue.append(nei)
    
    BFS(start_node)
    res = [i for i in range(node_num + 1) if visited[i] == K]

    return res, visited

G = [(1,3), (1,2), (2,4), (2,3), (3,5), (5,6)]
N = 6
dist = 3
start = 1

print(find_node(G, N, dist, start))
