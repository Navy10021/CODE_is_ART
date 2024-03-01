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
    start = head
    while start:
        temp = start
        while temp:
            result.append(copy_linked_list(start, temp))
            temp = temp.next
        start = start.next
    return result

# Adjusted copy function to copy up to a certain node
def copy_linked_list(start, end):
    copy_list = LinkedList()
    currNode = start
    while currNode != end.next and currNode is not None:
        copy_list.append(currNode.val)
        currNode = currNode.next
    return copy_list

# Special Conditions-II
def is_palindrome(linkedList):
    values = []
    curr = linkedList.head
    while curr:
        values.append(curr.val)
        curr = curr.next
    return values == values[::-1]
    
    # Compare 
    first_half = linkedList.head 
    while second_half:
        if first_half.val != second_half.val:
            return False
        first_half = first_half.next 
        second_half = second_half.next 
    
    return True 


input = "radar";
LL = LinkedList()
LL.strToList(input)

subLists = all_substrings(LL.head)
# Special condition
for ll in subLists:
    if is_palindrome(ll):
        ll.display()
