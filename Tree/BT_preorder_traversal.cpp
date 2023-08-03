/*
Tree : visited array 대신 parent array && depth array 사용
전위 순회(Preorder Traversal) : 현재 정점을 방문한다 -> 왼쪽 서브트리를 순회 -> 오른쪽 서브트리를 순회
전위 순회 == DFS
*/
#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};

void preorder(int cur){
    cout << cur << ' ';
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

int main(){
    preorder(1);
}
