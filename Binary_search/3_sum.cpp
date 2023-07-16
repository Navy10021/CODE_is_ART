/*
집합(U)에서 세개의 수를 골랐을때 그 합(sum)이 U안에 포함된 경우 중 가장 큰 sum
ex) {2,3,5,10,18} -> 가장 큰 sum : 3+5+10 = 18 

two[m] + a[k] = a[l]을 만족하는 a[l] 중 최대값 
k, l 2중 for문 -> a[l] - a[k]가 배열 two에 있는지 이분 탐색 
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
vector<int> two;    // 집합의 i, j의 원소 합(sum) 을 저장

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i=0; i<n; i++) cin >> a[i];
    
    // two sum array 
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++)
            two.push_back(a[i]+a[j]);
    }
    
    // sorting
    sort(two.begin(), two.end());
    
    // Binary search
    for (int i = n-1; i > 0; i--){      // 3개 수의 합(3sum) 
        for (int j = 0; j < i; j++){    // 1개 수(k)
            if (binary_search(two.begin(), two.end(), a[i]-a[j])){  // 3 sum - k = l(최대값) -> l이 존재하는 지 Binary search
                cout << a[i];
                return 0;
            }
        }
    }
}
