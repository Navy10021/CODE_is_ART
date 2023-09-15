#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort() to sort in ascending order
int compareAscending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Sort the array using qsort()
    qsort(arr, n, sizeof(int), compareAscending);

    printf("\nSorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
