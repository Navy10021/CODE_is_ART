#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// 1.Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 2.Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 3.Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// 4.Function to dequeue an element from the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // Reset rear if queue becomes empty
    }
    free(temp);
}

// 5.Function to get the front element of the queue
int front(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

// 6.Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// 7.Function to display the elements of the queue
void display(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 8.Function to free the memory occupied by the queue
void destroyQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    struct Queue* Q = createQueue();
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++){
        enqueue(Q, arr[i]);
    }
    printf("Original array : ");
    display(Q);
    printf("\n");

    printf("Left Rotation 3 : ");
    int N = 3;
    int num;
    while(N--){
        num = front(Q);
        dequeue(Q);
        enqueue(Q, num);
    }
    display(Q);

    return 0;
}
