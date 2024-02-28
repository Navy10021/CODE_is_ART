#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->val) {
            root->left = insertRecursive(root->left, key);
        } else {
            root->right = insertRecursive(root->right, key);
        }
        return root;
    }

    Node* deleteRecursive(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->val) {
            root->left = deleteRecursive(root->left, key);
        } else if (key > root->val) {
            root->right = deleteRecursive(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteRecursive(root->right, temp->val);
        }
        return root;
    }

    bool findRecursive(Node* root, int key) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == key) {
            return true;
        } else if (key < root->val) {
            return findRecursive(root->left, key);
        } else {
            return findRecursive(root->right, key);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderRecursive(Node* root, std::vector<int>& arr) {
        if (root != nullptr) {
            inorderRecursive(root->left, arr);
            arr.push_back(root->val);
            inorderRecursive(root->right, arr);
        }
    }

    Node* sortedArrayToBST(std::vector<int>& arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        Node* node = new Node(arr[mid]);
        node->left = sortedArrayToBST(arr, start, mid - 1);
        node->right = sortedArrayToBST(arr, mid + 1, end);
        return node;
    }

    std::pair<bool, int> checkBalanced(Node* node) {
        if (node == nullptr) {
            return {true, 0};
        }
        auto left = checkBalanced(node->left);
        auto right = checkBalanced(node->right);
        bool isBalanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = std::max(left.second, right.second) + 1;
        return {isBalanced, height};
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    void deleteNode(int key) {
        root = deleteRecursive(root, key);
    }

    bool find(int key) {
        return findRecursive(root, key);
    }

    bool isBalanced() {
        return checkBalanced(root).first;
    }

    void convertToBalancedBST() {
        std::vector<int> arr;
        inorderRecursive(root, arr);
        root = sortedArrayToBST(arr, 0, arr.size() - 1);
    }

    void inorderTraversal() {
        std::vector<int> result;
        inorderRecursive(root, result);
        for (int val : result) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    BST bst;
    // Example: Insertion
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the given tree:\n";
    bst.inorderTraversal();

    // Example: Deletion
    bst.deleteNode(20);
    std::cout << "Inorder traversal after deletion of 20:\n";
    bst.inorderTraversal();

    // Example: Find
    std::cout << "Does 30 exist in the tree? " << std::boolalpha << bst.find(30) << "\n";
    std::cout << "Does 100 exist in the tree? " << std::boolalpha << bst.find(100) << "\n";

    // Example: Check if balanced
    std::cout << "Is the tree balanced? " << std::boolalpha << bst.isBalanced() << "\n";

    // Example: Convert to balanced BST
    bst.convertToBalancedBST();
    std::cout << "Inorder traversal after converting to balanced BST:\n";
    bst.inorderTraversal();

    // Check if the tree is balanced after conversion
    std::cout << "is the tree balanced after conversion? " << std::boolalpha << bst.isBalanced() << "\n";

    return 0;
}
