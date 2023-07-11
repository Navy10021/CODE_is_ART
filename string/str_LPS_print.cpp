#include <bits/stdc++.h>
using namespace std;


// Return length of LCS for X[0 ... m-1], Y[0 ... n-1]
string LCS(string X, string Y){ // string& X, string& Y
    int m = X.length();
    int n = Y.length();
    
    int L[m+1][n+1];    // 2-dim array
    // L[i][j] : LCS 길이를 저장 
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    int idx = L[m][n];  // max length of LCS
    string lcs(idx + 1, '\0');  // array to store the LCS string
    
    int i = m, j = n;
    while (i > 0 && j > 0){
        // string X와 Y의 character가 같으면 현재 char은 LCS의 일부 
        if (X[i-1] == Y[j-1]){
            lcs[idx - 1] = X[i - 1];
            i--;
            j--;
            idx--;
        }
        // LCS 길이가 긴쪽으로 index 이동 
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}

string LPS(string str){
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    return LCS(str, rev);
}

int main(){
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    cout << "LCS : "<< LCS(S1, S2) << '\n';
    cout << "LPS : "<< LPS(S1) << '\n';
    return 0;
}
