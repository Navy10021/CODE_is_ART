#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;
vector<int> adj[MX];
int indeg[MX];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;  
    int no, u, v;
    for (int i = 0; i < m; i++){
        cin >> no;
        if (no == 0) continue;
        cin >> u;
        while(--no){
            cin >> v;
            adj[u].push_back(v);
            indeg[v]++;
            swap(u, v);
        }
    }

    // Topological sorting
    queue<int> Q;
    vector<int> res;
    for (int i=1; i<=n; i++){
        if (!indeg[i]) Q.push(i);
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        res.push_back(cur);

        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt]==0) Q.push(nxt);
        }
    }
    if (res.size() != n){
        cout << 0;
        }
    else{
            for (auto s : res) 
                cout << s << " ";
        }
}
