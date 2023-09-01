#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("Divisors of %d: ", number);
    
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    return 0;
}


