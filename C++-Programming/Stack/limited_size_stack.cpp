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
protected:
    Node<T>* top; // Points to the top of the stack

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
    
    Node<T>* getTop() const{
        return top;
    }
};

// Derived LimitedStack class that extends Stack
template <typename T>
class LimitedStack : public Stack<T> {
private:
    int limit; // Maximum number of elements the stack can hold

public:
    // Constructor with a specified limit
    LimitedStack(int sizeLimit) : limit(sizeLimit) {}

    // Override push method to limit the size
    void push(T value) {
        Stack<T>::push(value);

        // Check if the limit is reached and pop the oldest element if needed
        if (size() > limit) {
            T oldest = removed_oldest();
            cout << oldest << " is removed!" << endl;
        }
    }
    T removed_oldest() {
        if (Stack<T>::isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }
        T oldest_node;
        Node<T>* curr = Stack<T>::top;
        while(curr->next->next != nullptr){
            curr = curr->next;
        }
        oldest_node = curr->next->data;
        delete curr->next;     // remove last node
        curr->next = nullptr;  // remove last node
        
        return oldest_node;
    }
    
    
    // Get the maximum size limit of the stack
    int getLimit() const {
        return limit;
    }

    // Get the current size of the stack
    int size() const {
        int count = 0;
        Node<T>* current = Stack<T>::top;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }
};

int main() {
    // Example usage of LimitedStack
    LimitedStack<int> myLimitedStack(3);

    myLimitedStack.push(1);
    myLimitedStack.push(3);
    myLimitedStack.push(2);

    std::cout << "Current size: " << myLimitedStack.size() << std::endl;
    std::cout << "Max limited size: " << myLimitedStack.getLimit() << std::endl;

    myLimitedStack.push(5); // This will remove the oldest element (1)

    std::cout << "Current size after pushing 5: " << myLimitedStack.size() << std::endl;
    
    myLimitedStack.push(10);
    
    cout << "Current size after pushing 10: " << myLimitedStack.size() << std::endl;

    return 0;
}