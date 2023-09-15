#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 이진 트리 노드 정의
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// Set 구조체 정의
typedef struct {
    Node *root;
} Set;

// Set 초기화 함수
void initializeSet(Set *set) {
    set->root = NULL;
}

// Set에 원소 추가 함수
bool addToSet(Set *set, int element) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false; // 동적 메모리 할당 실패
    }

    newNode->key = element;
    newNode->left = NULL;
    newNode->right = NULL;

    if (set->root == NULL) {
        set->root = newNode;
    } else {
        Node *current = set->root;
        while (true) {
            if (element < current->key) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else if (element > current->key) {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            } else {
                free(newNode); // 이미 있는 값이므로 노드 제거
                return false;
            }
        }
    }
    return true;
}

// Set 출력 함수 (중위 순회)
void printSetHelper(Node *node) {
    if (node != NULL) {
        printSetHelper(node->left);
        printf("%d ", node->key);
        printSetHelper(node->right);
    }
}

void printSet(Set *set) {
    printf("{ ");
    printSetHelper(set->root);
    printf("}\n");
}

int main() {
    Set mySet;
    initializeSet(&mySet);

    addToSet(&mySet, 5);
    addToSet(&mySet, 10);
    addToSet(&mySet, 15);
    addToSet(&mySet, 5); // 중복된 값은 추가되지 않음

    printSet(&mySet);

    return 0;
}
