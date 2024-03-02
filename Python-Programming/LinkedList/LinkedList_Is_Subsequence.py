# 두개의 링크드 리스트가 서브시퀀스 인지 확인
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
    
# 두개의 리스트가 서브 시퀀스인지 확인 : list1 <= list2
def is_subsequence(list1, list2):
    curr_1 = list1.head 
    curr_2 = list2.head 
    
    while curr_1 and curr_2:
        if curr_1.val == curr_2.val:
            curr_1 = curr_1.next 
        
        curr_2 = curr_2.next 
    
    # curr_1이 없으면 list1은 list2의 subsequence
    return curr_1 is None 


input1 = ['C','A','R']
input2 = ['C','O','C','A','R','R']
LL1 = LinkedList()
LL2 = LinkedList()
LL1.strToList(input1)
LL2.strToList(input2)

print(is_subsequence(LL1, LL2))
