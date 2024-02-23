# DFS-Find Hamiltonian Paths-II(Backtracking)
# Find Hamiltonian Cycle with Backtracking
class GNode:
    def __init__(self, data, color = "W"):
        self.data = data 
        self.color = color 

def is_hamiltonian_cycle(graph):
    hamiltonian_paths = []
    def DFS(curr, path):
        path.append(curr.data)
        curr.color = "B"
        if len(path) == len(graph):
            hamiltonian_paths.append(path.copy())
        else: 
            for nei in graph[curr]:
                if nei.color == "W":
                    DFS(nei, path)
        
        # backtrack for all search
        print("DFS from {} is finish. {} will POP in {}.".format(path[0], curr.data, path))
        path.pop()
        curr.color = "W"
    
    for start_node in graph:
        DFS(start_node, [])
    
    hamiltonian_paths = [" -> ".join(p) for p in hamiltonian_paths]
    
    print("Hamiltonian paths : {} || {}".format(len(hamiltonian_paths), hamiltonian_paths))
    return hamiltonian_paths
    
    
A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G = GNode('E'), GNode('F'), GNode('G')

graph = {
    A : [B, C],
    B : [A, D],
    C : [A, D],
    D : [B, C, E, F],
    E : [D, F],
    F : [D, E]
}

is_hamiltonian_cycle(graph)
