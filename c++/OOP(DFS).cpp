#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Vertex {
public:
  // Constructor
  Vertex(string name) {name_ = name;} 

  // Functions
  // Data && Adj List 리턴 함수
  string GetName() const { return name_; }
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
  vector<Vertex*> vertices_; // Graph 내의 모든 Vertex instance를 저장하는 리스트
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


void DFS(Vertex* vertex, unsigned int &timestamp,   // start vertex, start time
    map<Vertex*, unsigned int> &discovery_time,     // discovery time 저장 맵
    map<Vertex*, unsigned int> &finishing_time) {   // finish time 저장 맵
  
  // discovery time 리스트에 vertex가 존재하면 OUT!
  if (discovery_time.find(vertex) != discovery_time.end())
    return;
  // increase timestamp for discovery time
  timestamp ++;
  cout << vertex->GetName() << " -> ";
  // store discovery time of current vertex
  discovery_time[vertex] = timestamp;
  
  // Sorting(오름차순 방문을 원할시)
  vector<Vertex*> sorted_adj_list = vertex->GetAdjacencyList();
  sort(sorted_adj_list.begin(), sorted_adj_list.end(),
       [](const Vertex* a, const Vertex* b) { return a->GetName() < b->GetName(); });

  // recursively call DFS for vertices in the adjancency list
  for (auto adjacent : sorted_adj_list){
    DFS(adjacent, timestamp, discovery_time, finishing_time);
  }
  // increase timestamp for finishing time
  timestamp ++;

  // store finishing time of current vertex
  finishing_time[vertex] = timestamp;
}



int main(){
    Graph graph;

    // generate vertices
    Vertex* vertex_u = graph.GenVertex("u");
    Vertex* vertex_v = graph.GenVertex("v");
    Vertex* vertex_w = graph.GenVertex("w");
    Vertex* vertex_x = graph.GenVertex("x");
    Vertex* vertex_y = graph.GenVertex("y");
    Vertex* vertex_z = graph.GenVertex("z");

    // generate edges
    graph.GenEdge(vertex_u, vertex_x);
    graph.GenEdge(vertex_u, vertex_v);
    graph.GenEdge(vertex_v, vertex_y);
    graph.GenEdge(vertex_w, vertex_y);
    graph.GenEdge(vertex_w, vertex_z);
    graph.GenEdge(vertex_x, vertex_v);
    graph.GenEdge(vertex_y, vertex_x);
    graph.GenEdge(vertex_z, vertex_z);

    // print all vertices and its their adjacency lists
    graph.PrintGraph();

    // do depth-first search
    cout << "=============== DFS Result ===============" << "\n";
    // initial timestamp starts from zero
    unsigned int timestamp = 0;
    // container that stores discovery time of each vertex
    map<Vertex*, unsigned int> discovery_time;
    // container that stores finishing time of each vertex
    map<Vertex*, unsigned int> finishing_time;

    // do DFS for all vertices in the graph
    for (auto vertex : graph.GetVertices()) {
      // call DFS only when the vertex is not discovered once
      if (discovery_time.find(vertex) == discovery_time.end()) {
        DFS(vertex, timestamp, discovery_time, finishing_time);
      }
    }
    cout << "\n";
    // print discovery time and finishing time of vertices
    for (auto vertex : graph.GetVertices()) {
      cout << "Vertex " << vertex->GetName() << ", ";
      cout << "Discovery time: " << discovery_time[vertex] << ", ";
      cout << "Finishing time: " << finishing_time[vertex] << "\n";
    }
}
