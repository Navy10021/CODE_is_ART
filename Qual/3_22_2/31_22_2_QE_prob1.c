#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char s[], int k, char **result, int *cnt) {
    static int isused[10]; // Initialized to zero since it's static
    static char Res[10];
    int i;
    if (s[k] == '\0') {
        Res[k] = '\0';
        result[*cnt] = (char *)malloc((strlen(Res) + 1) * sizeof(char));
        strcpy(result[*cnt], Res);
        (*cnt)++;
    } else {
        for (i = 0; s[i] != '\0'; i++) {
            if (isused[i] == 0) {
                Res[k] = s[i];
                isused[i] = 1;
                backtrack(s, k + 1, result, cnt);
                isused[i] = 0;
            }
        }
    }
}

int main() {
    char s[] = "ABC";
    int factorial = 1;
    for (int i = 1; i <= strlen(s); i++) {
        factorial *= i;
    }
    char **result = (char **)malloc(factorial * sizeof(char *)); // Allocate memory for the result array
    int cnt = 0;
    printf("string is \"%s\"\n", s);
    printf("Permutations are: \n");
    backtrack(s, 0, result, &cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // Free each string
    }
    free(result); // Free the result array
    return 0;
}
