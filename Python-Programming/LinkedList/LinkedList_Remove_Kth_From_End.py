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

# Remove N-th Node Frome End of list 
def removeNthFromEnd(head, n):
    dummy = Node(0)
    dummy.next = head 
    first = second = dummy
    
    # Find target Node 
    for _ in range(n + 1):
        first = first.next 
    
    while first:
        first = first.next 
        second = second.next 
    
    # Remove target Node
    second.next = second.next.next
    
    return dummy.next 
    

L = [1,2,3,4,5,6]
LL = arrToList(L)
LL.display()

newLL = LinkedList()
newLL.head = removeNthFromEnd(LL.head, 3)
newLL.display()
    