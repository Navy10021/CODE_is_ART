#include <stdio.h>
#include <stdlib.h>

// 1. Array is Pointer! 정적 메모리 할당
/*
int main(){
    int arr[4];
    int *ptr_arr = arr;

    for(int i=0; i<4; i++){
        *(ptr_arr + i) = i;
    }
    printf("%d \n", ptr_arr[2]);
}
*/

// 2. malloc(size) : (자료형 사이즈 * length) 동적 메모리 할당
/*
int main(){
    int length = 4;
    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i=0; i<length; i++){
        *(arr + i) = i;
    }
    printf("{ ");
    for(int i=0; i<length; i++)
        printf("%d ", arr[i]);
    printf("}");
}
*/
// 3. calloc(count, size) : (length, 자료형 사이즈) 동적 메모리할당 + 0 초기화
/*
int main(){
    int length = 5;
    int *arr = (int*)calloc(length, sizeof(int));
    printf("{ ");
    for(int i=0; i<length; i++)
        printf("%d ", arr[i]);
    printf("}");
}
*/

// 4. realloc(pointer, size) : size 만큼 length 변경
int main(){
    int len = 4;
    int len2 = 10;
    int *arr = (int*)malloc(sizeof(int) * len);
    for (int i=0; i<len; i++){
        //arr[i] = i;
        *(arr+i) = i;
    }

    realloc(arr, sizeof(int) * len2);
    for (int i=len; i<len2; i++){
        arr[i] = i;
    }
    printf("{");
    for (int i=0; i<len2; i++){
        printf("%d ", arr[i]);
    }
    printf("}");
}
