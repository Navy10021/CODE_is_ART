// LCS problem : Longest Common Subsequences

#include <bits/stdc++.h>
using namespace std;


// Return length of LCS for X[0 ... m-1], Y[0 ... n-1]
int LCS(string X, string Y, int m, int n){
    if (m == 0 || n == 0) 
        return 0;
    if (X[m-1] == Y[n-1])                   // string.end() 부터 character가 같으면 양쪽 index 감소 
        return 1 + LCS(X, Y, m-1, n-1);
    else                                    // 다르면 한쪽만 감소 후 max값
        return max(LCS(X, Y, m, n-1), LCS(X, Y, m-1, n)); 
}

int main(){
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    
    int m = S1.length();
    int n = S2.length();
    
    cout << "Length of LCS : " << LCS(S1, S2, m, n);
    return 0;
}
