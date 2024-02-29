#include <iostream>
#include <string>

class MyClass {
private:
    std::string data;

public:
    // Constructor
    MyClass(const std::string& initialInput) : data(initialInput) {}

    // Copy constructor (Deep Copy)
    MyClass(const MyClass& other) : data(other.data) {}

    // Assignment operator (Deep Copy)
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        // No explicit memory deallocation needed for std::string
    }

    // Method to display the string
    void display() const {
        std::cout << data;
    }
};

int main() {
    MyClass original("Hello, world!");

    // Using copy constructor
    MyClass deepCopyConstructor(original);

    // Using assignment operator
    MyClass deepCopyAssignment = original;

    // Display the deep copies
    std::cout << "Copy Constructor: ";
    deepCopyConstructor.display();
    std::cout << std::endl;

    std::cout << "Assignment Operator: ";
    deepCopyAssignment.display();
    std::cout << std::endl;

    return 0;
}