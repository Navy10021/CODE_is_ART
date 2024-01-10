#include<stdio.h>
#include<stdlib.h>

// 77. combinations
// Given two n and k, return all possible combinations k numbers from 1 ~ n.

void genCombinations(int *arr, int arrSize, int k, int * curr_combination, int index){
    if (index == k){
        for (int i = 0; i < k; i++){
            printf("%d ", curr_combination[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < arrSize; i++){
        curr_combination[index] = arr[i];
        genCombinations(arr+i+1, arrSize-i-1, k, curr_combination, index+1);
    }
}

void combinations(int n, int k){
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        arr[i] = i+1;
    }
    int *curr_combination = (int*)malloc(k * sizeof(int));
    genCombinations(arr, n, k, curr_combination, 0);

    free(arr);
    free(curr_combination);
    
}

int main(void){
    int n = 4;
    int k = 2;
    combinations(n, k);
    
    return 0;
}