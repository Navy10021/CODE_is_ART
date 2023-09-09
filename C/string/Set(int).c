#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Function to check if an integer is already in the set
bool contains(const int set[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) {
            return true;
        }
    }
    return false;
}

// Function to add an integer to the set if it's not already present
bool addToSet(int set[], int *size, int value) {
    if (*size < MAX_SIZE && !contains(set, *size, value)) {
        set[*size] = value;
        (*size)++;
        return true; // Added successfully
    }
    return false; // Element not added (either set is full or element already exists)
}

int main() {
    int integerSet[MAX_SIZE];
    int setSize = 0;

    // Example usage of addToSet function
    addToSet(integerSet, &setSize, 1);
    addToSet(integerSet, &setSize, 2);
    addToSet(integerSet, &setSize, 1);
    addToSet(integerSet, &setSize, 2);
    
    // Printing the elements in the set
    printf("Elements in the set:\n");
    for (int i = 0; i < setSize; i++) {
        printf("%d\n", integerSet[i]);
    }

    return 0;
}
