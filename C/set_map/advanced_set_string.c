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
    int size; // Added: To store the size of the set
} StringSet;

// Set initialization function
void initializeStringSet(StringSet *set) {
    set->root = NULL;
    set->size = 0; // Initialize the size to 0
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
    
    set->size++; // Increase the size of the set
    return true;
}

// Function to get the size of the set
int getSize(const StringSet *set) {
    return set->size;
}

// Function to print the set (in-order traversal)
void printStringSetHelper(Node *node) {
    if (node != NULL) {
        printStringSetHelper(node->left);
        printf("%s ", node->key);
        printStringSetHelper(node->right);
    }
}

void printStringSet(const StringSet *set) {
	printf("{ ");
    printStringSetHelper(set->root);
	printf("}");
}

// Function to delete all elements (free memory)
void deleteAllElementsHelper(Node *node) {
    if (node != NULL) {
        deleteAllElementsHelper(node->left);
        deleteAllElementsHelper(node->right);
        free(node->key);
        free(node);
    }
}

void emptySet(StringSet *set) {
    deleteAllElementsHelper(set->root);
    set->root = NULL;
    set->size = 0; // Reset the size to 0
}

int main() {
    StringSet Set;
	initializeStringSet(&Set);
	int n;
	int cnt = 0;
	char name[21];
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%s", name);
		if (strcmp(name, "ENTER")==0){// Set 초기화.
			cnt += getSize(&Set);
			emptySet(&Set);
		}
		else{
			addToSet(&Set, name);
		}
	}
	printStringSet(&Set);
	printf("\n");
	printf("%d", cnt + getSize(&Set));

    return 0;
}
