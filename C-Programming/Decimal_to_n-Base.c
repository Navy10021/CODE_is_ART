#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int -> string으로 변환 함수
char reVal(int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A'); // A부터 Z까지 10진수 이상을 표현
}

// string reverse 함수
void reverse(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// num: 변환할 숫자, base: 목표 진수
char* fromDeci(char res[], int base, int inputNum) {
    int index = 0;  // res 배열의 인덱스

    // inputNum이 0이 될 때까지 반복
    while (inputNum > 0) {
        // 나머지를 res에 저장
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    // 결과 문자열을 뒤집어 정확한 순서로 만듦
    reverse(res);

    return res;
}

int main() {
    int num, base;
    char res[100]; // 결과를 저장할 문자열

    printf("Enter the number to convert: ");
    scanf("%d", &num);

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Converted number: %s\n", fromDeci(res, base, num));

    return 0;
}
