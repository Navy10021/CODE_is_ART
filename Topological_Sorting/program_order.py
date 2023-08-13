from collections import deque 

MX = 10
adj = [[] for _ in range(MX)]
indeg = [0]*MX

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
        print("Cycle existe!")
    else:
        for e in res :
            print(e, end = " ")

n = 6   # num_node
order_list = [[1,4,3],[6,2,5,4],[2,3]]

for m in order_list:
    for i in range(1, len(m)):
        a, b = m[i-1:i+1]   # a -> b
        adj[a].append(b)
        indeg[b] += 1

topological()
        
