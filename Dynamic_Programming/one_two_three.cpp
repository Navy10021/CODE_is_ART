#include <bits/stdc++.h>
using namespace std;

// 1, 2, 3 더하기 : 정수 n이 주어졌을 떄 1, 2, 3의 합으로 나타내는 방법의 수.

int DP[20];
int main(void){
    int n;
    cin >> n;
    // base condition
    DP[1] = 1; DP[2] = 2; DP[3] = 4;
    
    // n : 11 보다 작은 정수 
    for (int i=4; i<11; i++){
        // D[4] = D[1] + D[2] + D[3]
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }
    cout << DP[n] << '\n';
}
