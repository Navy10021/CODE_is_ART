#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    int st_idx, en_idx;
    
    scanf("%s", str);
    st_idx = 0;
    en_idx = strlen(str) - 1;

    char res[3];
    res[0] = str[st_idx];
    res[1] = str[en_idx];
    //res[2] = "\0";

    printf("%s\n", res);
    
    printf("%c%c\n", str[st_idx], str[en_idx]);

    return 0;
}
