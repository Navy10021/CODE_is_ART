# 1.Make Linked List
# 2.Pring Linked List
# 3.Linked List Sorting
# 4.Merging Two Sorted Linked List
# 5.Reverse Linked List

class Node:
    def __init__(self, data):
        self.val = data
        self.next = None

def make_linked_list(E):
    head = Node(E[0])
    for e in E[1:]:
        ptr = head
        while ptr.next:
            ptr = ptr.next
        ptr.next = Node(e)
    return head

def print_linked_list(head):
    ptr = head
    print("[", end = "")
    while ptr:
        while ptr:
            print(ptr.val, end = ", ")
            ptr = ptr.next
    print("]")

def sorted_linked_list(node):
    res = []
    head = node
    while node:
        res.append(node.val)
        node = node.next
    res.sort()
    
    node = head
    while node:
        node.val = res.pop(0)
        node = node.next
    return head


def sorted_merge(a, b):
    if a == None and b == None:
        return None

    # Initialize Head of result linked list
    res = None

    # Traverse
    while a != None and b != None:
        if a.val <= b.val:
            temp = a.next
            a.next = res
            res = a
            a = temp
        
        else:
            temp = b.next
            b.next = res
            res = b
            b = temp
    
    # Add remaining node
    while a != None:
        temp = a.next
        a.next = res
        res = a
        a = temp
    
    while b != None:
        temp = b.next
        b.next = res
        res = b
        b = temp
    
    return res

def reverse_linked_list(head):
    prev = None
    curr = head
    while curr != None:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    head = prev
    return head


input_1 = [30, 20, 40, 10, 50]
head_1 = make_linked_list(input_1)

input_2 = [35, 25, 45, 15, 55]
head_2 = make_linked_list(input_2)

print(print_linked_list(head_1))
print(print_linked_list(head_2))
list_1 = sorted_linked_list(head_1)
list_2 = sorted_linked_list(head_2)
print(print_linked_list(list_1))
print(print_linked_list(list_2))
res_list = sorted_merge(list_1, list_2)
print(print_linked_list(res_list))
print(print_linked_list(reverse_linked_list(res_list)))
