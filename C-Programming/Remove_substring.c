#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove a substring from a string and return the removed substring
char* removeSubstring(char *str, const char *sub) {
    char *match = strstr(str, sub); // Find the first occurrence of the substring

    if (match != NULL) {
        // Calculate the length of the removed substring
        size_t subLen = strlen(sub);

        // Create a buffer to store the removed substring
        char *removed = malloc(subLen + 1);
        if (removed == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // Copy the removed substring to the buffer
        strncpy(removed, match, subLen);
        removed[subLen] = '\0'; // Null-terminate the buffer

        // Remove the substring from the original string
        memmove(match, match + subLen, strlen(match + subLen) + 1);

        return removed;
    }

    return NULL; // Substring not found
}

int main() {
    char inputString[] = "Hello World!";
    const char substring[] = "World";

    // Call the function to remove the substring
    char *removedSubstring = removeSubstring(inputString, substring);

    if (removedSubstring != NULL) {
        printf("Removed Substring: %s\n", removedSubstring);

        // Print the modified string
        printf("Modified String: %s\n", inputString);

        // Don't forget to free the allocated memory for the removed substring
        free(removedSubstring);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
