/*
DFS & BFS 탐색 결과 출력 프로그램
단, 방문할 정점이 여러개인 경우 정점이 작은 것부터 방문(1 ~ N)

1. BFS / DFS 함수 정의 
2. 인접리스트 크기순 정렬
3. BFS & DFS 수행
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int n, m, st;       // number of node, edge, start node

void BFS(){
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
        
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
        }
    }
}

void DFS(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]){
        if (vis[nxt]) continue;
        DFS(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> st;
    while(m--){
        int u, v;   // u -> v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 번호가 작은 것부터 방문하기 위해 각 노드의 연결리스트를 정렬(sort) 
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    // DFS 수행 
    DFS(st);
    cout << '\n';
    // visited array 초기화
    fill(vis+1, vis+n+1, false);
    // BFS 수행 
    BFS();
    
}
