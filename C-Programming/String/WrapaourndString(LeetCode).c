#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 467. Unique Substrings in Wraparound String
// Wraparound string : "... wxyzabcd ..."


int isWraparound(char * str){

    for(int i = 1; i < strlen(str); i++){
        if((str[i] - str[i-1]) != 1 && (str[i] - str[i-1]) != -25)
            return 0;
        }   
    return 1;
}

int SubstrIsWraparound(char * str){
    char **store = (char **)malloc(sizeof(char *) * 1000);
    int storeIdx = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            int subLen = j - i + 1;
            char *substr = (char*)malloc((subLen+1) * sizeof(char));
            strncpy(substr, str+i, subLen);
            if (isWraparound(substr)){
                int flag = 0;
                for (int i = 0; i <= storeIdx; i++){
                    if (strcmp(store[i], substr)==0){
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    store[storeIdx++] = substr;
            }
            free(substr);
        }
    }
    printf("Total Substring in Wraparound string : %d\n", storeIdx);
    return storeIdx;
}

int main(void){
    char input[100];
    scanf("%s", input);
    SubstrIsWraparound(input);
    return 0;
}