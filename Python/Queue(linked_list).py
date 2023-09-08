class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def enqueue(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    # pop_left()
    def dequeue(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        data = self.front.data
        self.front = self.front.next
        self.size -= 1
        if self.is_empty():
            self.rear = None
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
        while current:
            items.append(str(current.data))
            current = current.next
        return " -> ".join(items)

# Example usage:
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)

    print("Queue:", queue)  # Output: Queue: 1 -> 2 -> 3

    print("Dequeue:", queue.dequeue())  # Output: Dequeue: 1
    print("Peek:", queue.peek())  # Output: Peek: 2
    print("Queue size:", len(queue))  # Output: Queue size: 2
