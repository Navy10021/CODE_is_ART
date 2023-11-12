#include<stdio.h>
#include<stdlib.h>

#define True    1
#define False   0

// Define structure of Node
typedef struct _node{
    int data;
    struct _node * next;
} Node;

// Insert a new Node at the begining
void InsertAtBe(Node ** head, int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = * head;     // head가 가르키는 값을 연결
    *head = newNode;            // head가 newNode를 가르킴.
}

void InsertAtEnd(Node ** head, int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    // If list empty -> head
    if (*head == NULL){
        *head = newNode;
        return;
    }
    // Traverse the list
    Node *curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
}

void SortedInsert(Node ** head, int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // 리스트가 비었거나, Head 보다 작으면 Head
    if (*head == NULL || newNode->data < (*head)->data){
        newNode->next = *head;
        *head = newNode;
        //InsertAtBe(head, data);
        return;
    }

    // 현재 데이터 보다 크면 계속 이동
    Node *curr = *head;
    while(curr->next != NULL && curr->next->data < data){
        curr = curr->next;
    }
    // Insertion
    newNode->next = curr->next; // 오른쪽 연결
    curr->next = newNode;       // 왼쪽 연결
}

void LRmove(Node ** head, int tgt){
    if (*head == NULL)
        return;
    
    if((*head)->data == tgt){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *curr = *head;
    while(curr->next != NULL && curr->next->data != tgt){
        curr = curr->next;
    }

    if (curr->next == NULL){
        printf("Target is not found.\n");
        return;
    }
    
    Node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

// Reversed Linked List
void LReverse(Node **head){ // Head Node의 Pointer로 접근
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while(curr != NULL){
        next = curr->next;  // Save next node
        curr->next = prev;  // Reverse linked list
        prev = curr;        // Move to forward one step each pointer
        curr = next;
    }
    *head = prev;           // Update the head to point to the new first node.
}

// Find middle of Linked List : Runner technique.
Node* FindMiddle(Node * head){  // Head Node(struct)로 접근.
    if (head == NULL){
        return NULL;    // Empty list
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


// Display Linked List
void printList(Node * node){    // node Node(struct)로 접근.
    while(node != NULL){
        printf("%d-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Is palindrome
int isPalindrome(Node * head){
    if (head == NULL || head->next == NULL)
        return True;
    
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse
    Node * secondHalf = slow;
    LReverse(&secondHalf);

    // Compare
    while (secondHalf != NULL){
        if (head->data != secondHalf->data){
            return False;
        }
        head = head->next;
        secondHalf = secondHalf->next;
    }
    return True;
}

// Merge Two Sorted Lists
Node* MergeSortedLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    Node* merged = NULL;
    Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (merged == NULL) {
                merged = list1;
                current = merged;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (merged == NULL) {
                merged = list2;
                current = merged;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        current->next = list1;
    } else if (list2 != NULL) {
        current->next = list2;
    }

    return merged;
}

// Detect a Cycle
int HasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return True; // Cycle detected
        }
    }

    return False; // No cycle
}

// Remove Duplicates
void RemoveDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* runner = current;

        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

// Intersection Point.
Node* FindIntersection(Node* list1, Node* list2) {
    int len1 = Length(list1);
    int len2 = Length(list2);

    int diff = abs(len1 - len2);

    Node* longer = (len1 > len2) ? list1 : list2;
    Node* shorter = (len1 > len2) ? list2 : list1;

    // Move the longer list to the same starting point as the shorter list
    for (int i = 0; i < diff; ++i) {
        longer = longer->next;
    }

    // Move both lists until they intersect
    while (longer != NULL && shorter != NULL) {
        if (longer == shorter) {
            return longer; // Intersection point found
        }

        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL; // No intersection
}

// Rotate a Linked List
Node* RotateList(Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    int len = Length(head);
    k = k % len; // Handle cases where k is greater than the length of the list

    if (k == 0) {
        return head; // No rotation needed
    }

    Node* tail = head;
    for (int i = 1; i < len - k; ++i) {
        tail = tail->next;
    }

    Node* newHead = tail->next;
    tail->next = NULL;

    Node* temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;

    return newHead;
}


int main(void){
    Node *head = NULL;
    InsertAtBe(&head, 1);
    InsertAtBe(&head, 2);
    InsertAtBe(&head, 3);
    InsertAtBe(&head, 4);
    InsertAtBe(&head, 5);
    InsertAtBe(&head, 4);
    InsertAtBe(&head, 3);
    InsertAtBe(&head, 2);
    InsertAtBe(&head, 1);
    printList(head);

    if(isPalindrome(head)){
        printf("This List is a palindrome.\n");
    }
    else{
        printf("This List is NOT a palindrome.\n");
    }

    //LRmove(&head, 2);
    //printList(head);
    /*
    LReverse(&head);

    Node * middle = FindMiddle(head);

    if (middle != NULL){
        printf("Middle : %d\n", middle->data);
    }
    */
    /*
    //Node *head = NULL;
    InsertAtEnd(&head, 1);
    InsertAtEnd(&head, 2);
    InsertAtEnd(&head, 3);
    InsertAtEnd(&head, 4);
    InsertAtEnd(&head, 5);
    printList(head);
    */
    /*
    Node *head2 = NULL;
    SortedInsert(&head2, 3);
    SortedInsert(&head2, 5);
    SortedInsert(&head2, 1);
    SortedInsert(&head2, 2);
    SortedInsert(&head2, 4);
    printList(head2);
    */
    return 0;
}
