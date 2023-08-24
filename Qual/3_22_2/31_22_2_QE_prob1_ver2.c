#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int shouldSwap(char str[], int start, int curr) {
    for (int i = start; i < curr; i++) {
        if (str[i] == str[curr]) {
            return 0;
        }
    }
    return 1;
}

void str_perm_util(char str[], int index, int n, char **result, int *count) {
    if (index >= n) {
        result[*count] = (char *)malloc((n + 1) * sizeof(char));
        strcpy(result[*count], str);
        (*count)++;
        return;
    }

    for (int i = index; i < n; i++) {
        int check = shouldSwap(str, index, i);
        if (check) {
            swap(&str[index], &str[i]);
            str_perm_util(str, index + 1, n, result, count);
            swap(&str[index], &str[i]);
        }
    }
}

int factorial(int n){
    int result = 1;
    while(n>1){
        result *=n;
        n--;
    }
    return result;
}

char **str_perm(char *s) {
    int n = strlen(s);
    char **result = (char **)malloc(sizeof(char *) * n * factorial(n)); // Assuming maximum 1000 unique permutations
    int count = 0;

    str_perm_util(s, 0, n, result, &count);
    result[count] = NULL; // Marking the end of the result

    return result;
}

int main() {
    char s[] = "abcd";
    char **result = str_perm(s);

    for (int i = 0; result[i] != NULL; i++) {
        printf("\"%s\", ", result[i]);
        free(result[i]);
    }

    free(result);
    return 0;
}
