# 해당 노드간의 엣지가 없으면 두 개의 그래프로 나눠지는 노드~노드 구간
class GNode:
    def __init__(self, data, c="W", d=float('inf'), p=None):
        self.data = data
        self.color = c
        self.disc = d  # Discovery time
        self.low = d   # Low-link value : The smallest discovery time reachable from the node including itself.
        self.parent = p

def find_bridges(graph):
    bridges = set()
    time = 0
    def DFS(current):
        nonlocal time
        current.color = "B"
        current.disc = time
        current.low = time
        time += 1
        print("Node : {}  discovery time : {}  low-link : {}".format(current.data, current.disc, current.low))

        for neighbor in graph[current]:
            if neighbor.color == "W":
                neighbor.parent = current
                DFS(neighbor)
                
                current.low = min(current.low, neighbor.low)
                print("Node : {}  discovery time : {}  low-link : {}".format(current.data, current.disc, current.low))

                # Case
                if neighbor.low > current.disc:
                    bridges.add((current.data, neighbor.data))
                
            elif neighbor != current.parent:
                current.low = min(current.low, neighbor.disc)
                print("Node : {}  discovery time : {}  low-link : {}".format(current.data, current.disc, current.low))


    for start_node in graph:
        if start_node.color == "W":
            DFS(start_node)

    print("Bridges : ", bridges)

    return bridges

# Example usage
A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G = GNode('E'), GNode('F'), GNode('G')

graph = {
    A: [B, C],
    B: [A, D],
    C: [A, D],
    D: [B, C, E, F],
    E: [D],
    F: [D],
    
}

find_bridges(graph)
