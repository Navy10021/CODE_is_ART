class GNode:
    def __init__(self, data, color = "W", dist = -1, fin = -1, parent = None):
        self.data = data 
        self.color = color 
        self.dist = dist 

time = 0 
def DFS(graph, curr, time, path, all_paths, target_dist):
    time += 1 
    curr.dist = time
    #curr.color = "B"
    path.append(curr.data)
    
    if curr.dist == target_dist:
      all_paths.append(path.copy())
    
    else:
      for nxt in graph[curr]:
        if nxt.data not in path:
            DFS(graph, nxt, time, path, all_paths, target_dist) # Recursion
    time += 1 
    path.pop()    # backtracking
    #curr.color = "W"

def find_all_paths(graph, target_dist):
  all_paths = []
  for start in graph:
    for node in graph:
        node.dist = -1
        node.fin = -1
    path = []
    time = -1
    DFS(graph, start, time, path, all_paths, target_dist-1)
  return all_paths
    
    
# Adj List (Undirected edges)
A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [B, C]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, E, F]
G[E] = [D]
G[F] = [D]

distance = 5
paths = find_all_paths(G, distance)
print(paths)
