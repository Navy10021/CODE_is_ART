# DFS-Find Path-II(with Distance)
# 시작노드 ~ 끝노드간 DFS 탐색 경로와 거리를 리턴
class GNode:
  def __init__(self, id, c="W", d=-1):
    self.id = id
    self.color = c
    self.dist = d

def DFS(Graph, curr, en, path = []):
  #global time
  path = path + [curr.id]   # Visited && Path 두 가지 역할
  curr.color = "G"
  if curr == en:
    return path
  if curr not in Graph:
    return None
  
  for nxt in Graph[curr]:
    #if nxt.color == "W":
    if nxt.id not in path:
      newPath = DFS(Graph, nxt, en, path)
      if newPath:
        return newPath
  # reset node color
  #curr.color = "W"
  return None  
      
def DFS_start_to_end(graph, start, end):
  path = DFS(graph, start, end)
  print("DFS Node{} -> Node{} : {}".format(start.id, end.id, path))
  if path:
    distance = len(path) - 1
    print("Distance : {}".format(distance))
    #print("Node Distance : {}".format(end.dist))
  else:
    print("No path found.")
 
    
A, B, C, D = GNode("A"), GNode("B"), GNode("C"), GNode("D")
E, F, G, H = GNode("E"), GNode("F"), GNode("G"), GNode("H")

Graph = dict()
Graph[A] = [B]
Graph[B] = [A,E,G]
Graph[C] = [H]
Graph[D] = [H]
Graph[E] = [B, F]
Graph[F] = [E]
Graph[G] = [B]
Graph[H] = [C, D]

DFS_start_to_end(Graph, A, G)

        