#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValid(char *s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } 
        
        else if (isalpha(s[i]) || isalnum(s[i])){
            continue;
        }
        
        else {
            if (top == -1) {
                return 0;  // No matching open bracket
            }

            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{')) {
                return 0;  // Mismatched closing bracket
            }
            top--;
        }
    }
    return (top == -1);  // Check if all open brackets are closed
}

int main(void) {
    char input[100];
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The string of parentheses is valid.\n");
    } else {
        printf("The string of parentheses is not valid.\n");
    }

    return 0;
}
