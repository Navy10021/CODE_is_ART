/*
연결 요소의 개수 
방향이 없는 그래프(Undirected Graph)가 주어졌을 때, 연결 요소(Connected Component)의 개수를 구하는 프로그램

1. 인접 리스트
2. 모든 노드(For문)를 돌면서 BFS()
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

int BFS(int n){
    int cnt = 0;    // BFS 시행 횟수 카운트
    queue<int> Q;
    for (int i=1; i<=n; i++){   // 1번 노드 ~ n번 노드 모두 체크 
        if(vis[i]) continue;
        cnt++;
        Q.push(i);
        vis[i] = true;
        
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
    return cnt;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;       // number of node, edge
    
    cin >> n >> m;
    while(m--){
        int u, v;   // u -> v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = BFS(n);
    cout << ans;
}
