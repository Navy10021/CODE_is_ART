#include <iostream>
using namespace std;

// Merge Sort. 배열 합치기기
int n, m;
const int MX = 1000005;
int a[MX], b[MX], c[MX];
    
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    // 배열 합치기 
    int a_idx = 0, b_idx = 0;
    
    for (int i = 0; i < n+m; i++){
        if (a[a_idx] <= b[b_idx]) c[i] = a[a_idx++];
        else if (b_idx == m) c[i] = a[a_idx++];    // b_idx가 마지막인 경우 
        else if (a_idx == n) c[i] = b[b_idx++];    // a_idx가 마지막인 경우
        else c[i] = b[b_idx++];
    }
    
    for(int i = 0; i < n+m; i++) cout << c[i] << ' ';
}
    
