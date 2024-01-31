#include <iostream>
#include <stack>

// Derived QueueUsingStacks class that implements a queue using two stacks
template <typename T>
class QueueUsingStacks {
private:
    std::stack<T> stack1; // For enqueue operation
    std::stack<T> stack2; // For dequeue operation

public:
    // Enqueue operation to add an element to the back of the queue
    void enqueue(T value) {
        stack1.push(value);
    }

    // Dequeue operation to remove and return the front element of the queue
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        // If stack2 is empty, transfer elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop from stack2 to dequeue
        T frontElement = stack2.top();
        stack2.pop();

        return frontElement;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    // Example usage of QueueUsingStacks
    QueueUsingStacks<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

    myQueue.enqueue(4);

    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    std::cout << "Is the queue empty? " << std::boolalpha << myQueue.isEmpty() << std::endl;

    return 0;
}