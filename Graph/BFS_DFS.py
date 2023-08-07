# Adj list
num_node = 6 
num_edge = 6
edge = [(1,2), (5,1), (3,1), (4,6), (4,3), (2,5)]

adj = [[] for _ in range(num_node+1)]   # 1부터 시작 
for i in range(num_edge):
    #u, v = map(int, input().split())
    u, v = edge[i]
    # No direction
    adj[u].append(v)    # u->v
    adj[v].append(u)    # v->u

# sorting : 만약 크기순으로 BFS가 필요하다면 adj list sorting 필요 
for l in adj:
    l.sort()
        
print("Adjacent list : {}".format(adj))

# visited list
vis = [False]*(num_node+1)

from collections import deque
def BFS(st):
    Q = deque()
    Q.append(st)
    vis[st] = True 
    
    while (Q):
        cur = Q.popleft()   # Q.front(); Q.pop();
        print(cur, end = ' ')
        for nxt in adj[cur]:
            if (vis[nxt]):
                continue
            Q.append(nxt)
            vis[nxt] = True 
    return None

print("BFS Traversal")
BFS(1)
print("\n")

# initialized visted list 
vis = [False]*(num_node+1)
# backtracking
def DFS(cur):
    vis[cur] = True 
    print(cur, end = ' ')
    for nxt in adj[cur]:
        if (vis[nxt]):
            continue
        DFS(nxt)
    return None

print("DFS Traversal")
DFS(1)
