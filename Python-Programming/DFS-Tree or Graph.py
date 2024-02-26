class GNode:
    def __init__(self, id, c = "W", d = float('inf'), p = None):
        self.id = id 
        self.color = c
        self.dist = d 
        self.parent = p 
        self.neighbors = []
        
# Initalization       
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

graph = {
    A : [B, C, D],
    B : [A, D, C],
    C : [A, D, B],
    D : [B, C, A],
    E : [],
}
for node, adj in graph.items():
    node.neighbors = [i.id for i in adj]  # store node.id in neighbors 

# Is Complete Graph or not 
def is_complete(graph):
    vertices = list(node.id for node in graph)
    
    for node in graph:
        node.neighbors.append(node.id)
        if set(node.neighbors) != set(vertices): # same as sorted(list())
            return False 
    
    return True 
# Has Cycle in UDAG
def has_cycle(graph):
    def DFS(graph, curr, path):
        curr.color = "B"
        
        for nxt in graph[curr]:
            if nxt.color == "W":
                nxt.parent = curr
                path.append(nxt)
                if DFS(graph, nxt, path):
                    return True 
            elif nxt != curr.parent: # 이미방문한 곳이 부모가 아니면 사이클 존재
                path.append(nxt)
                return True 
    
    for node in graph:
        if node.color == "W":
            path = [node] 
            if DFS(graph, node, path):
                #print("Has Cycle : ", [node.id for node in path], end = '\n')
                return True
    return False
    
# Find Connected nodes
def connected_vertex(graph):
    def DFS(graph, curr, component):
        curr.color = "B"
        component.append(curr.id)
        for nxt in graph[curr]:
            if nxt.color == "W":
                DFS(graph, nxt, component)
    
    islands = []
    for node in graph:
        if node.color == "W":
            connected = []
            DFS(graph, node, connected)
            islands.append(connected)
    
    if len(islands) > 1:
        print("Graph with {} islands".format(len(islands)))
    
    elif len(islands) == 1:
        # Initalization 
        for node in graph:
            node.color = "W"
            
        # Check has Cycle 
        if has_cycle(graph):
            print("Graph without islands")
        else:
            # Not has Cycle : Tree 
            print("Tree")
        
    return islands

def foo(graph):
    if is_complete(graph):
        print("Completed Graph")
    else:
        islands = connected_vertex(graph)
        print(islands)
        
foo(graph)