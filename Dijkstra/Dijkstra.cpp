#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph{
    private:
        int num_vertices;
        vector<vector<pair<int, int>>> adjList; // {{{vertex, weight}, {, }}}
    
    public:
        Graph(int vertices) : num_vertices(vertices){
            adjList.resize(num_vertices);
        }

        void addEdge(int u, int v, int weight){
            adjList[u].push_back({v, weight});
            // or adjList[u].emplace_back(v, weight);
        }

        void Dijkstra(int src){
            vector<int> distance(num_vertices, INT_MAX);    // Store the smallest weight array
            vector<int> parent(num_vertices, -1);           // Store previous for tracking path
            distance[src] = 0; // 시작점 거리 = 0

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
            PQ.push({0, src});  // {weight, start vertex}

            while (!PQ.empty()){
                auto C = PQ.top(); // {weight, current vertex}
                int curr = C.second;
                int curr_weight = C.first;
                PQ.pop();
                if(distance[curr] != curr_weight) continue; // 거리가 Distance에 있는 값과 다르면 업데이트 되었으므로 continue

                for (const auto& edge : adjList[curr]){
                    int nxt = edge.first;
                    int nxt_weight = edge.second;

                    if (distance[curr] + nxt_weight < distance[nxt]) {
                        distance[nxt] = distance[curr] + nxt_weight;
                        parent[nxt] = curr;
                        PQ.push({distance[nxt], nxt});
                    }
                }
            }
            // Print the shortest distance and path
            for (int i=0; i<num_vertices; ++i){
                cout << "The shortest distance from " << src << " to " << i << " : " << distance[i] << " weight || ";
                int v = i;
                vector<int> path;   // for reverse
                while(v!=-1){
                    path.push_back(v);
                    v = parent[v];
                }
                for (int j = path.size()-1; j >=0; --j){
                    if (j == 0) cout << path[j];
                    else cout << path[j] << " -> ";
                }
                cout << "\n";
            }
        }
    };

int main(){
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 3);

    int src = 0;
    graph.Dijkstra(src);

    return 0;
}
