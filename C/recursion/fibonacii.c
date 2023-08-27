#include <stdio.h>

// Function to calculate Fibonacci using recursion
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fibonacci sequence is not defined for negative numbers.\n");
    } else {
        printf("Fibonacci sequence up to %d terms:\n", num);
        for (int i = 0; i < num; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
