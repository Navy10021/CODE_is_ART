#include <stdio.h>
#include <string.h>

void compressString(const char *input) {
    int length = strlen(input);
    int count = 1;

    for (int i = 0; i < length; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            printf("%c%d", input[i], count);
            count = 1;
        }
    }
    printf("\n");
}

int main() {
    const char *input = "aaabbbcc";
    printf("Original String: %s\n", input);
    printf("Compressed String: ");
    compressString(input);
    return 0;
}
