#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimum characters to be added at Front to make Palindrome.

int isPalindrome(char str[]) {
    int st = 0;
    int en = strlen(str) - 1;
    while (st < en) {
        if (str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}

// 팰린드롬이 될때까지 뒷 문자를 지우고, Front 문자열에 포함
void makePalindrome(char str[]){
    int count = 0;
    int flag = 0;   // Check is palindrome or not
    char original_str[100];
    char add_str[100];
    int addIdx = 0;
    strcpy(original_str, str);

    while(strlen(str) > 0){
        if (isPalindrome(str)){
            flag = 1;
            break;
        }
        else{
            add_str[addIdx++] = str[strlen(str) - 1];  // 마지막 문자를 추가하고, 문자열에서 삭제
            str[strlen(str) - 1] = '\0';
            count ++;
        }
    }
    if (flag){
        strcat(add_str, original_str);
        printf("%s || ", add_str);
        printf("Number of adding chars : %d\n", count);
    }
    else{
        printf("Can't make palindrome.\n");
    }
}

int main(void){
    char input[100];
    scanf("%s", input);
    makePalindrome(input);
}