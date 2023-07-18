#include <bits/stdc++.h>
using namespace std;

int n;
string check, name;

int main(void){
    vector<string> m;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--){
        cin >> name >> check;
        if (check == "enter"){
            m.push_back(name);
        }
        else if (check == "leave"){
            m.erase(remove(m.begin(), m.end(), name), m.end());
        }
    }
    
    for(auto e : m) cout << e << "\n";
}
