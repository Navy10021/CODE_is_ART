from collections import deque
# 그래프를 트리로 전환하는 함수
class GNode:
    def __init__(self, id, c="W", d=0):  # Changed default distance to 0 for root
        self.id = id
        self.color = c  
        self.distance = d

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []
        

def CreateTree(graph, start):
    start.color = "G"
    root = TreeNode(start)
    Q = deque()
    Q.append(root)
    
    while Q:
        curr_node = Q.popleft()
        curr_gnode = curr_node.data  # Current GNode
        
        for nxt in graph[curr_gnode]:  # Graph vertex
            if nxt.color == "W":
                nxt.color = "G"
                nxt.distance = curr_gnode.distance + 1
                nei_node = TreeNode(nxt)
                curr_node.children.append(nei_node)
                Q.append(nei_node)
    
    # Reset colors for potential reuse (optional)
    for node in graph:
        node.color = "W"
        node.distance = 0  # Reset distance if needed
    
    return root

def printTree(root, level=0):
    if root:
        print("  " * level + str(root.data.id))
        for child in root.children:
            printTree(child, level + 1)

# Graph setup
A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")
H, I, J = GNode("H"), GNode("I"), GNode("J")

G = {A: [B, C], B: [D, E], C: [F], D: [], E: [H], F: [I], H: [], I: [], J: []}

start_vertex = A 
tree_root = CreateTree(G, start_vertex)
printTree(tree_root)
