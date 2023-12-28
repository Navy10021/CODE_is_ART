#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALINDROMES 100

int isPalindrome(char str[]) {
    int st = 0;
    int en = strlen(str) - 1;
    while (st < en) {
        if (str[st] != str[en]) {
            return 0;
        }
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

int shouldSwap(char *str, int st, int en) {
    for (int i = st; i < en; i++) {
        if (str[i] == str[en])
            return 0;
    }
    return 1;
}

// 1. Rearrange string using Permutation.
void AnagramPalindrome(char str[], int curr_idx, int length, char palindromes[][MAX_PALINDROMES], int *palindrome_count) {
    if (curr_idx == length - 1) {
        // Check for palindrome after each permutation
        if (isPalindrome(str)) {
            strcpy(palindromes[*palindrome_count], str);
            (*palindrome_count)++;
        }
        return;
    }

    for (int i = curr_idx; i < length; i++) {
        if (shouldSwap(str, curr_idx, i)) {
            swap(&str[curr_idx], &str[i]);
            AnagramPalindrome(str, curr_idx + 1, length, palindromes, palindrome_count);
            swap(&str[curr_idx], &str[i]);
        }
    }
}

// 2. Erase string using Generate Subsequence.
void GenSubseq(char str[], int curr_idx, char subseq[], char palindromes[][MAX_PALINDROMES], int *palindrome_count) {
    int length = strlen(str);

    if (curr_idx == length) {
        int sub_len = strlen(subseq);
        AnagramPalindrome(subseq, 0, sub_len, palindromes, palindrome_count);
        return;
    }

    // Exclude current char
    GenSubseq(str, curr_idx + 1, subseq, palindromes, palindrome_count);

    // Include current char
    int subseq_len = strlen(subseq);
    subseq[subseq_len] = str[curr_idx];
    subseq[subseq_len + 1] = '\0';
    GenSubseq(str, curr_idx + 1, subseq, palindromes, palindrome_count);   // Recursion

    // Backtrack: Exclude current char
    subseq[subseq_len] = '\0';
}

int compareByLength(const void *a, const void *b) {
    return strlen(*(const char **)b) - strlen(*(const char **)a);
}

int compareLexicographically(const void *a, const void *b) {
    return strcmp(*(const char (*)[])a, *(const char (*)[])b);
}

int main(void) {
    char input[] = "aabc";
    int length = strlen(input);
    char subseq[length + 1];
    subseq[0] = '\0';

    char palindromes[MAX_PALINDROMES][MAX_PALINDROMES];
    int palindrome_count = 0;

    GenSubseq(input, 0, subseq, palindromes, &palindrome_count);

    // Create an array of pointers to palindromes
    char *sorted_palindromes[MAX_PALINDROMES];
    for (int i = 0; i < palindrome_count; i++) {
        sorted_palindromes[i] = palindromes[i];
    }

    // Sort the array of pointers based on the length of the strings
    qsort(sorted_palindromes, palindrome_count, sizeof(char *), compareByLength);
    //qsort(sorted_palindromes, palindrome_count, sizeof(char *), compareLexicographically);

    // Print or manipulate sorted_palindromes as needed
    for (int i = 0; i < palindrome_count; i++) {
        printf("%s\n", sorted_palindromes[i]);
    }

    return 0;
}
