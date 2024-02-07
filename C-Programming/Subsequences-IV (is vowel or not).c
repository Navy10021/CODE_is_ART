#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Check if the string has the same number of vowels and consonants
int is_same(char *str) {
    int num_vowel = 0, num_consonant = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i])) num_vowel++;
        else if (isalpha(str[i])) num_consonant++; // Ensure counting only alphabetic characters
    }
    return num_vowel == num_consonant;
}

void partition(char* str, int index, int length, char* path, int path_len, char** arr, int* arr_idx, int* used) {
    // Ensure the subsequence ends here for proper counting
    path[path_len] = '\0';
    if (path_len > 0 && is_same(path)) {
        for (int i = 0; i < *arr_idx; i++) {
            if (strcmp(arr[i], path) == 0) {
                // Duplicate found, do not add or print
                return;
            }
        }
        // Add unique subsequence with equal vowels and consonants
        arr[*arr_idx] = strdup(path);
        (*arr_idx)++;
    }

    for (int i = index; i < length; i++) {
        if (used[i]) continue; // Skip used characters to maintain uniqueness
        used[i] = 1;
        path[path_len] = str[i];
        partition(str, i + 1, length, path, path_len + 1, arr, arr_idx, used);
        used[i] = 0; // Backtrack
    }
}

void subsequences(char *str) {
    int length = strlen(str);
    char* path = malloc((length + 1) * sizeof(char));
    int* used = calloc(length, sizeof(int));

    int arr_size = 1 << length;
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;

    partition(str, 0, length, path, 0, arr, &arr_idx, used);
    
    int max_len = 0;
    char *max_subseq = NULL;
    for (int i = 0; i < arr_idx; i++) {
        int curr_len = strlen(arr[i]);
        if (curr_len > max_len || (curr_len == max_len && strcmp(arr[i], max_subseq) < 0)) {
            free(max_subseq);
            max_len = curr_len;
            max_subseq = strdup(arr[i]);
        }
    }
    
    if (max_subseq != NULL) {
        printf("Subsequence of max length with equal vowels and consonants: %s (%d)\n", max_subseq, max_len);
        free(max_subseq);
    } else {
        printf("No valid subsequence found.\n");
    }
    
    for (int i = 0; i < arr_idx; i++) free(arr[i]);
    free(path);
    free(arr);
    free(used);
}

int main(void) {
    char input[50];
    scanf("%s", input);
    subsequences(input);
    return 0;
}