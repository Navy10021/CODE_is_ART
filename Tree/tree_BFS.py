# Tree : Undirected Acyclic Connected Graph
# 특징 : V개의 정점을 가지고, V-1개의 간선(edge)를 가지는 Graph
# BFS : 시작점 Root + 부모 정점을 제외하고, 모두 Queue에 넣으면되며, Visited array 불필요

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

# Tree BFS 탐색 
from collections import deque
def BFS(root):
    Q = deque()
    Q.append(root)
    while(Q):
        curr = Q.popleft()
        print(curr, end = " ")
        for nxt in adj[curr]:
            if (p[curr] == nxt):
                continue
            Q.append(nxt)
            p[nxt] = curr
    return None 

BFS(1)
print("\n")
print(p)
            
        
        
    
    
