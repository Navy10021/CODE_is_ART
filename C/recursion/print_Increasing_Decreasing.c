#include <stdio.h>

void printIncreasingDecreasing(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);
    printIncreasingDecreasing(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Numbers in increasing and decreasing order: ");
    printIncreasingDecreasing(n);
    printf("\n");

    return 0;
}
