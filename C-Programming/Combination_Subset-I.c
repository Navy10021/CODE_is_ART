#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 78. Subsets : return all possible subsets
// [1,2,3] -> [[],[1],[2],[3],[1,2],[1,3], [2,3],[1,2,3]]

void genCombinations(int *arr, int arrSize, int k, int * curr_combination, int index){
    if (index == k){
        printf("[ ");
        for (int i = 0; i < k; i++){
            printf("%d ", curr_combination[i]);
        }
        printf("] ");
        return;
    }
    for (int i = 0; i < arrSize; i++){
        curr_combination[index] = arr[i];
        genCombinations(arr + i + 1, arrSize - i - 1, k, curr_combination, index + 1);
    }
}

void subsets(int *arr, int arrSize){
    // Generate All combinations
    for (int k = 0; k < arrSize + 1; k++){
        int *curr_combination = (int*)malloc(k * sizeof(int));
        genCombinations(arr, arrSize, k, curr_combination, 0);
        free(curr_combination);
    }
}

int main(void){
    int input[3] = {1,2,3};
    int inputSize = sizeof(input) / sizeof(input[0]);

    subsets(input, inputSize);

    return 0;
}
