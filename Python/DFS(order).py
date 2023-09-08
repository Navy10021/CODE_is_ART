class GNode:
    def __init__(self, id, c = "W", d = -1, f = -1, p=None):
        self.id = id 
        self.color = c
        self.dist = d
        self.finish = f
        self.parent = p
        
    def __str__(self):
        return self.id + "(" + str(self.dist) + ")"

    
# 현재 노드 : [인접 노드, 인접노드] 출력 함수
def printGraph(graph):
    for key, val in graph.items():
        print(str(key) + ":", end = "")
        for u in val:
            print(str(u), end = " ")
        print(" ")

# Queue 에 저장된 노드 출력
def printQ(q):
    print("Q = ", end = "")
    for element in q:
        print(element, end = "")
    print("")

# 오름차순 방문 정렬 
def ascendingOrder(graph):
    new_graph = dict()
    for key, val in graph.items():
        val = sorted(val, key = lambda val: val.id)
        new_graph[key] = val 
    return new_graph

# 내림차순 방문 정렬 
def descendingOrder(graph):
    new_graph = dict()
    for key, val in graph.items():
        val = sorted(val, key = lambda val: val.id, reverse=True)
        #val.reverse()
        new_graph[key] = val 
    return new_graph

# DFS 함수!
time = 0
def DFS(G, st, end):
    global time 
    time += 1
    st.dist = time
    st.color = "G"      # 방문 표시
    print(st, end = " -> ")
    #if end is not None and st == end:
    #    return 
    for nxt in G[st]:
        if (nxt.color == "W"):
            nxt.parent = st 
            DFS(G, nxt, end)
    st.color = "B"      # 탐색 종료
    time += 1
    st.finish = time 
     

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
G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

# 오름차순 방문 정렬 
G = ascendingOrder(G)
# 내림차순 방문 정렬 
#G = descendingOrder(G)

DFS(G, t, v)
