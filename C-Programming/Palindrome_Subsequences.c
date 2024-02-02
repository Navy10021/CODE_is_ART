#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Palindrome Partition == subsequnces

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

void partition(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        if (isPalindrome(path)){
            printf("%s\n", path);
        }
        return;
    }
    path[path_idx] = str[l];
    partition(str, l + 1, r, path, path_idx + 1);
    partition(str, l + 1, r, path, path_idx);
}

int main(void){
    char input[100];
    scanf("%s", input);
    
    int length = strlen(input);
    char * path = (char*)malloc((length + 1) * sizeof(char));
    partition(input, 0, length, path, 0);
    free(path);
    return 0;
}

