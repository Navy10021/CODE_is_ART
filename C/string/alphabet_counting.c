#include <stdio.h>
#include <ctype.h> // for isalpha


void countAlphaberts(const char *string, int letterCounts[]){
    // 알파벳 배열 초기화(소문자)
    for (int i = 0; i < 26; i++){
        letterCounts[i] = 0;
    }

    // 입력 string
    for (int i = 0; string[i] != '\0'; i++){
        char c = tolower(string[i]);    // 소문자 변경
        if (isalpha(c)){
            int idx = c - 'a';          // 인덱스 계산
            letterCounts[idx]++;        // 관련된 문자 카운팅
        }
    }
}

int main(){
    const char* intput = "Hello, World! I am Lee.";
    int letter_table[26];
    countAlphaberts(intput, letter_table);

    for (int i=0; i<26; i++){
        char letter = 'a' + i;
        printf("%c : %d\n", letter, letter_table[i]);
    }
    return 0;
}
