/*
BFS in Graph 
연결 그래프가 아닌 경우까지 순회  
*/
#include <bits/stdc++.h>
using namespace std;

int v, e;   // node, edge
vector<int> adj[10];
bool vis[10];  
int v = 9;  // 노드의 수 

void BFS(){
    queue<int> Q;
    for (int i = 1; i <= v; i++){   // 모든 노드를 체크 : 연결되지 않은 경우 대비 
        if(vis[i]) continue;
        Q.push(i);
        vis[i] = true;
        
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
}

