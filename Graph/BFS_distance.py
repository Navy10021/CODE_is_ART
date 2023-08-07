num_node = 6 
edge = [(1,2), (5,1), (3,1), (4,6), (4,3), (2,5)]

adj = [[] for _ in range(num_node+1)]   # 1부터 시작 
for i in range(len(edge)):
    #u, v = map(int, input().split())
    u, v = edge[i]
    # No direction
    adj[u].append(v)    # u->v
    adj[v].append(u)    # v->u

# sorting : 만약 크기순으로 BFS가 필요하다면 adj list sorting 필요 
for l in adj:
    l.sort()
        
print("Adjacent list : {}".format(adj))

# visited list = fill(dist, dist+num_node, -1)
dist = [-1]*(num_node+1) # 거리 초기화 : 방문하지 않은 곳 -1

from collections import deque
def BFS(st):
    Q = deque()
    Q.append(st)
    dist[st] = 0 
    
    while (Q):
        cur = Q.popleft()   # Q.front(); Q.pop();
        for nxt in adj[cur]:
            if (dist[nxt] != -1):
                continue
            Q.append(nxt)
            dist[nxt] = dist[cur] + 1
            
    return dist

print(BFS(1))
