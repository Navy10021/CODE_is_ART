#include <stdio.h>

int max_subarr_sum(int * arr, int arr_size){
    int max_sum = 0;
    for (int st = 0; st < arr_size; st++){
        int sum = arr[st];
        for (int en = st + 1; en < arr_size; en++){
            sum += arr[en];
            if (sum > max_sum){
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

// Optimize O(n) 
int max_subarr_sum2(int *arr, int arr_size) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < arr_size; i++) {
        current_sum = (current_sum > 0) ? current_sum + arr[i] : arr[i];
        max_sum = (current_sum > max_sum) ? current_sum : max_sum;
    }

    return max_sum;
}

int main(void) {
    int arr[] = {2, 3, -1, -2, 4, -3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int res = max_subarr_sum2(arr, arr_size);
    printf("%d\n", res);

    return 0;
}