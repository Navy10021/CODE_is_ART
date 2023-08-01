/*
환승(Transfer) : 하이퍼튜브 1개 : K개의 역을 서로 연결. 1번 -> N번역가는데 방문하는 최소 역의 수를 리턴
1. N : 역(노드)의 수 && K : 연결하는 역(edge)의 개수 && M 하이퍼튜브 개수 
2. 하이퍼튜브가 연결하는 역의 번호

하이퍼튜브 자체를 정점으로 생각해 그래프를 만들고 BFS 수행.
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 101002;
vector<int> adj[MX];
int dist[MX];
int n, k, m;    // node, edge, hypers

void BFS(){
    fill(dist, dist+n+m+1, -1);
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt : adj[cur]){
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k >> m;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=k; j++){
            int x;
            cin >> x;
            adj[n+i].push_back(x);  // n+i 노드 : i번쨰 하이퍼튜브의 노드 
            adj[x].push_back(n+i);
        }
    }
    BFS();
    
    if (dist[n] == -1) cout << dist[n];
    else cout << dist[n]/2 + 1;
}
