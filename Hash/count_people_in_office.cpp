#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        
        string check, name;
        cin >> name >> check;
        // Hash
        if (check == "enter")
            s.insert(name);
        else s.erase(name);
    }
    // 벡터 array에 결과값을 넣고 -> 알파벳 내림차순 정렬(역순) 
    vector<string> res(s.begin(), s.end());
    sort(res.begin(), res.end(), greater<string>());
    
    for(auto e : res) cout << e << "\n";
}
