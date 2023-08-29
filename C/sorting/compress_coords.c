#include<stdio.h>
#include<stdlib.h>

int compare(const void *first, const void *second){
    return (*(int *)first - *(int *)second);
}

int main(){
    int N;
    scanf("%d", &N);
    int *orgin = (int *)calloc(N, sizeof(int));     // 원본 배열 저장
    int *sorted = (int *)calloc(N, sizeof(int));    // 정렬된 배열 저장

    for (int i=0; i<N; i++){
        scanf("%d", &orgin[i]);
    }
    for (int i=0; i<N; i++){
        sorted[i] = orgin[i];
    }
    // 1. 정 렬
    qsort(sorted, N, sizeof(int), compare);
    // 2. 압 축
    int *compress = (int *)calloc(N, sizeof(int));
    int cnt;
    for (int i=0; i<N; i++){
        if (i > 0 && sorted[i] != sorted[i-1]){
            cnt++;
        }
        compress[i] = cnt;
    }
    // 3.압축값 찾기
    int idx;
    for (int i=0; i<N; i++){    // target = orgin[i]
        for (int j=0; j<N; j++){
            if(orgin[i] == sorted[j]){ // 매번 target의 인덱스를 찾는다.
                idx = j;
                break;
            }
        }
        printf("%d ", compress[idx]);
    }
    return 0;
}
