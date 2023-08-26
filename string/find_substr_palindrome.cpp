// Naive Pattern searching algorithm
#include <bits/stdc++.h>
using namespace std;


// is palindrome;
bool palindrome(string str){
    int l = 0;
    int r = str.size()-1;
    while (l <= r){
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}

// Order by length
struct myOrder{
    bool operator() (const string& left, const string& right) const{
        if (left.size()==right.size()){
            return left < right;
        }
        else {
            return left.size() < right.size();
        }
    }
};


void find_palindrome_substring(string str){
    set <string, myOrder> s;
    // Traverse string substring
    int n = str.size();
    for (int i = 0; i < n; i++){
        for (int len = 1; len <= n; len ++){
            // if substring is palindrome -> insert in set 
            if (palindrome(str.substr(i, len)))
                s.insert(str.substr(i, len));
        }
    }
    // print set
    for(auto iter : s) cout << iter << " ";
}


int main()
{   
    string txt = "ABCBA";
    find_palindrome_substring(txt);
    return 0;
    
}
