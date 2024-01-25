#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
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

// Function to find palindrome pairs
int** palindromePairs(char** words, int word_size, int** res_col, int* res_size) {
    for (int i = 0; i < word_size; i++) {
        for (int j = i + 1; j < word_size; j++) {
            char* str1 = strdup(words[i]);
            char* str2 = strdup(words[j]);
            strcat(str1, words[j]);
            strcat(str2, words[i]);
            if (is_palindrome(str1)) {
                res_col[*res_size][0] = i;
                res_col[*res_size][1] = j;
                (*res_size)++;
            }
            if (is_palindrome(str2)) {
                res_col[*res_size][0] = j;
                res_col[*res_size][1] = i;
                (*res_size)++;
            }
            free(str1);
            free(str2);
        }
    }
    return res_col;
}

int main(void) {
    int word_size;
    scanf("%d", &word_size);
    char** words = (char**)malloc(word_size * sizeof(char*));

    for (int i = 0; i < word_size; i++) {
        char word[100];
        scanf("%s", word);
        words[i] = strdup(word);
    }

    int** res = (int**)malloc((1 << word_size) * sizeof(int*));
    for (int i = 0; i < (1 << word_size); i++) {
        res[i] = (int*)malloc(2 * sizeof(int)); // [0, 1]
    }

    int res_size = 0;

    palindromePairs(words, word_size, res, &res_size);

    printf("[");
    for (int i = 0; i < res_size; i++) {
        printf("[%d, %d]", res[i][0], res[i][1]);
        if (i < res_size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    for (int i = 0; i < (1 << word_size); i++) {
        free(res[i]);
    }
    free(res);
    for (int i = 0; i < word_size; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}