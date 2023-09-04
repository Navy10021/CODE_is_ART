/*
입력되는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int* arr = (int*)calloc(N+1, sizeof(int));

    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    // 연속적인 K-window의 합이 최대가 되는 값 찾기
    int max_val = -105;
    for (int i=0; i<N-K; i++){
        int sum = 0;
        for (int j=i; j<i+K; j++){
            sum+= arr[j];
            if (max_val < sum)
                max_val = sum;
        }
    }

    printf("%d \n", max_val);
}
