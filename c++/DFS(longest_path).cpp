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
        end->addToadjList(start); // Undirected graph, so add the reverse edge
    }
    vector<Vertex*> GetVertices() { return vertices_; }

    // Modified DFS to find the longest path(DFS를 활용해 Path를 저장하는 함수)
    vector<Vertex*> FindLongestPath(Vertex* start, Vertex* end) {
        vector<Vertex*> longestPath;
        vector<Vertex*> currentPath;
        map<Vertex*, bool> visited;

        DFSLongestPath(start, end, currentPath, longestPath, visited);

        return longestPath;
    }

private:
    void DFSLongestPath(Vertex* current, Vertex* end, vector<Vertex*>& currentPath, vector<Vertex*>& longestPath, map<Vertex*, bool>& visited) {
        visited[current] = true;
        currentPath.push_back(current);

        if (current == end && currentPath.size() > longestPath.size()) {
            longestPath = currentPath;
        }

        for (Vertex* neighbor : current->GetAdjList()) {
            if (!visited[neighbor]) {
                DFSLongestPath(neighbor, end, currentPath, longestPath, visited);
            }
        }

        visited[current] = false;   // Backtracking
        currentPath.pop_back();     // Backtracking
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
    Vertex* end = vertex_y;

    // Find the longest path
    vector<Vertex*> longestPath = graph.FindLongestPath(start, end);

    if (!longestPath.empty()) {
        cout << "Longest Path from " << start->GetName() << " to " << end->GetName() << ": ";
        for (Vertex* vertex : longestPath) {
            cout << vertex->GetName() << " -> ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    // Clean up memory (delete vertices)
    for (Vertex* vertex : graph.GetVertices()) {
        delete vertex;
    }

    return 0;
}
