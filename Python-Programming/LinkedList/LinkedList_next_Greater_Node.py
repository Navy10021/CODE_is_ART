
# LeetCode 1019. Next greater node in linked list
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


def arr_to_LinkedList(arr):
    linked_list = LinkedList()
    for e in arr:
        linked_list.append(e)
    return linked_list


def nextLargerNode(head):
    if not head or not head.next:
        return head
    
    next_greater = []
    curr = head
    while curr:
        finder = curr.next
        while finder:
            if finder.data > curr.data:
                next_greater.append(finder.data)
                break
            else:
                finder = finder.next 
        if finder is None:
            next_greater.append(0)
        curr = curr.next 
    
    return next_greater
        
        

# Example usage
arr = [2,7,4,3,5]
#arr = [2,1,5]
arr = arr_to_LinkedList(arr)
res = nextLargerNode(arr.head)
print(res)
