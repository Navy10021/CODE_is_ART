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

void TwoSubsequences(char *str, char* str2){
    // Word1
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    
    int arr_size = 1 << length;
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;
    
    // Word2
    int length2 = strlen(str2);
    char * path2 = (char*)malloc((length2 + 1) * sizeof(char));
    
    int arr_size2 = 1 << length2;
    char** arr2 = malloc(arr_size2 * sizeof(char*));
    int arr_idx2 = 0;
    
    
    parition(arr, &arr_idx, str, 0, length, path, 0);
    parition(arr2, &arr_idx2, str2, 0, length2, path2, 0);
    
    // Find common max length 
    int max_len = 0;
    char* max_str = strdup("");
    for (int i = 0; i < arr_idx; i++){
        for (int j = 0; j < arr_idx2; j++){
            if (strcmp(arr[i], arr2[j]) == 0){
                if (max_len < strlen(arr[i]) || max_len == strlen(arr[i]) && strcmp(arr[i], max_str) < 0){
                    max_len = strlen(arr[i]);
                    free(max_str);
                    max_str = strdup(arr[i]);
                }
            }
        }
    }
    printf("Maximum Common Subsequnce : %s (%d)\n", max_str, max_len);
    
    // Clean up
    for (int i = 0; i < arr_idx; i++){
        free(arr[i]);
    }
    for (int i = 0; i < arr_idx2; i++){
        free(arr2[i]);
    }
    free(path);
    free(path2);
    free(arr);
    free(arr2);
}

int main(void){
    char word1[100];
    char word2[100];
    scanf("%s %s", word1, word2);
    TwoSubsequences(word1, word2);
    return 0;
}