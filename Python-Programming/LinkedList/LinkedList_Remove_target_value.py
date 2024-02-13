# LinkedList Merge k-sorted List
class Node:
    def __init__(self, val=None):
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
            self.append(int(c))  # Ensure that values are integers for proper comparison
    
    def copy(self):
        new_list = LinkedList()
        currNode = self.head
        while currNode:
            new_list.append(currNode.val)
            currNode = currNode.next
        return new_list
    
    def display(self):
        elements = []
        currNode = self.head
        while currNode:
            elements.append(currNode.val)
            currNode = currNode.next
        print(" -> ".join(map(str, elements)))


def removeElements(head, target):
    dummy = Node(0)
    dummy.next = head 
    
    # Initializae curr and prev pointers 
    prev, curr = dummy, head 
    
    while curr:
        if curr.val == target:
            prev.next = curr.next # remove node 
        else:
            prev = curr    # move 
        curr = curr.next   # move 
    
    return dummy.next 

input = "1234531"
LL = LinkedList()
LL.strToList(input)
LL.display()

LL.head = removeElements(LL.head, 3)
LL.display()
