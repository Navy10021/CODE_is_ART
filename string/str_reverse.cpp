#include<bits/stdc++.h>
using namespace std;

// Reverse : swap character string from two-coners

void reverse_str(string &str){
    int n = str.length();       // length() == size()
    // swap character of string from two coners
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(str[i], str[j]);
}

int main()
{
    string input = "SNU GSDS";
    
    reverse_str(input);
    cout << input << '\n';
    
    return 0;
}
