# Connecting Node with Minimum Cost
# 모든 노드를 연결하는 최소 비용 리턴
# Prims
import heapq 
def connect_nodes(num_nodes, graph):
    adj = [[] for _ in range(num_nodes + 1)]
    # Undirected
    for (u, v, cost) in graph:
        adj[u].append((cost, v))
        adj[v].append((cost, u))

    # Prim's
    res = 0             # minimum cost
    visited = list()
    minH = [(0, 1)]     # (cost, start node)

    while minH:
        cost, curNode = heapq.heappop(minH)
        if curNode in visited:
            continue
        res += cost
        visited.append(curNode)
        for (nei_cost, nei) in adj[curNode]:
            if nei not in visited:
                heapq.heappush(minH, (nei_cost, nei))
    
    # if all nodes are connected
    if len(visited) == num_nodes:
        return res, visited
    # else
    return -1, visited

N = 4
G = [[1,2,5],[1,3,6],[2,3,1],[2,4,2],[4,3,1]]     # (u, v, cost)

#print(connect_nodes(N, G))


# Floyd-Warshall
def connect_nodes_2(num_nodes, graph):
    N = num_nodes
    adj = [[float("inf") for _ in range(N+1)] for _ in range(N+1)]
    # self-node's cost is zero
    for i in range(1, N+1):
        adj[i][i] = 0       

    # adj[u][v] == weight
    for (u, v, cost) in graph:
        if adj[u][v] > cost:
            adj[u][v] = cost
    
    # Floyd warshall Traver
    for k in range(1, N+1):
        for u in range(1, N+1):
            for v in range(1, N+1):
                if adj[u][v] > adj[u][k] + adj[k][v]:
                    adj[u][v] = adj[u][k] + adj[k][v]
    
    res = -1 if adj[1][N] == float("inf") else adj[1][N]

    return res


N = 3
G = [[1,2,5],[1,3,7],[2,3,1]]     # (u, v, cost)

print(connect_nodes_2(N, G))
