class Node:
    def __init__(self, data = 0, next = None):
        self.data = data 
        self.next = next

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

    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        print(" -> ".join(map(str, elements)))

def arrToList(arr):
    ll = LinkedList()
    for e in arr:
        ll.append(e)
    return ll 


# LeetCode 2130. Maximum Twin Sum of a Linked List :
# linked list size is EVEN, return maximum Twin(i, n-1-i) Sum 

def pairSum(head):
    # Access Like Palindrome
    maxTwin = 0
    # Find middle
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    # reverse second half
    second_half = None 
    while slow:
        temp = slow.next 
        slow.next = second_half
        second_half = slow
        slow = temp
    
    # Comapare Twin Sum(first half & revesed second half)
    first_half = head 
    while second_half:
        twinSum = first_half.data + second_half.data 
        if twinSum > maxTwin:
            maxTwin = twinSum
        first_half = first_half.next 
        second_half = second_half.next
    
    return maxTwin
    

L = [4,2,2,3]
LL = arrToList(L)
LL.display()

res = pairSum(LL.head)
print("Max pair sum : ", res)