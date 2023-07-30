/*
회장 선출 
1. start node 모두 확인하면서
2. dist를 구하고,
3. me = * max_element(dist, dist + n)
4. me + me-1 ... + 1;
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[52];
int score[52];  // 거리가 가장 먼 값 저장
int n;          // number of node

int BFS(int st){ // start node의 거리 계산 
    queue<int> Q;
    int dist[52];
    fill(dist, dist+n+1, -1);
    
    dist[st] = 0;
    Q.push(st);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt : adj[cur]){
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    // 가장 먼 거리값 리턴 
    int res = *max_element(dist+1, dist+n+1);   // strat index == 1 이므로.. dist + 1, dist + n + 1 
    if (res == 0) return 100;   // 친구가 없는 경우
    return res;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;  // the number of node, edge
    int u = 0, v = 0;
    while(u != -1 && v != -1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i=1; i<= n; i++)
        score[i] = BFS(i);
    
    // score가 가장 낮은 점수와 회장의 수
    int mn_score = *min_element(score+1, score+n+1);
    // 후보 목록 저장
    vector<int> candidates;
    for (int i = 1; i <= n; i++){
        if (score[i] == mn_score) candidates.push_back(i);
    }
    cout << mn_score << ' ' << candidates.size() << '\n';
    for (int c : candidates)
        cout << c << '-';
}
