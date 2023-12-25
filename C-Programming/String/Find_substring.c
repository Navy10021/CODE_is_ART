// 문자열에서 서브스트링을 처음 발견한 위치의 인덱스를 반환
int find(const char* s, const char* substring) {
    /* Returns the index of the first occurrence of substring in the string. If not found, return -1. */
    char* pos = strstr(s, substring);
    if (pos) {
        return pos - s;
    }
    return -1;
}

// Test bw_find // 위치 찾아서 return
int main() {
    int idx = find("Hello, world!", "world");
    printf("bw_find: %d\n", idx);
		return 0;
}
