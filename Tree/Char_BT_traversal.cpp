/*
이진트리를 입력받아 preorder + inorder + postorder 결과를 출력하는 프로그램 
preorder : root -> left subtree -> right subtree 
inorder : left subtree -> root -> right subtree 
postorder : left subtree -> right subtree -> root  
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 30;
int lc[MX];
int rc[MX];
int n;

void preorder(int cur){
    cout << char(cur+'A'-1);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur){
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur+'A'-1);
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur+'A'-1);
}

int main(){
    #include <bits/stdc++.h>
    using namespace std;

    // Char 입력값 받기 
    cin >> n;
    for (int i = 1; i <= n; i++){
        char C, L, R;  // curr, left, right
        cin >> C >> L >> R;
        if (L != '.') lc[C-'A'+1] = L-'A'+1;    // Char->int로 변환 : A = 1, B = 2 ... Z = 26;
        if (R != '.') rc[C-'A'+1] = R-'A'+1;
    }
    
    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
}

