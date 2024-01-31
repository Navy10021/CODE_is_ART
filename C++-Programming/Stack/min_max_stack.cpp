#include <iostream>
using namespace std;
// Node class for the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Base Stack class using linked list
template <typename T>
class Stack {
private:
    Node<T>* top; // Points to the top of the stack && Points to head of LinkedList

public:
    Stack() : top(nullptr) {}

    // Push operation to add an element to the top of the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation to remove and return the element from the top of the stack
    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T poppedValue = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;

        return poppedValue;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Peek operation to get the element at the top of the stack without removing it
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        return top->data;
    }
};

// Derived StackWithMax class that extends Stack
template <typename T>
class StackWithMax : public Stack<T> {
private:
    Stack<T> maxStack; // Additional stack to keep track of maximum values

public:
    // Override push method to update maxStack
    void push(T value) {
        Stack<T>::push(value);

        if (maxStack.isEmpty() || value >= maxStack.peek()) {
            maxStack.push(value);
        }
    }

    // Override pop method to update maxStack
    T pop() {
        if (Stack<T>::isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T poppedValue = Stack<T>::pop();

        if (poppedValue == maxStack.peek()) {
            maxStack.pop();
        }

        return poppedValue;
    }

    // Get the maximum value in the stack
    T getMax() const {
        if (maxStack.isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        return maxStack.peek();
    }
};

// Derived StackWithMin class that extends Stack
template <typename T>
class StackWithMin : public Stack<T> {
private:
    Stack<T> minStack; // Additional stack to keep track of minimum values

public:
    // Override push method to update minStack
    void push(T value) {
        Stack<T>::push(value);

        if (minStack.isEmpty() || value <= minStack.peek()) {
            minStack.push(value);
        }
    }

    // Override pop method to update minStack
    T pop() {
        if (Stack<T>::isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T poppedValue = Stack<T>::pop();

        if (poppedValue == minStack.peek()) {
            minStack.pop();
        }

        return poppedValue;
    }

    // Get the minimum value in the stack
    T getMin() const {
        if (minStack.isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        return minStack.peek();
    }
};

int main() {
    // Base Stack 
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    std::cout << s.peek() << std::endl;
    
    // Example usage of StackWithMax and StackWithMin
    StackWithMax<int> maxStack;
    StackWithMin<int> minStack;

    maxStack.push(1);
    maxStack.push(3);
    maxStack.push(2);
    maxStack.push(10);

    minStack.push(5);
    minStack.push(2);
    minStack.push(8);
    minStack.push(1);

    std::cout << "Max element: " << maxStack.getMax() << std::endl;
    std::cout << "Min element: " << minStack.getMin() << std::endl;

    maxStack.pop();
    minStack.pop();

    std::cout << "Max element after pop: " << maxStack.getMax() << std::endl;
    std::cout << "Min element after pop: " << minStack.getMin() << std::endl;
    
    maxStack.pop();
    minStack.pop();

    std::cout << "Max element after pop: " << maxStack.getMax() << std::endl;
    std::cout << "Min element after pop: " << minStack.getMin() << std::endl;

    return 0;
}