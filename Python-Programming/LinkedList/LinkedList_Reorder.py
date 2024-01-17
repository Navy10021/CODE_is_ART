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
    
# 143. Reorder List : L0 -> Ln -> L1 -> Ln-1 -> L2 ...
def reorderList(head):
    # 1. Find middle 
    slow = head 
    fast = head 
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next 
    
    # Now middle is slow  
    # 2. Reverse Second list 
    second_half = None 
    while slow :
        temp = slow.next 
        slow.next = second_half
        second_half = slow 
        slow = temp 
    
    # 3. Merge First and Second List Directly in-place
    first_half = head 
    while second_half.next:
        # Save orginal next 
        temp1 = first_half.next 
        temp2 = second_half.next 
        
        # Connect
        first_half.next = second_half
        second_half.next = temp1 
        
        # Move to original next
        first_half = temp1
        second_half = temp2
    
    return head


L = [1,2,3,4,5]
LL = arrToList(L)
LL.display()

newLL = LinkedList()
newLL.head = reorderList(LL.head)
newLL.display()


