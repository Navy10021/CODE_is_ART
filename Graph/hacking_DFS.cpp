/*
Hacking : A->B 신뢰관계이면 B && A 해킹 가능
한번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램
*/
#include <bits/stdc++.h>
using namespace std;

int mx;         // 최대 연결수(깊이) == 해킹할 수 있는 컴퓨터수 
int sc[10005];  // 
vector<int> adj[10005];
bool vis[10005];
int n, m;       // num of node, edge

// DFS : 
void DFS_trav(int cur){
    vis[cur] = true;
    sc[cur]++;          // sc[cur]의 최대 깊이값 저장 
    mx = max(mx, sc[cur]);
    
    for (int nxt : adj[cur]){
        if (vis[nxt]) continue;
        DFS_trav(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // sc 초기화 
    fill(sc, sc+10005, 0);
    // 모든 시작점을 돌면서 해당 시작점에서의 최대깊이값 sc 저장 
    for (int i=1; i<=n; i++){
        fill(vis, vis+10005, 0); // visit 초기화 
        DFS_trav(i);
    }
    
    for (int i = 1; i <= n; i++) cout << sc[i] << ' '; // 각 노드의 최대 깊이(해킹할 수 있는 컴퓨터수) 출력 
    cout << '\n';
    for (int i = 1; i <=n; i++)
        if (sc[i] == mx) cout << i << ' ';
}
