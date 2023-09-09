#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list recursively
struct Node* reverseListRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: empty list or list with only one node
    }

    struct Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);

    printf("Original linked list:\n");
    printList(head);

    // Reverse the linked list recursively
    head = reverseListRecursive(head);

    printf("Reversed linked list:\n");
    printList(head);

    // Free memory for the linked list (not shown in detail here)
    
    return 0;
}
