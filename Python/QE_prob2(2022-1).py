class GNode:
    def __init__(self, id, color = 'w', d = 0, p = None):
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p

    # print id
    def __str__(self):
        return self.id
    
r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
# Graph : adj dict
G = dict()
G[s] = [r, w]
G[r] = [s, v]
G[w] = [w, r]
G[t] = [w, x, u]
G[u] = [t, x, y]
G[v] = [r]
G[w] = [s, t, x]
G[x] = [w, t, u, y]
G[y] = [x, u]


def bfs(G, s):
    """
    G : Graph
    s : start Node
    """
    #visited = [False] * len(G)
    res = []
    queue = []
    queue.append((s, order))
    s.distance = 1
    while queue:
        cur_node = queue.pop(0)
        res.append((cur_node[1], cur_node[0].id))
        for adj in G[cur_node[0]]:
            # Not visited
            if adj.distance == 0:
                adj.distance = cur_node[1]+1
                queue.append((adj, cur_node[1]+1))
    
    return res


def level_partition(G, s):
    res = dict()
    bfs_res = bfs(G, s)
    for (dist, color) in bfs_res:
        if dist not in res:
            res[dist] = [color]
        else:
            res[dist].append(color)

    return res.values()

print(level_partition(G, s))
