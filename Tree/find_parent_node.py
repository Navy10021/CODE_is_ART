# 트리의 부모 찾기 : ROOT를 1로 정의했을 때 각 노드의 부모 찾기
from collections import deque 

MX = 100002 
adj = [[] for _ in range(MX)]
p = [0] * MX 
n, m = 0, 0     # node, edge 

def BFS(root):
    Q = deque()
    Q.append(root)
    while Q:
        curr = Q.popleft()
        for nxt in adj[curr]:
            if (p[curr] == nxt):
                continue
            Q.append(nxt)
            p[nxt] = curr 

def DFS(curr):
    for nxt in adj[curr]:
        if p[curr] == nxt:
            continue
        p[nxt] = curr
        DFS(nxt)
        

if __name__ == "__main__":
    n = int(input())
    m = n - 1
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

# BFS 
BFS(1)
# print parents
for i in range(2, n+1):
    print(p[i], end = " ")


# DFS
p = [0]*MX   # 초기화 
DFS(1)
# print parents
for i in range(2, n+1):
    print(p[i], end = " ")
