/*
결혼식(wedding) : 결혼식에 자신의 친구, 친구의 친구를 초대, 초대할 사람의 수를 구하는 프로그램

1. BFS
2. 신랑(node 1)로부터 거리(distance)가 1 && 2인 노드 카운트  
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int dist[505];
int n, m;       // number of node, edge
int st = 1;
int cnt = 0;

void BFS(){
    fill(dist, dist+505, -1);   // 거리 초기화 
    queue<int> Q;
    Q.push(st);
    dist[st] = 0;
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur]){
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;  // 거리 증가 
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
 
    BFS();
    for(int i=1; i<=n; i++){
        if (dist[i] == 1 || dist[i] == 2) cnt++;
    }
    cout << cnt;
}
