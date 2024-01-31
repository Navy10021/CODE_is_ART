#include <iostream>
#include <string>

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

// Derived SyntaxChecker class that extends Stack
class SyntaxChecker : public Stack<char> {
public:
    // Check if the brackets in the given sequence are properly balanced
    bool isBalanced(const std::string& sequence) {
        for (char bracket : sequence) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                // If it's an opening bracket, push onto the stack
                push(bracket);
            } else if (bracket == ')' || bracket == ']' || bracket == '}') {
                // If it's a closing bracket, check if it matches the corresponding opening bracket
                if (isEmpty() || !isMatchingPair(peek(), bracket)) {
                    return false;
                }
                // If it matches, pop the opening bracket from the stack
                pop();
            }
        }

        // The sequence is balanced if the stack is empty at the end
        return isEmpty();
    }

private:
    // Helper function to check if two brackets form a matching pair
    bool isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') ||
               (opening == '[' && closing == ']') ||
               (opening == '{' && closing == '}');
    }
};

int main() {
    // Example usage of SyntaxChecker
    SyntaxChecker syntaxChecker;

    std::string balancedSequence = "{[()]()}";
    std::string unbalancedSequence = "([)]";

    std::cout << balancedSequence << " is balanced: " << std::boolalpha << syntaxChecker.isBalanced(balancedSequence) << std::endl;
    std::cout << unbalancedSequence << " is balanced: " << std::boolalpha << syntaxChecker.isBalanced(unbalancedSequence) << std::endl;

    return 0;
}