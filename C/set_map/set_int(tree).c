#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool find(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
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
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

typedef struct {
    Node* root;
    int size;
} TreeSet;

void initTreeSet(TreeSet* set) {
    set->root = NULL;
    set->size = 0;
}

void insertToTreeSet(TreeSet* set, int value) {
    if (!find(set->root, value)) {
        set->root = insert(set->root, value);
        set->size++;
    }
}

bool findInTreeSet(TreeSet* set, int value) {
    return find(set->root, value);
}

int sizeOfTreeSet(TreeSet* set) {
    return set->size;
}

int main() {
    TreeSet set;
    initTreeSet(&set);

    insertToTreeSet(&set, 5);
    insertToTreeSet(&set, 2);
    insertToTreeSet(&set, 8);
    insertToTreeSet(&set, 2); // Duplicate

    printf("Set contents:\n");
    inorderTraversal(set.root);

    printf("Size of the set: %d\n", sizeOfTreeSet(&set));

    if (findInTreeSet(&set, 8)) {
        printf("Found '8' in the set.\n");
    } else {
        printf("Did not find '8' in the set.\n");
    }

    return 0;
}
