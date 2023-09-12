#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((text[i] - base + shift) % 26) + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26));
}

int main() {
    char message[] = "Hello, World!";
    int shift = 3;

    printf("Original Message: %s\n", message);

    encrypt(message, shift);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, shift);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
