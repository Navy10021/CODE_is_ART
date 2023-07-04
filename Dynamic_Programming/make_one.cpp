#include <bits/stdc++.h>
using namespace std;

// 정수 1 만들기 : 3가지 공식만을 사용

int DP[100005];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    DP[1] = 0;
    for (int i = 2; i<= n; i++){
        DP[i] = DP[i-1] + 1;                                // -1 
        if (i % 2 == 0) DP[i] = min(DP[i], DP[i/2]+1);      // 2로 나누는 경우
        if (i % 3 == 0) DP[i] = min(DP[i], DP[i/3]+1);     // 3로 나누는 경우 
        }
        cout << DP[n];
}
