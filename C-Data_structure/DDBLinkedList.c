#include<stdio.h>
#include<stdlib.h>

#define True    1
#define False   0

typedef int Data;

// Node 정의
typedef struct _node{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

// Double Linked List 정의
typedef struct _dbDLinkedList{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *pdata);     // *pdata에 Head->data 저장
int LNext(List *plist, Data *pdata);      // *pdata에 cur->data 저장

Data LRemove(List *plist);                // 참조가 이뤄진 노드를 삭제
int LCount(List *plist);

// 1. 리스트 초기화
void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->numOfData = 0;
}

// 2. 리스트 삽입
void LInsert(List *plist, Data data){
    // 새노드를 생성하여 저장
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;  
    // 새노드와 왼쪽 노드 연결
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    // 새노드와 오른쪽 노드 연결        
    newNode->next = plist->tail;
    plist->tail->prev = newNode;

    (plist->numOfData)++;         
}

int LFirst(List *plist, Data *pdata){
    if (plist->head->next ==NULL)
        return False;
    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return True;
}

int LNext(List *plist, Data *pdata){
    if (plist->cur->next == plist->tail)
        return False;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return True;
}

Data LRemove(List *plist){
    Node * rpos = plist->cur;
    Data rdata = rpos->data;
    // 1번
    plist->cur->prev->next = plist->cur->next;
    // 4번
    plist->cur->next->prev = plist->cur->prev;

    // 위치 조정
    plist->cur = plist->cur->prev;
    free(rpos);
    return rdata;
}

int LCount(List *plist){
    return plist->numOfData;
}


int main(void){
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    // 조회
    if(LFirst(&list, &data)){
        printf("%d->", data);

        while(LNext(&list, &data))
            printf("%d->", data);

    printf("None\n");
    }
    

    return 0;
}
