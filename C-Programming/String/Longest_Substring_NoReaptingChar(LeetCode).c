#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LeetCode 3: Longest Substring Without Repeatng Char

int isReapting(char* str){
    int len = strlen(str);
    for(int i=1; i<len; i++){
        for(int j=0; j<i; j++){
            if(str[i]==str[j]){
                return 1;
            }
        }
    }
    return 0;
}

int isReapting2(char* str){
    int charSet[256] = {0};
    while(*str != '\0'){
        if (charSet[*str] > 0){
            return 1;
        }
        charSet[*str]++;
        str++;
    }
    return 0;
}

int LongestSubstr(char* str) {
    // generate substring and check repeatng characters.
    int maxLen = 0;
    char* longestsubstr = NULL;
    int length = strlen(str);
    // generate substring 
    for (int i = 0; i < length; i++){
        for (int j = i; j < length; j++){
            int sublen = j - i + 1;
            char* substr = (char*)malloc((sublen+1) * sizeof(char));
            strncpy(substr, str + i, sublen);
            substr[sublen] = '\0';
            if(!isReapting(substr) && sublen > maxLen){
                maxLen = sublen;
                longestsubstr = strdup(substr);
            }
            free(substr);
        }
    }
    printf("Longest Substring : %s \n", longestsubstr);
    free(longestsubstr);
    return maxLen;
}

int main(void) {
    char input[100];
    scanf("%s", input);
    int res = LongestSubstr(input);
    printf("%d", res);
    
    return 0;
}