#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
};

class List{
    private:
        Node* head;
    public:
        List() : head(nullptr) {}

        void distplay(){
            Node* curr = head;
            while (curr){
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "null \n";
        }

        // Insert new node with data at the front of the list
        void insert(int data){
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        
        // Delete the first node
        void del_front(){
            if (!head){
                cout << "Noting to delete.";
                return;
            }
            Node*temp = head;
            head = head->next;
            delete(temp);   // 삭제 : 메모리할당 취소
            return;
        }

        // returns the value of the first node
        int first(){
            return head->data;
        }

        // Check if the list is empty
        bool isEmpty(){
            return head == nullptr;
        }
};

int main(){
    List linked_list;
    linked_list.insert(1);
    linked_list.insert(2);
    linked_list.insert(3);
    linked_list.insert(4);
    linked_list.insert(5);
    linked_list.distplay();
    linked_list.del_front();
    linked_list.distplay();
    int res = linked_list.first();
    cout << res << "\n";
    linked_list.del_front();
    cout << linked_list.isEmpty() << "\n";
    linked_list.del_front();
    cout << linked_list.isEmpty() << "\n";
    linked_list.del_front();
    cout << linked_list.isEmpty() << "\n";
    linked_list.del_front();
    cout << linked_list.isEmpty() << "\n";
}
