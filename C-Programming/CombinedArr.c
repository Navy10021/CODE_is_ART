#include <stdio.h>

int main() {
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};

    // Calculate the size of the combined array
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int combinedSize = size1 + size2;

    // Create a new array to store the combined elements
    int combinedArray[combinedSize];

    // Copy elements from array1 to combinedArray
    for (int i = 0; i < size1; i++) {
        combinedArray[i] = array1[i];
    }

    // Copy elements from array2 to combinedArray
    for (int i = 0; i < size2; i++) {
        combinedArray[size1 + i] = array2[i];
    }

    // Print the combined array
    printf("Combined Array: ");
    for (int i = 0; i < combinedSize; i++) {
        printf("%d ", combinedArray[i]);
    }

    return 0;
}
