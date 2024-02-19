#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_adj(const char *str, int len) {
    for (int i = 1; i < len; i++) {
        if (abs(str[i] - str[i - 1]) == 1) {
            return 1;
        }
    }
    return 0;
}

int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

void partition(char* str, int l, int r, char* path, int path_idx, char** arr, int * arr_idx){
    if (l == r){
        path[path_idx] = '\0';
        // odd length
        if (!is_adj(path, path_idx) && !seen(arr, *arr_idx, path)){
            strcpy(arr[(*arr_idx)++], path);
        }
        return;
    }
    path[path_idx] = str[l];
    // include current char str[l]
    partition(str, l + 1, r, path, path_idx + 1, arr, arr_idx);
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
