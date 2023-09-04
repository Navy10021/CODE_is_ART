#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int * arr = (int*)calloc(N+1, sizeof(int));
    int * prefix = (int*)calloc(N+1, sizeof(int));

    for (int i=1; i <= N; i++){
        scanf("%d", &arr[i]);
    }
    // 누적합 구하기.
    prefix[1] = arr[1];
    for (int i=2; i<=N; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    // 구간합 구하기
    int left, right;
    scanf("%d %d", &left, &right);  // left 번째 수부터 ~ right 번째수
    int res = prefix[right] - prefix[left-1];
    printf("%d \n", res);
}
