#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str){
    int len = strlen(str);
    int st = 0;
    int en = len - 1;

    while(st < en){
        // swap
        char temp = *(str + st);
        *(str + st) = *(str + en);
        *(str + en) = temp;

        st++;
        en--;
    }
}

int main(void){
    char inputStr[20] = "ABCDE";
    reverse(inputStr);

    printf("%s\n", inputStr);
		
		return 0;
}
