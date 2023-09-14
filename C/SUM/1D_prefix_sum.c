#include <stdio.h>

int main(){
    int N;
    //scanf("%d", &N);
    //int * arr = (int*)calloc(N+1, sizeof(int));
    //int * prefix = (int*)calloc(N+1, sizeof(int));
    int arr[5] = {3, 5, 7, 1, 4};
    int psum[5];

    // 1. 누적합 : psum[n] = arr[0] + arr[1] + ... arr[n]
    psum[0] = arr[0];
    for (int i=1; i<=5; i++){
        psum[i] = psum[i-1] + arr[i];
    }
    // 2. 구간합(index : 1 ~ 3)
    int i = 1, j = 3;
    int res = psum[j] - psum[i-1];
    printf("%d", res);
}
