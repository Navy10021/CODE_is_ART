#include <stdio.h>

int main() {
    int size = 5;   // size of array
    int arr[size];

    // insert elements
    printf("Enter %d elements\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // initialize max and min 
    int max = arr[0];
    int min = arr[0];

    // Find max and min elements
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];  // Use '=' instead of '<'
        }
    }

    printf("Max element: %d\n", max);
    printf("Min element: %d\n", min);

    return 0;
}
