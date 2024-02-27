#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// Converts a single digit to its character representation
char digitToChar(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0';
    } else {
        // For alphabets A-Z to represent 10-35
        return num - 10 + 'A';
    }
}

// Reverses a string in place
void reverse(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Converts a decimal number to a string representation in a given base
char* fromDeci(char res[], int base, int num) {
    int index = 0; // res array index
    while (num > 0) {
        res[index++] = digitToChar(num % base); // Store remainder
        num /= base; // Divide by base
    }
    res[index] = '\0';
    reverse(res);
    return res;
}

// Checks if a string is a palindrome
int isPalindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

int main(void) {
    int num, base;
    scanf("%d %d", &num, &base);

    // Iterate through bases 2 to the given base
    for (int b = 2; b <= base; b++) {
        char arr[MAX_LEN];
        fromDeci(arr, b, num);
        if (isPalindrome(arr)) {
            printf("Base %d: %s\n", b, arr); // Print only if it's a palindrome
        }
    }

    return 0;
}
