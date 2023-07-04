#include <bits/stdc++.h>
using namespace std;

// 계단 오르기 : 한번에 한번 or 두 계단씩 / 연속된 세 개의 계단 X / 마지막 계단은 반드시 밟아야

int score[310]; // 계단 점수 
int n;          // 계단 수 
int DP[310][3]; // 한번씩 오르는 경우 or 두번씩 오르는 경우 

int main(void){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> score[i];
    
    if (n == 1){
        cout << score[1];
        return 0;
    }
    
    // base condition
    DP[1][1] = score[1];
    DP[1][2] = 0;
    DP[2][1] = score[2];
    DP[2][2] = score[1] + score[2];
    
    for (int i = 3; i <= n; i++){
        DP[i][1] = max(DP[i-2][1], DP[i-2][2]) + score[i];
        DP[i][2] = DP[i-1][1] + score[i];
    }
    cout << max(DP[n][1], DP[n][2]) << '\n';
}
