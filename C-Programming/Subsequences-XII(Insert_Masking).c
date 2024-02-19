// Insert masking : A#B#C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partition(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        printf("%s\n", path);
        return;
    }
    // include current char str[l]
    path[path_idx] = str[l];
    // if it's the last character, just proceed without adding masking
    if (l == r - 1){
        partition(str, l + 1, r, path, path_idx + 1);
    }
    else{
        // Not last character, include the current char and add masking
        partition(str, l + 1, r, path, path_idx + 1);
        // Masking
        char masking[2] = {'*', '#'};
        for (int i = 0; i < 2; i++){
            path[path_idx + 1] = masking[i];
            partition(str, l + 1, r, path, path_idx + 2);
        }
    }
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));

    partition(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[100] = "NAVY";
    //scanf("%s", input);
    
    subsequnces(input);
    return 0;
}