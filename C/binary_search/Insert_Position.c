#include <stdio.h>

int searchInsert(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return left; // Position to insert target
}

int main() {
    int arr[] = {1, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int insertPosition = searchInsert(arr, size, target);

    printf("Insert %d at index %d\n", target, insertPosition);

    return 0;
}
