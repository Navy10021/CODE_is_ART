# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked List class : push / push_back / printList / reverse
class LinkedList:
    def __init__(self):
        self.head = None 
    
    def printList(self):
        temp = self.head 
        while(temp):
            print(temp.data, end = " ")
            temp = temp.next 
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head 
        self.head = new_node 
    
    def push_back(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        else:
            last_node = self.head
            while(last_node.next != None):
                last_node = last_node.next
            last_node.next = new_node
            
    def reverse(self):
        Stack = []  # stack list 
        temp = self.head 
        while(temp.next != None):
            Stack.append(temp)
            temp = temp.next 
        # 마지막 노드를 Head로 정의 
        self.head = temp 
        # 스택이 빌때까지 POP값을 연결 
        while(len(Stack) > 0):      # while(Stack)
            temp.next = Stack.pop()
            temp = temp.next 
        temp.next = None
            
LL = LinkedList()
LL.push(1);
LL.push(2);
LL.push(3);
LL.push_back(4);
LL.push_back(5);
LL.printList();
print("\n")
LL.reverse();
LL.printList();
