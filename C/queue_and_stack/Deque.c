#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Deque;

void initDeque(Deque *deque) {
    deque->front = deque->rear = 0;
}

int isEmpty(Deque *deque) {
    return deque->front == deque->rear;
}

int isFull(Deque *deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

void pushFront(Deque *deque, int x) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    deque->data[deque->front] = x;
}

void pushBack(Deque *deque, int x) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    deque->data[deque->rear] = x;
    deque->rear = (deque->rear + 1) % MAX_SIZE;
}

int popFront(Deque *deque) {
    if (isEmpty(deque))
        return -1;
    int data = deque->data[deque->front];
    deque->front = (deque->front + 1) % MAX_SIZE;
    return data;
}

int popBack(Deque *deque) {
    if (isEmpty(deque))
        return -1;
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return deque->data[deque->rear];
}

int size(Deque *deque) {
    return (deque->rear - deque->front + MAX_SIZE) % MAX_SIZE;
}

int front(Deque *deque) {
    if (isEmpty(deque))
        return -1;
    return deque->data[deque->front];
}

int back(Deque *deque) {
    if (isEmpty(deque))
        return -1;
    return deque->data[(deque->rear - 1 + MAX_SIZE) % MAX_SIZE];
}

int main() {
    Deque deque;
    initDeque(&deque);

    int n;
    scanf("%d", &n);

    while (n--) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0){
            int x;
            scanf("%d", &x);
            pushFront(&deque, x);
        }

        else if (strcmp(command, "push_back") == 0){
            int x;
            scanf("%d", &x);
            pushBack(&deque, x);
        }

        else if (strcmp(command, "pop_front")==0){
            popFront(&deque);
        }

        else if (strcmp(command, "pop_back")==0){
            printf("%d\n", popBack(&deque));
        }

        else if (strcmp(command, "size")==0){
            printf("%d\n", size(&deque));
        }

        else if (strcmp(command, "empty")==0){
            printf("%d\n", isEmpty(&deque));
        }

        else if (strcmp(command, "front")==0){
            printf("%d\n", front(&deque));
        }

        else if (strcmp(command, "back")==0){
            printf("%d\n", back(&deque));
        }
    }

    return 0;
}
