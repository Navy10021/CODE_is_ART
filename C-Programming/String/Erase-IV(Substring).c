// 문자열내 substring을 삭제하는 함수

#include <stdio.h>
#include <string.h>

// 문자열에서 특정 서브스트링을 삭제하는 함수
void remove_substring(char* str, const char* substring) {
    char* match = strstr(str, substring); // 서브스트링을 찾음

    // 서브스트링을 찾았고 삭제할 수 있는 경우
    while (match != NULL) {
        memmove(match, match + strlen(substring), strlen(match + strlen(substring)) + 1);
        match = strstr(str, substring); // 다음 서브스트링을 찾음
    }
}

int main() {
    char text[] = "Hello, world! Hello, universe!";
    const char* substring = "Hello, ";
    
    printf("원본 문자열: %s\n", text);
    
    remove_substring(text, substring);
    
    printf("서브스트링 삭제 후: %s\n", text);
    
    return 0;
}
