#include <stdio.h>
#include <stdlib.h>

int smallest_pos_int(int array[], int n) {
    int j = 0;

    // Move all non-positive numbers to the left
    for (int i = 0; i < n; i++) {
        if (array[i] <= 0) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
    }

    // Consider only the positive part of the array
    int m = n - j;
    int *positive_subarray = array + j;

    // Mark the elements using their index
    for (int i = 0; i < m; i++) {
        int num = abs(positive_subarray[i]);
        if (num <= m && positive_subarray[num - 1] > 0) {
            positive_subarray[num - 1] = -positive_subarray[num - 1];
        }
    }

    // Find the first positive number in the modified array
    for (int i = 0; i < m; i++) {
        if (positive_subarray[i] > 0) {
            return i + 1;
        }
    }

    return m + 1;
}

int main() {
    int array1[] = {4, 7, -1, 1, 2};
    int array2[] = {100, 101, 102};
    int array3[] = {3, 2, 1, 0, -1};

    printf("%d\n", smallest_pos_int(array1, 5)); // Output: 3
    printf("%d\n", smallest_pos_int(array2, 3)); // Output: 1
    printf("%d\n", smallest_pos_int(array3, 5)); // Output: 4

    return 0;
}
