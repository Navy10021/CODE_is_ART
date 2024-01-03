#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 300. Longest Increasing Subsequence
/*
return length of the longest strictly increasing subsequnce
*/

int isIncrease(int *arr, int arrSize){
    for (int i = 1; i < arrSize; i++){
        if (arr[i-1] >= arr[i])
            return 0;
    }
    return 1;
}


void genSubseq(int *arr, int index, int *subseq, int arrSize, int subseqSize, int* maxLen, int* resArr){
    if (index == arrSize){
        if (isIncrease(subseq, subseqSize) && (*maxLen) < subseqSize){
            *maxLen = subseqSize;
            memcpy(resArr, subseq, subseqSize*sizeof(int)); // Copy the max length arr
        }
        return;
    }
    // Exclude
    genSubseq(arr, index + 1, subseq, arrSize, subseqSize, maxLen, resArr);
    // Include
    subseq[subseqSize] = arr[index];
    genSubseq(arr, index + 1, subseq, arrSize, subseqSize + 1, maxLen, resArr);
    // BackTrack to exclude the current element
    subseqSize--;
}


int lengthOfLIS(int *nums, int numsSize, int *resArr){
    int maxLen = 0;
    int *subseq = (int *)malloc(numsSize * sizeof(int));
    genSubseq(nums, 0, subseq, numsSize, 0, &maxLen, resArr);
    free(subseq);
    
    return maxLen;
}


int main(void){

    int numSize;
    scanf("%d", &numSize);
    int* nums = (int *)malloc(numSize * sizeof(int));
    int num;
    for (int i = 0; i < numSize; i++){
        scanf("%d", &num);
        nums[i] = num;
    }

    int* resArr = (int *)malloc(numSize * sizeof(int));  // Array for LIS;
    int res = lengthOfLIS(nums, numSize, resArr);
    printf("Max length : %d\n", res);
    printf("LIS : ");
    for (int i = 0; i < res; i++){
        printf("%d ", resArr[i]);
    }
    free(nums);
    free(resArr);
    
    
    return 0;
}