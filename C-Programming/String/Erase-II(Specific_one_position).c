// 1.특정 위치 의 문자 삭제처리 후 반환

void erase(char* str, int position){
    int length = strlen(str);

    if (position < 0 || position >= length){
        printf("Invalid.\n");
        return;
    }

    for (int i = position; i < length - 1; i++){
        str[i] = str[i + 1];
    }

    str[length - 1] = '\0';
}

char* erease2(const char* str, size_t index) {
    if (!str || index >= strlen(str)) {
        return NULL;
    }
	// char *strncpy(char *dest, const char *src, size_t n); : dest(복사된 문자가 저장될 대상 포인터) / src(복사할 문자의 원본을 가르키는 포인터)
    char* new_str = (char*)malloc(strlen(str));  // one less than original length
    strncpy(new_str, str, index);  // Copy up to the index : The number of index. No Null-termination
    strcpy(new_str + index, str + index + 1);  // Copy from index + 1 to end

    return new_str;
}

// 지정된 범위의 문자를 제거 : start부터 length 만큼 삭제
void erase3(char* s, int start, int length) {
    /* Erases length characters from the string, starting at the given index. */
    int i = start;
    while (s[i + length]) {
        s[i] = s[i + length];
        i++;
    }
    s[i] = '\0';
}

int main() {
    char input[50] = "ABCD";
    int tgt = 0;
    erase(input, tgt);
    // For remove_char_at_index
    char* result = erase2("Hello, World!", 7);
    if (result) {
        printf("Test remove_char_at_index: %s\n", result);
        free(result);
    }

    // For erase
    char str[] = "Hello, World!";
    erase(str, 7, 1);
    printf("Test erase: %s\n", str);

		return 0;
}
