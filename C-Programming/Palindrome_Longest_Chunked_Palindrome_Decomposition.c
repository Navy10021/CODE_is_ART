#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1147. Longest Chunked Palindrome Decomposition
// Function to check if a substring is a palindrome.
int isPartitionPalindrome(int n, char arr[][n+1], int depth) {
    int start = 0;
    int end = depth-1;
    while (start < end) {
        if (strcmp(arr[start], arr[end]) != 0) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Recursive function to find palindromic partitions.
// Added an extra parameter to keep track of the partitions
void partitions(int *max_num,const char *str, int start, int n, int k, int currentPartitions, char partitionedResult[][n+1], int depth) {
    // Base condition: If we've reached the end of the string
    if (start >= n) {
        // If the current partition count matches k, we've found a valid partitioning.
        if (currentPartitions == k && isPartitionPalindrome(n, partitionedResult, depth) && k > (*max_num)) {
            *max_num = k;
            for (int i = 0; i < depth; i++) {
                printf("'%s'", partitionedResult[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int end = start; end < n; end++) {
        
        // Copy the current substring into the partitionedResult array.
        int len = end - start + 1;
        strncpy(partitionedResult[depth], str + start, len);
        partitionedResult[depth][len] = '\0'; // Null-terminate the string.

        // Recurse for the remaining string with the current partition added.
        partitions(max_num, str, end + 1, n, k, currentPartitions + 1, partitionedResult, depth + 1);
    }
}

int max_partitions(const char* str){
    
    int len = strlen(str);
    int arr_size = len; 
    char arr[arr_size][len + 1];
    int max_num = 0;

    for (int k = 1; k <= len; k++){
        partitions(&max_num, str, 0, len, k, 0, arr, 0);
    }
    return max_num;
}


int main() {
    const char *str = "antaprezatepzapreanta";
    int length = strlen(str);
    int res = max_partitions(str);
    printf("Longest Chunked Pakindrome Decomposition : %d\n", res);
    return 0;
}