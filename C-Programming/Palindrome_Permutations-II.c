#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int isDuplicate(char *str, int st, int en) {
    for (int i = st; i < en; i++) {
        if (str[i] == str[en]) {
            return 1;
        }
    }
    return 0;
}

int isPalindrome(char *str) {
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

void genPermutation(char *str, int l, int r, char **arr, int *arr_idx) {
    if (l == r && isPalindrome(str)) {
        strcpy(arr[(*arr_idx)++], str);
        //arr[(*arr_idx)++] = strdup(str);
        return;
        
    } else {
        for (int i = l; i <= r; i++) {
            if (!isDuplicate(str, l, i)) {
                swap((str + l), (str + i));
                genPermutation(str, l + 1, r, arr, arr_idx);
                swap((str + l), (str + i));
            }
        }
    }
}

void permutation(char *str) {
    int len = strlen(str);
    int st = 0;
    int en = len - 1;

    int res_size = 1 << len;
    int res_idx = 0;
    char **res = (char **)malloc(res_size * sizeof(char *));
    for (int i = 0; i < res_size; i++) {
        res[i] = (char *)malloc((len + 1) * sizeof(char));
    }
    genPermutation(str, st, en, res, &res_idx);

    // Print the results
    for (int i = 0; i < res_idx; i++) {
        printf("%s\n", res[i]);
        free(res[i]); // Free memory for each string
    }

    free(res); // Free memory for the array of strings
}

int main(void) {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    permutation(input);
    return 0;
}