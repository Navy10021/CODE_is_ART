#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Set {
private:
    Node* root;
    size_t nodeCount;

    Node* insertRecursive(Node* root, int value, bool& inserted) {
        if (root == nullptr) {
            root = new Node(value);
            inserted = true;
            nodeCount++;
            return root;
        }
        if (value < root->value) {
            root->left = insertRecursive(root->left, value, inserted);
        } else if (value > root->value) {
            root->right = insertRecursive(root->right, value, inserted);
        }
        // If value already exists, we don't insert it and 'inserted' remains false.
        return root;
    }

    Node* eraseRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->value) {
            root->left = eraseRecursive(root->left, value);
        } else if (value > root->value) {
            root->right = eraseRecursive(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                nodeCount--;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                nodeCount--;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = eraseRecursive(root->right, temp->value);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    bool findRecursive(Node* root, int value) const {
        if (root == nullptr) {
            return false;
        }
        if (root->value == value) {
            return true;
        }
        return value < root->value ? findRecursive(root->left, value) : findRecursive(root->right, value);
    }

public:
    Set() : root(nullptr), nodeCount(0) {}

    void insertion(int value) {
        bool inserted = false;
        root = insertRecursive(root, value, inserted);
    }

    void erase(int value) {
        root = eraseRecursive(root, value);
    }

    bool find(int value) const {
        return findRecursive(root, value);
    }

    size_t size() const {
        return nodeCount;
    }

    ~Set() {
        clear(root);
    }

private:
    void clear(Node* root) {
        if (root != nullptr) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
};

int main() {
    Set mySet;
    mySet.insertion(10);
    mySet.insertion(20);
    mySet.insertion(10); // Attempting to insert a duplicate

    std::cout << "Set contains 10: " << std::boolalpha << mySet.find(10) << "\n"; // true
    std::cout << "Set contains 30: " << std::boolalpha << mySet.find(30) << "\n"; // false

    std::cout << "Set size before erase: " << mySet.size() << "\n"; // 2
    mySet.erase(10);
    std::cout << "Set size after erase 10 " << mySet.size() << "\n";

    return 0;
}
