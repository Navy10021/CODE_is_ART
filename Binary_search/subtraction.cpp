// 차집합 집합 A에는 속하면서 집합 B에는 속하지 않는 모든 원소 구하기 
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A, B;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    int num;
    for (int i=0; i<n; i++){
        cin >> num;
        A.push_back(num);
    }
    
    for (int i=0; i<m; i++){
        cin >> num;
        B.push_back(num);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> ans;                // binary search한 결과를 입력할 vector 
    for (int num : A){
        if(!binary_search(B.begin(), B.end(), num)){   // B집합 내에서 binary search가 되지 않은 원소를 입력
            ans.push_back(num);    
        }
    }
    cout << ans.size() << '\n';     
    for (int num : ans) cout << num << " ";
}


