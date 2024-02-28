import heapq

def prim(graph, start_vertex, n):
    visited = [False] * n
    min_heap = [(0, start_vertex)]
    mst = []
    total_cost = 0

    while min_heap:
        weight, u = heapq.heappop(min_heap)
        if not visited[u]:
            visited[u] = True
            total_cost += weight
            mst.append((u, weight))
            for v, w in graph[u]:
                if not visited[v]:
                    heapq.heappush(min_heap, (w, v))

    return mst[1:], total_cost  # 첫 번째 튜플은 시작 정점이므로 제외

# 그래프를 인접 리스트로 표현
graph = {
    0: [(1, 10), (2, 6), (3, 5)],
    1: [(0, 10), (3, 15)],
    2: [(0, 6), (3, 4)],
    3: [(0, 5), (1, 15), (2, 4)]
}
n = 4  # 정점의 수
mst, total_cost = prim(graph, 0, n)  # 0번 정점에서 시작
print("MST:", mst)
print("Total Cost:", total_cost)
