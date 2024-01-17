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


# LeetCode 2095 : Delete the Middle Node of a linked list

def deleteMiddle(head):
    # Find middle 
    slow = fast = head
    prev = None 
    
    while fast and fast.next:
        prev = slow
        slow = slow.next 
        fast = fast.next.next 
    
    #middle = slow
    if prev:
        prev.next = slow.next 
    else:
        head = head.next
    
    return head

L = [1,2,3,4,5]
LL = arrToList(L)
LL.display()

LL.head = deleteMiddle(LL.head)
LL.display()