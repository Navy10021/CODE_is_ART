#include <stdio.h>
#include <ctype.h>

int main(void){
    char ch = '5';

    if (isdigit(ch)){
        printf("is a digit.\n", ch);
    }
    
    return 0;
}
