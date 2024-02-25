// 지정된 범위의 문자를 제거 : start index ~ length길이 만큼 삭제
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
