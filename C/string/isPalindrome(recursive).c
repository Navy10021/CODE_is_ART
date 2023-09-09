#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is a palindrome recursively
bool isPalindrome(const char* str, int start, int end) {
    if (start >= end) {
        return true; // Base case: a string with 0 or 1 character is a palindrome
    } else if (str[start] != str[end]) {
        return false; // Base case: the characters at the start and end positions do not match
    } else {
        return isPalindrome(str, start + 1, end - 1); // Recursive case
    }
}

int main() {
    char str[100]; // Assuming a maximum string length of 100 characters

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    bool result = isPalindrome(str, 0, length - 1);

    if (result) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }

    return 0;
}
