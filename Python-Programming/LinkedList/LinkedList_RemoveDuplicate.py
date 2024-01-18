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
    
    
# LeetCode 82. Remove Duplicates from Sorted List
def deleteDuplicate(head):
    curr = head
    dummy = Node(0)
    dummy.next = head
    prev = dummy
    
    if (curr is Node or curr.next is None):
        return head
    
    while(curr and curr.next):
        if curr.data == curr.next.data:
            while(curr.data != curr.next.data):
                curr = curr.next
            prev.next = curr.next # remove 
        
        prev = curr
        curr = curr.next
    
    head = dummy.next 
    
    return head
    

inputs = [1,1,2,3,3,4,4,5]
LL = arrToList(inputs)
LL.display()

LL.head = deleteDuplicate(LL.head)
LL.display()


