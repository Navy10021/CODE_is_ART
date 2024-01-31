#include <stdio.h>

// LeetCode 121. Best time to Buy and Sell Stock

int max_profit(int * prices, int prices_size){
    int profit = 0;
    for (int buy_idx = 0; buy_idx < prices_size; buy_idx++){
        for (int sell_idx = buy_idx + 1; sell_idx < prices_size; sell_idx++){
            if (profit < (prices[sell_idx] - prices[buy_idx])){
                profit = prices[sell_idx] - prices[buy_idx];
            }
        }
    }
    return profit;
}

// Optimize O(n)
int max_profit2(int * arr, int arr_size){
    if (arr_size <= 1){
        return 0;
    }
    int min_price = arr[0];
    int profit = 0;
    
    for (int i = 1; i < arr_size; i++){
        int curr_profit = arr[i] - min_price;
        if(curr_profit > profit){
            profit = curr_profit;
        }
        if (arr[i] < min_price){
            min_price = arr[i];
        }
    }
    return profit;
}

int main(void){
    int arr[] = {7,6,4,3,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    int res = max_profit2(arr, arr_size);
    printf("%d\n", res);
    return 0;
}