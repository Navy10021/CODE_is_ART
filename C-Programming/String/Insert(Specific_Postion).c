#include <stdio.h>
#include <string.h>

void InsertChar(char * str, int position, char target){
    int len = strlen(str);
    
    if (position < 0 || position > len){
        printf("Invalid.\n");
        return;
    }
    // Make room for new char 
    for (int i = len; i > position; i--){
        str[i] = str[i - 1];
    }
    // Insertion
    str[position] = target;
}

int main(){
    char myStr[20] = "ABCD";
    int insertPos = strlen(myStr);
    char insertc = 'X';
    
    InsertChar(myStr, insertPos, insertc);
    printf("%s\n", myStr);
    
    return 0;
}
