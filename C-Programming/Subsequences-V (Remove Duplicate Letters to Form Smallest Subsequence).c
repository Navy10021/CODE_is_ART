/* Remove Duplicate Letters to Form smallest subsequence
 Condition 1 : Lexicograpically smallest
 Condition 2 : No Duplicate(Distinct)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasDuplicateChar(char *str){
    if (strlen(str) > 256){
        return 1;
    }
    int hash[256] = {0};
    for (int i = 0; str[i] != '\0'; i++){
        if (hash[str[i]]){
            return 1;
        }
        hash[str[i]] = 1;
    }
    return 0;
}

void partition(char* new_str, int *max_length, char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        // No duplicate characters
        if (!hasDuplicateChar(path) && strlen(path) >= *max_length){
            *max_length = strlen(path);
            // Store Lexicograpically smallest string
            if (strcmp(new_str, str) == 0){
                strcpy(new_str, path);
            }
            else {
                if(strcmp(path, new_str) <= 0){
                    strcpy(new_str, path);
                }
            }
        }
        return;
    }
    path[path_idx] = str[l];
    // include current char str[l]
    partition(new_str, max_length, str, l + 1, r, path, path_idx + 1);
    // Exclude current char
    partition(new_str, max_length, str, l + 1, r, path, path_idx);
}

void subsequnces(char *str){
    int max_length = 0;
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    char * new_str = (char*)malloc((length + 1) * sizeof(char));
    strcpy(new_str, str);  // Initialization
    
    partition(new_str, &max_length, str, 0, length, path, 0);
    free(path);
    printf("%d\n", length - max_length);
    printf("%s\n", new_str);
    free(new_str);
}

int main(void){
    char input[100];
    scanf("%s", input);
    subsequnces(input);
    return 0;
}