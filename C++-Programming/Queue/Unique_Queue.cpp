#include <iostream>
#include <unordered_set>

// Derived UniqueQueue class that extends Queue (inheritance from BaseQueue)
template <typename T>
class UniqueQueue : public Queue<T> {
private:
    std::unordered_set<T> uniqueElements; // To store unique elements

public:
    // Override the virtual enqueue method to add unique elements to the queue
    void enqueue(T value) override {
        if (uniqueElements.find(value) == uniqueElements.end()) {
            Node<T>* newNode = new Node<T>(value);

            if (this->isEmpty()) {
                this->front = this->rear = newNode;
            } else {
                this->rear->next = newNode;
                this->rear = newNode;
            }

            uniqueElements.insert(value);
            this->size++;
        }
    }
};

int main() {
    // Example usage of UniqueQueue
    UniqueQueue<int> myUniqueQueue;

    myUniqueQueue.enqueue(2);
    myUniqueQueue.enqueue(4);
    myUniqueQueue.enqueue(2); // Should not be added
    myUniqueQueue.enqueue(6);

    std::cout << "Front element: " << myUniqueQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myUniqueQueue.dequeue() << std::endl;

    std::cout << "Front element after dequeue: " << myUniqueQueue.peek() << std::endl;

    std::cout << "Updated queue size: " << myUniqueQueue.getSize() << std::endl;

    return 0;
}