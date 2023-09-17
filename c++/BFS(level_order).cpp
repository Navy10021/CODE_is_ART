#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Vertex{
    private:
        string name_;
        vector<Vertex*> adjList_;

    public:
        Vertex(string name) { name_ = name; }   // Constructor
        string GetName() { return name_; }
        
        void addToadjList(Vertex* vertex){
            adjList_.push_back(vertex);
        }  
        vector<Vertex*> GetAdjList() { return adjList_; }

};

class Graph{
    private:
        vector<Vertex*> vertices_;
    
    public:
        Graph() {}  // Constructor
        ~Graph(){   // Destructor
            for (auto vertex : vertices_)
                delete vertex;
            vertices_.clear();
        }
        // Vertex 생성
        Vertex* GenVertex(string name){
            Vertex* vertex = new Vertex(name);
            vertices_.push_back(vertex);
            return vertex;
        } 
        // Vertex 연결 : s -> e
        void GenEdge(Vertex* start, Vertex* end){
            start->addToadjList(end);
        }
        // vetetices 결과 저장값 
        vector<Vertex*> GetVertices() { return vertices_; }
        
        // Print Graph
        void PrintGraph(){
            for (auto vertex : vertices_){
                cout << "Vertex " << vertex->GetName() << " || Adj List : ";
                
                bool is_first = true;
                for (auto nei : vertex->GetAdjList()){
                    if (is_first == false){
                        cout << ", ";
                    }
                    cout << "Vertex " << nei->GetName();
                    is_first = false;
                }
                cout << "\n";
            }
        }
};

// 시작 Vertex
void BFS(Vertex* start) {
    Vertex* vertex;
    queue<Vertex*> q;
    map<Vertex*, bool> visited;   // 방문표시
  
    // 1. mark root node as visited
    visited[start] = true;
    // 2. push (root node, distance 0) pair to the queue
	q.push(start);

	// 3. loop utill the queue is empty
	while (q.empty() == false) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++){
            vertex = q.front();
            q.pop();
            cout << vertex->GetName() << " ";
            for (auto adjacent : vertex->GetAdjList()) {
            // when adjacent vertex is not yet visited
                if (visited[adjacent] == false) {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
	    }
        cout << "\n";
    }
}

int main(){
    Graph graph;
    // generate vertices
    Vertex* vertex_r = graph.GenVertex("r");
    Vertex* vertex_s = graph.GenVertex("s");
    Vertex* vertex_t = graph.GenVertex("t");
    Vertex* vertex_u = graph.GenVertex("u");
    Vertex* vertex_v = graph.GenVertex("v");
    Vertex* vertex_w = graph.GenVertex("w");
    Vertex* vertex_x = graph.GenVertex("x");
    Vertex* vertex_y = graph.GenVertex("y");

    // generate edges(Undirected Graph)
    graph.GenEdge(vertex_r, vertex_s); graph.GenEdge(vertex_s, vertex_r);
    graph.GenEdge(vertex_r, vertex_v); graph.GenEdge(vertex_v, vertex_r);
    graph.GenEdge(vertex_s, vertex_w); graph.GenEdge(vertex_w, vertex_s);
    graph.GenEdge(vertex_t, vertex_w); graph.GenEdge(vertex_w, vertex_t);
    graph.GenEdge(vertex_t, vertex_x); graph.GenEdge(vertex_x, vertex_t);
    graph.GenEdge(vertex_t, vertex_u); graph.GenEdge(vertex_u, vertex_t);
    graph.GenEdge(vertex_u, vertex_x); graph.GenEdge(vertex_x, vertex_u);
    graph.GenEdge(vertex_u, vertex_y); graph.GenEdge(vertex_y, vertex_u);
    graph.GenEdge(vertex_w, vertex_x); graph.GenEdge(vertex_x, vertex_w);
    graph.GenEdge(vertex_x, vertex_y); graph.GenEdge(vertex_y, vertex_x);

  
    
    Vertex* start = vertex_s;
    // BFS level order
    BFS(start);

}
