#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Sturcture for a single node 
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push_front(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    
    newNode->next = *head;
    *head = newNode;
}

void push_back(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    
    if (*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
}

void display(struct Node* head){
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int search(struct Node* head, int target){
    struct Node* curr = head;
    int position = 0;
    while (curr != NULL){
        if (curr->data == target){
            return position;
        }
        curr = curr->next;
        position++;
    }
    return -1;  // element not found;
}

// Bubble sort
void sorted(struct Node** head){
    struct Node* curr;
    //struct Node* temp;
    int temp_data;

    if (*head == NULL){
        return;
    }
    int swapped;    // swap 했는지 여부
    do {
        swapped = 0;
        curr = *head;

        while (curr->next != NULL){
            if (curr->data > curr->next->data){
                // Swap data
                temp_data = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp_data;
                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped);
}

void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next_node;

    while(curr != NULL){
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    *head = prev;
}

void rotate(struct Node** head, int k){
    if (k <= 0 || *head == NULL)
        return;
    
    // 1.Traverse find length 
    struct Node* curr;
    int length = 1;
    curr = *head;
    while (curr->next != NULL){
        curr = curr->next;
        length++;
    }

    // 2. Make the list circular
    curr->next = *head;

    // 3. Find the new head after rotation
    int new_head_position = length - (k % length) -1;

    // 4. Traverse to the new head position
    curr = *head;
    for (int i = 0; i < new_head_position; i++){
        curr = curr->next;
    }
    // 5. Update new head and break the circular link
    *head = curr->next;
    curr->next = NULL;
}

void erase(struct Node** head, int target){
    struct Node* curr = *head;
    struct Node* prev = NULL;

    while(curr != NULL && curr->data != target){
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL){
        return;     // target is not in Linked list
    }

    if (prev == NULL){
        *head = curr->next;
    }
    else{
        prev->next = curr->next;
    }
    free(curr); //memory out -> erase
}

void erase_duplicates(struct Node* head){
    struct Node* curr = head;
    struct Node* runner;    // 현재 노드 보다 다음 블록을 나아가며 중복 확인
    while(curr != NULL){
        runner = curr;
        while (runner->next != NULL){
            if(curr->data == runner->next->data){
                struct Node* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            }
            else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }    
}
// merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* dummy = createNode(0);
    struct Node* merged = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            merged->next = list1;
            list1 = list1->next;
        } else {
            merged->next = list2;
            list2 = list2->next;
        }
        merged = merged->next;
    }

    if (list1 != NULL)
        merged->next = list1;
    else
        merged->next = list2;

    return dummy->next;
}

// Function to check if one linked list is a sublist of another
bool isSublist(struct Node* mainList, struct Node* subList) {
    if (subList == NULL) {
        return true; // An empty list is always a sublist
    }
    if (mainList == NULL) {
        return false; // Cannot be a sublist if the main list is empty
    }

    struct Node* mainCurrent = mainList;
    struct Node* subCurrent = subList;

    while (mainCurrent != NULL) {
        if (mainCurrent->data == subCurrent->data) {
            struct Node* mainTemp = mainCurrent;
            struct Node* subTemp = subCurrent;

            while (mainTemp != NULL && subTemp != NULL && mainTemp->data == subTemp->data) {
                mainTemp = mainTemp->next;
                subTemp = subTemp->next;
            }

            if (subTemp == NULL) {
                return true; // Sublist found in the main list
            }
        }

        mainCurrent = mainCurrent->next;
    }

    return false; // Sublist not found in the main list
}

bool isPalindrome(struct Node* head){
    if (head == NULL){
        return true;
    }

    // 1. 리스트의 중간을 찾는다.
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;      // Node* slow = middle
        fast = fast->next->next;
    }
    // 2. 뒤에 절반(second half)을 reverse
    struct Node* prev = NULL;
    struct Node* curr = slow;
    struct Node* next_node;

    while(curr != NULL){
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    // 3. 비교 : first half <-> reversed second half
    struct Node* first_half = head;
    struct Node* second_half = prev;

    while(second_half != NULL){
        if (first_half->data != second_half->data){
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;    // is palindrome.
}

void display_sublist(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* sublist = curr;

        while (sublist != NULL) {
            display(sublist);
            sublist = sublist->next;
        }
        curr = curr->next;
    }
}

int main(){
    struct Node* head = NULL;   // creat head Node;
    struct Node* head2 = NULL;
    // Enter the elements(array)
    int arr [] = {1, 3, 5, 7, 9};
    int arr2 [] = {0, 2, 4, 8, 10}; 
    int N = 5;
    for (int i=0; i<N; i++){
        push_back(&head, arr[i]);
        push_back(&head2, arr2[i]);
    }
    printf("Original list : ");
    display(head);
    display(head2);

    struct Node* mergedList = mergeLists(head, head2);
    display(mergedList);


    //printf("After Rotate : ");
    //rotate(&head, 3);
    //display(head);
    


    // Search (target)
    //printf("%d", search(head, 3));
    //printf("\n");
    //printf("%d", search(head, 7));
    //printf("\n");
    
    // Sorting
    //sorted(&head);
    //printf("After sorting : ");
    //display(head);

    // reverse
    //reverse(&head);
    //printf("After reverse : ");
    //display(head);

    // erase
    //erase(&head, 3);
    //display(head);

    // erase duplicate
    //erase_duplicates(head);
    //printf("After erase duplicates : ");
    //display(head);
    /*
    // sublist
    struct Node* sublist = NULL;
    push_front(&sublist, 4);
    push_front(&sublist, 5);
    printf("Sublist : ");
    display(sublist);
    if (isSublist(head, sublist)){
        printf("Sublist found.\n");
    }
    else{
        printf("Not found.\n");
    }
    // check is palindrome
    if(isPalindrome(head)){
        printf("is Palindrome\n");
    }

    display_sublist(head);
    */
}
