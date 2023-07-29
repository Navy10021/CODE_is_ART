/*
인접행렬(adj matrix)
*/
#include <bits/stdc++.h>
using namespace std;

int adj_matrix[10][10] = {};
int v, e;       // node, edge 개수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    // 1. Directed Graph
    for (int i=0; i<e; i++){
        int u, v;   // node U -> V;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        // 2. Undirected Graph
        //adj_matrix[v][u] = 1;   
    }
    
    // print
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout << adj_matrix[i][j] << ' ';
        }
    }
}


