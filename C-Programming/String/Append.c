#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# 주어진 string에 char 1개를 뒤에 추가하는 함수.

void Append(char * str, char oneChar){
    size_t length = strlen(str);
    str[length] = oneChar;
    str[length + 1] = '\0';
}


char* Append2(char * str, char oneChar){
    size_t length = strlen(str);

    // Memory allocation
    char *new_str = (char*)malloc((length + 2) * sizeof(char));

    // Copy the original string
    strcpy(new_str, str);

    // Append Char
    new_str[length] = oneChar;
    new_str[length + 1] = '\0';

    return new_str;
}

int main(void){
    char input[50] = "abcd";
    Append(input, 'A');
    printf("%s\n", input);

    char* res = Append2(input, 'B');
    printf("%s\n", res);
    free(res);
    return 0;
}
