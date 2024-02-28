#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef pair<int, int> pii; // First: weight, Second: vertex

class Graph {
public:
    int V; // 정점의 수
    vector<vector<pii>> adj; // 인접 리스트 (가중치, 정점)

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    void prim(int start) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        int total_cost = 0;

        pq.push(make_pair(0, start));
        key[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            total_cost += key[u];

            for (auto& [w, v] : adj[u]) {
                if (!inMST[v] && key[v] > w) {
                    key[v] = w;
                    pq.push(make_pair(w, v));
                    parent[v] = u;
                }
            }
        }

        // 결과 출력
        cout << "Edges in MST:" << endl;
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) // 시작 정점을 제외한 모든 정점에 대해
                cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
        cout << "Total Cost: " << total_cost << endl;
    }
};

int main() {
    int V = 4;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.prim(0); // 0번 정점에서 시작

    return 0;
}
