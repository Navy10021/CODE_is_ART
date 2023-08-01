/*
이분 그래프(Bipartite Graph) : 정점의 집합을 둘로 분할시 각 집합에 속한 정점끼리 인접하지 않도록 분할 
그래프가 이분 그래프인지 아닌지 판별하는 프로그램 작성
No Cycle?
*/
#include <bits/stdc++.h>
using namespace std;

int k, v, e;
int gr[20002];              // 노드가 속한 그룹을 저장 -> 인접한 노드는 다른 그룹에 속해야한다.
vector<int> adj[20002];

bool bi_graph(){
    fill(gr, gr+v+1, -1);   // 초기화
    
    for(int i = 1; i <= v; i++){    // 모든 노드를 시작점으로하여 확인
        if (gr[i] != -1) continue;  
        
        queue<int> Q;
        Q.push(i);
        gr[i] = 0;
        
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for (int nxt : adj[cur]){
                if (gr[nxt] != -1){
                    if (gr[nxt] == gr[cur]) return false; // 인접 노드가 같은 그룹이면 Fasle
                    else continue;
                }
                gr[nxt] = (gr[cur] + 1) % 2;         // 2개의 그룹(0. 1.)으로 나눔
                Q.push(nxt);
            }
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    while(k--){
        cin >> v >> e;
        for (int i = 1; i<= v; i++) adj[i].clear();
        
        // make adj
        int a, b;
        while(e--){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    if (bi_graph()) cout << "YES\n";
    else cout << "NO\n";
    }
}
