# Combination based Subseqence
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
        curr = self.head 
        while curr.next:
            curr = curr.next 
        curr.next = newNode
    
    def buildList(self, l):
        for e in l:
            self.append(e)


def display(head):
    elements = []
    curr = head 
    while curr:
        elements.append(curr.val)
        curr = curr.next 
    print(' -> '.join(map(str,elements)))

def listPop(head):
    if head is None:
        return 
    elif head.next is None:
        head = None 
    else:
        curr = head 
        while curr.next.next:
            curr = curr.next 
        curr.next = None 

def printCombinations(linkedArr):
    def generateCombinations(node, k, curr_arr):
        # Base case 
        if k == 0:
            if curr_arr not in combinaions:
                combinaions.append(curr_arr)
                display(curr_arr.head)
            return 
        
        if not node:
            return 
        # Include current node in path
        curr_arr.append(node.val)
        generateCombinations(node.next, k-1, curr_arr)
        # Exclude current node and move to next
        listPop(curr_arr.head)
        generateCombinations(node.next, k, curr_arr)
    
    def listSize(node):
        size = 0
        while node:
            size += 1 
            node = node.next 
        return size 
    
    size = listSize(linkedArr.head)
    combinaions = []
    # generate k-length linkedList 
    for k in range(1, size + 1):
        curr_combination = LinkedList()
        generateCombinations(linkedArr.head, k, curr_combination)
    
    return combinaions
    
    
List = [1,2,2]
LL = LinkedList() 
LL.buildList(List)
display(LL.head)
combi = printCombinations(LL)