// 중복 없이 L개 중 C개의 암호 만들기 + 1개의 모음 && 2개의 자음 + 오름차순
#include <bits/stdc++.h>
using namespace std;

int L, C;
const int MX = 17;
int arr[MX];
char s[MX];
bool is_used[MX];

// 모음 구분 함수
bool is_aeiou(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void func(int k, int st){ // 현재 k번째 
    if (k == L){
        bool flag = false;  // 모음 1개 이상 && 자음 2개 이상 여부 확인
        int cnt_1 = 0;      // 모음 개수
        int cnt_2 = 0;      // 자음 개수 
        for (int i=0; i<L; i++){
            if (is_aeiou(s[arr[i]])) cnt_1 ++;
            else cnt_2 ++;
        }
        if (cnt_1 >= 1 && cnt_2 >= 2) flag = true;
        
        // 조건을 만족하면 출력
        if (flag){
            for (int i=0; i<L; i++)
                cout << s[arr[i]];
            cout << '\n';
        }
    }
    for (int i = st; i < C; i++){
        arr[k] = i;
        func(k+1, i+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for (int i=0; i<C; i++) cin >> s[i];
    sort(s, s+C);        // 사전순, 오름차순
    func(0, 0);
}
