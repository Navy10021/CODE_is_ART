class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete(self, data):
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def search(self, data):
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

    def erase_duplicates(self):
        if self.head is None:
            return

        current = self.head
        while current:
            runner = current
            while runner.next:
                if runner.next.data == current.data:
                    runner.next = runner.next.next
                else:
                    runner = runner.next
            current = current.next

    def merge_sort(self):
        if self.head is None or self.head.next is None:
            return self.head

        # Split the linked list into two halves
        mid = self.get_middle()
        left_half = LinkedList()
        left_half.head = self.head
        right_half = LinkedList()
        right_half.head = mid.next
        mid.next = None

        # Recursively sort both halves
        left_half.merge_sort()
        right_half.merge_sort()

        # Merge the sorted halves
        self.head = self.merge(left_half.head, right_half.head)

    def get_middle(self):
        slow_ptr = self.head
        fast_ptr = self.head
        while fast_ptr.next and fast_ptr.next.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
        return slow_ptr

    def merge(self, left, right):
        if left is None:
            return right
        if right is None:
            return left

        merged = None
        if left.data < right.data:
            merged = left
            merged.next = self.merge(left.next, right)
        else:
            merged = right
            merged.next = self.merge(left, right.next)

        return merged

    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def is_palindrome(self):
        if self.head is None:
            return False

        # Find the middle of the linked list
        slow_ptr = self.head
        fast_ptr = self.head
        while fast_ptr and fast_ptr.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

        # Reverse the second half of the linked list
        second_half = LinkedList()
        current = slow_ptr
        while current:
            second_half.prepend(current.data)
            current = current.next

        # Compare the first half with the reversed second half
        current1 = self.head
        current2 = second_half.head
        while current1 and current2:
            if current1.data != current2.data:
                return False
            current1 = current1.next
            current2 = current2.next

        return True

    def __str__(self):
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        return " -> ".join(elements) + " -> None"

# Example usage:
if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.append(2)
    linked_list.append(1)

    print("Original Linked List:")
    print(linked_list)

    print("Is Palindrome:", linked_list.is_palindrome())

