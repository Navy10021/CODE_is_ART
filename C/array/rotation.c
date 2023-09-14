#include <stdio.h>
#include <stdlib.h>

// Function to rotate an array to the left by 'd' positions
void leftRotate(int arr[], int n, int d) {
    //int temp[d];
    int *temp = (int*)calloc(d, sizeof(int));
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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // Number of positions to rotate left
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    leftRotate(arr, n, d);

    printf("\nArray after left rotation by %d positions: ", d);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
