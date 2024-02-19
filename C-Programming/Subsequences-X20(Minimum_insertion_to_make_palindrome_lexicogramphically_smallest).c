// Insert alphabet : #a#b#c#
// Condition 1 : is palindrome
// Condition 2 : Minimum Insertion to build palindrome.
// Condition 3 : Lexicographically Smallest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 100

int is_palindrome(char* str){
    int st = 0;
    int en = strlen(str) -1;
    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

void partition(int* min_size, char** min_palindrome, char* str, int l, int r, char* path, int path_idx, char mask_arr[], int arr_size){
    if (l == r){
        path[path_idx] = '\0';
        // Condition 1 & 2. find minimum size palindrome.
        if (is_palindrome(path)){
            if (strlen(path) < *min_size || (strlen(path) == *min_size && strcmp(path, *min_palindrome) < 0)){
                // Update minimum size and lexicographically smallest palindrome
                *min_size = strlen(path);
                free(*min_palindrome); // Ensure to free previous memory
                *min_palindrome = strdup(path);
            }
        }
        // also front masking 
        for (int i = 0; i < arr_size; i++){
            char* add_path = (char*)malloc((path_idx + 1) * sizeof(char));
            add_path[0] = mask_arr[i];
            strcpy(add_path + 1, path);
            if (is_palindrome(add_path) && (strlen(add_path) < *min_size || (strlen(add_path) == *min_size && strcmp(add_path, *min_palindrome) < 0))){
                *min_size = strlen(add_path);
                free(*min_palindrome); // Ensure to free previous memory
                *min_palindrome = strdup(add_path);
            }
            free(add_path);
        }
        return;
    }
    
    // include current char str[l]
    path[path_idx] = str[l];
    // include current char and proceed to next proceed
    partition(min_size, min_palindrome, str, l + 1, r, path, path_idx + 1, mask_arr, arr_size);
    // Insert masks
    for (int i = 0; i < arr_size; i++){
        path[path_idx + 1] = mask_arr[i];
        partition(min_size, min_palindrome, str, l + 1, r, path, path_idx + 2, mask_arr, arr_size);
    }
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length*2 + 1) * sizeof(char));
    // store minimum palindrome 
    int min_size = INT_MAX;
    char * min_palindrome = strdup("");
    // insert different alphabets.
    char masked_arr[26] = {0};
    for (int i = 0; i < 26; i++){
        masked_arr[i] = i + 'a';
    }    
    int arr_size = sizeof(masked_arr) / sizeof(masked_arr[0]);
    partition(&min_size, &min_palindrome, str, 0, length, path, 0, masked_arr, arr_size);
    
    printf("Minimum Insertion Palindrome : %s (%d)\n", min_palindrome, min_size);

    // clean up 
    free(path);
    free(min_palindrome);
}

int main(void){
    char input[10];
    scanf("%s", input);

    subsequnces(input);
    return 0;
}
