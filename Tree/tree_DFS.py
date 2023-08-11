num_node = 7
edge = [(1,2), (1,3), (2,4), (2,5), (3,6), (3,7)]

adj = [[] for i in range(num_node+1)]
for i in range(len(edge)):
    u, v = edge[i]
    adj[u].append(v) 
    adj[v].append(u)
    
print("Tree adj list : {}".format(adj))

#vis = [False]*(num_node+1)
p = [0]*(num_node+1)        # 부모노드(반드시 0 삽입) & visited list 불필요
depth = [0]*(num_node+1)    # DFS : Tree 깊이 추적 가능

# Tree DFS 탐색 
def DFS(curr):
    print(curr, end = " ")
    for nxt in adj[curr]:
        if (p[curr] == nxt): continue
        p[nxt] = curr
        depth[nxt] = depth[curr] + 1
        DFS(nxt)
         

DFS(1)
print("\n")
print(p, end = "\n")
print(depth, end= "\n")
