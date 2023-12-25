#include <stdio.h>
#include <string.h>

void rotateStr(char * str){
    int len = strlen(str);
    char temp = str[0];

    for (int i = 0; i < len - 1; ++i){
        str[i] = str[i + 1];
    }

    str[len - 1] = temp;
}

int isSubstring(const char* str, const char* substr){
    while(*str){
        const char * a = str;
        const char * b = substr;

        while (*a && *b && (*a == *b)){
            a++;
            b++;
        }

        if (!*b){
            return 1;
        }
        str++;
    }
    return 0;
}

void rotateAndPrint(char * str1, char * str2, int str1_len, int * res){
    for (int i = 0; i < str1_len; i++){
        rotateStr(str1);
        if (isSubstring(str1, str2)){
            *res += 1;
            break;
        }
    }
}

int main(void){
    char input[100];
    scanf("%s", input);
    char input2[100];
    scanf("%s", input2);
    int result = 0;

    rotateAndPrint(input, input2, strlen(input), &result);
    printf("%d", result);

    return 0;

}
