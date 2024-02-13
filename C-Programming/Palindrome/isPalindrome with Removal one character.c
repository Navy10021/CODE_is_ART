#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to check if a substring is a palindrome
bool isPalindrome(const char *s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

// Function to determine if the string can become a palindrome by removing one character
bool validPalindrome(char *s) {
    int left = 0, right = strlen(s) - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            // Check skipping either character makes the string a palindrome
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char input[] = "abca";
    if (validPalindrome(input)) {
        printf("The string can become a palindrome by removing one character.\n");
    } else {
        printf("The string cannot become a palindrome by removing one character.\n");
    }
    return 0;
}