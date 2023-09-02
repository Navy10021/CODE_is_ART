/*
<Key(id) : val(bool) 
*/
# include <iostream>
# include <map>
using namespace std;

int main(){
    map<string, bool> m;
    int N, cnt = 0;
    string str1, str2;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str1 >> str2;
        // 초기화 
        if (str1=="Dance")
            m.insert({str1, true});
        else if (str2=="Dance")
            m.insert({str2, true});
        // 둘중 한명이 춤추면(true) 다른 친구도 true
        if (m[str1])
            m[str2] = true;
        if (m[str2])
            m[str1] = true;
    }

    // value가 true인 경우 count
    for (auto &val : m){
        if (val.second)
            cnt++;
    }
    /*
    for (auto iter = m.begin(); iter != m.end(); iter++){
        if (iter->second){
            cnt++;
        }
    }*/
    
    cout << cnt;
}
