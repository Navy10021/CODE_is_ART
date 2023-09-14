#include <stdio.h>

// Function to rotate an array to the right by 'd' positions
void rightRotate(int arr[], int n, int d) {
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[n - d + i];
    }

    for (int i = n - 1; i >= d; i--) {
        arr[i] = arr[i - d];
    }

    for (int i = 0; i < d; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // Number of positions to rotate right
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rightRotate(arr, n, d);

    printf("\nArray after right rotation by %d positions: ", d);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
