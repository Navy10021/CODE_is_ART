// Naive Pattern searching algorithm
#include <bits/stdc++.h>
using namespace std;


void search(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    
    // Silde pat[] one by one 
    for (int i=0; i <= n-m; i++){
        // For current index i, check for pattern match
        int j;
        for(j = 0; j < m; j++){
            if (txt[i+j] != pat[j])
                break;
        }
        if (j == m)         // if pat[0 ... M-1] = txt[i, i+1, ... i+M-1]; 
            //cout << txt.substr(i, m) << '\n';
            cout << i << '\n';
    }
}


int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";

    search(txt, pat);
    return 0;
    
}
