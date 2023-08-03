/*
트리의 부모 찾기 : 루트를 1이라고 정의했을 때 각 노드의 부모를 구하는 프로그램 
Tree = Undirected Acyclic Connected Graph
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000002;
vector<int> adj[MX];
int p[MX];
int n, m;

void BFS(int root){
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt : adj[cur]){
            if (p[cur] == nxt) continue;
            Q.push(nxt);
            p[nxt] = cur;
        }
    }
}

void DFS(int cur){
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        DFS(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    m = n-1;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // BFS 수행 
    BFS(1);     // root == 1;
    // 부모 출력
    for(int i = 2; i <= n; i++) cout << p[i] << ' ';
    cout << '\n';
    
    // DFS 수행
    fill(p, p+n, 0);
    DFS(1);
    // 부모 출력
    for(int i = 2; i <= n; i++) cout << p[i] << ' ';
}
