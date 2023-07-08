#include <bits/stdc++.h>
using namespace std;


// N개의 로프를 이용하여 들어 올릴 수 있는 최대 중량 구하기.
// k개 로프를 사용하여 중량(w)을 들어올릴 때 각 로프에 걸리는 중량 : w / k 

// 로프의 최대 중량을 정렬 -> k개 로프 구하기 (w[n-k]*k)
int n;
int w[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;   // 로프의 개수 
    for (int i = 0; i < n; i++) cin >> w[i];    // 로프의 중량 
    sort(w, w+n);
    
    int res = 0;    // k개의 로프로 들어올릴 수 있는 최대 중량 
    for (int i = 1; i <= n; i++) 
        res = max(res, w[n-i]*i);
    cout << res;
}
