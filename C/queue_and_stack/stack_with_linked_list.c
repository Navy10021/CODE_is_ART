#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

// 1.Function to create a new node
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 2.Function to initalize a Stack
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// 3. Fucntion to push an element onto the stack
void push(struct Stack* stack, int value){
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// 4. Function to pop an element from the stack
void pop(struct Stack* stack){
    if (stack->top == NULL){
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp); // erase stack->top memory
}

// 5. Function to peak at the top element without pop()
int peek(struct Stack* stack){
    if (stack->top == NULL){
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

// 6. Function to check if the stack is empty
int isEmpty(struct Stack* stack){
    return stack->top == NULL;
}

// 7. Function to get size of the stack
int size(struct Stack* stack){
    int cnt=0;
    struct Node* curr = stack->top;
    while (curr != NULL){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

// 8. Function to display the elements of the stack
void display(struct Stack* stack){
    struct Node* curr = stack->top;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void destroyStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main(){
    struct Stack* S = createStack();
    push(S, 0);
    push(S, 10);
    push(S, 20);
    push(S, 30);
    push(S, 50);
    display(S);

    printf("Top element: %d\n", peek(S));
    printf("Stack size: %d\n", size(S));
    printf("POP!\n");
    pop(S);
    printf("Top element: %d\n", peek(S));
    printf("Stack size: %d\n", size(S));
    display(S);
}
