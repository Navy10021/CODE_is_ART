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


def printCombinations(linkedArr):
    def generateCombinations(node, k, path = []):
        # Base case 
        if k == 0:
            if path not in combinaions:
                combinaions.append(path)
                #print(' -> '.join(map(str, path)))
            return 
        
        if not node:
            return 
        # Include current node in path 
        generateCombinations(node.next, k-1, path + [node.val])
        # Exclude current node and move to next 
        generateCombinations(node.next, k, path)
    
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
        generateCombinations(linkedArr.head, k)
    
    return combinaions
    
    
List = [1,2,2]
LL = LinkedList() 
LL.buildList(List)
display(LL.head)
combi = printCombinations(LL)
print(combi)




