#include <stdio.h>

// Function to check if 's' is a subsequence of 't'
bool isSubsequence(char *s, char *t) {
    while (*t) {
        // If characters match, move to the next character in 's'
        if (*s == *t)
            s++;
        t++;
    }
    // If we've reached the end of 's', all characters were found in sequence
    return *s == '\0';
}

int main() {
    char s[] = "abc";  // Subsequence
    char t[] = "ahbgdc";  // Main string

    if (isSubsequence(s, t)) {
        printf("'%s' is a subsequence of '%s'\n", s, t);
    } else {
        printf("'%s' is NOT a subsequence of '%s'\n", s, t);
    }

    return 0;
}
