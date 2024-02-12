#include <stdio.h>

int isPalindrome(int number) {
    int reversed = 0;
    int originalNumber = number;

    // Reversing the number
    while (number != 0) {
        int remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    // Checking if the number is palindrome
    if (originalNumber == reversed)
        return 1;
    else
        return 0;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a palindrome.\n", number);
    else
        printf("%d is not a palindrome.\n", number);

    return 0;
}