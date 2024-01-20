#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValid(char *s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } 
        
        else if (isalpha(s[i]) || isalnum(s[i])){
            continue;
        }
        
        else {
            if (top == -1) {
                return 0;  // No matching open bracket
            }

            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{')) {
                return 0;  // Mismatched closing bracket
            }
            top--;
        }
    }
    return (top == -1);  // Check if all open brackets are closed
}

void swap(char * a, char * b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shoudSwap(char * str, int start, int end){
    for (int i = start; i < end; i++){
        if (str[i] == str[end]){
            return 0;   // Character are the same. No swap.
        }
    }
    return 1;    // Character are different. Swap.
}

void genPermutation(char* str, int str_idx, int str_len, char** res, int* res_idx){
    if (str_idx == str_len - 1){
        // Check valid pharentheses!
        if (isValid(str)){
            char * element = strdup(str);
            res[*res_idx] = element;
            (*res_idx)++;
            return;
        }
    }
    
    for (int i = str_idx; i < str_len; i++){
        if (shoudSwap(str, str_idx, i)){
            swap(&str[str_idx], &str[i]);
            genPermutation(str, str_idx + 1, str_len, res, res_idx);
            swap(&str[str_idx], &str[i]);
        }
    }
}

void permutation(char* str){
    int length = strlen(str);
    int size_permutations = 1;
    for (int i=1; i<=length; i++){
        size_permutations *= i;
    }

    // allocate memory
    char **permutations = (char**)malloc(size_permutations * sizeof(char *));
    int perm_index = 0;

    genPermutation(str, 0, length, permutations, &perm_index);

    // Use the stored permutations
    for (int i = 0; i < perm_index; i++){
        printf("%s\n", permutations[i]);
    }

    // Free allocated memory
    for (int i = 0; i < perm_index; i++){
        free(permutations[i]);
    }
    free(permutations);
}

int main(void) {
    char input[100];
    scanf("%s", input);
    printf("----------------\n");
    permutation(input);

    return 0;
}
