// Insert masking : #A#B#C#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partition(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        printf("%s\n", path);
        // also front masking 
        char mask = '#';
        char* add_path = (char*)malloc((path_idx + 1) * sizeof(char));
        add_path[0] = mask;
        strcpy(add_path + 1, path);
        printf("%s\n", add_path);
        return;
    }
    
    // include current char str[l]
    path[path_idx] = str[l];
    // include current char and proceed to next proceed
    partition(str, l + 1, r, path, path_idx + 1);
    // Insert masking
    char mask = '#';
    path[path_idx + 1] = mask;
    partition(str, l + 1, r, path, path_idx + 2);
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));

    partition(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[100] = "ABC";
    //scanf("%s", input);

    subsequnces(input);
    return 0;
}