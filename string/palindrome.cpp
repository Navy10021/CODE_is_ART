// Palindrome
#include <iostream>
#include <string.h>
using namespace std;

bool palindrome(char* str){
    int l = 0;
    int r = strlen(str) - 1;
    
    while(r > l){
        if (str[l++] != str[r--]) 
            return false;
    }
    return true;
}

bool palindrome2(string str){
    int l = 0;
    int r = str.size() - 1;
    while (r > l){
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}

int main()
{
    //char str[] = "SNUNS";
    //bool res = palindrome(str);
    //cout << res << '\n';        // true = 1 ; false = 0;
    
    string str2 = "SNUNS";
    bool res2 = palindrome2(str2);
    cout << res2;
}
