#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char str[]) {
    int st = 0;
    int en = strlen(str) - 1;
    while (st < en) {
        if (str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(char *str, int start, int end) {
    for (int i = start; i < end; i++) {
        if (str[i] == str[end])
            return 0;
    }
    return 1;
}

// Rearrange using permutation.
void anagramPalindrome(char str[], int start, int length) {
    if (start == length - 1) {
        if (isPalindrome(str)) {
            printf("%s\n", str);
            return;
        }
    }
    for (int i = start; i < length; i++) {
        if (shouldSwap(str, start, i)) {
            swap(&str[start], &str[i]);
            anagramPalindrome(str, start + 1, length);
            swap(&str[start], &str[i]); // Backtracking.
        }
    }
}

// Removal using Subsequences.
void getSubsequences(char str[], int index, char subsequence[]) {
    int length = strlen(str);

    if (index == length) {
        // Print non-empty subsequences
        if (strlen(subsequence) > 0) {
            int sub_len = strlen(subsequence);
            anagramPalindrome(subsequence, 0, sub_len);
        }
        return;
    }

    // Exclude the current character
    getSubsequences(str, index + 1, subsequence);

    // Include the current character
    subsequence[strlen(subsequence)] = str[index];
    subsequence[strlen(subsequence) + 1] = '\0';

    // Recur for the remaining substring
    getSubsequences(str, index + 1, subsequence);

    // Exclude the current character
    subsequence[strlen(subsequence) - 1] = '\0';
}

int main() {
    char str[] = "abcabc";
    int length = strlen(str);

    // Allocate memory for subsequence
    char subsequence[length + 1];
    subsequence[0] = '\0';

    // Start from the first character of the string
    getSubsequences(str, 0, subsequence);

    return 0;
}