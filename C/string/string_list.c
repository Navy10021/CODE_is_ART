#include <stdio.h>
#include <string.h>

int main(){
    // Declare an array of pointers to string
    char *strings[5];
    //char strings[5][100];   // 단어개수 X 단어길이

    // strdup(S) : 문자 S를 복사하고, 복사된 문자열을 가르키는 포인터 반환 
    strings[0] = strdup("LEE");
    //strcpy(strings[0], "LEE");  // 또는 복사하는 형태 가능
    strings[1] = strdup("YOON");
    strings[2] = strdup("SEOP");
    strings[3] = strdup("Good");
    strings[4] = strdup("Boy");

    for (int i=0; i<5; i++){
        printf("%s  ", strings[i]);
        free(strings[i]);
    }
    return 0;
}
