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

    // Perform BFS and print the result in the specified format
    void BFS(Vertex* start) {
        queue<Vertex*> q;
        map<Vertex*, bool> visited;
        vector<vector<string>> result;  // <level : levelNode>

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<string> levelNodes;

            for (int i = 0; i < levelSize; i++) {
                Vertex* vertex = q.front();
                q.pop();
                levelNodes.push_back(vertex->GetName());    // 같은 레벨 노드를 저장

                for (auto adjacent : vertex->GetAdjList()) {
                    if (visited[adjacent] == false) {
                        visited[adjacent] = true;
                        q.push(adjacent);
                    }
                }
            }

            result.push_back(levelNodes);       // 레벨 순으로 push_back
        }

        // Print the result in the specified format
        cout << "[";
        for (const auto& level : result) {
            if (level != result.front()) cout << ", ";
            cout << "[";
            for (const string& node : level) {
                if (node != level.front()) cout << ", ";
                cout << node;
            }
            cout << "]";
        }
        cout << "]" << endl;
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

    // BFS level order and print in the specified format
    graph.BFS(start);

    return 0;
}
