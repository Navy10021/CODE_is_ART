/*
인접 리스트(adj list)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int v, e;       // node, edge 개수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    // 1. Directed Graph
    for (int i = 0; i < e; i++){
        int u, v;   // node U -> V;
        cin >> u >> v;
        adj[u].push_back(v);
        // 2. Undirected Graph
        //adj[v].push_back(u);
    }
    // print
    for(auto e: adj){
        for(int i=0; i<e.size(); i++){
            cout << e[i] << ' ';
        }
        cout << '\n';
    }
}

