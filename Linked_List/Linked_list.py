class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None 
    
    def printList(self):
        temp = self.head 
        while(temp):
            print(temp.data, end = " ")
            temp = temp.next 
    
    def push(self, data):
        temp = Node(data)
        temp.next = self.head 
        self.head = temp 
    
    def push_back(self, data):
        temp = Node(data)
        if self.head == None:
            self.head = temp
        else:
            last_node = self.head
            while(last_node.next != None):
                last_node = last_node.next 
            last_node.next = temp 
    
    def del_front(self):
        self.head = self.head.next
        
    def del_pop(self):
        temp = self.head 
        while(temp.next and temp.next.next != None):
            temp = temp.next
        temp.next = None 
        
    def del_position(self, pos):
        temp = self.head
        prev = self.head 
        for i in range(0, pos):
            if i == 0 and pos == 1:
                self.head = self.head.next
            else:
                if i == (pos-1) and temp is not None:
                    prev.next = temp.next 
                else:
                    prev = temp 
                    # position was greater than num of list
                    if prev is None:
                        break
                    temp = temp.next 
            
    
LL = LinkedList()
LL.push_back(0)
LL.push_back(1)
LL.push_back(2)
LL.push_back(3)
LL.push_back(4)
LL.push_back(5)
LL.printList();
print("\n")
LL.del_position(2)
LL.printList();




    
