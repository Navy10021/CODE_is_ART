/*
DFS : 기본 : Queue -> Stack 으로만 변경 가능 
DFS : 연결 그래프에서의 순회, 재귀(recursive)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool vis[10];

void DFS(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        DFS(nxt);
    }
}
