#include <stdio.h>

int sumofThree(int a, int b, int c){
    return a+b+c;
}

int main(){
    int num1, num2, num3;

    printf("Enter three numbers :");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = sumofThree(num1, num2, num3);

    printf("Sum of the three numbers is : %d\n", result);
    return 0;
}
