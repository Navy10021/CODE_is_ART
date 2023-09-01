#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack *stack, char c) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        exit(1); // Exit with an error code
    }
    stack->data[++stack->top] = c;
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1); // Exit with an error code
    }
    return stack->data[stack->top--];
}

// Check if parentheses are valid
bool isValidParentheses(char *s) {
    int len = strlen(s);
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty(&stack)) {
                return false; // Unmatched closing bracket
            }

            char topChar = pop(&stack);

            if ((s[i] == ')' && topChar != '(') ||
                (s[i] == '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                return false; // Mismatched opening and closing brackets
            }
        }
    }

    return isEmpty(&stack); // True if the stack is empty (all brackets matched)
}

int main() {
    char input[MAX_SIZE];
    scanf("%s", input);

    if (isValidParentheses(input)) {
        printf("Valid parentheses!\n");
    } else {
        printf("Invalid parentheses!\n");
    }

    return 0;
}
