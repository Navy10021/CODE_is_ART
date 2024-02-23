#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Delete Operation for Two strings(word1 & word2).
// Given Two strings, return the minimum number of STEPS to make word1 == word2

// Find The Longest Common Subsequnce, given Two strings.

void parition(char** arr, int* arr_idx, char* str, int l, int r, char* path, int path_idx){
    if (l == r) {
        path[path_idx] = '\0';
        //printf("%s\n", path);
        arr[*arr_idx] = strdup(path);
        (*arr_idx)++;
        return;
    }
    
    // Include 
    path[path_idx] = str[l];
    parition(arr, arr_idx, str, l + 1, r, path, path_idx + 1);
    // Exclude
    parition(arr, arr_idx, str, l + 1, r, path, path_idx);
}

void subsequences(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    
    int arr_size = 1 << length;
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;
    
    parition(arr, &arr_idx, str, 0, length, path, 0);
    
    for (int i = 0; i < arr_idx; i++){
        printf("%s, ", arr[i]);
    }
    
    // Clean up
    for (int i = 0; i < arr_idx; i++){
        free(arr[i]);
    }
    free(path);
    free(arr);
}

int main(void){
    char input[100];
    scanf("%s", input);
    subsequences(input);
    return 0;
}