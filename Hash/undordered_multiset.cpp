#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_multiset<int> ms;
    ms.insert(10);   // {10};
    ms.insert(100);  // {10,100}
    ms.insert(1000); // {10,100,1000}
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    ms.insert(10);   // {10, 10, 100, 1000} 중복 O 
    ms.insert(100);  // {10,10,100,100,1000}
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    
    ms.erase(10);    // 모두 지워짐
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    
    ms.erase(ms.find(100)); // 하나만 찾아서 지움 
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    
    if(ms.find(50) != ms.end()) cout << "50 in set\n";    // 없으면 마지막 원소를 반환
    else cout << "50 not in set\n";
    
    cout << ms.size() << '\n';
    cout << ms.count(50) << '\n';    // 원소 여부 확인시 확인 가능 있으면 1, 없으면 0 
}
