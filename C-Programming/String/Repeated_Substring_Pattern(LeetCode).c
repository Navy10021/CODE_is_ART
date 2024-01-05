#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeSubstr(char *str, char *sub){
    int len = strlen(sub);
    while((str = strstr(str, sub))){
        memmove(str, str + len, strlen(str+len) + 1);
    }
}

int repeatedSubstr(char * str){
    int flag = 0;
    char *resStr = NULL;
    int len = strlen(str);
    // each substring
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            int subLen = j - i + 1;
            char *substr = (char *)malloc((subLen+1)*sizeof(char));
            strncpy(substr, str + i, subLen);
            substr[subLen] = '\0';

            // Erase substring
            char * newstr = strdup(str);
            removeSubstr(newstr, substr);
            if (strlen(newstr) == 0 && subLen != len){
                //printf("%s\n", substr);
                // Update results
                free(resStr);
                resStr = strdup(substr);
                flag = 1;
            }
            free(substr);
            free(newstr);
        }
    }
    int numRepeated = len / strlen(resStr);
    printf("%s pattern is repeated %d times in string\n", resStr, numRepeated);
    return flag;
}

int main(void) {
    char input[100];
    scanf("%s", input);
    int res = repeatedSubstr(input);
    if (!res){
        printf("False\n");
    }
    else
        printf("True\n");        
    return 0;
}