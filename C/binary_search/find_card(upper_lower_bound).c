#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
/*
N개의 숫자카드 중 target 카드의 개수
tgt 카드의 개수 : upper_bound - lower_bound
upper_bound = target을 초과한 최초의 인댁스
lower_bound = target 이상의 최초 인덱스
*/

int cmp(const void*a, const void*b){
    return *(int*)a > *(int*)b ? 1: *(int*)a < *(int*)b ? -1 : 0;
}

int lower_bound(int* arr, int key, int size){
    int left = 0;
    int right = size-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (key <= arr[mid])    // 이상!
            right = mid;
        else
            left = mid+1;
    }
    return right;
}

int upper_bound(int* arr, int key, int size){
    int left = 0;
    int right = size-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (key < arr[mid])    // 초과!
            right = mid;
        else
            left = mid+1;
    }
    // 해당문제의 경우 예외처리(수정) : 맨마지막 카드의 경우 right + 1
    if (arr[right] == key){
        return right + 1;
    }

    return right;
}


int main(){
    int N;
    scanf("%d", &N);
    int* arr = (int*)calloc(N, sizeof(int));
    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    // sorting
    qsort(arr, N, sizeof(int), cmp);

    // arr에 num의 개수 확인.
    int M, num, ans;
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &num);
        ans = upper_bound(arr, num, N) - lower_bound(arr, num, N);
        printf("%d \n", ans);
    }
}
