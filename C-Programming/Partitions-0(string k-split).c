#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Improved Generate String Partitions.
void genPartitions(char *str, int start, int n, int k, int curr_partitions, char arr[][n+1], int arr_idx) {
    // Base Condition: if start index has covered the string and current partition count matches k
    if (start >= n) {
        if (curr_partitions == k) {
            for (int i = 0; i < arr_idx; i++) {
                printf("'%s'", arr[i]);
                if (i < arr_idx - 1) printf(", "); // Improved readability for output
            }
            printf("\n");
        }
        return;
    }

    for (int end = start; end < n; end++) {
        // Creating substring for current partition
        int len = end - start + 1;
        strncpy(arr[arr_idx], str + start, len);
        arr[arr_idx][len] = '\0'; // Ensuring null-termination

        // Recursive call for the next part of the string
        genPartitions(str, end + 1, n, k, curr_partitions + 1, arr, arr_idx + 1);
    }
}

void partitions(char *str) {
    int len = strlen(str);
    char arr[len][len + 1]; // Allocating array based on string length

    for (int k = 1; k <= len; k++) { // Iterating over all possible numbers of partitions
        printf("%d-partition \n", k);
        genPartitions(str, 0, len, k, 0, arr, 0);
    }
}

int main(void) {
    char str[100] = "abcd";
    partitions(str);
    return 0;
}
