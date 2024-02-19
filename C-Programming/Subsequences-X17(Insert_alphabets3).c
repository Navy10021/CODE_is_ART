// Insert alphabets : #A#B#C#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partition(char* str, int l, int r, char* path, int path_idx, char mask_arr[], int arr_size){
    if (l == r){
        path[path_idx] = '\0';
        printf("%s\n", path);
        // also front masking 
        for (int i = 0; i < arr_size; i++){
            char* add_path = (char*)malloc((path_idx + 1) * sizeof(char));
            add_path[0] = mask_arr[i];
            strcpy(add_path + 1, path);
            printf("%s\n", add_path);
            free(add_path);
        }
        return;
    }
    
    // include current char str[l]
    path[path_idx] = str[l];
    // include current char and proceed to next proceed
    partition(str, l + 1, r, path, path_idx + 1, mask_arr, arr_size);
    // Insert masks
    for (int i = 0; i < arr_size; i++){
        path[path_idx + 1] = mask_arr[i];
        partition(str, l + 1, r, path, path_idx + 2, mask_arr, arr_size);
    }
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    // insert different alphabets.
    char masked_arr[26] = {0};
    for (int i = 0; i < 26; i++){
        masked_arr[i] = i + 'a';
    }    
    int arr_size = sizeof(masked_arr) / sizeof(masked_arr[0]);
    partition(str, 0, length, path, 0, masked_arr, arr_size);
    free(path);
}

int main(void){
    char input[10] = "a";
    //scanf("%s", input);

    subsequnces(input);
    return 0;
}
