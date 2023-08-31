#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, const char* value) {
    if (root == NULL) {
        return createNode(value);
    }

    int cmp = strcmp(value, root->data);

    if (cmp < 0) {
        root->left = insert(root->left, value);
    } else if (cmp > 0) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool find(Node* root, const char* value) {
    if (root == NULL) {
        return false;
    }

    int cmp = strcmp(value, root->data);

    if (cmp == 0) {
        return true;
    } else if (cmp < 0) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%s\n", root->data);
    inorderTraversal(root->right);
}

#define MAX_LEN 100

typedef struct {
    Node* root;
    int size;
} TreeSet;

void initTreeSet(TreeSet* set) {
    set->root = NULL;
    set->size = 0;
}

void insertToTreeSet(TreeSet* set, const char* value) {
    if (!find(set->root, value)) {
        set->root = insert(set->root, value);
        set->size++;
    }
}

bool findInTreeSet(TreeSet* set, const char* value) {
    return find(set->root, value);
}

int sizeOfTreeSet(TreeSet* set) {
    return set->size;
}

int main() {
    TreeSet set;
    initTreeSet(&set);

    insertToTreeSet(&set, "apple");
    insertToTreeSet(&set, "banana");
    insertToTreeSet(&set, "cherry");
    insertToTreeSet(&set, "banana");

    printf("Set contents:\n");
    inorderTraversal(set.root);

    printf("Size of the set: %d\n", sizeOfTreeSet(&set));

    if (findInTreeSet(&set, "banana")) {
        printf("Found 'banana' in the set.\n");
    } else {
        printf("Did not find 'banana' in the set.\n");
    }

    return 0;
}
