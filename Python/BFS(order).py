class GNode:
    def __init__(self, id, c = "W", d = -1, p=None):
        self.id = id 
        self.color = c
        self.distance = d 
        self.parent = p
        
    def __str__(self):
        return self.id + "(" + str(self.distance) + ")"
    
# 현재 노드 : [인접 노드, 인접노드] 출력 함수
def printGraph(graph):
    for key, val in graph.items():
        print(str(key) + ":", end = "")
        for u in val:
            print(str(u), end = " ")
        print(" ")

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

# Queue 에 저장된 노드 출력
def printQ(q):
    print("Q = ", end = "")
    for element in q:
        print(element, end = "")
    print("")
    
# 그래프 초기화 함수
def initGraph(G):
    for key in G:
        key.color = "W"
        key.distance = -1
        key.parent = None 
    return G 

# BFS 함수!
from collections import deque 
def BFS(G, st):
    # 초기화(필요시 함수 밖에서 설정)
    G = initGraph(G)
    st.color = "G";
    st.distance = 0
    Q = deque()
    Q.append(st)
    #printGraph(G)
    #printQ(Q)
    while(Q):
        curr = Q.popleft()
        print(curr, end =" ")
        for nxt in G[curr]:
            if nxt.color == "W":    # 인근 노드 미방문
                nxt.color = "G"     # 인근 노드 방문
                nxt.distance = curr.distance + 1
                nxt.parent = curr 
                Q.append(nxt)
        curr.color = "B"            # 현재 노드 탐색 종료
        #printGraph(G)
        #printQ(Q)

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
#G = ascendingOrder(G)
# 내림차순 방문 정렬 
#G = descendingOrder(G)

BFS(G, s)
