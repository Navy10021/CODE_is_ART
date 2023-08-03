/*
Tree : visited array 대신 parent array && depth array 사용
레벨 순회(Level-order Traversal) : 레벨 순서데로 순회 
*/
#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};

void BFS(){
    queue<int> Q;
    Q.push(1);  // root = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        if(lc[cur]) Q.push(lc[cur]);
        if(rc[cur]) Q.push(rc[cur]);
    }
}

int main(){
    BFS();
}
