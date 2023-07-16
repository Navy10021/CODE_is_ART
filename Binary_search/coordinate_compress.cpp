/*
X1 ... Xn -> Xi > Xj를 만족하는 Xj의 개수 : 중복을 제외하고 나보다 작은 숫자 몇개?
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
vector<int> tmp, uni;   // uni : 중복제거된 배열 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        tmp.push_back(a[i]);    
    }
    
    // 1. sort
    sort(tmp.begin(), tmp.end());
    
    // 2. remove duplicate 
    for(int i=0; i<n; i++){
        if (i == 0 || tmp[i-1] != tmp[i])
            uni.push_back(tmp[i]);
    }
    
    // 3. lower bound(a.k.a Binary Search)
    for (int i=0; i<n; i++)
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
  
    return 0;
}
