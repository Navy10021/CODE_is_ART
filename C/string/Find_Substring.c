#include <stdio.h>
#include <string.h>

int findSubstring(const char *haystack, const char *needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i; // Substring found at index i
        }
    }
    
    return -1; // Substring not found
}

int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    
    int index = findSubstring(haystack, needle);
    
    if (index != -1) {
        printf("Substring found at index %d.\n", index);
    } else {
        printf("Substring not found.\n");
    }
    
    return 0;
}
