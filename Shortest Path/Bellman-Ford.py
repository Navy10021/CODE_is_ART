def bellman_ford(edges, V, start):
    # 거리 값을 무한대로 초기화
    distance = [float("inf")] * V
    # 시작 정점까지의 거리는 0
    distance[start] = 0

    # V-1번 각 간선에 대해 relaxation을 수행
    for _ in range(V - 1):
        for u, v, w in edges:
            if distance[u] != float("inf") and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    # 음수 가중치 사이클 존재 확인
    for u, v, w in edges:
        if distance[u] != float("inf") and distance[u] + w < distance[v]:
            print("Graph contains a negative weight cycle")
            return None

    return distance

# 간선 리스트 (u, v, w)는 u에서 v로 가는 가중치 w의 간선을 의미
edges = [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
V = 5 # 정점의 수
start_vertex = 0

distance = bellman_ford(edges, V, start_vertex)
if distance:
    print("Vertex Distance from Source")
    for i, d in enumerate(distance):
        print(f"{i}\t{d}")