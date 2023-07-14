// N크기의 string과 자연수 M이 주어졌을 때 길이가 M인 character 수열 + 오름차순으로 증가
// ABCD 중 3개 -> ABC, ABD, BCD  
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool is_used[10];
int N, M;
char str[10];

void func(int k, int st){        // 현재 k개의 알파벳 선택, start 인덱스
    if (k == M){                 // M개의 알파벳을 선택했으면, arr에 대응되는 string 출력
        for(int i=0; i < M; i++)
            cout << str[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    // else (k != M)
    //int st = 0;
    //if (k != 0) st = arr[k-1] + 1;
    
    for (int i = st; i < N; i++){
        if(!is_used[i]){
            arr[k] = i;         // 해당 인덱스를 저장 
            is_used[i] = 1;     // use true 
            func(k+1, i);      // backtracking
            is_used[i] = 0;     // use false 
        }
    }
}

int main(void){
    string s = "DBCA";
    for(int i=0; i<s.size(); i++) str[i] = s[i]; 
    M = 3;              // N Combination M
    N = strlen(str);
    sort(str, str+N);   // Sorting
    func(0, 0);         // k, start index
    return 0;
    
}
