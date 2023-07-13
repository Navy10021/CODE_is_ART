#include <bits/stdc++.h>
using namespace std;
// Count of total Anagram Substrings.
// "xyyx" -> {x, x} {y, y} {xy, yx} {xyy, yyx}
#define MAX_CHAR 52

int char_to_num(char c){
    return c - 'A';
}

int cnt_anagram_substr(string str){
    int n = str.length();
    // 1. Store substring conunt using MAP
    map<vector<int>, int> mp;   // map<key, value> mp; key를 기준으로 오름차순정렬
    // 2. Traverse all substrings   
    // Loop for start index of substring
    for (int i=0; i < n; i++){
        vector<int> freq(MAX_CHAR, 0);   // 각 string 시작 인덱스마다 vector 만들고, 0으로 초기화

        // Loop for length of substring 
        for (int j = i; j < n; j++){
            // update frequnce array of current substring
            freq[char_to_num(str[j])]++;
            // increase count corresponding to this freq array 
            mp[freq]++; // map<vector[0,1,0,...0], count>
        }
    }
    // 3. Loop over all different freq array & sum count;
    int res = 0;
    for (auto it = mp.begin(); it != mp.end(); it++){
        res += (it->second * (it->second - 1)) / 2;
        //cout << it->first;
    }
    return res;
}


int main(){
    string str = "XYYX";
    cout << cnt_anagram_substr(str);
    return 0;
}
