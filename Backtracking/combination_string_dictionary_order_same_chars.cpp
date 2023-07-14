// N개의 문자, 길이가 M인 수열 + 사전순으로 증가 + 같은 문자 여러번 가능 
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
char num[10];

void func(int k, int st){
    if (k == M){
        for(int i=0; i< M; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = st; i < N; i++){
        arr[k] = i;
        func(k+1, i);
    }
}

int main(void){
    string s = "DBCA";
    for(int i=0; i<s.size(); i++) num[i] = s[i]; 
    M = 3;              // N Combination M
    N = strlen(num);
    sort(num, num+N);   // Sorting
    func(0, 0);         // 2개의 파라미터를 받음 -> k, start index
    return 0;
}
