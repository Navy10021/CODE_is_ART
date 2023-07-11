#include <bits/stdc++.h>
using namespace std;


// LPSub : Longest Palindromic Substring
// SNUGSDSSD -> DSSD 

int LPSub(string str){
    string lps = "";
    string sub = "";
    string rev = "";
    
    int str_len = str.size();
    int j;
    
    for (int i = 0; i < str_len; i++){
        j = str_len - 1;
        while (i < j){
            // 만약 first char 과 last char 같고, 현재까지 크기가 가장클떄 palindrome 확인 
            if (str[i] == str[j] && lps.size() < j-i+1){
                // substirng이 palindrome이면 저장
                sub = str.substr(i, (j-i+1));
                rev = sub;
                reverse(rev.begin(), rev.end());
                if (sub == rev){
                    lps = sub;
                    //cout << lps << '\n';
                }
            }
            j--; // j 안쪽으로 이동
        }
    }
    // Longest substring이 없으면 첫번째 character를 리턴
    if (lps.size() == 0){
        lps = str[0];
    }
    // LPSub 출력
    cout << "Longest Palindrome Substring : " << lps << '\n';
    cout << "LPS length : " << lps.size() << '\n';
    return lps.size();
}

int main(){
    string str = "ABBBACCACAAC";
    LPSub(str);
    return 0;
}
