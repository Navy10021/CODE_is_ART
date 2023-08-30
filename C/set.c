#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Set {
    struct Node* head;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Set* createSet() {
    struct Set* set = (struct Set*)malloc(sizeof(struct Set));
    set->head = NULL;
    return set;
}

void insert(struct Set* set, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = set->head;
    set->head = newNode;
}

void display(struct Set* set) {
    struct Node* current = set->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void destroySet(struct Set* set) {
    struct Node* current = set->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

int main() {
    struct Set* s = createSet();
    insert(s, 1);
    insert(s, 2);
    insert(s, 3);
    insert(s, 4);
    insert(s, 5);

    display(s);

    destroySet(s);

    return 0;
}
