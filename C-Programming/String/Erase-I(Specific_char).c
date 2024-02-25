// ㅈ특정 문자를 삭제하는 함수
void remove_char(char* str, char target) {
    int i, j = 0
    int length = strlen(str);

    for (i = 0; i < length; i++) {
        if (str[i] != target) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
