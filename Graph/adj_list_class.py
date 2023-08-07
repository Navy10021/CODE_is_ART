# adj node == linked list
class AdjNode:
    def __init__(self, value):
        self.val = value
        self.next = None 

class Graph:
    def __init__(self, num):
        self.V = num
        self.graph = [None] * self.V
    
    def add_edge(self, u, v):
        node = AdjNode(v)           # v -> u
        node.next = self.graph[u]   
        self.graph[u] = node 
        
        # No direction
        node = AdjNode(u)           # u -> v
        node.next = self.graph[v]
        self.graph[v] = node 
    
    def print_graph(self):
        for i in range(self.V):
            print("Vertex "+str(i)+":", end="")
            temp = self.graph[i]
            while (temp):
                print("-> {}".format(temp.val), end="")
                temp = temp.next 
            print("\n")

G = Graph(5)
G.add_edge(0,1)
G.add_edge(0,2)
G.add_edge(0,3)
G.add_edge(1,2)
G.print_graph()
