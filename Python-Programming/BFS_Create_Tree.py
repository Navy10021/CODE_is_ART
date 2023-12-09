from collections import deque

class GNode:
    def __init__(self, id, c="W", d=-1):
        self.id = id
        self.color = c  
        self.distance = d

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []
        

def CreateTree(graph, start):
    start.color = "G"
    start.distance += 1
    root = TreeNode(start)
    Q = deque()
    Q.append((root, None))
    
    while(Q):
        curr_node, parent = Q.popleft()
        
        for nxt in graph[curr_node.data]:   # Graph vertex
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr_node.data.distance + 1
                nei_node = TreeNode(nxt)
                curr_node.children.append(nei_node)
                Q.append((nei_node, curr_node))
    
    return root

def printTree(root):
    if root:
        print("  " * (root.data.distance - 1) + str(root.data.id))
        for child in root.children:
            printTree(child)


A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")
H, I, J = GNode("H"), GNode("I"), GNode("J")

G = dict()
G[A] = [B, C]
G[B] = [D, E]
G[C] = [F]
G[D] = []
G[E] = [H]
G[F] = [I]
G[H] = []
G[I] = []

start_vertex = A 
tree_root = CreateTree(G, start_vertex)
printTree(tree_root)
