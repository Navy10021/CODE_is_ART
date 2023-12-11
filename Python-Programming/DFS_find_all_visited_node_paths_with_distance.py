class GNode:
    def __init__(self, data, color = "W", dist = -1, fin = -1, parent = None):
        self.data = data 
        self.color = color 
        self.dist = dist 
        self.finish = fin 
        self.parent = parent

time = 0 
def DFS(graph, curr, time, visited, path, all_paths):
    time += 1 
    curr.dist = time
    #curr.color = "G"
    visited.add(curr.data)
    path.append((curr.data, curr.dist, curr.finish))
    
    if len(visited) == len(graph):
      all_paths.append(path.copy())
    
    else:
      for nxt in graph[curr]:
        if nxt.data not in visited:
            #nxt.color = "G"
            nxt.parent = curr
            DFS(graph, nxt, time, visited, path, all_paths) # Recursion
    #curr.color = "B"
    #print(curr.data + "(Back)", end = "-> ")
    time += 1 
    curr.finish = time 
    visited.remove(curr.data)
    path.pop()    # backtracking

def find_all_paths(graph):
  all_paths = []
  for start in graph:
    visited = set()
    path = []
    time = -1
    DFS(graph, start, time, visited, path, all_paths)
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
G[E] = [D, F]
G[F] = [D, E]

paths = find_all_paths(G)
for path in paths:
  for node in path:
    print(node[0], end ="->")
  print("\n")