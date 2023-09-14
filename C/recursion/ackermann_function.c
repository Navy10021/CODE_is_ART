#include <stdio.h>
/*아커만 함수 A(m, n)*/
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    }
    if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0; // Error case
}

int main() {
    int m, n;
    printf("Enter values for m and n: ");
    scanf("%d %d", &m, &n); // (3, 2)

    int result = ackermann(m, n);
    printf("Ackermann(%d, %d) = %d\n", m, n, result);

    return 0;
}
