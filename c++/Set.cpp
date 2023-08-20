#include <iostream>

class Set{
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;

            Node(int val) : data(val), left(nullptr), right(nullptr) {}
        };

        // Tree's root node 
        Node* root;
        
        // Recursive insert function(BST)
        Node* insertRecursive(Node* root, int val){
            // 1. root가 없으면, root == newNode(val)
            if (root == nullptr){
                return new Node(val);
            }
            // 2. root.data 보다 작으면 왼쪽
            if (val < root->data){
                root->left = insertRecursive(root->left, val);
            }
            // 3. root.data 보다 크면 오른쪽
            else if (val > root->data){
                root->right = insertRecursive(root->right, val);
            }
            return root;
        }

        // Recursive erase function(BST)
        Node* eraseRecursive(Node* root, int val){
            if (root == nullptr){
                return root;
            }
            if (val < root->data){
                root->left = eraseRecursive(root->left, val);
            }
            else if (val > root->data){
                root->right = eraseRecursive(root->right, val);
            }
            // if find erase value
            else{
                if (root->left == nullptr){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                Node* successor = root->right;
                while(successor->left != nullptr){
                    successor = successor->left;
                }

                root->data = successor->data;
                root->right = eraseRecursive(root->right, successor->data);
        }
        return root;
    }
        // Recursive Search function
        bool containsRecursive(Node* root, int val) const {
            if (root == nullptr){
                return false;
            }
            if (val == root->data){
                return true;
            }
            else if (val < root->data){
                return containsRecursive(root->left, val);
            }
            else {
                return containsRecursive(root->right, val);
            }
        }

    // Recursive size function
        int sizeRecursive(Node* root) const{
            if (root == nullptr){
                return 0;
            }
            return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
        }

    public:
        Set() : root(nullptr) {}

        // Insert function
        void insert(int val){
            root = insertRecursive(root, val);
        }

        void erase(int val){
            root = eraseRecursive(root, val);
        }

        bool contains(int val) const {
            return containsRecursive(root, val);
        }

        int size() const{
            return sizeRecursive(root);
        }

        // Inorder traversal function
        void inorderTraversal(Node* root) const{
            if(root != nullptr){
                inorderTraversal(root->left);
                std::cout << root->data << " ";
                inorderTraversal(root->right);
            }
        }

        void display() const{
            inorderTraversal(root);
            std::cout << "\n";
        }
};

int main(){
    Set mySet;
    mySet.insert(5);
    mySet.insert(4);
    mySet.insert(3);
    mySet.insert(2);
    mySet.insert(2);
    mySet.insert(1);
    mySet.insert(4);

    mySet.display();
    std::cout << "Set size : " << mySet.size() << "\n";
    
    mySet.erase(2);
    mySet.display();
    std::cout << "Set size : " << mySet.size() << "\n";
    std::cout << "7 Contain? : " << (mySet.contains(7) ? "YES" : "No") << "\n";
    std::cout << "5 Contain? : " << (mySet.contains(5) ? "YES" : "No") << "\n";
}
