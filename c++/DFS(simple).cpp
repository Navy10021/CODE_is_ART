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

    void DFS(Vertex* vertex, map<Vertex*, bool>& visited) {  
        visited[vertex] = true;        
        cout << vertex->GetName() << " -> ";
        
        // Sorting(오름차순 방문을 원할시)
        vector<Vertex*> sorted_adj_list = vertex->GetAdjList();
        sort(sorted_adj_list.begin(), sorted_adj_list.end(),[](Vertex* a, Vertex* b) {
            return a->GetName() < b->GetName(); });

        // recursively call DFS for vertices in the adjancency list
        for (auto nei : sorted_adj_list){
            if (!visited[nei]){
                DFS(nei, visited);
            }
        }
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


    // DFS
    map<Vertex*, bool> visited;
    for (auto vertex : graph.GetVertices()){
        if(!visited[vertex]){
            graph.DFS(vertex, visited);
        }
        cout << "\n";
    }
    
    return 0;
}
