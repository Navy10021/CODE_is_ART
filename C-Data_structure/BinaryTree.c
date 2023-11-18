#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
BTreeNode* GetLeftSub(BTreeNode* bt);
BTreeNode* GetRightSub(BTreeNode* bt);
void MakeLeftSub(BTreeNode* main, BTreeNode* sub);
void MakeRightSub(BTreeNode* main, BTreeNode* sub);
void DelTree(BTreeNode* bt);
void PreorderTrav(BTreeNode* bt, void (*action)(BTData));
void InorderTrav(BTreeNode* bt, void (*action)(BTData));
void PostorderTrav(BTreeNode* bt, void (*action)(BTData));
void RemoveNode(BTreeNode** root, BTData target);

BTreeNode* MakeBTreeNode(void) {
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
    bt->data = data;
}

BTreeNode* GetLeftSub(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSub(BTreeNode* bt) {
    return bt->right;
}

void MakeLeftSub(BTreeNode* main, BTreeNode* sub) {
    main->left = sub;
}

void MakeRightSub(BTreeNode* main, BTreeNode* sub) {
    main->right = sub;
}

void DelTree(BTreeNode* bt) {
    if (bt == NULL) {
        return;
    }
    DelTree(bt->left);
    DelTree(bt->right);
    free(bt);
}

void ShowData(BTData data) {
    printf("%d -> ", data);
}

void PreorderTrav(BTreeNode* bt, void (*action)(BTData)) {
    if (bt == NULL)
        return;
    action(bt->data);
    PreorderTrav(bt->left, action);
    PreorderTrav(bt->right, action);
}

void InorderTrav(BTreeNode* bt, void (*action)(BTData)) {
    if (bt == NULL)
        return;
    InorderTrav(bt->left, action);
    action(bt->data);
    InorderTrav(bt->right, action);
}

void PostorderTrav(BTreeNode* bt, void (*action)(BTData)) {
    if (bt == NULL)
        return;
    PostorderTrav(bt->left, action);
    PostorderTrav(bt->right, action);
    action(bt->data);
}

BTreeNode* FindMinNode(BTreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

BTreeNode* FindMaxNode(BTreeNode* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}


void RemoveNode(BTreeNode** root, BTData target) {
    if (*root == NULL) {
        return;
    }

    if (target < (*root)->data) {
        RemoveNode(&((*root)->left), target);
    } else if (target > (*root)->data) {
        RemoveNode(&((*root)->right), target);
    } else {
        // Node to be deleted is found
        if ((*root)->left == NULL) {
            BTreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            BTreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Node has two children
            BTreeNode* temp = FindMaxNode((*root)->left);
            (*root)->data = temp->data;
            RemoveNode(&((*root)->left), temp->data);
        }
    }
}

int main(void) {
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSub(bt1, bt2);
    MakeRightSub(bt1, bt3);
    MakeLeftSub(bt2, bt4);

    printf("Original Tree (Inorder): ");
    InorderTrav(bt1, ShowData);
    printf("\n");

    // Remove node with data 3
    RemoveNode(&bt1, 3);

    printf("Tree after removing node with data 3 (Inorder): ");
    InorderTrav(bt1, ShowData);
    printf("\n");

    DelTree(bt1);

    return 0;
}
