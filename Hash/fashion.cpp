// Fashion ; {colth : nums} -> 가지수 = nums * nums ... -1 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_map<string, int> m;
    int n, res = 1;
    cin >> n;
    while(n--){
        string a, b;
        cin >> a >> b;
        m[b]++;
    }
    for (auto e : m) res *= e.second + 1; // 안입은 경우 +1 
    cout << res - 1 << '\n';
}
