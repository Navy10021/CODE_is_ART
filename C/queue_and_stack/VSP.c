#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

bool is_valid_parentheses(const char* str) {
    int stack[MAX_LEN];
    int top = -1; // Initialize stack top

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                return false; // Closing bracket with empty stack
            }
            if ((str[i] == ')' && stack[top] == '(') ||
                (str[i] == '}' && stack[top] == '{') ||
                (str[i] == ']' && stack[top] == '[')) {
                top--; // Pop opening bracket from stack
            } else {
                return false; // Mismatched brackets
            }
        }
    }

    return top == -1; // Stack should be empty for VSP
}

int main() {
    char input[MAX_LEN];
    printf("Enter a parentheses string: ");
    scanf("%s", input);

    if (is_valid_parentheses(input)) {
        printf("YES: The input is a valid parentheses string.\n");
    } else {
        printf("NO: The input is not a valid parentheses string.\n");
    }

    return 0;
}
