/*
1부터 N까지 자연수 중에서 M개를 고르는 것
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void genCombination(int arr[], int n, int m, int data[], int idx, int start){
    if (idx == m){
        for (int i=0; i<m; i++){
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i<n; i++){
        data[idx] = arr[i];
        genCombination(arr, n, m, data, idx + 1, i + 1);
    }
}

// Comparator function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[N];
    for (int i = 0; i<N; i++){
        arr[i] = i+1;
    }
    // Sort the array in ascending order
    qsort(arr, N, sizeof(int), compare);

    // Combination을 저장하는 배열
    int data[M];

    genCombination(arr, N, M, data, 0, 0);


}
