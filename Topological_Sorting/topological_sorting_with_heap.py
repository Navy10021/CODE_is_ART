import heapq

n, m = map(int, input().split())
PQ = []         # min-heap

in_degree = [0] * (n+1)
adj = [[] for _ in range(n+1)]

# Build adj list and calculate in-degrees
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)    # a -> b
    in_degree[b] += 1 
    
# Initalize the priority queue(min-heap)
for i in range(1, n+1):
    if (in_degree[i] == 0):
        heapq.heappush(PQ, i)   # (list, int)

# Topological sorting
while (PQ):
    curr = heapq.heappop(PQ)
    print(curr, end = " ")
    for nxt in adj[curr]:
        in_degree[nxt] -= 1 
        if in_degree[nxt] == 0:
            heapq.heappush(PQ, nxt)   
