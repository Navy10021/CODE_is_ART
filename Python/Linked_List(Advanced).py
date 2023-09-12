class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

def display(head):
    curr = head 
    while curr:
        print(curr.data, end = " -> ") 
        curr = curr.next
    print("None")

# 1. Reverse
def reverse_linked_list(head):
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev

# 2. Detect Cycle in Linked List
def has_cycle(head):
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False

# 3. Find Middle
def find_middle(head):
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow

# 4. Add Two Linked List
def addTwoList(L1, L2):
    dummy = Node(0)
    curr = dummy
    carry = 0
    
    while L1 or L2:
        x = L1.data if L1 else 0 
        y = L2.data if L2 else 0 
        
        total_sum = x + y + carry
        carry = total_sum // 10     # 10 올림
        
        curr.next = Node(total_sum % 10)    # 10 나머지값으로 저장
        curr = curr.next
        
        if L1:
            L1 = L1.next 
        if L2:
            L2 = L2.next
    
    if carry > 0:
        curr.next = Node(carry)
    
    return dummy.next

# 5. get Intersection
def getIntersectionNode(headA, headB):
    # Find the lengths of both linked lists
    lenA, lenB = 0, 0
    currentA, currentB = headA, headB

    while currentA:
        lenA += 1
        currentA = currentA.next

    while currentB:
        lenB += 1
        currentB = currentB.next

    # Reset pointers to the beginning of the linked lists
    currentA, currentB = headA, headB

    # Move the longer linked list's pointer to make both lists equal in length
    if lenA > lenB:
        for _ in range(lenA - lenB):
            currentA = currentA.next
    elif lenB > lenA:
        for _ in range(lenB - lenA):
            currentB = currentB.next

    # Traverse both linked lists simultaneously until they intersect
    while currentA and currentB:
        if currentA == currentB:
            return currentA  # Intersection found
        currentA = currentA.next
        currentB = currentB.next

    return None  # No intersection found

# Example usage:
if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.append(2)
    linked_list.append(1)
    
    linked_list2 = LinkedList()
    linked_list2.append(9)
    linked_list2.append(8)
    linked_list2.append(7)
    linked_list2.append(0)
    linked_list2.append(5)
    linked_list2.append(5)
    

    display(linked_list.head)
    #display(reverse_linked_list(linked_list.head))
    
    if(has_cycle(linked_list.head)):
        print("Has Cycle!")
    else:
        print("No Cycle!")
        
    print("Middle Node : ",find_middle(linked_list.head).data)
    
    display(addTwoList(linked_list.head, linked_list2.head))
    
