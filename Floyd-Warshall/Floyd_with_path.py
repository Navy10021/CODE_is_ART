import math

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_matrix = [[math.inf] * num_vertices for _ in range(num_vertices)]
        for i in range(num_vertices):
            self.adj_matrix[i][i] = 0  # Diagonal is 0

    def add_edge(self, u, v, weight):
        self.adj_matrix[u][v] = weight

    def floyd(self):
        dist = [row[:] for row in self.adj_matrix]
        next_vertex = [[-1] * self.num_vertices for _ in range(self.num_vertices)]

        for k in range(self.num_vertices):
            for i in range(self.num_vertices):
                for j in range(self.num_vertices):
                    if dist[i][k] != math.inf and dist[k][j] != math.inf and \
                            dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
                        next_vertex[i][j] = k

        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                if dist[i][j] == math.inf:
                    print("INF", end=" ")
                else:
                    print(dist[i][j], end=" ")

                u = i
                v = j
                path = [str(u)]
                while next_vertex[u][v] != -1:
                    u = next_vertex[u][v]
                    path.append(str(u))
                print(" | " + " -> ".join(path))


def main():
    V = 4  # 0, 1, 2, 3
    G = Graph(V)

    G.add_edge(0, 1, 5)
    G.add_edge(0, 3, 10)
    G.add_edge(1, 2, 3)
    G.add_edge(2, 3, 1)

    G.floyd()


if __name__ == "__main__":
    main()
