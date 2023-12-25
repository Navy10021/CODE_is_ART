#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// result array에 combination 을 저장
void genCombinations(char *str, char *buffer, int start, int depth, char **result, int *count) {
    int len = strlen(str);

    if (depth == 0) { // 요구하는 길이와 일치하면 저장
        // Allocate memory for the result and copy the combination
        result[*count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(result[*count], buffer);
        (*count)++;
        return;
    }

    for (int i = start; i < len; i++) {
        buffer[depth - 1] = str[i];  // 해당 문자열의 문자 저장
        genCombinations(str, buffer, i + 1, depth - 1, result, count);
    }
}

int main() {
    char input[] = "ABC";
    int length = strlen(input);

    // Calculate the number of combinations (2^n)
    int numCombinations = 1 << length;

    // Allocate memory for the array to store combinations
    char **combinations = malloc(numCombinations * sizeof(char *));
    int count = 0;

    for (int depth = 1; depth <= length; depth++) {
        char combinationBuffer[depth + 1];
        combinationBuffer[depth] = '\0'; // NULL-terminate

        printf("Combination of length: %d\n", depth);
        genCombinations(input, combinationBuffer, 0, depth, combinations, &count);
        printf("\n");
    }

    // Print or use the stored combinations
    for (int i = 0; i < count; i++) {
        printf("%s\n", combinations[i]);
        // If you want to use the combinations in your program, you can access them through the combinations array.
    }

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(combinations[i]);
    }
    free(combinations);

    return 0;
}
