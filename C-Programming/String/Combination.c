#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void genCombination(char *str, char *buffer, int start, int depth, int size) {
    int len = strlen(str);
    if (depth == 0) { // 해당 조합의 길이(depth)와 일치하면 return
        for (int j = 0; j < size; j++) {
            printf("%c", buffer[j]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < len; i++) {
        buffer[depth - 1] = str[i]; // 해당 문자열의 Char를 array(buffer)에 저장
        genCombination(str, buffer, i + 1, depth - 1, size);
    }
}

int main(void) {
    char inputStr[] = "abcd";
    int length = strlen(inputStr);

    for (int depth = 1; depth <= length; depth++) { // 1 ~ length까지 모든 길이의 조합 생성
        char combinationArr[depth];                  // 조합을 저장할 Array 생성.
        genCombination(inputStr, combinationArr, 0, depth, depth);
    }
    return 0;
}
