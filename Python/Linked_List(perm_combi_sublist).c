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
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

# Swap Node function
def swap_nodes(a, b):
    a.data, b.data = b.data, a.data

# Permutation generation function
def generate_permutation(head, curr):
    if curr is None:
        print_list(head)
        return
    iter_node = curr
    while iter_node:
        swap_nodes(curr, iter_node)
        generate_permutation(head, curr.next)
        swap_nodes(curr, iter_node)
        iter_node = iter_node.next

# Combination generation function
def generate_combination(head, combo_size, index, combo, combo_idx):
    if combo_idx == combo_size:
        print([node.data for node in combo])
        return

    if index >= combo_size or not head:
        return

    combo[combo_idx] = head
    generate_combination(head.next, combo_size, index + 1, combo, combo_idx + 1)
    generate_combination(head.next, combo_size, index, combo, combo_idx)

# Permutation with Repetition function
def generate_permutation_rep(head, curr):
    if curr is None:
        print_list(head)
        return
    iter_node = curr
    while iter_node:
        swap_nodes(curr, iter_node)
        generate_permutation_rep(head, curr.next)
        swap_nodes(curr, iter_node)
        iter_node = iter_node.next
        while iter_node and iter_node.data == curr.data:
            iter_node = iter_node.next

# Loop check function
def has_loop(head):
    slow = fast = head
    while slow and fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Generate Sub linked list
def generate_sub_list(head, st_idx, en_idx):
    if not head or st_idx > en_idx:
        return None

    dummy = Node(None)  # Dummy node
    idx = 0
    curr = dummy

    while head:
        if st_idx <= idx <= en_idx:
            curr.next = Node(head.data)
            curr = curr.next
        head = head.next
        idx += 1

    return dummy.next

if __name__ == "__main__":
    head = None
    head = append(head, 1)
    head = append(head, 2)
    head = append(head, 3)
    head = append(head, 4)
    head = append(head, 5)
    
    print("=== Original List ===")
    print_list(head)

    print("=== Permutation ===")
    generate_permutation(head, head)

    print("=== Permutation with Repetition ===")
    generate_permutation_rep(head, head)

    print("=== Combination ===")
    combo_size = 2
    combo = [None] * combo_size
    generate_combination(head, combo_size, 0, combo, 0)

    print("=== Subset ===")
    st_idx = 1  # Start index (inclusive)
    en_idx = 3  # End index (inclusive)
    sub_list = generate_sub_list(head, st_idx, en_idx)
    print_list(sub_list)
