#include <stdio.h>

// LeetCode 209. minimum size subarray sum

int min_subarr(int tgt, int * arr, int arr_size){
    int min_len = arr_size; 
    for (int st = 0; st < arr_size; st++){
        int sum = arr[st];
        for (int en = st + 1; en < arr_size; en++){
            sum += arr[en];
            if (sum == tgt && (en - st + 1) < min_len){
                min_len = en - st + 1;
            }
        }
    }
    return min_len;
}

// Optimize O(n) 
int min_subarr2(int tgt, int * arr, int arr_size){
    int min_len = arr_size + 1;
    int st = 0;
    int en = 0;
    int sum = 0;
    
    // add element
    while (en < arr_size){
        sum += arr[en++];
        // minimize length
        while (sum >= tgt){
            if (en - st < min_len){
                min_len = en - st;
            }
            sum -= arr[st++];
        }
    }
    return (min_len == arr_size + 1) ? 0 : min_len;
}

int main(void){
    int arr[] = {2,3,1,2,4,3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int res = min_subarr2(target, arr, arr_size);
    printf("%d\n", res);
    return 0;
}