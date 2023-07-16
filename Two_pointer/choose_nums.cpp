/*
수 고르기 : 수열 A에서 2개의 원소를 골랐을 때, 그 차이가 M 이상이면서 가장 작은 경우 
*/

#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[100005];
int ans = 0x7fffffff;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    
    int en = 0;
    for (int st=0; st<n; st++){
        while(en < n && a[en]-a[st] < m) en++;  // en을 증가시키는 조건!
        if (en == n) break;                     // en이 범위를 벗어나면 종료!
        ans = min(ans, a[en]-a[st]);
    }
    cout << ans;
}
