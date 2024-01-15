class Node:
    def __init__(self, val = None):
       self.val = val
       self.next = None 
        
class LinkedList:
    def __init__(self):
        self.head = None 
    
    def is_empty(self):
        return self.head is None 
  
    def append(self, val):
        newNode = Node(val)
        if self.is_empty():
            self.head = newNode
            return 
        currNode = self.head 
        while currNode.next:
            currNode = currNode.next
        currNode.next = newNode
    
    def strToList(self, str):
        for c in str:
            self.append(c)
    
    def display(self):
        elements = []
        currNode = self.head 
        while currNode:
            elements.append(currNode.val)
            currNode = currNode.next
        print(" -> ".join(map(str, elements)))

def kLeftRotation(head, k):
    # Handle edge case
    if not head or k == 0:
        return head
    
    # Find the length of Linked List
    len = 1
    currNode = head
    while(currNode.next):
        len += 1
        currNode = currNode.next
    
    rotation_count = k % length
    if rotation_count == 0:
        return head 
    
    # Traver to the node Postition and Cut
    currNode = head 
    for _ in range(rotation_count):
        currNode = currNode.next
    
    # Make New Linked List and Cut Original Linked List tail
    new_head = currNode.next
    currNode.next = None
    
    # Connecte two Linked List
    currNode = new_head
    while(currNode):
        currNode = currNode.next
    currNode.next = head
    
    return new_head

def kRightRotation(head, k):
    # Handle edge case
    if not head or k == 0:
        return head

    # Find the length of the linked list
    length = 1
    currNode = head
    while(currNode.next):
        length += 1
        currNode = currNode.next

    # Calculate the effective rotation count
    rotation_count = k % length

    if rotation_count == 0:
        return head 

    # Traver to the node at Position and Cut
    currNode = head
    for _ in range(length - rotation_count - 1):
        currNode = currNode.next

    # Make new linked list and Cut
    new_head = currNode.next
    currNode.next = None 

    # Find new linked list tail and Connect
    currNode = new_head 
    while currNode.next:
        currNode = currNode.next
    currNode.next = head
    return new_head

    
input = "12345"
LL = LinkedList()
LL.strToList(input)

LL.head = kRightRotation(LL.head, 2)
LL.display()
LL.head = kLeftRotation(LL.head, 2)
LL.display()