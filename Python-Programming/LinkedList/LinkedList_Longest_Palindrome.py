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
    
    def delete(self, data):
        if (self.is_empty()):
            return 
    
        if (self.head.data == data):
            self.head = self.head.next 
            return 

        currNode = self.head 
        while(currNode.next != None and currNode.next.data != data):
            currNode = currNode.next 
        
        # Erase
        if (currNode.next):
            currNode.next = currNode.next.next
            
    
    def deletePosition(self, position):     # position = index
        if (position < 0 or self.is_empty()):
            return 
        
        if (position == 0):
            self.head = self.head.next 
            return 

        currNode = self.head 
        for _ in range(position - 1):
            if (currNode.next):
                currNode = currNode.next 
            else:
                print("Position exceed the length of Linked List.", end = "\n")
                return 
        
        # Erase
        if (currNode.next):
            currNode.next = currNode.next.next
            
    def deletePositions(self, positions):
        for position in sorted(positions, reverse=True):    # 높은 Index Node 부터 삭제하면, 순서 변경이 없다.
            self.deletePosition(position)
    
    def length(self):
        count = 0
        currNode = self.head
        while(currNode):
            count += 1
            currNode = currNode.next 
        return count 
    
    def display(self):
        currNode = self.head 
        while(currNode):
            print(currNode.data, end = " -> ")
            currNode = currNode.next 
        print("None")
    
    def CopyList(self):
        newList = LinkedList()
        currNode = self.head 
        while (currNode):
            newList.append(currNode.data)
            currNode = currNode.next 
        
        return newList
    
    def isPalindrome(self):
        copyList = self.CopyList()
        head = copyList.head
        if not head:
            return False
        slow = head 
        fast = head 
    
        while (fast and fast.next):
            slow = slow.next 
            fast = fast.next.next 
    
        # Reverse second half
        second_half = None 
        while (slow):
            temp = slow.next
            slow.next = second_half
            second_half = slow 
            slow = temp 

        # Compare
        first_half = head 
        while (second_half):
            if (first_half.data != second_half.data):
                return False 
            first_half = first_half.next 
            second_half = second_half.next 
    
        return True 
        

def createLinkedList(list):
    LL = LinkedList()
    for item in list:
        LL.append(item)
    return LL

def genCombination(arr, data, st, en, idx, r, res):
    if (idx == r):
        res.append(list(data))
        return
    
    # Recursion
    for i in range(st, en + 1):
        # array index loop && remaining element >= elements to be filled in data
        if (en - i + 1 >= r - idx):
            data[idx] = arr[i]  # save the current element
            genCombination(arr, data, i + 1, en, idx + 1, r, res)
            
def genAllCombinationIdx(n):
    arr = [i for i in range(0, n)]
    all_combinations = []
    for r in range(1, n+1):
        data = [0] * r 
        genCombination(arr, data, 0, n - 1, 0, r, all_combinations)
    
    return all_combinations


def LongestPalindrome(List):
    print("Original Linked List : ", end = " ")
    List.display()
    length = List.length()
    
    if (List.isPalindrome()):
        print("After Modified Linked List : ", end = " ")
        List.display()
    
    else:
        # Combination
        all_combinations = genAllCombinationIdx(length)
        for case in all_combinations:
            ListCopy = List.CopyList()
            ListCopy.deletePositions(case)
            if (ListCopy.isPalindrome()):
                print("After Modified Linked List : ", end = " ")
                ListCopy.display()
                break 
                
    
    

# Example
inputList = [1,2,3,4,5,3,1]
myLinkedList = createLinkedList(inputList)
LongestPalindrome(myLinkedList)
