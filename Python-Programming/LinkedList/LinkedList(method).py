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
        newNode = Node(data)
        if (self.is_empty()):
            self.head = newNode
            return
        lastNode = self.head
        while (lastNode.next != None):
            lastNode = lastNode.next
        lastNode.next = newNode
    
    def display(self):
        curr = self.head
        while(curr != None):
            print(curr.data, end = " -> ")
            curr = curr.next
        print("None")
    
    def arr_to_linkedList(self, arr):
        for element in arr:
            self.append(element)
    
    def string_to_linkedList(self, string):
        #self.arr_to_linkedList(str.split())
        for char in string:
            self.append(char)

    def reverse(self):
        prevNode = None 
        currNode = self.head
        while(currNode != None):
            nextNode = currNode.next 
            currNode.next = prevNode
            prevNode = currNode 
            currNode = nextNode
        self.head = prevNode
    
    def find_middle(self):
        slow = self.head
        fast = self.head

        while(fast != None and fast.next != None):
            slow = slow.next
            fast = fast.next.next
        return slow if (slow != None) else None 

    def is_palindrome(self):
        # Deep Copy 
        copyList = self.copy()
        # Reverse the second half of the list
        middle = copyList.find_middle()
        second_half = middle.next if (middle != None) else None 
        second_half_rev = None 
        while (second_half != None):
            temp = second_half.next
            second_half.next = second_half_rev
            second_half_rev = second_half
            second_half = temp 
        # Compare
        first_half = copyList.head 
        while(first_half != None and second_half_rev != None):
            if (first_half.data != second_half_rev.data):
                return False
            first_half = first_half.next
            second_half_rev = second_half_rev.next
        return True
    
    def copy(self):
        newLinkedList = LinkedList()
        currNode = self.head
        while(currNode != None):
            newLinkedList.append(currNode.data)
            currNode = currNode.next
        return newLinkedList

    def get_substring(self, startNode, endNode):
        substring = []
        currNode = startNode
        while(currNode != endNode.next):
            substring.append(currNode.data)
            #substring.append(int(currNode.data))
            currNode = currNode.next
        return substring
    
    def get_all_substrings(self):
        substrings = []
        currNode = self.head
        while(currNode != None):
            runner = currNode
            while(runner != None):
                substr = self.get_substring(currNode, runner)
                substrings.append(substr)
                runner = runner.next
            currNode = currNode.next
        return substrings 
    
    def generate_subseqs(self, curr, curr_subseq, subsequences):
        # Recursion out
        if (curr == None):
            return

        # Include current Node
        new_subseq = curr_subseq.copy()
        new_subseq.append(curr.data)    # Include
        subsequences.append(new_subseq)
        
        # Recursively generate subsequences : Include and Exclude currNode 
        self.generate_subseqs(curr.next, curr_subseq, subsequences)
        self.generate_subseqs(curr.next, new_subseq, subsequences)

    def get_all_subseqs(self):
        subsequences = []
        curr = self.head
        while (curr != None):
            self.generate_subseqs(curr, [], subsequences)
            curr = curr.next

        return subsequences

    def compare(self, otherList):
        curr_self = self.head 
        curr_other = otherList.head

        while(curr_self != None and curr_other != None):
            if (curr_self.data != curr_other.data):
                return False 
            curr_self = curr_self.next
            curr_other = curr_other.next

        return curr_self is None and curr_other is None

    def delete_for_value(self, value):
        curr = self.head
        # Check if the head value or not
        if (curr != None and curr.data == value):
            self.head = curr.next
            return
        # Search for the value in the rest of the list 
        prev = None
        while (curr != None and curr.data != value):
            prev = curr
            curr = curr.next 
        # target value is NOT found
        if (curr == None):
            return
        # Remove
        prev.next = curr.next

    def delete_for_index(self, index):
        curr = self.head
        if (curr != None and index == 0):
            self.head = curr.next
            return
        
        prev = None 
        count = 0
        while(curr != None and count != index):
            prev = curr
            curr = curr.next
            count += 1
        
        if (curr == None):
            return 
        
        prev.next = curr.next

    def delete_for_indices(self, indices):
        for index in sorted(indices, reverse = True):
            self.delete_for_index(index)

    def remove_duplicates(self):
        curr = self.head
        # Base case
        if (curr == None or curr.next == None):
            return
        # Using set()
        unique_values = set([curr.data])
        prev = curr
        curr = curr.next 

        while(curr != None):
            if (curr.data in unique_values):
                prev.next = curr.next   # Remove
            else:
                unique_values.add(curr.data)
            prev = curr
            curr = curr.next

    def slicing(self, start, end):
        curr = self.head
        curr_idx = 0
        if (curr == None or start > end):
            return 
        # Traverse to starting position
        while(curr != None and curr_idx < start):
            curr = curr.next 
            curr_idx += 1 
        
        # Build the sliced linked list
        new_linkedList = LinkedList()
        while(curr != None and curr_idx <= end):
            new_linkedList.append(curr.data)
            curr = curr.next
            curr_idx += 1

        return new_linkedList

    def merge_sort(self):
        self.head = self._merge_sort(self.head)
    
    def _merge_sort(self, head):
        if (head == None or head.next == None):
            return head
        # Split the Linked List into Two Halves
        mid = self._get_middle_node(head)
        left_half, right_half = self._split_linked_list(head, mid)
        # Recursively sort Both halves
        left_half = self._merge_sort(left_half)
        right_half = self._merge_sort(right_half)
        # Merge the Sorted halves
        sorted_list = self._merge_linked_lists(left_half, right_half)
        return sorted_list
    
    def _get_middle_node(self, head):
        slow = head 
        fast = head 
        while(fast.next and fast.next.next):
            slow = slow.next
            fast = fast.next.next 
        return slow

    def _split_linked_list(self, head, mid):
        mid_next = mid.next
        mid.next = None 
        return head, mid_next
    
    def _merge_linked_lists(self, left, right):
        dummy = Node(None)
        curr = dummy
        while (left != None and right != None):
            if (left.data < right.data):
                curr.next = left
                left = left.next 
            else:
                curr.next = right 
                right = right.next 
            curr = curr.next
        
        if (left != None):
            curr.next = left 
        
        if (right != None):
            curr.next = right

        return dummy.next
    
    def ascending_order(self):
        self.merge_sort()
    
    def descending_order(self):
        self.merge_sort()
        self.reverse()

    def is_cycle(self):
        if (self.head == None):
            return False
        
        slow = self.head
        fast = self.head
        
        while (fast != None and fast.next != None):
            slow = slow.next 
            fast = fast.next.next 
            
            if slow == fast:
                return True     # There is cycle
        
        return False
    
    def split_odd_even(self):
        if (self.is_empty()):
            return None, None 
        
        odd_list = LinkedList()
        even_list = LinkedList()
        
        curr = self.head 
        while(curr != None):
            if (curr.data % 2 == 0):
                even_list.append(curr.data)
            else:
                odd_list.append(curr.data)
            curr = curr.next 

        return odd_list, even_list
    
    def length(self):
        count = 0
        curr = self.head 
        while(curr != None):
            count += 1
            curr = curr.next 
        return count 
    
    def add(self, otherList):
        if (self.is_empty()):
            self.head = otherList.head
        else:
            curr = self.head 
            while(curr.next != None):
                curr = curr.next 
        
            curr.next = otherList.head
    
        
