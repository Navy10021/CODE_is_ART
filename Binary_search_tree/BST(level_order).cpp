#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BinarySearchTree {
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to search for a value in the BST
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Function to perform an in-order traversal of the BST
    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
    }

    // Function to perform a level-order traversal of the BST
    vector<vector<int>> levelOrderTraversal() {
        return levelOrderTraversalQueue(root);
    }

private:
    // Recursive function to insert a value into the BST
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Recursive function to search for a value in the BST
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Recursive function for in-order traversal (left-root-right)
    void inOrderTraversalRecursive(TreeNode* current) {
        if (current != nullptr) {
            inOrderTraversalRecursive(current->left);
            cout << current->data << " ";
            inOrderTraversalRecursive(current->right);
        }
    }

    // Function for level-order traversal using a queue
    vector<vector<int>> levelOrderTraversalQueue(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                levelValues.push_back(current->data);

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            result.push_back(levelValues);
        }

        return result;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform in-order traversal to print the values in sorted order
    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    // Perform level-order traversal and print the result
    vector<vector<int>> levelOrderResult = bst.levelOrderTraversal();
    cout << "Level-order traversal: [";
    for (size_t i = 0; i < levelOrderResult.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < levelOrderResult[i].size(); j++) {
            cout << levelOrderResult[i][j];
            if (j < levelOrderResult[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < levelOrderResult.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    // Search for values in the BST
    int searchValue = 40;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the BST." << endl;
    } else {
        cout << searchValue << " not found in the BST." << endl;
    }

    return 0;
}
