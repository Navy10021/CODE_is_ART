#include <stdio.h>
#include <stdlib.h>

#define True    1
#define False   0
#define Que_len 100

typedef int Data;

// Linked List Node
typedef struct _node{
    Data data;
    struct _node * next;
} Node;

typedef struct _listQueue{
    Node * front;
    Node * rear;
} ListQueue;

typedef ListQueue Queue;

void QueueInit(Queue * pq);
int IsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data Peek(Queue * pq);


void QueueInit(Queue * pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int IsEmpty(Queue * pq){    // Queue가 비었다면 Front에 NULL이 저장
    if (pq->front == NULL)
        return True;
    else
        return False;
}

void Enqueue(Queue * pq, Data data){
    Node * newNode = (Node *)malloc(sizeof(Node));  // 새 노드 생성
    newNode->data = data;
    newNode->next = NULL;

    if(IsEmpty(pq)){    // 첫 번째 노드에 추가될 경우 Front && Rear 포인트 변수 모두 새 노드르 가르킴.
        pq->front = newNode;
        pq->rear = newNode;
    }
    else{
        pq->rear->next = newNode;   // 마지막 노드가 새 노드를 가르키게 하고,
        pq->rear = newNode;         // rear 포인트 변수 이동하여 가르킴.
    }
}

Data Dequeue(Queue * pq){       // Front 포인트 변수만 신경쓰면 됨.
    Data rdata;
    Node * delNode;
    
    if (IsEmpty(pq)){
        printf("Queue memory error.\n");
        exit(-1);
    }
    delNode = pq->front;            // 삭제할 노드 주소값 저장
    rdata = pq->front->data;        // 삭제할 노드의 값 저장
    pq->front = pq->front->next;    // 삭제할 노드 다음을 가르킴.
    free(delNode);                  // 노드 삭제

    return rdata;
}

Data Peek(Queue * pq){
        if (IsEmpty(pq)){
        printf("Queue memory error.\n");
        exit(-1);
    }

    return pq->front->data;
}


int main(void){
    Queue Q;
    QueueInit(&Q);

    Enqueue(&Q, 10); Enqueue(&Q, 20);
    Enqueue(&Q, 30); Enqueue(&Q, 40);
    Enqueue(&Q, 50); Enqueue(&Q, 60);
    Enqueue(&Q, 70); Enqueue(&Q, 80);

    while (!IsEmpty(&Q)){
        printf("%d ", Dequeue(&Q));
    }
    return 0;
}
