#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a substring is a palindrome.
int isPalindrome(const char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Recursive function to find palindromic partitions.
// Added an extra parameter to keep track of the partitions
void findPalindromicPartitions(int * min_partition, const char *str, int start, int n, int k, int currentPartitions, char partitionedResult[][n+1], int depth) {
    // Base condition: If we've reached the end of the string
    if (start >= n) {
        // If the current partition count matches k, we've found a valid partitioning.
        if (currentPartitions == k && k < (*min_partition)) {
            * min_partition = k; 
            printf("Minimum cuts need to palindromic partitions : %d\n", k-1);
            for (int i = 0; i < depth; i++) {
                printf("'%s'", partitionedResult[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int end = start; end < n; end++) {
        if (isPalindrome(str, start, end)) {
            // Copy the current palindromic substring into the partitionedResult array.
            int len = end - start + 1;
            strncpy(partitionedResult[depth], str + start, len);
            partitionedResult[depth][len] = '\0'; // Null-terminate the string.

            // Recurse for the remaining string with the current partition added.
            findPalindromicPartitions(min_partition, str, end + 1, n, k, currentPartitions + 1, partitionedResult, depth + 1);
        }
    }
}

int main() {
    const char *str = "abcbm";
    int len = strlen(str);
    char arr[len][len+1]; // Assuming maximum `len` partitions.
    int min_partition = len;

    for (int k = 1; k <= len; k++) {
        findPalindromicPartitions(&min_partition, str, 0, len, k, 0, arr, 0);
    }
    
    // print possible Partitioned Palindrome
    return 0;
}