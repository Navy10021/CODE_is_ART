#include <stdio.h>
#include <string.h>
#include<ctype.h>

int main(){
    char str[10000];
    int alpabet[52];

    for (int i = 0; i < 52; i++){
        alpabet[i] = 0; // fasle;
    }

    scanf("%[^\n]", &str);   // \n이 나올때까지 전부 입력

    for (int i = 0; i < strlen(str); i++){
        
        if (isalpha(str[i]) == 0) continue;

        if ('a' <= str[i] && str[i] <= 'z'){
            alpabet[str[i]-'a'] = 1;
        }
        else if ('A' <= str[i] && str[i] <= 'Z'){
            alpabet[str[i] - 'A' + 26] = 1;
        }
    }

    int sum = 0;
    for (int i=0; i<52; i++){
        sum += alpabet[i];
    }

    printf("%d", sum);

    return 0;
}
