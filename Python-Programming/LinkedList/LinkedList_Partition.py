class Node:
    def __init__(self, data = 0, next = None):
        self.data = data 
        self.next = next

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

    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        print(" -> ".join(map(str, elements)))

def arrToList(arr):
    ll = LinkedList()
    for e in arr:
        ll.append(e)
    return ll 
    
    
# LeetCode 86 : Partition List 
# Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
def partition(head, x):
    dummy_low = Node(0)
    dummy_high = Node(0)
    low, high = dummy_low, dummy_high

    curr = head

    while curr:
        if curr.data < x:
            low.next = curr
            low = low.next
        else:
            high.next = curr
            high = high.next

        curr = curr.next

    # Combine the two partitions
    low.next = dummy_high.next
    high.next = None  # Set the end of the higher partition to None

    # Set the head to the beginning of the lower partition
    head = dummy_low.next

    return head

inputs = [1, 4, 3, 2, 5, 2]
LL = arrToList(inputs)
LL.display()

LL.head = partition(LL.head, 3)
LL.display()



