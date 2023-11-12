#include<stdio.h>
#include<stdlib.h>

#define True    1
#define False   0

typedef int LData;

// Node 정의
typedef struct _node{
    LData data;
    struct _node * next;
} Node;

// Linked List 정의
typedef struct _linkedList{
    Node * head;     // 더미노드를 가르키는 멤버
    Node * cur;      // 참조 및 삭제를 위한 멤버
    Node * before;   // 삭제를 위한 멤버
    int numOfData;   // 저장된 데이터 수 
    int (*comp)(LData d1, LData d2);    // 정렬의 기준을 등록하기 위한 멤버
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata);     // *pdata에 Head->data 저장
int LNext(List *plist, LData *pdata);      // *pdata에 cur->data 저장

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

// 1. 리스트 초기화
void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node));      // 더미노드 생성
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

// 2. 노드 추가 
void FInsert(List *plist, LData data){
    Node * newNode = (Node*)malloc(sizeof(Node));   // 새노드를 생성
    newNode->data = data;                           // 데이터 저장

    newNode->next = plist->head->next;              // 새노드가 더미노드를 가르킴.(오른쪽 연결)
    plist->head->next = newNode;                    // 더미노드가 새노드를 가르킴.(왼쪽 연결)
    (plist->numOfData)++;
}

// 3. 정렬 노드 추가
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)){
    plist->comp = comp;
}

void SInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head;           // pred : 더미노드를 가르킴
    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0){  // pred가 마지막 노드를 가르키지 않고, 데이터가 들어갈 자리가 아니면
        pred = pred->next;      // 다음노드로 이동
    }

    newNode->next = pred->next;     // 새노드 오른쪽 연결 
    pred->next = newNode;           // 새노드 왼쪽 연결
    
    (plist->numOfData)++;
}

void LInsert(List *plist, LData data){
    if (plist->comp == NULL)
        FInsert(plist, data);
    
    else
        SInsert(plist, data);
}

// 4. 데이터 조회
int LFirst(List *plist, LData *pdata){
    if(plist->head->next == NULL)
        return False;

    plist->before = plist->head;        // before는 더미노드를 가르킴.
    plist->cur = plist->head->next;     // cur는 첫번째 노드를 가르킴.

    *pdata = plist->cur->data;           // cur 데이터를 전달
    return True;
}

int LNext(List *plist, LData *pdata){
    if (plist->cur->next == NULL)
        return False;
    
    plist->before = plist->cur;         // before는 curr 가르킨 노드를 가르킴.
    plist->cur = plist->cur->next;      // cur는 한칸 이동한 노드를 가르킴.
    *pdata = plist->cur->data;
    return True;
}

// 5. 삭제
LData LRemove(List *plist){
    Node * rpos = plist->cur;       // 삭제할 노드의 주소값 저장
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;     // 리스트 삭제 : before --- cur->next 연결
    plist->cur = plist->before;                 // cur 참조값 재조정
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist){
    return plist->numOfData;
}

int WhoIsprecede(int d1, int d2){
    if (d1 < d2)    // d1이 정렬 순서상 앞선다.
        return 0;
    else
        return 1;   // d2가 정렬 순서상 앞선다.
}

int main(void){
    // 리스트 생성 && 초기화
    List list;
    int data;
    ListInit(&list);
    printf("Make Linked List and Initialization. \n");


    // 정렬
    SetSortRule(&list, WhoIsprecede);
    printf("Sorted Linked List\n");

    LInsert(&list, 3);
    LInsert(&list, 1);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 2);

    printf("Number of data : %d\n", LCount(&list));

    if (LFirst(&list, &data)){
        printf("%d -> ", data);

        while(LNext(&list, &data))
            printf("%d -> ", data);
    }
    printf("NULL\n");

    // 삭제 
    int tgt = 3;
    if(LFirst(&list, &data)){
        if (data == tgt)
            LRemove(&list);
        
        while(LNext(&list, &data)){
            if (data == tgt)
                LRemove(&list);
        }
    }

    if (LFirst(&list, &data)){
        printf("%d -> ", data);

        while(LNext(&list, &data))
            printf("%d -> ", data);
    }
    printf("NULL\n");

    return 0;
}
