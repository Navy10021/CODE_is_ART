class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Print sublist of a given linked list specified by given indices
class LinkedListSublist():
    
    def __init__(self):
        self.head = None
    
    def push_node(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
    
    def print_linked_list(self):

        current = self.head
        while current != None:
            print(current.data, end = " -> ")
            current = current.next

    def sub_list(self, start_idx, end_idx):
        # 1. Create Three instance variables : current / sub_current / sub_end
        sub_current = None
        sub_end = None
        current = self.head
        i = 1

        # 2. Traverse the linked list
        while current != None and i <= end_idx:

            # if the start index of the sub_list is found
            if i == start_idx:
                sub_current = current

            # if the end index of the sub_list is found
            if i == end_idx:
                sub_end = current
                sub_end.next = None     # CUT linked list!
            
            # Move to next node
            current = current.next
            i += 1

        return sub_current
    
linked_list = LinkedListSublist()
N= 1
val = 10
while (N < 11):
    linked_list.push_node(val)
    val -= 1
    N += 1

#linked_list.print_linked_list()

start_index, end_index = 2, 5

linked_list.head = linked_list.sub_list(start_index, end_index)
linked_list.print_linked_list()
