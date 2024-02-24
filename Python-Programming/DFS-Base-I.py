# DFS 탐색 기본함수(Recursive)
class GNode:
    def __init__(self, data, color = "W", dist = -1, fin = -1, parent = None):
        self.data = data 
        self.color = color 
        self.dist = dist 
        self.fin = fin 
        self.parent = parent
    
    def __str__(self):
        return "(" + self.data + ")" 

def printG(g):
    print("====== Graph ======")
    for key, val in g.items():
        print(str(key) + " :", end = " ")
        for u in val:
            print(str(u), end = " ")
        print("")

time = 0 
def DFS(G, curr):
    global time
    time += 1 
    curr.dist = time 
    curr.color = "G"
    print(curr.data, end = "-> ")    # print current vertex 
    for nxt in G[curr]:
        if (nxt.color == "W"):
            nxt.parent = curr 
            DFS(G, nxt) # Recursion
    curr.color = "B"
    print(curr.data + "(Back)", end = "-> ")
    time += 1 
    curr.fin = time 
    
A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

# Adj List (Undirected edges)
G = dict()
G[A] = [C, B]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, E, F]
G[E] = [D, F]
G[F] = [D, E]

# Visit Ascending order
def ascendingOrder(G):
    newG = dict()
    for key, val in G.items():
        val = sorted(val, key = lambda val : val.data)
        newG[key] = val 
    return newG
    
#printG(G)
G = ascendingOrder(G)
#printG(G)
start_vertex = A
# DFS : 1. 한명 에게만 연락할 수 있다. 
# 2. 더 이상 연락할 사람이 없으면 마지막으로 연락한 사람에게 연락한다.(Back)
# 3. 처음 연락한 사람으로 돌아오면 탐색을 종료한다.
DFS(G, start_vertex)
print("DFS is Done.", end = "\n")
