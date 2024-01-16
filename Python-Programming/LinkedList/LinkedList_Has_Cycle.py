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
    new_list = LinkedList()
    for e in arr:
        new_list.append(e)
        
    return new_list    

def hasCycle(head):
    # Floyd's algorithm : using two pointers(slow and fast)
    if not head or not head.next:
        return 0
    
    slow = head 
    fast = head.next 
    
    while slow != fast:
        if not fast or not fast.next:
            return 0
        slow = slow.next 
        fast = fast.next.next
    
    return 1 
    
A,B,C,D = Node(3), Node(2), Node(0), Node(4)
LL = LinkedList()
LL.head = A 
A.next = B 
B.next = C 
C.next = D 
D.next = B

if(hasCycle(LL.head)):
    print("This Linked List Has Cyle.")






