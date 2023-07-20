/*
이진검색트리(BST) : set, multiset, map : 자동으로 sorting되어 저장 
insert && search && erase 모두 O(logN)
prev, next 사용이 필요하거나 대부분의 경우 set / map 사용을 추천 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> m;
    m["Lee"] = 100;
    m["Park"] = 80;
    m["Kim"] = 60;
    m["Aana"] = 90;
    m["Babo"] = 10;
    
    cout << m.size() << '\n';
    m["Kim"] = 40;
    if(m.find("Kim") != m.end()) cout << m["Kim"] << '\n';
    else cout << "Not in map";
    m.erase("Park");
    
    for(auto e : m) cout << e.first << " : " << e.second << " -- ";
    
    // iterator : // pair<string, int>로 되어 있기 때문에 ->first or ->second로 key value 접근
    auto it1 = m.find("Kim");
    auto it2 = prev(it1);
    auto it3 = next(it1);
    cout << it1->first << " : " << it1->second << '\n';
    cout << it2->first << " : " << it2->second << '\n';
    cout << it3->first << " : " << it3->second << '\n';
}
