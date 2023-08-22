#include<iostream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

class Graph{
    private:
        int num_vertices;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int vertices) : num_vertices(vertices){
            adjMatrix.resize(num_vertices, vector<int>(num_vertices, INT_MAX));
            for (int i=0; i < num_vertices; ++i)
                adjMatrix[i][i] = 0; // 대각선은 0
        }

        void addEdge(int u, int v, int weight){
            adjMatrix[u][v] = weight;
        }

        void floyd(){
            vector<vector<int>> dist = adjMatrix;
            vector<vector<int>> next(num_vertices, vector<int>(num_vertices,-1));

            for (int k=0; k < num_vertices; ++k){         // 중간점
                for (int i=0; i < num_vertices; ++i){     // 시작점
                    for (int j=0; j < num_vertices; ++j){ // 끝점
                        // (시작~중간 + 중간~끝 거리)가 작으면 업데이트
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                            dist[i][k] + dist[k][j] < dist[i][j]){
                                dist[i][j] = dist[i][k] + dist[k][j];
                                next[i][j] = k; // 중간지점을 저장
                            }
                    }
                }
            }
        
            // 최소거리 출력
            for (int i = 0; i < num_vertices; ++i){
                for (int j = 0; j < num_vertices; ++j){
                    if (dist[i][j] == INT_MAX) cout << "INF ";
                    else cout << dist[i][j] << " ";

                    // Print the shortest path
                    int u = i;
                    int v = j; 
                    string path = to_string(u);
                    while (next[u][v] != -1){
                        u = next[u][v];
                        path += "->" + to_string(u);
                    }
                    cout << " | " << path << "\n";
                }
            }
        }
    };

int main(){
    int V = 4;  // 0,1,2,3
    Graph G(V);

    G.addEdge(0, 1, 5);
    G.addEdge(0, 3, 10);
    G.addEdge(1, 2, 3);
    G.addEdge(2, 3, 1);

    G.floyd();
    return 0;


}
