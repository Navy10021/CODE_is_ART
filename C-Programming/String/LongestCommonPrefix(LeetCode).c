#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the longest common prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    // Check for empty input array
    if (strsSize == 0) {
        char* emptyString = malloc(1);
        emptyString[0] = '\0';
        return emptyString;
    }

    // Initialize the common prefix with the first string
    char* prefix = strdup(strs[0]);

    // Iterate through the array of strings
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Compare characters until the end of the current prefix or the end of the current string
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        // Shorten the common prefix to the matched characters
        prefix[j] = '\0';
    }

    return prefix;
}

int main(void) {
    char* strings[] = {"flower", "flow", "flight"};
    int size = sizeof(strings) / sizeof(strings[0]);

    char* result = longestCommonPrefix(strings, size);

    printf("Longest Common Prefix: %s\n", result);

    // Remember to free allocated memory
    free(result);

    return 0;
}