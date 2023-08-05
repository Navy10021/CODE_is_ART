/*number of Trees : 트리의 개수를 세는 프로그램 작성*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 502;
vector<int> adj[MX];
bool vis[MX];
bool isTree;
int n, m, u, v, trees;

// DFS 
void DFS(int cur, int prev){
    for (int nxt : adj[cur]){
        if (nxt == prev) continue;    // next와 부모일 경우 contniue
        if (vis[nxt]){
            isTree = false;           // 이미 방문한 곳을 방문하면 Connected Component가 트리가 아님을 의미
            continue;
        }
        vis[nxt] = true;
        DFS(nxt, cur);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        cin >> n >> m;
        if (!n && !m) break;    // n == 0 && m == 0 
        
        fill(vis, vis+n+1, 0);                      // visited list 초기화 
        for (int i=1; i<=n; i++) adj[i].clear();    // adj list(vector) 비우기
        trees = 0;
        
        while (m--){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++){   // 모든 노드를 시작점으로 돌면서
            if (vis[i]) continue;
            vis[i] = true;
            isTree = true;
            DFS(i, -1);
            trees += isTree;            // +=-1
        }
        if (!trees) cout << "NO Trees." << '\n';
        else if (trees == 1) cout << "Only One Tree" << '\n';
        else cout << trees << " Trees." << '\n';
    }
}
