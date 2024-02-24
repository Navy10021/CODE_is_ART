class GNode:
    def __init__(self, data):
        self.data = data
        self.visited = False
        self.parent = None

def DFS(graph, curr, path, all_paths, visited_set):
    visited_set.add(curr)
    path.append(curr.data)
    
    if len(visited_set) == len(graph):
        all_paths.append(path.copy())
    else:
        for nxt in graph[curr]:
            if nxt not in visited_set:
                DFS(graph, nxt, path, all_paths, visited_set)

    # Backtrack
    visited_set.remove(curr)
    path.pop()

def find_all_paths(graph):
    all_paths = []
    for start in graph:
        visited_set = set()
        path = []
        DFS(graph, start, path, all_paths, visited_set)
    return all_paths

# Initialize nodes
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

# Define the graph
G = {
    A: [B, C],
    B: [A, D],
    C: [A, D],
    D: [B, C, E],
    E: [D],
}

# Find all paths
res = find_all_paths(G)

# Print paths
for path in res:
    print(" -> ".join(path))
