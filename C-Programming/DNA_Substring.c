#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 11  // 10 characters + '\0'

struct Sequence {
    char value[MAX_LEN];
    int count;
};

struct Sequence* findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    if (len < 10) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100;
    struct Sequence* result = (struct Sequence*)malloc(capacity * sizeof(struct Sequence));
    int resultSize = 0;

    for (int i = 0; i <= len - 10; ++i) {
        char current[MAX_LEN];
        strncpy(current, s + i, 10);
        current[10] = '\0';

        int found = 0;
        for (int j = 0; j < resultSize; ++j) {
            if (strcmp(current, result[j].value) == 0) {
                result[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (resultSize == capacity) {
                capacity *= 2;
                result = (struct Sequence*)realloc(result, capacity * sizeof(struct Sequence));
            }

            strcpy(result[resultSize].value, current);
            result[resultSize].count = 1;
            resultSize++;
        }
    }

    // Filter the result to include only sequences that occur more than once
    struct Sequence* finalResult = (struct Sequence*)malloc(resultSize * sizeof(struct Sequence));
    int finalSize = 0;

    for (int i = 0; i < resultSize; ++i) {
        if (result[i].count > 1) {
            strcpy(finalResult[finalSize].value, result[i].value);
            finalResult[finalSize].count = result[i].count;
            finalSize++;
        }
    }

    free(result);
    *returnSize = finalSize;
    return finalResult;
}

int main() {
    char* sequence = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    int resultSize;
    struct Sequence* result = findRepeatedDnaSequences(sequence, &resultSize);

    printf("Repeated 10-letter sequences: \n");
    for (int i = 0; i < resultSize; ++i) {
        printf("%s\n", result[i].value);
    }

    free(result);

    return 0;
}