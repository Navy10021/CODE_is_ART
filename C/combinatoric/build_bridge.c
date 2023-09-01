#include <stdio.h>

// 팩토리얼 계산 함수
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 이항 계수 계산 함수
double binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // 유효하지 않은 경우
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n, k;
    scanf("%d %d", &k, &n);

    double result = binomialCoefficient(n, k);

    printf("C(%d, %d) = %lf\n", n, k, result);

    return 0;
}
