#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if two arrays are equal
int areArraysEqual(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

// Function to check if a subset is already generated
int isSubsetGenerated(int **subsets, int subsetCount, int *curr_combination, int k) {
    for (int i = 0; i < subsetCount; i++) {
        if (areArraysEqual(subsets[i], curr_combination, k)) {
            return 1; // Subset is already generated
        }
    }
    return 0; // Subset is not generated yet
}

void genCombinations(int *arr, int arrSize, int k, int *curr_combination, int index, int **subsets, int *subsetCount) {
    if (index == k) {
        // Check for duplicates in subsets
        if (!isSubsetGenerated(subsets, *subsetCount, curr_combination, k)) {
            // Print the non-duplicated subset
            printf("[ ");
            for (int i = 0; i < k; i++) {
                printf("%d ", curr_combination[i]);
            }
            printf("] ");
            
            // Add the current subset to the list of generated subsets
            subsets[*subsetCount] = malloc(k * sizeof(int));
            memcpy(subsets[*subsetCount], curr_combination, k * sizeof(int));
            (*subsetCount)++;
        }
        return;
    }

    for (int i = 0; i < arrSize; i++) {
        curr_combination[index] = arr[i];
        genCombinations(arr + i + 1, arrSize - i - 1, k, curr_combination, index + 1, subsets, subsetCount);
    }
}

void subsets(int *arr, int arrSize) {
    // Generate all combinations
    int **allSubsets = (int **)malloc(arrSize * arrSize * sizeof(int *));
    int subsetCount = 0;

    for (int k = 0; k < arrSize + 1; k++) {
        int *curr_combination = (int *)malloc(k * sizeof(int));
        genCombinations(arr, arrSize, k, curr_combination, 0, allSubsets, &subsetCount);
        free(curr_combination);
    }

    // Free allocated memory for subsets
    for (int i = 0; i < subsetCount; i++) {
        free(allSubsets[i]);
    }
    free(allSubsets);
}

int main(void) {
    int input[3] = {1, 2, 3};
    int inputSize = sizeof(input) / sizeof(input[0]);

    subsets(input, inputSize);

    return 0;
}