/*
X1 ... Xn -> Xi > Xj를 만족하는 Xj의 개수 : 중복을 제외하고 나보다 작은 숫자 몇개?
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
vector<int> uni;   // uni : 중복제거된 배열 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        uni.push_back(a[i]);    
    }
    
    // 1. sort
    sort(uni.begin(), uni.end());
    
    // 2. remove duplicate : 
    // unique(vector.begin(), vector.end()) : 중복을 제거해주고 제거된 공간만큼 쓰레기값 넣어줌.
    // vector.erase(unique(), vector.end()) : 뒤에 쓰레기값을 제거
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    
    // 3. lower bound(a.k.a Binary Search)
    for (int i=0; i<n; i++)
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
    return 0;
}
