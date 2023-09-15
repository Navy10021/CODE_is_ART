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
bool insert(int set[], int *size, int value) {
    if (*size < MAX_SIZE && !contains(set, *size, value)) {
        set[*size] = value;
        (*size)++;
        return true; // Added successfully
    }
    return false; // Element not added (either set is full or element already exists)
}

// function to erase an int
bool erase(int set[], int *size, int value) {
    for (int i = 0; i < *size; i++) {
        if (set[i] == value) {
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
    int integerSet[MAX_SIZE];
    int setSize = 0;

    // Example usage of addToSet function
    insert(integerSet, &setSize, 3);
    insert(integerSet, &setSize, 1);
    insert(integerSet, &setSize, 2);
    insert(integerSet, &setSize, 1);
    insert(integerSet, &setSize, 2);
    
    // Printing the elements in the set
    printf("Elements in the set : ");
    for (int i = 0; i < setSize; i++) {
        printf("%d ", integerSet[i]);
    }

    erase(integerSet, &setSize, 2);
    printf("\nElements in the set : ");
    for (int i = 0; i < setSize; i++) {
        printf("%d ", integerSet[i]);
    }

    return 0;
}
