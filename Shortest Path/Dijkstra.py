import heapq

def dijkstra(graph, start):
    V = len(graph)
    distance = [float("inf")] * V
    distance[start] = 0
    pq = [(0, start)]  # 우선순위 큐 초기화 (거리, 정점)

    while pq:
        current_distance, current_vertex = heapq.heappop(pq)

        # 현재 정점까지의 거리가 이미 알려진 최단 거리보다 길 경우 스킵
        if current_distance > distance[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex]:
            distance_through_u = current_distance + weight
            if distance_through_u < distance[neighbor]:
                distance[neighbor] = distance_through_u
                heapq.heappush(pq, (distance_through_u, neighbor))

    return distance

# 그래프는 각 정점에서 (이웃, 가중치) 형태의 리스트를 가지는 인접 리스트로 표현됨
graph = [[(1, 4), (2, 1)], [(2, 2), (3, 5)], [(3, 1)], []]
start_vertex = 0

distance = dijkstra(graph, start_vertex)
print("Vertex Distance from Source")
for i, d in enumerate(distance):
    print(f"{i}\t{d}")