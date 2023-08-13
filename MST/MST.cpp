// 트리 : 무방향 + 무사이클
// 최소 신장트리(MST) : 그래프의 모든 정점들을 연결하는 부분 중 그 가중치 합이 최소인 트리
// Prim 알고리즘 : 임의의 점을 선택 -> 비용인 최소 간선을 선택(Priority Queue)
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

int v, e;   // vertex, edge(cost)
const int MX = 105;
vector<pair<int, int>> adj[MX];  // <cost, vertex>
bool chk[MX];       // chk[i] : i-th vertex가 MST에 속해 있는지 여부 확인


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i=0; i<e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    int cnt = 0;    // 현재 선택된 간선의 수 
    int ans = 0;
    priority_queue< tuple<int, int, int>,           // <cost, vertex a, vertex b> : cost a->b
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>> > PQ;
    
    chk[1] = true;
    for (auto nxt : adj[1])
        PQ.push({nxt.X, 1, nxt.Y});  // {cost, 1->nxt}

    while (cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = PQ.top(); PQ.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = true;
        cnt++;
        for (auto nxt : adj[b]){
            if (!chk[nxt.Y])
                PQ.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;
}
