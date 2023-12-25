#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* rotate_string(const char* string, int n) {
    int length = strlen(string);
    char* result = (char*)malloc(length + 1);
    if (!result) return NULL;  // memory allocation failed

    strncpy(result, string + n, length - n);
    strncpy(result + length - n, string, n);
    result[length] = '\0';

    return result;
}

bool cycle_string(const char* compare, const char* string) {
    int n = strlen(string);

    if (strlen(compare) != n) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        char* rotated = rotate_string(string, i);
        bool isEqual = strcmp(rotated, compare) == 0;
        free(rotated);
        if (isEqual) {
            return true;
        }
    }
    return false;
}
