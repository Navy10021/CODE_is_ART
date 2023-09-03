#include <stdio.h>
/*
1 ~ N 자연수 중 중복 없이 M개를 고르는 '수열'(순서 있음.)
*/

int N, M;
int arr[10];
int is_used[10] = {0,};

void func(int K){ // 현재까지 K개의 수를 선택.
    if (K == M){  // 길이가 M이면 array 출력
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
    printf("\n");
    return;
    }
    for (int i = 1; i <= N; i++){ // 모든 arr의 index에 1 ~ N까지의 수를 사용.
        if (!is_used[i]){     // i를 사용하지 않았다면
            arr[K] = i;       // K번째arr에 해당수(i)를 추가하고
            is_used[i] = 1;   // 사용 표시 후
            func(K+1);        // recursion(K+1) : K+1 위치에 1~N까지의 수를 사용.
            is_used[i] = 0;   // 사용값 원위치 backtracking
            }
    }
}

int main(){
    scanf("%d %d", &N, &M);

    func(0); // array[0] 부터 시작!
}



