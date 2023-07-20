/*
이진검색트리 : set, multiset, map 
insert && search && erase 모두 O(logN)
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s; // binary search tree : 자동 sorting 저장 
    // Insert
    s.insert(1); s.insert(5); s.insert(10);
    s.insert(3);
    for(auto e: s) cout << e << ' ';
    cout << '\n';
    
    if(s.find(3) != s.end()) cout << "3 in s\n";    // 없으면 s.end()를 return
    else cout << "3 not in s\n";
    
    cout << s.size() << '\n';
    cout << s.count(1000) << '\n';
    
    s.insert(-10);
    for(auto e : s) cout << e << ' ';
    
    // unordered_set과 차이점! move node(iterator)
    cout << "BFS search\n";
    set<int>::iterator it1 = s.begin(); // {-10(<--it), 1, 3, 5, 10}
    it1++;                              // {-10, 1(<--it), 3, 5, 10}
    auto it2 = prev(it1);               // {-10(<--it), 1, 3, 5, 10}
    auto it3 = next(it1);               // {-10, 1, 3(<--it), 5, 10}
    
    cout << *it1 << '\n';
    cout << *it2 << '\n';
    cout << *it3 << '\n';
    advance(it3, +2);                   // {-10, 1, 3, 5, 10(<--it)}
    cout << *it3 << '\n';
    advance(it3, -2);                  
    cout << *it3 << '\n';
    
    auto it4 = s.lower_bound(2);        // {-10, 1(<--it), 3, 5, 10} : 0보다 큰 최초 인덱스의 값 
    auto it5 = s.find(5);
    cout << *it4 << '\n';
    cout << *it5 << '\n';               // 5 
}
