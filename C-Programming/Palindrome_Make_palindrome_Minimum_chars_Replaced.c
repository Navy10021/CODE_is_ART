#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Minimum number of characters to be replaced to make given string palindrome.

int replace_palindrome(char str[]){
    int st = 0;
    int en = strlen(str) - 1;
    int count = 0;

    while (st < en){
        if (str[st] != str[en]){
            count++;
            if (str[st] < str[en])
                str[en] = str[st];
            else 
                str[st] = str[en];
        }
        st++;
        en--;
    }
    printf("Replaced string : %s\n", str);
    printf("The number of replace : %d\n", count);
    return count;
}

int main(void){
    char input[50];
    scanf("%s", input);
    char* new_input = strdup(input);
    int res = replace_palindrome(new_input);

    printf("%s", input);
    free(new_input);
    return 0;
}
