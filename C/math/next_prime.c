#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int find_next_prime(int num) {
    while (true) {
        if (is_prime(num)) {
            return num;
        }
        num++;
    }
}

int main() {
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    int next_prime = find_next_prime(input);

    printf("The smallest prime greater than or equal to %d is: %d\n", input, next_prime);

    return 0;
}
