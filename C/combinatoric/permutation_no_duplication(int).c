#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int containsDuplicate(int arr[], int left, int right, int key) {
    for (int i = left; i <= right; i++) {
        if (arr[i] == key) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

void permute(int arr[], int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = left; i <= right; i++) {
            if (!containsDuplicate(arr, left, i - 1, arr[i])) {
                swap(&arr[left], &arr[i]);
                permute(arr, left + 1, right);
                swap(&arr[left], &arr[i]); // Backtrack
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Permutations of the array with duplicates:\n");
    permute(arr, 0, n - 1);

    return 0;
}
