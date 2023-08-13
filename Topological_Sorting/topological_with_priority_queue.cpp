#include <bits/stdc++.h>
using namespace std;

// 최소힙을 활용하여 낮은 번호를 먼저 선택(순서에 기반한 위상정렬)
// priority queue : 가장 높은 값 = TOP() 유지 
// priority queue<int, vector<int>, greater<int>> : 가장 작은 값 = TOP() 유지

int n, m;  // vertecis, edge
priority_queue<int, vector<int>, greater<int>> PQ;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int indgre[n + 2] = {};
    vector<int> adj[n + 2];
    
    // 인접리스트 + 진입차수
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indgre[b]++;
    }

    // 위상정렬
    for (int i = 1; i <= n; i++){
        if (!indgre[i]) PQ.push(i);
    }
    while (!PQ.empty()){
        auto curr = PQ.top(); PQ.pop();
        cout << curr << " ";
        for (int nxt : adj[curr]){
            indgre[nxt]--;
            if (!indgre[nxt]) PQ.push(nxt);
        }
    }
}
