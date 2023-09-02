#include <stdio.h>
#include <math.h>

void canto(int n) {
    int size = pow(3, n - 1);

    // Base case
    if (n == 0) {
        printf("-");
        return;
    }
    // canto(n) = canto(n-1) + space(size) + canto(n-1);
    canto(n - 1);
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
    canto(n - 1);
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        canto(N);
        printf("\n");
    }
    return 0;
}
