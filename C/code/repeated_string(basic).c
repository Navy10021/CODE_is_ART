#include <stdio.h>
#include <string.h>

int main(){
    int R;  // 반복횟수
    char str[100];

    scanf("%d %s", &R, str);
    
    for (int i = 0; i < strlen(str); i++){
        for (int j = 0; j < R; j++) printf("%c", str[i]);
    
    //printf("\n");
    }
}
