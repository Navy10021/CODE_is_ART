#include <iostream>

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
            std::cout << current->data << " ";
            inOrderTraversalRecursive(current->right);
        }
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
    std::cout << "In-order traversal: ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    // Search for values in the BST
    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    return 0;
}
