// Count Distinct subsequences : Given two string S and T -> Count of distinct occurrences of T in S.
// S = banana   T = ban -> [ban] [ba  n] [b  an]
#include <bits/stdc++.h>
using namespace std;

int cnt_sub_seq(int i, string S, int j, string T){  // i : S'index  j : T'index
    // T가 모두 삭제 된 경우 +=1
    if (j >= T.size()) return 1;
    // S가 모두 삭제된 경우 +=0;
    if (i >= S.size()) return 0;
    // S와 T의 character가 매칭되는 경우 -> S & T를 지운 경우 + S만 지운 경우 
    if (S[i] == T[j]){
        return cnt_sub_seq(i+1, S, j+1, T) + cnt_sub_seq(i+1, S, j, T); // recursive sum
    }
    // S와 T가 매칭되지 않는 경우 -> S만 삭제 
    return cnt_sub_seq(i+1, S, j, T);       // recursive 
}

int find_sub_seq(string S, string T){
    return cnt_sub_seq(0, S, 0, T);
}

int main(void){
    string S = "BANANA";
    string T = "BAN";
    cout << find_sub_seq(S, T) << '\n';
    return 0;
}

