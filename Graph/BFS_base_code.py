class GNode:
    def __init__(self, id, c = "White", d = -1, p = None):
        self.id = id 
        self.color = c  # white -> gray(in Queue) -> black(out Queue)
        self.distance = d 
        self.parent = p 
    
    def __str__(self):
        if (self.parent != None):
            return "(" + self.id + ", " + self.color + ", " + str(self.distance) + ", " + self.parent.id + ")"
        else:
            return "(" + self.id + ", " + self.color + ", " + str(self.distance) + ", None)"

def printGraph(g):
    print("=============================================="*2)
    for key, val in g.items():
        print(str(key) + ": ", end = "")
        for u in val:
            print(str(u), end = " ")
        print(" ")

def printQ(q):
    print("Q = ", end = "")
    for u in q:
        print(u, end = "")
    print("")

from collections import deque
def BFS(G, st):
    # 모든 그래프 초기화
    for key in G:
        key.color = "White"
        key.distance = -1 
        key.parent = None 
    # 시작점 방문 표시(visited) 및 거리 
    st.color = "Gray"
    st.distance = 0 
    Q = deque()
    Q.append(st)
    # 출력 #
    printGraph(G)
    printQ(Q)
    while (Q):
        curr = Q.popleft() 
        for nxt in G[curr]:
            if nxt.color == "White":
                nxt.color = "Gray"
                nxt.distance = curr.distance + 1
                nxt.parent = curr 
                Q.append(nxt)
        curr.color = "Black" 
        # 출력 #
        printGraph(G)
        printQ(Q)
        
            
    
        
r = GNode("r")
s = GNode("s")
t = GNode("t")
u = GNode("u")
v = GNode("v")
w = GNode("w")
x = GNode("x")
y = GNode("y")

# adj list
G = dict()
G[r] = [s, v]
G[s] = [w, r]
G[t] = [w, x, u]
G[u] = [t, x, y]
G[v] = [r]
G[w] = [s, t, x]
G[x] = [w,t,u,y] 
G[y] = [x, u]


BFS(G, s)
