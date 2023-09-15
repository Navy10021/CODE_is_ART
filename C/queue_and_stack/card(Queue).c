// N장의 카드. 1.제일 위의 카드를 버린다. 2. 다음 카드를 카드 밑으로 옮긴다. 3. 1장 남을때까지 반복.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void push(Queue *queue, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int pop(Queue *queue) {
    if (queue->front == NULL)
        return -1;

    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL)
        queue->rear = NULL;

    queue->size--;
    return data;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue *queue = createQueue();
    for (int i = 1; i <= n; i++) {
        push(queue, i);
    }

    while (queue->size > 1) {
        pop(queue);
        int frontValue = pop(queue);
        push(queue, frontValue);
    }

    printf("%d\n", queue->front->data);

    free(queue);

    return 0;
}
