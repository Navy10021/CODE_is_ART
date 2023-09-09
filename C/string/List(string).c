#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_STRING_LENGTH 100

void appendStringToList(char** list, int* numStrings, const char* newString) {
    if (*numStrings < MAX_STRINGS) {
        // Allocate memory for the new string
        list[*numStrings] = malloc(strlen(newString) + 1);
        if (list[*numStrings] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // Copy the new string to the list
        strcpy(list[*numStrings], newString);

        (*numStrings)++; // Increment the count of strings in the list
        //printf("String added to the list.\n");
    } else {
        printf("The list is full.\n");
    }
}

int main() {
    char* stringList[MAX_STRINGS];
    int numStrings = 0;

    // Example usage of the appendStringToList function
    appendStringToList(stringList, &numStrings, "Hello");
    appendStringToList(stringList, &numStrings, "World");

    // Printing the list of strings
    printf("List of strings:\n");
    for (int i = 0; i < numStrings; i++) {
        printf("%s\n", stringList[i]);
    }

    // Free memory for the strings
    for (int i = 0; i < numStrings; i++) {
        free(stringList[i]);
    }

    return 0;
}
