// Count Distinct subsequences : GFG -> G, F, GF, GFG
#include <bits/stdc++.h>
using namespace std;

// 1. subsequences를 담을 empty set을 생성
set<string> sub_set;

// 2. subsequences를 생성하는 함수
void sub_seq(char str[], char output[], int i, int j){
    // Base case : 생성된 subsequences를 set에 저장 
    if (str[i] == '\0'){
        output[j] = '\0';
        
        sub_set.insert(output);
        return;
    }
    // Recursive case
    else {
        // 특정 char를 이미 받았으면, i + 1 & j + 1
        output[j] = str[i];
        sub_seq(str, output, i+1, j+1);
        
        // 특정 char를 받지 않았으면, i + 1 & j
        sub_seq(str, output, i+1, j);
        return;
    }
    
}


int main(){
    char str[] = "GSDS";
    int m = sizeof(str) / sizeof(char); // m = 5
    int n = pow(2, m) + 1;              // n = 2**5 +1;
    
    char output[m + 1];      // output array for storing generating subsequences
    
    sub_seq(str, output, 0, 0);
    cout << sub_set.size() << '\n';
    
   for (auto it = sub_set.begin(); it != sub_set.end(); ++it) cout << ' ' << *it;
    
    sub_set.clear();
    return 0;
}


