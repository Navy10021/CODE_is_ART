// Check string is palindrome
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;

    // Lowercase the string to ignore capitalization
    for(int i = 0; str[i]; i++){
      str[i] = tolower(str[i]);
    }

    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str); // Note: Using gets() is not safe, consider using fgets() in real programs

    if (isPalindrome(str))
        printf("'%s' is a palindrome.\n", str);
    else
        printf("'%s' is not a palindrome.\n", str);

    return 0;
}