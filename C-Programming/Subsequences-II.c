#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_adj(const char *str, int len) {
    for (int i = 1; i < len; i++) {
        if (abs(str[i] - str[i - 1]) == 1) {
            return 1;
        }
    }
    return 0;
}

void partition(char* str, int index, int length, char* path, int path_len, char** arr, int* arr_idx, int* used) {
    if (path_len > 0 && !is_adj(path, path_len)) {
        path[path_len] = '\0';
        for (int i = 0; i < *arr_idx; i++) {
            if (strcmp(arr[i], path) == 0) {
                // Duplicate found, do not add or print
                return;
            }
        }
        // Add unique subsequence
        arr[*arr_idx] = strdup(path);
        printf("%s\n", path);
        (*arr_idx)++;
    }

    for (int i = index; i < length; i++) {
        if (used[i]) continue; // Skip used characters to maintain uniqueness
        // if current character is not used char add path.
        used[i] = 1;
        path[path_len] = str[i];
        partition(str, i + 1, length, path, path_len + 1, arr, arr_idx, used);
        used[i] = 0; // backtrack
    }
}

void subsequences(char *str) {
    int length = strlen(str);
    char* path = malloc((length + 1) * sizeof(char));
    int* used = calloc(length, sizeof(int));

    int arr_size = 1 << length;
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;

    partition(str, 0, length, path, 0, arr, &arr_idx, used);

    for (int i = 0; i < arr_idx; i++) {
        free(arr[i]);
    }
    free(path);
    free(arr);
    free(used);
}

int main(void) {
    char input[] = "banana";
    subsequences(input);
    return 0;
}