#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Vertex {
private:
    string name_;
    vector<Vertex*> adjList_;

public:
    Vertex(string name) { name_ = name; }
    string GetName() { return name_; }

    void addToadjList(Vertex* vertex) {
        adjList_.push_back(vertex);
    }
    vector<Vertex*> GetAdjList() { return adjList_; }
};

class Graph {
private:
    vector<Vertex*> vertices_;

public:
    Graph() {}
    ~Graph() {
        for (auto vertex : vertices_)
            delete vertex;
        vertices_.clear();
    }
    Vertex* GenVertex(string name) {
        Vertex* vertex = new Vertex(name);
        vertices_.push_back(vertex);
        return vertex;
    }
    void GenEdge(Vertex* start, Vertex* end) {
        start->addToadjList(end);
    }
    vector<Vertex*> GetVertices() { return vertices_; }

    // Perform BFS and return the shortest path as a vector of strings
    vector<string> BFS(Vertex* start, Vertex* end) {
        queue<pair<Vertex*, vector<string>>> Q;
        map<Vertex*, bool> visited;

        visited[start] = true;
        Q.push({start, {start->GetName()}});

        while (!Q.empty()) {
            Vertex* curr = Q.front().first;
            vector<string> path = Q.front().second;
            Q.pop();

            if (curr == end) {
                return path; // Return the shortest path
            }

            for (Vertex* nei : curr->GetAdjList()) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    vector<string> new_path = path;
                    new_path.push_back(nei->GetName());
                    Q.push({nei, new_path});
                }
            }
        }

        // No path found
        return {"No path found."};
    }
};

int main() {
    Graph graph;

    // Generate vertices
    Vertex* vertex_r = graph.GenVertex("r");
    Vertex* vertex_s = graph.GenVertex("s");
    Vertex* vertex_t = graph.GenVertex("t");
    Vertex* vertex_u = graph.GenVertex("u");
    Vertex* vertex_v = graph.GenVertex("v");
    Vertex* vertex_w = graph.GenVertex("w");
    Vertex* vertex_x = graph.GenVertex("x");
    Vertex* vertex_y = graph.GenVertex("y");

    // Generate edges (Undirected Graph)
    graph.GenEdge(vertex_r, vertex_s);
    graph.GenEdge(vertex_s, vertex_r);
    graph.GenEdge(vertex_r, vertex_v);
    graph.GenEdge(vertex_v, vertex_r);
    graph.GenEdge(vertex_s, vertex_w);
    graph.GenEdge(vertex_w, vertex_s);
    graph.GenEdge(vertex_t, vertex_w);
    graph.GenEdge(vertex_w, vertex_t);
    graph.GenEdge(vertex_t, vertex_x);
    graph.GenEdge(vertex_x, vertex_t);
    graph.GenEdge(vertex_t, vertex_u);
    graph.GenEdge(vertex_u, vertex_t);
    graph.GenEdge(vertex_u, vertex_x);
    graph.GenEdge(vertex_x, vertex_u);
    graph.GenEdge(vertex_u, vertex_y);
    graph.GenEdge(vertex_y, vertex_u);
    graph.GenEdge(vertex_w, vertex_x);
    graph.GenEdge(vertex_x, vertex_w);
    graph.GenEdge(vertex_x, vertex_y);
    graph.GenEdge(vertex_y, vertex_x);

    Vertex* start = vertex_s;
    Vertex* end = vertex_u;

    // BFS and get the shortest path
    vector<string> shortestPath = graph.BFS(start, end);

    // Print the shortest path or "No path found."
    if (shortestPath.front() == "No path found.") {
        cout << "No path found." << endl;
    } else {
        cout << "Shortest path from " << start->GetName() << " to " << end->GetName() << ": ";
        for (size_t i = 0; i < shortestPath.size(); ++i) {
            cout << shortestPath[i];
            if (i < shortestPath.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    // Clean up memory (delete vertices)
    for (auto vertex : graph.GetVertices()) {
        delete vertex;
    }

    return 0;
}
