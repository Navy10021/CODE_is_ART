class GNode:
    def __init__(self, id, color="W", d=-1, f=-1, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.d = d # discover time of node
        self.f = f # finish time of node
        self.parent = p # predecessor time of node

    def __str__(self):
        return self.id  

def merge(L:list, first:int, mid:int, last:int) -> None:
    k = first
    sub1 = L[first:mid+1]
    sub2 = L[mid+1:last+1]
    i = j = 0
    while i < len(sub1) and j < len(sub2):
        if sub1[i].id <= sub2[j].id:
            L[k] = sub1[i]
            i = i + 1
        else:
            L[k] = sub2[j]
            j = j + 1
        k = k + 1
    if i < len(sub1):
        L[k:last+1] = sub1[i:]
    elif j < len(sub2):
        L[k:last+1] = sub2[j:]


def mergeSortHelp(L:list, first: int, last: int)->None:
    if first == last:
        return
    else:
        mid = first + (last - first) // 2
        mergeSortHelp(L, first, mid)
        mergeSortHelp(L, mid+1, last)
        merge(L, first, mid, last)

def mergeSort(L:list)->None:
    mergeSortHelp(L, 0, len(L)-1)



def LexSmallest(G: dict, t:GNode, v:GNode)->list:
    out = []
    if t == v: return [t.id]
    find = 0
    def dfs(st:GNode, en:GNode)->None:
        nonlocal find # 이걸 붙여줘야 바깥 scope와 연계 가능.
        if find: return
        st.color = "K" # "K" means visited, "W" means not visitied;
        out.append(st.id)
        for nxt in G[st]:
            if(nxt.color == "K"): continue
            nxt.color = "K"
            if(nxt == en):
                find = 1
                out.append(nxt.id)
                return
            dfs(nxt, en)
    for n in G:
        # mergeSort(G[n])
        G[n].sort(key = lambda x: x.id)
    dfs(t, v)
    if find:
        return out
    else:
        return []


if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [w, s, x], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

    print(LexSmallest(G, t, v))
    print(LexSmallest(G, u, u))
    print(LexSmallest(G, x, y))