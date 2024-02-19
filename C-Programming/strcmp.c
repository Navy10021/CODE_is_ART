#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char* str1 = "abc";
    char* str2 = "cba";
    char* str3 = "abcd";
    char* str4 = "azaz";
    char* str5 = "cd";
    char* str6 = "ce";
    char* str7 = "abc";
    
    // true : 앞에서 부터 알파벳 ASCII를 비교하면 작으면 음수, 같으면 0, 크면 양수 반환.
    int res;
    res = strcmp(str1, str2) < 0;
    printf("%d", res);
    res = strcmp(str2, str5) < 0;
    printf("%d", res);
    res = strcmp(str3, str4) < 0;
    printf("%d", res);
    res = strcmp(str5, str6) < 0;
    printf("%d", res);
    res = strcmp(str1, str7) == 0;
    printf("%d", res);

}
