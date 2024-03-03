#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// set 원소를 중복사용 가능하게 조합만들기
void backtrack(int* set, int target, int l, int r, char* path, int path_idx, int k, char** arr, int* arr_idx){
    if (path_idx == k){
        path[path_idx] = '\0';
        int sum = 0;
        for (int i = 0; path[i] != '\0'; i++){
            sum += path[i] - '0';
        }
        if (sum == target){
            strcpy(arr[(*arr_idx)++], path);
        }
        return;
    }
    
    for (int i = 0; i < r; i++){
        path[path_idx] = set[i] + '0';
        backtrack(set, target, l, r, path, path_idx + 1, k, arr, arr_idx);
    }
}

void combinationSum(int* set, int setSize, int k, int target){
    char * path = (char*)malloc((k + 1) * sizeof(char));

    int arr_size = 1 << target;
    int arr_idx = 0;
    char** arr = (char**)malloc(arr_size * sizeof(char*));
    for (int i = 0; i < arr_size; i++){
        arr[i] = (char*)malloc((k + 1) * sizeof(char));
    }
    backtrack(set, target, 0, setSize, path, 0, k, arr, &arr_idx);

    if (arr_idx == 0){
        printf("0\n");
    }
    else {
        for (int i = 0; i < arr_idx; i++){
            printf("[");
            for (int j = 0; arr[i][j] != '\0'; j++){
                printf("%c, ", arr[i][j]);
            }
            printf("]\n");
            free(arr[i]);
        }
    }
    free(arr);
    free(path);
}

int main()
{
    int candidates[] = {1,2,3};
    int candidates_size = sizeof(candidates) / sizeof(candidates[0]);
    int target = 4;
    
    for (int k = 1; k <= target; k++){ // 1로 만들 수 있는 최대 길이 target
        combinationSum(candidates, candidates_size, k, target);
    }
    return 0;
}
