#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If the lengths are different, the strings cannot be anagrams
    if (len1 != len2) {
        return 0;
    }

    // Sort the characters in both strings
    qsort(str1, len1, sizeof(char), compareChars);
    qsort(str2, len2, sizeof(char), compareChars);

    // Compare the sorted strings
    return strcmp(str1, str2) == 0;
}

// Comparison function for qsort
int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char str1[100], str2[100];

    // Input the two strings
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("The strings \"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("The strings \"%s\" and \"%s\" are not anagrams.\n", str1, str2);
    }

    return 0;
}
