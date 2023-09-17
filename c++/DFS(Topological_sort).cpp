#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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

    void topologicalSortDFS(Vertex* curr, map<Vertex*, bool>& visited, stack<string>& result){
        visited[curr] = true;
        for (Vertex* nei : curr->GetAdjList()){
            if(!visited[nei]){
                topologicalSortDFS(nei, visited, result);
            }
        }
        result.push(curr->GetName());  // Visit all neighbors and then push the current vertex onto the stack.
    }

    void topologicalSort(){
        stack<string> result;
        map<Vertex*, bool> visited;

        for (auto vertex : vertices_){
            if (!visited[vertex]){
                topologicalSortDFS(vertex, visited, result);
            }
        }
        cout << "Topological Sorting Order: ";
        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
        }
        cout << "\n";
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

    // Find Topological sort
    graph.topologicalSort();

    return 0;
}
