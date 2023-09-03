#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printPermutations(int arr[], int n, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        swap(&arr[index], &arr[i]);
        printPermutations(arr, n, index + 1);
        swap(&arr[index], &arr[i]); // Backtrack to the original order
    }
}

int main() {
    int N = 5; // Change N to the desired range (1 to N)

    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1; // Filling the array with integers from 1 to N
    }

    printf("Permutations of integers from 1 to %d (no duplicates):\n", N);
    printPermutations(arr, N, 0);

    return 0;
}
