#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1071. Greatest Common Divior of Strings : return the largest string x that x divided both str1 and str2



// 문자열에서 특정 substr을 삭제하는 함수
int can_remove_sub(char* str, const char * substr){
    char * match = strstr(str, substr); // Find substr;
    while (match != NULL){
        memmove(match, match + strlen(substr), strlen(match + strlen(substr)) + 1);
        match = strstr(str,substr);     // search next matching
    }
    return (strlen(str) == 0);
}

void GCD(char * string1, char * string2){
    // More shorter Substring 중에서 str1과 str2를 모두 지울 수 있는 string 구하기
    // 1. str1 or str2 substring : 어떤것을 기준으로 하든 상관없음.
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    int minLen = len2;
    char * res = NULL; 

    for (int i = 0; i < len2; i++){
        for (int j = i; j < len2; j++){
            int subLen = j - i + 1;
            char* substr = (char*)malloc(sizeof(char) * (subLen));
            strncpy(substr, string2 + i, subLen);
            substr[subLen] = '\0';

            char* str1 = strdup(string1);
            char* str2 = strdup(string2);
            if(can_remove_sub(str1, substr) && can_remove_sub(str2, substr) && strlen(substr) < minLen){
                //printf("%s\n", substr);
                minLen = strlen(substr);
                res = strdup(substr);
            }

            free(substr);
            free(str1);
            free(str2);
        }
    }
    printf("GCD of string : %s\n", res);
    free(res);
}

int main(void){

    char str1[] = "ABABABAB";
    char str2[] = "ABAB";
    GCD(str1, str2);

    return 0;
}
