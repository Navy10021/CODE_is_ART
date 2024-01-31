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

// Derived PalindromeChecker class that extends Stack
class PalindromeChecker : public Stack<char> {
public:
    // Check if a given string is a palindrome
    bool isPalindrome(const std::string& sequence) {
        // Push the first half of the characters onto the stack
        for (size_t i = 0; i < sequence.length() / 2; i++) {
            push(sequence[i]);
        }

        // Check the second half of the characters with the elements from the stack
        size_t start = (sequence.length() + 1) / 2; // Skip the middle character for odd-length strings
        for (; start < sequence.length(); start++) {
            if (sequence[start] != pop()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Example usage of PalindromeChecker
    PalindromeChecker palindromeChecker;

    std::string palindrome1 = "racecar";
    std::string palindrome2 = "level";
    std::string notPalindrome = "hello";

    std::cout << palindrome1 << " is a palindrome: " << std::boolalpha << palindromeChecker.isPalindrome(palindrome1) << std::endl;
    std::cout << palindrome2 << " is a palindrome: " << std::boolalpha << palindromeChecker.isPalindrome(palindrome2) << std::endl;
    std::cout << notPalindrome << " is a palindrome: " << std::boolalpha << palindromeChecker.isPalindrome(notPalindrome) << std::endl;

    return 0;
}