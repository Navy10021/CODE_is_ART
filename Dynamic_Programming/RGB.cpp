#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int DP[MX][3];    // RGB
int R[MX], G[MX], B[MX];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> R[i] >> G[i] >> B[i];
    DP[1][0] = R[1];
    DP[1][1] = G[1];
    DP[1][2] = B[1];
    
    for (int i = 2; i <= n; i++){
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + R[i];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + G[i];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + B[i];
    }
    int res = min({DP[n][0],DP[n][1],DP[n][2]});
    //int res = *min_element(DP[n], DP[n]+3);   // min_element(arr, arr+size)
    
    cout << res;
}
