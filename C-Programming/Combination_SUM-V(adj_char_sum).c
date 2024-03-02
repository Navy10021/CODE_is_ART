#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 인접한 알파벳간의 거리합
int adj_sum(char* str){
    int sum = 0;
    for (int i = 1; i < strlen(str); i++){
        sum += abs(str[i] - str[i-1]);
    }
    return sum;
}

void bactrack(char* str, int k, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        
        int str_sum = adj_sum(path);
        if (str_sum == k){
            printf("%s\n", path);
        }
        return;
    }
    path[path_idx] = str[l];
    bactrack(str, k, l + 1, r, path, path_idx + 1);
    bactrack(str, k, l + 1, r, path, path_idx);
}

void combinationSum(char* str, int k){
    int len = strlen(str);
    char* path = (char*)malloc((len + 1) * sizeof(char));
    bactrack(str, k, 0, len, path, 0);
}

int main(void){
    char input[100] = "carracer";
    int k = 2;
    combinationSum(input, k);

    return 0;
}
