#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Find The Longest Substring in Parentheses. 
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

int longestValidSubstring(char *s) {
    int len = strlen(s);
    int max_len = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 2; j <= len; j += 2) {
            if (isValid(&s[i]) && j - i > max_len) {
                max_len = j - i;
            }
        }
    }
    return max_len;
}

int main() {
    char str[] = "(({)[][]";
    printf("The length of the longest valid substring in %s is %d\n", str, longestValidSubstring(str));
    return 0;
}
