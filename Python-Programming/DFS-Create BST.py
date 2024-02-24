class GNode:
    def __init__(self, id, c="W", d=0):  # Changed default distance to 0 for root
        self.id = id
        self.color = c  
        self.distance = d
        
class BSTNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insertIntoBST(root, data):
    if root is None:
        return BSTNode(data)
    else:
        if data.id < root.data.id:
            root.left = insertIntoBST(root.left, data)
        else:
            root.right = insertIntoBST(root.right, data)
    return root

def buildBST(sortedNodes):
    if not sortedNodes:
        return None
    mid = len(sortedNodes) // 2
    root = BSTNode(sortedNodes[mid])
    root.left = buildBST(sortedNodes[:mid])
    root.right = buildBST(sortedNodes[mid+1:])
    return root

# 그래프 평탄화 + 노드정렬 : 전체 그래프를 DFS 탐색을 통해 고유한 노드(Unique Node)를 수집 및 정렬
def flattenGraphToSortedList(graph):
    visited = set()
    nodesList = []

    def dfs(node):
        if node in visited:
            return
        visited.add(node)
        nodesList.append(node)
        for next_node in graph.get(node, []):
            dfs(next_node)

    for start_node in graph.keys():
        dfs(start_node)

    return sorted(nodesList, key=lambda node: node.id)

def printBST(root, indent=""):
    if root:
        printBST(root.right, indent + "   ")
        print(f"{indent}{root.data.id}")
        printBST(root.left, indent + "   ")


# Graph setup
A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")
H, I, J = GNode("H"), GNode("I"), GNode("J")

G = {A: [B, C], B: [D, E], C: [F], D: [], E: [H], F: [I], H: [], I: [], J: []}

# Assuming G is your graph and start_vertex is the start node
sortedNodes = flattenGraphToSortedList(G)
bstRoot = buildBST(sortedNodes)
printBST(bstRoot)
