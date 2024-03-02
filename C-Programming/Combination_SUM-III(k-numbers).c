#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Combination-III : Find all Valid Combinations of 'k' numbers sum up
// 1 ~ 9 까지 숫자중에 한번만! 선택 
int compare(const void *a, const void *b){
    return (*(char*)a - *(char*)b);  
}

int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

void backtrack(int* set, int target, int l, int r, char* path, int path_idx, int k, char** arr, int* arr_idx){
    if (l == r){
        path[path_idx] = '\0';
        int sum = 0;
        for (int i = 0; path[i] != '\0'; i++){
            sum += path[i] - '0';
        }
        if (sum == target && strlen(path) == k){
            qsort(path, strlen(path), sizeof(char), compare);  // sorting!!!
            if (!seen(arr, *arr_idx, path)){
                strcpy(arr[(*arr_idx)++], path);
            }
        }
        return;
    }
    
    path[path_idx] = set[l] + '0';  // int -> char로 변형
    backtrack(set, target, l + 1, r, path, path_idx + 1, k, arr, arr_idx);
    backtrack(set, target, l + 1, r, path, path_idx, k, arr, arr_idx);
}

void combinationSum(int* set, int setSize, int target, int k){
    char * path = (char*)malloc((setSize + 1) * sizeof(char));

    int arr_size = 1 << setSize;
    int arr_idx = 0;
    char** arr = (char**)malloc(arr_size * sizeof(char *));
    for (int i = 0; i < arr_size; i++){
        arr[i] = (char*)malloc((setSize + 1) * sizeof(char));
    }
    backtrack(set, target, 0, setSize, path, 0, k, arr, &arr_idx);

    for (int i = 0; i < arr_idx; i++){
        //printf("%s\n", arr[i]);
        printf("[");
        for (int j = 0; arr[i][j] != '\0'; j++){
            printf("%c, ", arr[i][j]);
        }
        printf("]\n");
        free(arr[i]);
    }
    free(path);
    free(arr);

}

int main(void){
    // 1 ~ 9까지 숫자
    int candidates[] = {1,2,3,4,5,6,7,8,9};
    int k = 3;    // 선택할 개수
    int tgt = 9;  // 선택한 수의 합
    int candidates_size = sizeof(candidates) / sizeof(candidates[0]);
    combinationSum(candidates, candidates_size, tgt, k);

    return 0;
}
