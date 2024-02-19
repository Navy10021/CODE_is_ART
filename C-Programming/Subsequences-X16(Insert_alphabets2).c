// Insert alphabets : A#B#C
// Condition 1 : is Palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // include current char str[l]
    path[path_idx] = str[l];
    // if it's the last character, just proceed without adding masking
    if (l == r - 1){
        partition(str, l + 1, r, path, path_idx + 1);
    }
    else{
        // Not last character, include the current char and add masking
        partition(str, l + 1, r, path, path_idx + 1);
        // Insert A ~ Z alphabets
        for (char c = 'a'; c <= 'z'; c++){
            path[path_idx + 1] = c;
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
    char input[100] = "aaa";
    //scanf("%s", input);
    
    subsequnces(input);
    return 0;
}
