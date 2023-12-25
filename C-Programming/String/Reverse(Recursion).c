#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str, int st, int en){

    if (st == en){
        return;
    }
    else{
        char temp = str[st];
        str[st] = str[en];
        str[en] = temp;

        reverse(str, st+1, en-1);
    }
}

int main(void){
    char inputStr[20] = "ABCDE";
    int length = strlen(inputStr);
    reverse(inputStr, 0, length - 1);

    printf("%s\n", inputStr);
		return 0;
}
