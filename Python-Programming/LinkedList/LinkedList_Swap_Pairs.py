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

    def swap(self, node1, node2):
        temp = node1.data
        node1.data = node2.data
        node2.data =temp 

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


# 24. Swap Nodes in Pairs : Given a linked list, swap every two adjacent nodes and return its head.
 
def swapPairs(head):
    currNode = head
    while(currNode and currNode.next):
        # swap(currNode, currNode.next)
        temp = currNode.data
        currNode.data = currNode.next.data
        currNode.next.data = temp
        currNode = currNode.next.next
    

input = [1,2,3,4,5]
my_LL = list_to_LinkedList(input)
my_LL.display()

swapPairs(my_LL.head)
my_LL.display()


