from collections import defaultdict

# DFS-Find Shorest Path with Topological Sort.
# DFS - 최단경로 찾기
class GNode:
    def __init__(self, data, d = -1, c = "W"):
        self.data = data
        self.distance = d
        self.color = c

# Shortest Path & Distance in a Directed Acyclic Graph(DAG) 
def shortest_path(graph, start):
    # Topological Sort 
    def topological(graph):
        def DFS(graph, curr, path):
            curr.color = "B"
            for nxt in graph[curr]:
                DFS(graph, nxt, path)
            path.insert(0, curr)
        
        stack = []  # store topological sorting result
        for node in graph:
            if node.color == "W":
                DFS(graph, node, stack)
        return stack
    
    topological_order = topological(graph)
    distances = {node.data : float('inf') for node in graph}
    distances[start.data] = 0
    
    for node in topological_order:
        for nei in graph[node]:
            new_distance = distances[node.data] + 1 
            if new_distance < distances[nei.data]:
                distances[nei.data] = new_distance
    
    print("The shortest distance from {} : {}".format(start.data, distances))
    
    return distances

def find_all_paths(graph, start, end):
    def DFS(curr, path):
        if curr == end:
            paths.append(path.copy())
            return
        for nei in graph[curr]:
            DFS(nei, path + [nei.data])
    paths = []
    DFS(start, [start.data])
    
    print("All paths {} -> {}".format(start.data, end.data))
    for path in paths:
        print(path)
    
    return paths

A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G, H = GNode('E'), GNode('F'), GNode('G'), GNode('H')

Graph = {
    A: [B, C],
    B: [D],
    C: [D],
    D: [E, F],
    E: [F],
    F: [G],
    G: [H],
    H: []
}

startNode = A
endNode = H
dist_dict = shortest_path(Graph, startNode)
paths = find_all_paths(Graph, startNode, endNode)