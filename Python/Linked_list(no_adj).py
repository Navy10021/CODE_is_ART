class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked List append function
def append(head, data):
    new_node = Node(data)
    if head is None:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    return head

# Print Linked List function
def print_list(head):
    current = head
    result = []
    while current:
        result.append(current.data)
        #print(current.data, end=" ")
        current = current.next
    return result

# Function to check if a linked list contains a specific value
def is_contain(head, target):
    current = head
    while current:
        if current.data == target:
            return True  # Value found in the linked list
        current = current.next
    return False  # Value not found in the linked list

# Function to check if a linked list contains consecutive numbers
def is_continous(head):
    current = head
    while current.next:
        if current.data + 1 == current.next.data or current.data == current.next.data + 1:
            return True  # consecutive
        current = current.next
    return False  # No Consecutive

# Function to swap the data of two nodes in the linked list
def swap_nodes(a, b):
    a.data, b.data = b.data, a.data

# Permutation generation function
def gen_permutation(head, curr):
    if curr is None:
        return print(print_list(head))
    iter_node = curr
    while iter_node:
        swap_nodes(curr, iter_node)
        gen_permutation(head, curr.next)
        swap_nodes(curr, iter_node)
        iter_node = iter_node.next

# Permutation generation function
def gen_permutation_on_adj(head, curr):
    if curr is None and not is_continous(head):
        return print(print_list(head))
    iter_node = curr
    while iter_node:
        swap_nodes(curr, iter_node)
        gen_permutation_on_adj(head, curr.next)
        swap_nodes(curr, iter_node)
        iter_node = iter_node.next

if __name__ == "__main__":
    head = None
    head = append(head, 1)
    head = append(head, 2)
    head = append(head, 5)

    print("=== Original List ===")
    print(print_list(head))

    print("=== Permutation except consecutive number ===")
    gen_permutation(head, head)

    print("=== Permutation except consecutive number ===")
    gen_permutation_on_adj(head, head)
