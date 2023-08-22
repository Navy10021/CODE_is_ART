import heapq
import math

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]

    def add_edge(self, u, v, weight):
        self.adj_list[u].append((v, weight))

    def dijkstra(self, src):
        distance = [math.inf] * self.num_vertices
        parent = [-1] * self.num_vertices
        distance[src] = 0

        pq = [(0, src)]

        while pq:
            curr_weight, curr = heapq.heappop(pq)

            if curr_weight > distance[curr]:
                continue

            for nxt, nxt_weight in self.adj_list[curr]:
                if distance[curr] + nxt_weight < distance[nxt]:
                    distance[nxt] = distance[curr] + nxt_weight
                    parent[nxt] = curr
                    heapq.heappush(pq, (distance[nxt], nxt))

        # Print the shortest distances and paths
        for i in range(self.num_vertices):
            print(f"The shortest distance from {src} to {i}: {distance[i]} weight ||", end=" ")
            v = i
            path = []
            while v != -1:
                path.append(v)
                v = parent[v]
            print(" -> ".join(map(str, reversed(path))))

# Example usage
V = 5
graph = Graph(V)

graph.add_edge(0, 1, 4)
graph.add_edge(0, 2, 2)
graph.add_edge(1, 3, 5)
graph.add_edge(2, 1, 1)
graph.add_edge(2, 3, 8)
graph.add_edge(3, 4, 3)

src = 0
graph.dijkstra(src)
