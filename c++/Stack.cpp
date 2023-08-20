#include<iostream>

class Node {
    public : 
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
};

// Stack Class
class Stack {
    private :
    Node* top;
    
    public :
    Stack() : top(nullptr) {}
    
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (isEmpty()){
            std::cout << "Stack is empty." << "\n";
            return;
        }
        // else
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if (isEmpty()){
            std::cout << "Stack is empty." << "\n";
            return -1;
        }
        // else
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    int size() {
        int cnt = 0;
        Node* curr = top;
        while(curr != nullptr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    void display(){
        Node* curr = top;
        while(curr != nullptr){
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    ~Stack(){
        while (!isEmpty()){
            pop();
        }
    }
};


int main(){
    Stack S;
    S.push(0);
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(50);
    S.display();

    std::cout << "Top element : " << S.peek() << "\n";
    std::cout << "Stack size : " << S.size() << "\n";
    S.pop();
    S.display();
}
