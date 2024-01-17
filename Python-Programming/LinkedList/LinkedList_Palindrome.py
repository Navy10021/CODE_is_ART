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
    
# Palindrome Linked List 
def isPalindrome(head):
    # Find middle
    slow = fast = head 
    while fast and fast.next :
        slow = slow.next 
        fast = fast.next.next
    
    # Reverse second half 
    second_half = None 
    while slow:
        temp = slow.next 
        slow.next = second_half
        second_half = slow
        slow = temp 
    
    # Compare first and second 
    first_half = head 
    while second_half:
        if first_half.data != second_half.data:
            return False 
        first_half = first_half.next 
        second_half = second_half.next 
    
    return True

L = ['A','B','C','B','A']
LL = arrToList(L)
LL.display()

if (isPalindrome(LL.head)):
    print("This Linked List is Palindrome")
else:
    print("No Palindrome")


