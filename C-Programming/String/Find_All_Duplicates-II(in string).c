#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String에서 중복된 char를 찾는 함수(해쉬 이용)

void findDuplicates(char *str) {
    int length = strlen(str);

    int hash[256] = {0};
    
    for (int i = 0; i < length; i++) {
        hash[str[i]]++;
    }

    char* duplicate_char = (char*)malloc(length + 1 * sizeof(char));
    int char_idx = 0;

    for (int i = 0; i < 256; i++) {
        if (hash[i] > 1) {
            duplicate_char[char_idx++] = i;
        }
    }
    duplicate_char[char_idx] = '\0';
    printf("%s\n", duplicate_char);
    free(duplicate_char);
}

int main(void) {
    char arr[100] = "aabbcdeef";

    findDuplicates(arr);

    return 0;
}
