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

// 시작 Vertex, 거리 저장 맵
void BFS(Vertex* start, map<Vertex*, unsigned int> &distance) {
    unsigned int curr;  
    Vertex* vertex;
    queue<pair<Vertex*, unsigned int>> q;

    map<Vertex*, bool> visited;   // 방문표시
    curr = 0;                     // Root와의 거리
  
    // 1. mark root node as visited
    visited[start] = true;
    // 2. push (root node, distance 0) pair to the queue
	q.push(make_pair(start, curr));

	// 3. loop utill the queue is empty
	while (q.empty() == false) {
        // lookup front of the queue
		vertex = q.front().first;
        cout << vertex->GetName() << " -> ";
        curr = q.front().second;
        q.pop();

        for (auto adjacent : vertex->GetAdjList()) {
        // when adjacent vertex is not yet visited
        if (visited[adjacent] == false) {
            visited[adjacent] = true;
            int nxt_dist = curr + 1;
            q.push(make_pair(adjacent, nxt_dist));
        }
    }
    // write distance of the vertex to the map
    distance[vertex] = curr;
	}
    cout << "\n";
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

  
    
    map<Vertex*, unsigned int> dist;
    Vertex* start = vertex_s;
    // BFS
    BFS(start, dist);
  
    // start로 부터 가장 거리가 멀리 있는 Vertex 출력
    auto max_val = max_element(dist.begin(), dist.end(), [](const auto &x, const auto &y){
        return x.second < y.second;
        });
    cout << max_val->second << "\n";

    for (int i=0; i<=max_val->second; i++){
        cout << "  Dist " << i << " : ";
        for(auto e : dist){
            if (e.second == i){
                cout << e.first->GetName() << " ";
            }
        }
    }


}
