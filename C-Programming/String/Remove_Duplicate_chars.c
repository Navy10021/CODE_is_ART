#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicates(char * str){
    int len = strlen(str);

    if (len <= 1){
        return;     // No duplicate
    }

    int idx = 0;    // Index for the non-duplicate characters

    for (int i = 0; i < len; i++){
        int j;
        for (j = 0; j < idx; j++){
            if (str[i] == str[j]){  
                break;
            }
        }
        if (j == idx){  // If NOT encountered, ADD it the result
            str[idx++] = str[i];
        }
    }
    str[idx] = '\0';
}

int main(){
    char inputStr[20];
    scanf("%s", inputStr);

    printf("Original string : %s\n", inputStr);
    removeDuplicates(inputStr);
    printf("Modified string : %s\n", inputStr);

    return 0;
}
