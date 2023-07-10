#include<bits/stdc++.h>
using namespace std;

// print all subsequence of given string : ABC -> A B C AB BC AC ABC

void sub_seq(string in_str, string out_str){
    // Base case
    if (in_str.empty()){
        cout << out_str << '\n';
        return;
    }
    // including i-st char 
    sub_seq(in_str.substr(1), out_str + in_str[0]);
    // excluding i-st char 
    sub_seq(in_str.substr(1), out_str);
}


int main(void){
    string input = "ABC";
    string output = "";
    sub_seq(input, output);
    
    return 0;
}
