class Node:
    def __init__(self, val = None):
       self.val = val
       self.next = None 
        
class LinkedList:
    def __init__(self):
        self.head = None 
    
    def is_empty(self):
        return self.head is None 
    
    def length(self):
        count = 0;
        currNode = self.head 
        while currNode:
            count += 1
            currNode = currNode.next 
        return count 
    
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
    
    def toStr(self):
        elements = []
        currNode = self.head 
        while currNode:
            elements.append(currNode.val)
            currNode = currNode.next 
        return "".join(map(str, elements))
    
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
    
    # Remove last element from the linked list == POP()
    def remove_last(self):
        if self.is_empty():
            return 
        elif self.head.next is None:
            self.head = None 
        else:
            currNode = self.head 
            while currNode.next.next:
                currNode = currNode.next
            currNode.next = None  # Remove last Node 
        

def all_subsequences(head):
    result = []
    curr_sequence = LinkedList()
    
    def generate_subseq(node):
        if not node:
            # Check if duplicated linkedList 
            flag = 0
            curr_str = curr_sequence.toStr()
            for i in result:
                if (curr_str == i.toStr()):
                    flag = 1
                    break
            if (flag == 0):    
                result.append(curr_sequence.copy())
            return 
        
        # Include current node in subseq
        curr_sequence.append(node.val)
        generate_subseq(node.next)
        # Exclude current node in subseq
        curr_sequence.remove_last()   # pop()
        generate_subseq(node.next)
    
    generate_subseq(head)
    
    return result

# Special Condtion-II : palindrome check to use a list conversion
def is_palindrome(linkedList):
    values = []
    curr = linkedList.head
    while curr:
        values.append(curr.val)
        curr = curr.next
    return values == values[::-1]


input = "carracer"
LL = LinkedList()
LL.strToList(input)

# Condition-III : Maximum length linked list
subLists = all_subsequences(LL.head)
max_len = 0;
max_palindrome = None 
for l in subLists:
    if (is_palindrome(l) and l.length() > max_len):
        max_len = l.length()
        max_palindrome = l

print("Maximum subsequence palindrome : ", end=' ')
max_palindrome.display()
