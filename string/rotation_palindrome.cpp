// Rotation of Palindrome
#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str){
    int l = 0;
    int r = str.size() - 1;
    while (r > l){
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}

bool is_rotation_palindrome(string str){
    // itself palindrome 
    if (is_palindrome(str))
        return true;
    // Try all rotations one by one.
    int n = str.size();
    for(int i = 0; i < n - 1; i++){
        string s1 = str.substr(i + 1, n - i - 1);
        string s2 = str.substr(0, i + 1);
        if (is_palindrome(s1.append(s2)))
            return true;
    }
    return false;
}

int main()
{
    string str = "AABB";
    cout << is_palindrome(str) << '\n' << is_rotation_palindrome(str);
}
