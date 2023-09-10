class GNode:
    def __init__(self, id, c = "W", d=-1):
        self.id = id    # 노드 ID
        self.color = c  # 노드 색 (W: White, G: Gray)
        self.dist = d   # 거 리 
        
    def __str__(self):
        return self.id

from collections import deque
def find_shortest_path(G, start, end):
    # BFS 활용 
    start.color = "G"   # 방문표시 
    start.distance = 0  # Root vertex
    Q = deque()  
    Q.append((start, [start.id])) # (Vertex, Path list)
    
    while (Q):
        curr, path = Q.popleft()
        for nei in G[curr]:
            if nei.color == "W":
                if nei == end:
                    return path + [nei.id]
                else:
                    Q.append((nei, path + [nei.id]))
            nei.color = "G"
        curr.color = "B"
    
    return "No path found."

a = GNode("a")
b = GNode("b")
c = GNode("c")
d = GNode("d")
e = GNode("e")
f = GNode("f") 

# adj list
G = dict()
G[a], G[b], G[c], G[d] = [b, c], [a, d, e], [a, f], [b, e]
G[e], G[f] = [b, d], [c]


res = find_shortest_path(G, a, f)

print("Sortest Path:", res)
