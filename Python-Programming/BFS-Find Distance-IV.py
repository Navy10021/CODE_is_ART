# BFS-Find Distance-IV(start ~ end)
# 주어진 두 노드간의 거리를 구하는 함수. I/II/III과 같은 맥락이므로 참고만..
class GNode:
  def __init__(self, id, c="W", d=-1):
    self.id = id
    self.color = c
    self.dist = d
 
 
from collections import deque

def BFS(G, st, en):
  ans = []
  flag = False 
  
  st.color = "G"
  st.dist = 0
  if (st == en):
    flag = True
    ans.append((st.id, st.dist))
    return flag, ans
  
  Q = deque()
  Q.append(st)
  while(Q):
    curr = Q.popleft()
    ans.append((curr.id, curr.dist))
    if (curr == en):
      flag = True
      return flag, ans
    
    for nxt in G[curr]:
      if (nxt.color == "W"):
        nxt.color = "G"
        nxt.dist = curr.dist + 1
        Q.append(nxt)
        
  return flag, ans
  
def BFS_start_to_end(graph, start, end):
  flag, ans = BFS(graph, start, end)
  print("BFS Node{} -> Node{} ".format(start.id, end.id))
  if (flag):
    print(ans)
  else:
    ans = [([], -1)]
    print(ans)
  
  print("Node{} -> Node{} distance is {}".format(start.id, end.id, ans[-1][1]))
    
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

BFS_start_to_end(Graph, A, F)

 
 
        
        
        
