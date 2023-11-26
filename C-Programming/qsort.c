#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void qsort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
- base : 정렬할 배열의 시작 주소
- nmemb : 배열의 요소의 개수
- size : 각 요소의 크기
- 비교함수의 포인터

int compare(const void *a, void *b);
- a < b : 음수 반환
- a == b : 0
- a > b : 양수 반환
*/

// 정수 비교함수
int compare(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}

// 문자열 비교함수
int compareStr(const void * a, const void * b){
    return strcmp(*(const char **)a, *(const char **)b);
}

// 문자열 길이 비교함수
int compareLen(const void * a, const void * b){
    size_t lenA = strlen(*(const char **)a);
    size_t lenB = strlen(*(const char **)b);

    // 길이 비교
    if (lenA < lenB) return -1;
    if (lenA > lenB) return 1;

    // 길이가 같으면 사전순으로 정렬
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(){
    /*
    int arr[] = {3,2,1,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    */

    const char * strings[] = {"BA", "BC", "CB", "CD", "BD", "AB", "AC", "AD", "AAA", "BBB", "CCC", "ABC"};
    int n = sizeof(strings) / sizeof(strings[0]);

    //qsort(strings, n, sizeof(strings[0]), compareStr);
    qsort(strings, n, sizeof(strings[0]), compareLen);

    for (int i = 0; i < n; i++){
        printf("%s -> ", strings[i]);
    }
    return 0;
}
