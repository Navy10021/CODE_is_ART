#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 지정된 위치에 다른 문자열(substring)을 삽입
void insert(char* s, int index, const char* substring) {
    /* Inserts the substring into the string at the specified index. */
    int original_length = strlen(s);
    int substring_length = strlen(substring);
    for (int i = original_length; i >= index; i--) {
        s[i + substring_length] = s[i];
    }
    strncpy(s + index, substring, substring_length);
}

int main() {
// Test bw_insert // 문자열 삽입
    char ins[50] = "Helloworld!";
    insert(ins, 5, ", ");
    printf("insert: %s\n", ins);
    return 0;
}
