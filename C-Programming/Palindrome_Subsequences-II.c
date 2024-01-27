#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
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

void genSubseq(char *str, int l, int r, char *subseq, int subseq_idx, char **arr, int *arr_idx) {
    if (l > r) {
        if (strlen(subseq) > 0 && isPalindrome(subseq) && !seen(arr, *arr_idx, subseq)) {
            strcpy(arr[(*arr_idx)++], subseq);
            //arr[(*arr_idx)++] = strdup(subseq);
        }
        return;
    }

    // 1. Exclude current char
    genSubseq(str, l + 1, r, subseq, subseq_idx, arr, arr_idx);
    // 2. Include current char
    subseq[subseq_idx] = str[l];
    subseq[subseq_idx + 1] = '\0';
    genSubseq(str, l + 1, r, subseq, subseq_idx + 1, arr, arr_idx);
    subseq[subseq_idx] = '\0';  // 3. Reset for backtracking : POP()
}

void subsequnces(char *str) {
    int len = strlen(str);
    int st = 0;
    int en = len - 1;

    int res_size = 1 << len;
    int res_idx = 0;
    char **res = (char **)malloc(res_size * sizeof(char *));
    for (int i = 0; i < res_size; i++) {
        res[i] = (char *)malloc((len + 1) * sizeof(char));
    }
    char* subseq = (char*)malloc((len + 1) * sizeof(char));
    int subseq_idx = 0;
    genSubseq(str, st, en, subseq, subseq_idx, res, &res_idx);

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
    subsequnces(input);
    return 0;
}