#include <stdio.h>
#include <math.h>

int binarySearchFloat(double arr[], int size, double target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        if (fabs(arr[mid] - target) < 1e-9) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found in the array
}

int main() {
    double arr[] = {1.0, 2.5, 3.8, 5.2, 6.7, 9.0};
    int size = sizeof(arr) / sizeof(arr[0]);
    double target = 3.8;

    int result = binarySearchFloat(arr, size, target);

    if (result != -1) {
        printf("Element %lf found at index %d\n", target, result);
    } else {
        printf("Element %lf not found in the array\n", target);
    }

    return 0;
}
