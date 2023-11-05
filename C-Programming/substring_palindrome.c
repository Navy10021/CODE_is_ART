#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char str[]){
    int st = 0;
    int en = strlen(str)-1;
    while(st < en){
        if (str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}

void printSubstring(const char *str){
    char *substr;
    int len = strlen(str);
    for (int st=0; st < len; st++){
        for (int en=st; en < len; en++){
            //printf("%s\n", str+st);
            substr = (char *)malloc(sizeof(char) * (en-st+2));
            strncpy(substr, str+st, en-st); // start string : str+st / size : en-st
            substr[en-st+1] = '\0';
            if (isPalindrome(substr)){
                printf("%s\n", substr);
            }
        }
    }
}

int main(){
    char input[10] = "banana";
    printSubstring(input);
}
