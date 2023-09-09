#include <stdio.h>

void rotateArray(int arr[], int length, int positions) {
    positions %= length; // Adjust positions to handle overflows

    int temp[positions];

    // Store the last 'positions' elements in temp
    for (int i = length - positions, j = 0; i < length; i++, j++) {
        temp[j] = arr[i];
    }

    // Shift the remaining elements to the right
    for (int i = length - positions - 1; i >= 0; i--) {
        arr[i + positions] = arr[i];
    }

    // Copy back the elements from temp to the beginning of the array
    for (int i = 0; i < positions; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int input[] = {3, 9, 2, 8, 5};
    int length = sizeof(input) / sizeof(input[0]);
    int positions = 2;

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    rotateArray(input, length, positions);

    printf("Array after rotating %d positions to the right: ", positions);
    for (int i = 0; i < length; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}
