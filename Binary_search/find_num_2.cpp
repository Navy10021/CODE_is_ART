#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;          // array size 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);   // 반드시 정렬
    
    int m;
    cin >> m;
    while (m--){
        int tgt;
        cin >> tgt;
        cout << binary_search(a, a+n, tgt) << '\n';     // {범위의 시작, 범위의 끝, 타겟} -> true / false로 반환
                                                        // vector인 경우 {v.begin(), v.end(), target}
    }
}
