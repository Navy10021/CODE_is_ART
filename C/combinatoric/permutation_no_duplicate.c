#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            int should_swap = 1;

            // Check for duplicates and avoid swapping if duplicates are found
            for (int j = left; j < i; j++) {
                if (str[j] == str[i]) {
                    should_swap = 0;
                    break;
                }
            }

            if (should_swap) {
                swap(&str[left], &str[i]);
                permute(str, left + 1, right);
                swap(&str[left], &str[i]); // Backtrack
            }
        }
    }
}

int main() {
    char str[] = "aab";
    int n = strlen(str);

    printf("Permutations of '%s' with duplicates:\n", str);
    permute(str, 0, n - 1);

    return 0;
}
