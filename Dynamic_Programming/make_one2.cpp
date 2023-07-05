#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int DP[MX];
int pre[MX];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    DP[1] = 0;
    for (int i = 2; i <= n; i++){
        DP[i] = DP[i-1] + 1;
        pre[i] = i - 1;
        
        if (i % 2 == 0 && DP[i] > DP[i/2] + 1){ // 2로 나눠 떨어지고, 계산 수가 작은 경우
            DP[i] = DP[i/2] + 1;        // 계산수 
            pre[i] = i/2;               // 계산 결과
        }
        if (i % 3 == 0 && DP[i] > DP[i/3] + 1){
            DP[i] = DP[i/3] + 1;
            pre[i] = i/3;
        }
    }
    
    cout << DP[n] << '\n';
    
    int cur_res = n;
    while(1){
        cout << cur_res << ' ';
        if (cur_res == 1) break;
        cur_res = pre[cur_res];
    }
}
