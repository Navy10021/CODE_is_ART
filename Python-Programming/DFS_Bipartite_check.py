# 이분 그래프 : 인접한 두 정점이 같은색으로 칠해지지 않도록 두 가지색으로 그래프를 칠 할 수 있는 경우
class GNode:
    def __init__(self, data, color="W", bipart=None):
        self.data = data
        self.color = color
        self.bipart = bipart  # Use None as uninitialized, 0 and 1 for two parts

def isBipartite(graph):
    def DFS(curr, bipart):
        if curr.color == "B":  # If already visited
            return curr.bipart == bipart  # Check if bipartition is consistent
        curr.color = "B"
        curr.bipart = bipart
        for nei in graph[curr]:
            if not DFS(nei, bipart ^ 1):  # Toggle bipart for neighbor
                return False
        return True
    
    for node in graph:
        if node.color == "W":  # If not visited
            if not DFS(node, 0):  # Start with bipart=0 for unvisited components
                return False
    return True

# Adj List (Undirected edges)
A, B, C = GNode('A'), GNode('B'), GNode('C')
D, E, F = GNode('D'), GNode('E'), GNode('F')
Graph = {A: [C, B],
         B: [A, D],
         C: [A], 
         D: [B, E, F], 
         E: [D],
         F: [D]}

# Test the function
is_bipartite = isBipartite(Graph)
print("Is the graph bipartite?", is_bipartite)