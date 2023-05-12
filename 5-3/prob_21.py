# Minimum Spanning Tree(MST)
# 그래프에서 모든 노드를 연결할 때 사용된 에지의 가중치(Weight) 합을 최소로 하는 Tree
# 1. 모든 노드를 연결하면서, 비용이 최소가 되는 Graph
import heapq
# Union-Find
def MST(N, connec):
    par = [i for i in range(N + 1)]
    minH = []
    for (u, v, cost) in connec:
        heapq.heappush(minH, (cost, u, v))
    
    # Find
    def find(n1):
        if n1 == par[n1]:
            return n1
        else:
            par[n1] = find(par[n1])
            return par[n1]
        
    # Union
    def union(n1, n2):
        n1 = find(n1)
        n2 = find(n2)
        if n1 != n2:
            par[n2] = n1

    # MST : using edge < N-1
    use_edge, res = 0, 0
    tree = []
    while use_edge < N-1:
        w, u, v = heapq.heappop(minH)
        if find(u) != find(v):
            union(u, v)
            res += w
            tree.append((u, v))
            use_edge += 1
    
    print(tree)

    return res

N = 5
connections = [(1,2,1), (1,3,3), (2,3,2), (2,5,10), (3,4,5), (3,1,4), (4,5,10)]
print(MST(5, connections))
