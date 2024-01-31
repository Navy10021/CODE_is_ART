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
    Node<T>* top; // Points to the top of the stack

public:
    Stack() : top(nullptr) {}

    // Push operation to add an element to the top of the stack
    void push(T value) {
        Node<T> * newNode = new Node<T>(value);  // new Node Class ; int * ptr = new int  && delete ptr 
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
        delete temp;      // delete Node class free() 

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

// Derived StackWithSum class that extends Stack(inheritance from BaseStack)
template <typename T>
class StackWithSum : public Stack<T> {
private:
    T sum; // Additional variable to keep track of the sum

public:
    StackWithSum() : sum(0) {}

    // Override push method to update the sum
    void push(T value) {
        Stack<T>::push(value);
        sum += value;
    }

    // Override pop method to update the sum
    T pop() {
        if (Stack<T>::isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T poppedValue = Stack<T>::pop();
        sum -= poppedValue;

        return poppedValue;
    }

    // Get the current sum of all elements in the stack
    T getSum() const {
        return sum;
    }
};

// Derived StackWithAverage class that extends StackWithSum(inheritance from StackWithSum)
template <typename T>
class StackWithAverage : public StackWithSum<T> {
private:
    int count; // Additional variable to keep track of the count of elements

public:
    StackWithAverage() : count(0) {}

    // Override push method to update the average
    void push(T value) {
        StackWithSum<T>::push(value);
        count++;
    }

    // Override pop method to update the average
    T pop() {
        if (Stack<T>::isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T poppedValue = StackWithSum<T>::pop();
        count--;

        return poppedValue;
    }

    // Get the current average of all elements in the stack
    double getAverage() const {
        if (count == 0) {
            std::cerr << "Cannot calculate average. Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        return static_cast<double>(StackWithSum<T>::getSum()) / count;
    }
};

int main() {
    // Example usage of StackWithAverage
    StackWithAverage<int> myStackWithAverage;

    myStackWithAverage.push(1);
    myStackWithAverage.push(2);
    myStackWithAverage.push(3);
    myStackWithAverage.push(4);
    myStackWithAverage.push(5);

    std::cout << "Current average: " << myStackWithAverage.getAverage() << std::endl;

    myStackWithAverage.pop();
    std::cout << "Average after pop: " << myStackWithAverage.getAverage() << std::endl;

    return 0;
}