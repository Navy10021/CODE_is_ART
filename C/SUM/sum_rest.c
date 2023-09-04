#include <stdio.h>
#include <stdlib.h>
/*
수 N개 A1, A2, ..., AN. 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
*/
int main(){
    int N, M, num;
    scanf("%d %d", &N, &M);
    int* cnt = (int*)calloc(N+10, sizeof(int));
    int* prefix = (int*)calloc(N+10, sizeof(int));

    // [1, a] 구간합의 나머지와 [1,b] 구간합의 나머지가 동일하면 [a+1, b] 구간합은 M으로 나눠떨어짐.
    for (int i=1; i<=N; i++){
        scanf("%d", &num);
        prefix[i] = (prefix[i-1] + num) % M; // 누적합의 나머지를 저장
        cnt[prefix[i]]++;                    // 누적합 개수 ++
    }

    int ans = cnt[0];
    for (int i=0; i<M; i++){
        ans += (cnt[i] * (cnt[i]-1)) / 2;
    }
    printf("%d", ans);
}
