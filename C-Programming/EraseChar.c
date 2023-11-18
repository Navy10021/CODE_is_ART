#include <stdio.h>
#include <string.h>

void removeChar(char * str, char target){
    int len = strlen(str);
    int i, j;

    for (i = 0, j = 0; i < len; i++){
        if (str[i] != target){  // 만약 현재 Char이 target Char이 아니면, 유지.
            str[j++] = str[i];
        }
    }
    
    str[j] = '\0';  // string의 마지막을 NULL값으로 처리.
}

int main(){
    char input[10];
    char tgt;

    printf("Enter a string and target character : ");
    scanf("%s %c", input, &tgt);
   
    removeChar(input, tgt);
    printf("Modified string : %s \n", input);

    return 0;

}
