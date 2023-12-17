#include <stdio.h>
#include <string.h>

void removeSubstring(char *str, const char *sub) {
    int len = strlen(sub); // string search : If substring is found, strstr() returns pointer to the first occurrence of the substring
    while ((str = strstr(str, sub))) {
        // memory copy function : overlapping memory. Shift the remaining portion of the string to overwrite the substring.
        memmove(str, str + len, strlen(str + len) + 1);
    }
}

int main() {
    /*
    const char *str = "Hello, World";
    const char *sub = "World";
    const char *res = strstr(str, sub);
    printf("%s\n", res);

    char src[] = "Hello, World";
    char dst[20];
    int numbytes = strlen(src) + 1; // NUll-terminate
    memmove(dst, src, numbytes);
    printf("%s\n", dst);
    */
    
    char originalString[] = "Hello, remove 'remove' from this string.";
    const char substring[] = "remove";

    removeSubstring(originalString, substring);

    printf("Modified String: %s\n", originalString);

    return 0;
}