#include <bits/stdc++.h>
using namespace std;

// 단어정렬 : 길이가 짧은 것부터 + 길이가 같으면 사전 순으로 + 중복된 단어 제거 

int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    vector <string> S(N);
    
    for (int i = 0; i < N; i++) cin >> S[i];
    
    // 사전순으로 정렬 + 조건 : 길이가 짧은것 부터 정렬 
    sort(S.begin(), S.end(), [](const string& u, const string& v){
        int u_len = u.length();
        int v_len = v.length();
        if (u_len != v_len) return u_len < v_len;
        return u < v;
    });
    // S-vector에서 중복된 값 지우기
    S.erase(unique(S.begin(), S.end()), S.end());
    // print
    for (string &s : S) cout << s << '\n';
    return 0;
}
