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

    def swap(self, node1, node2):
        temp = node1.data
        node1.data = node2.data
        node2.data =temp 

    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev
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


def permutation_LinkedList(linked_list):
    def backtrack(start_node):
        if not start_node.next:
            all_permutations.append(linked_list.copy())
            return

        seen = set()        # To keep track of unique elements at given postion
        curr_node = start_node
        while(curr_node):
            if (curr_node.data not in seen):
                seen.add(curr_node.data)
                linked_list.swap(start_node, curr_node)
                backtrack(start_node.next)
                linked_list.swap(start_node, curr_node)
            curr_node = curr_node.next 
    
    all_permutations = []
    backtrack(linked_list.head)
    
    return all_permutations
        

# Example usage
string = "AABB"
my_LL = string_to_LinkedList(string)
permutations = permutation_LinkedList(my_LL)

for perm in permutations:
    if perm.is_palindrome():
        perm.display()
