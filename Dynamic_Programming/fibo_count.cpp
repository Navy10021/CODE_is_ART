// fibo : fibonacci(N)을 호출 했을 때 0과 1이 각각 몇번 호출되는지 구하는 프로그래밍
// N <= 40
// 0이 출력되는 횟수와 1이 출력되는 횟수 구분 

#include <bits/stdc++.h>
using namespace std;

int fibo[42][2];    // 1-row : 0 호출 개수 / 2-row : 1 호출 개수
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fibo[0][0] = 1;
    fibo[1][1] = 1;
    
    for (int i = 2; i <= 40; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][0];
    }
    int N;
    cin >> N;
    cout << fibo[N][0] << " " << fibo[N][1] << "\n";
}
