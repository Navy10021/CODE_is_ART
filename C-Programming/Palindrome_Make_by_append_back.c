#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimum character to be added at back to make palindrome.

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

void Erase(char* str, int position){
    int length = strlen(str);

    if (position < 0 || position >= length){
        printf("Invalid.\n");
        return;
    }

    for (int i = position; i < length - 1; i++){
        str[i] = str[i + 1];
    }

    str[length - 1] = '\0';
}

void InsertFront(char *str, char target) {
    int len = strlen(str);

    // str -> str + 1에 (len + 1) 메모리 만큼 복사
    memmove(str + 1, str, len + 1); // Use memmove to handle overlapping regions
    str[0] = target;
}

void InsertPostion(char *str, char target, int position){
    int len = strlen(str);

    if (position < 0 || position > len){
        printf("Invalid.\n");
        return;
    }
    memmove(str + position + 1, str + position, len - position + 1);
    str[position] = target;
}

// 팰린드롬이 될때까지 앞문자를 지우고, Back 문자열에 Insert(0)
void makePalindrome(char str[]){
    int count = 0;
    int flag = 0;
    char original_str[100];
    char add_str[100];
    add_str[0] = '\0';

    strcpy(original_str, str);

    while(strlen(str) > 0){
        if (isPalindrome(str)){
            flag = 1;
            break;
        }
        else{
            InsertFront(add_str, str[0]); // string의 첫문자를 추가
            Erase(str, 0);                // string의 첫문자를 삭제
            count++;
        }
    }
    if (flag){
        strcat(original_str, add_str);
        printf("%s ||", original_str);
        printf("Number of adding chars : %d\n", count);
    }
    else{
        printf("Can't make palindrome.\n");
    }

}

int main(void){
    char input[] = "NAVY";
    makePalindrome(input);
}
