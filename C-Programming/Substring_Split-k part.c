#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Split K-parts

void splitStringIntoKParts(const char* str, int k) {
    int len = strlen(str);
    int baseLength = len / k;
    int remainder = len % k;
    char** substrings = malloc(k * sizeof(char*));
    int currentPosition = 0;

    for (int i = 0; i < k; i++) {
        // Calculate length of this substring
        int thisSubstringLength = baseLength + (i < remainder ? 1 : 0);
        substrings[i] = malloc((thisSubstringLength + 1) * sizeof(char)); // +1 for null terminator

        // Copy the substring
        strncpy(substrings[i], str + currentPosition, thisSubstringLength);
        substrings[i][thisSubstringLength] = '\0'; // Null-terminate the substring

        // Print the substring (for demonstration)
        printf("Substring %d: %s\n", i+1, substrings[i]);

        currentPosition += thisSubstringLength;
    }

    // Cleanup
    for (int i = 0; i < k; i++) {
        free(substrings[i]);
    }
    free(substrings);
}

int main() {
    const char* str = "abcdef";
    int len = strlen(str);
    // Ensure k starts from 1 to avoid division by zero
    // and doesn't exceed the length of the string
    for (int k = 1; k <= len; k++){
        printf("Splitting into %d parts:\n", k);
        splitStringIntoKParts(str, k);
        printf("\n"); // Add a newline for better readability between tests
    }
    return 0;
}