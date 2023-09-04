#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "null \n";
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void del_front() {
        if (!head) {
            cout << "Nothing to delete.";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete (temp);
        return;
    }

    int first() {
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

class Stack {
private:
    List list;

public:
    void display(){
        list.display();
    }
    // Push an element onto the stack
    void push(int data) {
        list.insert(data);
    }

    // Pop the top element from the stack
    void pop() {
        list.del_front();
    }

    // Return the top element of the stack
    int top() {
        return list.first();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return list.isEmpty();
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element: " << stack.top() << "\n";
    stack.pop();
    cout << "Popped the top element.\n";

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
