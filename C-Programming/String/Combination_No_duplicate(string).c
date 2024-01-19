#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int seen(char ** arr, int arr_idx, char * target){
    for(int i=0; i<arr_idx; i++){
        if(strcmp(arr[i], target)==0){
            return 1;
        }
    }
    return 0;
}

void backtrack(char *str, char *buffer, int start, int depth, int combination_size, char**store, int*store_idx) {
    int len = strlen(str);
    if (depth == 0) { // 해당 조합의 길이(depth)와 일치하면 return
        buffer[combination_size] = '\0';
        // Check is already in store
        if(!seen(store, *store_idx, buffer)){
            store[*store_idx] = strdup(buffer);
            (*store_idx)++;
            return;
        }
    }
    for (int i = start; i < len; i++) {
        buffer[depth - 1] = str[i]; // 해당 문자열의 Char를 array(buffer)에 저장
        backtrack(str, buffer, i + 1, depth - 1, combination_size, store, store_idx);
    }
}

void letterCombination(char *str){
    int length = strlen(str);
    // store all combination results
    int combinations_size = 1 << length;
    char**combinations = (char**)malloc(sizeof(combinations_size) * sizeof(char*));
    int combinations_idx = 0;
    
    for (int depth = 1; depth <= length; depth++){
        char*combination = (char*)malloc((depth + 1) * sizeof(char));
        backtrack(str, combination, 0, depth, depth, combinations, &combinations_idx);
    }
    // using stored arr 
    for(int i = 0; i < combinations_idx; i++){
        printf("%s\n", combinations[i]);
        free(combinations[i]);
    }
    free(combinations);
}

int main(void) {
    char inputStr[] = "aab";
    letterCombination(inputStr);
    
    return 0;
}
