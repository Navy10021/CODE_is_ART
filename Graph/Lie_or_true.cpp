/*
거짓말과 진실 : 진실을 이야기한 사람이 거짓말을 듣게되면 거짓말쟁이가 된다.
1. 사람수(N) / 파티수(M)
2.진실을 아는 사람수 + 사람번호
3.각 파티에 오는 사람 번호 
거짓말을 할 수 있는 파티수 리턴 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, t;    // node, edge, knower
vector<int> party[52];
vector<int> adj[52];
bool tr[52];    // visited list == 방문(진실) 여부 확인 

void BFS(){
    queue<int> Q;
    for (int i=1; i<=n; i++)        // 모든 노드를 시작점으로 확인(Disconnected cases)
        if (tr[i])                  // 진실을 안다면 BFS 시작 
            Q.push(i);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt : adj[cur]){
            if(tr[nxt]) continue;   // 이미 방문(진실을 안다면)
            tr[nxt] = true;
            Q.push(nxt);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> t;
    while (t--){    // number of knowers
        int x;      // knowers
        cin >> x;
        tr[x] = true;
    }
    
    for (int i = 0; i < m; i++){
        int np;
        cin >> np;      // 참석자 수 
        
        int prev, next; // 참석자 : 앞-뒤 사람들끼리 edge로 연결되었다고 생각 
        cin >> prev;
        party[i].push_back(prev);
        
        while(--np){
            cin >> next;
            party[i].push_back(next);
            adj[next].push_back(prev);
            swap(prev, next);
        }
    }
    // BFS 수행 : 진실을 아는 사람을 기준으로 연결된 인원에게 진실 전파 
    BFS();
    
    // 결과 확인 : 거짓말이 가능한 파티수
    int cnt = 0;
    for (int i=0; i<m; i++){
        bool known = 0;
        for (int p : party[i])
            if (tr[p]) known = 1;
        if (!known) cnt++;
    }
    cout << cnt;
}
