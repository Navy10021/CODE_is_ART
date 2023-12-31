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

def string_to_LinkedList(str):
    linked_list = LinkedList()
    
    for char in str:
        linked_list.append(char)
    
    return linked_list

def subLinkedList(linked_list):
    all_sublists = []
    curr_node = linked_list.head
    
    while(curr_node):
        sublist = LinkedList()
        sublist_head = curr_node
        
        while(sublist_head):
            sublist.append(sublist_head.data)
            sublist_head = sublist_head.next 
            #all_sublists.append(sublist)         # 기존의 sublist가 반복됨.
            all_sublists.append(sublist.copy())   # Append a copy of the sublist
        
        curr_node = curr_node.next
    
    return all_sublists

# Example usage

string = "NAVY"
my_LL = string_to_LinkedList(string)

all_sublists = subLinkedList(my_LL)
for sublist in all_sublists:
    sublist.display()
