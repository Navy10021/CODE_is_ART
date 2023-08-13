import heapq

v, e = map(int, input().split())
MX = 105
adj = [[] for _ in range(MX)]     # (cost, vertex)
chk = [False] * MX                # chk[i]: whether i-th vertex is in MST

for _ in range(e):
    a, b, cost = map(int, input().split())
    adj[a].append((cost, b))
    adj[b].append((cost, a))

cnt = 0      # Number of selected edges
ans = 0
PQ = []      # Min-heap: (cost, vertex a, vertex b)

chk[1] = True 
for (nxt_cost, nxt_vertex) in adj[1]:
    heapq.heappush(PQ, (nxt_cost, 1, nxt_vertex))
    
while (cnt < (v-1)):
    cost, a, b = heapq.heappop(PQ)
    if chk[b]: continue
    ans += cost
    chk[b] = True 
    cnt += 1
    for (nxt_cost, nxt_vertex) in adj[b]:
        if not chk[nxt_vertex]:
            heapq.heappush(PQ, (nxt_cost, b, nxt_vertex))

print(ans)
