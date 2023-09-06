#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a, const void*b){
    return *(int*)a > *(int*)b ? 1: *(int*)a < *(int*)b ? -1 : 0;
}

int binary_search(int *arr, int key, int size){
    int left = 0; 
    int right = size-1;
    int mid;
    while (left <= right){
        mid = (left+right) / 2;
        if (key < arr[mid])
            right = mid-1;
        
        else if(key > arr[mid])
            left = mid +1;

        else    // arr[mid] == key
            return 1;
    }
    return 0;   // Not founded.
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
    
    // arr에 num이 존재하는지 확인
    int M, num, ans;
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &num);
        ans = binary_search(arr, num, N);
        printf("%d \n", ans);
    }
}
