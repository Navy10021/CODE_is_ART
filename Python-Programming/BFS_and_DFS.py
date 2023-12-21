from collections import deque

class GNode:
  def __init__(self, id, c="W", d=-1):
    self.id = id
    self.color = c
    self.dist = d


# 가장작은 노드(id)를 먼저 방문
time = 0
def DFS(graph, curr, path):
  global time
  time += 1
  curr.dist = time
  curr.color = "G"
  path.append(curr.id)
  
  for nxt in graph[curr]:
    if (nxt.color == "W"):
      DFS(graph, nxt, path)
  
  curr.color = "B"  # finish search

def DFS_path(graph, start):
  # initialize
  for node in graph:
    node.color = "W"
    node.dist = -1
  path = []
  DFS(graph, start, path)
  return path
  
def BFS(graph, start, path):
  start.color = "G"
  start.dist += 1
  Q = deque()
  Q.append(start)
  
  while (Q):
    curr = Q.popleft()
    path.append(curr.id)
    for nxt in graph[curr]:
      if nxt.color == "W":
        nxt.color = "G"
        nxt.dist = curr.dist + 1
        Q.append(nxt)
  
  curr.color = "B"  # current Node Queue out
  
def BFS_path(graph, start):
  # initialize
  for node in graph:
    node.color = "W"
    node.dist = -1
  path = []
  BFS(graph, start, path)
  return path
  
  
A0, B1, C2, D3 = GNode(0), GNode(1), GNode(2), GNode(3)
E4, F5, G6, H7 = GNode(4), GNode(5), GNode(6), GNode(7)
I8, J9, K10 = GNode(8), GNode(9), GNode(10)

# Directed Graph
Graph = dict()
Graph[A0] = [C2, E4, F5]
Graph[B1] = [E4, F5, G6]
Graph[C2] = [D3, E4]
Graph[D3] = []
Graph[E4] = [F5, I8]
Graph[F5] = [J9, K10]
Graph[G6] = []
Graph[H7] = [F5]
Graph[I8] = []
Graph[J9] = []
Graph[K10] = [G6, H7]

# Ascending order
def ascOrder(graph):
  newGraph = dict()
  for key, val in graph.items():
    val = sorted(val, key = lambda node : node.id)
    newGraph[key] = val
  return newGraph

Graph = ascOrder(Graph)

start_node = C2
BFS_res = BFS_path(Graph, start_node)
DFS_res = DFS_path(Graph, start_node)

print("BFS path start from Node {} : {}".format(start_node.id, BFS_res))
print("DFS Path start from Node {} : {}".format(start_node.id, DFS_res))
        