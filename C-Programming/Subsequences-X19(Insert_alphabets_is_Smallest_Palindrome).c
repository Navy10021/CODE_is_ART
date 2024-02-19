/* Minimum insertion to make palindrome
   Insert alphabet : abc -> a#b#c#
   Condition 1 : is palindrome
   Condition 2 : Minimum insertion
   Condition 3 : if same length, return the Lexicographically smallest
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 100

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

void partition(int* min_size, char** min_palindrome, char* str, int l, int r, char* path, int path_idx, char alpha_arr[], int arr_size){
    if (l == r){
        path[path_idx] = '\0';
        // Codition 1.
        if (is_palindrome(path)){
            // Condition 2 & 3.
            if (strlen(path) < *min_size || (strlen(path) == *min_size && strcmp(path, *min_palindrome) < 0)){
                *min_size = strlen(path);
                free(*min_palindrome);
                *min_palindrome = strdup(path);
            }
        }
        return;
    }
    
    // Include current char str[l]
    path[path_idx] = str[l];
    // Include current char and proceed to next proceed 
    partition(min_size, min_palindrome, str, l + 1, r, path, path_idx + 1, alpha_arr, arr_size);
    // Insert alphabets and proceed to next proceed 
    for (int i = 0; i < arr_size; i++){
        path[path_idx + 1] = alpha_arr[i];
        partition(min_size, min_palindrome, str, l + 1, r, path, path_idx + 2, alpha_arr, arr_size);
    }
}

void subsequences(char * str){
    int length = strlen(str);
    char* path = (char*)malloc((length*2 + 1) * sizeof(char));
    int min_size = STR_MAX;
    char* min_palindrome = strdup("");
    // Insert lower alphabet
    char alpha_arr[26] = {0};
    for (int i = 0; i < 26; i++){
        alpha_arr[i] = i + 'a';
    }
    int arr_size = sizeof(alpha_arr) / sizeof(alpha_arr[0]);
    
    // Let's make palindrome given string
    partition(&min_size, &min_palindrome, str, 0, length, path, 0, alpha_arr, arr_size);
    
    printf("Minimum Insertion Palindrome (length) : %s (%d)\n", min_palindrome, min_size);

    // Clean up 
    free(path);
    free(min_palindrome);
}

int main(void){
    char input[10];
    scanf("%s", input);
    
    subsequences(input);
    return 0;
}