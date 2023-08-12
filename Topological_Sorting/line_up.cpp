// A -> B : A가 B보다 앞에 있어야함.
#include <bits/stdc++.h>
using namespace std;

const int MX = 32000;
vector<int> adj[MX];
int indeg[MX];
int n, m;

void toplogical(){
    queue<int> Q;
    vector<int> res;

    for (int i=1; i<=n; i++){
        if (indeg[i]==0) Q.push(i);
    }
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        res.push_back(cur);

        for (int nxt : adj[cur]){
            indeg[nxt] --;
            if (indeg[nxt] == 0) Q.push(nxt);
        }
    }
    if (res.size() != n)
        cout << "Graph has Cycle : NO DAG";
    else {
        for (auto x : res) cout << x << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;  // node, edge
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    toplogical();

    return 0;
}
