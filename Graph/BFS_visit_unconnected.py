# 연결되지 않은 노드를 고려한 BFS
num_node = 10
edge = [(1,2), (5,1), (3,1), (4,6), (4,3), (2,5), (8,10), (7,8)]

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
vis = [False]*(num_node+1) # 거리 초기화 : 방문하지 않은 곳 -1

from collections import deque
def BFS():
    Q = deque()
    res_list = []
    for i in range(1, num_node):
        if (vis[i]):
            continue
        sub_list = []
        Q.append(i)
        vis[i] = True

        while (Q):
            cur = Q.popleft()   # Q.front(); Q.pop();
            #print(cur, end=" ")
            sub_list.append(cur)
            for nxt in adj[cur]:
                if (vis[nxt]):
                    continue
                Q.append(nxt)
                vis[nxt] = True
        res_list.append(sub_list)
    return res_list

print(BFS())
