#include <stdio.h>

// Function to calculate the power of a number recursively
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1; // Any number raised to the power of 0 is 1
    } else if (exponent > 0) {
        return base * power(base, exponent - 1); // Recursive case for positive exponents
    } else {
        return 1 / (base * power(base, -exponent)); // Recursive case for negative exponents
    }
}

int main() {
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);

    printf("%.2lf^%d = %.2lf\n", base, exponent, result);

    return 0;
}
