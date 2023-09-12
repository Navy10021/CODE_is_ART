#include <stdio.h>

int findFirstOccurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Store the index but continue searching in the left half
            right = mid - 1; // Search in the left half
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return result;
}

int findLastOccurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Store the index but continue searching in the right half
            left = mid + 1; // Search in the right half
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int firstOccurrence = findFirstOccurrence(arr, size, target);
    int lastOccurrence = findLastOccurrence(arr, size, target);

    if (firstOccurrence != -1 && lastOccurrence != -1) {
        printf("First occurrence of %d is at index %d\n", target, firstOccurrence);
        printf("Last occurrence of %d is at index %d\n", target, lastOccurrence);
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}
