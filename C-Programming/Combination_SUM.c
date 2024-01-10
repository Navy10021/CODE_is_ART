#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int start, int target, int* path, int pathSize, int*** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        (*result) = realloc(*result, (*returnSize + 1) * sizeof(int*));
        (*returnColumnSizes) = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
        (*result)[(*returnSize)] = malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++) {
            (*result)[(*returnSize)][i] = path[i];
        }
        (*returnColumnSizes)[(*returnSize)] = pathSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            continue;
        }
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, i, target - candidates[i], path, pathSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    int* path = malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, 0, target, path, 0, &result, returnSize, returnColumnSizes);

    free(path);
    return result;
}

int main() {
    int candidates1[] = {2, 3, 6, 7};
    int target1 = 7;
    int returnSize1, *returnColumnSizes1;

    int** result1 = combinationSum(candidates1, sizeof(candidates1) / sizeof(candidates1[0]), target1, &returnSize1, &returnColumnSizes1);

    // Printing the result for Example 1
    for (int i = 0; i < returnSize1; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes1[i]; j++) {
            printf("%d", result1[i][j]);
            if (j < returnColumnSizes1[i] - 1) {
                printf(",");
            }
        }
        printf("]\n");
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);

    // Similar code for other examples

    return 0;
}