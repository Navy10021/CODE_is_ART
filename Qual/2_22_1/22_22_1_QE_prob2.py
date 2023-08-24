from collections import deque
# Node definition.
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id
r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
G = dict()
G[r], G[s], G[t], G[u], G[v] = [s, v], [r, w], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]


def bfs(G:dict, s :GNode)->list:
    nodelist = []; q = deque()
    q.append(s)
    nodelist.append([s.id])
    s.color = "B"
    s.distance = 0
    maxdistance = 0
    while q:
        node = q.popleft()
        for adj in G[node]:
            if adj.color == "B": continue
            q.append(adj); adj.color = "B"
            adj.distance = node.distance + 1
            maxdistance = max(adj.distance, maxdistance)
    nodelist = [[] for _ in range(maxdistance+1)]
    for node in G:
        nodelist[node.distance].append(node.id)
    return nodelist



def level_partition(G:dict, s:GNode)->list:
    return bfs(G,s)
        
if __name__ == "__main__":
    print(level_partition(G,s)) 