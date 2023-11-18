#include <stdio.h>
#include <stdlib.h>

#define True    1
#define False   0

typedef int Data;

// Linked List Node
typedef struct _node{
    Data data;
    struct _node * next;
} Node;

typedef struct _listStack{
    Node * head;
} ListStack;

// Linked List based Stack
typedef ListStack Stack;

void StackInit(Stack * pstack);         // 스택 초기화
int IsEmpty(Stack * pstack);            // 빈 스택 확인
void Push(Stack * pstack, Data data);   
Data Pop(Stack * pstack);
Data Peek(Stack * pstack);              

void StackInit(Stack * pstack){
    pstack->head = NULL;        // 포인트 변수인 head = NULL 초기화
}

int IsEmpty(Stack * pstack){
    if (pstack->head == NULL)
        return True;
    else   
        return False;
}

void Push(Stack * pstack, Data data){  // Linked List 머리에 새 노드를 추가!
    Node * newNode = (Node *)malloc(sizeof(Node));      // 새 노드 생성
    newNode->data = data;
    newNode->next = pstack->head;                       // 새 노드가 최근에 추가된 노드(Head)를 가르킴
    pstack->head = newNode;                             // 포인터 변수 Head 이동(새 노드를 가르키도록)
}

Data Pop(Stack * pstack){   // head가 가르키는 노드 소멸 및 데이터 반환
    Data rdata;
    Node * rnode;

    if (IsEmpty(pstack)){
        printf("Stack memorry Error.");
        exit(-1);
    }

    rdata = pstack->head->data;         // 삭제할 노드 임시 저장
    rnode = pstack->head;               // 삭제할 노드의 주소값 저장

    pstack->head = pstack->head->next;  // 포인터 변수 Head 삭제할 노드 다음 노드로 이동
    free(rnode);
    return rdata;                       // 삭제된 노드 데이터 반환
}

Data Peek(Stack * pstack){
    if (IsEmpty(pstack)){
        printf("Stack memorry Error.");
        exit(-1);
    }

    return pstack->head->data;
}


int main(void){
    // 1. Stack 생성 및 초기화
    Stack stack;
    StackInit(&stack);

    // 2. 데이터 넣기(1 -> 2 ... -> 6)
    Push(&stack, 1); Push(&stack, 2);
    Push(&stack, 3); Push(&stack, 4);
    Push(&stack, 5); Push(&stack, 6);

    // 3. 데이터 꺼내기(6 5 4 ... 1)
    while(!IsEmpty(&stack)){
        printf("%d ", Pop(&stack));
    }
    return 0;
}
