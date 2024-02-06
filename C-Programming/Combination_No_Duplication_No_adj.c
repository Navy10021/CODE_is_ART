#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// is palindrome
int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

// Check if given string has adj chars
int is_adj(const char *str, int len) {
    for (int i = 1; i < len; i++) {
        if (abs(str[i] - str[i - 1]) == 1) {
            return 1;
        }
    }
    return 0;
}

// Combination generation without repetition and no adjacent characters, adjusted for duplicates
void generateCombinations(const char set[], int set_size, int k, char *current, int current_index, int start) {
    if (current_index == k) {
        if (!is_adj(current, k)) {
            printf("%s\n", current);
        }
        return;
    }

    for (int i = start; i < set_size; i++) {
        // Skip duplicates
        if (i > start && set[i] == set[i - 1]) continue;

        current[current_index] = set[i];
        generateCombinations(set, set_size, k, current, current_index + 1, i + 1); // Move to next element to ensure no duplication
    }
}

void combinations(char set[], int set_size, int k) {
    // Sort the set to ensure duplicates are adjacent
    qsort(set, set_size, sizeof(char), compare);

    char *current = (char *)malloc((k + 1) * sizeof(char));
    current[k] = '\0'; // Null-terminate the string

    generateCombinations(set, set_size, k, current, 0, 0);

    free(current); // Free allocated memory
}

int main() {
    char set[] = "ABAB";
    int n = strlen(set);
    
    for (int k = 1; k <= n; k++) {
        printf("Combinations of length %d:\n", k);
        combinations(set, n, k);
    }
    
    return 0;
}