#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;   // key<string> : value<int>
    m["LEE"] = 100;
    m["KIM"] = 90;
    m["PARK"] = 85;
    cout << m.size() << '\n';
    
    m["LEE"] = 120;     // {LEE : 120, KIM : 90, PARK : 85} 업데이트 중복X
    
    if(m.find("LEE") != m.end()) cout << "LEE's score is " << m["LEE"];
    else cout << "No data";
    cout << "\n";
    
    m.erase("KIM");
    for (auto e : m)
        cout << e.first << " : " << e.second << ", ";
}
