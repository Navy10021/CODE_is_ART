#include <stdio.h>
#include <stdlib.h>

// Define a structure for a set (implemented as an array of integers)
struct Set {
    int* elements;    // int elements[size];
    int size;
};

// Function to initialize a set
void initializeSet(struct Set* set) {
    set->elements = NULL;
    set->size = 0;
}

// Function to check if an element exists in the set
int existsInSet(const struct Set* set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1; // Element found in the set
        }
    }
    return 0; // Element not found in the set
}

// Function to insert an element into the set
void insertIntoSet(struct Set* set, int element) {
    if (!existsInSet(set, element)) {
        // Increase the size of the set
        set->size++;
        
        // Reallocate memory for the set elements. realloc(Pointer, Size);
        set->elements = realloc(set->elements, sizeof(int) * set->size);
        
        // Add the new element(array) to the set
        set->elements[set->size - 1] = element;
    }
}

// Function to free the memory used by the set
void freeSet(struct Set* set) {
    free(set->elements);
    set->size = 0;
}

int main() {
    struct Set arr;
    initializeSet(&arr);
    
    insertIntoSet(&arr, 42); // Example: Inserting integer element 42
    
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        
        if (existsInSet(&arr, num1) || existsInSet(&arr, num2)) {
            insertIntoSet(&arr, num1);
            insertIntoSet(&arr, num2);
        }
    }
    
    printf("%d\n", arr.size - 1); // Excluding the initial element
    
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.elements[i]);
    }
    
    // Free the memory used by the set
    freeSet(&arr);
    
    return 0;
}
