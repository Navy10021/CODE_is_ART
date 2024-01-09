#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 491. Non-Decreasing Subseqences : Return all different possible non-decreasing subsequnces
// [4, 6, 7, 7] -> [4, 6], [4,6,7], [4,6,7,7], [4,7], [4,7,7], [6,7], [6,7,7], [7,7]
// [4,4,3,2,1] -> [[4,4]]

int isNonDecreasing(int *arr, int arrSize){
    for (int i = 1; i < arrSize; i++){
        if (arr[i-1] > arr[i])
            return 0;
    }
    return 1;
}

void printArr(int *arr, int arrSize){
    printf(" [ ");
    for (int i = 0; i < arrSize; i++){
        if (arr[i] != 0)
            printf("%d, ", arr[i]);
    }
    printf("] ");
}

void genSubseq(int *arr, int index, int *subseq, int arrSize, int subseqSize, int **res, int *resSize){
    if (index == arrSize){
        if (isNonDecreasing(subseq, subseqSize) && subseqSize > 1){
            //printArr(subseq, subseqSize);
            res[*resSize] = (int*)malloc(subseqSize * sizeof(int));
            memcpy(res[*resSize], subseq, subseqSize * sizeof(int));
            (*resSize)++;
        }
        return;
    }
    // Exclude
    genSubseq(arr, index + 1, subseq, arrSize, subseqSize, res, resSize);
    // Include
    subseq[subseqSize] = arr[index];
    genSubseq(arr, index + 1, subseq, arrSize, subseqSize + 1, res, resSize);
    // BackTrack
    subseqSize--;
}

void findSubseq(int *nums, int numSize){
    int ** result = NULL;
    int resultSize = 0;
    int maxCount = 1 << numSize;
    result = (int**)malloc(maxCount * sizeof(int *));
    
    int *subseq = (int *)malloc(numSize * sizeof(int));
    genSubseq(nums, 0, subseq, numSize, 0, result, &resultSize);
    free(subseq);
    
    for (int i = 0; i < resultSize; i++){
        printArr(result[i], numSize);
        free(result[i]);
    }
    free(result);
}

int main(void){
    int input [4] = {4,6,7,7};
    int inputSize = sizeof(input) / sizeof(input[0]);

    findSubseq(input, inputSize);
    
    return 0;
}