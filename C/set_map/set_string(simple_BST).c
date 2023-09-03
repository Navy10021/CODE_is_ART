#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Binary tree node definition
typedef struct Node {
    char *key;
    struct Node *left;
    struct Node *right;
} Node;

// Set structure definition
typedef struct {
    Node *root;
} StringSet;

// Set initialization function
void initializeStringSet(StringSet *set) {
    set->root = NULL;
}

// Function to add a string to the set
bool addToSet(StringSet *set, const char *element) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false; // Memory allocation failed
    }

    newNode->key = strdup(element); // Copy the string
    newNode->left = NULL;
    newNode->right = NULL;

    if (set->root == NULL) {
        set->root = newNode;
    } else {
        Node *current = set->root;
        while (true) {
            int cmp = strcmp(element, current->key);
            if (cmp < 0) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else if (cmp > 0) {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            } else {
                free(newNode->key);
                free(newNode); // String already exists, so free the node
                return false;
            }
        }
    }
    return true;
}

// Function to print the set (in-order traversal)
void printStringSetHelper(Node *node) {
    if (node != NULL) {
        printStringSetHelper(node->left);
        printf("%s ", node->key);
        printStringSetHelper(node->right);
    }
}

void printStringSet(StringSet *set) {
    printStringSetHelper(set->root);
}

// Function to free memory used by the set
void freeStringSetHelper(Node *node) {
    if (node != NULL) {
        freeStringSetHelper(node->left);
        freeStringSetHelper(node->right);
        free(node->key);
        free(node);
    }
}

void freeStringSet(StringSet *set) {
    freeStringSetHelper(set->root);
}

int main() {
    StringSet mySet;
    initializeStringSet(&mySet);

    addToSet(&mySet, "apple");
    addToSet(&mySet, "banana");
    addToSet(&mySet, "cherry");
    addToSet(&mySet, "apple"); // Duplicate value, won't be added

    printf("Set contents:\n");
    printStringSet(&mySet);

    freeStringSet(&mySet);

    return 0;
}
