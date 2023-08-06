#include<bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node{
    int data;
    struct Node* next;
    // 데이터 + 포인터 저장 
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Linked List 
struct LinkedList{
    // Head 만들기
    Node* head;
    LinkedList(){
        head = NULL;
    }
    // print 
    void printList(){
        // Head 노드 저장 -> temp가 없을때까지 next && print
        struct Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    // push : add front
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

    // reverse with stack
    void reverseList(){
        // 스택생성 
        stack<Node*> S;
        Node* temp = head;
        // 리스트를 스택에 넣기
        while (temp->next != NULL){
            S.push(temp);
            temp = temp->next;
        }
        // 마지막 노드를 Head값으로 정의 
        head = temp;
        // 스택이 빌때까지 Top을 연결 
        while(!S.empty()){
            temp->next = S.top();
            S.pop();
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

int main(){
    LinkedList LL;
    LL.push(1);
    LL.push(2);
    LL.push(3);
    LL.push_back(4);
    LL.printList();
    cout << "\n";
    LL.reverseList();
    LL.printList();
}
