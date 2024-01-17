#include <stdio.h>
#include <stdlib.h>

// LeetCode 605. Can Place Flowers: flowers can't be planted in adjacent plots
int canPlaceFlower(int *arr, int arrSize, int n) {
    for (int i = 1; i < arrSize - 1; i++) {
        if (arr[i] == 0 && arr[i - 1] != 1 && arr[i + 1] != 1) {
            arr[i] = 1;
            n--;
        }
    }
    return n == 0;
}

int main(void) {
    int size;
    int num;
    int flowers;
    
    // Input size and elements of the array
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }

    // Input the number of flowers to be planted
    scanf("%d", &flowers);

    // Check if flowers can be placed
    int res = canPlaceFlower(arr, size, flowers);

    // Output the result
    printf("%d", res);

    // Free allocated memory
    free(arr);
    return 0;
}