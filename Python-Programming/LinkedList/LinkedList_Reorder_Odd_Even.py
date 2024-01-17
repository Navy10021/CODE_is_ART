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


# LeetCode 328 Odd Even Linked List : retrun Reorder list Odd indcice + Even indcice

def oddEvenList(head):
    if not head or not head.next:
        return head 
    
    odd_dummy = Node(0)
    even_dummy = Node(0)
    odd_node = odd_dummy
    even_node = even_dummy
    
    is_odd = True 
    
    while head:
        if is_odd:
            odd_node.next = head 
            odd_node = odd_node.next 
        else:
            even_node.next = head 
            even_node = even_node.next
        
        is_odd = not is_odd
        head = head.next 
    
    # Termination and Connection
    even_node.next = None 
    odd_node.next = even_dummy.next 
    
    head = odd_dummy.next
    
    return head


L = [1,2,3,4,5]
LL = arrToList(L)
LL.display()

LL.head = oddEvenList(LL.head)
LL.display()