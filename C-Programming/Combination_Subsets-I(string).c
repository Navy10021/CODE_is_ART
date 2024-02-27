#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Subsets : Input: "Arr"  / Output: [  ] [ A ] [ Ar ] [ Arr ] [ r ] [ rr ] 

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    int count[256] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return 0; // Different lengths, not anagrams
    }

    for (int i = 0; i < len1; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0; // Character frequencies don't match, not anagrams
        }
    }

    return 1; // Strings are anagrams
}

// Function to check if a subset is already generated
int isAnagramSubsetGenerated(char **subsets, int subsetCount, char *curr_combination) {
    for (int i = 0; i < subsetCount; i++) {
        if (areAnagrams(subsets[i], curr_combination)) {
            return 1; // Anagram subset is already generated
        }
    }
    return 0; // Anagram subset is not generated yet
}

void genAnagramSubsets(char *arr, int arrSize, char *curr_combination, int index, char **subsets, int *subsetCount) {
    // Check for duplicates in anagram subsets
    if (!isAnagramSubsetGenerated(subsets, *subsetCount, curr_combination)) {
        // Print the non-duplicated anagram subset
        printf("[ %s ] ", curr_combination);

        // Add the current anagram subset to the list of generated subsets
        subsets[*subsetCount] = malloc((strlen(curr_combination) + 1) * sizeof(char));
        strcpy(subsets[*subsetCount], curr_combination);
        (*subsetCount)++;
    }

    for (int i = 0; i < arrSize; i++) {
        // Include the current character
        curr_combination[index] = arr[i];
        curr_combination[index + 1] = '\0'; // Null-terminate the string

        // Recursively generate anagram subsets
        genAnagramSubsets(arr + i + 1, arrSize - i - 1, curr_combination, index + 1, subsets, subsetCount);

        // Exclude the current character to backtrack
        curr_combination[index] = '\0';
    }
}

void anagramSubsets(char *arr) {
    // Generate all anagram subsets
    int arrSize = strlen(arr);
    char **allAnagramSubsets = (char **)malloc(arrSize * arrSize * sizeof(char *));
    int subsetCount = 0;

    char *curr_combination = (char *)malloc((arrSize + 1) * sizeof(char));
    curr_combination[0] = '\0'; // Start with an empty string

    genAnagramSubsets(arr, arrSize, curr_combination, 0, allAnagramSubsets, &subsetCount);

    // Free allocated memory for anagram subsets
    for (int i = 0; i < subsetCount; i++) {
        free(allAnagramSubsets[i]);
    }
    free(allAnagramSubsets);
    free(curr_combination);
}

int main(void){
    char input[] = "ABCD";
    anagramSubsets(input);

    return 0;
}
