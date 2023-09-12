#include <stdio.h>

int findPeakElement(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            right = mid; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    }

    return left; // Peak element index
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, size);

    printf("Peak element is %d at index %d\n", arr[peakIndex], peakIndex);

    return 0;
}
