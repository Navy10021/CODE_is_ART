# Hamiltonian Cycle : Visits every vertex exactly once in Undirected Graph.
# 주어진 그래프에서 모든 노드를 정확히 한번씩 방문하는 모든 경로 찾는 함수. 즉, 모든 노드를 한번에 탐색하는 경로!
# 접근법 : 각 노드를 시작노드로(초기화 필요 or Path 리스트 활용) 모든 경로 저장 -> 모든 노드 방문 여부 확인.
class GNode:
    def __init__(self, data, color = "W"):
        self.data = data 
        self.color = color 

def is_hamiltonian_cycle(graph):
    # find all paths func
    def find_all_paths(graph, start, end):
        def DFS(curr, path):
            if curr == end:
                paths.append(path.copy())
                return
            for nxt in graph[curr]:
                if nxt.data not in path:  # also visited check!(self.color 초기화 불필요)
                    DFS(nxt, path + [nxt.data])
        paths = []
        DFS(start, [start.data])
        return paths
    
    # Check visit all vertices
    hamilton_cycle = []
    vertices = list(graph.keys())
    for start in vertices:
        removed_vertices = vertices.copy()
        removed_vertices.remove(start)
        for end in removed_vertices:
            # 1. find all paths
            paths = find_all_paths(graph, start, end)
            for path in paths:
                # 2. check all nodes visit.
                if len(path) == len(vertices):
                    hamilton_cycle.append(path)
    
    num = len(hamilton_cycle)
    hamilton_cycle = ["->".join(path) for path in hamilton_cycle]
    print("Hamiltonian Cycle Paths : {} || {}".format(num, hamilton_cycle))
    return hamilton_cycle
     
    
A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G = GNode('E'), GNode('F'), GNode('G')

graph = {
    A : [B, C],
    B : [A, D],
    C : [A, D],
    D : [B, C, E, F],
    E : [F],
    F : [E]
}

is_hamiltonian_cycle(graph)
