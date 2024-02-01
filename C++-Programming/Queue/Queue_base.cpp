#include <iostream>

// Node class for the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Queue class using linked list
template <typename T>
class Queue {
private:
    Node<T>* front; // Points to the front of the queue
    Node<T>* rear;  // Points to the rear of the queue
    int size;       // Variable to keep track of the size

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(T value) {
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

int main() {
    // Example usage of Queue
    Queue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Queue size: " << myQueue.getSize() << std::endl;

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

    std::cout << "Front element after dequeue: " << myQueue.peek() << std::endl;

    std::cout << "Updated queue size: " << myQueue.getSize() << std::endl;

    return 0;
}