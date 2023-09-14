#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find the maximum value in the array
    int max_num = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_num)
            max_num = arr[i];
    }

    // Create a hash table
    int hash[max_num + 1];
    for (int i = 0; i <= max_num; i++) {
        hash[i] = 0;
    }

    // Populate the hash table
    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;
    }

    // Find the maximum frequency
    int max_freq = 0;
    for (int i = 0; i <= max_num; i++) {
        if (hash[i] > max_freq) {
            max_freq = hash[i];
        }
    }

    // Print the mode(s)
    printf("The mode(s) is/are: ");
    for (int i = 0; i <= max_num; i++) {
        if (hash[i] == max_freq) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
