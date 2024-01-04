#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicateLetters(char* str) {
    int count[256] = {0};
    bool inStack[256] = {false};
    char stack[256];
    int stackTop = -1;

    // Count the occurrences of each character
    for (int i = 0; i < strlen(str); i++) {
        count[str[i]]++;
    }

    for (int i = 0; i < strlen(str); i++) {
        count[str[i]]--;

        // Skip if the character is already in the stack
        if (inStack[str[i]]) {
            continue;
        }

        // Pop characters from the stack if a smaller character is available and it occurs later
        while (stackTop >= 0 && str[i] < stack[stackTop] && count[stack[stackTop]] > 0) {
            inStack[stack[stackTop--]] = false;
        }

        // Push the current character onto the stack
        stack[++stackTop] = str[i];
        inStack[str[i]] = true;
    }

    stack[++stackTop] = '\0';  // Null-terminate the stack to form the result string

    printf("Remove Duplicate Letters: %s\n", stack);
}

int main(void) {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character
    removeDuplicateLetters(input);

    return 0;
}