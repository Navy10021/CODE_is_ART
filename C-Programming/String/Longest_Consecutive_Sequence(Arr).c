#include <stdio.h>
#include <stdlib.h>

// LeetCode 128: Longest Consecutive Sequence. Runs in O(N).

int longestConsecutiveSeq(int *arr, int arrsize) {
    // Find max
    int maxnum = 0;
    for (int i = 0; i < arrsize; i++) {
        if (arr[i] > maxnum) {
            maxnum = arr[i];
        }
    }

    // Make hash & initialization
    int *hash = (int *)malloc((maxnum + 1) * sizeof(int));
    for (int i = 0; i <= maxnum; i++) {
        hash[i] = 0;
    }

    // Fill in hash
    for (int i = 0; i < arrsize; i++) {
        hash[arr[i]] = 1;
    }

    int longseq = 0;
    // Find consecutive elements
    for (int i = 0; i <= maxnum; i++) {
        if (hash[i] == 1) {
            int st = i;
            int length = 0;
            while (hash[st] == 1) {
                st++;
                length++;
            }
            if (length > longseq) {
                longseq = length;
            }
        }
    }

    printf("Longest Consecutive Sequence: %d\n", longseq);

    // Free dynamically allocated memory
    free(hash);

    return longseq;
}

int main(void) {
    int arr[10] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int res = longestConsecutiveSeq(arr, arrSize);

    return 0;
}