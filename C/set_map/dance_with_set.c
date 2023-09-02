#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a set (implemented as an array of strings)
struct Set {
    char** elements;
    int size;
};

// Function to initialize a set
void initializeSet(struct Set* set) {
    set->elements = NULL;
    set->size = 0;
}

// Function to check if an element exists in the set
int existsInSet(const struct Set* set, const char* element) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->elements[i], element) == 0) {
            return 1; // Element found in the set
        }
    }
    return 0; // Element not found in the set
}

// Function to insert an element into the set
void insertIntoSet(struct Set* set, const char* element) {
    if (!existsInSet(set, element)) {
        // Allocate memory for the new element
        char* newElement = strdup(element);
        
        // Increase the size of the set
        set->size++;
        
        // Reallocate memory for the set elements
        set->elements = realloc(set->elements, sizeof(char*) * set->size);
        
        // Add the new element to the set
        set->elements[set->size - 1] = newElement;
    }
}

// Function to free the memory used by the set
void freeSet(struct Set* set) {
    for (int i = 0; i < set->size; i++) {
        free(set->elements[i]);
    }
    free(set->elements);
    set->size = 0;
}

int main() {
    struct Set arr;
    initializeSet(&arr);
    
    insertIntoSet(&arr, "Dance");
    
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char str1[100], str2[100];
        scanf("%s %s", str1, str2);
        
        if (existsInSet(&arr, str1) || existsInSet(&arr, str2)) {
            insertIntoSet(&arr, str1);
            insertIntoSet(&arr, str2);
        }
    }
    
    printf("%d\n", arr.size - 1); // Excluding "Dance"
    
    for (int i = 0; i < arr.size; i++) {
        printf("%s ", arr.elements[i]);
    }
    
    // Free the memory used by the set
    freeSet(&arr);
    
    return 0;
}
