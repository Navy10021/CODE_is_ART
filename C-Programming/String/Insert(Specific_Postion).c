#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Insert(char * str, int position, char target){
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

char * Insert2(char * str, int position, char addChar){
    size_t length = strlen(str);
    
    if (position < 0 || position > length){
        printf("Invalid.\n");
        return strdup(str);
    }

    char *new_str = (char*)malloc((length+2) * sizeof(char));
    // Copy the characters before the insertion position.
    strncpy(new_str, str, position);
    // Insert the character
    new_str[position] = addChar;
    // Copy the characters after the insertion position
    strcpy(new_str + position + 1, str + position);
    
    return new_str;
}

int main(){
    char myStr[20] = "ABCD";
    int insertPos = 1;
    char insertc = 'X';
    
    Insert(myStr, insertPos, insertc);
    printf("%s\n", myStr);

    char* res = Insert2(myStr, insertPos, insertc);
    printf("%s\n", res);
    free(res);
    
    return 0;
}
