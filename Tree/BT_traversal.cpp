/*
Tree : visited array 대신 parent array && depth array 사용
전위순회(Preorder Traversal) : 현재 정점 방문 -> 왼쪽 서브트리 -> 오른쪽 서브트리 / 전위순회 == DFS
중위순회(Inorder Traversal) : 왼쪽 서브트리 -> 현재 정점 -> 오른쪽 서브트리
후위순회(Postorder Traversal) : 왼쪽 서브트리 -> 오른쪽 서브트리 -> 현재정점
*/
#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};

void preorder(int cur){ // 현재 -> 왼쪽 -> 오른쪽
    cout << cur << ' ';
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}


void inorder(int cur){
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
    if (lc[cur] != 0) postorder(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) postorder(rc[cur]);
}


int main(){
    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}
