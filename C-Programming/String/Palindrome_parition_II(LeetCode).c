#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 132. Palindrome Partitioning II : return minimum cuts for a palindrome patitions of str

int isPalindrome(char *str, int st, int en) {
    while (st < en) {
        if (str[st] != str[en]) {
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

void backtrack(char *str, int start, char **curr_partition, int curr_size, int max_size, int* minCut) {
    if (start == strlen(str)) {
        // Check if all substrings in the current partition are palindromes.
        for (int i = 0; i < curr_size; i++) {
            if (!isPalindrome(curr_partition[i], 0, strlen(curr_partition[i]) - 1)) {
                return;  // No need for the flag, just return if any substring is not a palindrome.
            }
        }
        // minimum cutting update
        if (curr_size - 1 < *minCut){
            *minCut = curr_size - 1;
        }
        return;
    }
    for (int end = start + 1; end < strlen(str) + 1; end++) {
        // Add substring to current partition
        //strncpy(curr_partition[curr_size], &str[start], end - start);
        strncpy(curr_partition[curr_size], str + start, end - start);
        curr_partition[curr_size][end - start] = '\0';

        // Continue with the next substring
        backtrack(str, end, curr_partition, curr_size + 1, max_size, minCut);
    }
}

void get_partitioned_substr(char *str) {
    int max_size = strlen(str);
    int minCut = max_size;

    // Allocate memory for current partition
    char *curr_partition[max_size];
    for (int i = 0; i < max_size; i++) {
        curr_partition[i] = (char *)malloc((max_size + 1) * sizeof(char));
    }

    // Start the backtracking
    backtrack(str, 0, curr_partition, 0, max_size, &minCut);
    printf("Minimum cuts : %d", minCut);
    // Free allocated memory
    for (int i = 0; i < max_size; i++) {
        free(curr_partition[i]);
    }
}

int main(void) {
    char input[100];
    scanf("%s", input);
    get_partitioned_substr(input);

    return 0;
}
