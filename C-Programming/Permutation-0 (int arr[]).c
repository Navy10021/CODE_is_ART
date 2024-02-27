#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int * a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(int * arr, int start, int end){
    for (int i = start; i < end; i++){
        if (arr[i] == arr[end])
            return 0;
    }
    return 1;
}

void genPerm(int * arr, int start, int lenght, int ** res, int * count){
    if (start == lenght - 1){
        res[*count] = malloc((lenght) * sizeof(int));
        // memcpy(void *dest, const void *src, size_t n); // src -> dest로 n 바이트 복사
        memcpy(res[*count], arr, lenght * sizeof(int));
        (*count)++;
        return;
    }
    for (int i = start; i < lenght; i++){
        if (shouldSwap(arr, start, i)){
            swap(&arr[start], &arr[i]);
            genPerm(arr, start+1, lenght, res, count);
            swap(&arr[start], &arr[i]);
        }
    }
}

int comparePermutations(const void *a, const void *b) {
    // int memcmp(const void *ptr1, const void *ptr2, size_t num);
    /*
    0 : 두 메모리 영역이 동일하면 
    양수 : ptr1 > ptr2 (첫번째로 일치하지 않는 바이트의 차이)
    음수 : ptr2 < ptr1 (첫번째로 일치하지 않는 바이트의 차이)
    */
    return memcmp(*(const int **)a, *(const int **)b, sizeof(int));  
}

int main(){
    char string[10];
    scanf("%s", string);
    int n = strlen(string);
    //int input = atoi(string);
    
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = string[i] - '0';
    }

    int numPerms = 1;
    for (int i = 1; i <= n; i++){
        numPerms *= i;
    }

    // Array to store permutations
    int ** permutations = malloc(numPerms * sizeof(int *));
    int count = 0;

    genPerm(arr, 0, n, permutations, &count);

    // Sort the array of permutations
    qsort(permutations, count, sizeof(int *), comparePermutations);

    // Print the permutations
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", permutations[i][j]);
        }
        printf("\n");
        free(permutations[i]);  // Free memory for each permutation
    }

    free(permutations);

    return 0;

}
