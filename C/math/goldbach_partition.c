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

int count_goldbach_partitions(int num) {
    int count = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (is_prime(i) && is_prime(num - i) && i <= num-i) {
            count++;
        }
    }
    return count;
}

int main() {
    int input;
    printf("Enter an even number: ");
    scanf("%d", &input);

    if (input % 2 != 0) {
        printf("Please enter an even number.\n");
        return 1;
    }

    int partition_count = count_goldbach_partitions(input);
    printf("Number of distinct Goldbach partitions: %d\n", partition_count);

    return 0;
}
