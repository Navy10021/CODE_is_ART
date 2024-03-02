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
    
# 서브시퀀스 이후에 해당되지 않는 노드를 정렬해서 추가하는 함수
def reorder(list1, list2):
    curr_1 = list1.head 
    curr_2 = list2.head 
    rest = []
    while curr_1:
        if curr_1.val == curr_2.val:
            curr_1 = curr_1.next 
            curr_2 = curr_2.next 
        else:
            rest.append(curr_2.val)
            curr_2 = curr_2.next  
    
    rest.sort() # 정렬
    while curr_2:
        rest.append(curr_2.val)
        curr_2 = curr_2.next
        
    for node in rest:
        list1.append(node)
    
    list1.display()


input1 = [1,2]
input2 = [1,3,2,4,5]
LL1 = LinkedList()
LL2 = LinkedList()
LL1.strToList(input1)
LL2.strToList(input2)

reorder(LL1, LL2)
