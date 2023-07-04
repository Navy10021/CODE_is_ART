#include <bits/stdc++.h>
using namespace std;

// 두 개의 집합(A, B)가 주어졌을 때 A->B 쌍(A.원소 > B.원소)의 개수

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; // A size, B size 
    cin >> N >> M;
    vector<pair <int, int>> V(N+M);
    
    for (int i=0; i<N; i++){
        char a;
        cin >> a;
        V[i] = {a, 0};
    }
    for (int i=N; i<N+M; i++){
        char b;
        cin >> b;
        V[i] = {b, 1};
    }
    
    sort(V.begin(), V.end());
    
    int cnt = 0;    // 현재까지 나온 B집합의 원소 
    int ans = 0;    // A.원소 > B.원소 개수 
    for (int i = 0; i < N+M; i++){
        if(V[i].second == 0) ans += cnt;    // A집합 원소인 겨우
        else cnt ++;                        // B집합 원소인 경우 
    }
    
    for (int i=0; i<N+M; i++)
        cout << '('<< V[i].first << ", " << V[i].second << ')' << ' ';
        
    cout << ans << '\n';
}
