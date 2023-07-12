// Minimum characters delection to make a string palindrome
#include <bits/stdc++.h>
using namespace std;

// Remove all subsequnces one by one and check if the remaining string is palindrome.
// Two pointer : first(i) last(j) -> If char is equal : ++i ; --j; -> else : min(f(++i,j), j(i,--j))+1
int min_del_palindrome(string str, int i, int j){
    if (i >= j)
        return 0;
    
    if (str[i] == str[j]){
        return min_del_palindrome(str, i+1, j-1);
    }
    //else
    return 1 + min(min_del_palindrome(str, i+1, j), min_del_palindrome(str, i, j-1));
}

int main(){
    string str = "ABEFBAC";
    int res = min_del_palindrome(str, 0, str.length()-1);
    cout << res << '\n';
    return 0;
}
