from collections import deque
# BFS-Find K-Distnace(Get Close)
# 시작 노드로 부터 K-거리 보다 작거나 같은 Node를 알파벳순으로 리턴하는 함수
class GNode:
  def __init__(self, id, c="W", d=-1):
    self.id = id
    self.color = c
    self.dist = d
  
def BFS(graph, start, path):
  start.color = "G"
  start.dist += 1
  Q = deque()
  Q.append(start)
  
  while (Q):
    curr = Q.popleft()
    path.append((curr.id, curr.dist))
    for nxt in graph[curr]:
      if nxt.color == "W":
        nxt.color = "G"
        nxt.dist = curr.dist + 1
        Q.append(nxt)
  
  curr.color = "B"  # current Node Queue out
  
def get_close(graph, start, K):
  # initialize
  for node in graph:
    node.color = "W"
    node.dist = -1
  path = []
  BFS(graph, start, path)
  # Check distance lower than K+1
  close_node = []
  for node in path:
    if node[1] <= K:
      close_node.append(node[0])
  close_node.remove(start.id)
  close_node = sorted(close_node)
  
  return close_node
  
  
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

start_node = B1
max_dist = 1
res = get_close(Graph, start_node, max_dist)

print("BFS start from Node {} : {}".format(start_node.id, res))
