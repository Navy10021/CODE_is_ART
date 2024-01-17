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


# Insertion sorting in linked list 
def insertionSort(head):
    if not head and head.next:
        return head 
    
    sorted_head = None 
    currNode = head 
    
    while currNode:
        nextNode = currNode.next 
        sorted_head = insertIntoSorted(sorted_head, currNode)
        currNode = nextNode
    
    return sorted_head

# Insertion into sorted linked list 
def insertIntoSorted(sorted_head, new_node):
    if not sorted_head or sorted_head.data >= new_node.data:
        new_node.next = sorted_head
        return new_node
    
    currNode = sorted_head
    while(currNode.next and currNode.next.data < new_node.data):
        currNode = currNode.next
    
    new_node.next = currNode.next 
    currNode.next = new_node
    
    return sorted_head


L = [3, 2, 4, 2, 1, 3, 4, 4, 3, 4]
LL = arrToList(L)
LL.display()

LL.head = insertionSort(LL.head)
LL.display()