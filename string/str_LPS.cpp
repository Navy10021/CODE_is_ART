// LPS : Longest Palindromic Subsequence
// BBABCBCAB -> BABCBAB
#include <bits/stdc++.h>
using namespace std;


int LPS(char* str, int i, int j){
    // Two pointer i, j
    // Base case 1 : only one character 
    if (i == j) return 1;
    
    // Base case 2 : only two character
    if (str[i] == str[j] && i + 1 == j) return 2;
    
    // 만약 첫 알파벳과 마지막 알파벳이 매칭되면 +=2 
    if (str[i] == str[j])
        return LPS(str, i+1, j-1) + 2;
        
    // 매칭되지 않으면 i + 1칸 or j - 1칸 중 큰것
    return max(LPS(str, i, j-1), LPS(str, i+1, j));
}

int main(){
    char str[] = "ABZZCBCA"; // ABCCBA
    int n = strlen(str);
    cout << LPS(str, 0, n-1);
    return 0;
}

