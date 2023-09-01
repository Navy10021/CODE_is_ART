#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // 입력 받을 문자열
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 문자열을 "."로 분할
    char *token = strtok(input, ".");
    while (token != NULL) {
        printf("분할된 부분: %s\n", token);
        token = strtok(NULL, ".");
    }

    return 0;
}
