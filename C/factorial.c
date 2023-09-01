#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 0) {
        printf("Impossible\n");
        return 1; // 오류 코드 반환
    }

    unsigned long long factorial = 1; // 큰 수를 다루기 위해 unsigned long long 사용

    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    printf("%d! = %llu\n", N, factorial);

    return 0;
}
