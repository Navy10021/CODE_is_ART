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
        //printf("%s\n", path);
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

    int arr_size = 1 << length; // Allocate space for all potential subsequences
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;

    partition(str, 0, length, path, 0, arr, &arr_idx, used);
    
    // Find maximum length subsequence
    int max_len = 0;
    char *max_subseq = NULL;
    for (int i = 0; i < arr_idx; i++) {
        int curr_len = strlen(arr[i]); // Correctly reference arr[i] here
        if (curr_len > max_len) {
            max_len = curr_len;
            free(max_subseq); // Free previous max_subseq to avoid memory leak
            max_subseq = strdup(arr[i]); // Correctly duplicate arr[i]
        }
        // if same lengt BUT lexicographically smallest subsequence of maximum lengt
        else if(curr_len == max_len && strcmp(arr[i], max_subseq) < 0){
            free(max_subseq);
            max_subseq = strdup(arr[i]);
        }
    }
    
    // Print maximum subsequence and its length
    if (max_subseq != NULL) {
        printf("Subsequence of max length: %s (%d)\n", max_subseq, max_len);
        free(max_subseq); // Ensure to free allocated memory
    } else {
        printf("No valid subsequence found.\n");
    }
    
    // Cleanup
    for (int i = 0; i < arr_idx; i++) {
        free(arr[i]); // Ensure all allocated memory is freed
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