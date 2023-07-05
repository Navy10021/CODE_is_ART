#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int N;
int arr[MX], DP[MX];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    DP[0] = 0;
    
    for (int i=1; i<=N; i++){
        cin >> arr[i];
        DP[i] = DP[i-1] + arr[i];   // arr 합을 저장 
    }
    int i, j;
    cin >> i >> j;
    int res = DP[j] - DP[i-1];
    
    cout << res;
}
