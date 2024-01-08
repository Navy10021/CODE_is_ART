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

int isIn(char ** strings, int currIdx, const char * val){
    for (int i = 0; i < currIdx; i++){
        if (strcmp(strings[i], val) == 0)
            return 1;
    }
    return 0;
}

int SubstrIsWraparound(char * str){
    char **store = NULL;
    int storeIdx = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            int subLen = j - i + 1;
            char *substr = (char*)malloc((subLen+1) * sizeof(char));
            strncpy(substr, str+i, subLen);
            substr[subLen] = '\0';      // NULL-terminate!!!
            if (isWraparound(substr) && !isIn(store, storeIdx, substr)){
                store = (char**)realloc(store, (storeIdx + 1) * sizeof(char*));
                store[storeIdx++] = strdup(substr);
            }
            free(substr);
        }
    }
    printf("Total Substring in Wraparound string : %d\n", storeIdx);

    for (int i = 0; i < storeIdx; i++){
        printf("%s, ", store[i]);
    }

    for (int i = 0; i < storeIdx; i++){
        free(store[i]);
    }
    free(store);
    
    return storeIdx;
}

int main(void){
    char input[100];
    scanf("%s", input);
    SubstrIsWraparound(input);
    return 0;
}
