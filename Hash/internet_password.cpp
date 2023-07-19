// Password ; {주소 : 비밀번호}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;                   // 저장될 사이트 주소 개수 / 사이트 주소의 수 
    string adress, password;
    unordered_map<string, string> my_map;
    
    cin >> n >> m;
    while(n--){
        cin >> adress >> password;
        my_map[adress] = password;
    }
    
    while(m--){
        cin >> adress;
        cout << my_map[adress] << '\n';
    }
}
