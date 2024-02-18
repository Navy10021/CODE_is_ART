#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateCombinations(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '0';
        path[path_idx + 1] = '\0';
        printf("%s\n", path);
        return;
    }
    
    // Insert '+' between current digit and next digit
    path[path_idx] = str[l];
    path[path_idx + 1] = '+';
    generateCombinations(str, l + 1, r, path, path_idx + 2);
    
    // Insert '-' between current digit and next digit
    //path[path_idx] = str[l];
    path[path_idx + 1] = '-';
    generateCombinations(str, l + 1, r, path, path_idx + 2);
}

void generateAllCombinations(char *str){
    int length = strlen(str);
    // Allocate memory for path which will store the combinations
    char * path = (char*)malloc((2 * length) * sizeof(char));

    generateCombinations(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[100] = "123";
    //scanf("%s", input);

    generateAllCombinations(input);
    return 0;
}
