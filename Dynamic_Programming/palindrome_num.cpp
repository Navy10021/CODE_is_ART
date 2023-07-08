// N개의 자연수, S~E까지 숫자가 팰린드롬인지 아닌지 확인
#include <bits/stdc++.h>
using namespace std;


int n;
int a[2005];
int DP[2005][2005];     // 팰린드롬 여부 저장 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    for (int i = 1; i <= n; i++){
        DP[i][i] = 1;
        if (a[i-1] == a[i]) // 연속 같은 수 : 팰린드롬 
            DP[i-1][i] = 1;
    }
    
    for (int gap = 2; gap < n; ++gap){      // 2이상 gap을 가지면서 
        for (int i = 1; i <= n - gap; ++i){ // index 1 ~ n;
            int s = i;
            int e = i + gap;
            
            if (a[s] == a[e] && DP[s + 1][e - 1])
                DP[s][e] = 1;
        }
    }
    int s, e;
    cin >> s >> e;
    cout << DP[s][e];
    
    return 0;
}
