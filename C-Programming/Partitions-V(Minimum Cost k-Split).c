#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

#define MAX_LENGTH 100 // Maximum length of the input string

int diff(char *str){
    int n = strlen(str);
    int cost = 0;
    for (int i = 1; i < n; i++){
        int curr_cost = abs(str[i] - str[i-1]);
        cost += curr_cost;
    }
    return cost;
}

// Declare global variables to store the best partition and its details
char best_partition[MAX_LENGTH][MAX_LENGTH];
int best_partition_size = 0;

void backtrack(int* min_cost, char* str, int st, int n, int k, int curr_partitions, char arr[][n+1], int arr_idx){
    if (st >= n){
        if (curr_partitions == k){
            int cost_sum = 0;
            for (int i = 0; i < arr_idx; i++){
                printf("%s | ", arr[i]);
                cost_sum += diff(arr[i]);
            }
            printf("cost : %d\n", cost_sum);
            if (cost_sum < *min_cost){
                *min_cost = cost_sum;
                // Update the best_partition with the current partition configuration
                best_partition_size = arr_idx;
                for (int i = 0; i < arr_idx; i++){
                    strcpy(best_partition[i], arr[i]);
                }
            }
        }
        return;
    }
    for (int en = st; en < n; en++){
        int len = en - st + 1;
        strncpy(arr[arr_idx], str + st, len);
        arr[arr_idx][len] = '\0';

        backtrack(min_cost, str, en + 1, n, k, curr_partitions + 1, arr, arr_idx + 1);
    }
}

void partition(char* str, int k){
    int len = strlen(str);
    char arr[len][len + 1];
    int min_cost = INT_MAX;

    backtrack(&min_cost, str, 0, len, k, 0, arr, 0);
    
    // Print the best partition and its cost
    printf("Minimum cost %d-partition : %d\n", k, min_cost);
    printf("Best partition:\n");
    for (int i = 0; i < best_partition_size; i++){
        printf("%s | ", best_partition[i]);
    }
}

int main(void){
    char input[MAX_LENGTH];
    int k;
    scanf("%s %d", input, &k);
    partition(input, k);

    return 0;
}
