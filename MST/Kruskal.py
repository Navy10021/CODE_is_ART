class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]
        self.rank = [1] * size

    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])  # Path compression
        return self.root[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1

def kruskal(graph_edges, n):
    uf = UnionFind(n)
    mst = []
    cost = 0

    graph_edges.sort(key=lambda x: x[2])  # Sort edges by weight

    for edge in graph_edges:
        u, v, weight = edge
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            mst.append((u, v, weight))
            cost += weight

    return mst, cost

# 예제 사용
edges = [(0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)]
n = 4  # 정점의 수
mst, total_cost = kruskal(edges, n)
print("MST:", mst)
print("Total Cost:", total_cost)
