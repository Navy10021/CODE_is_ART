#include <stdio.h>
#include <string.h>

void printPalindromicString(char str[], int n) {
    int dp[n][n];

    // Initialize the dynamic programming table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0;
        }
    }

    // Build the dynamic programming table
    for (int gap = 1; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            dp[i][j] = (str[i] == str[j]) ? dp[i + 1][j - 1] : (1 + (dp[i][j - 1] < dp[i + 1][j] ? dp[i][j - 1] : dp[i + 1][j]));
        }
    }
    printf("The number of Insertion : %d\n", dp[0][n-1]);

    // Reconstruct the palindromic string
    int i = 0, j = n - 1;
    char palindromicString[n + dp[0][n - 1] + 1];
    palindromicString[n + dp[0][n - 1]] = '\0';

    int start = 0, end = n + dp[0][n - 1] - 1;

    while (i <= j) {
        if (i == j) {
            palindromicString[start++] = str[i];
            palindromicString[end--] = str[i];
            break;
        }

        if (str[i] == str[j]) {
            palindromicString[start++] = str[i];
            palindromicString[end--] = str[i];
            ++i;
            --j;
        } else if (dp[i][j - 1] < dp[i + 1][j]) {
            palindromicString[start++] = str[j];
            palindromicString[end--] = str[j];
            --j;
        } else {
            palindromicString[start++] = str[i];
            palindromicString[end--] = str[i];
            ++i;
        }
    }

    printf("Palindromic String: %s\n", palindromicString);
}

int main() {
    char str[50];
    scanf("%s", str);
    int n = strlen(str);

    printPalindromicString(str, n);

    return 0;
}