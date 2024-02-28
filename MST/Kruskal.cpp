#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
    }
};

class KruskalMST {
public:
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // (weight, start, end)

    KruskalMST(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back(make_tuple(weight, u, v));
    }

    vector<tuple<int, int, int>> constructMST() {
        sort(edges.begin(), edges.end());
        UnionFind uf(V);
        vector<tuple<int, int, int>> result;

        for (auto &[weight, u, v] : edges) {
            if (uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                result.push_back({u, v, weight});
            }
        }
        return result;
    }
};

int main() {
    int V = 4; // 정점의 수
    KruskalMST kruskal(V);
    
    // 간선 추가: u, v, 가중치
    kruskal.addEdge(0, 1, 10);
    kruskal.addEdge(0, 2, 6);
    kruskal.addEdge(0, 3, 5);
    kruskal.addEdge(1, 3, 15);
    kruskal.addEdge(2, 3, 4);
    
    auto mst = kruskal.constructMST();

    cout << "Edges in the MST:" << endl;
    for (auto &[u, v, weight] : mst) {
        cout << u << " - " << v << " : " << weight << endl;
    }

    return 0;
}
