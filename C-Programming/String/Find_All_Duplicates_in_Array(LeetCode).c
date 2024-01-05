#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int *arr, int numSize, int *resArr, int *resIdx) {
    // Max number == numSize + 1 to accommodate 0-based indexing
    int hash[numSize + 1];
    
    for (int i = 0; i <= numSize; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < numSize; i++) {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= numSize; i++) {
        if (hash[i] > 1) {
            resArr[(*resIdx)++] = i;
        }
    }
}

int main(void) {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int res[100];
    int resIdx = 0;

    findDuplicates(arr, arrSize, res, &resIdx);

    for (int i = 0; i < resIdx; i++) {
        printf("%d, ", res[i]);
    }

    return 0;
}