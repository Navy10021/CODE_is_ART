#include <stdio.h>
#include <string.h>

void InsertPoss(char * str, int * positions, int numPos, char target){
    int len = strlen(str);
    for (int i = 0; i < numPos; i++){
        int position = positions[i];

        if (position >= 0 && position <= len){
            for (int j = len; j > position; j--){
                str[j] = str[j - 1];
            }
            str[position] = target;
            len++;  // Increase length for making room
        }
        else{
            printf("Invalid.\n");
        }
    }
}

int main(){
    char myStr[20] = "ABCDE";
    int targetPos[] = {1,3,5};
    int numOfTgt = sizeof(targetPos) / sizeof(targetPos[0]);
    InsertPoss(myStr, targetPos, numOfTgt, 'X');
    
    printf("%s", myStr);
    
    return 0;
}
