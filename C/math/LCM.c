#include <stdio.h>

// 두 정수의 최대 공약수(GCD)를 계산하는 함수
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

// 두 정수의 최소 공배수(LCM)를 계산하는 함수
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int main() {
    int num1, num2;
    
    //printf("두 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);
    
    int lcm = findLCM(num1, num2);
    
    printf("LCM(%d and %d) is %d.\n", num1, num2, lcm);
    
    return 0;
}
