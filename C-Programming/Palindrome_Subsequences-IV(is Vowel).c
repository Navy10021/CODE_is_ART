#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Palindrome Partition == subsequnces

int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

int isVowel(char ch){
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void partition(char* str, int l, int r, char* path, int path_idx, char** arr, int * arr_idx){
    if (l == r){
        path[path_idx] = '\0';
        if (isPalindrome(path) && !seen(arr, *arr_idx, path)){
            //printf("%s\n", path);
            strcpy(arr[(*arr_idx)++], path);
        }
        return;
    }
    if (isVowel(str[l])){
        path[path_idx] = str[l];
        // include current char str[l]
        partition(str, l + 1, r, path, path_idx + 1, arr, arr_idx);
    }
    // Exclude current char
    partition(str, l + 1, r, path, path_idx, arr, arr_idx);
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    
    int arr_size = 1 << length;
    int arr_idx = 0;
    char **arr = (char **)malloc(arr_size * sizeof(char *));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = (char *)malloc((length + 1) * sizeof(char));
    }
    
    partition(str, 0, length, path, 0, arr, &arr_idx);
    
    for (int i = 0; i < arr_idx; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]); // Free memory for each string
    }
    free(path);
    free(arr);
}

int main(void){
    char input[100];
    scanf("%s", input);
    subsequnces(input);
    
    return 0;
}

