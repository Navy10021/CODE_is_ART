class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def reverse(self):
        prev = None
        curr = self.head 
        while (curr is not None):
            next = curr.next 
            curr.next =prev 
            prev = curr 
            curr = next 
        self.head = prev 
        
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head 
        self.head = new_node
    
    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data, end = " ")
            temp = temp.next
            
LL = LinkedList()
LL.push(1)
LL.push(2)
LL.push(3)
LL.push(4)
LL.printList()
print("\n")
LL.reverse()
LL.printList()
