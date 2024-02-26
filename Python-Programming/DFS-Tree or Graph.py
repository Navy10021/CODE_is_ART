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
    A : [B, C],
    B : [A, D],
    C : [A, D],
    D : [B, C],
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

