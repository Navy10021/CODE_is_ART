// 무한 수열 : A0 = 1, A_i = A_l/p + A_l/q
// N, P, Q가 주어졌을 때 A_n을 구하는 프로그램.

#include <bits/stdc++.h>
using namespace std;

long long n;
int p, q;
unordered_map<long long, long long> m;

long long solve(long long x){
    if (x == 0) return 1;
    if (m[x]) return m[x];              // 값을 이미 계산했다면 반환
        
    m[x] = solve(x/p) + solve(x/q);     // 값 계산 
    
    return m[x];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p >> q;
    cout << solve(n);
}
