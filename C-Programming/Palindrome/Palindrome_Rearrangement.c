#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

// Function to check if characters of a string can form a palindrome
int canFormPalindrome(char *str) {
    int count[NO_OF_CHARS] = {0};

    // Count frequency of each character
    for (int i = 0; str[i]; i++)
        count[str[i]]++;

    // Check for palindrome conditions
    int odd = 0;
    for (int i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] & 1) // == 1 is odd , == 0 is even 
            odd++;

        if (odd > 1)
            return 0;
    }

    return 1;
}

int main() {
    char str[] = "tactcoa";
    if (canFormPalindrome(str))
        printf("Yes. Can make Palindrome.\n");
    else
        printf("No\n");
    return 0;
}