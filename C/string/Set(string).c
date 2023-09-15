#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Include the string.h header for string operations

#define MAX_SIZE 10

// Function to check if a string is already in the set
bool contains(const char *set[], int size, const char *value) {
    for (int i = 0; i < size; i++) {
        if (strcmp(set[i], value) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a string to the set if it's not already present
bool insert(const char *set[], int *size, const char *value) {
    if (*size < MAX_SIZE && !contains(set, *size, value)) {
        set[*size] = value;
        (*size)++;
        return true; // Added successfully
    }
    return false; // Element not added (either set is full or element already exists)
}

// Function to erase a string from the set if it exists
bool erase(const char *set[], int *size, const char *value) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(set[i], value) == 0) {
            // Shift elements to the left to remove the element at index i
            for (int j = i; j < *size - 1; j++) {
                set[j] = set[j + 1];
            }
            (*size)--;
            return true; // Erased successfully
        }
    }
    return false; // Element not found or not erased
}

int main() {
    const char *stringSet[MAX_SIZE];
    int setSize = 0;

    // Example usage of insert function
    insert(stringSet, &setSize, "apple");
    insert(stringSet, &setSize, "banana");
    insert(stringSet, &setSize, "cherry");
    insert(stringSet, &setSize, "date");
    insert(stringSet, &setSize, "grape");
    insert(stringSet, &setSize, "fig");
    insert(stringSet, &setSize, "apple");
    
    // Printing the elements in the set
    printf("Elements in the set: ");
    for (int i = 0; i < setSize; i++) {
        printf("%s ", stringSet[i]);
    }

    // Erase a string from the set (e.g., erase "banana")
    const char *elementToErase = "banana";
    bool erased = erase(stringSet, &setSize, elementToErase);
    if (erased) {
        printf("\nErased \"%s\" from the set.\n", elementToErase);
    } else {
        printf("\n\"%s\" not found or not erased from the set.\n", elementToErase);
    }

    return 0;
}
