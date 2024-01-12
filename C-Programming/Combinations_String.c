#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if two strings are equal
int areStringsEqual(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

// Function to check if a subset is already generated
int isSubsetGenerated(char **subsets, int subsetCount, char *curr_combination, int k) {
    for (int i = 0; i < subsetCount; i++) {
        if (areStringsEqual(subsets[i], curr_combination)) {
            return 1; // Subset is already generated
        }
    }
    return 0; // Subset is not generated yet
}

void genStringCombinations(char *arr, int arrSize, int k, char *curr_combination, int index, char **subsets, int *subsetCount) {
    if (index == k) {
        // Check for duplicates in subsets
        if (!isSubsetGenerated(subsets, *subsetCount, curr_combination, k)) {
            // Print the non-duplicated subset
            printf("[ %s ] ", curr_combination);

            // Add the current subset to the list of generated subsets
            subsets[*subsetCount] = malloc((strlen(curr_combination) + 1) * sizeof(char));
            strcpy(subsets[*subsetCount], curr_combination);
            (*subsetCount)++;
        }
        return;
    }

    for (int i = 0; i < arrSize; i++) {
        curr_combination[index] = arr[i];
        genStringCombinations(arr + i + 1, arrSize - i - 1, k, curr_combination, index + 1, subsets, subsetCount);
    }
}

void stringSubsets(char *arr) {
    // Generate all combinations
    int arrSize = strlen(arr);
    char **allSubsets = (char **)malloc(arrSize * arrSize * sizeof(char *));
    int subsetCount = 0;

    for (int k = 0; k < arrSize + 1; k++) {
        char *curr_combination = (char *)malloc((k + 1) * sizeof(char));
        curr_combination[k] = '\0'; // Null-terminate the string
        genStringCombinations(arr, arrSize, k, curr_combination, 0, allSubsets, &subsetCount);
        free(curr_combination);
    }

    // Free allocated memory for subsets
    for (int i = 0; i < subsetCount; i++) {
        free(allSubsets[i]);
    }
    free(allSubsets);
}

int main(void) {
    char input[] = "abc";
    stringSubsets(input);

    return 0;
}