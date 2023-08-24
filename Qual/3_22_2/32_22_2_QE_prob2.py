class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id
    
a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
G = dict()
G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

def paths(Gd : dict, s:GNode, t:GNode)->list:
    ans = []
    tmp = []
    def backtracking(Gd, st, tgt):
        if (st == tgt):
            ans.append(tmp.copy()) #tmp로 넣어주면 tmp가 계속 바뀌어서 ans에도 영향을 줌
            return
        for adj in G[st]:
            tmp.append(adj.id)
            backtracking(Gd, adj, tgt)
            tmp.remove(adj.id)
    tmp.append(s.id)
    backtracking(Gd, s, t)
    return ans

if __name__ == "__main__":
    print(paths(G, a, c))

