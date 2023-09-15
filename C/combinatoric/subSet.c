#include <stdio.h>

// Function to print subsets of an array
void Subsets(int arr[], int n, int subset[], int subsetSize, int index) {
    if (index == n) {
        // Base case: Print the current subset
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}, ");
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = arr[index];
    Subsets(arr, n, subset, subsetSize + 1, index + 1);

    // Exclude the current element from the subset and move to the next element
    Subsets(arr, n, subset, subsetSize, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4};   // sorted array
    int n = sizeof(arr) / sizeof(arr[0]);

    int subset[n]; // This array will hold subsets

    printf("All subsets of the array:\n");
    Subsets(arr, n, subset, 0, 0);

    return 0;
}
