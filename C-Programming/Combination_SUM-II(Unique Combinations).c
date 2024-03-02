#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Combination-II : Find all 'Unique Combinations' in candidates
int compare(const void *a, const void *b){
    return (*(char*)a - *(char*)b);  // using void* pointer : (int*)로 결정 / a pointer's value b pointer's value 비교 
}

int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

void backtrack(int* set, int target, int l, int r, char* path, int path_idx, char** arr, int* arr_idx){
    if (l == r){
        path[path_idx] = '\0';
        int sum = 0;
        for (int i = 0; path[i] != '\0'; i++){
            sum += path[i] - '0';
        }
        if (sum == target){
            qsort(path, strlen(path), sizeof(char), compare);  // sorting!!!
            if (!seen(arr, *arr_idx, path)){
                strcpy(arr[(*arr_idx)++], path);
            }
        }
        return;
    }
    
    path[path_idx] = set[l] + '0';  // int -> char로 변형
    backtrack(set, target, l + 1, r, path, path_idx + 1, arr, arr_idx);
    backtrack(set, target, l + 1, r, path, path_idx, arr, arr_idx);
}

void combinationSum(int* set, int setSize, int target){
    char * path = (char*)malloc((setSize + 1) * sizeof(char));

    int arr_size = 1 << setSize;
    int arr_idx = 0;
    char** arr = (char**)malloc(arr_size * sizeof(char *));
    for (int i = 0; i < arr_size; i++){
        arr[i] = (char*)malloc((setSize + 1) * sizeof(char));
    }
    backtrack(set, target, 0, setSize, path, 0, arr, &arr_idx);

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
    //int candidates[] = {10,1,2,7,6,1,5};
    //int tgt = 8;
    int candidates[] = {2,5,2,1,2};
    int tgt = 5;
    int candidates_size = sizeof(candidates) / sizeof(candidates[0]);
    combinationSum(candidates, candidates_size, tgt);

    return 0;
}
