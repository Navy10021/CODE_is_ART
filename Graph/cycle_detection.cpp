#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
public:
    Graph(int vertices) : vertices(vertices), adj_list(vertices) {}

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

    bool has_cycle() {
        std::vector<bool> vis(vertices, false);
        std::vector<bool> recursion_stack(vertices, false);

        for (int vertex = 0; vertex < vertices; ++vertex) {
            if (!vis[vertex]) {
                if (DFS(vertex, vis, recursion_stack)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    int vertices;
    std::unordered_map<int, std::vector<int>> adj_list;

    bool DFS(int curr, std::vector<bool>& vis, std::vector<bool>& recursion_stack) {
        vis[curr] = true;
        recursion_stack[curr] = true;

        for (int nxt : adj_list[curr]) {
            if (!vis[nxt]) {
                if (DFS(nxt, vis, recursion_stack)) {
                    return true;
                }
            } else if (recursion_stack[nxt]) {
                return true;
            }
        }

        recursion_stack[curr] = false;
        return false;
    }
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);

    if (g.has_cycle()) {
        std::cout << "Graph contains a cycle" << std::endl;
    } else {
        std::cout << "Graph does not contain a cycle" << std::endl;
    }

    return 0;
}
