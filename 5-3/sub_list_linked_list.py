class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# 방법 1
def find_list(list_1, list_2):
    if not list_1 and not list_2:
        return True

    if not list_1 or not list_2:
        return False

    ptr_1, ptr_2 = list_1, list_2

    while ptr_2: 

        prt_2 = list_2

        while ptr_1:
            if not ptr_2:
                return False
            elif ptr_1.data == ptr_2.data:
                ptr_1 = ptr_1.next
                ptr_2 = ptr_2.next
            else:
                break

        # Check : if ptr_1 is empty -> is sub list
        if not ptr_1:
            return True
        # ptr_1 to point to 1st node of first linked list
        ptr_1 = list_1 
        # Increment seconde node element to next
        ptr_2 = list_2.next
    
    return False

# 방법 2
def is_sublist(sub_list, par_list):
    if sub_list is None:
        return True
    if par_list is None:
        return False
    # Recursive
    if par_list.data == sub_list.data:
        return is_sublist(sub_list.next, par_list.next)
    else:
        return is_sublist(sub_list.next, par_list)

    return None

node_1 = Node(1)
node_1.next = Node(2)
node_1.next.next = Node(3)

node_2 = Node(1)
node_2.next = Node(2)
node_2.next.next = Node(3)
node_2.next.next.next = Node(4)
node_2.next.next.next.next = Node(1)

print(find_list(node_1, node_2))
print(is_sublist(node_1, node_2))
