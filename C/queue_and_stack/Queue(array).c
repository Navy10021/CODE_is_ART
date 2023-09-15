#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = queue->rear = 0;
}

int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void push(Queue *queue, int x) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = x;
}

int pop(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    queue->front = (queue->front + 1) % MAX_SIZE;
    return queue->data[queue->front];
}

int size(Queue *queue) {
    return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}

int front(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    return queue->data[(queue->front + 1) % MAX_SIZE];
}

int back(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    return queue->data[queue->rear];
}

int main() {
    Queue queue;
    initQueue(&queue);

    int n;
    scanf("%d", &n);

    while (n--) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(&queue, x);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(&queue));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&queue));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", isEmpty(&queue));
        } else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&queue));
        } else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&queue));
        }
    }

    return 0;
}
