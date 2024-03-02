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
        
    def copy(self):
        copied_list = LinkedList()
        currNode = self.head 
        while currNode:
            copied_list.append(currNode.val)
            currNode = currNode.next
        return copied_list
    
# 두개의 리스트가 같은지 확인하는 함수
def is_same(list1, list2):
    curr_1 = list1.head 
    curr_2 = list2.head
    
    while curr_1 and curr_2:
        if curr_1.val != curr_2.val:
            return False
        
        curr_1 = curr_1.next 
        curr_2 = curr_2.next 
    
    return curr_1 is None and curr_2 is None 

def is_anagram(list1, list2):
    value_counts = {}

    curr_1 = list1.head
    while curr_1:
        # Increment the count for the current value in list1
        if curr_1.val in value_counts:
            value_counts[curr_1.val] += 1
        else:
            value_counts[curr_1.val] = 1
        curr_1 = curr_1.next

    curr_2 = list2.head
    while curr_2:
        # Decrement the count for the current value in list2
        if curr_2.val in value_counts:
            value_counts[curr_2.val] -= 1
        else:
            # If the value is not in the hash, lists can't be anagrams
            return False
        curr_2 = curr_2.next

    # Check if all counts are zero
    for count in value_counts.values():
        if count != 0:
            return False

    return True

input1 = [2,8,7,7]
input2 = [7,2,8,7]
LL1 = LinkedList()
LL2 = LinkedList()
LL1.strToList(input1)
LL2.strToList(input2)

print(is_anagram(LL2, LL1))

    
