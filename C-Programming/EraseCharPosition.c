#include <stdio.h>
#include <string.h>

void removePos(char * str, int target){
    int len = strlen(str);
    int i, j;

    for (i = 0, j = 0; i < len; i++){
        if (i != target){  // 만약 현재 Char Index가 target Index가 아니면, 유지.
            str[j++] = str[i];
        }
    }
    
    str[j] = '\0';  // string의 마지막을 NULL값으로 처리.
}

int main(){
    char input[10];
    int position;

    printf("Enter a string and target position : ");
    scanf("%s %d", input, &position);
   
    removePos(input, position);
    printf("Modified string : %s \n", input);

    return 0;

}
