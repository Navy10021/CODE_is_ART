#include <stdio.h>
#include <string.h>

// 1. 특정 문자 변경
void replaceChar(char * str, char target, char replacement){
    int len = strlen(str);
    
    for (int i = 0; i < len; i++){
        if (str[i] == target){
            str[i] = replacement;
        }
    }
}

// 2. 특정 인덱스의 문자 변경
void replacePos(char *str, int position, char replacement){
    int len = strlen(str);
    
    if (position >= 0 && position < len){
        str[position] = replacement;
    }
    else{
        printf("Invalid position.\n");
    }
}

int main(){
    char input[20] = "Lee Yoon Seop";
    char tgt = 'o';
    char replacement = 'X';
    
    printf("Original string : %s\n", input);
    replaceChar(input, tgt, replacement);
    replacePos(input, 2, ' ');
    printf("After modified : %s\n", input);
    return 0;
}
