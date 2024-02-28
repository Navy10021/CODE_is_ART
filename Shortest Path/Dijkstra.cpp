#include <vector>
#include <limits>
#include <set>

class Graph {
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(std::make_pair(v, w));
    }

    void dijkstra(int src) {
        std::vector<int> dist(vertices, std::numeric_limits<int>::max());
        dist[src] = 0;

        std::set<std::pair<int, int>> queue;
        queue.insert({0, src});

        while (!queue.empty()) {
            auto top = *(queue.begin());
            int u = top.second;
            queue.erase(queue.begin());

            for (auto &next : adjList[u]) {
                int v = next.first;
                int weight = next.second;

                if (dist[u] + weight < dist[v]) {
                    if (dist[v] != std::numeric_limits<int>::max()) {
                        queue.erase(queue.find(std::make_pair(dist[v], v)));
                    }
                    dist[v] = dist[u] + weight;
                    queue.insert({dist[v], v});
                }
            }
        }

        // Print the shortest distance
        for (int i = 0; i < vertices; ++i)
            std::cout << "Distance from " << src << " to " << i << " is " << dist[i] << std::endl;
    }
};