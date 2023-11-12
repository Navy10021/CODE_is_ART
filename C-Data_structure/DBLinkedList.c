#include <stdio.h>
#include <stdlib.h>

#define True    1
#define False   0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _DBLinkedList{
    Node * head;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);

void ListInit(List * plist){
    plist->head = NULL;
    plist->numOfData = 0;
}
// 삽입
void LInsert(List * plist, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;        // 새 노드가 기존 노드를 가르킨다. 첫노드인 경우(plist->head == NULL)
    if (plist->head != NULL){           // 두 번째 이후 
        plist->head->prev = newNode;    // 기존 노드가 새 노드를 가르킨다.
    }

    newNode->prev = NULL;               // 새 노드의 prev에 NULL 저장.
    plist->head = newNode;              // 포인트 변수 Head가 새 노드를 가르킨다.

    (plist->numOfData)++;
}

// 조회
int LFirst(List * plist, Data * pdata){
    if (plist->head == NULL)
        return False;
    
    plist->cur = plist->head;       // cur가 첫번째 노드를 가르킴.
    * pdata = plist->cur->data;     // cur가 가르키는 노드의 데이터 반환
    return True;
} 

int LNext(List * plist, Data * pdata){
    if (plist->cur->next == NULL)
        return False;
    
    plist->cur = plist->cur->next;      // cur를 오른쪽으로 이동
    *pdata = plist->cur->data;
    return True;
}

int LPrevious(List * plist, Data * pdata){
    if (plist->cur->prev == NULL)
        return False;
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return True;
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
    
    if (LFirst(&list, &data)){
        printf("%d -> ", data);
        while(LNext(&list, &data)){
            printf("%d -> ", data);
        }

        while(LPrevious(&list, &data)){
            printf("%d -> ", data);
        }
        printf("None \n");
    }
    return 0;
}
