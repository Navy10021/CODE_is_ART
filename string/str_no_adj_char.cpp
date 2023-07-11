// Longest subsequnce with different adjacent characters
#include <bits/stdc++.h>
using namespace std;

// Greedy approach
string long_adj_char(string str){
    int n = str.size();
    int cnt = 0;
    string res = "";
    
    char prev = '#';
    
    for (int i = 0; i < n ; i++){
        // current character가 previous character와 다르면 prev 업데이트 및 count ++
        if (prev != str[i]){
            prev = str[i];
            res += str[i];
            cnt ++;
        }
    }
    return res;
}


int main(){
    string str = "ABBBBBABBBBBCC";
    cout << long_adj_char(str);
}
