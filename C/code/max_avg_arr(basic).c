#include <stdio.h>

// 새로운 평균 : 최대값(M), Total score / M * 100

int main(){
    int N;
    int max = 0;
    double avg = 0;
    scanf("%d", &N);
    int arr[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        if (max < arr[i]){
            max = arr[i];
        }
    }
    for (int i = 0; i < N; i++){
        avg += (double)arr[i] / max * 100;
    }

    printf("%f\n", avg/N);

}
