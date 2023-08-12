# Tree 개수 세기 : 모든 노드를 시작점으로 설정하여 돌면서 Count

num_node = 6
#edge = [(1,2),(2,3),(3,5),(4,5),(5,6)]
edge = [(1,2),(2,3),(1,3),(4,5),(5,6),(6,4)]

adj = [[] for i in range(num_node+1)]
for i in range(len(edge)):
    u, v = edge[i]
    adj[u].append(v) 
    adj[v].append(u)
    
#print("Tree adj list : {}".format(adj))

#p = [0]*(num_node+1)          # 부모노드(반드시 0 삽입) & visited list 불필요
vis = [False]*(num_node+1)     # 해당 노드를 방문여부 확인
# Tree DFS 탐색 
def DFS(curr, prev):
    global isTree           # global 함수 필요!!!
    for nxt in adj[curr]:
        if (nxt == prev): continue
        if (vis[nxt]):
            isTree = False  # Cycle이면 NO Tree!
            continue
        vis[nxt] = True
        DFS(nxt, curr)
        
# 모든 노드를 시작점으로 돌아야함
treeCnt = 0 
for i in range (1, num_node+1):
    if (vis[i]): continue
    vis[i] = True         # 시작점 방문표시 
    isTree = True   
    DFS(i, 0)            # DFS를 돌면서 Tree 여부 확인
    if (isTree): 
        treeCnt+=1

print(treeCnt)   
