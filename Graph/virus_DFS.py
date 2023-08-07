# 모두 연결되지 않은 그래프도 존재
num_node = 10
edge = [(1,2), (5,1), (3,1), (4,6), (4,3), (2,5), (8,10), (7,8)]

adj = [[] for _ in range(num_node+1)]   # 1부터 시작 
for i in range(len(edge)):
    u, v = edge[i]
    # No direction
    adj[u].append(v)    # u->v
    adj[v].append(u)    # v->u
        
print("Adjacent list : {}".format(adj))


vis = [False]*(num_node+1) 
cnt = 0  

def DFS(cur):
    global cnt 
    vis[cur] = True
    for nxt in adj[cur]:
        if (vis[nxt]): continue
        cnt += 1
        DFS(nxt)
      
DFS(1)  # 1번으로 인해 감염되는 컴퓨터 수
print("감염된 컴퓨터 수 : {}".format(cnt))
