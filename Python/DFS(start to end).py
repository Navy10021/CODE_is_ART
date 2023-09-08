class GNode:
    def __init__(self, id, c = "W", d = -1, f = -1, p=None):
        self.id = id 
        self.color = c
        self.dist = d
        self.finish = f
        self.parent = p
        
    def __str__(self):
        return self.id + "(" + str(self.dist) + ")"

     
def LexSmallest(G, u, v):
    out = []
    if (u == v):
        return [u.id]
    find = 0
    def DFS(st, en):
        nonlocal find
        if find:
            return 
        st.color = "G"
        out.append(st.id)
        for nxt in G[st]:
            if (nxt.color == "W"):
                nxt.color = "G"
                if (nxt == en):
                    find = 1
                    out.append(nxt.id)
                    return 
                DFS(nxt, en)
    for n in G:
        G[n].sort(key = lambda x : x.id)
    DFS(u, v)
    if find:
        return out 
    else:
        return []

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


print(LexSmallest(G, t, v))
