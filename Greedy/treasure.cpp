// array A & B
// S = A[0] x B[0] + ... + A[N-1] x B[N-1]
// S 값을 작게 만들기 위해 A를 재배열. B는 그대로 -> S의 최소값

// 재배열 부등식 : 큰원소 <-> 작은 원소 매칭 

#include <bits/stdc++.h>
using namespace std;


int a[105], b[105];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+n);
    
    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i] * b[n-1-i]; // A 최대값 x B 최소값
    cout << res;
}
