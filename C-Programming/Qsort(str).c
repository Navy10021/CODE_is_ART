#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// string 오름차순 정렬
int compare(const void *a, const void *b){
    return (*(char*)a - *(char*)b);  // using void* pointer : (int*)로 결정 / a pointer's value b pointer's value 비교 
}

int main(void){
  char arr[100] = "bcacde";

    qsort(arr, strlen(arr), sizeof(char), compare);

    printf("%s", arr);

    return 0;
}

