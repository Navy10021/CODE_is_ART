class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        data = self.top.data
        self.top = self.top.next
        self.size -= 1
        return data

    def peek(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        return self.top.data

    def __len__(self):
        return self.size

    def __str__(self):
        if self.is_empty():
            return "Stack is empty"
        current = self.top
        items = []
        while current:
            items.append(str(current.data))
            current = current.next
        return " -> ".join(items)

# Example usage:
if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)

    print("Stack:", stack)  # Output: Stack: 3 -> 2 -> 1

    print("Pop:", stack.pop())  # Output: Pop: 3
    print("Peek:", stack.peek())  # Output: Peek: 2
    print("Stack size:", len(stack))  # Output: Stack size: 2
