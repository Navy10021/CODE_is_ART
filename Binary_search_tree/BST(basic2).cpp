#include <iostream>

class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* Insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = Insert(root->left, key);
        } else if (key > root->key) {
            root->right = Insert(root->right, key);
        }

        return root;
    }

    Node* Delete(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = Delete(root->left, key);
        } else if (key > root->key) {
            root->right = Delete(root->right, key);
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

            Node* minRight = FindMin(root->right);
            root->key = minRight->key;
            root->right = Delete(root->right, minRight->key);
        }

        return root;
    }

    Node* FindMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* Search(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return Search(root->left, key);
        }

        return Search(root->right, key);
    }

    void Inorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        Inorder(root->left);
        std::cout << root->key << " ";
        Inorder(root->right);
    }

    void Preorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        std::cout << root->key << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Postorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        Postorder(root->left);
        Postorder(root->right);
        std::cout << root->key << " ";
    }

    void Print(Node* root, std::string indent, bool last) {
        if (root == nullptr) {
            return;
        }

        std::cout << indent;
        if (last) {
            std::cout << "└────";
            indent += "     ";
        } else {
            std::cout << "├────";
            indent += "|    ";
        }

        std::cout << root->key << std::endl;

        Print(root->left, indent, false);
        Print(root->right, indent, true);
    }

public:
    BST() : root(nullptr) {}

    void Insert(int key) {
        root = Insert(root, key);
    }

    void Delete(int key) {
        root = Delete(root, key);
    }

    bool Search(int key) {
        return Search(root, key) != nullptr;
    }

    void Inorder() {
        Inorder(root);
        std::cout << std::endl;
    }

    void Preorder() {
        Preorder(root);
        std::cout << std::endl;
    }

    void Postorder() {
        Postorder(root);
        std::cout << std::endl;
    }

    void Print() {
        Print(root, "", true);
    }
};
