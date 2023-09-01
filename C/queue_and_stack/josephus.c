#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// 큐 초기화
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 큐에 요소 추가
void push(Queue* queue, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;

    if (queue->size == 0) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// 큐에서 요소 제거 및 반환
int pop_front(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

// (N, K)-요세푸스 순열 계산
void josephus(int n, int k) {
    Queue queue;
    initQueue(&queue);

    // 큐에 1부터 n까지의 숫자 추가
    for (int i = 1; i <= n; i++) {
        push(&queue, i);
    }

    printf("<");
    while (queue.size > 0) {
        for (int i = 0; i < k - 1; i++) {
            // k-1개의 사람은 큐의 뒤로 이동
            int front = pop_front(&queue);
            push(&queue, front);
        }

        // k번째 사람을 출력하고 큐에서 제거
        int kthPerson = pop_front(&queue);
        printf("%d", kthPerson);

        if (queue.size > 0) {
            printf(", ");
        }
    }
    printf(">");
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    josephus(N, K);
    return 0;
}
