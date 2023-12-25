#include <stdio.h>
#include <string.h>

// 문자열(string) 내 특정 위치(positions)의 문자(char)를 삭제하는 함수 
void erasePoss(char * str, int * positions, int numPos){
    int len = strlen(str);
    int eraseCount = 0;
    
    for (int i = 0; i < len; i++){
        if (eraseCount < numPos && i == positions[eraseCount]){
            // Skip!
            eraseCount++;
        }
        else{
            // Copy non-erased chars to new positions
            str[i - eraseCount] = str[i];
        }
    }
    str[len - eraseCount] = '\0';
}

int main(){
    char input[20];
    int numPos;
    int pos;
    int targetPos[20];
    scanf("%s", input);
    scanf("%d", &numPos);
    for (int i = 0; i < numPos; i++){
        scanf("%d", &pos);
        targetPos[i] = pos;
    }
    //int numPos = sizeof(targetPos) / sizeof(targetPos[0]);
    printf("Oringinal string : %s\n", input);
    erasePoss(input, targetPos, numPos);
    printf("Modified string : %s\n", input);
    return 0;
}
