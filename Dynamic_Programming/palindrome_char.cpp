// 문자열 str, S~E까지 숫자가 팰린드롬인지 아닌지 확인

#include <bits/stdc++.h>
using namespace std;

string s;
char arr[2005];
int DP[2005][2005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    int n = s.size();
    
    // 1~N까지 
    for (int i=0; i<=n; i++)
        arr[i+1] = s[0];
    
    for (int i = 1; i <= n; i++){
        DP[i][i] = 1;
        if (arr[i-1] == arr[i]) DP[i-1][i] = 1;
    }
    
    for (int gap = 2; gap < n; ++gap){
        for (int i = 1; i <= n-gap; ++i){
            int start = i;
            int end = i + gap;
            
            if (arr[start] == arr[end] && DP[start + 1][end - 1])
                DP[start][end] = 1;
        }
    }
    // 팰린드롬 개수 세기
    int cnt;
    for (int i=1; i <=n; i++)
        for (int j=1; j<=n; j++)
            if (DP[i][j] == 1) cnt++;
    
    cout << cnt/2 << '\n';
}
