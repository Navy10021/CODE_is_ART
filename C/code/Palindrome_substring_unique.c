#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int isSubstringAlreadyPrinted(char substr[], char substrings[][100], int numSubstrings) {
    for (int i = 0; i < numSubstrings; i++) {
        if (strcmp(substr, substrings[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void printUniquePalindromicSubstrings(char str[]) {
    int length = strlen(str);
    char substrings[100][100];
    int numSubstrings = 0;


    for (int len = 1; len <= length; len++) {
        for (int start = 0; start <= length - len; start++) {
            int end = start + len - 1;

            if (isPalindrome(str, start, end)) {
                char substring[100];
                int k = 0;

                for (int i = start; i <= end; i++) {
                    substring[k++] = str[i];
                }
                substring[k] = '\0';

                if (!isSubstringAlreadyPrinted(substring, substrings, numSubstrings)) {
                    strcpy(substrings[numSubstrings], substring);
                    numSubstrings++;

                    printf("%s\n", substring);
                }
            }
        }
    }
}

int main() {
    char input_str[] = "ABCBA";

    printUniquePalindromicSubstrings(input_str);

    return 0;
}
