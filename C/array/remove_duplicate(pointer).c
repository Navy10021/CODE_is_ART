#include <stdio.h>
#include <string.h>

void remove_duplicate(char *str) {
    // Make hash table
    int hash[26];
    for (int i = 0; i < 26; i++) {
        hash[i] = 0;
    }

    // Insert alphabets using pointers
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            hash[*str - 'a']++;
        }
        str++; // Move the pointer to the next character
    }

    // Print unique characters using pointers
    for (int i = 0; i < 26; i++) {
        if (hash[i] != 0) {
            printf("%c", i + 'a');
        }
    }
}

int main() {
    char string[] = "aaabbbcccddd";
    remove_duplicate(string);
}
