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
    
# Merge Two ordered Linked List with Sorting 
def mergeTwoList(LL1, LL2):
    # new Linked List 
    dummy = Node(0)
    currNode = dummy 
    
    while LL1 and LL2:
        if LL1.data < LL2.data:
            currNode.next = LL1 
            LL1 = LL1.next 
        else:
            currNode.next = LL2 
            LL2 = LL2.next 
        currNode = currNode.next 
    
    # Add rest node 
    currNode.next = LL1 or LL2
    
    head = dummy.next 
    return head 

L1 = ['A','B','C']
L2 = ['B','C','D','E','F']
LL1 = arrToList(L1)
LL2 = arrToList(L2)

newLL = LinkedList()
newLL.head = mergeTwoList(LL1.head, LL2.head)
newLL.display()
