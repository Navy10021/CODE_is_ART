// ~by YS
#include <stdio.h>
#include <string.h>

void lexicographically_smallest_palindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
       // str[st]와 str[en]를 비교해서 사전순으로 앞선 알파벳으로 변경
       if (str[st] < str[en]){
        str[en] = str[st];
       }
       else{
        str[st] = str[en];
       }
       st++;
       en--;
    }
}

int main(void){
    char input[1000];
    scanf("%s", input);

    printf("Original string : %s\n", input);

    lexicographically_smallest_palindrome(input);

    printf("After modified string : %s\n", input);
}