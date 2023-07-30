/*
결혼식(wedding) : 결혼식에 자신의 친구, 친구의 친구를 초대, 초대할 사람의 수를 구하는 프로그램

1. DFS
2. Depth == 2까지만 탐색 후 break!  
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int vis[505];
int n, m;       // number of node, edge
int st = 1;
int depth = 0;
int ans = 0;

void DFS(){
    stack<int> S;
    S.push(st);
    while(!S.empty()){
        if (depth == 2) break;  // 친구의 친구까지만!
        int cur = S.top();
        S.pop();
        vis[cur] = 1;
        for (auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            ans++;
            if(cur == 1) S.push(nxt);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;  // the number of node, edge
    while(m--){
        int u, v;   // u -> v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    DFS();
    cout << ans;
}
