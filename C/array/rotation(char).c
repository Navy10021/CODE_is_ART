#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to rotate an array to the left by 'd' positions
void leftRotate(char arr[], int n, int d) {
    //int temp[d];
    char *temp = (char*)calloc(d, sizeof(char));
    // 0 ~ position까지 array를 temp에 복사
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    // position 이후의 값을 저장
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }
    // temp 값을 추가
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

int main() {
    char arr[] = "ABCDE";
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n = strlen(arr);
    int d = 2; // Number of positions to rotate left
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }

    leftRotate(arr, n, d);

    printf("\nArray after left rotation by %d positions: ", d);
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }

    return 0;
}
