// Minimum characters to be added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;


// is palindrome;
bool palindrome(string str){
    int l = 0;
    int r = str.size()-1;
    while (r > l){
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}


int main()
{   
    string txt = "BABABAC";
    int cnt = 0;
    int flag = 0;   // is palindrome -> flag = 1; else flag = 0;
    string add_str = "";
    string erase_str;
    
    while(txt.size() > 0){
        if (palindrome(txt)){
            flag = 1;
            break;
        }
        else{
            cnt++;
            add_str += txt[txt.length()-1];
            txt.erase(txt.begin() + txt.length() - 1);
        }
        erase_str = add_str;
        reverse(add_str.begin(), add_str.end());
    }
    if(flag)
        cout << cnt << '\n';
        cout << add_str + txt + erase_str << '\n';
}
