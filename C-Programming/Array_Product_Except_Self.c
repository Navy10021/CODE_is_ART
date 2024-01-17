#include <stdio.h>
#include <stdlib.h>

// LeetCode 238. Product of array Except self
void productExceptSelf(int *arr, int arrSize) {
    int mul = 1;
    int is_in_zero = 0;
    int zero_arr[arrSize];
    for(int i=0; i<arrSize; i++){
        zero_arr[i]=0;
    }

    // Calculate the product excluding zeros and track the positions of zeros
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != 0) {
            mul *= arr[i];
        } else {
            is_in_zero = 1;
            zero_arr[i] = 1;
        }
    }

    if (!is_in_zero) {
        // No zero in the array, directly calculate the result
        for (int i = 0; i < arrSize; i++) {
            arr[i] = mul / arr[i];
        }
    } else {
        // There is at least one zero in the array
        int zero_mul = 1;

        // Calculate the product excluding zeros
        for (int i = 0; i < arrSize; i++) {
            if (!zero_arr[i]) {
                zero_mul *= arr[i];
            }
        }

        // Set the result for each zero position
        for (int i = 0; i < arrSize; i++) {
            if (zero_arr[i]) {
                arr[i] = zero_mul;
            } else {
                arr[i] = 0;
            }
        }
    }

    // Print the resulting array
    printf("{");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("}");
}

int main(void) {
    int inp[5] = {-1,1,0,3,-3};
    productExceptSelf(inp, 5);

    return 0;
}