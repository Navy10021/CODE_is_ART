#include <stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(char str[], int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        generatePermutations(str, start + 1, end);
        swap(&str[start], &str[i]); // Backtrack
    }
}

int main() {
    char str[] = "ABC";
    int n = sizeof(str) - 1; // Length of the string

    printf("Permutations of \"%s\":\n", str);
    generatePermutations(str, 0, n - 1);

    return 0;
}
