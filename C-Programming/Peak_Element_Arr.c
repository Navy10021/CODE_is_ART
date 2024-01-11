#include<stdio.h>

int findPeakElement(int *arr, int arrSize) {
    int maxIdx = 0;

    for (int i = 1; i < arrSize - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
    }

    printf("Peak index: %d && Peak element: %d\n", maxIdx, arr[maxIdx]);

    return maxIdx;
}

int main(void) {
    int nums[7] = {1, 2, 1, 3, 5, 6, 4};
    int numSize = sizeof(nums) / sizeof(nums[0]);

    findPeakElement(nums, numSize);

    return 0;
}