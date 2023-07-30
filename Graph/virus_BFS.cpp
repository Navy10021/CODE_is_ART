/*
바이러스 : 컴퓨터와 네트워크상 연결되어 있는 모든 컴퓨터는 바이러스에 걸린다.
1번 컴퓨터가 웜 바이러스에 걸렸을 경우, 1번 컴퓨터에 의해 웜바이러스에 걸리게 되는 컴퓨터 수
1. BFS 수행 
2. vis true 개수 count - 1(1번 컴퓨터)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];
int n, m;       // number of node, edge
int st = 1;

void BFS(){
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
        
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
        }
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
    // BFS 수행 
    BFS();
    // true 개수 count
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i] == true) cnt++;
    cout << cnt - 1;
}
