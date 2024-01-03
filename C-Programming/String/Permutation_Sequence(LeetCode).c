#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 60. Permutation Sequence.

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(char* str, int st, int en) {
    for (int i = st; i < en; i++) {
        if (str[i] == str[en])
            return 0;
    }
    return 1;
}

char* genPerm(char *str, int st, int length, int k, int* currentCount) {
    if (st == length - 1) {
        (*currentCount)++;
        if (*currentCount == k) {
            // If count matches required permutation, return the result
            char *result = (char*)malloc(sizeof(char) * (length + 1));
            strcpy(result, str);
            return result;
        }
    }
    
    for (int i = st; i < length; i++) {
        if (shouldSwap(str, st, i)) {
            swap(&str[st], &str[i]);
            char* result = genPerm(str, st + 1, length, k, currentCount);
            swap(&str[st], &str[i]);
            
            // If result is found, return it
            if (result != NULL) {
                return result;
            }
        }
    }

    return NULL;  // No result found
}

char* getPermutation(int n, int k) {
    char *str = (char*)malloc(sizeof(char) * (n + 1));
    int strIdx = 0;
    
    for (int i = 0; i < n; i++) {
        str[strIdx++] = i + 1 + '0';
    }
    
    str[strIdx] = '\0';
    
    int currentCount = 0;
    char* res = genPerm(str, 0, n, k, &currentCount);

    free(str);  // Free the original string
    
    return res;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    char* res = getPermutation(N, K);
    printf("%s", res);

    free(res);  // Free the result
    
    return 0;
}