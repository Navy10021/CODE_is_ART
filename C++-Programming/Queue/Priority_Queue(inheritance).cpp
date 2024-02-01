#include <iostream>

// Node class for the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Base Queue class using linked list
template <typename T>
class Queue {
protected:
    Node<T>* front; // Points to the front of the queue
    Node<T>* rear;  // Points to the rear of the queue
    int size;       // Variable to keep track of the size

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Virtual enqueue operation to add an element to the rear of the queue
    virtual void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    // Dequeue operation to remove and return the element from the front of the queue
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        T dequeuedValue = front->data;
        Node<T>* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;
        size--;

        return dequeuedValue;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Peek operation to get the element at the front of the queue without removing it
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        return front->data;
    }

    // Get the current size of the queue
    int getSize() const {
        return size;
    }
};

// Derived PriorityQueue class that extends Queue (inheritance from BaseQueue)
template <typename T>
class PriorityQueue : public Queue<T> {
public:
    // Override the virtual enqueue method to add elements with priority
    void enqueue(T value) override {
        Node<T>* newNode = new Node<T>(value);

        // Add elements in ascending order : in case smallest value is priority!
        if (this->isEmpty() || value <= this->front->data) {
            newNode->next = this->front;
            this->front = newNode;

            if (this->isEmpty()) {
                this->rear = newNode;
            }

            this->size++;
        } else {
            Node<T>* current = this->front;
            while (current->next != nullptr && value > current->next->data) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;

            if (current == this->rear) {
                this->rear = newNode;
            }

            this->size++;
        }
    }
};

int main() {
    // Example usage of PriorityQueue
    PriorityQueue<int> myPriorityQueue;

    myPriorityQueue.enqueue(3);
    myPriorityQueue.enqueue(1); 
    myPriorityQueue.enqueue(2);

    std::cout << "Front element: " << myPriorityQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myPriorityQueue.dequeue() << std::endl;

    std::cout << "Front element after dequeue: " << myPriorityQueue.peek() << std::endl;

    std::cout << "Updated queue size: " << myPriorityQueue.getSize() << std::endl;

    return 0;
}