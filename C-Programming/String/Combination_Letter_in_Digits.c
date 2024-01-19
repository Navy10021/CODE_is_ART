#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LeetCode 17. Letter Combinations of Phone Number

// 1. mapping of digits to letter 
char * digit_mapping[] = {
  "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"  
};

// 2. BackTracking (Combinations)
void backtrack(char *digits, int index, char *curr_combination, char **res, int *res_cnt){
    if (index == strlen(digits)){
        // store Combination results
        res[*res_cnt] = strdup(curr_combination);
        (*res_cnt)++;
        return;
    }
    
    char curr_digit = digits[index] - '0';
    char *letters = digit_mapping[curr_digit];
    
    for (int i=0; i<strlen(letters); i++){
        // add current digit letter
        curr_combination[index] = letters[i];
        // add new digit_letters
        backtrack(digits, index+1, curr_combination, res, res_cnt);
    }
}

// 3. letters Combination using backtrack
char ** letter_combi(char* digits, int* returnSize){
    if(digits == NULL || strlen(digits)==0){
        *returnSize = 0;
        return NULL;
    }
    
    // memory allocation
    int total_combi = 1;
    for(int i=0; i<strlen(digits); i++){
        total_combi *= strlen(digit_mapping[digits[i]-'0']);
    }
    char **res = (char**)malloc(total_combi * sizeof(char*));
    int res_cnt = 0;
    char *curr_combination = (char*)malloc((strlen(digits)+1) * sizeof(char));
    curr_combination[strlen(digits)] = '\0';
    
    // backtrack 
    backtrack(digits, 0, curr_combination, res, &res_cnt);
    
    free(curr_combination);
    *returnSize = res_cnt;
    
    return res;
}

int main(void){
    char digits[] = "23";
    int returnSize;
    
    char ** res = letter_combi(digits, &returnSize);
    
    printf("[");
    for (int i=0; i<returnSize; i++){
        printf("%s, ", res[i]);
        free(res[i]);
    }
    printf("]\n");
}