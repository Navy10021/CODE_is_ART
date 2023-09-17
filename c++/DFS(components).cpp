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

    // DFS 결과를 component에 저장
    void DFS(Vertex* vertex, map<Vertex*, bool>& visited, vector<Vertex*>& component) {
        visited[vertex] = true;
        component.push_back(vertex);

        vector<Vertex*> sorted_adj_list = vertex->GetAdjList();
        sort(sorted_adj_list.begin(), sorted_adj_list.end(), [](Vertex* a, Vertex* b) {
            return a->GetName() < b->GetName();
        });

        for (auto nei : sorted_adj_list) {
            if (!visited[nei]) {
                DFS(nei, visited, component);
            }
        }
    }
    // 연결된 요소들을 리턴하는 함수
    vector<vector<Vertex*>> ConnectedComponents() {
        map<Vertex*, bool> visited;
        vector<vector<Vertex*>> components;

        for (auto vertex : vertices_) {
            if (!visited[vertex]) {
                vector<Vertex*> component;
                DFS(vertex, visited, component);
                components.push_back(component);
            }
        }

        return components;
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
    Vertex* vertex_a = graph.GenVertex("a");
    Vertex* vertex_b = graph.GenVertex("b");
    Vertex* vertex_c = graph.GenVertex("c");

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
    graph.GenEdge(vertex_a, vertex_b);
    graph.GenEdge(vertex_b, vertex_c);

    // Find connected components and print them
    vector<vector<Vertex*>> components = graph.ConnectedComponents();
    cout << "[";

    for (size_t i = 0; i < components.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < components[i].size(); j++) {
            cout << components[i][j]->GetName();
            if (j < components[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < components.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;

    // Clean up memory (delete vertices)
    for (auto vertex : graph.GetVertices()) {
        delete vertex;
    }

    return 0;
}
