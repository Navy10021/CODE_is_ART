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


def all_substrings(head):
    result = []
    
    # Traverse each Node
    currNode = head 
    while currNode:
        # Generate substring start from Current Node
        result.append(copy_linked_list(currNode))
        currNode = currNode.next 
        
    return result

# Help function(Copy function)
def copy_linked_list(head):
    copy_list = LinkedList()
    currNode = head 
    while currNode:
        copy_list.append(currNode.val)
        currNode = currNode.next 
    return copy_list
        
input = ['A','B','C','D','E']
#input = "ABCDE"  # same
LL = LinkedList()
LL.strToList(input)
#LL.display()

subLists = all_substrings(LL.head)
for l in subLists:
    l.display()

