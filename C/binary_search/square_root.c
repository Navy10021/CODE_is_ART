#include <stdio.h>
#include <math.h>

double squareRoot(double x, double epsilon) {
    double left = 0;
    double right = x;

    while (fabs(right - left) > epsilon) {
        double mid = left + (right - left) / 2; // Calculate the middle value

        if (mid * mid > x) {
            right = mid; // Search in the left half
        } else {
            left = mid; // Search in the right half
        }
    }

    return (left + right) / 2; // Approximation of square root
}

int main() {
    double number = 20.0;
    double epsilon = 1e-6; // Tolerance for approximation

    double result = squareRoot(number, epsilon);

    printf("Square root of %lf is approximately %lf\n", number, result);

    return 0;
}
