#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Vertex {
public:
  // Constructor
  Vertex(string name) {name_ = name;} 

  // Functions
  // Data && Adj List 리턴 함수
  string GetName() { return name_; }
  vector<Vertex*> GetAdjacencyList() { return adjacency_list_; }
  // Vertex의 Adj List에 입력받은 인자를 추가 
  void AddToAdjacentList(Vertex* vertex);

private:
  string name_;                       // Vertex 데이터("A", "B", "C"...)
  vector<Vertex*> adjacency_list_;    // 인접리스트 : [Vertex1, Vertex2, Vertex3]
};

void Vertex::AddToAdjacentList(Vertex* vertex) {
  adjacency_list_.push_back(vertex);
}


class Graph {
public:
  Graph() {}  // Constructor
  ~Graph();   // Destructor

  // Functions
  // 1. data를 받고, vertex생성 및 vertices_에 저장
  Vertex* GenVertex(string name); 
  // 2. Start vertex의 adj list에 end vertex를 추가.
  void GenEdge(Vertex* start, Vertex* end);
  // 3. Graph 내의 모든 vertex 인스턴스를 담은 리스트 리턴
  vector<Vertex*> GetVertices() { return vertices_; }
  // 4. Grpah 내의 모든 vertex 개수 리턴
  size_t GetNumVertices() { return vertices_.size(); }
  // 5. Graph 내의 모든 vertex의 이름과 adj List 출력
  void PrintGraph();

private:
  std::vector<Vertex*> vertices_; // Graph 내의 모든 Vertex instance를 저장하는 리스트
};

Graph::~Graph() {
  for (auto vertex : vertices_)
    delete vertex;
  vertices_.clear();
}

Vertex* Graph::GenVertex(string name) {
  Vertex* vertex = new Vertex(name);
  vertices_.push_back(vertex);
  return vertex;
}

void Graph::GenEdge(Vertex* start, Vertex* end) {
  start->AddToAdjacentList(end);
}

void Graph::PrintGraph() {
  cout << "============== Defined Graph ==============" << "\n";
  for (auto vertex : vertices_) {
    cout << "Vertex " << vertex->GetName() << " || Adjacency List: ";

    bool is_first = true;
    for (auto adjacent : vertex->GetAdjacencyList()) {
      if (is_first == false) {
        cout << ", ";
      }
      cout << "Vertex " << adjacent->GetName();
      is_first = false;
    }
    cout << "\n";
  }
}


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
	/*	
        // Collect adjacent vertices and sort them alphabetically
        vector<Vertex*> sortedAdjacency = vertex->GetAdjacencyList();
        sort(sortedAdjacency.begin(), sortedAdjacency.end(), [](Vertex* a, Vertex* b) {
            return a->GetName() < b->GetName();
        });*/

        for (auto adjacent : vertex->GetAdjacencyList()) {
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

  // print all vertices and its their adjacency lists
  graph.PrintGraph();

  // do breadth-first search
  {
    // container that stores distance for each vertex
    map<Vertex*, unsigned int> distance;

    // print computed distance
    cout << "=============== BFS Result ===============" << endl;
    // compute distance from vertex_s
    BFS(vertex_s, distance);
    for (auto vertex : graph.GetVertices()) {
      cout << "Vertex " << vertex->GetName() << ", ";
      cout << "Distance: " << distance[vertex] << endl;
    }
  }
}
