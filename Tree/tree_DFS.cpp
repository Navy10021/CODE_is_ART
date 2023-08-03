/*
Tree DFS : visited array 대신 parent array && depth array 사용
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int p[10];          // 각 정점의 부모 번호를 저장할 P 배열
int depth[10];

void DFS(int root){
    stack<int> S;
    S.push(root);
    while (!S.empty()){
        int cur = S.top(); S.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]){
            if (p[cur] == nxt) continue;    // nxt가 cur의 부모 확인 -> 부모인 인접값은 제외 && 자식 인접값만 추가
            S.push(nxt);
            p[nxt] = cur;                   // nxt의 부모로 cur를 저장 
            depth[nxt] = depth[cur] + 1;    // Tree depth ++
        }
    }
}

// 재귀 DFS 
void DFS_2(int cur){
    cout << cur << ' ';
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        DFS_2(nxt);
    }
}
