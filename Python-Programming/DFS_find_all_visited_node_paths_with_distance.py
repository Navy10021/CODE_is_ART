class GNode:
  def __init__(self, data, color="W", parent=None, dist =0):
    self.data = data
    self.color = color
    self.parent = parent
    self.dist = dist

def DFS(graph, curr, visited, path, all_paths):
  #curr.color = "G"
  visited.add(curr.data)
  path.append((curr.data, curr.dist))  # store data & distance
  
  if len(visited) == len(graph):
    all_paths.append(path.copy())
  else:
    for nxt in graph[curr]:
      if nxt.data not in visited:
        #nxt.color = "G"    
        nxt.parent = curr
        nxt.dist = curr.dist + 1
        DFS(graph, nxt, visited, path, all_paths)
  
  #curr.color = "W"
  curr.dist += 1
  visited.remove(curr.data)
  path.pop()
  

def find_all_paths(graph):
  all_paths = []
  
  for start in graph:
    visited = set()
    path = []
    for node in graph:
      node.dist = 0 
    DFS(graph, start, visited, path, all_paths)
  return all_paths 
  
A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E = GNode("D"), GNode("E")

G = {
  A : [B, C],
  B : [A],
  C : [A, D],
  D : [C, E],
  E : [D],
}

print(find_all_paths(G))