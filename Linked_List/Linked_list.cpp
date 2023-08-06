#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void printList(){
        struct Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void push_back(int data){
        Node* temp = new Node(data);

        if (head == NULL) head = temp;
        else{
            Node* last_node = head;
            while(last_node->next != NULL){
                last_node = last_node->next;
            } 
            last_node->next = temp;
        }
    }

    void del_front(){
        // delete linked list from beginning
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void del_pop(){
        Node* temp = head;
        while(temp->next->next !=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void del_position(int position){
        Node* temp = head;
        Node* prev = head;
        for (int i = 0; i < position; i++){
            if (i == 0 && position == 1){
                head = head->next;
                delete(temp);
            }
            else{
                // 이전 포지션 next값을 연결 후 삭제 
                if (i == position-1 && temp){
                    prev->next = temp->next;
                    delete(temp);
                }
                else {
                    // temp -> next 이동 && prev 이동 
                    prev = temp;
                    if (prev == NULL) break; // Position > len(Linked List)
                    temp = temp->next;
                }
            }
        }
    }
};

int main(){
    LinkedList LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);
    LL.push_back(4);
    LL.push_back(5);
    LL.push(0);
    LL.printList();
    cout << "\n";
    LL.del_position(5);
    LL.printList();
}
