class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def copy(self):
        new_linked_list = LinkedList()
        current_node = self.head
        while current_node:
            new_linked_list.append(current_node.data)
            current_node = current_node.next
        return new_linked_list

    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        print(" -> ".join(map(str, elements)))

    def reverse(self, left, right):
        if left >= right or not self.head:
            return
        
        # make prev with dummy node 
        dummy = Node(0)
        dummy.next = self.head
        prevNode = dummy
        
        # Move to node position 'left - 1'
        for _ in range(left - 1):
            prevNode = prevNode.next 
        
        # Reverse 
        currNode = prevNode.next 
        nextNode = None 
        
        for _ in range(right - left + 1):
            temp = currNode.next 
            currNode.next = nextNode
            nextNode = currNode
            currNode = temp
        
        # Connect
        prevNode.next.next = currNode
        prevNode.next = nextNode
        
        self.head = dummy.next 
        
        return self.head
        

def list_to_LinkedList(List):
    linked_list = LinkedList()

    for element in List:
        linked_list.append(element)

    return linked_list

# 96. Reverse Linked List left to right.

input = [1, 2, 3, 4, 5, 6, 7, 8, 9]
my_LL = list_to_LinkedList(input)
my_LL.display()

my_LL.reverse(2, 5)
my_LL.display()


