#include <stdio.h>
#include <string.h>     // for string

const char* A_and_B(int a, int b){
    if (a > b){
        return ">";
    }

    else if (a < b){
        return "<";
    }

    return "==";
}

int main(){
    int A, B;

    printf("Enter three numbers :");
    scanf("%d %d", &A, &B);

    const char* result = A_and_B(A, B); // Use const char* for strings

    printf("Sum of the three numbers is : %s\n", result);   // Use %s for string
    return 0;
}
