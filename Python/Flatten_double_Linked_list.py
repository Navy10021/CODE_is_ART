class Node:
    def __init__(self, val=None, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

def flatten(head):
    if not head:
        return None

    current = head
    while current:
        if current.child:
            # Save the next node in the original list
            next_node = current.next

            # Flatten the child list recursively
            child_tail = flatten(current.child)

            # Connect the current node to the child list
            current.next = current.child
            current.child.prev = current
            current.child = None

            # Connect the tail of the child list to the next node in the original list
            if next_node:
                child_tail.next = next_node
                next_node.prev = child_tail

            current = next_node
        else:
            current = current.next

    return head
