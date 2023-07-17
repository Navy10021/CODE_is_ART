/*
3명의 코딩 실력의 합이 0이 되는 팀 만들기 -> 팀 개수
ex) {2, -5, 2, 3, -4, 7, -4, 0, 1, -6} -> 6개팀 (2,-5,3) (2,2,-4) (2,2-4) (-5,2,3) (3,-4,1) (3,-4,1)
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];

int main(void){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    
    // sorting
    sort(a, a + n);
    
    // binary search : 두명을 선택하고, 나머지 한명을 이분 탐색으로 찾는다.
    long long ans = 0;  // 합이 0이되는 묶음 개수 
    for (int i=0; i<n-1; i++){      // a[i] + a[j] + a[k] = 0 -> a[k] = -(a[i]+a[j])
        for (int j=i+1; j<n; j++){
            auto up_b = upper_bound(a+j+1, a+n, -(a[i]+a[j]));  // a[k]의 오른쪽 index
            auto low_b = lower_bound(a+j+1, a+n, -(a[i]+a[j])); // a[k]의 왼쪽 index
            ans += (up_b - low_b);                               // 개수 추가  
        }
    }
    cout << ans;
}

