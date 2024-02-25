#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// LeetCode 1930. Unique Length Palindromic Subsequences.
int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

int seen(char **arr, int arr_idx, char *tgt){
    for (int i = 0; i < arr_idx; i++){
        if (strcmp(arr[i], tgt) == 0){
            return 1;
        }
    }
    return 0;
}

void partition(char** arr, int* arr_idx, char* str, int l, int r, char* path, int path_idx, int k){
    if (l == r){
        path[path_idx] = '\0';
        // 팰린드롬이면서 길이가 k인 경우 저장(중복 제거)
        if (isPalindrome(path) && strlen(path) == k && !seen(arr, *arr_idx, path)){
            arr[*arr_idx] = strdup(path);
            (*arr_idx)++;
            return;
        }
        return;
    }
    // Include
    path[path_idx] = str[l];
    partition(arr, arr_idx, str, l + 1, r, path, path_idx + 1, k);
    // Exclude
    partition(arr, arr_idx, str, l + 1, r, path, path_idx, k);
}

void PalindromicSubsequence(char * str, int k){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    int arr_size = 1 << length;
    char** arr = malloc(arr_size * sizeof(char*));
    int arr_idx = 0;
    // Subsequnce를 생성
    partition(arr, &arr_idx, str, 0, length, path, 0, k);

    for (int i = 0; i < arr_idx; i++){
        printf("%s, ", arr[i]);
    }

    // Clean up
    for (int i = 0; i < arr_idx; i++){
        free(arr[i]);
    }
    free(path);
    free(arr);
}


int main(void){
    char input[50] = "bbcbaba";
    int k = 3;
    PalindromicSubsequence(input, k);

    return 0;
}




