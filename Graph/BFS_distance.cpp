/*
BFS in Graph 
연결 그래프에서 1번 노드와의 거리 
*/
#include <bits/stdc++.h>
using namespace std;

int v, e;   // node, edge
vector<int> adj[10];
bool dist[10];  // 거리 저장

void BFS(){
    fill(dist, dist+10, -1);    // 거리 초기화 : 방문하지 않은 곳 '-1'
    queue<int> Q;
    // 1. 시작 노드를를 넣고, 거리 = 0
    Q.push(1);      
    dist[1] = 0;
    // 2. Queue가 빌때까지, 연결된 노드(인접리스트)을 Queue에 넣고, 방문(거리)표시 
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur]){
            if (dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;   // 거리 += 1 증가 
        }
    }
}
