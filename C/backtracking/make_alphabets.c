#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 
주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.
*/
int L, C;
#define MX 17
int arr[MX];
char s[MX];
bool is_used[MX];

// 모음 구분 함수
bool is_aeiou(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void func(int k, int st) { // 현재 k번째 
    if (k == L) {
        bool flag = false;  // 모음 1개 이상 && 자음 2개 이상 여부 확인
        int cnt_1 = 0;      // 모음 개수
        int cnt_2 = 0;      // 자음 개수 
        for (int i = 0; i < L; i++) {
            if (is_aeiou(s[arr[i]])) cnt_1++;
            else cnt_2++;
        }
        if (cnt_1 >= 1 && cnt_2 >= 2) flag = true;

        // 조건을 만족하면 출력
        if (flag) {
            for (int i = 0; i < L; i++)
                printf("%c", s[arr[i]]);
            printf("\n");
        }
    }
    for (int i = st; i < C; i++) {
        arr[k] = i;
        func(k + 1, i + 1);
    }
}

int main(void) {
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) scanf(" %c", &s[i]);
    qsort(s, C, sizeof(char), strcmp); // 사전순, 오름차순
    func(0, 0);
    return 0;
}
