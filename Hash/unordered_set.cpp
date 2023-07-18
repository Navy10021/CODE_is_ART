#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);   // {10};
    s.insert(100);  // {10,100}
    s.insert(1000); // {10,100,1000}
    for (auto e : s) cout << e << ' ';
    cout << '\n';
    s.insert(10);   // {10, 100, 1000} 중복 X 
    for (auto e : s) cout << e << ' ';
    cout << '\n';
    
    if(s.find(50) != s.end()) cout << "50 in set\n";    // 없으면 마지막 원소를 반환
    else cout << "50 not in set\n";
    
    cout << s.size() << '\n';
    cout << s.count(50) << '\n';    // 원소 여부 확인시 확인 가능 있으면 1, 없으면 0 
}
