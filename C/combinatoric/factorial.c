#include <stdio.h>

// 팩토리얼 계산 함수
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    int n;
    scanf("%d", &n);

    unsigned long long result = factorial(n);

    printf("%d", result);

    return 0;
}

