// N개의 문자, 길이가 M인 수열 + 중복된 수열을 여러번 출력하면 안됨 + 사전순 정렬렬
#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[10];
bool is_used[10];
char str[10];

void func(int k){
    if (k == M){
        for(int i=0; i< M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    int tmp = 0;    // 중복된 수열을 체크하는 임시변수 
    
    for (int i = 0; i < N; i++){
        if (!is_used[i] && tmp != str[i]){  // 사용한 적이 없는 알파벳 + 이전수열의 알파벳과 현재 수열의 알파벳이 다르면 
            is_used[i] = 1;
            arr[k] = str[i];
            tmp = arr[k];
            func(k+1);
            is_used[i] = 0;
        }
    }
}

int main(void){
    string s = "BCAA";
    for(int i=0; i<s.size(); i++) str[i] = s[i]; 
    M = 3;              // N Combination M
    N = strlen(str);
    sort(str, str+N);   // dictionary Sorting
    func(0);
    return 0;
}
