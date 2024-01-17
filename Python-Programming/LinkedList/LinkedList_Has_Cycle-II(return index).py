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


# Linked List Cycle II : return the node(tail connects index) where the cycle is begins.

def detectCycle(head):
    # using set()
    seen = set()
    currNode = head
    
    while currNode:
        if currNode in seen:
            break 
        seen.add(currNode)
        currNode = currNode.next 
    
    # Find detected index 
    idx = 0 
    checkNode = head 
    while(checkNode):
        if checkNode == currNode:
            return idx 
        
        idx += 1 
        checkNode = checkNode.next 
    
    if checkNode == None:
        print("No detected Cycle.")
    
    
A,B,C,D = Node(3), Node(2), Node(0), Node(4)
LL = LinkedList()
LL.head = A 
A.next = B 
B.next = C 
C.next = D 
#D.next = C

print(detectCycle(LL.head))






