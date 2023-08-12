from collections import deque 

MX = 1005
adj = [[] for _ in range(MX)]
indeg = [0] * MX 
n, m = map(int, input().split())

def topological():
    Q = deque()
    res = []
    
    for i in range(1, n+1):
        if (indeg[i] == 0):
            Q.append(i)
    
    while (Q):
        cur = Q.popleft()
        res.append(cur)
        
        for nxt in adj[cur]:
            indeg[nxt] -= 1
            if (indeg[nxt] == 0):
                Q.append(nxt)
    
    if (len(res) != n):
        print("No DAG. Graph has cycle")
    
    else:
        for x in res:
            print(x, end = " ")

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    indeg[b] += 1
    
topological()
