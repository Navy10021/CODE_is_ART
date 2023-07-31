/*
숨박꼭질 : 1번 헛간에서 최대한 멀리 있는 헛간 찾는 프로그램 
Undirected Graph
return 1. 숨어야하는 헛간 2. 1~숨은 헛간까지 거리 3. 숨은 헛간과 같은 거리에 있는 헛간의 개수
*/
#include <bits/stdc++.h>
using namespace std;

const int MXN = 50005; 
vector<int> adj[MXN];
int dist[MXN];
int n, m;       // num of node, edge
int mx;

// DFS 
void BFS_trav(int st){
    fill(dist, dist+MXN, -1);
    queue<int> Q;
    Q.push(st);
    dist[st] = 0;
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (auto nxt : adj[cur]){
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            // 최대 거리값 업데이트
            mx = max(dist[nxt], mx);
        }
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
        adj[v].push_back(u);
    }
    // visted 초기화 
    BFS_trav(1);
    
    // 최대 거리값 구하기
    //int mx = *max_element(dist, dist+MXN)
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if(dist[i] == mx){
            if (!cnt) cout << i << ' '; // 가장 작은 인덱스 출력
        cnt++;
        }
    }
    cout << mx << ' ' << cnt;           // max_element값과 동일한 max 값을 가진 결과 count
}
