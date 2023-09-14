class GNode:
    def __init__(self, id, c = "W", d = -1, f = -1, p = None):
        self.id = id
        self.color = c 
        self.dist = d 
        self.fin = f 
        self.parent = p 
        
    def __str__(self):
        if (self.parent != None):
            return "(" + self.id + ", " + self.color + ", (" \
                + str(self.dist) + ", " + str(self.fin) + "), " + self.parent.id + ")"
        else:
            return "(" + self.id + ", " + self.color + ", (" \
                + str(self.dist) + ", " + str(self.fin) + "), None)"

def printG(g):
    print("====================================================")
    for key, val in g.items():
        print(str(key) + ": ", end="")
        for u in val:
            print(str(u), end = " ")
        print("")

time = 0

def DFS(G, st, stack):
    global time 
    time += 1
    st.dist = time 
    st.color = "G"
    for nxt in G[st]:
        if nxt.color == "W":
            nxt.parent = st
            DFS(G, nxt, stack)
    st.color = "B"
    time += 1 
    st.fin = time
    stack.insert(0, st.id)

def topological_sort(G):
    stack = []
    for vertex in G:
        if vertex.color == "W":
            DFS(G, vertex, stack)
    return stack

u, v, w = GNode("u"), GNode("v"), GNode("w")
x, y, z = GNode("x"), GNode("y"), GNode("z")
# Directed adj
G = dict()
G[u] = [v, x]   # u -> v, x 
G[v] = [w, y]
G[w] = [z]
G[z] =[]

result = topological_sort(G)
print("Topological Sort:", [node for node in result])
