#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int max_len;
    scanf("%d", &max_len);
    getchar();      // '\n' 삭제
    // str 변수의 메모리 동적 할당 : 주소값을 리턴.
    char *str = (char *)malloc(sizeof(char) * (max_len+1));
    
    printf("Enter your string : ");
    fgets(str, max_len+1, stdin);       // fgets(str, sizeof(str), stdin)
    str[strlen(str)-1] = 0;
    
    printf("%s\n", str);
    printf("Reversed String.\n");
    
    for (int i = max_len; i > 0; i--){
        if (str[i] == ' '){
            printf("%s ", &str[i+1]);   // 주소값으로 출력.
            str[i] = 0;                 // NUL 처리.
        }
    }
    printf("%s ", &str[0]);             // 주소값으로 출력.
    free(str);
    return 0;
}
