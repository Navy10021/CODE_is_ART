#include<bits/stdc++.h>
using namespace std;

// remove characters in a string
string remove_char(string str, char c){
    // Base case 
    if (str.length() == 0){
        return "";
    }
    
    if (str[0] == c){
        // pass the rest of the string 
        return remove_char(str.substr(1), c);   // substr(start position, length) : length를 입력하지 않으면 전체 문자열 
    }
    return str[0] + remove_char(str.substr(1), c);
}


int main(void){
    string input = "SNU GSDS";
    string output = remove_char(input, 'S');
    cout << output << '\n';
    
    return 0;
}
