#include <stdio.h>
#include <stdlib.h>

void backtrack(int* set, int target, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        int sum = 0;
        for (int i = 0; path[i] != '\0'; i++){
            sum += path[i] - '0';
        }
        if (sum == target){
            printf("{");
            for (int i = 0; path[i] != '\0'; i++){
                printf("%c, ", path[i]);
            }
            printf("}\n");
        }
        return;
    }
    
    path[path_idx] = set[l] + '0';
    backtrack(set, target, l + 1, r, path, path_idx + 1);
    backtrack(set, target, l + 1, r, path, path_idx);
}

void combinationSum(int* set, int setSize, int target){
    char * path = (char*)malloc((setSize + 1) * sizeof(char));
    backtrack(set, target, 0, setSize, path, 0);
}

int main()
{
    int candidates[] = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;
    
    int candidates_size = sizeof(candidates) / sizeof(candidates[0]);
    combinationSum(candidates, candidates_size, target);
    return 0;
}
