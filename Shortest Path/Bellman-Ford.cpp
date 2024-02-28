#include <vector>
#include <iostream>
#include <limits>

class Graph {
public:
    struct Edge {
        int src, dest, weight;
    };

    int vertices;
    std::vector<Edge> edges;

    Graph(int v) : vertices(v) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    void bellmanFord(int src) {
        std::vector<int> dist(vertices, std::numeric_limits<int>::max());
        dist[src] = 0;

        for (int i = 1; i <= vertices - 1; ++i) {
            for (const auto &e : edges) {
                int u = e.src;
                int v = e.dest;
                int weight = e.weight;
                if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (const auto &e : edges) {
            int u = e.src;
            int v = e.dest;
            int weight = e.weight;
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains a negative weight cycle" << std::endl;
                return;
            }
        }

        // Print the shortest distance
        for (int i = 0; i < vertices; ++i)
            std::cout << "Distance from " << src << " to " << i << " is " << dist[i] << std::endl;
    }
};