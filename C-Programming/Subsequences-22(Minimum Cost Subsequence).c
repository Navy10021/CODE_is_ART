#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Minimum Code difference Subsequnces.

int diff(char *str){
    int n = strlen(str);

    int cost = 0; 
    for (int i = 1; i < n; i++){
        int curr_cost = abs(str[i] - str[i-1]);
        cost += curr_cost;
    }
    return cost;
}

void backtrack(char* str, int l, int r, char* path, int path_idx, int* min_cost, char** min_cost_subseq){
    if (l == r){
        path[path_idx] = '\0';
        if (strlen(path) > 1){
            int curr_cost = diff(path);
            if (curr_cost < *min_cost){
                *min_cost = curr_cost;
                free(*min_cost_subseq);
                *min_cost_subseq = strdup(path);
            }
        }
        return;
    }
    
    path[path_idx] = str[l];
    backtrack(str, l + 1, r, path, path_idx + 1, min_cost, min_cost_subseq);
    backtrack(str, l + 1, r, path, path_idx, min_cost, min_cost_subseq);
}

void subsequences(char* str){
    int length = strlen(str);
    char* path = (char*)malloc((length + 1) * sizeof(char));
    int min_cost = 10000;
    char* min_cost_subseq = strdup("");

    backtrack(str, 0, length, path, 0, &min_cost, &min_cost_subseq);

    printf("Minimum cost subsequence (Cost) : %s(%d)\n", min_cost_subseq, min_cost);

    free(path);
    free(min_cost_subseq);
}

int main(void){
    char input[100];
    scanf("%s", input);
    subsequences(input);
    return 0;
}
