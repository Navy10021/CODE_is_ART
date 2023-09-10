class GNode:
    def __init__(self, id, c="W", d=-1, f=-1, p=None):
        self.id = id  # 노드 ID
        self.color = c  # 노드 색 (W: White, G: Gray)

    def __str__(self):
        return self.id

def find_longest_path(G, start, end):
    curr_path = []  # 현재 경로를 저장하는 리스트
    longest_path = ""  # 가장 긴 경로

    def DFS(G, curr):
        curr.color = "G"  # 현재 노드를 방문 중(Gray)으로 표시
        curr_path.append(curr.id)  # 현재 경로에 노드 추가

        if curr == end and len(curr_path) > 2:
            nonlocal longest_path
            curr_path_str = " ".join(curr_path)
            if len(curr_path_str) > len(longest_path):
                longest_path = curr_path_str  # 가장 긴 경로 업데이트

        for nei in G[curr]:
            if nei.color == "W":
                DFS(G, nei)  # 인접한 미방문 노드를 재귀적으로 탐색

        curr.color = "W"  # 현재 노드를 방문 완료(White)로 표시
        curr_path.pop()  # 현재 경로에서 노드 제거

    DFS(G, start)

    return longest_path if longest_path else "No path found"

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


longest_path = find_longest_path(G, t, s)

print("Longest Path:", longest_path)
