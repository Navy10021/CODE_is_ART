/*
이진검색트리 : set, multiset, map 
insert && search && erase 모두 O(logN)
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> ms; // binary search tree
    // Insert
    ms.insert(1); ms.insert(5); ms.insert(10);
    ms.insert(10);    // 중복허용
    ms.insert(1);
    ms.insert(-10);
    for(auto e: ms) cout << e << ' ';
    cout << '\n';
    
    if(ms.find(3) != ms.end()) cout << "3 in s\n";    // 없으면 s.end()를 return
    else cout << "3 not in s\n";
    
    cout << ms.erase(1) << '\n';    // 삭제된 개수 리턴 {-10, 5, 10, 10};
    
    ms.erase(ms.find(10));          // 한개만 삭제 {-10, 5, 10}
    ms.insert(100); ms.insert(100); ms.insert(100);
    cout << ms.count(100) << '\n';
    
    // iterator 
    auto it1 = ms.begin();            // {-10(<--it), 5, 10, 100, 100, 100}
    auto it2 = ms.upper_bound(100);   // {-10, 5, 10, 100, 100, 100, 100} <--(it) ms.size() 100보다 큰 최초값
    auto it3 = ms.find(100);          // {-10, 5, 10, 100(<--it), 100, 100,}
    
    cout << *it1 << '\n';
    cout << *it2 << '\n';
    cout << *it3 << '\n';
}
