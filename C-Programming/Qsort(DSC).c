#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
// void pointer : 주소값에만 의미를 두고, 포인터 형은 나중에 결정하겠다.
int compare(const void *a, const void *b){
    return (*(int*)b - *(int*)a);  // using void* pointer : (int*)로 결정 / a pointer's value b pointer's value 비교 
}

int main(){
    int arr[] = {3, 4, 5, 6, 7, 2, 1};

    size_t n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for (int i  = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}