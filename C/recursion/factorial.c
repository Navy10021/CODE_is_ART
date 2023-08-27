#include<stdio.h>

int factorial(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int num;
    scanf("%d", &num);

    if (num<0){
        printf("negative number");
    }
    else{
        int res = factorial(num);
        printf("%d", res);
    }
}
