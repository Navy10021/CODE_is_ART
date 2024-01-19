#include <stdio.h>
#include <string.h>

int patternMatch(char *pattern, char *str) {
    if (*pattern == '\0' && *str == '\0') {
        return 1;
    }

    if (*pattern == '*' && *(pattern + 1) != '\0' && *str == '\0') {
        return 0;
    }

    if (*pattern == '?' || *pattern == *str) {
        return patternMatch(pattern + 1, str + 1);
    }

    if (*pattern == '*') {
        return patternMatch(pattern + 1, str) || patternMatch(pattern, str + 1);
    }

    return 0;
}

int main(void) {
    char pattern[100] = "a*d?";
    char str[100] = "abcde";

    if (patternMatch(pattern, str)) {
        printf("Pattern matches the string.\n");
    } else {
        printf("Pattern does not match the string.\n");
    }

    return 0;
}