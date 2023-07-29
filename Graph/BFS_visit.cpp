/*
BFS in Graph 
연결 그래프에서 순회
*/
#include <bits/stdc++.h>
using namespace std;

int v, e;   // node, edge
vector<int> adj[10];
bool vis[10];

void BFS(){
    queue<int> Q;
    // 1. 시작 노드를를 넣고, 방문표시
    Q.push(1);      
    vis[1] = true;
    // 2. Queue가 빌때까지, 연결된 노드(인접리스트)을 Queue에 넣고, 방문표시 
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';     // 현재 방문노드 출력
        for (auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
        }
    }
}
