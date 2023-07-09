#include<bits/stdc++.h>
using namespace std;

// print frequency of each character in alphabetical order : using map  

void compress_str(string str){
    
    // map pair
    map<char, int> mp;
    // map over string
    for (auto it : str) mp[it]++;
    
    for (auto it : mp)
        cout << it.first << it.second;
}

int main()
{
    string input = "AABBBCCCC";
    compress_str(input);
    //cout << output << '\n';
    
    return 0;
}
