#include <stdio.h>
/*
A ~ Z 알파벳 중 '중복을 허용'해 M개를 고르는 '수열'(순서 있음.)
*/

int N, M, st;
int arr[10];
int is_used[10] = {0,};

void func(int K){ // 현재까지 K개의 수를 선택.
    if (K == M){  // 길이가 M이면 array 출력
        for (int i = 0; i < M; i++){
            printf("%c ", arr[i]);
        }
    printf("\n");
    return;
    }

    for (int i = 65; i <= 65+N-1; i++){ // 모든 arr의 index에 1 ~ N까지의 수를 사용.
            arr[K] = i;       // K번째arr에 해당수(i)를 추가하고
            is_used[i] = 1;   // 사용 표시 후
            func(K+1);        // recursion(K+1) : K+1 위치에 1~N까지의 수를 사용.
            is_used[i] = 0;   // 사용값 원위치 backtracking
    }
}

int main(){
    scanf("%d %d", &N, &M);
    //printf("%c %c", 65, 90);

    func(0); // array[0] 부터 시작!
}



