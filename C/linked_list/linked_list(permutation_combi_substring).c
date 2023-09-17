#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node struct 정의
struct Node{
    int data;
    //char data;
    struct Node* next;
};

// Linked List append 함수
void append(struct Node** headRef, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL){
        *headRef = newNode;
        return;
    }

    struct Node* curr = *headRef;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
}

// Print Linked List 함수 
void printList(struct Node* head){
    printf("[ ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

// Function to check if a linked list contains a specific value
bool is_contain(struct Node* head, int target) {
    struct Node* current = head;
    while (current) {
        if (current->data == target) {
            return true; // Value found in the linked list
        }
        current = current->next;
    }
    return false; // Value not found in the linked list
}

bool is_continous(struct Node* head){
    struct Node* curr = head;
    while (curr->next != NULL){
        if(curr->data == curr->next->data + 1 || curr->data + 1 == curr->next->data)
            return true;
        
        curr = curr->next;
    }
    return false;
}

// Swap Node 함수
void swapNodes(struct Node* a, struct Node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Permutation 생성 함수
void genPermutation(struct Node* head, struct Node* curr){
    //if (curr == NULL && is_continous(head)==false){ // 끝까지 도달(Linked list size)했으면 출력
    if (curr == NULL){
        printList(head);
        return;
    }
    struct Node* iter = curr;
    while(iter != NULL){
        swapNodes(curr, iter);
        genPermutation(head, curr->next);   // + 1 이동 
        swapNodes(curr, iter);              // Backtracking 
        iter = iter->next;
    }
}

// Combination 생성 함수 
void genCombination(struct Node* head, int comboSize, int index, struct Node* combo[], int comboIdx){
    // Combination 크기를 만족하면 노드 출력
    if (comboIdx == comboSize){
        for (int i = 0; i < comboSize; i++){
            printf("%d ", combo[i]->data);
        }
        printf("\n");
        return;
    }

    if (index >= comboSize || head == NULL){
        return;
    }
    // 현재 노드를 Combination array에 추가
    combo[comboIdx] = head;
    genCombination(head->next, comboSize, index+1, combo, comboIdx+1);
    // 현재 노드를 Combination array에서 제거
    genCombination(head->next, comboSize, index, combo, comboIdx);
}

// Permutation with Repetition 함수
void genPermutationRep(struct Node* head, struct Node* curr){
    if (curr == NULL){ // 끝까지 도달(Linked list size)했으면 출력
        printList(head);
        return;
    }
    struct Node* iter = curr;
    while(iter != NULL){
        swapNodes(curr, iter);
        genPermutationRep(head, curr->next);    // + 1 이동 
        swapNodes(curr, iter);                  // Backtracking 
        iter = iter->next;

        // 중복되는 경우는 SKIP(추가)
        while (iter != NULL && iter->data == curr->data){
            iter = iter->next;
        }
    }
}

// Loop 여부를 확인하는 함수
int hasLoop(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
            return 1;       // LOOP 존재
    }
    return 0;               // LOOP 없음
}


// Generation Sub linked list
struct Node* genSub(struct Node* head, int st_idx, int en_idx) {
    if (head == NULL || st_idx > en_idx) {
        return NULL;
    }

    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->next = NULL; // Dummy node

    int idx = 0;
    struct Node* curr = dummy;

    while (head != NULL) {
        if (idx >= st_idx && idx <= en_idx) {
            curr->next = malloc(sizeof(struct Node));
            curr = curr->next;
            curr->data = head->data;
            curr->next = NULL;
        }
        head = head->next;
        idx += 1;
    }

    return dummy->next;
}


int main(){
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 5);
    printf("=== Original List ===\n");
    printList(head);

    printf("=== Permutation ===\n");
    genPermutation(head, head);

    printf("=== Permutation with Repetition ===\n");
    genPermutationRep(head, head);


/*
    printf("=== Combination ===\n");
    int comboSize = 2;
    struct Node* combo[comboSize];
    genCombination(head, comboSize, 0, combo, 0);
    
    printf("=== Subset ===\n");
    int st_idx = 1;  // Start index (inclusive)
    int en_idx = 3;  // End index (inclusive)
    struct Node* subList = genSub(head, st_idx, en_idx);
    printList(subList);
*/
    return 0;
}
