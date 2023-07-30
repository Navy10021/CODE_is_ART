/*
바이러스 : 컴퓨터와 네트워크상 연결되어 있는 모든 컴퓨터는 바이러스에 걸린다.
1번 컴퓨터가 웜 바이러스에 걸렸을 경우, 1번 컴퓨터에 의해 웜바이러스에 걸리게 되는 컴퓨터 수
1. DFS 수행 
2. 인접리스트 방문시 count ++
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];
int n, m;       // number of node, edge
int cnt = 0;

void DFS(int cur){
    vis[cur] = true;
    for (auto nxt : adj[cur]){
        if (vis[nxt]) continue;
        cnt++;
        DFS(nxt);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;  // 컴퓨터 수, 연결 수수
    while(m--){
        int u, v;   // u -> v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 1번 컴퓨터를 시작으로 DFS 수행 
    DFS(1); 
    cout << cnt;
}
