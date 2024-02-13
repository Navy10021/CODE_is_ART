class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None
    # Comparison method to make Node compatible with heapq
    def __lt__(self, other):
        return self.val < other.val

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
            self.append(int(c))  # Ensure that values are integers for proper comparison
    
    def copy(self):
        new_list = LinkedList()
        currNode = self.head
        while currNode:
            new_list.append(currNode.val)
            currNode = currNode.next
        return new_list
    
    def display(self):
        elements = []
        currNode = self.head
        while currNode:
            elements.append(currNode.val)
            currNode = currNode.next
        print(" -> ".join(map(str, elements)))

import heapq

def mergeKLists(lists):
    heap = []
    for head in lists:
        curr = head
        while curr:
            heapq.heappush(heap, (curr.val, curr))
            curr = curr.next
    
    dummy = Node(0)
    curr = dummy
    
    while heap:
        _, node = heapq.heappop(heap)
        curr.next = node
        curr = curr.next
        # As nodes are individually pushed, avoid creating cycles
        node.next = None
    
    result = LinkedList()
    result.head = dummy.next
    return result

# Input setup
input1 = "145"
input2 = "135"
input3 = "26"
LL1 = LinkedList()
LL2 = LinkedList()
LL3 = LinkedList()
LL1.strToList(input1)
LL2.strToList(input2)
LL3.strToList(input3)

kLists = [LL1.head, LL2.head, LL3.head]
mergedList = mergeKLists(kLists)
mergedList.display()
