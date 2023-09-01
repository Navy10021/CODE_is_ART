#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int x) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = x;
}

int pop(Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top--];
}

int size(Stack *stack) {
    return stack->top + 1;
}

int top(Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    while (n--) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(&stack, x);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(&stack));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&stack));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", isEmpty(&stack));
        } else if (strcmp(command, "top") == 0) {
            printf("%d\n", top(&stack));
        }
    }

    return 0;
}
