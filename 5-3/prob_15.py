# Minimum cost(paths) it takes for all N-nodes visited(Dijkstra)
# K에서 시작해서 모든 노드를 방문하는 최소 비용(최단경로) 리턴
import heapq
def min_cost(graph, num_nodes, start_node):
    # Directed Graph
    adj = [[] for _ in range(num_nodes + 1)]
    for u, v, cost in graph:
        adj[u].append((v, cost))

    # 방문리스트(array) : 방문리스트에 Weight(비용)를 저장
    visited = [0] + [float("inf")] * num_nodes
    minH = [(0, start_node)]    # (cost, start node)

    while minH:
        time, curNode = heapq.heappop(minH) # POP min cost value
        if time < visited[curNode]:
            visited[curNode] = time
            for (v, cost) in adj[curNode]:
                heapq.heappush(minH, (time + cost, v)) 

    if max(visited) < float("inf"):
        res = max(visited)
    else:
        res = -1 

    return res, visited

G = [[2,1,1],[2,3,1],[3,4,1]]
N = 4
K = 2
print(min_cost(G, N, K))
