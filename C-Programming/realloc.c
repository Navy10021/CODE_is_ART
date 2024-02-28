#include <stdio.h>
#include <stdlib.h> // 동적 메모리 할당을 위한 헤더 파일

int main() {
    int *arr;
    int n = 5; // 초기 배열 크기
    int newSize = 10; // 새 배열 크기

    // malloc을 사용하여 초기 배열 할당
    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // 메모리 할당 실패 시 프로그램 종료
    }

    // 할당된 배열을 0으로 초기화 (calloc이 자동으로 해주는 일)
    for(int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    // 배열 크기 변경을 위해 realloc 사용
    arr = (int*)realloc(arr, newSize * sizeof(int));
    if(arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1; // 메모리 재할당 실패 시 프로그램 종료
    }

    // 새로 할당된 부분을 0으로 초기화
    for(int i = n; i < newSize; i++) {
        arr[i] = 0;
    }

    // 배열 사용 (여기서는 간단히 프린트만 해보겠습니다)
    for(int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 메모리 해제
    free(arr);

    return 0;
}