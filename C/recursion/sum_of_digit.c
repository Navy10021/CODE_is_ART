#include <stdio.h>

// Function to calculate the sum of digits of a positive integer recursively
int sumOfDigits(int n) {
    if (n == 0) {
        return 0; // Base case: the sum of digits of 0 is 0
    } else {
        return (n % 10) + sumOfDigits(n / 10); // Recursive case
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int result = sumOfDigits(num);

    printf("Sum of digits of %d is %d\n", num, result);

    return 0;
}
