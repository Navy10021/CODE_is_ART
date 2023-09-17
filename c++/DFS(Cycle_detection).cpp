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

    bool isCycleUtil(Vertex* curr, Vertex* parent, map<Vertex*, bool>& visited){
        visited[curr] = true;

        for (auto nei : curr->GetAdjList()){
            if (!visited[nei]){
                if (isCycleUtil(nei, curr, visited))
                    return true;
            }
            else if (nei != parent)
                return true;
        }
        return false;
    }

    bool isCycle(){
        map<Vertex*, bool> visited;

        for (auto vertex : vertices_) {
            if (!visited[vertex] && isCycleUtil(vertex, nullptr, visited))
                return true;
        }
        return false;
    }
};

int main() {
    Graph graph;

    // Generate vertices
    Vertex* vertex_r = graph.GenVertex("r");
    Vertex* vertex_s = graph.GenVertex("s");
    Vertex* vertex_t = graph.GenVertex("t");
    Vertex* vertex_u = graph.GenVertex("u");
    

    // Generate edges (Undirected Graph)
    graph.GenEdge(vertex_r, vertex_s);
    graph.GenEdge(vertex_s, vertex_t);
    graph.GenEdge(vertex_t, vertex_u);
    graph.GenEdge(vertex_u, vertex_s);
    

    // Find Cycle
    if(graph.isCycle()){
        cout << "The graph contains a Cycle." << "\n";
    }
    else{
        cout << "NO Cycle detection." << "\n";
    }

    return 0;
}
