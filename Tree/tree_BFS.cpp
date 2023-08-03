/* 
Tree : 무방향이면서 사이클이 없는 연결 그래프(Undirected Acyclic Connected Graph)
주요성질 : V개의 정점을 가지고, V-1개의 간선을 가지는 연결 그래프 + 임의의 두 점을 연결하는 Simple path가 유일한 그래프
simple path : 정점이 중복해서 나오지 않는 경로 

BFS 알고리즘 : Graph와 동일
- 시작점을 Root로 정해서 트리를 재배치했을 때 높이 순으로 방문! 
- 부모 정점을 제외하고, 나머지를 전부 Queue에 넣으면 된다. -> visited array 불필요 && 부모 노드만 알면 된다
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int p[10];          // 각 정점의 부모 번호를 저장할 P 배일 

void BFS(int root){
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]){
            if (p[cur] == nxt) continue;    // nxt가 cur의 부모 확인 -> 부모인 인접값은 제외 && 자식 인접값만 추가
            Q.push(nxt);
            p[nxt] = cur;
        }
    }
}
