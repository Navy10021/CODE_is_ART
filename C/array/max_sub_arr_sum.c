#include <stdio.h>

int maxSubarraySum(int nums[], int size) {
    if (size == 0) {
        return 0;
    }

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < size; i++) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : (currentSum + nums[i]);
        maxSum = (maxSum > currentSum) ? maxSum : currentSum;
    }

    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = maxSubarraySum(arr, size);
    printf("%d\n", result); // Output will be 6
    return 0;
}
