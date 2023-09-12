#include <stdio.h>

int binarySearchCustom(int arr[], int left, int right, int target, int (*compare)(int, int)) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        if (compare(arr[mid], target) == 0) {
            return mid; // Target found, return its index
        } else if (compare(arr[mid], target) < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found in the array
}

// Custom comparison function to find a specific value
int customCompare(int a, int b) {
    if (a == b) {
        return 0; // Equal
    } else if (a < b) {
        return -1; // Less than
    } else {
        return 1; // Greater than
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearchCustom(arr, 0, size - 1, target, customCompare);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
