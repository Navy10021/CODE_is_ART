#include <stdio.h>
#include <stdlib.h>

#define True    1
#define False   0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
} Node;

typedef struct _CLL{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
void LInsertFront(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

void ListInit(List * plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// 머리에 추가
void LInsertFront(List * plist, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));   // 새노드 생성
    newNode->data = data;

    if (plist->tail == NULL){       // 첫번째 노드인 경우
        plist->tail = newNode;      // tail이 새노드를 가르키고,
        newNode->next = newNode;    // 새노드 자신을 가르키게 한다.
    }
    else{
        newNode->next = plist->tail->next;      // 새노드를 기존 Head와 연결
        plist->tail->next = newNode;            // Head를 새노드 연결
    }

    (plist->numOfData)++;
}

// 꼬리에 추가
void LInsert(List * plist, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL){
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}

// 데이터 조회
int LFirst(List * plist, Data * pdata){
    if (plist->tail == NULL)
        return False;
    
    plist->before = plist->tail;        // before : 꼬리를 가르키게
    plist->cur = plist->tail->next;     // cur : 머리를 가르키게

    *pdata = plist->cur->data;          // cur 데이터를 반환
    return True;
}

// LNext : cur && before 한칸씩 이동하며 cur 데이터 반환
int LNext(List * plist, Data * pdata){
    if (plist->tail == NULL)
        return False;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return True;
}

// 데이터 삭제 
Data LRemove(List * plist){
    Node *rpos = plist->cur;
    Data rdata = rpos->data;

    if (rpos == plist->tail){   // 삭제노드가 tail이 가르킨다면 
        if (plist->tail == plist->tail->next)   // 마지막 남은 노드라면
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List * plist){
    return plist->numOfData;
}

int main(void){
    // 원형 연결 리스트 생성&초기화
    List list;
    int data, nodeNum;
    ListInit(&list);

    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 2);
    LInsert(&list, 1);

    if (LFirst(&list, &data)){
        printf("%d -> ", data);

        for (int i = 0; i < LCount(&list) - 1; i++){  // 리스트에 저장된 데이터를 3번 출력
            if(LNext(&list, &data))
                printf("%d -> ", data);
        }
    }
    printf("\n");

    // 2의 배수를 찾아서 삭제
    nodeNum = LCount(&list);

    if(nodeNum != 0){
        LFirst(&list, &data);
        if (data % 2 ==0)
            LRemove(&list);
        
        for (int i=0; i<nodeNum-1; i++){
            LNext(&list, &data);
            if (data % 2 ==0)
                LRemove(&list);
        }
    }
    // 출력
    if (LFirst(&list, &data)){
        printf("%d -> ", data);
        for (int i = 0; i < LCount(&list)-1; i++){
            if(LNext(&list, &data))
                printf("%d -> ", data);
        }
    }

    return 0;
}
