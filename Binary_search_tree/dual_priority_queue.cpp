#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    multiset<int> ms;    // 이진검색트리 : set, multiset, map
    while(t--){
        char oper;
        int q;
        cin >> oper >> q;
        
        if (oper == 'D'){
            if (ms.empty()) continue;
            // prev : 가장 큰 원소의 주소값 -> prev(ms.end());  // ms.end() : {0,1,2,3,4,} (<-- it)
            if (q == 1) ms.erase(prev(ms.end()));
            // multiset.begin() : 가장 작은 원소의 주소값 -> ms.begin() : ms.begin() : {0(<--it),1,2,3,4,}
            // 만약 ms.erase(*ms.begin()) 경우 최솟값이 여러개일때 모두 삭제함.
            else ms.erase(ms.begin());
        }
        // oper == I 
        else {
            ms.insert(q);
        }
    }
    
    if (ms.empty()) cout << "EMPTY";
    
    else{
        cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
    
}
