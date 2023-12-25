#include <stdio.h>
#include <string.h>

void repalcePoss(char * str, int * positions, int numPos, char replacement){
    int len = strlen(str);
    
    for (int i = 0; i < numPos; i++){
        int pos = positions[i];
        
        if (pos >= 0 && pos < len){
            str[pos] = replacement;
        }
        else{
            printf("Invalid position %d\n", pos);
        }
    }
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
    char replacement = ' ';
    
    printf("Oringinal string : %s\n", input);
    repalcePoss(input, targetPos, numPos, replacement);
    printf("Modified string : %s\n", input);
    return 0;
}
