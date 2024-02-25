#include <stdio.h>
#include <string.h>

// 문자열에서 서브스트링을 발견한 모든 위치의 인덱스를 반환
void findSubstrIdx(const char* str, const char* substring, int* arr, int* idx) {
    /* Returns the index of the first occurrence of substring in the string. If not found, return -1. */
    const char* pos = str;

    while((pos = strstr(pos, substring)) != NULL){
        arr[(*idx)++] = pos - str;
        pos++;
    }
}

// 위치 찾아서 return
int main() {
    char input[100] = "abcabcyoonseopabc";
    char substr[10] = "abc";
    int arr[10];
    int arr_idx = 0;

    findSubstrIdx(input, substr, arr, &arr_idx);
    for (int i = 0; i < arr_idx; i++){
        printf("%d, ", arr[i]);
    }

	return 0;
}
