#include <stdio.h>
#include <string.h>

void compressString(char *input) {
    int len = strlen(input);
    int compressedIndex = 0;

    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        int count = 1;

        while (i + 1 < len && input[i + 1] == currentChar) {
            i++;
            count++;
        }

        input[compressedIndex++] = currentChar;
        if (count > 1) {
            char countStr[5]; // Assuming count won't exceed 9999
            snprintf(countStr, sizeof(countStr), "%d", count);
            int countLen = strlen(countStr);

            for (int j = 0; j < countLen; j++) {
                input[compressedIndex++] = countStr[j];
            }
        }
    }

    input[compressedIndex] = '\0';
}

int main() {
    char input[] = "aabcccccaaa";
    printf("Original string: %s\n", input);
    compressString(input);
    printf("Compressed string: %s\n", input);

    return 0;
}
