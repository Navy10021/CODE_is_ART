#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parition(char* str, int l, int r, char* path, int path_idx){
    if (l == r) {
        path[path_idx] = '\0';
        printf("%s\n", path);
        return;
    }
    
    // Include 
    path[path_idx] = str[l];
    parition(str, l + 1, r, path, path_idx + 1);
    // Exclude
    parition(str, l + 1, r, path, path_idx);
}

void subsequences(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    parition(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[50] = "ABC";
    subsequences(input);
    return 0;
}