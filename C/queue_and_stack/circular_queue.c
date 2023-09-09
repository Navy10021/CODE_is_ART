#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Circular Queue structure
struct CircularQueue {
    int max_size;
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new circular queue
struct CircularQueue* createCircularQueue(int max_size) {
    struct CircularQueue* cq = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (cq == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    cq->max_size = max_size;
    cq->front = NULL;
    cq->rear = NULL;
    cq->size = 0;
    return cq;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->size == 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return cq->size == cq->max_size;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* cq, int data) {
    if (isFull(cq)) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    struct Node* newNode = createNode(data);
    if (isEmpty(cq)) {
        cq->front = cq->rear = newNode;
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
    }
    cq->rear->next = cq->front;
    cq->size++;
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = cq->front->data;
    if (cq->front == cq->rear) {
        free(cq->front);
        cq->front = cq->rear = NULL;
    } else {
        struct Node* temp = cq->front;
        cq->front = cq->front->next;
        cq->rear->next = cq->front;
        free(temp);
    }
    cq->size--;
    return data;
}

// Function to peek at the front element of the circular queue
int peek(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return cq->front->data;
}

// Function to get the current size of the circular queue
int getSize(struct CircularQueue* cq) {
    return cq->size;
}

// Function to print the circular queue
void printQueue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = cq->front;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != cq->front);
    printf("\n");
}

int main() {
    struct CircularQueue* cq = createCircularQueue(5);
    enqueue(cq, 1);
    enqueue(cq, 2);
    enqueue(cq, 3);

    printf("Circular Queue: ");
    printQueue(cq);

    printf("Dequeue: %d\n", dequeue(cq));
    printf("Peek: %d\n", peek(cq));
    printf("Queue size: %d\n", getSize(cq));

    enqueue(cq, 4);
    enqueue(cq, 5);

    printf("Circular Queue: ");
    printQueue(cq);

    // This will raise an exception because the queue is full
    enqueue(cq, 6);

    return 0;
}
