class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularQueue:
    def __init__(self, max_size):
        self.max_size = max_size
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.max_size

    def enqueue(self, data):
        if self.is_full():
            raise Exception("Queue is full")
        new_node = Node(data)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.rear.next = self.front
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        data = self.front.data
        if self.front == self.rear:
            self.front = self.rear = None
        else:
            self.front = self.front.next
            self.rear.next = self.front
        self.size -= 1
        return data

    def peek(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.front.data

    def __len__(self):
        return self.size

    def __str__(self):
        if self.is_empty():
            return "Queue is empty"
        current = self.front
        items = []
        while True:
            items.append(str(current.data))
            current = current.next
            if current == self.front:
                break
        return " -> ".join(items)

# Example usage:
if __name__ == "__main__":
    cq = CircularQueue(5)
    cq.enqueue(1)
    cq.enqueue(2)
    cq.enqueue(3)

    print("Circular Queue:", cq)  # Output: Circular Queue: 1 -> 2 -> 3

    print("Dequeue:", cq.dequeue())  # Output: Dequeue: 1
    print("Peek:", cq.peek())        # Output: Peek: 2
    print("Queue size:", len(cq))    # Output: Queue size: 2

    cq.enqueue(4)
    cq.enqueue(5)
    print("Circular Queue:", cq)  # Output: Circular Queue: 2 -> 3 -> 4 -> 5

    cq.enqueue(6)  # This will raise an exception because the queue is full
