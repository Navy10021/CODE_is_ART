#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_STRING_LENGTH 100

// Function to check if a string is already in the set
bool contains(const char* set[], int size, const char* value) {
    for (int i = 0; i < size; i++) {
        if (strcmp(set[i], value) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a string to the set if it's not already present
bool addToSet(char* set[], int* size, const char* value) {
    if (*size < MAX_SIZE && !contains(set, *size, value)) {
        set[*size] = strdup(value);
        if (set[*size] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        (*size)++;
        return true; // Added successfully
    }
    return false; // Element not added (either set is full or element already exists)
}

int main() {
    char* stringSet[MAX_SIZE];
    int setSize = 0;
    char *strList[] = {"apple", "banana", "Data", "Data", "banana"};
    // Example usage of addToSet function
    int List_size = sizeof(strList) / sizeof(strList[0]);
    for (int i=0; i<List_size; i++){
        addToSet(stringSet, &setSize, strList[i]);
    }

    // Printing the elements in the set
    printf("Elements in the set:\n");
    for (int i = 0; i < setSize; i++) {
        printf("%s\n", stringSet[i]);
    }

    // Free memory for the strings
    for (int i = 0; i < setSize; i++) {
        free(stringSet[i]);
    }

    return 0;
}
