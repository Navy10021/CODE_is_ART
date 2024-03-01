class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, val):
        newNode = Node(val)
        if not self.head:
            self.head = newNode
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = newNode

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.val)
            current = current.next
        print(" -> ".join(map(str, elements)))

    def is_palindrome(self):
        if not self.head or not self.head.next:
            return True

        # Find the middle
        slow = fast = self.head
        prev_of_slow = None
        while fast and fast.next:
            fast = fast.next.next
            prev_of_slow = slow
            slow = slow.next

        midnode = None

        # Handling odd size list
        if fast:
            midnode = slow
            slow = slow.next

        second_half_start = self.reverse_list(slow)
        palindrome = self.compare_lists(self.head, second_half_start)

        # Restore the original list (Reverse the second half back)
        self.reverse_list(second_half_start)

        if midnode:
            prev_of_slow.next = midnode
            midnode.next = slow
        else:
            prev_of_slow.next = slow

        return palindrome

    def reverse_list(self, head):
        prev = None
        current = head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev

    def compare_lists(self, head1, head2):
        while head2:  # Only need to compare till the end of second half or shorter list
            if head1.val != head2.val:
                return False
            head1 = head1.next
            head2 = head2.next
        return True

input = "radar"
LL = LinkedList()
for char in input:
    LL.append(char)

if(LL.is_palindrome()):
    LL.display()
    print("Is palindrome Linked List.")
