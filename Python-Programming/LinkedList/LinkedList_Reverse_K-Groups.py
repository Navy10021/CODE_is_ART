class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

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
        
    def copy(self):
        new_linked_list = LinkedList()
        current_node = self.head
        while current_node:
            new_linked_list.append(current_node.data)
            current_node = current_node.next
        return new_linked_list

    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        print(" -> ".join(map(str, elements)))


def list_to_LinkedList(List):
    linked_list = LinkedList()
    
    for element in List:
        linked_list.append(element)
    
    return linked_list


# 25. Revers K-Group : Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

def reverseGroup(head, k):
    
    def reverse_linked_list(start, end):    # start node ~ end node
        prev, curr = None, start 
        while(curr != end):
            temp = curr.next 
            curr.next = prev 
            prev, curr = curr, temp 
        return prev 
        
    count = 0 
    currNode = head
    # Find end : k-Move to end and next end ... 
    while(count < k and currNode):
        currNode = currNode.next 
        count += 1 
    # if count is short no reverse
    if count < k:
        return head 
    
    # Reverse 
    reversed_head = reverse_linked_list(head, currNode)
    head.next = reverseGroup(currNode, k)
    
    return reversed_head

input = [1,2,3,4,5,6,7,8,9]
my_LL = list_to_LinkedList(input)
my_LL.display()

newLL = LinkedList()
newLL.head = reverseGroup(my_LL.head, 3)
newLL.display()

