class GNode:
    def __init__(self, id, c = "W", d=-1):
        self.id = id    # 노드 ID
        self.color = c  # 노드 색 (W: White, G: Gray)
        
    def __str__(self):
        return self.id

def find_path(graph, start, target):
    def DFS(curr, path):
        if curr == target:
            return path + [curr.id]
        
        if curr.color == "W":
            curr.color = "G"
            for nei in graph.get(curr, []):
                new_path = DFS(nei, path + [curr.id])
                if new_path:
                    return new_path
        
        return None
    
    res = DFS(start, [])
    return res if res else "No path found."

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


res = find_path(G, a, f)

print("Sortest Path:", res)
