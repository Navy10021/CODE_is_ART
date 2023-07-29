/*
DFS : 기본 : Queue -> Stack 으로만 변경 가능 -> 방문순서 유지 X
DFS : 연결 그래프에서의 순회, 재귀(recursive) -> 실제 방문할 때 출력 -> DFS 방문순서 유지
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
