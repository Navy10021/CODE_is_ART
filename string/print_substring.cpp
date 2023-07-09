#include<bits/stdc++.h>
using namespace std;

// print all substring of given string 

void sub_str(string str, int n){
    for (int i = 0; i < n; i++){                    // start position
        for (int len = 1; len <= n - i; len ++){    // print lenght
            cout << str.substr(i, len) << '\n';
        }   
    }
}


int main(void){
    string input = "ABC";
    sub_str(input, input.size());
    
    return 0;
}
