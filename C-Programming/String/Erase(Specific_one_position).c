// 1.특정 위치의 문자 삭제처리 후 반환
char* remove_char_at_index(const char* str, size_t index) {
    if (!str || index >= strlen(str)) {
        return NULL;
    }

    char* new_str = (char*)malloc(strlen(str));  // one less than original length
    strncpy(new_str, str, index);  // Copy up to the index : The number of index. No Null-termination
    strcpy(new_str + index, str + index + 1);  // Copy from index + 1 to end

    return new_str;
}

// 지정된 범위의 문자를 제거 : start부터 length 만큼 삭제
void erase(char* s, int start, int length) {
    /* Erases length characters from the string, starting at the given index. */
    int i = start;
    while (s[i + length]) {
        s[i] = s[i + length];
        i++;
    }
    s[i] = '\0';
}

int main() {
    // For remove_char_at_index
    char* result = remove_char_at_index("Hello, World!", 7);
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
