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

    def swap(self, node1, node2):
        temp = node1.val
        node1.val = node2.val
        node2.val =temp 
        
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

# Permutation 
def permutation_LinkedList(linked_list):
    def backtrack(start_node):
        if not start_node.next:
            all_permutations.append(linked_list.copy())
            return

        seen = set()        # To keep track of unique elements at given postion
        curr_node = start_node
        while(curr_node):
            if (curr_node.val not in seen):
                seen.add(curr_node.val)
                linked_list.swap(start_node, curr_node)
                backtrack(start_node.next)
                linked_list.swap(start_node, curr_node)
            curr_node = curr_node.next 
    
    all_permutations = []
    backtrack(linked_list.head)
    
    return all_permutations

def is_anagram(list1, list2):
    
    permutations = permutation_LinkedList(list1)
    for ll in permutations:
        if is_same(ll, list2):
            return True
    
    return False 
    

input1 = [2,8,7,7]
input2 = [7,2,7,7]
LL1 = LinkedList()
LL2 = LinkedList()
LL1.strToList(input1)
LL2.strToList(input2)

print(is_anagram(LL1, LL2))
